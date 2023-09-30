#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

  char nome[50];
  float populacao;
  float area;
  float area_desmatada;

} Cidades;


int verificar_cadastro(Cidades *cidade, char *nome, int qtd_cidades);

int cadastrar_cidade(Cidades **cidade, int *qtd_cidades);

void gerarRelatorio(Cidades *cidade, int qtd_cidades);

void menuInicial();