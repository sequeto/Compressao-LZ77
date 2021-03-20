#ifndef LZ77_H_INCLUDED
#define LZ77_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Tupla.h"

using namespace std;

class Lz77
{
    public:
        Lz77();
        virtual ~Lz77();
        vector<Tupla*> compressao(string chave);

    private:
        int tamanho_buffer = 4;
        int tamanho_dicionario = 6;
        string buffer;
        string dicionario;
        vector<Tupla*> codigo;
};

#endif