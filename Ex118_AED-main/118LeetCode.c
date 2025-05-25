/*Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

/*Jonathan Nickel - 23200579*/

#include <stdio.h>
#include <stdlib.h>

int** Generate ( int numRows, int* returnSize, int** returnColumnSizes );

int main( int argc, char const *argv[] ){
  int numRows, *returnSize, **retunColumnSizes;
  scanf( "%d", &numRows );
  Generate ( numRows, &returnSize, &retunColumnSizes );
  return 0;
}

/*
===========================================================================================================================================
Generate
 Monta o triângulo de pascal e retorna por malloc a matriz e o tamanho das colunas, e também retorna o número de colunas por um ponteiro. 
===========================================================================================================================================
*/


 int** Generate (int numRows, int* returnSize, int** returnColumnSizes) {
	
  int** triangle = ( int** ) malloc ( numRows * sizeof ( int* ) );
  *returnColumnSizes = ( int* )malloc( numRows * sizeof ( int ) );
    
  int cont = 0;
  for ( int i = 0 ; i < numRows ; i++ ){
    triangle[i] = ( int* ) malloc ( ( i + 1 ) * sizeof ( int ) );
    ( *returnColumnSizes ) [ i ] = i + 1;    
    for ( int j = 0 ; j <= i ; j++ ) {
      if ( j == 0 ){
        triangle [ i ] [ j ] = 1;
      } else if ( j == cont ) {
        triangle [ i ] [ j ] = 1;
      } else {
        triangle [ i ] [ j ] = ( triangle [ i - 1 ] [ j - 1 ] ) + ( triangle [ i - 1 ] [ j ]);
      }
    }
    cont++;
  }
  *returnSize = numRows;
  return triangle;
}