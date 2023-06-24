//
// Created by Alisson on 24/06/2023.
//
using namespace std;
#include "Menu.h"

bool Menu::primeiraJogada() {
    srand(time(nullptr));
    int valorAleatorio = rand() % 2;

    if(valorAleatorio == 0) return true;
    return false;
}

void Menu::rodar(Arvore mapa){
    bool vez = primeiraJogada();

    if(vez == true){
        cout << "Vez do jogador" << endl;
        this->jogo.mapa.Jogar('X');
        vez = false;
    } else {
        cout << "Vez da IA" << endl;
        this->jogo.mapa.Set(0, 0, 'O');
        vez = true;
    }
    while(this->jogo.mapa.MapaCheio() == false && this->jogo.mapa.Vitoria('X') == false || this->jogo.mapa.MapaCheio() == false == false && this->jogo.mapa.Vitoria('O') == false){
        if(vez == true){
            cout << "Vez do jogador" << endl;
            this->jogo.mapa.Jogar('X');
            vez = false;
        } else {
            JogadaMaquina IA;
            cout << "Vez da IA" << endl;
            IA = this->jogo.encontrarJogada();
            this->jogo.mapa.mapa[IA.lin][IA.col] = 'O';
            vez = true;
        }
        system("cls");
        this->jogo.mapa.Print();
    }
    this->jogo.mapa.Print();
}