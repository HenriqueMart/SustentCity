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

    printf("Digite o Nome da Cidade: ");
    scanf("%s", novacidade->nome);

    printf("Digite a Populacao: ");
    scanf("%f", &novacidade->populacao);

    printf("Digite a Área, em Km²: ");
    scanf("%f", &novacidade->area);

    printf("Digite a Área Desmatada, em Km²: ");
    scanf("%f", &novacidade->area_desmatada);

    printf("Digite o Código da Cidade: ");
    scanf("%d", &novacidade->codigo);

    //Criando a fórmula que irá gerar a porcentagem
    if(novacidade->area < novacidade->area_desmatada){
      printf("Erro, área desmatada maior que área total da cidade\n");
      return -1;
    }
    novacidade->porcentagem = novacidade->area - novacidade->area_desmatada;  
    if(novacidade->area == novacidade->area_desmatada){
      novacidade->porcentagem  = 0;
    }else if(novacidade->area != novacidade->area_desmatada){
      //Para gerar a porcentagem era a area desmatada pela area atual * 100
      novacidade->porcentagem = (novacidade->area_desmatada / novacidade->area) * 100.00;
    }

    novacidade->populacaoporarea = (novacidade->porcentagem * novacidade->area) * novacidade->populacao;
  
  if(novacidade->porcentagem < 40.0){
    char nivelverde[] = "VERDE";
    strcpy(novacidade->nivel, nivelverde);
  }else if(novacidade->porcentagem < 60.0){
    char nivelamarelo[] = "AMARELO";
    strcpy(novacidade->nivel, nivelamarelo);
  }else if(novacidade->porcentagem <= 100.0){
    char nivelvermelho[] = "VERMELHO";
    strcpy(novacidade->nivel, nivelvermelho);
  }
  
    (*cidades)[*qtd_cidades] = *novacidade;
    (*qtd_cidades)++;
  
    system("clear");
    free(novacidade);
    return 1;
}

//FUNCAO PARA GERAR O RELATORIO DAS CIDADES
void gerarRelatorio(Cidade *cidades, int qtd_cidades){
  system("clear");
    int opmenu;
    if(qtd_cidades > 0){
        printf("\n\t\tCidades Cadastradas:\n\n");
        for(int i = 0; i < qtd_cidades; i++){
          printf("\t╭────────────────────────────────────────╮\n");
          printf("\t│                                        │\n");
          printf("\t│ Cidade: %s, Codigo: %d\n", cidades[i].nome,     cidades[i].codigo );
          printf("\t│                                        │\n");
          printf("\t╰────────────────────────────────────────╯\n");
        }
      printf("\n\tQuantidade de Cidades Registradas: %d\n", qtd_cidades);
      printf("\n\tDigite (1) Para Mais Detalhes, Voltar (0)\n\tQual opção deseja: ");
      scanf("%d", &opmenu);
      if(opmenu == 1){
        for(int i = 0; i < qtd_cidades; i++){
          printf("\t╭────────────────────────────────────────╮\n");
          printf("\t│                                        │\n");
          printf("\t│ Cidade: %s\n", cidades[i].nome);
          printf("\t│ Populacao: %0.f Habitantes\n", cidades[i].populacao);
          printf("\t│ Área: %0.3f Km²\n", cidades[i].area);
          printf("\t│ Área Desmatada: %0.3f Km²\n", cidades[i].area_desmatada);
          printf("\t│ Porcentagem: %0.1f% %\n", cidades[i].porcentagem);
          printf("\t│ Nível: %s\n", cidades[i].nivel);
          printf("\t│ População Por Km²: %1.0f\n", cidades[i].populacaoporarea);
          printf("\t│                                        │\n");
          printf("\t╰────────────────────────────────────────╯\n");
        }
      }else{
        return;
      }
    }else{
        printf("\tNenhuma cidade cadastrada!\n");
    }
}

/* Verificação da Área: Irá verificar os dados que usuário digitou no cadastro, assim verificando a taxa de desmatamento, comparando com sua área atual, com níveis: Verde, amarelo e vermelho. */
void indicedesmatamento(Cidade *dados, int tquantidade){
  system("clear");
  int opcao = 0, cod;
  printf("\n\t\tTELA DE MONITORAMENTO\n\n");
  printf("\tEscolha a opção:\n\n");
  printf("\t1 - Verificar todas as Cidades Cadastradas\n");
  printf("\t2 - Digitar o Código da Cidade\n\n\tDigite a opção: ");
  scanf("%d", &opcao);
  system("clear");
  switch(opcao){
    case 1:
      gerarRelatorio(dados, tquantidade);
    case 2:
      printf("\n\t\tTELA DE MONITORAMENTO\n");
      printf("\n\t---------======@======---------\n");
      printf("\n\tDigite o codigo: ");
      scanf("%d", &cod);
      int indice = -1;
        for (int i = 0; i < tquantidade; i++) {
            if (dados[i].codigo == cod) {
                indice = i;
                break;
            }
        }
      if(indice != -1) {
        // Cidade encontrada, mostrar o gráfico interativo
        mensagem(dados, indice);
      }else{
        printf("\n\tCidade Não Encontrada!\n");
      }
    break;
    default:
    printf("\n\tERRO, Número não válido\n"); 
  }
  return ;
}

