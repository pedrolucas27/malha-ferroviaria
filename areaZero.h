#ifndef AREAZERO_H
#define AREAZERO_H

/**
 * condicao = 0 -> Trem 1 anda, Trem 2 para (se necessário)
 * condicao = 1 -> Trem 2 anda, Trem 1 para (se necessário)
 */

class AreaZero{
    public:
        AreaZero(int condicao = 0);

        int chacar_condicao();

        //Mutex mutex;
    private:
        int m_condicao;

        void bloquear();

        void desbloquear();
};

#endif // AREAZERO_H



