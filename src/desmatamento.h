#ifndef DESMATAMENTO_H
#define DESMATAMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define letras 20

typedef struct {

  //colocar na função de carregar e salvar cidade!!
  //Só vai salvar ser tiver alguns cidade a mais do que está no arquivo salvo, para não salvar espaço vazio.
  //nível da cidade amarelo, verde ...
  char nivel[letras];
  //Mostrar porcentagem de desmatamento
  float porcentagem; 
  //Mostrar a taxa da população por área  9metro^2 (OMS)
  float populacaoporarea;
  //
  char nome[letras];
  float populacao;
  float area;
  float area_desmatada;
  //Codigo da cidade
  int codigo; 

} Cidade;

//FUNCAO DO MENU 
void menuPrincipal();

//FUNCAO QUE CADASTRA AS CIDADES COM ALOCACAO DINAMICA
int cadastrarCidade(Cidade **cidades, int *qtd_cidades);

//FUNCAO QUE GERA O RELATORIO SIMPLES
void gerarRelatorio(Cidade *cidades, int qtd_cidades);

//Mostrando o nível de desmatamento
void indicedesmatamento(Cidade *dados, int tquantidade);

//FUNCAO QUE SALVA AS NOVAS CIDADES REGISTRADAS NO ARQUIVO
int salvarCidades(Cidade *cidades, char nomeArquivoEstoque[], int qtd_cidades);

//FUNCAO QUE CARREGA AS CIDADES A INICIALIZAR O PROGRAMA
int carregarCidades(Cidade **cidades, char nomeArquivoEstoque[], int *qtd_cidades);

//Mostar para o usuário determinada área e sua situação da cidade
void mensagem(Cidade *dados, int cod);
















#endif