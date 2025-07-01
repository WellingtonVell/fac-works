#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

// Estrutura para armazenar os dados de uma carta
typedef struct {
    char codigo[4];               // Código da carta (ex: A01)
    unsigned long int populacao;  // População (unsigned long para nível Mestre)
    float area;                   // Área em km²
    float pib;                    // PIB em milhões
    int pontosTuristicos;        // Número de pontos turísticos
    float densidadePopulacional; // População / Área
    float pibPerCapita;          // PIB / População
    float superPoder;            // Soma de todos atributos (com densidade invertida)
} Carta;

// Função para calcular os atributos derivados de uma carta
void calcularAtributos(Carta *carta) {
    // Calcula densidade populacional
    carta->densidadePopulacional = (float)carta->populacao / carta->area;
    
    // Calcula PIB per capita
    carta->pibPerCapita = carta->pib / carta->populacao;
    
    // Calcula Super Poder (soma de todos os atributos com densidade invertida)
    carta->superPoder = (float)carta->populacao + 
                       carta->area + 
                       carta->pib + 
                       (float)carta->pontosTuristicos + 
                       carta->pibPerCapita + 
                       (1.0f / carta->densidadePopulacional);
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("Codigo: %s\n", carta.codigo);
    printf("Populacao: %lu\n", carta.populacao);
    printf("Area: %.2f km2\n", carta.area);
    printf("PIB: %.2f milhoes\n", carta.pib);
    printf("Pontos Turisticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km2\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Função para comparar duas cartas
void compararCartas(Carta carta1, Carta carta2) {
    printf("\n=== Resultado da Comparacao ===\n");
    printf("1 = Carta 1 vence, 0 = Carta 2 vence\n\n");
    
    // Para densidade populacional, menor valor vence
    printf("Populacao: %d\n", carta1.populacao > carta2.populacao);
    printf("Area: %d\n", carta1.area > carta2.area);
    printf("PIB: %d\n", carta1.pib > carta2.pib);
    printf("Pontos Turisticos: %d\n", carta1.pontosTuristicos > carta2.pontosTuristicos);
    printf("Densidade Populacional: %d\n", carta1.densidadePopulacional < carta2.densidadePopulacional);
    printf("PIB per Capita: %d\n", carta1.pibPerCapita > carta2.pibPerCapita);
    printf("Super Poder: %d\n", carta1.superPoder > carta2.superPoder);
}

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    printf("=== SUPER TRUNFO - PAISES ===\n\n");
    
    // Declaração das cartas
    Carta carta1, carta2;
    
    // Cadastro da primeira carta
    printf("Cadastro da Carta 1:\n");
    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Digite a populacao (ex: 12396372): ");
    scanf("%lu", &carta1.populacao);
    printf("Digite a area (km2) (ex: 1521.11): ");
    scanf("%f", &carta1.area);
    printf("Digite o PIB (milhoes) (ex: 875000.50): ");
    scanf("%f", &carta1.pib);
    printf("Digite o numero de pontos turisticos (ex: 15): ");
    scanf("%d", &carta1.pontosTuristicos);
    
    // Cadastro da segunda carta
    printf("\nCadastro da Carta 2:\n");
    printf("Digite o codigo da carta (ex: B02): ");
    scanf("%s", carta2.codigo);
    printf("Digite a populacao (ex: 6775561): ");
    scanf("%lu", &carta2.populacao);
    printf("Digite a area (km2) (ex: 1200.27): ");
    scanf("%f", &carta2.area);
    printf("Digite o PIB (milhoes) (ex: 420000.75): ");
    scanf("%f", &carta2.pib);
    printf("Digite o numero de pontos turisticos (ex: 22): ");
    scanf("%d", &carta2.pontosTuristicos);
    
    // Calcula os atributos derivados para ambas as cartas
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);
    
    // Exibe os dados das cartas
    printf("\n=== Carta 1 ===\n");
    exibirCarta(carta1);
    printf("\n=== Carta 2 ===\n");
    exibirCarta(carta2);
    
    // Compara as cartas
    compararCartas(carta1, carta2);
    
    printf("\nPressione ENTER para encerrar...");
    while (getchar() != '\n');
    getchar();
    
    return 0;
}