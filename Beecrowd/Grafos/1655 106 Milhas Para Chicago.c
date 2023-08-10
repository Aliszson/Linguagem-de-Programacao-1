#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAX 110

inline double maximo(double, double);

int main(int argc, char **argv)
{

    int n, m;
    int i, j, k;

    while (scanf("%d", &n), n)
    {

        scanf("%d", &m);

        double probabilidade[TAMANHO_MAX][TAMANHO_MAX] = {{0}};

        while (m--)
        {
            
            scanf("%d %d %d", &i, &j, &k);
            probabilidade[i][j] = probabilidade[j][i] = k * 0.01;

        }

        for (i = 1; i <= n; ++i)
            for (j = 1; j < n; ++j)
                for (k = 1; k <= n; ++k)
                    probabilidade[j][k] = maximo(probabilidade[j][k], probabilidade[j][i] * probabilidade[i][k]);

        printf("%.6F percent\n", probabilidade[1][n] * 100);

    }

    return 0;

}

double maximo(double a, double b)
{

    return a > b ? a : b;

}
