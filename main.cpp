#include <iostream>
#include <string>
#include <fstream>
#include "Lz77.h"
#include "Tupla.h"

using namespace std;

int main(int argc, char* argv[]){
    // Verificando se possui arquivo txt como argumento
    if(argc < 2) {
        cout << "ERRO: Insira um arquivo txt como parametro" << endl;
        cout << "./ <nome do programa> <nome do arquivo>" << endl;
        return 1;
    }

    // Abrindo arquivo para leitura
    ifstream myfile(argv[1]);
    if(!myfile.is_open()){
        cout << "Erro ao abrir o arquivo";
        return 1;
    }

    // Lendo Arquivo
    string line;
    cout << "Lendo Arquivo" << endl;
    while(!myfile.eof()) {
        getline(myfile, line);
    }
    Lz77* compressor = new Lz77();

    vector<Tupla*> tupla = compressor->compressao(line);

    cout << "Compressao" << endl;
    for(int i=0; i<tupla.size(); i++){
        cout << "(" << tupla[i]->getPosicao() << "," << tupla[i]->getPulo() << ","  << tupla[i]->getCode() << ")" << endl;
    }
}