//
// Created by Alisson on 24/06/2023.
//

#ifndef TICTACTOE_ARVOREDEDECISAO_MENU_H
#define TICTACTOE_ARVOREDEDECISAO_MENU_H

#include <iostream>
#include <ctime>
#include "Arvore.h"

struct Menu{
    Arvore menu;
    bool primeiraJogada();
    void rodar();
};

bool Menu::primeiraJogada() {
    srand(time(nullptr));
    int valorAleatorio = rand() % 2;

    if(valorAleatorio == 0) return true;
    return false;
}

void Menu::rodar(){
    bool vez = primeiraJogada();

    if(vez == true){
        cout << "Vez do jogador" << endl;
        this->menu.mapa.Jogar('X');
        vez = false;
    } else {
        cout << "Vez da IA" << endl;
        this->menu.mapa.Set(0, 0, 'O');
        vez = true;
    }
    while(!this->menu.mapa.MapaCheio() && !this->menu.mapa.Vitoria('X') && !this->menu.mapa.Vitoria('O')){
        if(vez){
            cout << "Vez do jogador" << endl;
            this->menu.mapa.Jogar('X');
            vez = false;
        } else {
            cout << "Vez da IA" << endl;
            JogadaMaquina IA = this->menu.encontrarJogada();
            this->menu.mapa.Set(IA.lin, IA.col, 'O');
            //arvore.mapa.mapa[IA.lin][IA.col] = 'O';
            vez = true;
        }
        //system("cls");
        this->menu.mapa.Print();
    }
    this->menu.mapa.Print();
}

#endif //TICTACTOE_ARVOREDEDECISAO_MENU_H
