#ifndef geradorArvoreBinaria_h
#define geradorArvoreBinaria_h
#include <iostream>
#include <string>
#include "tipoRegistro.h" // Incluir a definição de TipoRegistro

using namespace std;

typedef struct {
    TipoRegistro registro;
    long int filho_dir;
    long int filho_esq;
} TipoNo;

bool adicionaNo(FILE *arq_saida, TipoNo *no, TipoNo *no_pai, bool insere, int *numero_de_nos);
int gera_Arvore_Binaria(string arq_entrada);


#endif