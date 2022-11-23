#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,60,30);
    trem2 = new Trem(2,330,30);
    trem3 = new Trem(3,600,30);
    trem4 = new Trem(4,190,150);
    trem5 = new Trem(5,460,150);

    area0 = new AreaZero();
    area1 = new AreaOne();
    startAll();

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */

    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    strategy(id);

    switch(id){
        case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
            ui->label_trem1->setGeometry(trem1->get_x(),trem1->get_y(),21,17);
            break;
        case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
            ui->label_trem2->setGeometry(trem2->get_x(),trem2->get_y(),21,17);
            break;
        case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
            ui->label_trem3->setGeometry(trem3->get_x(),trem3->get_y(),21,17);
            break;
        case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
            ui->label_trem4->setGeometry(trem4->get_x(),trem4->get_y(),21,17);
            break;
        case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
            ui->label_trem5->setGeometry(trem5->get_x(),trem5->get_y(),21,17);
            break;
        default:
            break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */
void MainWindow::startAll()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

void MainWindow::on_slider_trem_t1_sliderMoved(int position)
{
    trem1->set_velocidade(position);
}

void MainWindow::on_slider_trem_t2_sliderMoved(int position)
{
    trem2->set_velocidade(position);
}

void MainWindow::on_slider_trem_t3_sliderMoved(int position)
{
    trem3->set_velocidade(position);
}

void MainWindow::on_slider_trem_t4_sliderMoved(int position)
{
    trem4->set_velocidade(position);
}

void MainWindow::on_slider_trem_t5_sliderMoved(int position)
{
    trem5->set_velocidade(position);
}

void MainWindow::andar_trem1(){
    if (trem1->get_x() < 330 && trem1->get_y() == 30)
        trem1->set_x(trem1->get_x() + 10);
    else if (trem1->get_x() == 330 && trem1->get_y() < 150)
        trem1->set_y(trem1->get_y() + 10);
    else if (trem1->get_x() > 60 && trem1->get_y() == 150)
        trem1->set_x(trem1->get_x() - 10);
    else
        trem1->set_y(trem1->get_y() - 10);
}

void MainWindow::andar_trem2(){
    if (trem2->get_x() < 600 && trem2->get_y() == 30)
        trem2->set_x(trem2->get_x() + 10);
    else if (trem2->get_x() == 600 && trem2->get_y() < 150)
        trem2->set_y(trem2->get_y() + 10);
    else if (trem2->get_x() > 330 && trem2->get_y() == 150)
        trem2->set_x(trem2->get_x() - 10);
    else
        trem2->set_y(trem2->get_y() - 10);
}

void MainWindow::andar_trem3(){
    if (trem3->get_x() < 870 && trem3->get_y() == 30)
        trem3->set_x(trem3->get_x() + 10);
    else if (trem3->get_x() == 870 && trem3->get_y() < 150)
        trem3->set_y(trem3->get_y() + 10);
    else if (trem3->get_x() > 600 && trem3->get_y() == 150)
        trem3->set_x(trem3->get_x() - 10);
    else
        trem3->set_y(trem3->get_y() - 10);
}

void MainWindow::andar_trem4(){
    if (trem4->get_x() < 460 && trem4->get_y() == 150)
        trem4->set_x(trem4->get_x() + 10);
    else if (trem4->get_x() == 460 && trem4->get_y() < 290)
        trem4->set_y(trem4->get_y() + 10);
    else if (trem4->get_x() > 190 && trem4->get_y() == 290)
        trem4->set_x(trem4->get_x() - 10);
    else
        trem4->set_y(trem4->get_y() - 10);
}

void MainWindow::andar_trem5(){
    if (trem5->get_x() < 730 && trem5->get_y() == 150)
        trem5->set_x(trem5->get_x() + 10);
    else if (trem5->get_x() == 730 && trem5->get_y() < 290)
        trem5->set_y(trem5->get_y() + 10);
    else if (trem5->get_x() > 460 && trem5->get_y() == 290)
        trem5->set_x(trem5->get_x() - 10);
    else
        trem5->set_y(trem5->get_y() - 10);
}

void MainWindow::strategy(int ID){
    switch (ID){
        case 1: // Trem 1
            if(!(area0->checar_proximidade_area(trem1->get_x(), trem1->get_y(), ID) && area0->get_ocupacao() == 1)){
                area0->atualizarOcupacao(trem1->get_x(), trem1->get_y()); // -> usar mutex aqui
                andar_trem1();
            }
            break;
        case 2: // Trem 2
            if(area0->checar_proximidade_area(trem2->get_x(), trem2->get_y(), ID)){
                if(!(area0->get_ocupacao() == 1)){
                    area0->atualizarOcupacao(trem2->get_x(), trem2->get_y()); // -> usar mutex aqui
                    andar_trem2();
                }
            }else if(area1->checar_proximidade_area(trem2->get_x(), trem2->get_y(), ID)){
                if(!(area1->get_ocupacao() == 1)){
                    area1->atualizarOcupacao(trem2->get_x(), trem2->get_y()); // -> usar mutex aqui
                    andar_trem2();
                }
            }else{
                area0->atualizarOcupacao(trem2->get_x(), trem2->get_y());
                area1->atualizarOcupacao(trem2->get_x(), trem2->get_y());
                andar_trem2();
            }
            break;
        case 3: // Trem 3
            if(area1->checar_proximidade_area(trem3->get_x(), trem3->get_y(), ID)){
                if(!(area1->get_ocupacao() == 1)){
                    area1->atualizarOcupacao(trem3->get_x(), trem3->get_y()); // -> usar mutex aqui
                    andar_trem3();
                }
            }else{
                area1->atualizarOcupacao(trem3->get_x(), trem3->get_y()); // -> usar mutex aqui
                andar_trem3();
            }
            break;
        case 4: // Trem 4
            andar_trem4();
            break;

        case 5: // Trem 5
            andar_trem5();
            break;
        default:
            break;
    }
}
