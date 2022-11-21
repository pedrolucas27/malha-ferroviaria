#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

    void startAll();

private slots:
    void on_slider_trem_t1_sliderMoved(int position);

    void on_slider_trem_t2_sliderMoved(int position);

    void on_slider_trem_t3_sliderMoved(int position);

    void on_slider_trem_t4_sliderMoved(int position);

    void on_slider_trem_t5_sliderMoved(int position);


private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
};

#endif // MAINWINDOW_H
