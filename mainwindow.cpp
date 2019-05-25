#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //把背景设为黑色
    ui->label->clear();
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255, 0, 0));
    ui->label->setAutoFillBackground(true);  //一定要这句，否则不行,要绘制的图像区域
    ui->label->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//显示第一张图片
void MainWindow::on_First_clicked()
{
    QPixmap *pixmap = new QPixmap(":/images/picture_1.png");
    pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label->setScaledContents(true); //自适应窗口的大小
    ui->label->setPixmap(*pixmap);
}
//显示第二张图片
void MainWindow::on_Second_clicked()
{
    QPixmap *pixmap = new QPixmap(":/images/picture_2.png");
    pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(*pixmap);
}
