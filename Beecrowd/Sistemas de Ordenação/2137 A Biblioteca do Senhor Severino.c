#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    int numLivros = 0, aux = 0;

    while (scanf("%d", &numLivros) != EOF)
    {

        int codLivro[numLivros];

        if (numLivros >= 1 && numLivros <= 1000) // corrigido: usar o operador lógico "&&" em vez de "||"
        {
            for (int i = 0; i < numLivros; i++)
            {
                scanf("%d", &codLivro[i]); // corrigido: ler os valores do teclado usando "scanf"
            }

            for (int i = 0; i < numLivros; i++) // corrigido: trocar "4" por "TAM" para usar a constante definida acima
            {
                for (int j = i + 1; j < numLivros; j++) // corrigido: trocar "4" por "TAM" e corrigir o limite do segundo loop
                {
                    if (codLivro[i] > codLivro[j])
                    {
                        aux = codLivro[i];
                        codLivro[i] = codLivro[j];
                        codLivro[j] = aux;
                    }
                }
            }
        }

        for (int k = 0; k < numLivros; k++)
        {
            printf("%04d\n", codLivro[k]);
        }
    }

    return 0;
}