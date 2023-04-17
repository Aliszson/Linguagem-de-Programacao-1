#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    int habPais, casoTeste, aux, casos;

    while (scanf("%d%d", &habPais, &casoTeste) != EOF)
    {
        int notas[habPais];

        for (int i = 0; i < habPais; i++)
        {
            scanf("%d", &notas[i]);
        }

        for (int i = 0; i < habPais; i++)
        {
            for (int j = i + 1; j < habPais; j++)
            {
                if (notas[i] < notas[j])
                {
                    aux = notas[i];
                    notas[i] = notas[j];
                    notas[j] = aux;
                }
            }
        }

        for (int k = 0; k < casoTeste; k++)
        {
            scanf("%d", &casos);
            printf("%d\n", notas[casos - 1]);
        }
    }

    return 0;
}
