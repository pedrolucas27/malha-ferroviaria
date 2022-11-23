#include "areaOne.h"

AreaOne::AreaOne(){
    m_ocupacao = 0;
}

void AreaOne::bloquear(){
    m_ocupacao = 1;
}

void AreaOne::desbloquear(){
    m_ocupacao = 0;
}

void AreaOne::atualizarOcupacao(int x, int y){
    m_mutex.lock();
    if(ehAreaCritica(x, y)){
        bloquear();
    }else{
        desbloquear();
    }
    m_mutex.unlock();
}

int AreaOne::get_ocupacao(){
    return m_ocupacao;
}

bool AreaOne::ehAreaCritica(int x, int y){
    return x == 600 && (y >= 30 && y <= 150);
}

bool AreaOne::checar_proximidade_area(int x, int y, int ID){
    if(ID == 2) return (x >= 580 && x <= 600) && (y == 30);
    return (x <= 620 && x >= 600) && (y == 150);
}

