#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nota;
    int posicao;
} Aluno;

int cmp(const void* a, const void* b) {
    Aluno* alunoA = (Aluno*)a;
    Aluno* alunoB = (Aluno*)b;

    if (alunoA->nota != alunoB->nota) {
        return alunoB->nota - alunoA->nota;
    } else {
        return alunoA->posicao - alunoB->posicao;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int numAlunos, nao_trocaram = 0;

        scanf("%d", &numAlunos);

        Aluno qtdAlunos[numAlunos];

        for (int i = 0; i < numAlunos; i++) {
            scanf("%d", &qtdAlunos[i].nota);
            qtdAlunos[i].posicao = i;
        }

        qsort(qtdAlunos, numAlunos, sizeof(Aluno), cmp);
        
        for (int i = 0; i < numAlunos; i++) {
            if (qtdAlunos[i].posicao == i) {
                nao_trocaram++;
            }
        }

        printf("%d\n", nao_trocaram);
    }

    return 0;
}
