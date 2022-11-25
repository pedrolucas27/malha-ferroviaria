#include "areaTres.h"

AreaTres::AreaTres(){
    m_ocupacao = 0;
}

void AreaTres::bloquear(){
    m_ocupacao = 1;
}

void AreaTres::desbloquear(){
    m_ocupacao = 0;
}

void AreaTres::atualizarOcupacao(int x, int y){
    m_mutex.lock();
    if(ehAreaCritica(x, y)){
        bloquear();
    }else{
        desbloquear();
    }
    m_mutex.unlock();
}

int AreaTres::get_ocupacao(){
    return m_ocupacao;
}

bool AreaTres::ehAreaCritica(int x, int y){
    return y == 150 && (x >= 330 && x <= 480);
}

bool AreaTres::checar_proximidade_area(int x, int y, int ID){
    if(ID == 2){
        return (x >= 460 && x <= 480) && y == 150;
    }
    return (x >= 310 && x <= 330) && y == 150;
}
