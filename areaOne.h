#ifndef AREAONE_H
#define AREAONE_H
#include "QMutex"
/**
 * condicao = 0 -> Trem 2 anda, Trem 3 para (se necessário)
 * condicao = 1 -> Trem 3 anda, Trem 2 para (se necessário)
 */

class AreaOne{
    public:
        AreaOne();

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

#endif // AREAONE_H
