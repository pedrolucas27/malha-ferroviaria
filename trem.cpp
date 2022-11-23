#include "trem.h"
#include <QtCore>
#include <QMutex>

#include "iostream"

QMutex mutexArea0;
int stopArea0 = 0;

/*
 * 0 -> NÃO TEM NINGUÉM NO TRILHO
 * 1 -> TRILHO OCUPADO
 */

// Construtor
Trem::Trem(int ID, int x, int y)
{
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
    //a0 = new AreaZero(&stopArea0);
}


// Função a ser executada após executar trem->START
void Trem::run()
{
    while (true)
    {
        switch (ID)
        {
        case 1: // Trem 1
            /*if(!(a0->checar_proximidade_area(x, y, ID) && a0->get_condicao() == 1)){
                a0->atualizarOcupacao(x, y); // -> usar mutex aqui

                if (x < 330 && y == 30)
                    x += 10;
                else if (x == 330 && y < 150)
                    y += 10;
                else if (x > 60 && y == 150)
                    x -= 10;
                else
                    y -= 10;
                emit updateGUI(ID, x, y); // Emite um sinal
            }*/
            emit updateGUI(ID, x, y); // Emite um sinal

            break;
        case 2: // Trem 2
            /*if (!(a0->checar_proximidade_area(x, y, ID) && a0->get_condicao() == 1)) {
                a0->atualizarOcupacao(x, y);

                if (y == 30 && x < 600)
                    x += 10;
                else if (x == 600 && y < 150)
                    y += 10;
                else if (x > 330 && y == 150)
                    x -= 10;
                else
                    y -= 10;
                emit updateGUI(ID, x, y); // Emite um sinal
            }*/
            emit updateGUI(ID, x, y); // Emite um sinal

            break;
        case 3: // Trem 3
            /*if (y == 30 && x < 870)
                x += 10;
            else if (x == 870 && y < 150)
                y += 10;
            else if (x > 600 && y == 150)
                x -= 10;
            else
                y -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal
            */
            emit updateGUI(ID, x, y); // Emite um sinal
            break;

        case 4: // Trem 4
            /*if (y == 150 && x < 460)
                x += 10;
            else if (x == 460 && y < 290)
                y += 10;
            else if (x > 190 && y == 290)
                x -= 10;
            else
                y -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal*/
            emit updateGUI(ID, x, y); // Emite um sinal
            break;

        case 5: // Trem 5
            /*if (y == 150 && x < 730)
                x += 10;
            else if (x == 730 && y < 290)
                y += 10;
            else if (x > 460 && y == 290)
                x -= 10;
            else
                y -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal*/
            emit updateGUI(ID, x, y); // Emite um sinal
            break;
        default:
            break;
        }
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
