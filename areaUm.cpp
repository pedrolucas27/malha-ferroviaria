#include "areaUm.h"

AreaUm::AreaUm(){
    m_ocupacao = 0;
}

void AreaUm::bloquear(){
    m_ocupacao = 1;
}

void AreaUm::desbloquear(){
    m_ocupacao = 0;
}

void AreaUm::atualizarOcupacao(int x, int y){
    m_mutex.lock();
    if(ehAreaCritica(x, y)){
        bloquear();
    }else{
        desbloquear();
    }
    m_mutex.unlock();
}

int AreaUm::get_ocupacao(){
    return m_ocupacao;
}

bool AreaUm::ehAreaCritica(int x, int y){
    return x == 600 && (y >= 30 && y <= 150);
}

bool AreaUm::checar_proximidade_area(int x, int y, int ID){
    if(ID == 2) return (x >= 580 && x <= 600) && (y == 30);
    return (x <= 620 && x >= 600) && (y == 150);
}

