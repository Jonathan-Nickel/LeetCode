//Jonathan Nickel - 23200579

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize);
void numberOfLetters (char* licenseplate, int *freq);
int possibleWord (int *frequencePlate, const char *word ); 

int main(int argc, char const *argv[])
{
    shortestCompletingWord("1s3 PSt", (char*[]){"step","steps","licenseplateipe","stepple"}, 4);

    return 0;
}

/*
================================================================================
shortestCompletingWord
 declara um vetor de 26 tamanhos para armazenar quantas vezes deve ter cada letra;
 chama uma segunda função para que armazena a quantidade de letras nesse vetor;
 realiza o teste para ver se a palavra é possivel, chamando uma terceira função,
 se a palavra for possível verifica se é a menor entre as possíveis;
 returna a menor palavra possível.
================================================================================
*/
char* shortestCompletingWord( char* licensePlate, char** words, int wordsSize ) {
    int frequencePlate[ 26 ] = { 0 };
    numberOfLetters( licensePlate, frequencePlate );

    char *result = NULL;

    for ( int i = 0; i < wordsSize; i++ ) {
        if ( possibleWord( frequencePlate, words [ i ] ) ) {
            if ( result == NULL || strlen ( words [ i ] ) < strlen ( result ) ) {
                result = words [ i ] ;
            }
        }
    }
    
    return result;
}

/*
================================================================================
possibleWord
 declara um vetor que irá verificar a quantidade de cada letra na palavra;
 chama a função que armazena no vetor essa quantidade de letras;
 compara cada letra da palavra senha e da palavra a ser comparada para verificar
 se é uma palavra possível;
 se a palavra possui todas as letras necessárias na senha ela retorna que é possível.
================================================================================
*/
int possibleWord ( int *frequencePlate, const char *word ) {
    int frequenceWord [ 26 ] = { 0 };
    numberOfLetters ( word, frequenceWord ) ;

    for ( int i = 0; i < 26; i++ ) {
        if ( frequencePlate [ i ]  > frequenceWord [ i ] ) {
            return 0;
        }
    }
    return 1;

}
  /*
  hint
  Count only the letters (possibly converted to lowercase) of each word. 
  If a word is shorter and the count of each letter is at least the count of that letter in the licensePlate, 
  it is the best answer we've seen yet.
  */

/*
================================================================================
numberOfLetters
 repete para todos os caracters dos elementos desejados na palavra;
 seleciona apenas aqueles caracters que são letras;
 converte a letra para minúsculo para poder comparar apenas a quantidade;
 armazena no vetor responsável por guardar a frequência que se repete a letra.
================================================================================
*/
void numberOfLetters ( char* licenseplate, int *frequence ) {
    for ( int i = 0; licenseplate[i]; i++ ) {
        if ( isalpha( licenseplate [ i ] ) ) {
            char lowerChar = tolower ( licenseplate [ i ] );
            frequence [ lowerChar - 'a' ]++;
        }
    }
}