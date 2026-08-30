#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PRODUTOS 5
#define DIAS 7

int estoque[PRODUTOS][DIAS];
char dias_semana[DIAS][4] = {"Seg", "Ter", "Qua", "Qui", "Sex", "Sab", "Dom"};

void cadatrarEstoque()
{

    for (int i = 0; i < PRODUTOS; i++)
    {
        printf("\nProduto %d\n", i + 1);
        for (int j = 0; j < DIAS; j++)
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

    printf("\nEstoque cadastrado com sucesso!");
    printf("\nAperte enter para fechar: ");
    scanf("%*c");
}

void exibirEstoque()
{

    printf("           ");

    for (int i = 0; i < DIAS; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%c", dias_semana[i][j]);
        }
        printf(" ");
    }

    for (int i = 0; i < PRODUTOS; i++)
    {
        printf("\n");
        printf("Produto %d:  ", i + 1);
        for (int j = 0; j < DIAS; j++)
        {
            if (estoque[i][j] < 10)
            {
                printf("%d   ", estoque[i][j]);
            }
            else if (estoque[i][j] < 100)
            {
                printf("%d  ", estoque[i][j]);
            }
        }
    }

    printf("\nAperte enter para fechar: ");
    scanf("%*c");
}

void calcularEstoqueTotalPorProduto()
{
    int total_por_produto;

    for (int i = 0; i < PRODUTOS; i++)
    {
        total_por_produto = 0;
        for (int j = 0; j < DIAS; j++)
        {
            total_por_produto += estoque[i][j];
        }
        printf("\nProduto %d: %d unidades", i + 1, total_por_produto);
    }
    printf("\n");

    printf("\nAperte enter para fechar: ");
    scanf("%*c");
}

void calcularEstoqueTotaPorDia()
{
    int total_por_dia;

    for (int i = 0; i < DIAS; i++)
    {
        for (int j = 0; j < PRODUTOS; j++)
        {
            total_por_dia += estoque[j][i];
        }
    }
    printf("\n");

    printf("\nAperte enter para fechar: ");
    scanf("%*c");
}

int main()
{
    int opcao;

    while (true)
    {
        system("clear");
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

        do
        {
            int leitura_sucesso;

            printf("Digite sua opção: ");

            leitura_sucesso = scanf("%d", &opcao);
            while (getchar() != '\n')
                ;
            if (opcao < 0 || opcao > 7 || leitura_sucesso != 1)
            {
                printf("Opção inválida. Por favor, digite um número entre 0 e 7.\n");
            }

        } while (opcao < 0 || opcao > 7);

        switch (opcao)
        {
        case 1:

            printf("\n========================================\n");
            printf(" CADASTRO DE ESTOQUE\n");
            printf("========================================\n");
            cadatrarEstoque();
            break;

        case 2:

            printf("\n========================================\n");
            printf(" EXIBIR ESTOQUE\n");
            printf("========================================\n");
            exibirEstoque();
            break;

        case 3:

            printf("\n========================================\n");
            printf(" Calcular Total de Estoque por Produto\n");
            printf("========================================\n");
            calcularEstoqueTotalPorProduto();
            break;

        case 4:

            printf("\n========================================\n");
            printf(" Calcular Total de Estoque por Dia\n");
            printf("========================================\n");
            calcularEstoqueTotaPorDia();
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
            exit(0);
        }
    }

    return 0;
}