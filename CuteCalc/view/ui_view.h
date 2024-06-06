#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  QLineEdit *input_text;

  QPushButton *btn_credit;
  QPushButton *btn_deposit;

  QWidget *numbers;
  QPushButton *button_1;
  QPushButton *button_2;
  QPushButton *button_3;
  QPushButton *button_4;
  QPushButton *button_5;
  QPushButton *button_6;
  QPushButton *button_7;
  QPushButton *button_8;
  QPushButton *button_9;
  QPushButton *button_0;
  QPushButton *button_dot;

  QPushButton *button_del;
  QPushButton *button_ac;
  QPushButton *button_unary;
  QPushButton *button_x;
  QPushButton *button_cos;
  QPushButton *button_atan;
  QPushButton *button_ln;
  QPushButton *button_sin;
  QPushButton *button_asin;
  QPushButton *button_tan;
  QPushButton *button_acos;
  QPushButton *button_mod;
  QPushButton *button_sqrt;
  QPushButton *button_log;
  QPushButton *button_power;
  QPushButton *button_close_br;
  QPushButton *button_open_br;

  QWidget *operations;
  QPushButton *button_mul;
  QPushButton *button_equal;
  QPushButton *button_minus;
  QPushButton *button_plus;
  QPushButton *button_div;

  QLabel *result;
  QLabel *x_label;
  QLineEdit *input_x;

  QLineEdit *x_min;
  QLineEdit *x_max;
  QLabel *label_x_min;
  QLabel *label_x_max;
  QCustomPlot *widget;
  QLineEdit *y_min;
  QLineEdit *y_max;
  QLabel *label_y_min;
  QLabel *label_y_max;
  QPushButton *button_plot;
  QPushButton *button_clear_plot;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(635, 390);
    MainWindow->setStyleSheet(QString::fromUtf8("background-color: #f7ebf7;"));

    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setStyleSheet(QString::fromUtf8("font: bold;"));

    input_text = new QLineEdit(centralwidget);
    input_text->setObjectName(QString::fromUtf8("input_text"));
    input_text->setEnabled(true);
    input_text->setGeometry(QRect(10, 50, 341, 31));
    input_text->setStyleSheet(
        QString::fromUtf8("color: black;\nborder: 1px solid grey;\n"
                          "font: 22px bold;"));
    input_text->setAlignment(Qt::AlignRight | Qt::AlignTrailing |
                             Qt::AlignVCenter);

    btn_credit = new QPushButton(centralwidget);
    btn_credit->setObjectName(QString::fromUtf8("btn_credit"));
    btn_deposit = new QPushButton(centralwidget);
    btn_deposit->setObjectName(QString::fromUtf8("btn_deposit"));
    btn_credit->setGeometry(QRect(370, 10, 100, 32));
    btn_deposit->setGeometry(QRect(520, 10, 100, 32));
    btn_credit->setText("Credit");
    btn_deposit->setText("Deposit");
    btn_credit->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "    color: black;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");
    btn_deposit->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "    color: black;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_del = new QPushButton(centralwidget);
    button_del->setObjectName(QString::fromUtf8("button_del"));
    button_del->setGeometry(QRect(260, 90, 41, 41));
    button_del->setFlat(false);
    button_del->setFont(QFont("Arial", 18));
    button_del->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    numbers = new QWidget(centralwidget);
    numbers->setObjectName(QString::fromUtf8("numbers"));
    numbers->setGeometry(QRect(160, 140, 141, 191));
    numbers->setStyleSheet(
        QString::fromUtf8("color: black;\n"
                          "font: 26px;"));

    button_0 = new QPushButton(numbers);
    button_0->setObjectName(QString::fromUtf8("button_0"));
    button_0->setGeometry(QRect(50, 150, 41, 41));
    button_0->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #FBCEFF;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_1 = new QPushButton(numbers);
    button_1->setObjectName(QString::fromUtf8("button_1"));
    button_1->setGeometry(QRect(0, 100, 41, 41));
    button_1->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #FBCEFF;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_2 = new QPushButton(numbers);
    button_2->setObjectName(QString::fromUtf8("button_2"));
    button_2->setGeometry(QRect(50, 100, 41, 41));
    button_2->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #FBCEFF;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_3 = new QPushButton(numbers);
    button_3->setObjectName(QString::fromUtf8("button_3"));
    button_3->setGeometry(QRect(100, 100, 41, 41));
    button_3->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #FBCEFF;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_4 = new QPushButton(numbers);
    button_4->setObjectName(QString::fromUtf8("button_4"));
    button_4->setGeometry(QRect(0, 50, 41, 41));
    button_4->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #FBCEFF;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_5 = new QPushButton(numbers);
    button_5->setObjectName(QString::fromUtf8("button_5"));
    button_5->setGeometry(QRect(50, 50, 41, 41));
    button_5->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #FBCEFF;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_6 = new QPushButton(numbers);
    button_6->setObjectName(QString::fromUtf8("button_6"));
    button_6->setGeometry(QRect(100, 50, 41, 41));
    button_6->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #FBCEFF;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_7 = new QPushButton(numbers);
    button_7->setObjectName(QString::fromUtf8("button_7"));
    button_7->setGeometry(QRect(0, 0, 41, 41));
    button_7->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #FBCEFF;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_8 = new QPushButton(numbers);
    button_8->setObjectName(QString::fromUtf8("button_8"));
    button_8->setGeometry(QRect(50, 0, 41, 41));
    button_8->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #FBCEFF;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_9 = new QPushButton(numbers);
    button_9->setObjectName(QString::fromUtf8("button_9"));
    button_9->setGeometry(QRect(100, 0, 41, 41));
    button_9->setStyleSheet(QString::fromUtf8(""));
    button_9->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #FBCEFF;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_dot = new QPushButton(numbers);
    button_dot->setObjectName(QString::fromUtf8("button_dot"));
    button_dot->setGeometry(QRect(100, 150, 41, 41));
    button_dot->setFont(QFont("Arial", 18));
    button_dot->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_unary = new QPushButton(centralwidget);
    button_unary->setObjectName(QString::fromUtf8("button_unary"));
    button_unary->setGeometry(QRect(160, 290, 41, 41));
    button_unary->setFont(QFont("Arial", 18));
    button_unary->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_cos = new QPushButton(centralwidget);
    button_cos->setObjectName(QString::fromUtf8("button_cos"));
    button_cos->setGeometry(QRect(60, 190, 41, 41));
    button_cos->setFont(QFont("Arial", 18));
    button_cos->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_atan = new QPushButton(centralwidget);
    button_atan->setObjectName(QString::fromUtf8("button_atan"));
    button_atan->setGeometry(QRect(110, 240, 41, 41));
    button_atan->setFont(QFont("Arial", 18));
    button_atan->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_ln = new QPushButton(centralwidget);
    button_ln->setObjectName(QString::fromUtf8("button_ln"));
    button_ln->setGeometry(QRect(60, 140, 41, 41));
    button_ln->setFont(QFont("Arial", 18));
    button_ln->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_sin = new QPushButton(centralwidget);
    button_sin->setObjectName(QString::fromUtf8("button_sin"));
    button_sin->setGeometry(QRect(10, 190, 41, 41));
    button_sin->setFont(QFont("Arial", 18));
    button_sin->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_asin = new QPushButton(centralwidget);
    button_asin->setObjectName(QString::fromUtf8("button_asin"));
    button_asin->setGeometry(QRect(10, 240, 41, 41));
    button_asin->setFont(QFont("Arial", 18));
    button_asin->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_x = new QPushButton(centralwidget);
    button_x->setObjectName(QString::fromUtf8("button_x"));
    button_x->setGeometry(QRect(110, 290, 41, 41));
    button_x->setFont(QFont("Arial", 18));
    button_x->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_tan = new QPushButton(centralwidget);
    button_tan->setObjectName(QString::fromUtf8("button_tan"));
    button_tan->setGeometry(QRect(110, 190, 41, 41));
    button_tan->setFont(QFont("Arial", 18));
    button_tan->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_acos = new QPushButton(centralwidget);
    button_acos->setObjectName(QString::fromUtf8("button_acos"));
    button_acos->setGeometry(QRect(60, 240, 41, 41));
    button_acos->setFont(QFont("Arial", 18));
    button_acos->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_mod = new QPushButton(centralwidget);
    button_mod->setObjectName(QString::fromUtf8("button_mod"));
    button_mod->setGeometry(QRect(110, 90, 41, 41));
    button_mod->setFont(QFont("Arial", 18));
    button_mod->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_sqrt = new QPushButton(centralwidget);
    button_sqrt->setObjectName(QString::fromUtf8("button_sqrt"));
    button_sqrt->setGeometry(QRect(110, 140, 41, 41));
    button_sqrt->setFont(QFont("Arial", 22));
    button_sqrt->setStyleSheet(
        "QPushButton {"
        "    font-size: 20px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_close_br = new QPushButton(centralwidget);
    button_close_br->setObjectName(QString::fromUtf8("button_close_br"));
    button_close_br->setGeometry(QRect(60, 90, 41, 41));
    button_close_br->setFont(QFont("Arial", 18));
    button_close_br->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_log = new QPushButton(centralwidget);
    button_log->setObjectName(QString::fromUtf8("button_log"));
    button_log->setGeometry(QRect(10, 140, 41, 41));
    button_log->setFont(QFont("Arial", 18));
    button_log->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_power = new QPushButton(centralwidget);
    button_power->setObjectName(QString::fromUtf8("button_power"));
    button_power->setGeometry(QRect(160, 90, 41, 41));
    button_power->setFont(QFont("Arial", 18));
    button_power->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    button_open_br = new QPushButton(centralwidget);
    button_open_br->setObjectName(QString::fromUtf8("button_open_br"));
    button_open_br->setGeometry(QRect(10, 90, 41, 41));
    button_open_br->setFont(QFont("Arial", 18));
    button_open_br->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    operations = new QWidget(centralwidget);
    operations->setObjectName(QString::fromUtf8("operations"));
    operations->setGeometry(QRect(310, 90, 41, 241));
    operations->setStyleSheet(
        QString::fromUtf8("color: black;\n"
                          "font: 26px;"));

    button_mul = new QPushButton(operations);
    button_mul->setObjectName(QString::fromUtf8("button_mul"));
    button_mul->setGeometry(QRect(0, 50, 41, 41));
    button_mul->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #c8eafa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_equal = new QPushButton(operations);
    button_equal->setObjectName(QString::fromUtf8("button_equal"));
    button_equal->setGeometry(QRect(0, 200, 41, 41));
    button_equal->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #c8eafa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_minus = new QPushButton(operations);
    button_minus->setObjectName(QString::fromUtf8("button_minus"));
    button_minus->setGeometry(QRect(0, 100, 41, 41));
    button_minus->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #c8eafa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_plus = new QPushButton(operations);
    button_plus->setObjectName(QString::fromUtf8("button_plus"));
    button_plus->setGeometry(QRect(0, 150, 41, 41));
    button_plus->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #c8eafa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    QFont font;
    font.setBold(false);
    font.setItalic(false);

    button_plus->setFont(font);
    button_plus->setFlat(false);

    button_div = new QPushButton(operations);
    button_div->setObjectName(QString::fromUtf8("button_div"));
    button_div->setGeometry(QRect(0, 0, 41, 41));
    button_div->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #c8eafa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_ac = new QPushButton(centralwidget);
    button_ac->setObjectName(QString::fromUtf8("button_ac"));
    button_ac->setGeometry(QRect(210, 90, 41, 41));
    button_ac->setFont(QFont("Arial", 18));
    button_ac->setStyleSheet(
        "QPushButton {"
        "    font-size: 18px;"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}"
        "QPushButton {"
        "    color: black;"
        "}");

    QFont font2;
    font2.setPointSize(16);
    font2.setBold(true);
    font2.setItalic(false);

    result = new QLabel(centralwidget);
    result->setObjectName(QString::fromUtf8("result"));
    result->setGeometry(QRect(10, 20, 341, 20));
    result->setFont(font2);
    result->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
    result->setTextInteractionFlags(Qt::LinksAccessibleByMouse |
                                    Qt::TextSelectableByMouse);
    result->setStyleSheet(
        QString::fromUtf8("color: black;\n"
                          "font: 16px;"));

    x_label = new QLabel(centralwidget);
    x_label->setObjectName(QString::fromUtf8("x_label"));
    x_label->setGeometry(QRect(10, 290, 21, 41));
    x_label->setStyleSheet(
        "QLabel { border: 1px solid gray; color: black; font-size: 16px; }");

    input_x = new QLineEdit(centralwidget);
    input_x->setObjectName(QString::fromUtf8("input_x"));
    input_x->setGeometry(QRect(30, 290, 71, 41));
    input_x->setStyleSheet(
        "QLineEdit { border: 1px solid gray; color: black; font-size: 16px; }");

    QFont font1;
    font1.setPointSize(6);
    font1.setBold(true);
    font1.setItalic(false);

    x_min = new QLineEdit(centralwidget);
    x_min->setObjectName(QString::fromUtf8("x_min"));
    x_min->setGeometry(QRect(370, 250, 71, 31));
    x_min->setStyleSheet("QLineEdit { border: 1px solid gray; color: black; }");

    x_max = new QLineEdit(centralwidget);
    x_max->setObjectName(QString::fromUtf8("x_max"));
    x_max->setGeometry(QRect(450, 250, 71, 31));
    x_max->setStyleSheet("QLineEdit { border: 1px solid gray; color: black; }");

    label_x_min = new QLabel(centralwidget);
    label_x_min->setObjectName(QString::fromUtf8("label_x_min"));
    label_x_min->setGeometry(QRect(370, 220, 51, 41));
    label_x_min->setFont(font1);
    label_x_min->lower();
    label_x_min->setStyleSheet("color: black;");

    label_x_max = new QLabel(centralwidget);
    label_x_max->setObjectName(QString::fromUtf8("label_x_max"));
    label_x_max->setGeometry(QRect(450, 220, 51, 41));
    label_x_max->setFont(font1);
    label_x_max->lower();
    label_x_max->setStyleSheet("color: black;");

    y_min = new QLineEdit(centralwidget);
    y_min->setObjectName(QString::fromUtf8("y_min"));
    y_min->setGeometry(QRect(370, 300, 71, 31));
    y_min->setStyleSheet("QLineEdit { border: 1px solid gray; color: black; }");

    y_max = new QLineEdit(centralwidget);
    y_max->setObjectName(QString::fromUtf8("y_max"));
    y_max->setGeometry(QRect(450, 300, 71, 31));
    y_max->setStyleSheet("QLineEdit { border: 1px solid gray; color: black; }");

    label_y_min = new QLabel(centralwidget);
    label_y_min->setObjectName(QString::fromUtf8("label_y_min"));
    label_y_min->setGeometry(QRect(370, 280, 63, 20));
    label_y_min->setFont(font1);
    label_y_min->lower();
    label_y_min->setStyleSheet("color: black;");

    label_y_max = new QLabel(centralwidget);
    label_y_max->setObjectName(QString::fromUtf8("label_y_max"));
    label_y_max->setGeometry(QRect(450, 280, 63, 20));
    label_y_max->setFont(font1);
    label_y_max->lower();
    label_y_max->setStyleSheet("color: black;");

    widget = new QCustomPlot(centralwidget);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(370, 50, 251, 181));
    widget->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));

    button_plot = new QPushButton(centralwidget);
    button_plot->setObjectName(QString::fromUtf8("button_plot"));
    button_plot->setGeometry(QRect(530, 250, 91, 31));
    button_plot->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "    color: black;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    button_clear_plot = new QPushButton(centralwidget);
    button_clear_plot->setObjectName(QString::fromUtf8("button_clear_plot"));
    button_clear_plot->setGeometry(QRect(530, 300, 91, 31));
    button_clear_plot->setStyleSheet(
        "QPushButton {"
        "    border: 1px solid gray;"
        "    background-color: #ddc8fa;"
        "    color: black;"
        "}"
        "QPushButton:hover {"
        "    background-color: #8761FF;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #FF16E4;"
        "}");

    MainWindow->setCentralWidget(centralwidget);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    input_text->setText(
        QCoreApplication::translate("MainWindow", "0", nullptr));
    button_del->setText(
        QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
    button_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
    button_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
    button_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
    button_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
    button_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
    button_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
    button_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
    button_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
    button_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
    button_dot->setText(
        QCoreApplication::translate("MainWindow", ".", nullptr));
    button_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    button_unary->setText(
        QCoreApplication::translate("MainWindow", "\302\261", nullptr));
    button_cos->setText(
        QCoreApplication::translate("MainWindow", "cos", nullptr));
    button_atan->setText(
        QCoreApplication::translate("MainWindow", "atan", nullptr));
    button_ln->setText(
        QCoreApplication::translate("MainWindow", "ln", nullptr));
    button_sin->setText(
        QCoreApplication::translate("MainWindow", "sin", nullptr));
    button_asin->setText(
        QCoreApplication::translate("MainWindow", "asin", nullptr));
    button_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
    button_tan->setText(
        QCoreApplication::translate("MainWindow", "tan", nullptr));
    button_acos->setText(
        QCoreApplication::translate("MainWindow", "acos", nullptr));
    button_mod->setText(
        QCoreApplication::translate("MainWindow", "mod", nullptr));
    button_sqrt->setText(
        QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
    button_close_br->setText(
        QCoreApplication::translate("MainWindow", ")", nullptr));
    button_log->setText(
        QCoreApplication::translate("MainWindow", "log", nullptr));
    button_power->setText(
        QCoreApplication::translate("MainWindow", "x\312\270", nullptr));
    button_open_br->setText(
        QCoreApplication::translate("MainWindow", "(", nullptr));
#if QT_CONFIG(whatsthis)
    button_mul->setWhatsThis(QString());
#endif  // QT_CONFIG(whatsthis)
    button_mul->setText(
        QCoreApplication::translate("MainWindow", "\303\227", nullptr));
    button_equal->setText(
        QCoreApplication::translate("MainWindow", "=", nullptr));
    button_minus->setText(
        QCoreApplication::translate("MainWindow", "-", nullptr));
    button_plus->setText(
        QCoreApplication::translate("MainWindow", "+", nullptr));
    button_div->setText(
        QCoreApplication::translate("MainWindow", "\303\267", nullptr));
    button_ac->setText(
        QCoreApplication::translate("MainWindow", "AC", nullptr));
    result->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    x_label->setText(QCoreApplication::translate("MainWindow", "X=", nullptr));
    input_x->setInputMask(QString());
    x_min->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
    x_max->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
    label_x_min->setText(
        QCoreApplication::translate("MainWindow", "Xmin", nullptr));
    label_x_max->setText(
        QCoreApplication::translate("MainWindow", "Xmax", nullptr));
    y_min->setText(QCoreApplication::translate("MainWindow", "-10", nullptr));
    y_max->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
    label_y_min->setText(
        QCoreApplication::translate("MainWindow", "Ymin", nullptr));
    label_y_max->setText(
        QCoreApplication::translate("MainWindow", "Ymax", nullptr));
    button_plot->setText(
        QCoreApplication::translate("MainWindow", "Plot", nullptr));
    button_clear_plot->setText(
        QCoreApplication::translate("MainWindow", "Clear Plot", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
