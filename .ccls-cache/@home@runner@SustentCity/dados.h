#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

  char nome[50];
  int populacao;
  float area;
  float area_desmatada;

} Cidades;

int cadastrar_cidade();