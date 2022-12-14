#ifndef AREAZERO_H
#define AREAZERO_H

#include "QMutex"

class AreaZero{
    public:
        AreaZero();

        void bloquear();

        void desbloquear();

        void atualizarOcupacao(int x, int y);

        bool checar_proximidade_area(int x, int y, int ID);

        bool ehAreaCritica(int x, int y);

        int get_ocupacao();

    private:
        int m_ocupacao;

        QMutex m_mutex;
};

#endif // AREAZERO_H



