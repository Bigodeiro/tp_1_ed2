#include "pesquisaArvoreBinaria.h"
using namespace chrono;

typedef struct {
    int chave;
    long int dado1;
    char dado2[5000];
} TipoRegistro;

typedef struct {
    TipoRegistro registro;
    long int filho_dir;
    long int filho_esq;
} TipoNo;

bool pesquisaArvoreBinaria(int chave, FILE *arqEntrada) {

    TipoNo *no = (TipoNo*)malloc(sizeof(TipoNo));

    while( fread(no, sizeof(TipoNo), 1, arqEntrada)  ) {
        if(chave > no->registro.chave)
            fseek(arqEntrada, no->filho_dir * sizeof(TipoNo), SEEK_SET);
        else if(chave < no->registro.chave)
            fseek(arqEntrada, no->filho_esq * sizeof(TipoNo), SEEK_SET);
        else {
            free(no);
            return true;
        }
    }

    free(no);
    return false;

}

int pesquisa_Arvore_Binaria(string arq_path, int c) {
    FILE* arqEntrada = fopen(arq_path.c_str(), "rb");
    

    auto tempoInicio = high_resolution_clock::now();

    if(pesquisaArvoreBinaria(c, arqEntrada)) 
        cout << "Chave encontrada!";
    else 
        cout << "Não foi possivel achar a chave.";
    
    auto tempoFim = high_resolution_clock::now();
    auto tempoExecucao = duration_cast<milliseconds>(tempoFim - tempoInicio);
    cout << "\nTempo de pesquisa: " << tempoExecucao.count() << "ms\n";
    return 0;   
}