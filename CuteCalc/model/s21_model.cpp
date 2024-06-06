#include "s21_model.h"

s21::Model::Model() {
  infix_ = "";
  varX_ = 0.0;
  xMin_ = 0.0;
  xMax_ = 0.0;
  yMin_ = 0.0;
  yMax_ = 0.0;
  step_ = 0.01;
  errorCode_ = 0;
  theError_ = "";
}

void s21::Model::SetExpression(std::string expression) { infix_ = expression; }
void s21::Model::SetVarX(double x) { varX_ = x; }
void s21::Model::SetStep(double step) { step_ = step; }

void s21::Model::SetPlotRange(double xMin, double xMax, double yMin,
                              double y_max) {
  xMin_ = xMin;
  xMax_ = xMax;
  yMin_ = yMin;
  yMax_ = y_max;
  step_ = 0.01;
  double range = fabs(xMin_) + fabs(xMax_);
  if (range >= 100) step_ = 0.1;
  if (range >= 1000) step_ = 1;
  if (range >= 10000) step_ = 10;
  if (range >= 100000) step_ = 100;
  if (range >= 1000000) step_ = 1000;
}

std::pair<std::vector<double>, std::vector<double>> s21::Model::Plot() {
  std::vector<double> x;
  std::vector<double> y;
  std::string result = "";
  std::string expression = infix_;
  double res;
  theError_.clear();
  errorCode_ = 0;
  double before_result = 0.0;
  for (varX_ = xMin_; varX_ <= xMax_; varX_ += step_) {
    if (fabs(varX_) < S21_EPSILON) varX_ = 0;
    errorCode_ = Parser(infix_);
    if (theError_.empty() && errorCode_ == 0) {
      errorCode_ = ProcessTokenInputList();
    }
    if (theError_.empty() && errorCode_ == 0) {
      ConvertInfixToPostfix();
      before_result = PostfixNotationCalculation(varX_);
    }
    if (theError_.empty() && errorCode_ == 0) {
      res = before_result;
    } else {
      break;
    }
    if ((res < 0 && res < yMin_) || (res > 0 && res > yMax_)) res = NAN;
    x.push_back(varX_);
    y.push_back(res);
    infix_ = expression;
  }
  return std::make_pair(x, y);
}

std::string s21::Model::Calculate() {
  std::string result = "";
  result.clear();
  double before_result = 0.0;
  theError_.clear();
  errorCode_ = 0;
  errorCode_ = Parser(infix_);
  if (theError_.empty() && errorCode_ == 0) {
    errorCode_ = ProcessTokenInputList();
  }
  if (theError_.empty() && errorCode_ == 0) {
    ConvertInfixToPostfix();
    if (theError_.empty() && errorCode_ == 0) {
      before_result = PostfixNotationCalculation(varX_);
    }
  }
  if (theError_.empty() && errorCode_ == 0) {
    result = FormatValueAsString(before_result);
  } else {
    result = theError_;
  }
  theError_.clear();
  errorCode_ = 0;
  return result;
}

