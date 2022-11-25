#include "areaDois.h"

AreaDois::AreaDois()
{
    m_ocupacao = 0;
}


void AreaDois::bloquear(){
    m_ocupacao = 1;
}

void AreaDois::desbloquear(){
    m_ocupacao = 0;
}

void AreaDois::atualizarOcupacao(int x, int y){
    m_mutex.lock();
    if(ehAreaCritica(x, y)){
        bloquear();
    }else{
        desbloquear();
    }
    m_mutex.unlock();
}

int AreaDois::get_ocupacao(){
    return m_ocupacao;
}

bool AreaDois::ehAreaCritica(int x, int y){
    return y == 150 && (x >= 190 && x <= 330);
}

bool AreaDois::checar_proximidade_area(int x, int y, int ID){
    if(ID == 4) return (y >= 130 && y <= 150) && (x == 190);
    return (y <= 170 && y >= 150) && (x == 330);
}
