#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "malhaFerroviaria.h"

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

private slots:
    void on_slider_trem_t1_sliderMoved(int position);

    void on_slider_trem_t2_sliderMoved(int position);

    void on_slider_trem_t3_sliderMoved(int position);

    void on_slider_trem_t4_sliderMoved(int position);

    void on_slider_trem_t5_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    MalhaFerroviaria *mf;

    QString intToQString(int);
};

#endif // MAINWINDOW_H
