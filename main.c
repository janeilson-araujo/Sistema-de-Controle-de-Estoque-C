#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PRODUTOS 5
#define DIAS 7

int estoque[PRODUTOS][DIAS];
char dias_semana[DIAS][8] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sabado", "Domingo"};

void cadatrarEstoque()
{
    system("clear");
    printf("\n========================================\n");
    printf(" CADASTRO DE ESTOQUE\n");
    printf("========================================\n");

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
    system("clear");
    printf("\n========================================\n");
    printf(" EXIBIR ESTOQUE\n");
    printf("========================================\n");

    printf("           ");
    for (int i = 0; i < DIAS; i++)
    {
        for (int j = 0; j < 3; j++)
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
    system("clear");
    printf("\n========================================\n");
    printf(" Calcular Total de Estoque por Produto\n");
    printf("========================================\n");

    int total_por_produto;

    for (int i = 0; i < PRODUTOS; i++)
    {
        total_por_produto = 0;
        for (int j = 0; j < DIAS; j++)
        {
            total_por_produto = total_por_produto + estoque[i][j];
        }
        printf("\nProduto %d: %d unidades", i + 1, total_por_produto);
    }
    printf("\n");

    printf("\nAperte enter para fechar: ");
    scanf("%*c");
}

void calcularEstoqueTotaPorDia()
{
    system("clear");
    printf("\n========================================\n");
    printf(" Calcular Total de Estoque por Dia\n");
    printf("========================================\n");

    int total_por_dia;

    for (int i = 0; i < DIAS; i++)
    {

        total_por_dia = 0;

        for (int j = 0; j < PRODUTOS; j++)
        {
            total_por_dia = total_por_dia + estoque[j][i];
        }

        for (int j = 0; j < 8; j++)
        {
            printf("%c", dias_semana[i][j]);
        }
        printf(":");
        printf(" %d unidades", total_por_dia);
        printf("\n");
    }

    printf("\n");
    printf("\nAperte enter para fechar: ");
    scanf("%*c");
}

void produtoComMaiorEstoque()
{
    system("clear");
    printf("\n========================================\n");
    printf(" Produto com Maior Estoque\n");
    printf("========================================\n");

    int produto_maior_estoque = 0;
    int produto_maior_estoque_valor = 0;
    int total_por_produto;

    for (int i = 0; i < PRODUTOS; i++)
    {
        total_por_produto = 0;
        for (int j = 0; j < DIAS; j++)
        {
            total_por_produto = total_por_produto + estoque[i][j];
        }

        if (produto_maior_estoque_valor <= total_por_produto)
        {
            produto_maior_estoque_valor = total_por_produto;
            produto_maior_estoque = i;
        }
    }

    printf("\nProduto com maior estoque:\nProduto %d\n\nQuantidade total:\n%d unidades", produto_maior_estoque + 1, produto_maior_estoque_valor);

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
            cadatrarEstoque();
            break;

        case 2:
            exibirEstoque();
            break;

        case 3:
            calcularEstoqueTotalPorProduto();
            break;

        case 4:
            calcularEstoqueTotaPorDia();
            break;

        case 5:

            produtoComMaiorEstoque();
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