#include "areaZero.h"

AreaZero::AreaZero(){
    m_ocupacao = 0;
}

void AreaZero::bloquear(){
    m_ocupacao = 1;
}

void AreaZero::desbloquear(){
    m_ocupacao = 0;
}

void AreaZero::atualizarOcupacao(int x, int y){
    m_mutex.lock();
    if(ehAreaCritica(x, y)){
        bloquear();
    }else{
        desbloquear();
    }
    m_mutex.unlock();
}

int AreaZero::get_ocupacao(){
    return m_ocupacao;
}

bool AreaZero::ehAreaCritica(int x, int y){
    return x == 330 && (y >= 30 && y <= 150);
}

bool AreaZero::checar_proximidade_area(int x, int y, int ID){
    if(ID == 1) return (x >= 310 && x <= 330) && (y == 30);
    return (x <= 350 && x >= 330) && (y == 150);
}

