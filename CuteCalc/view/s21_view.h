#ifndef SRC_VIEW_S21_VIEW_H_
#define SRC_VIEW_S21_VIEW_H_

#include <QApplication>
#include <QDialog>
#include <QLayout>
#include <QMainWindow>
#include <QMessageBox>
#include <QQuickStyle>
#include <QRegularExpression>
#include <QValidator>
#include <QVector>

#include "../controller/s21_controller.h"
#include "ui_view.h"

#include "../credit_deposit/creditwindow.h"
#include "../credit_deposit/depositwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class View : public QMainWindow {
  Q_OBJECT

 public:
  explicit View(s21::Controller *controller = nullptr);
  ~View();

 private slots:
  void button_number();
  void button_operation();
  void on_button_del_clicked();
  void on_button_equal_clicked();
  void on_button_ac_clicked();
  void on_button_unary_clicked();
  void on_button_x_clicked();
  void on_button_plot_clicked();
  void on_button_clear_plot_clicked();
  void credit_window();
  void deposit_window();

 private:
  Ui::MainWindow *ui;
  s21::Controller *controller;
  bool check_range();
  double xMin;
  double xMax;
  double yMin;
  double yMax;
  CreditWindow *crWindow;
  DepositWindow *dWindow;
};
}  // namespace s21

#endif  // SRC_VIEW_S21_VIEW_H_
