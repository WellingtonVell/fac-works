#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

typedef struct {
    char estado[50];
    char codigo[20];
    char nome[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Cidade;

// Função para calcular densidade populacional
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para cadastrar uma cidade
void cadastrarCidade(Cidade *cidade) {
    printf("\n=== Cadastro de Cidade ===\n");
    
    printf("Estado: ");
    scanf("%49s", cidade->estado);
    limparBuffer();
    
    printf("Codigo da cidade: ");
    scanf("%19s", cidade->codigo);
    limparBuffer();
    
    printf("Nome da cidade: ");
    scanf("%99[^\n]", cidade->nome);
    limparBuffer();
    
    printf("Populacao: ");
    scanf("%d", &cidade->populacao);
    limparBuffer();
    
    printf("Area (km2): ");
    scanf("%f", &cidade->area);
    limparBuffer();
    
    printf("PIB (milhoes): ");
    scanf("%f", &cidade->pib);
    limparBuffer();
    
    printf("Numero de pontos turisticos: ");
    scanf("%d", &cidade->pontosTuristicos);
    limparBuffer();
    
    printf("\nCidade cadastrada com sucesso!\n");
}

// Função para exibir os dados de uma cidade
void exibirCidade(Cidade cidade, int numero) {
    float densidade = calcularDensidade(cidade.populacao, cidade.area);
    
    printf("\n=== Cidade %d: %s ===\n", numero, cidade.nome);
    printf("Estado: %s\n", cidade.estado);
    printf("Codigo: %s\n", cidade.codigo);
    printf("Populacao: %d habitantes\n", cidade.populacao);
    printf("Area: %.2f km2\n", cidade.area);
    printf("Densidade populacional: %.2f hab/km2\n", densidade);
    printf("PIB: %.2f milhoes\n", cidade.pib);
    printf("Pontos turisticos: %d\n", cidade.pontosTuristicos);
}

// Função para comparar dois atributos e determinar o vencedor
int compararAtributos(Cidade cidade1, Cidade cidade2, int atributo1, int atributo2) {
    int resultado1 = 0;
    int resultado2 = 0;
    
    // Comparação do primeiro atributo
    switch (atributo1) {
        case 1: // População
            resultado1 = (cidade1.populacao > cidade2.populacao) ? 1 : 
                         (cidade1.populacao < cidade2.populacao) ? -1 : 0;
            break;
        case 2: // Área
            resultado1 = (cidade1.area > cidade2.area) ? 1 : 
                         (cidade1.area < cidade2.area) ? -1 : 0;
            break;
        case 3: // PIB
            resultado1 = (cidade1.pib > cidade2.pib) ? 1 : 
                         (cidade1.pib < cidade2.pib) ? -1 : 0;
            break;
        case 4: // Pontos turísticos
            resultado1 = (cidade1.pontosTuristicos > cidade2.pontosTuristicos) ? 1 : 
                         (cidade1.pontosTuristicos < cidade2.pontosTuristicos) ? -1 : 0;
            break;
        case 5: // Densidade populacional (menor é melhor)
            resultado1 = (calcularDensidade(cidade1.populacao, cidade1.area) < 
                          calcularDensidade(cidade2.populacao, cidade2.area)) ? 1 : 
                         (calcularDensidade(cidade1.populacao, cidade1.area) > 
                          calcularDensidade(cidade2.populacao, cidade2.area)) ? -1 : 0;
            break;
    }
    
    // Comparação do segundo atributo
    switch (atributo2) {
        case 1: // População
            resultado2 = (cidade1.populacao > cidade2.populacao) ? 1 : 
                         (cidade1.populacao < cidade2.populacao) ? -1 : 0;
            break;
        case 2: // Área
            resultado2 = (cidade1.area > cidade2.area) ? 1 : 
                         (cidade1.area < cidade2.area) ? -1 : 0;
            break;
        case 3: // PIB
            resultado2 = (cidade1.pib > cidade2.pib) ? 1 : 
                         (cidade1.pib < cidade2.pib) ? -1 : 0;
            break;
        case 4: // Pontos turísticos
            resultado2 = (cidade1.pontosTuristicos > cidade2.pontosTuristicos) ? 1 : 
                         (cidade1.pontosTuristicos < cidade2.pontosTuristicos) ? -1 : 0;
            break;
        case 5: // Densidade populacional (menor é melhor)
            resultado2 = (calcularDensidade(cidade1.populacao, cidade1.area) < 
                          calcularDensidade(cidade2.populacao, cidade2.area)) ? 1 : 
                         (calcularDensidade(cidade1.populacao, cidade1.area) > 
                          calcularDensidade(cidade2.populacao, cidade2.area)) ? -1 : 0;
            break;
    }
    
    // Determinar o vencedor com base nos resultados dos dois atributos
    if (resultado1 > 0 && resultado2 > 0) {
        return 1; // Cidade 1 vence em ambos os atributos
    } else if (resultado1 < 0 && resultado2 < 0) {
        return -1; // Cidade 2 vence em ambos os atributos
    } else if (resultado1 > 0 || resultado2 > 0) {
        return (resultado1 + resultado2 > 0) ? 1 : -1; // Cidade com mais vitórias vence
    } else if (resultado1 < 0 || resultado2 < 0) {
        return (resultado1 + resultado2 < 0) ? -1 : 1; // Cidade com mais vitórias vence
    } else {
        return 0; // Empate
    }
}

// Função para exibir o nome do atributo
void exibirNomeAtributo(int atributo) {
    switch (atributo) {
        case 1:
            printf("Populacao");
            break;
        case 2:
            printf("Area");
            break;
        case 3:
            printf("PIB");
            break;
        case 4:
            printf("Pontos Turisticos");
            break;
        case 5:
            printf("Densidade Populacional"); 
            break;
    }
}

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);
    
    Cidade cidade1, cidade2;
    int opcao, atributo1, atributo2;
    
    printf("=== Super Trunfo - Paises - Nivel Mestre ===\n");
    
    do {
        printf("\nMenu Principal:\n");
        printf("1. Cadastrar Cidades\n");
        printf("2. Exibir Cidades\n");
        printf("3. Comparar Cidades\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();
        
        switch (opcao) {
            case 1:
                printf("\nCadastrando Cidade 1:\n");
                cadastrarCidade(&cidade1);
                
                printf("\nCadastrando Cidade 2:\n");
                cadastrarCidade(&cidade2);
                break;
                
            case 2:
                exibirCidade(cidade1, 1);
                exibirCidade(cidade2, 2);
                break;
                
            case 3:
                printf("\n=== Comparacao de Cidades ===\n");
                printf("Escolha o primeiro atributo para comparacao:\n");
                printf("1. Populacao (maior vence)\n");
                printf("2. Area (maior vence)\n");
                printf("3. PIB (maior vence)\n");
                printf("4. Pontos Turisticos (maior vence)\n");
                printf("5. Densidade Populacional (menor vence)\n");
                printf("Escolha: ");
                scanf("%d", &atributo1);
                limparBuffer();
                
                printf("\nEscolha o segundo atributo para comparacao:\n");
                printf("1. Populacao (maior vence)\n");
                printf("2. Area (maior vence)\n");
                printf("3. PIB (maior vence)\n");
                printf("4. Pontos Turisticos (maior vence)\n");
                printf("5. Densidade Populacional (menor vence)\n");
                printf("Escolha: ");
                scanf("%d", &atributo2);
                limparBuffer();
                
                printf("\nComparando ");
                exibirNomeAtributo(atributo1);
                printf(" e ");
                exibirNomeAtributo(atributo2);
                printf("...\n");
                
                int resultado = compararAtributos(cidade1, cidade2, atributo1, atributo2);
                
                if (resultado > 0) {
                    printf("\nA cidade %s venceu!\n", cidade1.nome);
                } else if (resultado < 0) {
                    printf("\nA cidade %s venceu!\n", cidade2.nome);
                } else {
                    printf("\nEmpate! As cidades tem desempenho igual nos atributos selecionados.\n");
                }
                
                // Mostrar detalhes da comparação usando operador ternário
                printf("\nDetalhes da comparacao:\n");
                
                // Primeiro atributo
                printf("- ");
                exibirNomeAtributo(atributo1);
                printf(": ");
                
                switch (atributo1) {
                    case 1: // População
                        printf("%s (%d) %s %s (%d)\n", 
                               cidade1.nome, cidade1.populacao,
                               cidade1.populacao > cidade2.populacao ? ">" : 
                               cidade1.populacao < cidade2.populacao ? "<" : "=",
                               cidade2.nome, cidade2.populacao);
                        break;
                    case 2: // Área
                        printf("%s (%.2f) %s %s (%.2f)\n", 
                               cidade1.nome, cidade1.area,
                               cidade1.area > cidade2.area ? ">" : 
                               cidade1.area < cidade2.area ? "<" : "=",
                               cidade2.nome, cidade2.area);
                        break;
                    case 3: // PIB
                        printf("%s (%.2f) %s %s (%.2f)\n", 
                               cidade1.nome, cidade1.pib,
                               cidade1.pib > cidade2.pib ? ">" : 
                               cidade1.pib < cidade2.pib ? "<" : "=",
                               cidade2.nome, cidade2.pib);
                        break;
                    case 4: // Pontos turísticos
                        printf("%s (%d) %s %s (%d)\n", 
                               cidade1.nome, cidade1.pontosTuristicos,
                               cidade1.pontosTuristicos > cidade2.pontosTuristicos ? ">" : 
                               cidade1.pontosTuristicos < cidade2.pontosTuristicos ? "<" : "=",
                               cidade2.nome, cidade2.pontosTuristicos);
                        break;
                    case 5: // Densidade populacional
                        printf("%s (%.2f) %s %s (%.2f) [menor e melhor]\n", 
                               cidade1.nome, calcularDensidade(cidade1.populacao, cidade1.area),
                               calcularDensidade(cidade1.populacao, cidade1.area) < calcularDensidade(cidade2.populacao, cidade2.area) ? "<" : 
                               calcularDensidade(cidade1.populacao, cidade1.area) > calcularDensidade(cidade2.populacao, cidade2.area) ? ">" : "=",
                               cidade2.nome, calcularDensidade(cidade2.populacao, cidade2.area));
                        break;
                }
                
                // Segundo atributo
                printf("- ");
                exibirNomeAtributo(atributo2);
                printf(": ");
                
                switch (atributo2) {
                    case 1: // População
                        printf("%s (%d) %s %s (%d)\n", 
                               cidade1.nome, cidade1.populacao,
                               cidade1.populacao > cidade2.populacao ? ">" : 
                               cidade1.populacao < cidade2.populacao ? "<" : "=",
                               cidade2.nome, cidade2.populacao);
                        break;
                    case 2: // Área
                        printf("%s (%.2f) %s %s (%.2f)\n", 
                               cidade1.nome, cidade1.area,
                               cidade1.area > cidade2.area ? ">" : 
                               cidade1.area < cidade2.area ? "<" : "=",
                               cidade2.nome, cidade2.area);
                        break;
                    case 3: // PIB
                        printf("%s (%.2f) %s %s (%.2f)\n", 
                               cidade1.nome, cidade1.pib,
                               cidade1.pib > cidade2.pib ? ">" : 
                               cidade1.pib < cidade2.pib ? "<" : "=",
                               cidade2.nome, cidade2.pib);
                        break;
                    case 4: // Pontos turísticos
                        printf("%s (%d) %s %s (%d)\n", 
                               cidade1.nome, cidade1.pontosTuristicos,
                               cidade1.pontosTuristicos > cidade2.pontosTuristicos ? ">" : 
                               cidade1.pontosTuristicos < cidade2.pontosTuristicos ? "<" : "=",
                               cidade2.nome, cidade2.pontosTuristicos);
                        break;
                    case 5: // Densidade populacional
                        printf("%s (%.2f) %s %s (%.2f) [menor e melhor]\n", 
                               cidade1.nome, calcularDensidade(cidade1.populacao, cidade1.area),
                               calcularDensidade(cidade1.populacao, cidade1.area) < calcularDensidade(cidade2.populacao, cidade2.area) ? "<" : 
                               calcularDensidade(cidade1.populacao, cidade1.area) > calcularDensidade(cidade2.populacao, cidade2.area) ? ">" : "=",
                               cidade2.nome, calcularDensidade(cidade2.populacao, cidade2.area));
                        break;
                }
                break;
                
            case 0:
                printf("\nEncerrando o programa. Obrigado!\n");
                break;
                
            default:
                printf("\nOpcao invalida. Tente novamente.\n");
        }
        
    } while (opcao != 0);

    return 0;
}