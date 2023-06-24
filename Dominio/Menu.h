//
// Created by Alisson on 24/06/2023.
//

#ifndef TICTACTOE_ARVOREDEDECISAO_MENU_H
#define TICTACTOE_ARVOREDEDECISAO_MENU_H

#include <iostream>
#include <ctime>
#include "Arvore.cpp"

struct Menu{
    Arvore jogo;
    bool primeiraJogada();
    void rodar(Arvore jogo);
    bool rodando();
};


#endif //TICTACTOE_ARVOREDEDECISAO_MENU_H
