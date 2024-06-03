#include "view.h"

#include "ui_view.h"

View::View(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::View),
      wid(new s21::OpenGl),
      timer(new QTimer) {
  ui->setupUi(this);
  setWindowTitle("3D_Viewer");

  settings = new QSettings("21School", "Viewer");
  setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint |
                 Qt::WindowSystemMenuHint | Qt::WindowMinimizeButtonHint |
                 Qt::WindowCloseButtonHint);
  setFixedSize(width(), height());
  wid->setFixedSize(QSize(800, 800));
  wid->setGeometry(10, 10, 800, 800);
  wid->show();
  ui->opengl_layout->insertWidget(0, wid);
  loadSettings();
  connect(timer, SIGNAL(timeout()), this, SLOT(add_qimage_in_gif()));
}

View::~View() {
  saveSetting();
  delete ui;
  delete wid;
  delete settings;
  delete timer;
}

void View::on_solidLine_clicked() {
  wid->is_solid_line = true;
  wid->update();
}

void View::on_dashedLine_clicked() {
  wid->is_solid_line = false;
  wid->update();
}

void View::on_redLine_valueChanged(double arg1) {
  wid->line_color.red = arg1;
  wid->update();
}

void View::on_greenLine_valueChanged(double arg1) {
  wid->line_color.green = arg1;
  wid->update();
}

void View::on_blueLine_valueChanged(double arg1) {
  wid->line_color.blue = arg1;
  wid->update();
}

void View::on_lineWidth_valueChanged(double arg1) {
  wid->line_width = arg1;
  wid->update();
}

void View::on_redBackground_valueChanged(double arg1) {
  wid->background_color.red = arg1;
  wid->update();
}

void View::on_rdNoneVertices_clicked() {
  wid->setVetricesType(0);
  wid->update();
}

void View::on_greenBackground_valueChanged(double arg1) {
  wid->background_color.green = arg1;
  wid->update();
}

void View::on_rdCircleVertices_clicked() {
  wid->setVetricesType(1);
  wid->update();
}

void View::on_blueBackground_valueChanged(double arg1) {
  wid->background_color.blue = arg1;
  wid->update();
}

void View::on_rdSquareVertices_clicked() {
  wid->setVetricesType(2);
  wid->update();
}

void View::on_parallelProjection_clicked() {
  wid->is_parallel_projection = true;
  wid->update();
}

void View::on_dSb_verticesSize_valueChanged(double arg1) {
  wid->setVerticesThickness(arg1);
  wid->update();
}

void View::on_centralProjection_clicked() {
  wid->is_parallel_projection = false;
  wid->update();
}

void View::on_redLine_Verticles_valueChanged(double arg1) {
  wid->vertex_color.red = arg1;
  wid->update();
}

void View::on_greenLine_Verticles_valueChanged(double arg1) {
  wid->vertex_color.green = arg1;
  wid->update();
}

void View::on_blueLine_Verticles_valueChanged(double arg1) {
  wid->vertex_color.blue = arg1;
  wid->update();
}

void View::on_OpenFile_clicked() {
  QFileDialog dialog(this);
  dialog.setFileMode(QFileDialog::ExistingFile);
  fileName = dialog.getOpenFileName(this, "Выбрать файл", "../", "*.obj");
  auto& obj = wid->c.getObject();
  if (!fileName.isEmpty()) {
    obj.vertexes.clear();
    obj.lines.clear();
    ui->dSBMoveX->setValue(0.00);
    ui->dSBMoveY->setValue(0.00);
    ui->dSBMoveZ->setValue(0.00);

    ui->hRotate_x->setValue(0);
    ui->hRotate_y->setValue(0);
    ui->hRotate_z->setValue(0);

    ui->hScale->setValue(100);

    wid->c.parseFile(fileName.toStdString());
    wid->c.Normalization();
    wid->update();
    ui->filePath_label->setText(fileName);
    count_vetrexes_and_edges();
  }
}

void View::on_hMove_x_valueChanged(int value) {
  static float last_val = 0.0;
  wid->c.TransformModel(s21::MoveX, value / 100.0 - last_val);
  last_val = value / 100.0;
  wid->update();
  ui->dSBMoveX->setValue(last_val);
}

