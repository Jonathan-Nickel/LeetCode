//Jonathan Goulart Nickel - 23200579

#include <stdio.h>
#include <stdlib.h>

int numOfWays(int* nums, int numsSize);
void buildCombinations();
int countWays(int* nums, int numsSize);

#define MOD 1000000007
#define MAX 1001


int combinations[MAX][MAX];

int main()
{
    numOfWays();

    return 0;
}

/*
========================================================
buildCombinations
 Preeche a tabela utilizando a formula do triângulo de pascal.
========================================================
*/
void buildCombinations()
{
    for ( int i = 0; i < MAX; i++) {
        combinations [ i ] [ 0 ] = combinations [ i ] [ i ] = 1; 
        for ( int j = 1; j < i; j++) {
            combinations [ i ] [ j ] = ( combinations [ i - 1 ] [ j - 1 ] + combinations [ i - 1 ] [ j ] ) % MOD;
        }
    }
}

/*
================================================================================
countWays
 Verifica se o vetor possui mais de 2 elementos.
 monta as subarvores esquerda e direita,
 conta as formas de organizar cada subárvore.
 diz de quantas maneiras é possível organizar os elementos da esquerda e direita,
 multiplica um valor pelo outro.
 libera a memória alocada para as subárvores.
 retorna o total de maneiras de organizar os números.
================================================================================
*/
int countWays(int* nums, int numsSize)
{
    if ( numsSize <= 2 ) {
        return 1;
    }

    int* left = malloc ( numsSize * sizeof ( int ) );
    int* right = malloc ( numsSize * sizeof ( int ) );
    int leftSize = 0, rightSize = 0;

    for ( int i = 1; i < numsSize; i++) {
        if ( nums [ i ] < nums[0] ) {
            left [ leftSize++ ] = nums [ i ];
        } else {
            right [ rightSize++ ] = nums [ i ];
        }
    }
    int leftWays = countWays ( left, leftSize );
    int rightWays = countWays ( right, rightSize );

    free ( left );
    free ( right );

    int totalWays = ( int ) ( ( 1LL * combinations [ leftSize + rightSize ] [ leftSize ] * leftWays ) % MOD );
    totalWays = ( int ) ( ( 1LL * totalWays * rightWays ) %  MOD );

    return totalWays;
}

/*
================================================================================
numOfWays
 Chama a função que manda construir a tabela de combinações e depois 
 chama a função que conta as maneiras de organizar os números.
 pega o resultado e subtrai 1 (para não contar o vetor original) e retorna o resultado.
================================================================================
*/
int numOfWays(int* nums, int numsSize)
{
    buildCombinations();
    int result = countWays ( nums, numsSize );
    return ( result - 1 + MOD ) % MOD;
}