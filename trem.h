#ifndef TREM_H
#define TREM_H

#include <QThread>
#include "areaZero.h"

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int,int,int);  //construtor
    void run();         //função a ser executada pela thread

    void set_velocidade(int valor_slider);

    bool checarArea0(int x, int y, int ID);

    bool checarEstaProximo(int x, int y, int ID);

    void set_x(int x);

    void set_y(int y);

    int get_x();

    int get_y();


//Cria um sinal
signals:
    void updateGUI(int,int,int);
    //void updateGUI(int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;          //ID do trem
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem

   //AreaZero *a0;
};

#endif // TREM_H
