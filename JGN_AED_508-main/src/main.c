//Jonathan Nickel - 23200579
/*
Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.
The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).
*/

#include <stdio.h>
#include <stdlib.h>

#define NumberNodes 10000 //The number of nodes in the tree is in the range [1, 10^4].

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* newNode( int val ) {
    TreeNode* node = ( TreeNode* ) malloc ( sizeof ( TreeNode ) );
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int subtreeSum( struct TreeNode* root, int* somas, int* freqs, int* counter );
int* findFrequentTreeSum( struct TreeNode* root, int* returnSize );

int main()
{
    int returnSize; 
        TreeNode* root = newNode( 5 );
        root->left = newNode( 2 );
        root->right = newNode( -3 ); 

    int* result = findFrequentTreeSum( root, &returnSize );

    printf( "Somas mais frequentes: " );
    for ( int i = 0; i < returnSize; i++ ) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free( root->left );
    free( root->right );
    free( root );
    free( result );

    printf("Pressione Enter para sair...");
    getchar();
    return 0;
}

/*
=============================================================================
findFrequentTreeSum
 Chama uma função pra calcular as somas.
 Verifica no vetor de guardou as frequencias qual o valor que mais se repete.
 Verifica quantos valores repetem esse numero de vezes.
 Aloca dinamicamente um vetor com a quantidade de valores.
 Armazena no vetor quais são esses valores que mais repetem.
 Retorna esse vetor dinamico.
=============================================================================
*/
int* findFrequentTreeSum( struct TreeNode* root, int* returnSize ) {
    if ( !root ) {
        *returnSize = 0;
        return NULL;
    }
    int MoreFreq = 0, resultCount = 0, ResultX = 0;
    int somas[NumberNodes], freqs[NumberNodes], counter = 0;

    subtreeSum( root, somas, freqs, &counter );

    for ( int i = 0; i < counter; i++ ) {
        if ( freqs[i] > MoreFreq ) {
            MoreFreq = freqs[i];
        }
    }
    for ( int i = 0; i < counter; i++ ) {
        if ( freqs[i] == MoreFreq ) {
            resultCount++;
        }
    }
    int* result = (int*)malloc(resultCount * sizeof(int));
    for (int i = 0; i < counter; i++) {
        if (freqs[i] == MoreFreq) {
            result[ResultX++] = somas[i];
        }
    }
    *returnSize = resultCount;
    return result;
}
/*
====================================================================================================
subtreeSum
 calcula o valor da soma de forma recursiva somando todos valores a esquerda e a direita da arvore.
 Ve se esse valor encontrado já ta entre os valores encontrados se sim, soma o contador referente a esse valor.
 aso não adiciona mais um ao numero de valores encontrados, e define a quantidade desse valor novo em 1.
====================================================================================================
*/
int subtreeSum( struct TreeNode* root, int* somas, int* freqs, int* counter ) {
    if ( !root ) {
        return 0;
    }
    int sum;
    sum = root->val + subtreeSum( root->left, somas, freqs, counter ) + subtreeSum( root->right, somas, freqs, counter );

    for ( int i = 0; i < *counter; i++ ) {
        if ( somas[i] == sum ) {
            freqs[i]++;
            return sum;
        }
    }
    somas[*counter] = sum;
    freqs[*counter] = 1;
    ( *counter )++;
    return sum;
}