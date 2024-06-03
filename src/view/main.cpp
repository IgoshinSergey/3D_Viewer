#include <QApplication>

#include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  View w;
  w.setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint |
                   Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint);
  w.show();
  return a.exec();
}
