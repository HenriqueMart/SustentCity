#include "desmatamento.h"

int cadastrarCidade(Cidade **cidades, int *qtd_cidades) {
    int novoTamanho = *qtd_cidades + 1; 
    Cidade *novaAloc =
        (Cidade *)realloc(*cidades, novoTamanho * sizeof(Cidade));
    if (novaAloc == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 0;
    }

    *cidades = novaAloc;
    
    Cidade *novacidade = (Cidade *)malloc(sizeof(Cidade));
    if (novacidade == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 0;
    }

    printf("Digite o nome da cidade: ");
    scanf("%s", novacidade->nome);

    printf("Digite a populacao: ");
    scanf("%f", &novacidade->populacao);

    printf("Digite a area: ");
    scanf("%f", &novacidade->area);

    printf("Digite a area desmatada: ");
    scanf("%f", &novacidade->area_desmatada);

    /*Tirei a taxa e o a população por área pós o programa que irar   gerar isso na opção 3*/

  /*Caso desejar, criar um if mostrando com o printf pra o usuário   que essas informações será gerada quando ele selecionar a opção 3, caso a taxa e população por área for igual a 0*/
  
    novacidade->codigo = *qtd_cidades;

    (*cidades)[*qtd_cidades] = *novacidade;
    (*qtd_cidades)++;

    free(novacidade);
    system("clear");
    printf("\tSalvo com sucesso!\n");
    return 1;
}

//RELATORIO TESTE, ADICIONADO UMA FORMA DE MOSTRAR DETALHES SO SE QUISER
void gerarRelatorio(Cidade *cidades, int qtd_cidades){
    int opmenu;
    if(qtd_cidades > 0){
      /*Colocar para mostrar o nível da cidade que é a nova variável na struct*/
        printf("\n\tCidades Cadastradas:\n");
        for(int i = 0; i < qtd_cidades; i++){
                printf("\nCidade: %s, Codigo: %d\n", cidades[i].nome, cidades[i].codigo );
        }
      printf("\n\tDigite (1) Para Mais Detalhes: ");
      scanf("%d", &opmenu);
      if(opmenu == 1){
        for(int i = 0; i < qtd_cidades; i++){
          printf("\nCidade: %s\nPopulacao: %0.3f Habitantes\nArea: %0.3f m²\nÁrea Desmatada: %0.3f m²\nTaxa: %d\nPopulação Por Área: %0.2f\n", cidades[i].nome, cidades[i].populacao, cidades[i].area, cidades[i].area_desmatada, cidades[i].taxa, cidades[i].populacaoporarea);
        }
      }else{
        return;
      }
    }else{
        printf("Nenhuma cidade cadastrada!\n");
    }
}

/* Verificação da Área: Irá verificar os dados que usuário digitou no cadastro, assim verificando a taxa de desmatamento, comparando com sua área atual, com níveis: Verde, amarelo e vermelho. 
OBS: Terão funções orientando usuários para respectivos níveis. */
void indicedesmatamento(){
  system("clear");
  //clear();
  printf("\nTELA DE MONITORAMENTO\n");
  
  /*Cidade *cidade;
  Cidade dados = (*dados) malloc(sizeof(cidade);*/
  int nivel;
  char nome[100] = "Irecê";
  float area_desmatada = 0;
  float area = 10000;
  float populacao = 100.000;
  //Criando a fórmula que irá gerar a porcentagem
  nivel = area - area_desmatada;
  //int x = len(cidade.niveltotal);
  
  if(area >= area_desmatada){
    int taxa = 0;
    if(nivel != area){
      int taxa =  (nivel) / 100;
    }
    
    //gerando a população por área 
    float populacaoporarea = populacao / (nivel  / 9);
    printf("Indice de população por 9 metro %.2f\n", populacaoporarea);
    
    printf("Porcentagem %d\n", taxa);
    //lá dentro irar gerar o nível
    mensagem(taxa, nome);
  }else{
    printf("ERRO, área de desmatamento é maior que o total de área verde\n");
  }
  
  return ;
}

