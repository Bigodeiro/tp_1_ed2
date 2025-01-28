#ifndef geradorDeArquivo_h
#define geradorDeArquivo_h
#include <iostream>
#include "tipoRegistro.h" // Incluir a definição de TipoRegistro

int geraArqAscendente(int N, FILE *arqEscrita);
int geraArqDecrescente(int N, FILE *arqEscrita);
int geraArqDesordenado(int N, FILE *arqEscrita);

#endif