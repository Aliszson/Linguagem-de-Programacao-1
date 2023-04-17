#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    int numAlunos, qtdCasos, aux, cont = 0;

    scanf("%d", &qtdCasos);

    for (int k = 0; k < qtdCasos; k++)
    {

        scanf("%d", &numAlunos);
        int alunos[numAlunos];

        for (int i = 0; i < numAlunos; i++)
        {
            scanf("%d", &alunos[i]);
        }

        cont = 0;
        for (int i = 0; i < numAlunos; i++)
        {
            for (int j = i + 1; j < numAlunos; j++)
            {
                if (alunos[i] > alunos[j])
                {
                    aux = alunos[i];
                    alunos[i] = alunos[j];
                    alunos[j] = aux;
                    cont++;
                }
            }
        }
        
        printf("%d \n", numAlunos - cont);
    }

    return 0;
}
