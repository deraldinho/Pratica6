#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int instancia = 1;
    // enquanto houver dados
    while (1)
    {
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        struct time *vetor;

        // leia o numero de times
        scanf("%d", &n);


        // se for zero, o programa acaba
        if (n == 0)
        {
            return 0;
        }

        // aloque o vetor
        vetor = alocaVetor(n);
        fflush(NULL);
        // calcula o numero de partidas
        npartidas = (n * (n - 1)) / 2;

        // para cada partida...
        for (i = 0; i < npartidas; ++i) {
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);
            vetor[time1 - 1].pontosfeito += pontos1;
            vetor[time1 - 1].pontoscontra += pontos2;
            vetor[time2 - 1].pontosfeito += pontos2;
            vetor[time2 - 1].pontoscontra += pontos1;

            if (pontos1 > pontos2) {
                vetor[time1 - 1].pontuacao += 2;
                vetor[time2 - 1].pontuacao += 1;
            } else {
                vetor[time1 - 1].pontuacao += 1;
                vetor[time2 - 1].pontuacao += 2;
            }
            fflush(NULL);
            // preencher o vetor de estruturas de acordo com os dados lidos
        }
        // inicializando algumas variaveis como x e saldo de cestas
        for (int j = 0; j < n; j++)
        {
            vetor[j].x = j + 1;
            if (vetor[j].pontoscontra != 0)
            {
                vetor[j].saldodepontos = (vetor[j].pontosfeito / vetor[j].pontoscontra);
            }
            else
            {
                vetor[j].saldodepontos = vetor[j].pontosfeito;
            }
        }
        // ordenar os times
        ordenacao(vetor, 0, n);

        // imprima o resultado

        printf("\nInstancia %d", instancia++);

        for (int j = 0; j < n; j++)
        {
           printf("%d ", vetor[j].x);
        }
        printf("\n");

        // desaloque o vetor
        desalocaVetor(&vetor);
    }

    return 0;
}
