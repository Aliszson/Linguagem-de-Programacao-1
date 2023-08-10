#include <stdio.h>
#include <windows.h>

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

        //  Percorre os elementos da lista a partir do intervalo gap
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

    LARGE_INTEGER start, end, freq;
    double elapsed;

    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    // Executa o código que deseja medir o tempo de execução
    // ...

    int vetor[] = {56, 77, 44, 21, 0, 13, -1, 432, 51, 12, 77, -99, 95, 302, 9, 1000, 1955, 1920, 2001, 1945, 1500};
    int n = sizeof(vetor) / sizeof(int); // Calcula o tamanho do vetor

    shellSort(vetor, n); // Executa o algoritmo de ordenação

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++)
        printf("%i ", vetor[i]);

    QueryPerformanceCounter(&end);
    elapsed = (end.QuadPart - start.QuadPart) / (double)freq.QuadPart;

    // Imprime o tempo decorrido em milissegundos
    printf("\nTempo de execucao: %.3f ms\n", elapsed * 1000);

    return 0;
}
