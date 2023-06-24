//
// Created by Alisson on 24/06/2023.
//

#ifndef TICTACTOE_ARVOREDEDECISAO_MENU_H
#define TICTACTOE_ARVOREDEDECISAO_MENU_H

#include <iostream>
#include <ctime>
#include "Arvore.h"

struct Menu{
    bool primeiraJogada();
    void rodar(Arvore jogo);
};

bool Menu::primeiraJogada() {
    srand(time(nullptr));
    int valorAleatorio = rand() % 2;

    if(valorAleatorio == 0) return true;
    return false;
}

void Menu::rodar(Arvore arvore){
    bool vez = primeiraJogada();

    if(vez == true){
        cout << "Vez do jogador" << endl;
        arvore.mapa.Jogar('X');
        vez = false;
    } else {
        cout << "Vez da IA" << endl;
        arvore.mapa.Set(0, 0, 'O');
        vez = true;
    }
    while(!arvore.mapa.MapaCheio() && !arvore.mapa.Vitoria('X') && !arvore.mapa.Vitoria('O')){
        if(vez){
            cout << "Vez do jogador" << endl;
            arvore.mapa.Jogar('X');
            vez = false;
        } else {
            cout << "Vez da IA" << endl;
            JogadaMaquina IA = arvore.encontrarJogada();
            arvore.mapa.Set(IA.lin, IA.col, 'O');
            //arvore.mapa.mapa[IA.lin][IA.col] = 'O';
            vez = true;
        }
        //system("cls");
        arvore.mapa.Print();
    }
    arvore.mapa.Print();
}

#endif //TICTACTOE_ARVOREDEDECISAO_MENU_H
