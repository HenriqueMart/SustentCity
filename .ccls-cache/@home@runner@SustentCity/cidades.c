#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

// OBS >> FAZER FUNCOES PARA OS MENUS, POLUIR MENOS A MAIN <<

// VERIFICAR SE A CIDADE JA FOI CADASTRADA
int verificar_cadastro(Cidades *cidade, int qtd_cidades){
  for(int i = 0; i  < qtd_cidades; i++){
    if(strcmp(cidade[i].nome, nome) == 0){
      return 1;
    }
  }
  return 0;
}

// FUNCAO QUE CADASTRA AS CIDADES
int cadastrar_cidade(Cidades **cidade, int *qtd_cidades){

  if(verificar_cadastro(&cidade, qtd_cidades)){
    return;
  }
  
  int novoTamanho = *qtd_cidades + 1; 
  Cidades *novoDado =
      (Cidades *)realloc(*cidade, novoTamanho * sizeof(Cidades));
  if (novoDado == NULL) {
    printf("Erro ao alocar memoria.\n");
    return 0;
  }
  *cidade = novoDado;

    Cidades *novacidade = (Cidades *)malloc(sizeof(Cidades));
    if (novacidade == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 0;
    }

    printf("Digite o nome da cidade: ");
    scanf("%s", novacidade->nome);

    printf("Digite a população da cidade: ");
    scanf("%f", &novacidade->populacao);

    printf("Digite a area da cidade: ");
    scanf("%f", &novacidade->area);

    printf("Digite a area desmatada: ");
    scanf("%f", &novacidade->area_desmatada);

    (*cidade)[*qtd_cidades] = *novacidade;
    (*qtd_cidades)++;

    free(novacidade);
    return 1;
}

// RELATORIO TESTE
void gerarRelatorio(Cidades *cidade, int qtd_cidades){
  printf("\n\tRELATORIO DE ESTOQUE:\n\n");
        printf("----------------------------\n");
        for(int i = 0; i < qtd_cidades; i++){
            printf("Nome: %s\nPopulacao: %0f\nArea: %0f\nArea Desmatada: %f\n", cidade[i].nome, cidade[i].populacao, cidade[i].area, cidade[i].area_desmatada);
            printf("----------------------------\n");
  }
}

void menuInicial(){
  printf("\t1\n");
  printf("\t2\n");
  printf("\t3\n");
  printf("\t4\n");
  printf("\t5\n");
  printf("\t6\n");
  printf("\t7\n");
  printf("\nDigite uma opção: ");
}