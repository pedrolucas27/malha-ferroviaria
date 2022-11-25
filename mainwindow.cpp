#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mf = new MalhaFerroviaria();

    connect(mf->get_trem1(),SIGNAL(updateGUI(int)),SLOT(updateInterface(int)));
    connect(mf->get_trem2(),SIGNAL(updateGUI(int)),SLOT(updateInterface(int)));
    connect(mf->get_trem3(),SIGNAL(updateGUI(int)),SLOT(updateInterface(int)));
    connect(mf->get_trem4(),SIGNAL(updateGUI(int)),SLOT(updateInterface(int)));
    connect(mf->get_trem5(),SIGNAL(updateGUI(int)),SLOT(updateInterface(int)));

}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id){
    mf->strategy(id);

    switch(id){
        case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
            ui->label_trem1->setGeometry(mf->get_trem1()->get_x(),mf->get_trem1()->get_y(),21,17);
            break;
        case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
            ui->label_trem2->setGeometry(mf->get_trem2()->get_x(),mf->get_trem2()->get_y(),21,17);
            break;
        case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
            ui->label_trem3->setGeometry(mf->get_trem3()->get_x(),mf->get_trem3()->get_y(),21,17);
            break;
        case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
            ui->label_trem4->setGeometry(mf->get_trem4()->get_x(),mf->get_trem4()->get_y(),21,17);
            break;
        case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
            ui->label_trem5->setGeometry(mf->get_trem5()->get_x(),mf->get_trem5()->get_y(),21,17);
            break;
        default:
            break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_slider_trem_t1_sliderMoved(int position)
{
    mf->get_trem1()->set_velocidade(position);
}

void MainWindow::on_slider_trem_t2_sliderMoved(int position)
{
    mf->get_trem2()->set_velocidade(position);
}

void MainWindow::on_slider_trem_t3_sliderMoved(int position)
{
    mf->get_trem3()->set_velocidade(position);
}

void MainWindow::on_slider_trem_t4_sliderMoved(int position)
{
    mf->get_trem4()->set_velocidade(position);
}

void MainWindow::on_slider_trem_t5_sliderMoved(int position)
{
    mf->get_trem5()->set_velocidade(position);
}
