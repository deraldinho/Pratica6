#ifndef ordenacao_h
#define ordenacao_h

struct time
{
    int pontuacao, x;
    double saldodepontos, pontosfeito, pontoscontra;
    // preencher com os dados de cada time
};

// Manter como especificado
void ordenacao(struct time *vetor, int l, int n);
// Manter como especificado
struct time *alocaVetor(int n);
// Manter como especificado
void desalocaVetor(struct time **vetor);
// faz a comparacao utilizada para ordenar os times
int compare(struct time t1, struct time t2);
#endif