void View::on_dSBMoveX_valueChanged(double arg1) {
  int val = static_cast<int>(arg1 * 100);
  ui->hMove_x->setValue(val);
}

void View::on_hMove_y_valueChanged(int value) {
  static float last_val = 0.0;
  wid->c.TransformModel(s21::MoveY, value / 100.0 - last_val);
  last_val = value / 100.0;
  wid->update();
  ui->dSBMoveY->setValue(last_val);
}

void View::on_hMove_z_valueChanged(int value) {
  static float last_val = 0.0;
  wid->c.TransformModel(s21::MoveZ, value / 100.0 - last_val);
  last_val = value / 100.0;
  wid->update();
  ui->dSBMoveZ->setValue(last_val);
}

void View::on_dSBMoveY_valueChanged(double arg1) {
  int val = static_cast<int>(arg1 * 100);
  ui->hMove_y->setValue(val);
}

void View::on_dSBMoveZ_valueChanged(double arg1) {
  int val = static_cast<int>(arg1 * 100);
  ui->hMove_z->setValue(val);
}

void View::on_hRotate_x_valueChanged(int value) {
  static int last_val = 0;
  wid->c.TransformModel(s21::RotateX, value - last_val);
  last_val = value;
  wid->update();
  ui->sBRotateX->setValue(value);
}

void View::on_hRotate_y_valueChanged(int value) {
  static int last_val = 0;
  wid->c.TransformModel(s21::RotateY, value - last_val);
  last_val = value;
  wid->update();
  ui->sBRotateY->setValue(value);
}

void View::on_sBRotateX_valueChanged(int arg1) {
  ui->hRotate_x->setValue(arg1);
}

void View::on_sBRotateY_valueChanged(int arg1) {
  ui->hRotate_y->setValue(arg1);
}

void View::on_hRotate_z_valueChanged(int value) {
  static int last_val = 0;
  wid->c.TransformModel(s21::RotateZ, value - last_val);
  last_val = value;
  wid->update();
  ui->sBRotateZ->setValue(value);
}

void View::on_sBRotateZ_valueChanged(int arg1) {
  ui->hRotate_z->setValue(arg1);
}

void View::on_hScale_valueChanged(int value) {
  static double last_val = 1.0;
  wid->c.TransformModel(s21::SCALE, value / 100.0 / last_val);
  last_val = static_cast<double>(value * 1.0 / 100);
  wid->update();
  ui->dSBScale->setValue(last_val);
}

void View::on_dSBScale_valueChanged(double arg1) {
  int val = static_cast<int>(arg1 * 100);
  ui->hScale->setValue(val);
}

void View::saveSetting() {
  settings->setValue("lineColorRed", wid->line_color.red);
  settings->setValue("lineColorGreen", wid->line_color.green);
  settings->setValue("lineColorBlue", wid->line_color.blue);
  settings->setValue("lineThickness", wid->line_width);
  settings->setValue("lineType", wid->is_solid_line);

  settings->setValue("vertexColorRed", wid->vertex_color.red);
  settings->setValue("vertexColorGreen", wid->vertex_color.green);
  settings->setValue("vertexColorBlue", wid->vertex_color.blue);
  settings->setValue("vertexType", wid->vertex_type);
  settings->setValue("vertexThickness", wid->vertices_thickness);

  settings->setValue("backgroundColorRed", wid->background_color.red);
  settings->setValue("backgroundColorGreen", wid->background_color.green);
  settings->setValue("backgroundColorBlue", wid->background_color.blue);

  settings->setValue("projection", wid->is_parallel_projection);

  settings->setValue("filePath", ui->filePath_label->text());
}

