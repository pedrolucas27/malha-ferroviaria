#ifndef AREACINCO_H
#define AREACINCO_H

#include "QMutex"

class AreaCinco{
    public:
        AreaCinco();

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

#endif // AREACINCO_H
