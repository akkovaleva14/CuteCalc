QT += core gui quickcontrols2

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TEMPLATE = app
TARGET = CuteCalc

SOURCES += \
    credit_deposit/credit_deposit.cpp \
    credit_deposit/creditwindow.cpp \
    credit_deposit/depositwindow.cpp \
    main.cpp \
    view/s21_view.cpp \
    view/qcustomplot.cpp \
    controller/s21_controller.cpp \
    controller/s21_credit_controller.cpp \
    controller/s21_deposit_controller.cpp \
    model/s21_model.cpp \
    model/s21_credit_model.cpp \
    model/s21_deposit_model.cpp

HEADERS += \
    credit_deposit/credit_deposit.h \
    credit_deposit/creditwindow.h \
    credit_deposit/depositwindow.h \
    view/s21_view.h \
    view/qcustomplot.h \
    controller/s21_controller.h \
    controller/s21_credit_controller.h \
    controller/s21_deposit_controller.h \
    model/s21_model.h \
    model/s21_credit_model.h \
    model/s21_deposit_model.h

FORMS += \
    credit_deposit/creditwindow.ui \
    credit_deposit/depositwindow.ui \
    view/view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
