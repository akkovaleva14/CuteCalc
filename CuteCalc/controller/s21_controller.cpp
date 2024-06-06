#include "s21_controller.h"

std::string s21::Controller::ProcessExpression(std::string expression) {
  model_->SetExpression(expression);
  return model_->Calculate();
}

void s21::Controller::SetVarX(double x) { model_->SetVarX(x); }

void s21::Controller::SetPlotRange(double xMin, double xMax, double yMin,
                                   double yMax) {
  model_->SetPlotRange(xMin, xMax, yMin, yMax);
}

std::pair<std::vector<double>, std::vector<double>> s21::Controller::Plot(
    std::string expression) {
  model_->SetExpression(expression);
  return model_->Plot();
}