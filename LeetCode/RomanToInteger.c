#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum numerosRomanos {
        I = 1,
        V = 5,
        X = 10,
        L = 50,
        C = 100,
        D = 500,
        M = 1000
    };

int conversaoUnaria( char c ) {
    switch ( c ) {
        case 'I':
            return I;
        case 'V':
            return V;
        case 'X':
            return X;
        case 'L':
            return L;
        case 'C':
            return C;
        case 'D':
            return D;
        case 'M':
            return M;
    }
    return 0;
}

int romanToInt(char* s) {
    int valConvertido = 0, len = strlen ( s );

    for ( int count = len - 1; count >= 0; count-- ) {
        if ( len - 1 == count ) {
        valConvertido += conversaoUnaria( s[count] );
        continue;
        }
        if ( conversaoUnaria( s[count] ) < conversaoUnaria ( s[count + 1] ) ) {
            valConvertido -= conversaoUnaria( s[count] );
            continue;
        } else {
            valConvertido += conversaoUnaria( s[count] );
        }
    }
    return valConvertido;
}

char *lerString() {
    char c = getchar();
    int tamanho = 5, i = 0;

    while ( c == '\n' ){
        c = getchar();
    }
    char *s = (char *) malloc ( sizeof ( char ) * tamanho );
    if ( s == NULL ) {
        return NULL;
    }
    s[i] = c;

    while ( (c = getchar ( ) ) != '\n'  ) {
        if ( i == tamanho - 2 ) {
            tamanho += 5;
            s = realloc ( s, sizeof ( char ) * tamanho );
            if ( s == NULL ) {
                return NULL;
            }
        }
        s[++i] = c;
    }
    s[++i] = '\0';
    return s;
}

int main() {
    printf ( "Digite o número romano a ser convertido: " );
    char *s = lerString();
    int romano = romanToInt ( s );

    printf ( "%d\n", romano );
}
