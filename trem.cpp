#include "trem.h"
#include <QtCore>
#include <QMutex>

#include "iostream"

// Construtor
Trem::Trem(int ID, int x, int y)
{
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}


// Função a ser executada após executar trem->START
void Trem::run()
{
    while (true)
    {
        emit updateGUI(ID);
        msleep(velocidade);
    }
}

void Trem::set_velocidade(int valor_slider)
{
    velocidade = 200 - valor_slider;
}

void Trem::set_x(int x){
    this->x = x;
}

void Trem::set_y(int y){
    this->y = y;
}

int Trem::get_x(){
    return x;
}

int Trem::get_y(){
    return y;
}
