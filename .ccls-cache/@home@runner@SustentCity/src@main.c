#include "desmatamento.h"


int main(void) {

  int opcao;
  int qtd_cidades;
  int codigobuscar;

  char nomeArquivoEstoque[] = "data/cidades.txt";

  Cidade *cidades = NULL;

  //Carrega os dados no arquivo, pode ser removido depois ou tratado melhor
  if(carregarCidades(&cidades, nomeArquivoEstoque, &qtd_cidades)){
    printf("AVISO DE TESTES...\nCIDADES CARREGADAS\n");
    
  }else{
    printf("Erro ao carregar cidades\n");
  }
    
  do {

        //FUNCAO COM O MENU PRINCIPAL, MELHOR PARA POLUIR MENOS A MAIN
        menuPrincipal();
        printf("\n\nDigite uma Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if(cadastrarCidade(&cidades, &qtd_cidades)){
                  printf("Cadastrada com sucesso!\n");
                }else{
                  printf("Erro ao cadastrar!\n");
                }
                break;
            case 2:
                gerarRelatorio(cidades, qtd_cidades);
                break;
            case 3:
                indicedesmatamento(cidades, qtd_cidades);
                break;
            case 4:
                if(salvarCidades(cidades, nomeArquivoEstoque, qtd_cidades)){
                  printf("Salvo com sucesso!\n");
                }else{
                  printf("Erro ao salvar dados!\n");
                }
                break;
            case 5:
                removerCidade(&cidades, &qtd_cidades, codigobuscar);
                break;
            case 6:
                
            break;
            default:
                printf("Programa Encerrado!");
                break;
        }

    printf("\n\nPressione Enter para Retornar ao Menu de Opções\n");
    getchar();
    getchar();
    }while (opcao != 0);
  free(cidades);
  return 0;
}