#include <stdio.h>

void shellSort(int arr[], int n)
{
    int gap = n / 2; // Define o tamanho inicial do intervalo

    // Executa o loop enquanto o tamanho do intervalo for maior que 0
    while (gap > 0)
    {
        // Percorre os elementos da lista a partir do intervalo gap
        for (int i = gap; i < n; i++)
        {
            // Armazena o valor atual da posição i em uma variável temporária
            int posiAtual = arr[i];
            int j = i;

            // Desloca os elementos da sublista enquanto o valor atual for menor que o elemento anterior
            while (j >= gap && arr[j - gap] > posiAtual)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Insere o valor armazenado na variável temporária na posição correta
            arr[j] = posiAtual;
        }

        // Atualiza o tamanho do intervalo para a próxima iteração
        gap /= 2;
    }
}

int main()
{

    int vetor[] = {12, 34, 54, 2, 3};

    //Calcula o valor do tamanho do vetor
    int n = sizeof(vetor) / sizeof(vetor[0]);

    // Executa o algoritmo de ordenação
    shellSort(vetor, n);

    // Imprime o resultado ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%i ", vetor[i]);

    return 0;
}
