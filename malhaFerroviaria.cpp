#include "malhaFerroviaria.h"

MalhaFerroviaria::MalhaFerroviaria(){
    trem1 = new Trem(1,60,30);
    trem2 = new Trem(2,330,30);
    trem3 = new Trem(3,600,30);
    trem4 = new Trem(4,190,150);
    trem5 = new Trem(5,460,150);

    area0 = new AreaZero();
    area1 = new AreaUm();
    area2 = new AreaDois();
    area3 = new AreaTres();
    area4 = new AreaQuatro();
    area5 = new AreaCinco();
    area6 = new AreaSeis();

    init_threads();
}

Trem* MalhaFerroviaria::get_trem1(){
    return trem1;
}

Trem* MalhaFerroviaria::get_trem2(){
    return trem2;
}

Trem* MalhaFerroviaria::get_trem3(){
    return trem3;
}

Trem* MalhaFerroviaria::get_trem4(){
    return trem4;
}

Trem* MalhaFerroviaria::get_trem5(){
    return trem5;
}

void MalhaFerroviaria::init_threads(){
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}


void MalhaFerroviaria::movimentar_trem1(){
    if (trem1->get_x() < 330 && trem1->get_y() == 30)
        trem1->set_x(trem1->get_x() + 10);
    else if (trem1->get_x() == 330 && trem1->get_y() < 150)
        trem1->set_y(trem1->get_y() + 10);
    else if (trem1->get_x() > 60 && trem1->get_y() == 150)
        trem1->set_x(trem1->get_x() - 10);
    else
        trem1->set_y(trem1->get_y() - 10);
}

void MalhaFerroviaria::movimentar_trem2(){
    if (trem2->get_x() < 600 && trem2->get_y() == 30)
        trem2->set_x(trem2->get_x() + 10);
    else if (trem2->get_x() == 600 && trem2->get_y() < 150)
        trem2->set_y(trem2->get_y() + 10);
    else if (trem2->get_x() > 330 && trem2->get_y() == 150)
        trem2->set_x(trem2->get_x() - 10);
    else
        trem2->set_y(trem2->get_y() - 10);
}

void MalhaFerroviaria::movimentar_trem3(){
    if (trem3->get_x() < 870 && trem3->get_y() == 30)
        trem3->set_x(trem3->get_x() + 10);
    else if (trem3->get_x() == 870 && trem3->get_y() < 150)
        trem3->set_y(trem3->get_y() + 10);
    else if (trem3->get_x() > 600 && trem3->get_y() == 150)
        trem3->set_x(trem3->get_x() - 10);
    else
        trem3->set_y(trem3->get_y() - 10);
}

void MalhaFerroviaria::movimentar_trem4(){
    if (trem4->get_x() < 460 && trem4->get_y() == 150)
        trem4->set_x(trem4->get_x() + 10);
    else if (trem4->get_x() == 460 && trem4->get_y() < 290)
        trem4->set_y(trem4->get_y() + 10);
    else if (trem4->get_x() > 190 && trem4->get_y() == 290)
        trem4->set_x(trem4->get_x() - 10);
    else
        trem4->set_y(trem4->get_y() - 10);
}

void MalhaFerroviaria::movimentar_trem5(){
    if (trem5->get_x() < 730 && trem5->get_y() == 150)
        trem5->set_x(trem5->get_x() + 10);
    else if (trem5->get_x() == 730 && trem5->get_y() < 290)
        trem5->set_y(trem5->get_y() + 10);
    else if (trem5->get_x() > 460 && trem5->get_y() == 290)
        trem5->set_x(trem5->get_x() - 10);
    else
        trem5->set_y(trem5->get_y() - 10);
}