void mensagem(int porcentagem, char nome){
  Cidade dados;
  dados.taxa = "ERRO";
  int codigo = -1;
  system("clear");
  printf("\n\t---------======@======---------\n");
  printf("\t               ▲      \n");
  printf("\t              ▲▲▲     \n");
  printf("\t             ▲▲▲▲▲    \n");
  printf("\t            ▲▲▲▲▲▲▲   \n");
  printf("\t              |||     \n");
  printf("\n\t---------======@======---------\n");
  
  
  printf("\t\tPorcentagem de desmatamento\n");
  float auxporcentagem;
  if(porcentagem  < 5){
      auxporcentagem = 5;
  }else{
    auxporcentagem = porcentagem;
  }
  for(int i = 0; i < 1; i++){
    printf("\t\t ╔═══════════════════════╗\n");
    
    for(int j = 0; j <= (auxporcentagem); j+= 5){
      if(j > 0 && j <= auxporcentagem){
        printf("║");
      }else if(j == 0){
        printf("\t\t  ");
      }
      
    }
    printf(" %d", porcentagem);
    printf("\n");
    printf("\t\t ╚═══════════════════════╝\n");
  // Criando e mostrado de nível com caractere especiais
  }
  
  
  if(porcentagem < 40){
    dados.taxa = "VERDE";
     codigo = 2;
  
  }else if(porcentagem < 60){
    dados.taxa = "AMARELO";
   codigo = 1;
  }else if(porcentagem <= 100){
    dados.taxa  = "VERMELHO";
    codigo = 0;
  }
  
  if(codigo != -1){
    switch(codigo){
      case 0:
        printf("\t╭────────────────────────────────────────╮\n");
        printf("\t│             Alerta Vermelho            │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t╰────────────────────────────────────────╯\n");
      break;
      case 1:
        printf("\t╭────────────────────────────────────────╮\n");
        printf("\t│              Alerta Amarelo            │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t╰────────────────────────────────────────╯\n");
      break;
      case 2:
        printf("\t╭────────────────────────────────────────╮\n");
        printf("\t│            Alerta  Verde               │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t╰────────────────────────────────────────╯\n");
      break;
    }
    }else{
    printf("ERRO, Nível Nâo definido!\n");
  }
  return;
}




int salvarCidades(Cidade *cidades, char nomeArquivoEstoque[], int qtd_cidades){
  system("clear");
  FILE *arquivo = fopen(nomeArquivoEstoque, "w"); 

  if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivoEstoque);
        return 0;
    }
  for(int i = 0; i < qtd_cidades; i++){
    fprintf(arquivo,"%s %0.3f %0.3f %0.3f %d %0.2f %d\n", cidades[i].nome, cidades[i].populacao, cidades[i].area, cidades[i].area_desmatada, cidades[i].taxa, cidades[i].populacaoporarea, cidades[i].codigo);
  }

  fclose(arquivo);
  
  return 1;
}

int carregarCidades(Cidade **cidades, char nomeArquivoEstoque[], int *qtd_cidades){
  system("clear");
  FILE *arquivo = fopen(nomeArquivoEstoque, "r");

  if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivoEstoque);
        return 0;
    }

  *cidades = (Cidade *)malloc(letras * sizeof(Cidade));
  *qtd_cidades = 0; 
  
  while (!feof(arquivo)) {
    fscanf(arquivo, "%s %f %f %f %d %f %d\n", (*cidades)[*qtd_cidades].nome, &(*cidades)[*qtd_cidades].populacao, &(*cidades)[*qtd_cidades].area, &(*cidades)[*qtd_cidades].area_desmatada, &(*cidades)[*qtd_cidades].taxa, &(*cidades)[*qtd_cidades].populacaoporarea, &(*cidades)[*qtd_cidades].codigo);
        (*qtd_cidades)++;
    }

    fclose(arquivo);
    return 1;
}




//FUNCAO TESTE, PODE SER MODIFICADA DE ACORDO COM AS MODIFICACOES
void menuPrincipal(){
  printf("\n\t\t---------======@======---------\n");
  
  printf("\t╭────────────────────────────────────────╮\n");
  printf("\t│             MENU DE OPÇÕES             │\n");
  printf("\t│                                        │\n");
  printf("\t│                                        │\n");
  printf("\t│ 1 - Cadastrar Cidade             ^     │\n");
  printf("\t│ 2 - Gerar Relatório             ^^^    │\n");
  printf("\t│ 3 - Indice de Desmatamento     ^^^^^   │\n");
  printf("\t│ 4 - Salvar Cidades            ^^^^^^^  │\n");
  printf("\t│ 0 - Encerrar Programa            |     │\n");
  printf("\t│                                        │\n");
  printf("\t╰────────────────────────────────────────╯\n");
  
  printf("\n\t\t---------======@======---------\n");
  
}