void mensagem(Cidade *dados, int cod){
  int codigo = -1;
  system("clear");
  printf("\n\t\t---------======@======---------\n");
  printf("\t\t\t\tCidade: %s\n", dados[cod].nome);
  printf("\t\t---------======@======---------\n");
  printf("\n\t\tPorcentagem de Área Desmatada\n");
  float auxporcentagem;
  if(dados[cod].porcentagem  < 5){
      auxporcentagem = 5;
  }else{
    auxporcentagem = dados[cod].porcentagem; 
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
  
  //comparação com string da struct
  if(strcmp(dados[cod].nivel, "VERDE") == 0){
     codigo = 2;

  }else if(strcmp(dados[cod].nivel, "AMARELO") == 0){

    codigo = 1;
  }else if(strcmp(dados[cod].nivel, "VERMELHO") == 0){
    codigo = 0;
  }else{
    printf("ERRO, no Nível!\n");
  }
  
  if(codigo != -1){
    switch(codigo){
      case 0:
        printf("\n\t\t---------======@======---------\n");
        printf("\t\t         Alerta VERMELHO         \n");
        printf("\t\t        ▲                        \n");
        printf("\t\t       ▲▲▲                       \n");
        printf("\t\t      ▲▲▲▲▲                      \n");
        printf("\t\t     ▲▲▲▲▲▲▲                     \n");
        printf("\t\t       |||      |||      |||     \n");
        printf("\n\t\t---------======@======---------\n");
        printf("\t╭────────────────────────────────────────╮\n");
        printf("\t│                ORIENTAÇÂO              │\n");
        printf("\t│                                        │\n");
        printf("\t│   - Implementar medidas de emergência  │\n");
        printf("\t│   - Restaurando área desmatada         │\n");
        printf("\t│   - Evitar atividades que causam       │\n");
        printf("\t│     desmatamento                       │\n");
        printf("\t│   - Participar de programas de         │\n");
        printf("\t│     concientização de desmatamento     │\n");
        printf("\t│   - Promover conscientização para      │\n");
        printf("\t│     familiares e amigos                │\n");
        printf("\t│                                        │\n");
        printf("\t╰────────────────────────────────────────╯\n");
      break;
      case 1:
        printf("\n\t\t---------======@======---------\n");
        printf("\t\t         ALERTA AMARELO        \n");
        printf("\t\t        ▲        ▲               \n");
        printf("\t\t       ▲▲▲      ▲▲▲              \n");
        printf("\t\t      ▲▲▲▲▲    ▲▲▲▲▲             \n");
        printf("\t\t     ▲▲▲▲▲▲▲  ▲▲▲▲▲▲▲            \n");
        printf("\t\t       |||      |||      |||     \n");
        printf("\n\t\t---------======@======---------\n");
        printf("\t╭────────────────────────────────────────╮\n");
        printf("\t│                ORIENTAÇÂO              │\n");
        printf("\t│                                        │\n");
        printf("\t│   - Restauração de áreas degradadas    │\n");
        printf("\t│   - Monitorar possíveis focos de       │\n");
        printf("\t│     desmatamento                       │\n");
        printf("\t│   - Promover práticas sustentáveis     │\n");
        printf("\t│   - Participar de programas de         │\n");
        printf("\t│     concientização de desmatamento     │\n");
        printf("\t│   - Busca por Política de conservação  │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t╰────────────────────────────────────────╯\n");
      break;
      case 2:
        printf("\n\t\t---------======@======---------\n");
        printf("\t\t         ALERTA VERDE          \n");
        printf("\t\t        ▲        ▲        ▲      \n");
        printf("\t\t       ▲▲▲      ▲▲▲      ▲▲▲     \n");
        printf("\t\t      ▲▲▲▲▲    ▲▲▲▲▲    ▲▲▲▲▲    \n");
        printf("\t\t     ▲▲▲▲▲▲▲  ▲▲▲▲▲▲▲  ▲▲▲▲▲▲▲   \n");
        printf("\t\t       |||      |||      |||     \n");
        printf("\n\t\t---------======@======---------\n");
        printf("\t╭────────────────────────────────────────╮\n");
        printf("\t│                ORIENTAÇÂO              │\n");
        printf("\t│                                        │\n");
        printf("\t│   - Estabelecer Reservas Naturais      │\n");
        printf("\t│   - Promover agricultura sustentável   │\n");
        printf("\t│   - Ter Uma fiscalização eficaz        │\n");
        printf("\t│   - Educação ambiental                 │\n");
        printf("\t│   - Participação em programas de       │\n");
        printf("\t│     Reflorestamento                    │\n");
        printf("\t│   - Apoiar projetos de conservação     │\n");
        printf("\t│                                        │\n");
        printf("\t│                                        │\n");
        printf("\t╰────────────────────────────────────────╯\n");
      break;
    }
    }else{
    printf("\tERRO, Nível Nâo definido!\n");
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
    fprintf(arquivo,"%s %0.3f %0.3f %0.3f %0.1f %0.2f %s %d\n", cidades[i].nome, cidades[i].populacao, cidades[i].area, cidades[i].area_desmatada, cidades[i].porcentagem, cidades[i].populacaoporarea, cidades[i].nivel, cidades[i].codigo);
  }

  fclose(arquivo);
  
  return 1;
}

int carregarCidades(Cidade **cidades, char nomeArquivoEstoque[], int *qtd_cidades){
  system("clear");

  *cidades = (Cidade *)malloc(letras * sizeof(Cidade));
  *qtd_cidades = 0; 
  
  FILE *arquivo = fopen(nomeArquivoEstoque, "r");

  if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivoEstoque);
        return 0;
    }

  while (fscanf(arquivo, "%s %f %f %f %f %f %s %d\n", (*cidades)[*qtd_cidades].nome, &(*cidades)[*qtd_cidades].populacao, &(*cidades)[*qtd_cidades].area, &(*cidades)[*qtd_cidades].area_desmatada, &(*cidades)[*qtd_cidades].porcentagem, &(*cidades)[*qtd_cidades].populacaoporarea, (*cidades)[*qtd_cidades].nivel, &(*cidades)[*qtd_cidades].codigo) == 8) {
        (*qtd_cidades)++;
    }

    fclose(arquivo);
    return 1;
}


