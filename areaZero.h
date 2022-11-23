#ifndef AREAZERO_H
#define AREAZERO_H

#include "QMutex"
/**
 * condicao = 0 -> Trem 1 anda, Trem 2 para (se necessário)
 * condicao = 1 -> Trem 2 anda, Trem 1 para (se necessário)
 */

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



