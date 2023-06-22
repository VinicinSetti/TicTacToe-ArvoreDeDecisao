//
// Created by vinic on 21/06/2023.
//

#include <iostream>
#include "Mapa.h"

Mapa::Mapa() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            this->mapa[i][j];
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

}

void Mapa::Mover(char valor) {

}

bool Mapa::Vitoria() {
    for (int i = 0; i < 3; ++i) {
        if(this->mapa[i][0] != ' ' && this->mapa[i][0] == this->mapa[i][1] && this->mapa[i][0] == this->mapa[i][2]) return true;
    }

    for (int j = 0; j < 3; ++j) {
        if(this->mapa[0][j] != ' ' && this->mapa[0][j] == this->mapa[1][j] && this->mapa[0][j] == this->mapa[2][j]) return true;
    }

    if(this->mapa[0][0] != ' ' && this->mapa[0][0] == this->mapa[1][1] && this->mapa[0][0] == this->mapa[2][2]) return true;

    if(this->mapa[0][2] != ' ' && this->mapa[0][2] == this->mapa[1][1] && this->mapa[0][2] == this->mapa[2][0]) return true;

    return false;
}

void Mapa::Print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << this->mapa[i][j];
        }
    }
}