//
// Created by vinic on 22/06/2023.
//
#include <iostream>

#include "./Dominio//Menu.h"

int main(){
    Menu menu;
    Arvore jogoVelha = Arvore();
    jogoVelha.mapa.Print();
    menu.rodar(jogoVelha);


    return 0;
}