#include <stdio.h>

void shellSort(int vet[], int n)
{
    int gap = 1; // Define o tamanho inicial do intervalo

    // Executa o loop enquanto o tamanho do intervalo for menor ou igual a n
    while (gap <= n)
    {
        gap = gap * 3 + 1;
    }

    // Executa o loop enquanto o tamanho do intervalo for maior que 0
    while (gap > 0) 
    {
        
        // Percorre os elementos da lista a partir do intervalo gap
        for (int i = gap; i < n; i++)
        {
            // Armazena o valor atual da posição i em uma variável temporária
            int posiAtual = vet[i]; 
            int j = i; 

            // Desloca os elementos da sublista enquanto o valor atual for menor que o elemento anterior
            while (j >= gap && vet[j - gap] > posiAtual)
            {
                vet[j] = vet[j - gap];
                j -= gap;
            }

            // Insere o valor armazenado na variável temporária na posição correta
            vet[j] = posiAtual;
        }

        // Atualiza o tamanho do intervalo para a próxima iteração
        gap = (gap - 1) / 3;
    } 
}

int main()
{

    int vetor[] = {12, 34, 54, 2, 3};

    //Calcula o valor em bytes do vetor e encontra seu valor inteiro
    int n = sizeof(vetor) / sizeof(vetor[0]);

    // Executa o algoritmo de ordenação
    shellSort(vetor, n);

    // Imprime o resultado ordenado
    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%i ", vetor[i]);


    return 0;
}