void s21::Token::CreateTokenMap(std::map<std::string, s21::Token> &tokenMap) {
  using std::initializer_list;
  using std::pair;
  using std::string;
  using namespace s21;
  initializer_list<pair<const string, Token>> list = {
      {" ", Token("space", kDefault, kNone, kNumber, nullptr)},
      {"x", Token("x", kDefault, kNone, kNumber, nullptr)},
      {"(", Token("(", kDefault, kNone, kOpenBracket, nullptr)},
      {")", Token(")", kDefault, kNone, kCloseBracket, nullptr)},
      {"+", Token("+", kLow, kLeft, kBinaryOperator, std::plus<double>())},
      {"-", Token("-", kLow, kLeft, kBinaryOperator, std::minus<double>())},
      {"*",
       Token("*", kMedium, kLeft, kBinaryOperator, std::multiplies<double>())},
      {"/",
       Token("/", kMedium, kLeft, kBinaryOperator, std::divides<double>())},
      {"^", Token("^", kHigh, kRight, kBinaryOperator, powl)},
      {"mod", Token("mod", kMedium, kLeft, kBinaryOperator, fmodl)},
      {"cos", Token("cos", kFunction, kRight, kUnaryFunction, cosl)},
      {"sin", Token("sin", kFunction, kRight, kUnaryFunction, sinl)},
      {"tan", Token("tan", kFunction, kRight, kUnaryFunction, tanl)},
      {"acos", Token("acos", kFunction, kRight, kUnaryFunction, acosl)},
      {"asin", Token("asin", kFunction, kRight, kUnaryFunction, asinl)},
      {"atan", Token("atan", kFunction, kRight, kUnaryFunction, atanl)},
      {"sqrt", Token("sqrt", kFunction, kRight, kUnaryFunction, sqrtl)},
      {"ln", Token("In", kFunction, kRight, kUnaryFunction, logl)},
      {"log", Token("log", kFunction, kRight, kUnaryFunction, log10l)},
      // {"cbrt", Token("cbrt", kFunction, kRight, kUnaryFunction, cbrtl)},
      // {"exp", Token("exp", kFunction, kRight, kUnaryFunction, expl)},
      // {"abs", Token("abs", kFunction, kRight, kUnaryFunction, fabsl)},
      // {"round", Token("round", kFunction, kRight, kUnaryFunction, roundl)},
      // {"e", Token("e", kDefault, kNone, kNumber, M_E)},
      // {"pi", Token("pi", kDefault, kNone, kNumber, M_PI)},
      // {"inf", Token("inf", kDefault, kNone, kNumber, INFINITY)},
      // {" !", Token("!", kUnaryOpeartor, kLeft, kUnaryPostfixOperator,
      // factorial)},
  };
  tokenMap.insert(list);
}

std::string s21::Token::FormatValueAsString(double value) {
  std::stringstream ss;
  ss << std::fixed << std::setprecision(7);
  ss << value;
  std::string result = ss.str();
  size_t pos = result.find_last_not_of('0');
  if (pos != std::string::npos) {
    result.erase(pos + 1);
  }
  if (result.back() == '.') {
    result.pop_back();
    size_t dotPos = result.rfind('.');
    if (dotPos != std::string::npos) {
      result.erase(dotPos + 1);
    }
  }
  return result;
}

void s21::Token::MakeNumber(std::string name, double value) {
  Token result(name, kDefault, kNone, kNumber, value);
  *this = result;
}

void s21::Token::MakeUnaryNegation() {
  Token result("negate", kHigh, kRight, kUnaryPrefixOperator,
               std::negate<double>());
  *this = result;
}

std::string s21::Model::ConvertToLowercase(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);
  return str;
}

std::string s21::Model::ReadWord(std::string &input,
                                 size_t &start_index) const {
  std::regex word_regex("([a-z]+)");
  std::sregex_iterator regex_iterator = std::sregex_iterator(
      input.begin() + start_index, input.end(), word_regex);
  std::smatch match = *regex_iterator;
  start_index += match.length();
  return match.str();
}

double s21::Model::ReadNumber(std::string &input, size_t &start_index) const {
  std::regex double_regex("\\d+([.]\\d+)?(e([-+])?\\d+)?");
  std::sregex_iterator regex_iterator = std::sregex_iterator(
      input.begin() + start_index, input.end(), double_regex);
  std::smatch match = *regex_iterator;
  start_index += match.length();
  return std::stod(match.str());
}

int s21::Model::TryToPushToken(std::string token) {
  auto token_map_it = tokenMap_.find(token);
  if (token_map_it == tokenMap_.end()) {
    theError_ = "Incorrect symbol: " + token;
    errorCode_ = 1;
    return errorCode_;
  } else {
    input_.push(token_map_it->second);
  }
  return errorCode_;
}

