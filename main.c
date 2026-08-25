#include <stdio.h>
#define PRODUTOS 5
#define DIAS 7

int estoque[PRODUTOS][DIAS];

void exibirestoque()
{
    for (int i = 0; i < PRODUTOS; i++)
    {
        for (int j = 0; j < DIAS; j++)
        {
            printf("Produto %d, Dia %d: %d\n", i + 1, j + 1, estoque[i][j]);
        }
    }
}

int main()
{

    int opcao;
    int i, j;
    do
    {
        printf("\n========================================\n");
        printf(" SISTEMA DE CONTROLE DE ESTOQUE\n");
        printf("========================================\n");
        printf("1 - Cadastrar estoque\n");
        printf("2 - Exibir estoque\n");
        printf("3 - Calcular estoque total por produto\n");
        printf("4 - Calcular estoque total por dia\n");
        printf("5 - Encontrar produto com maior estoque\n");
        printf("6 - Encontrar dia com maior estoque\n");
        printf("7 - Verificar produtos com estoque baixo\n");
        printf("0 - Sair\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:

            printf("\n========================================\n");
            printf(" CADASTRO DE ESTOQUE\n");
            printf("========================================\n");
            for (i = 0; i < PRODUTOS; i++)
            {
                printf("\nProduto %d\n", i + 1);
                for (j = 0; j < DIAS; j++)
                {
                    switch (j)
                    {
                    case 0:
                        printf("Segunda-feira: ");
                        break;
                    case 1:
                        printf("Terca-feira: ");
                        break;
                    case 2:
                        printf("Quarta-feira: ");
                        break;
                    case 3:
                        printf("Quinta-feira: ");
                        break;
                    case 4:
                        printf("Sexta-feira: ");
                        break;
                    case 5:
                        printf("Sabado: ");
                        break;
                    case 6:
                        printf("Domingo: ");
                        break;
                    }
                    scanf("%d", &estoque[i][j]);
                }
            }
            printf("\nEstoque cadastrado com sucesso!\n");
            break;
        case 2:
            printf("\n========================================\n");
            printf(" EXIBIR ESTOQUE\n");
            printf("========================================\n");
            exibirEstoque();
            break;
        case 3:
            printf("\nFuncionalidade ainda nao implementada.\n");
            break;
        case 4:
            printf("\nFuncionalidade ainda nao implementada.\n");
            break;
        case 5:
            printf("\nFuncionalidade ainda nao implementada.\n");
            break;
        case 6:
            printf("\nFuncionalidade ainda nao implementada.\n");
            break;
        case 7:
            printf("\nFuncionalidade ainda nao implementada.\n");
            break;
        case 0:
            printf("\nEncerrando o sistema...\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);
    return 0;
}