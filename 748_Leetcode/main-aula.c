/*
748
Given a licenseplateing licensePlate and an array of licenseplateings words, find the shortest completing word in words.
A completing word is a word that contains all the letters in licensePlate. 
Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. 
If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.

For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. 
Possible completing words are "abccdef", "caaacab", and "cbca".
Return the shortest completing word in words. It is guaranteed an answer exists. 
If there are multiple shortest completing words, return the first one that occurs in words.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize);
void numberOfLetters (char* licenseplate, int *frequence);
int possibleWord (int *frequencePlate, const char *word ); 

int main(int argc, char const *argv[])
{
    shortestCompletingWord("1s3 PSt", (char*[]){"step","steps","licenseplateipe","stepple"}, 4);

    return 0;
}

/*
*/
char* shortestCompletingWord( char* licensePlate, char** words, int wordsSize ) {
    int frequencePlate[ 26 ] = { 0 };
    numberOfLetters( licensePlate, frequencePlate );

    char *result = NULL;

    for ( int i = 0; i < wordsSize; i++ ) {
        if ( possibleWord(frequencePlate, words[i] ) ) {
            if ( result == NULL || strlen ( words [ i ] ) < strlen ( result ) ) {
                result = words [ i ] ;
            }
        }
    }
    
    return result;
}

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

void numberOfLetters ( char* licenseplate, int *frequence ) {
    for ( int i = 0; licenseplate[i]; i++ ) {
        if ( isalpha( licenseplate [ i ] ) ) {
            char lowerChar = tolower ( licenseplate [ i ] );
            frequence [ lowerChar - 'a' ]++;
        }
    }
}