int s21::Model::Parser(std::string str) {
  CreateTokenMap(tokenMap_);
  str = ConvertToLowercase(str);
  size_t start_index = 0;
  theError_.clear();
  errorCode_ = 0;
  while (!input_.empty()) {
    input_.pop();
  }
  while (start_index < str.size() && theError_.empty()) {
    if (std::isalpha(str[start_index])) {
      std::string word = ReadWord(str, start_index);
      errorCode_ = TryToPushToken(word);
      if (errorCode_ != 0) {
        return errorCode_;
      }
    } else if (std::isdigit(str[start_index])) {
      double number = ReadNumber(str, start_index);
      s21::Token numberToken;
      numberToken.MakeNumber(FormatValueAsString(number), number);
      input_.push(numberToken);
    } else {
      std::string s{str[start_index]};
      errorCode_ = TryToPushToken(s);
      start_index++;
      if (errorCode_ != 0) {
        return errorCode_;
      }
    }
  }
  return errorCode_;
}

void s21::Model::MoveTokenFromInputToOutput() {
  Token token = input_.front();
  input_.pop();
  output_.push(token);
}

void s21::Model::MoveTokenFromInputToStack() {
  Token token = input_.front();
  input_.pop();
  stack_.push_back(token);
}

void s21::Model::MoveTokenFromStackToOutput() {
  Token token = stack_.back();
  stack_.pop_back();
  output_.push(token);
}

void s21::Model::DeleteSpaces() {
  std::queue<Token> tempQueue;
  while (!input_.empty()) {
    Token token = input_.front();
    input_.pop();
    if (token.GetName() != "space") {
      tempQueue.push(token);
    }
  }
  input_ = tempQueue;
  while (!tempQueue.empty()) {
    tempQueue.pop();
  }
}

void s21::Model::BinaryToUnaryConverter() {
  Token prevToken;
  prevToken.SetType(kNumTokenTypes);
  std::queue<Token> tempQueue;
  while (!input_.empty()) {
    Token currentToken = input_.front();
    input_.pop();
    if (currentToken.GetType() == kBinaryOperator &&
        (currentToken.GetName() == "+" || currentToken.GetName() == "-")) {
      if (!(prevToken.GetType() == kNumber ||
            prevToken.GetType() == kCloseBracket)) {
        if (currentToken.GetName() == "+") {
          currentToken.SetType(kUnaryPrefixOperator);
          currentToken.SetPrecedence(kUnaryOpeartor);
        } else {
          currentToken.MakeUnaryNegation();
        }
      }
    }
    prevToken = currentToken;
    tempQueue.push(currentToken);
  }
  while (!tempQueue.empty()) {
    input_.push(tempQueue.front());
    tempQueue.pop();
  }
}

int s21::Model::BracketsCheck() {
  std::queue<Token> tempQueue;
  int bracket_check = 0;
  while (!input_.empty()) {
    Token currentToken = input_.front();
    input_.pop();
    tempQueue.push(currentToken);
    if (currentToken.GetType() == kCloseBracket) {
      bracket_check--;
    }
    if (currentToken.GetType() == kOpenBracket) {
      bracket_check++;
    }
    if (bracket_check < 0) {
      errorCode_ = 1;
      theError_ = "Bracket check failed";
      return errorCode_;
    }
  }
  input_ = tempQueue;
  while (!tempQueue.empty()) {
    tempQueue.pop();
  }
  return errorCode_;
}

