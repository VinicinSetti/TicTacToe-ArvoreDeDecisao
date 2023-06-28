#ifndef JOGODAVELHACOMARVORE_MAPA_H
#define JOGODAVELHACOMARVORE_MAPA_H
#include <iostream>

using namespace std;

// Estrutura que representa o mapa do jogo da velha
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
    // Inicializa todas as posições do mapa com espaço em branco
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
    // Verifica se a posição já está ocupada
    if (this->mapa[i][j] != ' ') {
        return false;
    }
    // Verifica se as coordenadas estão dentro dos limites do mapa
    else if (i < 0 || i > 2 || j < 0 || j > 2) {
        return false;
    }
    else {
        return true;
    }
}

bool Mapa::MapaCheio() {
    // Verifica se alguma posição do mapa ainda está vazia
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (this->mapa[i][j] == ' ') {
                return false;
            }
        }
    }
    // Se todas as posições estão ocupadas, o mapa está cheio
    return true;
}

void Mapa::Jogar(char valor) {
    int i, j = 0;

    this->Print();  // Imprime o mapa atual antes da jogada

    cout << "Escolha uma posicao X(0-2): ";
    cin >> i;
    cout << "Escolha uma posicao Y(0-2): ";
    cin >> j;

    if (this->JogadaValida(i, j)) {
        this->Set(i, j, valor);  // Realiza a jogada do jogador atual
    } else {
        cout << "Jogada invalida\n";
        Jogar(valor);  // Chama novamente a função para solicitar uma nova jogada
    }
}

bool Mapa::Vitoria(char jogador) {
    // Verifica todas as combinações possíveis de vitória: linhas, colunas e diagonais

    for (int i = 0; i < 3; ++i) { // Verifica as linhas
        if (this->mapa[i][0] == jogador && this->mapa[i][1] == this->mapa[i][0] && this->mapa[i][2] == this->mapa[i][0])
            return true;
    }

    for (int j = 0; j < 3; ++j) { // Verifica as colunas
        if (this->mapa[0][j] == jogador && this->mapa[1][j] == this->mapa[0][j] && this->mapa[2][j] == this->mapa[0][j])
            return true;
    }

    // Verifica as diagonais
    if (this->mapa[0][0] == jogador && this->mapa[1][1] == this->mapa[0][0] && this->mapa[2][2] == this->mapa[0][0])
        return true;

    if (this->mapa[0][2] == jogador && this->mapa[1][1] == this->mapa[0][2] && this->mapa[2][0] == this->mapa[0][2])
        return true;

    return false;  // Não houve vitória
}

void Mapa::Print() { // Exibe o mapa na tela
    cout << "-------------" << std::endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << this->mapa[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

#endif //JOGODAVELHACOMARVORE_MAPA_H
