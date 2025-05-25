/*Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/
/*Jonathan Nickel - 23200579*/

#include <stdio.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes);


int main(int argc, char const *argv[]){
  int numRows,*returnSize, **retunColumnSizes;
  scanf("%d",&numRows);
  generate (numRows, &returnSize, &retunColumnSizes);
  return 0;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
  int triangle [30][30];
  int cont = 0;
  int count2 = 0;
  int collumsizes;
  for (int i = 0; i<numRows;i++){
    for (int j=0;j<=i;j++) {
      if (j==0){
        triangle[i][j]=1;
      } else if (j==cont){
        triangle[i][j]=1;
      } else {
        triangle[i][j] = (triangle [i-1][j-1]) + (triangle[i-1][j]);
      }
    count2++;
    }
  cont++;
  }
  *returnSize = count2;


  /*int **result = (int **) malloc(sizeof(int) * count2);
  int resulttamanho = 0;
  for (int i = 0; i<numRows;i++){
    for (int j=0;j<=i;j++) {
      result[resulttamanho] = triangle[i][j];
      resulttamanho++; 
    }
  }
    return result;*/


//arrumar o retorno das informações por malloc

 for (int i = 0; i<numRows;i++){
    for (int j=0;j<=i;j++) {
      printf ("%d ", triangle[i][j]);
    }
    printf("\n");
    }


}