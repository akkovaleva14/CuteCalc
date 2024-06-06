#ifndef SRC_MODEL_S21_MODEL_H_
#define SRC_MODEL_S21_MODEL_H_

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
// NOLINTNEXTLINE(build/c++11)
#include <cctype>
#include <functional>
#include <map>
#include <queue>
#include <regex>
#include <type_traits>
#include <variant>
#include <vector>

#define S21_EPSILON 0.0000001

using unary_function = std::function<double(double)>;
using binary_function = std::function<double(double, double)>;
using function_variant = std::variant<double, unary_function, binary_function,
                                      nullptr_t>;  // nullptr_t - это x
using XYGraph = std::pair<std::vector<double>, std::vector<double>>;

template <class... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};
template <class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

enum Type {
  kNumber,
  kBinaryOperator,
  kUnaryPrefixOperator,   // унарные + -
  kUnaryPostfixOperator,  // factorial
  kUnaryFunction,  // все буквенные функции с аргументом в ()
  kOpenBracket,
  kCloseBracket,
  kNumTokenTypes,  // чтобы выводилось число 0-7
};

enum Precedence {
  kDefault,  // числа, x, скобки, пробел (т.е. все то, что не функции)
  kLow,      // бинарные + -
  kMedium,   // * / %
  kHigh,     // ^
  kUnaryOpeartor,  // чтобы записывать отрицательные числа без скобочек (иначе
                   // приоритет как kLow)
  kFunction,
};

enum Associativity {
  kNone,
  kLeft,  // - / % (несколько раз / будем считать слева-направо)
  kRight,  // ^ (несколько раз ^ будем считать справа-налево)
};

namespace s21 {
class Token {
 public:
  Token() = default;
  Token(const std::string &name, Precedence precedence,
        Associativity associativity, Type type, function_variant function)
      : name_(name),
        precedence_(precedence),
        associativity_(associativity),
        type_(type),
        function_(function){};
  ~Token() = default;

  std::string GetName() const { return name_; }
  Type GetType() const { return type_; }
  Precedence GetPrecedence() const { return precedence_; }
  Associativity GetAssociativity() const { return associativity_; }
  function_variant GetFunction() const { return function_; }
  void SetType(Type type) { type_ = type; }
  void SetPrecedence(Precedence precedence) { precedence_ = precedence; }

  std::string FormatValueAsString(double value);
  void MakeNumber(std::string name, double value);
  void MakeUnaryNegation();
  void CreateTokenMap(std::map<std::string, s21::Token> &tokenMap);

 private:
  std::string name_;
  Precedence precedence_;
  Associativity associativity_;
  Type type_;
  function_variant function_;
};

class Model : public Token {
 public:
  explicit Model();
  void SetExpression(const std::string expression);
  void SetVarX(double x);
  void SetStep(double step);
  void SetPlotRange(double xMin, double xMax, double yMin, double yMax);
  std::string Calculate();
  std::pair<std::vector<double>, std::vector<double>> Plot();
  ~Model() = default;

 private:
  std::string infix_;
  double varX_;
  double xMin_;
  double xMax_;
  double yMin_;
  double yMax_;
  double step_;
  int errorCode_;
  std::string theError_;
  std::map<std::string, Token> tokenMap_;
  std::queue<Token> input_;
  std::queue<Token> output_;
  std::vector<Token> stack_;
  std::vector<double> result_;

  static constexpr bool kAdjacencyMatrix_[kNumTokenTypes][kNumTokenTypes] = {
      {0, 1, 0, 1, 0, 0, 1},  // kNumber
      {1, 0, 1, 0, 1, 1, 0},  // kBinaryOperator
      {1, 0, 1, 0, 1, 1, 0},  // kUnaryPrefixOperator
      {0, 1, 0, 1, 0, 0, 1},  // kUnaryPostfixOperator
      {0, 0, 0, 0, 0, 1, 0},  // kUnaryFunction
      {1, 0, 1, 0, 1, 1, 0},  // kOpenBracket
      {0, 1, 0, 1, 0, 0, 1},  // kCloseBracket
  };
  static constexpr bool kFirstToken_[kNumTokenTypes] = {1, 0, 1, 0, 1, 1, 0};
  static constexpr bool kLastToken_[kNumTokenTypes] = {1, 0, 0, 1, 0, 0, 1};

  int Parser(std::string str);
  std::string ConvertToLowercase(std::string str);
  std::string ReadWord(std::string &input, size_t &start_index) const;
  double ReadNumber(std::string &input, size_t &start_index) const;
  int TryToPushToken(const std::string token);

  int ProcessTokenInputList();
  void ClearQueue(std::queue<Token> &output_);
  void DeleteSpaces();
  void BinaryToUnaryConverter();
  int BracketsCheck();
  void MoveTokenFromInputToOutput();

  void ConvertInfixToPostfix();
  void MoveTokenFromStackToOutput();
  void MoveTokenFromInputToStack();

  double PostfixNotationCalculation(double x_value);
  void PushToResult(double);
  double PopFromResult();
};

}  // namespace s21

#endif  // SRC_MODEL_S21_MODEL_H_
