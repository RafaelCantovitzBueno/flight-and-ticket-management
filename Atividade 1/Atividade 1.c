#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de Dados voo
struct voo
{
    int numero;
    char data[11];
    char horario[6];
    char aeroporto_saida[50];
    char aeroporto_chegada[50];
    char rota[100];
    int tempo_estimado;
    int passageiros_a_bordo;
};

// Função para cadastrar um novo voo
void cadastrarVoo(struct voo *voos, int *num_voos) // *voos funciona como um vetor
                                                   // *num_voos guarda quantos voos foram registrados
                                                   // o num_voos usa * nesse void pq ponteiro(*) é usado para modificar o
                                                   // valor da variável diretamente na função main.
{
    printf("Digite o numero do voo: ");
    scanf("%d", &voos[*num_voos].numero);
    printf("Digite a data do voo (dd/mm/aaaa): ");
    scanf("%s", voos[*num_voos].data);
    printf("Digite o horario do voo (hh:mm): ");
    scanf("%s", voos[*num_voos].horario);
    printf("Digite o aeroporto de saida: ");
    scanf(" %s", voos[*num_voos].aeroporto_saida);
    printf("Digite o aeroporto de chegada: ");
    scanf(" %s", voos[*num_voos].aeroporto_chegada);
    printf("Digite a rota: ");
    scanf(" %s", voos[*num_voos].rota);
    printf("Digite o tempo estimado de voo (em minutos): ");
    scanf("%d", &voos[*num_voos].tempo_estimado);
    printf("Digite o numero de passageiros a bordo: ");
    scanf("%d", &voos[*num_voos].passageiros_a_bordo);
    (*num_voos)++;
    printf("Voo cadastrado com sucesso!\n");
}

// Função para consultar informações de um voo
void consultarVoo(struct voo *voos, int num_voos) // o parâmetro num_voos não precisa ser um ponteiro,
                                                  // pois a função não altera o valor de num_voos.
{
    int numero, i;
    printf("Digite o número do voo: ");
    scanf("%d", &numero);
    for (i = 0; i < num_voos; i++)
    {
        if (voos[i].numero == numero)
        {
            printf(">Numero do voo: %d\n", voos[i].numero);
            printf(">Data do voo: %s\n", voos[i].data);
            printf(">Horario do voo: %s\n", voos[i].horario);
            printf(">Aeroporto de saida: %s\n", voos[i].aeroporto_saida);
            printf(">Aeroporto de chegada: %s\n", voos[i].aeroporto_chegada);
            printf(">Rota: %s\n", voos[i].rota);
            printf(">Tempo estimado de voo: %d minutos\n", voos[i].tempo_estimado);
            printf(">Passageiros a bordo: %d\n", voos[i].passageiros_a_bordo);
            return;
        }
    }
    printf("Voo não encontrado!\n");
}

int main()
{
    int opcao, num_voos = 0;
    struct voo voos[100];

    do
    {
        printf(" --- Selecione --- \n");
        printf("1 - Cadastrar voo\n");
        printf("2 - Consultar voo\n");
        printf("0 - Sair\n");
        printf("Digite a opcao escolhida: ");
        if (scanf("%d", &opcao) != 1) // Verifica se a entrada é um numero inteiro, se for letra ele entra no while
        {
            printf("Entrada invalida. Tente novamente.\n");
            while (getchar() != '\n'); // Quando ele apertar enter, sai do while
            continue;
        }

        switch (opcao)
        {
        case 1:
            cadastrarVoo(voos, &num_voos);
            break;
        case 2:
            consultarVoo(voos, num_voos);
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
