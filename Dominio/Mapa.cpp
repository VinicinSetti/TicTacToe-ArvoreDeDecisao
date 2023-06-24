//
// Created by vinic on 21/06/2023.
//

#include <iostream>
#include "Mapa.h"

Mapa::Mapa() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            this->mapa[i][j] = ' ';
        }
    }
}

char Mapa::Get(int i, int j) {
    return this->mapa[i][j];
}

void Mapa::Set(int i, int j, char value) {
    this->mapa[i][j] = value;
}

bool Mapa::JogadaValida(int i, int j) {
    if(mapa[i][j] != ' '){
        return false;
    } else if(i < 0 || i > 2 || j < 0 || j > 2){
        return false;
    } else  {
        return true;
    }
}

bool Mapa::MapaCheio() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(this->mapa[i][j] != ' ') return false;
        }
    }
    return true;
}

void Mapa::Jogar(char valor) {
    int i, j = 0;
    std::cout << "Escolha uma posicao X[0-2]: ";
    std::cin >> i;
    std::cout << "Escolha uma posicao Y[0-2]: ";
    std::cin >> j;

    if (this->JogadaValida(i, j))
        this->Set(i, j, valor);
    else
        std::cout << "Jogada invalida\n";
    Jogar(valor);
}


bool Mapa::Vitoria(char jogador) {
    for (int i = 0; i < 3; ++i) {
        if(this->mapa[i][0] == jogador && this->mapa[i][0] == this->mapa[i][1] && this->mapa[i][0] == this->mapa[i][2]) return true;
    }

    for (int j = 0; j < 3; ++j) {
        if(this->mapa[0][j] == jogador && this->mapa[0][j] == this->mapa[1][j] && this->mapa[0][j] == this->mapa[2][j]) return true;
    }

    if(this->mapa[0][0] == jogador && this->mapa[0][0] == this->mapa[1][1] && this->mapa[0][0] == this->mapa[2][2]) return true;

    if(this->mapa[0][2] == jogador && this->mapa[0][2] == this->mapa[1][1] && this->mapa[0][2] == this->mapa[2][0]) return true;

    return false;
}

int minimax(Mapa mapa, int depth, bool isMaximizingPlayer) {
    if (checkWin(board, 'X'))
        return 1;
    if (checkWin(board, 'O'))
        return -1;
    if (isBoardFull(board))
        return 0;

    if (isMaximizingPlayer) {
        int bestScore = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(board, depth + 1, false);
                    board[i][j] = ' ';
                    bestScore = std::max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(board, depth + 1, true);
                    board[i][j] = ' ';
                    bestScore = std::min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

void Mapa::Print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << this->mapa[i][j];
        }
    }
}