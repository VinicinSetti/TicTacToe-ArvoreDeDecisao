//
// Created by vinic on 21/06/2023.
//

#ifndef JOGODAVELHACOMARVORE_MAPA_H
#define JOGODAVELHACOMARVORE_MAPA_H
#include <iostream>

using namespace std;

struct Mapa {
    char mapa[3][3];

    Mapa();

    char Get(int i, int j);
    void Set(int i, int j, char valor);
    bool JogadaValida(int i, int j);
    void Jogar(char valor);
    bool Vitoria(char jogador);
    bool MapaCheio();
    int Minimax(int altura, bool rodada);
    void Print();
};

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

void Mapa::Set(int i, int j, char valor) {
    this->mapa[i][j] = valor;
}

bool Mapa::JogadaValida(int i, int j) {
    if(this->mapa[i][j] != ' '){
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
            if(this->mapa[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void Mapa::Jogar(char valor) {
    int i, j = 0;
    this->Print();
    std::cout << "Escolha uma posicao X[0-2]: ";
    std::cin >> i;
    std::cout << "Escolha uma posicao Y[0-2]: ";
    std::cin >> j;

    if (this->JogadaValida(i, j)){
        this->Set(i, j, valor);
    } else {
        std::cout << "Jogada invalida\n";
        Jogar(valor);
    }
}


bool Mapa::Vitoria(char jogador) {
    for (int i = 0; i < 3; ++i) {
        if(this->mapa[i][0] == jogador && this->mapa[i][1] == this->mapa[i][0] && this->mapa[i][2] == this->mapa[i][0]) return true;
    }

    for (int j = 0; j < 3; ++j) {
        if(this->mapa[0][j] == jogador && this->mapa[1][j] == this->mapa[0][j] && this->mapa[2][j] == this->mapa[0][j]) return true;
    }

    if(this->mapa[0][0] == jogador && this->mapa[1][1] == this->mapa[0][0] && this->mapa[2][2] == this->mapa[0][0]) return true;

    if(this->mapa[0][2] == jogador && this->mapa[1][1] == this->mapa[0][2] && this->mapa[2][0] == this->mapa[0][2]) return true;

    return false;
}


void Mapa::Print() {
    std::cout << "-------------" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "| ";
        for (int j = 0; j < 3; ++j) {
            std::cout << this->mapa[i][j] << " | ";
        }
        std::cout << std::endl << "-------------" << std::endl;
    }
}


#endif //JOGODAVELHACOMARVORE_MAPA_H
