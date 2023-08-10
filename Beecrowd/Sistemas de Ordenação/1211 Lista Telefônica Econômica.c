#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char s1[250];
} String;

String strings[100050];

int comparar(String *, String *);

int main(int argc, char **argv)
{

    unsigned int t, i, j;
    while (scanf("%d", &t) != EOF)
    {

        i = 0;
        unsigned int aux = t;
        while (t--)
            scanf("%s", strings[i++].s1);

        unsigned int ans = 0;
        qsort(strings, i, sizeof(String), comparar);

        for (i = 1; i < aux; ++i)
        {
            for (j = 0; strings[i].s1[j]; ++j)
            {
                if (strings[i].s1[j] == strings[i - 1].s1[j])
                {
                    ++ans;
                }
                else
                {
                    break;
                }
            }
        }

        printf("%u\n", ans);
    }

    return 0;
}

int comparar(String *a, String *b)
{
    int aux = strcmp(a->s1, b->s1);

    if (aux == 0)
    {
        return 0;
    }
    else if (aux < 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
