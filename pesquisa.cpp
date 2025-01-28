#include <stdio.h>
#include <iostream>
#include <string>

#include "psi.h"
#include "pesquisaArvoreBinaria.h"
#include "geradorDeArquivo.h"
#include "tipoRegistro.h"
#include "geradorArvoreBinaria.h"

using namespace std;
/*
g++ pesquisa.cpp psi.cpp pesquisaArvoreBinaria.cpp geradorDeArquivo.cpp geradorArvoreBinaria.cpp -o pesquisa
*/

// Argumentos: <metodo> <qntd_registros> <ordenacao_arquivo> <chave> [-P]

// <metodo>:    
// 1 - Pesquisa Sequencial Indexada
// 2 - Arvore Binaria de Pesquisa em Memoria Externa
// 3 - Arvore B
// 4 - Arvore B*

// <qntd_registros>: quantidade de registros a serem considerados

// <ordenacao_arquivo>:
// 1 - Registros em ordem crescente
// 2 - Registros em ordem decrescente
// 3 - Registros desordenados

// <chave>: chave a ser pesquisada

// [-P]: apresenta as chaves de pesquisa dos registros do arquivo considerado na tela


int main(int argc, char *argv[]) {
    if (argc < 5) {
        cerr << "Uso: " << argv[0] << " <metodo> <qntd_registros> <ordenacao_arquivo> <chave> [-P]" << endl;
        return 1;
    }

    int qntd_registros = stoi(argv[2]);
    int ordenacao = stoi(argv[3]);
    int chave_desejada = stoi(argv[4]);

    string arq_path = "arquivo.bin";
    FILE *arq = fopen(arq_path.c_str(), "wb");

    cout << "Gerando arquivo..." << endl;
    switch (ordenacao) {
    case 1:
        geraArqAscendente(qntd_registros, arq);
        break;
    case 2:
        geraArqDecrescente(qntd_registros, arq);
        break;
    case 3:
        geraArqDesordenado(qntd_registros, arq);
        break;
    default:
        cerr << "Ordenacao invalida." << endl;
        return 1;
    }

    cout << "Pesquisando chave " << chave_desejada << " no arquivo de " << qntd_registros << " registros..." << endl; 
    /* selecao do metodo de pesquisa */
    switch (stoi(argv[1])) {
    case 1:
        psi(arq_path.c_str(), chave_desejada);
        break;
    case 2:
        gera_Arvore_Binaria(arq_path);
        pesquisa_Arvore_Binaria("registros_arvore_binaria.bin", chave_desejada);
        break;
    case 3:
        /* executa ARVORE B */
        break;
    case 4:
        /* executa ARVORE B* */
        break;    
    default:
        cerr << "Metodo de pesquisa invalido." << endl;
        return 1;
    }

    if(argc > 5 && string(argv[5]) == "-P") {
        /* chaves de pesquisa dos registros do arquivo considerado sao apresentadas na tela */
    }

    return 0;
}