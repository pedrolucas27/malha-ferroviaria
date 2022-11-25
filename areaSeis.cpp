#include "areaSeis.h"

AreaSeis::AreaSeis(){
    m_ocupacao = 0;
}

void AreaSeis::bloquear(){
    m_ocupacao = 1;
}

void AreaSeis::desbloquear(){
    m_ocupacao = 0;
}

void AreaSeis::atualizarOcupacao(int x, int y){
    m_mutex.lock();
    if(ehAreaCritica(x, y)){
        bloquear();
    }else{
        desbloquear();
    }
    m_mutex.unlock();
}

int AreaSeis::get_ocupacao(){
    return m_ocupacao;
}

bool AreaSeis::ehAreaCritica(int x, int y){
    return x == 460 && (y >= 150 && y <= 290);
}

bool AreaSeis::checar_proximidade_area(int x, int y, int ID){
    if(ID == 5){
        return (x >= 460 && x <= 480) && y == 290;
    }
    return (x >= 440 && x <= 460) && y == 150;
}
