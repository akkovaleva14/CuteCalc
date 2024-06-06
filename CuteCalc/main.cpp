#include "view/s21_view.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    s21::Model model;
    s21::Controller controller(&model);
    s21::View view(&controller);

    view.setWindowTitle("CuteCalc");
    view.setFixedSize(635, 355);
    view.show();

    return a.exec();
}
