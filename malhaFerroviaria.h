#ifndef MALHAFERROVIARIA_H
#define MALHAFERROVIARIA_H

#include "trem.h"

#include "areaZero.h"
#include "areaUm.h"
#include "areaDois.h"
#include "areaTres.h"
#include "areaQuatro.h"
#include "areaCinco.h"
#include "areaSeis.h"

class MalhaFerroviaria{
    public:
        MalhaFerroviaria();

        void strategy(int);

        void movimentar_trem1();

        void movimentar_trem2();

        void movimentar_trem3();

        void movimentar_trem4();

        void movimentar_trem5();

        Trem* get_trem1();
        Trem* get_trem2();
        Trem* get_trem3();
        Trem* get_trem4();
        Trem* get_trem5();

    private:
        Trem *trem1;
        Trem *trem2;
        Trem *trem3;
        Trem *trem4;
        Trem *trem5;

        AreaZero *area0;
        AreaUm   *area1;
        AreaDois *area2;
        AreaTres *area3;
        AreaQuatro *area4;
        AreaCinco *area5;
        AreaSeis *area6;

        void init_threads();
};

#endif // MALHAFERROVIARIA_H
