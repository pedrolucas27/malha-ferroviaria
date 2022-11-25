#include "areaQuatro.h"
#include "iostream"
AreaQuatro::AreaQuatro(){
    m_ocupacao = 0;
}

void AreaQuatro::bloquear(){
    m_ocupacao = 1;
}

void AreaQuatro::desbloquear(){
    m_ocupacao = 0;
}

void AreaQuatro::atualizarOcupacao(int x, int y){
    m_mutex.lock();
    if(ehAreaCritica(x, y)){
        bloquear();
    }else{
        desbloquear();
    }
    m_mutex.unlock();
}

int AreaQuatro::get_ocupacao(){
    return m_ocupacao;
}

bool AreaQuatro::ehAreaCritica(int x, int y){
    return y == 150 && (x >= 460 && x <= 600);;
}

bool AreaQuatro::checar_proximidade_area(int x, int y, int ID){
    if(ID == 5) {
        return x == 460 && (y >= 150 && y <= 170);
    }
    return x == 600 && (y >= 130 && y <= 150);
}
