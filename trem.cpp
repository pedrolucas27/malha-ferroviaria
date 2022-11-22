#include "trem.h"
#include <QtCore>
#include <QMutex>

#include "iostream"

int areaCritica1T1 = 0;
int areaCritica1T2 = 0;

int area0 = 0;

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
}


void logPontos(int areaCritica1T1, int areaCritica1T2){
    std::cout << "Logs: " << areaCritica1T1 << " , " << areaCritica1T2 << std::endl;
}

// Função a ser executada após executar trem->START
void Trem::run()
{
    QMutex mutex;

    while (true)
    {
        switch (ID)
        {
        case 1: // Trem 1
            if(!(checarEstaProximo(x, y, ID) && area0 == 1)){
                if(checarArea0(x, y, ID)){
                    area0 = 1;
                }else{
                    area0 = 0;
                }

                if (x < 330 && y == 30)
                {
                    x += 10;
                }
                else if (x == 330 && y < 150)
                {
                    y += 10;
                }
                else if (x > 60 && y == 150)
                {
                    x -= 10;
                }
                else
                {
                    y -= 10;
                }
                emit updateGUI(ID, x, y); // Emite um sinal
            }

            break;
        case 2: // Trem 2
            if (!(checarEstaProximo(x, y, ID) && area0 == 1)) {
                if(checarArea0(x, y, ID)){
                    area0 = 1;
                }else{
                    area0 = 0;
                }

                if (y == 30 && x < 600)
                    x += 10;
                else if (x == 600 && y < 150)
                    y += 10;
                else if (x > 330 && y == 150)
                    x -= 10;
                else
                {
                    y -= 10;
                }
                emit updateGUI(ID, x, y); // Emite um sinal
            }

            break;
        case 3: // Trem 3
            if (y == 30 && x < 870)
                x += 10;
            else if (x == 870 && y < 150)
                y += 10;
            else if (x > 600 && y == 150)
                x -= 10;
            else
                y -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;

        case 4: // Trem 4
            if (y == 150 && x < 460)
                x += 10;
            else if (x == 460 && y < 290)
                y += 10;
            else if (x > 190 && y == 290)
                x -= 10;
            else
                y -= 10;
            emit updateGUI(ID, x, y); // Emite um sinal
            break;

        case 5: // Trem 5
            if (y == 150 && x < 730)
                x += 10;
            else if (x == 730 && y < 290)
                y += 10;
            else if (x > 460 && y == 290)
                x -= 10;
            else
                y -= 10;
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

bool Trem::checarArea0(int x, int y, int ID)
{
    return (x == 330 && (y >= 30 && y <= 150));
}

bool Trem::checarEstaProximo(int x, int y, int ID){
    bool estaProximo = false;
    if(ID == 1){
        estaProximo = (x >= 310 && x < 330) && (y == 30);
    }else{
        estaProximo = (x <= 350 && x > 330) && (y == 150);
    }
    return estaProximo;
}
