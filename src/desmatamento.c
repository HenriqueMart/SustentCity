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

    //Criando a fórmula que irá gerar a porcentagem
    if(novacidade->area < novacidade->area_desmatada){
      printf("Erro, área desmatada maior que área total da cidade\n");
      return -1;
    }
    novacidade->porcentagem = novacidade->area - novacidade->area_desmatada;  
    if(novacidade->area == novacidade->area_desmatada){
      novacidade->porcentagem  = 0;
    }else if(novacidade->area != novacidade->area_desmatada){
      novacidade->porcentagem  /= 100;
    }
    /*Tirei a taxa e o a população por área pós o programa que irar   gerar isso na opção 3*/
    
    
  //gerando a população por área 
    novacidade->populacaoporarea = novacidade->populacao / (novacidade->populacaoporarea  / 9);
    
  //Salvando os níveis de alerta co a porcentagem  
  /*if(novacidade->porcentagem > 60){
    novacidade->nivel = "VERDE";
  }else if(novacidade->porcentagem > 40){
    novacidade->nivel = "AMARELO";
  }else if(novacidade->porcentagem >= 0){
    novacidade->nivel  = "VERMELHO";
  }*/
  
    novacidade->codigo = *qtd_cidades;

    (*cidades)[*qtd_cidades] = *novacidade;
    (*qtd_cidades)++;

    free(novacidade);
    system("clear");
    printf("Indice de população por 9 metro %.2f\n", novacidade->populacao);
    printf("%0.2f\n", novacidade->porcentagem);
    return 1;
}

//RELATORIO TESTE, ADICIONADO UMA FORMA DE MOSTRAR DETALHES SO SE QUISER
void gerarRelatorio(Cidade *cidades, int qtd_cidades){
  system("cls");
    int opmenu;
    if(qtd_cidades > 0){
      /*Colocar para mostrar o nível da cidade que é a nova variável na struct*/
        printf("\n\tCidades Cadastradas:\n");
        for(int i = 0; i < qtd_cidades; i++){
                printf("\nCidade: %s, Codigo: %d\n", cidades[i].nome, cidades[i].codigo );
        }
      printf("\n\tDigite (1) Para Mais Detalhes, Voltar (0)\n\tQual opção deseja: ");
      scanf("%d", &opmenu);
      if(opmenu == 1){
        for(int i = 0; i < qtd_cidades; i++){
          printf("\nCidade: %s\nPopulacao: %0.2f Habitantes\nArea: %0.2f m²\nÁrea Desmatada: %0.2f m²\nPorcentagem: %0.1f\nNível %s \nPopulação Por Área: %f\n", cidades[i].nome, cidades[i].populacao, cidades[i].area, cidades[i].area_desmatada, cidades[i].porcentagem, cidades[i].nivel, cidades[i].populacaoporarea);
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
void indicedesmatamento(Cidade *dados, int tquantidade){
  system("clear");
  int opcao = 0, cod;
  printf("\nTELA DE MONITORAMENTO\n");
  printf("\tEscolha as opção:\n");
  printf("\t1 - Verificar todas as cidade Cadastrada\n");
  printf("\t2 - Digitar o Código da cidade\n\tDigite a opção:");
  scanf("%d", &opcao);
  switch(opcao){
    case 1:
      gerarRelatorio(dados, tquantidade);
    case 2:
      printf("\n\t---------======@======---------\n");
      printf("Digite o código da cidade:");
      scanf("%d", &cod);
      /*Criar um buscar pelo código ou nome da cidade */
      
      
      //Mostrar o gráfico interativo
      mensagem(dados, cod);
      
    break;
    default:
    printf("ERRO, Número não válido");
    
  }
  return ;
}

void mensagem(Cidade *dados, int cod){
  int codigo = -1;
  system("clear");
  printf("\t\tCidade %s\n", dados[cod].nome);
  printf("\n\t---------======@======---------\n");
  printf("\t               ▲      \n");
  printf("\t              ▲▲▲     \n");
  printf("\t             ▲▲▲▲▲    \n");
  printf("\t            ▲▲▲▲▲▲▲   \n");
  printf("\t              |||     \n");
  printf("\n\t---------======@======---------\n");
  
  
  printf("\t\tPorcentagem de área verde\n");
  float auxporcentagem;
  if(dados[cod].porcentagem  < 5){
      auxporcentagem = 5;
  }else{
    auxporcentagem = dados[cod].porcentagem ;
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
    printf(" %0.1f%%", dados[cod].porcentagem);
    printf("\n");
    printf("\t\t ╚═══════════════════════╝\n");
  // Criando e mostrado de nível com caractere especiais
  }
  
  /*//comparação com string da struct
  if(dados[cod].porcentagem  < 40){
     codigo = 2;
  
  }else if(dados[cod].porcentagem  < 60){

    codigo = 1;
  }else if(dados[cod].porcentagem  <= 100){

    codigo = 0;
  }*/
  
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
    fprintf(arquivo,"%s %0.3f %0.3f %0.3f %0.3f %0.2f %s %d\n", cidades[i].nome, cidades[i].populacao, cidades[i].area, cidades[i].area_desmatada, cidades[i].porcentagem, cidades[i].populacaoporarea, cidades[i].nivel, cidades[i].codigo);
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
    fscanf(arquivo, "%s %f %f %f %f %f %s %d\n", (*cidades)[*qtd_cidades].nome, &(*cidades)[*qtd_cidades].populacao, &(*cidades)[*qtd_cidades].area, &(*cidades)[*qtd_cidades].area_desmatada, &(*cidades)[*qtd_cidades].porcentagem, &(*cidades)[*qtd_cidades].populacaoporarea, &(*cidades)[*qtd_cidades].nivel, &(*cidades)[*qtd_cidades].codigo);
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