// FUNCAO DO MENU PRINCIPAL
void menuPrincipal(){
  system("clear");
  printf("\n\t\t--------== SustentCity ==--------\n");
  
  printf("\t╭────────────────────────────────────────╮\n");
  printf("\t│             MENU DE OPÇÕES             │\n");
  printf("\t│                                        │\n");
  printf("\t│                                        │\n");
  printf("\t│ 1 - Cadastrar Cidade             ^     │\n");
  printf("\t│ 2 - Gerar Relatório             ^^^    │\n");
  printf("\t│ 3 - Indice de Desmatamento     ^^^^^   │\n");
  printf("\t│ 4 - Salvar Cidades            ^^^^^^^  │\n");
  printf("\t│ 5 - Remover Cidade           ^^^^^^^^^ |\n");
  printf("\t│ 6 - Crédito                     │││    │\n");
  printf("\t│ 0 - Encerrar Programa                  │\n");
  printf("\t│                                        │\n");
  printf("\t╰────────────────────────────────────────╯\n");
  
  printf("\t\t--------== SustentCity ==--------\n");
  
}


// FUNCAO PARA BUSCAR INDICE
int buscarIndice(Cidade *cidades, int qtd_cidades, int codigobuscar){

  for (int i = 0; i <= qtd_cidades; i++) {
        if (codigobuscar == cidades[i].codigo) {
            return i;
        }
    }
    return -1;
}

int buscarNome(Cidade *cidades, int qtd_cidades, char *nomeBuscar){
    
    printf("Digite o nome da cidade: ");
    scanf("%s", nomeBuscar);

  for (int i = 0; i < qtd_cidades; i++) {
        if (strcmp(cidades->nome, nomeBuscar) == 0) {
            return i;
        }
    }
    return -1;
}

void removerCidade(Cidade **cidades, int *qtd_cidades, int codigobuscar) {

    printf("Digite o codigo: ");
    scanf("%d", &codigobuscar);
    int indice = buscarIndice(*cidades, *qtd_cidades, codigobuscar);

    if (indice != -1) {
        for (int i = indice; i < *qtd_cidades - 1; i++) {
            (*cidades)[i] = (*cidades)[i + 1];
        }

        Cidade *novaAloc = (Cidade *)realloc(*cidades, (*qtd_cidades - 1) * sizeof(Cidade));

        if (novaAloc != NULL || *qtd_cidades == 1) {
            *cidades = novaAloc;
            (*qtd_cidades)--;
            printf("\tCidade removida com sucesso!\n");
        } else {
            printf("\tErro ao realocar memoria.\n");
        }
    } else {
        printf("\tCidade não encontrada.\n");
    }
} 

// CREDITOS DO PROJETO
void credito(){
  system("clear");
  printf("\n\tDESENVOLVEDORES DO PROJETO:\n");
  printf("\n\tJosé Henrique Martins B. Silva");

  printf("\n\tGabriel Barauna De Souza\n");
  printf("\n\n\tTodos os Dados Foram Referentes ao Censo 2022\n");
  printf("\n\tFonte:\n");
  printf("\n\thttps://cidades.ibge.gov.br");
  printf("\n\thttps://www.dpi.inpe.br/prodesdigital/prodesmunicipal.php\n\n");
}