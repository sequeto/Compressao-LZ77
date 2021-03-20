#include <iostream>
#include "Tupla.h"

using namespace std;

Tupla::Tupla(int pos, int pulo, char code){
    this->posicao = pos;
    this->pulo = pulo;
    this->code = code;
}

Tupla::~Tupla(){

}

char Tupla::getCode(){
    return this->code;
}

void Tupla::setCode(char code){
    this->code = code;
}

int Tupla::getPosicao(){
    return this->posicao;
}

void Tupla::setPosicao(int pos){
    this->posicao = pos;
}

int Tupla::getPulo(){
    return this->pulo;
}

void Tupla::setPulo(int jump){
    this->pulo = jump;
}