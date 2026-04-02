#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int contarDigitos ( int x ) {
    /*
===============================================================================
contarDigitos 

    Essa função conta a quantidade de dígitos de uma int qualquer, considerando
    o símbolo de negativo, e devolve para transformar em uma string, adicionando
    1 para o '\0'
===============================================================================
*/

    int count = 1;
    unsigned int intTemp = x;

    if ( x < 0 ) {
        count = count + 1;
    }

    if ( x == 0 ) {
        return 1;
    }

    while ( intTemp > 0 ) {
        count = count +1;
        intTemp = intTemp / 10;
    }

    return count;
}

bool isPalindrome ( int x ) {
    /*
===============================================================================
isPalindrome

    Essa função recebe uma int e verifica se o número recebido é um palíndromo
===============================================================================
*/
    int numCar = contarDigitos ( x );
    char charTemp;
    char *numerosChar = ( char * ) malloc( sizeof( char ) * numCar );
    snprintf ( numerosChar, numCar, "%d", x );

    char *numerosInv = ( char * ) malloc ( sizeof ( char ) * numCar );
    strcpy ( numerosInv, numerosChar );
    int count1 = 0, count2 = strlen(numerosInv) - 1;

    while ( count1 < count2 ) {
        charTemp = numerosInv[count1];
        numerosInv[count1++] = numerosInv[count2];
        numerosInv[count2--] = charTemp;
    }

    if ( strcmp ( numerosInv, numerosChar ) == 0 ) {
        return true;
    } else {
        return false;
    }
}

int main () {
    int x;

    printf ( "Digite um número inteiro: " );
    scanf ( "%d", &x );

    if ( isPalindrome ( x ) ) {
        printf ( "O número %d é um palíndromo.\n", x );
    } else {
        printf ( "O número %d não é um palíndromo.\n", x );
    }

    return 0;
}
