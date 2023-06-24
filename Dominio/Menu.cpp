//
// Created by Alisson on 24/06/2023.
//

#include "Menu.h"

bool Menu::primeiraJogada() {
    srand(time(nullptr));
    int valorAleatorio = rand() % 2;

    if(valorAleatorio == 0) return true;
    return false;
}

void Menu::rodar(Mapa mapa){
    Mapa mapa = Mapa();
    bool vez = primeiraJogada();

    if(vez == true){
        cout << "Vez do jogador" << endl;
        mapa.Jogar('X');
        vez = false
    } else {
        cout << "Vez da IA" << endl;
        mapa.Set(0, 0, 'O');
        vez = true;
    }
    while(mapa.MapaCheio() == false && mapa.Vitoria() == false){
        if(vez == true){
            cout << "Vez do jogador" << endl;
            mapa.Jogar('X');
            vez = false;
        } else {
            cout << "Vez da IA" << endl;
            mapa.Set(0, 0, 'O');
            vez = true;
        }
        system("cls");
        mapa.Print();
    }
    mapa.Print();
}