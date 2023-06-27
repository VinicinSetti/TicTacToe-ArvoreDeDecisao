//
// Created by vinic on 21/06/2023.
//

#ifndef JOGODAVELHACOMARVORE_ARVORE_H
#define JOGODAVELHACOMARVORE_ARVORE_H
#include "Mapa.h"

struct Arvore {
    Mapa mapa;

    void encontrarJogada();
    int Minimax(int altura, bool rodada);

};

int Arvore::Minimax(int altura, bool rodada) {
    if (this->mapa.Vitoria('O'))
        return 1;
    if (this->mapa.Vitoria('X'))
        return -1;
    if (this->mapa.MapaCheio())
        return 0;

    if (rodada) {
        int melhorPonto = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(this->mapa.Get(i, j) == ' ') {
                    this->mapa.Set(i, j, 'O');
                    this->mapa.Print();
                    int score = Minimax(altura + 1, false);
                    this->mapa.Set(i, j, ' ');
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
                if (this->mapa.Get(i, j) == ' ') {
                    this->mapa.Set(i, j, 'X');
                    this->mapa.Print();
                    int score = Minimax(altura + 1, true);
                    this->mapa.mapa[i][j] = ' ';
                    if(score < melhorPonto) {
                        melhorPonto = score;
                    }
                    else {
                        melhorPonto = melhorPonto;
                    }
                }
            }
        }
        return melhorPonto;
    }
}

void Arvore::encontrarJogada() {
    int melhorPonto = -1000;
    int linha = -1;
    int coluna = -1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (this->mapa.Get(i, j) == ' ') {
                this->mapa.Set(i, j, 'O');
                this->mapa.Print();
                int ponto = Minimax(0, false);
                this->mapa.Set(i, j, ' ');
                if (ponto > melhorPonto) {
                    melhorPonto = ponto;
                    linha = i;
                    coluna = j;
                }
            }
        }
    }
    this->mapa.Set(linha, coluna, 'O');
}


#endif //JOGODAVELHACOMARVORE_ARVORE_H
