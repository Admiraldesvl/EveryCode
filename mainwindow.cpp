#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//------Parameters of QR code-------//
// Every time these parameters are changed,
// this program tries to generate a new code.

// Whether the qrcode is case-sensitive or not.
void MainWindow::on_checkBox_stateChanged(int arg1)
{
   if(arg1==Qt::Checked)
       MainWindow::case_sensitive = 1;
   else
       MainWindow::case_sensitive = 0;
   on_pushButton_2_clicked(); // Call this function to generate again.
}

// The version of it, which mainly decides its size.
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
   MainWindow::qr_version = value + 1;
   on_pushButton_2_clicked();
}

// The error correction level of it. The higher it is, the more information can be restored.
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
   MainWindow::er_correction = index;
   on_pushButton_2_clicked();
}

//-----------------------------------//
// To generate QR code by clicking push button 2.
void MainWindow::on_pushButton_2_clicked()
{
   if(ui->lineEdit->text().isEmpty())
   {
       q = 0;
   }
   else
   {
       generator g;
        q = g.encode_String(ui->lineEdit->text().toStdString().c_str(),\
                            MainWindow::qr_version,\
                            MainWindow::er_correction,\
                            MainWindow::case_sensitive);
   }
   update(); // This function evokes paintEvent.
}

// Paint it on the screen.
void MainWindow::paintEvent(QPaintEvent *event){
//-----Draw the backbround first-----//
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRect(0,0,300,300);
    if(q==0) // If q is empty, nothing will happen.
        return;

//-----------------------------------//
    painter.setBrush(Qt::black); // Ready to draw black blocks.
    double scale = 300.0/q->width; // The size of each block.
    for(int y=0;y<q->width;y++)
        for(int x=0;x<q->width;x++)
        {
           unsigned char b = q->data[y*q->width+x];
           if(b & 0x01) // If the last character of b is '1', then draw a black block.
           {
              QRectF r(x*scale,y*scale,scale,scale);
              painter.drawRects(&r, 1);
           }
        }
}
