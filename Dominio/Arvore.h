#ifndef JOGODAVELHACOMARVORE_ARVORE_H
#define JOGODAVELHACOMARVORE_ARVORE_H
#include "Mapa.h"

struct Arvore {
    Mapa mapa;
    Arvore* noFilho[8];

    Arvore() {
        for (int i = 0; i < 8; i++) {
            this->noFilho[i] = nullptr;
        }
    }

    int folha;

    void encontrarJogada();
    int Minimax(bool rodada, Arvore* noFilho);
};



int Arvore::Minimax(bool rodada, Arvore* noFilho) {
    if (noFilho->mapa.Vitoria('O'))
        return 1;
    if (noFilho->mapa.Vitoria('X'))
        return -1;
    if (noFilho->mapa.MapaCheio())
        return 0;

    if (rodada) {
        int melhorPonto = -1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(noFilho->mapa.Get(i, j) == ' ') {
                    noFilho->mapa.Set(i, j, 'O');
                    int score = Minimax(false, noFilho);
                    noFilho->mapa.Set(i, j, ' ');
                    if (score > melhorPonto) {
                        melhorPonto = score;
                    }
                }
            }
        }
        return melhorPonto;
    } else {
        int melhorPonto = 1;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (noFilho->mapa.Get(i, j) == ' ') {
                    noFilho->mapa.Set(i, j, 'X');
                    int score = Minimax(true, noFilho);
                    noFilho->mapa.Set(i, j, ' ');
                    if(score < melhorPonto) {
                        melhorPonto = score;
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
    int folha = 0;
    for (int i = 0; i < 8; ++i) {
        this->noFilho[i] = new Arvore;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                this->noFilho[i]->mapa.Set(j, k, this->mapa.Get(j, k));
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->mapa.Get(i, j) == ' ') {
                this->noFilho[folha]->mapa.Set(i, j, 'O');
                int ponto = Minimax(false, this->noFilho[folha]);
                this->noFilho[folha]->mapa.Set(i, j, ' ');
                if (ponto > melhorPonto) {
                    melhorPonto = ponto;
                    linha = i;
                    coluna = j;
                }
                folha++;
            }
        }
    }
    this->mapa.Set(linha, coluna, 'O');
}

#endif //JOGODAVELHACOMARVORE_ARVORE_H
