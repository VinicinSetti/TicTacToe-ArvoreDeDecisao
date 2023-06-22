//
// Created by vinic on 21/06/2023.
//

#ifndef JOGODAVELHACOMARVORE_MAPA_H
#define JOGODAVELHACOMARVORE_MAPA_H


class Mapa {
public:
    char mapa[3][3];

    Mapa();

    char Get(int i, int j);
    void Set(int i, int j, char value);
    bool JogadaValida(int i, int j);
    void Jogar(char valor);
    bool Vitoria();
    bool MapaCheio();
    void Print();
};


#endif //JOGODAVELHACOMARVORE_MAPA_H
