//
// Created by vinic on 21/06/2023.
//

#ifndef JOGODAVELHACOMARVORE_ARVORE_H
#define JOGODAVELHACOMARVORE_ARVORE_H
#include "Mapa.h"

struct JogadaMaquina{
    int col, lin;
};

struct Arvore {
    Mapa mapa;

    JogadaMaquina encontrarJogada();
    int Minimax(int altura, bool rodada);

};


int Arvore::Minimax(int altura, bool rodada) {
    if (this->mapa.Vitoria('X'))
        return 1;
    if (this->mapa.Vitoria('O'))
        return -1;
    if (this->mapa.MapaCheio())
        return 0;

    if (rodada) {
        int melhorPonto = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(this->mapa.mapa[i][j] == ' ') {
                    this->mapa.mapa[i][j] = 'X';
                    int score = Minimax(altura + 1, false);
                    this->mapa.mapa[i][j] = ' ';
                    if (score > melhorPonto) {
                        melhorPonto = score;
                    } else {
                        melhorPonto = melhorPonto;
                    }
                }
            }
        }
        return melhorPonto;
    } else {
        int melhorPonto = 1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (this->mapa.mapa[i][j] == ' ') {
                    this->mapa.mapa[i][j] = 'O';
                    int score = Minimax(altura + 1, true);
                    this->mapa.mapa[i][j] = ' ';
                    if(score < melhorPonto) melhorPonto = score;
                    else melhorPonto = melhorPonto;
                }
            }
        }
        return melhorPonto;
    }
}

JogadaMaquina Arvore::encontrarJogada() {
    int melhorPonto = -1000;
    JogadaMaquina melhorJogada;
    melhorJogada.lin = -1;
    melhorJogada.col = -1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (this->mapa.mapa[i][j] == ' ') {
                this->mapa.mapa[i][j] = 'X';
                int score = Minimax(0, false);
                this->mapa.mapa[i][j] = ' ';
                if (score > melhorPonto) {
                    melhorPonto = score;
                    melhorJogada.lin = i;
                    melhorJogada.col = j;
                }
            }
        }
    }
    return melhorJogada;
}


#endif //JOGODAVELHACOMARVORE_ARVORE_H
