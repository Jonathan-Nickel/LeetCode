#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximumGain(char* s, int x, int y);

int main() {
    char input[] = "cdbcbbaaabab";
    int x = 4;
    int y = 5;

    int resultado = maximumGain( input, x, y );

    printf( "Pontuacao maxima: %d\n", resultado );

    return 0;
}

int maximumGain(char* s, int x, int y) {

    int sizeS = strlen ( s );

    char first;
    char second;
    int high;
    int low;

    if ( x < y ) {
        first = 'b';
        second = 'a';
        high = y;
        low = x;
    } else {
        first = 'a';
        second = 'b';
        high = x;
        low = y;
    }

    char *stack = malloc ( sizeS );
    int top = 0;
    int score = 0;
    for ( int i = 0; i < sizeS; i++ ) {
        char letter = s [ i ];
        if ( top > 0 && stack [ top - 1 ]  == first && letter == second ) {
            top--;
            score = score + high;
        } else {
            stack [ top ] = letter;
            top = top + 1;
        }
    }

    char *stack2 = malloc ( top );
    int top2 = 0;
    for ( int i = 0; i < top; i++ ) {
        char letter = stack [ i ];
        if ( top2 > 0 && stack2 [ top2 - 1 ] == second && letter == first ) {
            top2--;
            score = score + low;
        } else {
            stack2 [ top2 ] = letter;
            top2 = top2 + 1;
        }
    }
    free ( stack );
    free ( stack2 );
    return score;
}