void View::loadLineSettings() {
  QColor color;
  color.setRedF(settings->value("lineColorRed").toFloat());
  color.setGreenF(settings->value("lineColorGreen").toFloat());
  color.setBlueF(settings->value("lineColorBlue").toFloat());
  wid->line_color.red = color.redF();
  wid->line_color.green = color.greenF();
  wid->line_color.blue = color.blueF();
  ui->redLine->setValue(color.redF());
  ui->greenLine->setValue(color.greenF());
  ui->blueLine->setValue(color.blueF());

  wid->is_solid_line = settings->value("lineType").toBool();
  wid->line_width = settings->value("lineThickness").toFloat();
  ui->solidLine->setChecked(wid->is_solid_line);
  ui->dashedLine->setChecked(!wid->is_solid_line);
  ui->lineWidth->setValue(wid->line_width);
}

void View::loadVertexSettings() {
  QColor color;
  color.setRedF(settings->value("vertexColorRed").toFloat());
  color.setGreenF(settings->value("vertexColorGreen").toFloat());
  color.setBlueF(settings->value("vertexColorBlue").toFloat());
  wid->vertex_color.red = color.redF();
  wid->vertex_color.green = color.greenF();
  wid->vertex_color.blue = color.blueF();

  ui->redLine_Verticles->setValue(color.redF());
  ui->greenLine_Verticles->setValue(color.greenF());
  ui->blueLine_Verticles->setValue(color.blueF());

  int type = settings->value("vertexType").toInt();
  wid->vertex_type = type;
  switch (type) {
    case 0:
      ui->rdNoneVertices->setChecked(true);
      break;
    case 1:
      ui->rdCircleVertices->setChecked(true);
      break;
    case 2:
      ui->rdSquareVertices->setChecked(true);
    default:
      break;
  }

  wid->vertices_thickness = settings->value("vertexThickness").toFloat();
  ui->dSb_verticesSize->setValue(wid->vertices_thickness);
}

void View::loadBackgroundSettings() {
  QColor color;
  color.setRedF(settings->value("backgroundColorRed").toFloat());
  color.setGreenF(settings->value("backgroundColorGreen").toFloat());
  color.setBlueF(settings->value("backgroundColorBlue").toFloat());
  wid->background_color.red = color.redF();
  wid->background_color.green = color.greenF();
  wid->background_color.blue = color.blueF();
  ui->redBackground->setValue(color.redF());
  ui->greenBackground->setValue(color.greenF());
  ui->blueBackground->setValue(color.blueF());
}

void View::loadSettings() {
  loadLineSettings();
  loadVertexSettings();
  loadBackgroundSettings();

  wid->is_parallel_projection = settings->value("projection").toBool();
  ui->parallelProjection->setChecked(wid->is_parallel_projection);
  ui->centralProjection->setChecked(!wid->is_parallel_projection);
  ui->filePath_label->setText(settings->value("filePath").toString());
  if (!ui->filePath_label->text().isEmpty()) {
    wid->c.parseFile(ui->filePath_label->text().toStdString());
    wid->c.Normalization();
    count_vetrexes_and_edges();
  }
}
void View::count_vetrexes_and_edges() {
  auto& obj = wid->c.getObject();
  int count_v = obj.vertexes.size();
  int count_e = 0;
  for (auto& f : obj.lines) {
    int s = f.indexes.size();
    if (s == 2) {
      count_e += 1;
    } else if (s > 2) {
      count_e += s;
    }
  }
  QString v_str{"Vertexes: "};
  QString e_str{"Edges: "};
  v_str += QString::number(count_v) + "\n";
  e_str += QString::number(count_e);
  ui->countVertAndEdges->setText(v_str + e_str);
}

void View::on_pngButton_clicked() {
  wid->renderScene();
  QImage image = wid->grabFramebuffer();
  image.save("scene.jpeg");
}

void View::on_bmpButton_clicked() {
  wid->renderScene();
  QImage image = wid->grabFramebuffer();
  image.save("scene.bmp");
}

void View::on_gifButton_clicked() {
  gif = new QGifImage();
  gif->setDefaultDelay(33);
  timer->setInterval(33);
  timer->start();
}

void View::add_qimage_in_gif() {
  QImage image = wid->grabFramebuffer().scaled(640, 480);
  gif->addFrame(image);
  if (gif->frameCount() == 5 * 30) {
    gif->save("scene.gif");
    delete gif;
    timer->stop();
  }
}
