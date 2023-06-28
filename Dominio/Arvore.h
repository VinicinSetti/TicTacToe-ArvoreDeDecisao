#ifndef JOGODAVELHACOMARVORE_ARVORE_H
#define JOGODAVELHACOMARVORE_ARVORE_H
#include "Mapa.h"

struct Arvore {
    Mapa mapa;

    // Encontra a melhor jogada possível para a IA
    void encontrarJogada();

    // Função Minimax para determinar a melhor posição de uma jogada
    int Minimax(bool rodada);
};

int Arvore::Minimax(bool rodada) {
    if (this->mapa.Vitoria('O'))  // Se 'O' venceu, retorna 1
        return 1;
    if (this->mapa.Vitoria('X'))  // Se 'X' venceu, retorna -1
        return -1;
    if (this->mapa.MapaCheio())  // Se o mapa está cheio e não houve vitória, retorna 0 (empate)
        return 0;

    if (rodada) {
        int melhorPonto = -1000;

        // Percorre todas as posições do mapa
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (this->mapa.Get(i, j) == ' ') {
                    this->mapa.Set(i, j, 'O');  // Simula uma jogada de 'O'
                    int pontuacao = Minimax(false);  // Chama a função Minimax para o próximo movimento
                    this->mapa.Set(i, j, ' ');  // Desfaz a jogada

                    // Atualiza a melhor jogada
                    if (pontuacao > melhorPonto) {
                        melhorPonto = pontuacao;
                    } else {
                        melhorPonto = melhorPonto;
                    }
                }
            }
        }
        return melhorPonto;  // Retorna a melhor posição encontrada
    } else {
        int melhorPonto = 1000;  // Pontuação mínima para o jogador 'X'

        // Percorre todas as posições do mapa
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (this->mapa.Get(i, j) == ' ') {
                    this->mapa.Set(i, j, 'X');  // Simula uma jogada de 'X'
                    int score = Minimax(true);  // Chama a função Minimax para o próximo movimento
                    this->mapa.mapa[i][j] = ' ';  // Desfaz a jogada

                    // Atualiza a melhor jogada
                    if (score < melhorPonto) {
                        melhorPonto = score;
                    }
                    else {
                        melhorPonto = melhorPonto;
                    }
                }
            }
        }
        return melhorPonto;  // Retorna a melhor posição encontrada
    }
}

void Arvore::encontrarJogada() {
    int melhorPonto = -1000;
    int linha = -1;
    int coluna = -1;

    // Percorre todas as posições do mapa
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (this->mapa.Get(i, j) == ' ') {
                this->mapa.Set(i, j, 'O');  // Simula uma jogada da IA
                int ponto = Minimax(false);  // Chama a função Minimax para o próximo movimento
                this->mapa.Set(i, j, ' ');  // Desfaz a jogada

                // Atualiza a melhor posição da jogada
                if (ponto > melhorPonto) {
                    melhorPonto = ponto;
                    linha = i;
                    coluna = j;
                }
            }
        }
    }

    this->mapa.Set(linha, coluna, 'O');  // Realiza a melhor jogada encontrada pela IA
}

#endif //JOGODAVELHACOMARVORE_ARVORE_H
