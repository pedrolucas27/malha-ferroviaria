#ifndef AREAQUATRO_H
#define AREAQUATRO_H

#include "QMutex"

class AreaQuatro {
    public:
        AreaQuatro();

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

#endif // AREAQUATRO_H
