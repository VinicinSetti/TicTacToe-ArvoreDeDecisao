//
// Created by vinic on 21/06/2023.
//

#include "Arvore.h"



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
                if (this->mapa[i][j] == ' ') {
                    this->mapa[i][j] = 'X';
                    int score = Minimax(altura + 1, false);
                    this->mapa[i][j] = ' ';
                    if(score > melhorPonto) melhorPonto = score;
                    else melhorPonto = melhorPonto;
                }
            }
        }
        return melhorPonto;
    } else {
        int melhorPonto = 1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (this->mapa[i][j] == ' ') {
                    this->mapa[i][j] = 'O';
                    int score = Minimax(altura + 1, true);
                    this->mapa[i][j] = ' ';
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
    JogadaMaquina melhorJoagada;
    melhorJoagada.lin = -1;
    melhorJoagada.col = -1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (this->mapa[i][j] == ' ') {
                this->mapa[i][j] = 'X';
                int score = Minimax(0, false);
                this->mapa[i][j] = ' ';
                if (score > melhorPonto) {
                    melhorPonto = score;
                    melhorJoagada.lin = i;
                    melhorJoagada.col = j;
                }
            }
        }
    }
}
