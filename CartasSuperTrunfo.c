#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIDADES 32  // 8 estados x 4 cidades
#define MAX_NOME 50

typedef struct {
    char estado;
    char codigo[4];
    char nome[MAX_NOME];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
} Cidade;

// Função para cadastrar uma cidade
void cadastrar_cidade(Cidade *cidade) {
    printf("=== Cadastro de Cidade ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &cidade->estado);
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", cidade->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade->nome);
    printf("Digite a população: ");
    scanf("%d", &cidade->populacao);
    printf("Digite a área em km²: ");
    scanf("%f", &cidade->area);
    printf("Digite o PIB: ");
    scanf("%f", &cidade->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->num_pontos_turisticos);

    printf("\n=== Cidade Cadastrada ===\n");
    printf("Estado: %c\n", cidade->estado);
    printf("Código: %s\n", cidade->codigo);
    printf("Nome da Cidade: %s\n", cidade->nome);
    printf("População: %d\n", cidade->populacao);
    printf("Área: %.2f km²\n", cidade->area);
    printf("PIB: R$ %.2f\n", cidade->pib);
    printf("Número de Pontos Turísticos: %d\n\n", cidade->num_pontos_turisticos);
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(Cidade cidade) {
    if (cidade.populacao == 0) return 0;
    return cidade.pib / cidade.populacao;
}

// Função para comparar duas cidades com base em um atributo
void comparar_cidades(Cidade c1, Cidade c2, int atributo) {
    printf("\nComparando %s vs %s\n", c1.nome, c2.nome);

    float valor1, valor2;

    switch (atributo) {
        case 1:
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            printf("População: %d vs %d\n", c1.populacao, c2.populacao);
            break;
        case 2:
            valor1 = c1.area;
            valor2 = c2.area;
            printf("Área: %.2f vs %.2f\n", c1.area, c2.area);
            break;
        case 3:
            valor1 = c1.pib;
            valor2 = c2.pib;
            printf("PIB: %.2f vs %.2f\n", c1.pib, c2.pib);
            break;
        case 4:
            valor1 = c1.num_pontos_turisticos;
            valor2 = c2.num_pontos_turisticos;
            printf("Pontos turísticos: %d vs %d\n", c1.num_pontos_turisticos, c2.num_pontos_turisticos);
            break;
        case 5:
            valor1 = calcular_pib_per_capita(c1);
            valor2 = calcular_pib_per_capita(c2);
            printf("PIB per capita: %.2f vs %.2f\n", valor1, valor2);
            break;
        default:
            printf("Atributo inválido.\n");
            return;
    }

    if (valor1 > valor2)
        printf("Vencedora: %s\n", c1.nome);
    else if (valor2 > valor1)
        printf("Vencedora: %s\n", c2.nome);
    else
        printf("Empate!\n");
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int cont = 0;
    char continuar;

    // Cadastro das cidades
    do {
        if (cont >= MAX_CIDADES) {
            printf("Número máximo de cidades cadastradas atingido.\n");
            break;
        }

        cadastrar_cidade(&cidades[cont]);
        cont++;

        printf("Deseja cadastrar outra cidade? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    // Comparação de cidades
    if (cont >= 2) {
        int i1, i2, atributo;

        printf("\n=== Comparação de Cidades ===\n");
        printf("Escolha o índice da primeira cidade (0 a %d): ", cont - 1);
        scanf("%d", &i1);
        printf("Escolha o índice da segunda cidade (0 a %d): ", cont - 1);
        scanf("%d", &i2);

        if (i1 < 0 || i1 >= cont || i2 < 0 || i2 >= cont) {
            printf("Índices inválidos.\n");
            return 1;
        }

        printf("\nEscolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos turísticos\n");
        printf("5 - PIB per capita\n");
        printf("Opção: ");
        scanf("%d", &atributo);

        comparar_cidades(cidades[i1], cidades[i2], atributo);
    } else {
        printf("É necessário cadastrar pelo menos duas cidades para comparar.\n");
    }

    printf("\nSistema encerrado.\n");
    return 0;
}
