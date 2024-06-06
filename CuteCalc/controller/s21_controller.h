#ifndef SRC_CONTROLLER_S21_CONTROLLER_H_
#define SRC_CONTROLLER_S21_CONTROLLER_H_

#include "../model/s21_model.h"

namespace s21 {
class Controller {
 public:
  explicit Controller(s21::Model *m) : model_(m) {}
  std::string ProcessExpression(std::string expression);
  void SetVarX(double x);
  void SetPlotRange(double xMin, double xMax, double yMin, double yMax);
  std::pair<std::vector<double>, std::vector<double>> Plot(
      std::string expression);

 private:
  s21::Model *model_;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_S21_CONTROLLER_H_
