#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados
{
    char nome[20];
    float altura;
    int dia;
    int mes;
    int ano;
    int idade

} Dados;

Dados humano[14];
int main()
{
    FILE *in, *out;
    float maior = 0;
    int posi, qntd = 0;
    char dia[8], mes[8], ano[8];
    char barra[1];
    int maisVelho = 0, maisNovo = 0, auxNovo = 0, posiVelho = 0, posiNovo = 0;
    int diaNasc = 0, mesNasc = 0, anoNasc = 0, idade, diasTotais;
    char titu1[20], titu2[20];

    in = fopen("dadinhos.txt", "r");
    if (in == NULL)
    {
        printf("Arquivo não encontrado\n");
        return 0;
    }

    fscanf(in, "%s %s", titu1, titu2);
    while (!feof(in))
    {
        fscanf(in, "%s %s %c %s %c %s", humano[qntd].nome, dia, &barra[0], mes, &barra[1], ano);

        humano[qntd].dia = atoi(dia);
        humano[qntd].mes = atoi(mes);
        humano[qntd].ano = atoi(ano);

        humano[qntd].idade = 2023 - humano[qntd].ano;

        if (humano[qntd].idade > maisVelho) // veirifcar idade do mais velho
        {
            maisVelho = 2023 - humano[qntd].ano;
            posiVelho = qntd;
            maisNovo = maisVelho;
        }
        if (humano[qntd].idade < maisNovo)
        {
            maisNovo = humano[qntd].idade;
            posiNovo = qntd;
        }

        qntd++;
    }
    fclose(in);

    out = fopen("saida.txt", "w");

    for (int i = 0; i < qntd; i++)
    {
        fprintf(out, "%s %i / %i / %i - %i anos  \n", humano[i].nome, humano[i].dia, humano[i].mes, humano[i].ano, 2023 - humano[i].ano);
    }

    fprintf(out, "Pessoa mais velha: %s %d: \n", humano[posiVelho].nome, maisVelho);
    fprintf(out, "Pessoa mais nova: %s %d: \n", humano[posiNovo].nome, maisNovo);

    fclose(out);
    return 0;
}

// if (humano[qntd].ano % 4 == 0)
//         {
//             for (int i = anoNasc; i < humano[qntd].ano; i++)
//             {
//                 idade += 366;
//             }
//         }
//         else
//         {
//             for (int i = anoNasc; i < humano[qntd].ano; i++)
//             {
//                 idade += 365;
//             }
//         }

//         if (humano[qntd].mes == 1 || humano[qntd].mes == 3 || humano[qntd].mes == 5 || humano[qntd].mes == 7 ||
//             humano[qntd].mes == 8 || humano[qntd].mes == 10 || humano[qntd].mes == 12)
//         {
//             mesNasc = 31;
//         }
//         else if (humano[qntd].mes == 4 || humano[qntd].mes == 6 || humano[qntd].mes == 9 || humano[qntd].mes == 11)
//         {
//             mesNasc = 30;
//         }
//         else if (humano[qntd].mes == 2)
//         {
//             if (humano[qntd].ano % 4 == 0)
//             {
//                 mesNasc = 28;
//             }
//             else
//             {
//                 mesNasc = 29;
//             }
//         }