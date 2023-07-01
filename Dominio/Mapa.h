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
    cout << "Escolha uma linha (1-3): ";
    cin >> i;
    i--;
    cout << "Escolha uma coluna (1-3): ";
    cin >> j;
    j--;

    if (this->JogadaValida(i, j)){
        this->Set(i, j, valor);
    } else {
        cout << "Jogada invalida\n";
        Jogar(valor);
    }
}

bool Mapa::Vitoria(char jogador) {
    for (int i = 0; i < 3; ++i) {
        if(this->mapa[i][0] == jogador && this->mapa[i][1] == jogador && this->mapa[i][2] == jogador) return true;
    }

    for (int j = 0; j < 3; ++j) {
        if(this->mapa[0][j] == jogador && this->mapa[1][j] == jogador && this->mapa[2][j] == jogador) return true;
    }

    if(this->mapa[0][0] == jogador && this->mapa[1][1] == jogador && this->mapa[2][2] == jogador) return true;

    if(this->mapa[0][2] == jogador && this->mapa[1][1] == jogador && this->mapa[2][0] == jogador) return true;

    return false;
}

void Mapa::Print() {
    int lin = 1;
    cout << "    1   2   3" << endl;
    cout << "  -------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << lin << " | ";
        for (int j = 0; j < 3; ++j) {
            cout << this->mapa[i][j] << " | ";
        }
        cout << endl << "  -------------" << endl;
        lin++;
    }
}

#endif //JOGODAVELHACOMARVORE_MAPA_H
