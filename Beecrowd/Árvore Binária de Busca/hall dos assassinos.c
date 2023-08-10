#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tipoDado{

	char nome[20];
	unsigned qtsMortes;

} Assassinos;

struct ArvHall{

	Assassinos info;
	struct ArvHall *esq;
	struct ArvHall *dir;

};

struct ArvMortos{

	char morto[20];
	struct ArvMortos *esq;
	struct ArvMortos *dir;

};

typedef struct ArvHall Hall;
typedef struct ArvMortos Mortos;

Hall* ins_Assassinos(Hall *hall, Assassinos assassino)
{

	if (!hall)
	{

		hall = (Hall *) malloc(sizeof(Hall));
		hall->info = assassino;
		hall->info.qtsMortes++;
		hall->esq = hall->dir = NULL;

	}
	else if (strcmp(hall->info.nome, assassino.nome) > 0)
		hall->esq = ins_Assassinos(hall->esq, assassino);
	else if (strcmp(hall->info.nome, assassino.nome) < 0)
		hall->dir = ins_Assassinos(hall->dir, assassino);
	else
		hall->info.qtsMortes++;

	return hall;

}

Mortos* ins_Mortos(Mortos *mortos, char *morto)
{

	if (!mortos)
	{

		mortos = (Mortos *) malloc(sizeof(Mortos));
		strcpy(mortos->morto, morto);
		mortos->esq = mortos->dir = NULL;

	}
	else if (strcmp(mortos->morto, morto) > 0)
		mortos->esq = ins_Mortos(mortos->esq, morto);
	else
		mortos->dir = ins_Mortos(mortos->dir, morto);

	return mortos;

}

bool busca_Assassino(Mortos *mortos, char *chave)
{

	bool direita, esquerda;

	if (!mortos)
		return false;

	if (strcmp(mortos->morto, chave) == 0)
		return true;

	if (strcmp(mortos->morto, chave) > 0)
		esquerda = busca_Assassino(mortos->esq, chave);
	else
		direita = busca_Assassino(mortos->dir, chave);

}
void impr_Assassino(Hall *hall, Mortos *mortos)
{

	if (hall != NULL)
	{

		impr_Assassino(hall->esq, mortos);
		if (!busca_Assassino(mortos, hall->info.nome))
			printf("%s %u\n", hall->info.nome, hall->info.qtsMortes);
		impr_Assassino(hall->dir, mortos);

	}

}


void main ()
{

	char matou[20], morreu[20];
	Hall *hall = NULL;
	Mortos *mortos = NULL;

	while (scanf(" %s %s", matou, morreu) != EOF)
	{

		Assassinos assassino = { 0 };
		strcpy(assassino.nome, matou);
		hall = ins_Assassinos(hall, assassino);
		mortos = ins_Mortos(mortos, morreu);

	}

	printf("HALL OF MURDERERS\n");
	impr_Assassino(hall, mortos);

}