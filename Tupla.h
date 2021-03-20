#ifndef TUPLA_H_INCLUDED
#define TUPLA_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Tupla
{
    public:
        Tupla(int pos, int pulo, char code);
        virtual ~Tupla();

        char getCode();
        void setCode(char code);
        
        int getPosicao();
        void setPosicao(int pos);

        int getPulo();
        void setPulo(int jump);

    private:
        char code;
        int posicao;
        int pulo;
};

#endif