//
// Created by vinic on 21/06/2023.
//

#ifndef JOGODAVELHACOMARVORE_ARVORE_H
#define JOGODAVELHACOMARVORE_ARVORE_H
#include "Mapa.cpp"

struct JogadaMaquina{
    int col, lin;
};
struct Arvore {
    Mapa mapa;

    JogadaMaquina encontrarJogada();
    Arvore(Mapa mapa);
    int Minimax(int altura, bool rodada)

};



#endif //JOGODAVELHACOMARVORE_ARVORE_H
