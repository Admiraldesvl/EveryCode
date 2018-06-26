#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "qrencode.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
/* Key parameters of QR code */
    int case_sensitive=0;
    int qr_version=1;
    int er_correction=0;
/* Reminder: The parameter about Japanese Kanji is left out */
private slots: // Functions that deal with widgets' events.
    void on_checkBox_stateChanged(int arg1);
    void on_horizontalSlider_valueChanged(int value);
    void on_comboBox_currentIndexChanged(int index);
    void on_pushButton_2_clicked();// To generate the code.
private:
    QRecLevel ECLEVEL(int lvl);
    Ui::MainWindow *ui;
    QRcode *q;
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
