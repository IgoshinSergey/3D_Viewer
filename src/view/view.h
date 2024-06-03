#ifndef VIEW_H
#define VIEW_H

#include <qgifimage.h>

#include <QFileDialog>
#include <QMainWindow>
#include <QSettings>
#include <QTimer>

#include "opengl.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow {
  Q_OBJECT

 public:
  View(QWidget *parent = nullptr);
  ~View();

 private slots:
  void on_solidLine_clicked();

  void on_dashedLine_clicked();

  void on_redLine_valueChanged(double arg1);

  void on_greenLine_valueChanged(double arg1);

  void on_blueLine_valueChanged(double arg1);

  void on_lineWidth_valueChanged(double arg1);

  void on_redBackground_valueChanged(double arg1);

  void on_greenBackground_valueChanged(double arg1);

  void on_blueBackground_valueChanged(double arg1);

  void on_parallelProjection_clicked();

  void on_centralProjection_clicked();
  void on_rdNoneVertices_clicked();

  void on_rdCircleVertices_clicked();

  void on_rdSquareVertices_clicked();

  void on_dSb_verticesSize_valueChanged(double arg1);

  void on_redLine_Verticles_valueChanged(double arg1);

  void on_greenLine_Verticles_valueChanged(double arg1);

  void on_blueLine_Verticles_valueChanged(double arg1);

  void on_OpenFile_clicked();

  void on_hMove_x_valueChanged(int value);

  void on_dSBMoveX_valueChanged(double arg1);

  void on_hMove_y_valueChanged(int value);

  void on_hMove_z_valueChanged(int value);

  void on_dSBMoveY_valueChanged(double arg1);

  void on_dSBMoveZ_valueChanged(double arg1);

  void on_hRotate_x_valueChanged(int value);

  void on_hRotate_y_valueChanged(int value);

  void on_sBRotateX_valueChanged(int arg1);

  void on_sBRotateY_valueChanged(int arg1);

  void on_hRotate_z_valueChanged(int value);

  void on_sBRotateZ_valueChanged(int arg1);

  void on_hScale_valueChanged(int value);

  void on_dSBScale_valueChanged(double arg1);

  void count_vetrexes_and_edges();

  void on_pngButton_clicked();

  void on_bmpButton_clicked();

  void on_gifButton_clicked();

  void add_qimage_in_gif();

  void saveSetting();
  void loadSettings();
  void loadLineSettings();
  void loadVertexSettings();
  void loadBackgroundSettings();

 private:
  Ui::View *ui;
  s21::OpenGl *wid;
  QTimer *timer;
  QGifImage *gif;
  QString fileName;
  QSettings *settings;
};
#endif  // VIEW_H
