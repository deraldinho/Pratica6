#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

// Manter como especificado
struct time *alocaVetor(int n)
{

    struct time *vetor = (struct time *)malloc(n * sizeof(struct time));
    if (vetor == NULL)
    {
        printf("MEMORIA INSUFICIENTE\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        vetor[i].pontuacao = 0;
        vetor[i].saldodepontos = 0.0;
        vetor[i].pontosfeito = 0;
        vetor[i].pontoscontra = 0;
    }
    return vetor;
}

// Manter como especificado
void desalocaVetor(struct time **vetor)
{
    free(*vetor);
}
void MERGE(struct time *v, int l, int m, int r)
{
    int size_l = (m - l + 1);
    int size_r = (r - m);
    
    struct time *vet_l = (struct time *)malloc(size_l * sizeof(struct time));
    struct time *vet_r = (struct time *)malloc(size_r * sizeof(struct time));
    for (int i = 0; i < size_l; i++)
    {
        vet_l[i] = v[i + l];
    }
    for (int j = 0; j < size_r; j++)
    {
        vet_r[j] = v[m + j + 1];
    }
    int i = 0, j = 0;
    for (int k = l; k <= r; k++)
    {
        if (i == size_l)
        {
            v[k] = vet_r[j++];
        }
        else if (j == size_r)
        {
            v[k] = vet_l[i++];
        }
        
        else if (compare(vet_l[i], vet_r[j]))
        {
            v[k] = vet_l[i++];
        }
        else
        {
            v[k] = vet_r[j++];
        }
    }
    desalocaVetor(&vet_l);
    desalocaVetor(&vet_r);
}

// implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(struct time *vetor, int l, int n)
{

    if (l < n) // n = r so para fins didaticos
    {
        int m = (l + n) / 2;
        ordenacao(vetor, l, m);
        ordenacao(vetor, m + 1, n);
        MERGE(vetor, l, m, n);
    }
}

// compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const struct time t1, const struct time t2)
{
    if (t1.pontuacao > t2.pontuacao)
    {
        return 1;
    }
    else if (t1.pontuacao < t2.pontuacao)
    {
        return 0;
    }
    else
    {
        if (t1.saldodepontos > t2.saldodepontos)
        {
            return 1;
        }
        else if (t1.saldodepontos < t2.saldodepontos)
        {
            return 0;
        }
        else
        {
            if (t1.pontosfeito > t2.pontosfeito)
            {
                return 1;
            }
            else if (t1.pontosfeito < t2.pontosfeito)
            {
                return 0;
            }
            else
            {
                if (t1.x < t2.x)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
}
