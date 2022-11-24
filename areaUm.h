#ifndef AREAUM_H
#define AREAUM_H

#include "QMutex"

class AreaUm{
    public:
        AreaUm();

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

#endif // AREAUM_H
