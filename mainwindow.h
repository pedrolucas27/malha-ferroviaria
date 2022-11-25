#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "trem.h"
#include "areaZero.h"
#include "areaUm.h"
#include "areaSeis.h"
#include "areaDois.h"
#include "areaTres.h"

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
    void updateInterface(int);

    void startAll();

    void strategy(int);

    void andar_trem1();

    void andar_trem2();

    void andar_trem3();

    void andar_trem4();

    void andar_trem5();

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

    AreaZero *area0;
    AreaUm   *area1;
    AreaDois *area2;
    AreaTres *area3;
    AreaSeis *area6;
};

#endif // MAINWINDOW_H
