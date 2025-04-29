#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de Dados Passagem
struct Passagem
{
    int num_passagem;
    int num_voo;
    char data[11];
    char horario[6];
    char portao[20];
};

// Função para cadastrar uma nova passagem
void cadastrarPassagem(struct Passagem *passagem, int *num_passagem)
{
    printf("Digite o numero da passagem: ");
    scanf("%d", &passagem[*num_passagem].num_passagem);
    fflush(stdin);
    printf("Digite o numero do voo: ");
    scanf("%d", &passagem[*num_passagem].num_voo);
    fflush(stdin);
    printf("Digite a data do voo (dd/mm/aaaa): ");
    scanf("%s", passagem[*num_passagem].data);
    fflush(stdin);
    printf("Digite o horario de embarque do voo (hh:mm): ");
    scanf("%s", passagem[*num_passagem].horario);
    fflush(stdin);
    printf("Digite o portao de embarque: ");
    scanf("%s", passagem[*num_passagem].portao);
    fflush(stdin);
    (*num_passagem)++;
    printf("Passagem Cadastrada com Sucesso!\n");
}

// Função para consultar informações de uma passagem
void consultarPassagem(struct Passagem *passagem, int num_passagem)
{
    int numero, i;
    printf("Digite o numero da passagem: ");
    scanf("%d", &numero);
    for (i=0;i<num_passagem;i++)
    {
        if (passagem[i].num_passagem == numero)
        {
            printf("Numero da passagem: %d\n", passagem[i].num_passagem);
            printf("Numero do voo: %d\n", passagem[i].num_voo);
            printf("Data do voo: %s\n", passagem[i].data);
            printf("Horario do voo: %s\n", passagem[i].horario);
            printf("Portao de Embarque:: %s\n", passagem[i].portao);
            return;
        }
    }
    printf("Numero da Passagem nao encontrada!\n");
}

int main()
{
    int opcao, num_passagem=0;
    struct Passagem passagem[100];

    do
    {
        printf("\n --- Selecione --- \n");
        printf("1 - Cadastrar Passagem\n");
        printf("2 - Consultar Passagem\n");
        printf("0 - Sair\n");
        printf("Digite a opcao escolhida: ");
        if (scanf("%d", &opcao) != 1) // Verifica se a entrada é um numero inteiro
        {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcao)
        {
        case 1:
            cadastrarPassagem(passagem, &num_passagem);
            break;
        case 2:
            consultarPassagem(passagem, num_passagem);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Selecione o que existe!\n");
        }
    }
    while (opcao != 0);

    return 0;
}
