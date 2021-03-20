#include <iostream>
#include <string>
#include "Lz77.h"
#include "Tupla.h"

/* 
* (p, l, c)
* p é a posição relativa (a contar do cursor) da maior sequência do dicionário
* l é o comprimento da maior sequência
* c é o símbolo do buffer que se segue à sequência
*/

Lz77::Lz77(){

}

Lz77::~Lz77(){

}

vector<Tupla*> Lz77::compressao(string chave){

    int p;
    int l;
    char c;
    int tamanhoPulo;
    int inicio_dicionario; // indica onde inicia o dicionario

    int bufferAux;
    int dicionAux;

    for(int i = 0; i < chave.size(); i = i + l + 1)
    {
        p = 0;
        l = 0;

        inicio_dicionario = i - this->tamanho_dicionario;
        if(inicio_dicionario < 0){
            inicio_dicionario = 0;
        }

        this->buffer = chave.substr(i, this->tamanho_buffer);

        for (int j = inicio_dicionario; j < i; j++)
        {
            tamanhoPulo = 0;
            this->dicionario = chave.substr(j, i); // andando uma casa no dicionario

            bufferAux = 0;
            dicionAux = 0;
            while (this->dicionario[dicionAux] == this->buffer[bufferAux]) // Identificando a maior sequencia
            {
                dicionAux++;
                bufferAux++;
                tamanhoPulo++;
            }

            if (tamanhoPulo > l)
            {
                p = i - j;
                l = tamanhoPulo;
            }
        }

        c = chave[i + l];
        Tupla* tupla = new Tupla(p, l, c);
        this->codigo.push_back(tupla);
    }

    return this->codigo;
}