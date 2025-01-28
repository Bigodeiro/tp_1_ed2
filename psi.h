#ifndef PSI_H
#define PSI_H

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <string>

#include "tipoRegistro.h"

#define QTDPAGINAS 5
#define REGISTROSPAGINA 20

bool buscaBinaria(TipoRegistro pagina[], int qtdItens, int chave, int pEsq, int pDir, int pMeio, TipoRegistro *registro, int *cont);
bool pesquisa(int menorChaveDaPagina[], int tam, TipoRegistro *registroBuscado, FILE *arq, int *cont, int *nTransferencias_pes);
int psi(std::string arq_path, int chave);

#endif // PSI_H