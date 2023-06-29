//
// Created by vinic on 21/06/2023.
//

#ifndef JOGODAVELHACOMARVORE_ARVORE_H
#define JOGODAVELHACOMARVORE_ARVORE_H
#include "Mapa.h"

struct Arvore {
    Mapa mapa;
    int profundidade;

    void encontrarJogada();
    int Minimax(bool rodada);

};


int Arvore::Minimax(bool rodada) {
    if (this->mapa.Vitoria('O'))
        return 1;
    if (this->mapa.Vitoria('X'))
        return -1;
    if (this->mapa.MapaCheio())
        return 0;

    if (rodada) {
        int melhorPonto = -1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(this->mapa.Get(i, j) == ' ') {
                    this->profundidade++;
                    this->mapa.Set(i, j, 'O');
                    int score = Minimax(false);
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
        int melhorPonto = 1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (this->mapa.Get(i, j) == ' ') {
                    this->profundidade++;
                    this->mapa.Set(i, j, 'X');
                    int score = Minimax(true);
                    this->mapa.Set(i, j, ' ');
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
    int melhorPonto = -1;
    int linha = -1;
    int coluna = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->mapa.Get(i, j) == ' ') {
                this->profundidade = 0;
                this->mapa.Set(i, j, 'O');
                int ponto = Minimax(false);
                this->mapa.Set(i, j, ' ');
                if (ponto > melhorPonto) {
                    melhorPonto = ponto;
                    linha = i;
                    coluna = j;
                }
                if(this->profundidade == 0){
                    linha = i;
                    coluna = j;
                    break;
                }
            }
        }
        if(this->profundidade == 0) break;
    }
    this->mapa.Set(linha, coluna, 'O');
}


#endif //JOGODAVELHACOMARVORE_ARVORE_H