void MalhaFerroviaria::strategy(int ID){
    switch (ID){
        case 1: // Trem 1
            if(area0->checar_proximidade_area(trem1->get_x(), trem1->get_y(), ID)){
                if(!(area0->get_ocupacao() == 1)){
                    area0->atualizarOcupacao(trem1->get_x(), trem1->get_y()); // -> usar mutex aqui
                    movimentar_trem1();
                }
            }else if(area2->checar_proximidade_area(trem1->get_x(), trem1->get_y(), ID)){
                if(!(area2->get_ocupacao() == 1)){
                    area2->atualizarOcupacao(trem1->get_x(), trem1->get_y()); // -> usar mutex aqui
                    movimentar_trem1();
                }
            }else{
                area0->atualizarOcupacao(trem1->get_x(), trem1->get_y());
                area2->atualizarOcupacao(trem1->get_x(), trem1->get_y());
                movimentar_trem1();
            }

            break;
        case 2: // Trem 2
            if(area0->checar_proximidade_area(trem2->get_x(), trem2->get_y(), ID)){
                if(!(area0->get_ocupacao() == 1)){
                    area0->atualizarOcupacao(trem2->get_x(), trem2->get_y()); // -> usar mutex aqui
                    movimentar_trem2();
                }
            }else if(area1->checar_proximidade_area(trem2->get_x(), trem2->get_y(), ID)){
                if(!(area1->get_ocupacao() == 1)){
                    area1->atualizarOcupacao(trem2->get_x(), trem2->get_y()); // -> usar mutex aqui
                    movimentar_trem2();
                }
            }else if(area3->checar_proximidade_area(trem2->get_x(), trem2->get_y(), ID)){
                if(!(area3->get_ocupacao() == 1)){
                    area3->atualizarOcupacao(trem2->get_x(), trem2->get_y()); // -> usar mutex aqui
                    movimentar_trem2();
                }
            }else if(area4->checar_proximidade_area(trem2->get_x(), trem2->get_y(), ID)){
                if(!(area4->get_ocupacao() == 1)){
                    area4->atualizarOcupacao(trem2->get_x(), trem2->get_y()); // -> usar mutex aqui
                    movimentar_trem2();
                }
            }else{
                area0->atualizarOcupacao(trem2->get_x(), trem2->get_y());
                area1->atualizarOcupacao(trem2->get_x(), trem2->get_y());
                area3->atualizarOcupacao(trem2->get_x(), trem2->get_y());
                area4->atualizarOcupacao(trem2->get_x(), trem2->get_y());

                movimentar_trem2();
            }
            break;
        case 3: // Trem 3
            if(area1->checar_proximidade_area(trem3->get_x(), trem3->get_y(), ID)){
                if(!(area1->get_ocupacao() == 1)){
                    area1->atualizarOcupacao(trem3->get_x(), trem3->get_y()); // -> usar mutex aqui
                    movimentar_trem3();
                }
            }else if(area5->checar_proximidade_area(trem3->get_x(), trem3->get_y(), ID)){
                if(!(area5->get_ocupacao() == 1)){
                    area5->atualizarOcupacao(trem3->get_x(), trem3->get_y()); // -> usar mutex aqui
                    movimentar_trem3();
                }
            }else{
                area1->atualizarOcupacao(trem3->get_x(), trem3->get_y()); // -> usar mutex aqui
                area5->atualizarOcupacao(trem3->get_x(), trem3->get_y()); // -> usar mutex aqui
                movimentar_trem3();
            }
            break;
        case 4: // Trem 4
            if(area6->checar_proximidade_area(trem4->get_x(), trem4->get_y(), ID)){
                if(!(area6->get_ocupacao() == 1)){
                    area6->atualizarOcupacao(trem4->get_x(), trem4->get_y()); // -> usar mutex aqui
                    movimentar_trem4();
                }
            }else if(area2->checar_proximidade_area(trem4->get_x(), trem4->get_y(), ID)){
                if(!(area2->get_ocupacao() == 1)){
                    area2->atualizarOcupacao(trem4->get_x(), trem4->get_y()); // -> usar mutex aqui
                    movimentar_trem4();
                }
            }else if(area3->checar_proximidade_area(trem4->get_x(), trem4->get_y(), ID)){
                if(!(area3->get_ocupacao() == 1)){
                    area3->atualizarOcupacao(trem4->get_x(), trem4->get_y()); // -> usar mutex aqui
                    movimentar_trem4();
                }
            }else{
                area6->atualizarOcupacao(trem4->get_x(), trem4->get_y());
                area2->atualizarOcupacao(trem4->get_x(), trem4->get_y());
                area3->atualizarOcupacao(trem4->get_x(), trem4->get_y());
                movimentar_trem4();
            }

            break;
        case 5: // Trem 5
            if(area4->checar_proximidade_area(trem5->get_x(), trem5->get_y(), ID)){
                if(!(area4->get_ocupacao() == 1)){
                    area4->atualizarOcupacao(trem5->get_x(), trem5->get_y()); // -> usar mutex aqui
                    movimentar_trem5();
                }
            }else if(area5->checar_proximidade_area(trem5->get_x(), trem5->get_y(), ID)){
                if(!(area5->get_ocupacao() == 1)){
                    area5->atualizarOcupacao(trem5->get_x(), trem5->get_y()); // -> usar mutex aqui
                    movimentar_trem5();
                }
            }
            else if(area6->checar_proximidade_area(trem5->get_x(), trem5->get_y(), ID)){
                if(!(area6->get_ocupacao() == 1)){
                    area6->atualizarOcupacao(trem5->get_x(), trem5->get_y()); // -> usar mutex aqui
                    movimentar_trem5();
                }
            }else{
                area4->atualizarOcupacao(trem5->get_x(), trem5->get_y()); // -> usar mutex aqui
                area6->atualizarOcupacao(trem5->get_x(), trem5->get_y()); // -> usar mutex aqui
                area5->atualizarOcupacao(trem5->get_x(), trem5->get_y()); // -> usar mutex aqui
                movimentar_trem5();
            }

            break;
        default:
            break;
    }
}

