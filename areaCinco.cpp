#include "areaCinco.h"

AreaCinco::AreaCinco()
{
    m_ocupacao = 0;
}


void AreaCinco::bloquear(){
    m_ocupacao = 1;
}

void AreaCinco::desbloquear(){
    m_ocupacao = 0;
}

void AreaCinco::atualizarOcupacao(int x, int y){
    m_mutex.lock();
    if(ehAreaCritica(x, y)){
        bloquear();
    }else{
        desbloquear();
    }
    m_mutex.unlock();
}

int AreaCinco::get_ocupacao(){
    return m_ocupacao;
}

bool AreaCinco::ehAreaCritica(int x, int y){
    return (x >= 600 && x <= 730) && y == 150;
}

bool AreaCinco::checar_proximidade_area(int x, int y, int ID){
    if(ID == 3){
        return (x > 730 && x < 750) &&  y == 150;
    }

    return (x > 580 && x < 600) &&  y == 150;
}