int s21::Model::ProcessTokenInputList() {
  theError_.clear();
  errorCode_ = 0;
  ClearQueue(output_);
  DeleteSpaces();
  BinaryToUnaryConverter();
  errorCode_ = BracketsCheck();
  if (errorCode_ != 0) return errorCode_;
  if (!kFirstToken_[static_cast<size_t>(input_.front().GetType())]) {
    theError_ = "Invalid starting token: " + input_.front().GetName();
    errorCode_ = 1;
    return errorCode_;
  } else {
    MoveTokenFromInputToOutput();
  }
  while (!output_.empty() && !input_.empty()) {
    if (!kAdjacencyMatrix_[output_.back().GetType()]
                          [input_.front().GetType()]) {
      theError_ = "Wrong sequence: " + output_.back().GetName() + " " +
                  input_.front().GetName();
      errorCode_ = 1;
      return errorCode_;
    }
    MoveTokenFromInputToOutput();
  }
  if (!kLastToken_[static_cast<size_t>(output_.back().GetType())]) {
    theError_ = "Invalid ending token: " + output_.back().GetName();
    errorCode_ = 1;
    return errorCode_;
  }
  return errorCode_;
}

void s21::Model::ClearQueue(std::queue<Token> &output_) {
  while (!output_.empty()) {
    output_.pop();
  }
}

void s21::Model::ConvertInfixToPostfix() {
  using namespace s21;
  input_ = output_;
  ClearQueue(output_);
  while (!input_.empty()) {
    switch (input_.front().GetType()) {
      case Type::kNumber:
      case Type::kNumTokenTypes:
      case Type::kUnaryPostfixOperator:
        MoveTokenFromInputToOutput();
        break;
      case Type::kUnaryFunction:
      case Type::kOpenBracket:
        MoveTokenFromInputToStack();
        break;
      case Type::kUnaryPrefixOperator:
        if (input_.front().GetName() == "+") {
          input_.pop();
        } else {
          MoveTokenFromInputToStack();
        }
        break;
      case Type::kBinaryOperator: {
        if (stack_.empty() || stack_.back().GetType() == Type::kOpenBracket) {
          MoveTokenFromInputToStack();
        } else {
          Precedence currentPrecedence = input_.front().GetPrecedence();
          Precedence stackPrecedence = stack_.back().GetPrecedence();
          Associativity currentAssociativity =
              input_.front().GetAssociativity();
          Associativity stackAssociativity = stack_.back().GetAssociativity();
          if (currentPrecedence > stackPrecedence ||
              (currentAssociativity == kRight &&
               stackAssociativity == kRight)) {
            MoveTokenFromInputToStack();
          } else {
            while (!stack_.empty() &&
                   stack_.back().GetPrecedence() >= currentPrecedence &&
                   stack_.back().GetType() != Type::kOpenBracket) {
              MoveTokenFromStackToOutput();
            }
            MoveTokenFromInputToStack();
          }
        }
      } break;
      case Type::kCloseBracket: {
        while (stack_.back().GetType() != Type::kOpenBracket) {
          MoveTokenFromStackToOutput();
        }
        if (stack_.back().GetType() == Type::kOpenBracket) {
          stack_.pop_back();
        }
        if (stack_.back().GetType() == Type::kUnaryFunction) {
          MoveTokenFromStackToOutput();
        }
        input_.pop();
      } break;
    }
  }

  while (!stack_.empty()) {
    if (stack_.back().GetType() == Type::kOpenBracket) {
      stack_.pop_back();
    } else {
      MoveTokenFromStackToOutput();
    }
  }
}

double s21::Model::PostfixNotationCalculation(double x_value) {
  using namespace s21;
  input_ = output_;
  ClearQueue(output_);
  result_.clear();
  while (!input_.empty()) {
    std::visit(
        overloaded{[&](double function) { PushToResult(function); },
                   [&](unary_function function) {
                     PushToResult(function(PopFromResult()));
                   },
                   [&](binary_function function) {
                     double right_argument = PopFromResult();
                     double left_argument = PopFromResult();
                     PushToResult(function(left_argument, right_argument));
                   },
                   [&](auto) { PushToResult(x_value); }},
        input_.front().GetFunction());
    input_.pop();
  }
  stack_.clear();
  if (errorCode_ == 0) {
    theError_.clear();
  }
  return PopFromResult();
}

void s21::Model::PushToResult(double value) { result_.push_back(value); }

double s21::Model::PopFromResult() {
  double value = result_.back();
  result_.pop_back();
  return value;
}