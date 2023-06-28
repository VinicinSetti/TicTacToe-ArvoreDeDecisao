#ifndef TICTACTOE_ARVOREDEDECISAO_MENU_H
#define TICTACTOE_ARVOREDEDECISAO_MENU_H

#include <iostream>
#include <ctime>
#include "Arvore.h"

struct Menu {
    Arvore menu;

    bool primeiraJogada();
    void rodar();
};

bool Menu::primeiraJogada() { // Função para determinar o primeiro a jogar, de maneira aleatória
    srand(time(nullptr));
    int valorAleatorio = rand() % 2;

    if (valorAleatorio == 0)
        return true;
    return false;
}

void Menu::rodar() {
    bool vez = primeiraJogada();

    if (vez) {
        cout << "Vez do jogador" << endl;
        this->menu.mapa.Jogar('X');  // Jogador faz a primeira jogada
        vez = false; // Passa a vez para a IA
    } else {
        cout << "Vez da IA" << endl;
        this->menu.mapa.Set(0, 0, 'O');  // IA faz a primeira jogada
        vez = true; // Passa a vez para o Jogador
    }

    // Loop principal do jogo
    while (!this->menu.mapa.MapaCheio() && !this->menu.mapa.Vitoria('X') && !this->menu.mapa.Vitoria('O')) {
        if (vez) {
            cout << "Vez do jogador" << endl;
            this->menu.mapa.Jogar('X');  // Jogador realiza sua jogada
            vez = false; // Passa a vez para a IA
        } else {
            cout << "Vez da IA" << endl;
            this->menu.encontrarJogada();  // IA encontra a melhor jogada e a realiza
            vez = true; // Passa a vez para o Jogador
        }

        this->menu.mapa.Print();  // Imprime o estado atual do mapa
    }

    this->menu.mapa.Print();  // Imprime o estado final do mapa

    // Verifica o resultado do jogo e exibe a mensagem correspondente
    if (this->menu.mapa.Vitoria('X')) {
        cout << "Jogador venceu!";
    } else if (this->menu.mapa.Vitoria('O')) {
        cout << "IA venceu!";
    } else {
        cout << "Deu velha!";
    }
}

#endif //TICTACTOE_ARVOREDEDECISAO_MENU_H
