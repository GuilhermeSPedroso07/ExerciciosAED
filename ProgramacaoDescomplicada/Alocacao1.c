#include <stdio.h>
#include <stdlib.h>

int main(){
    int *inteiros = ( int * ) malloc ( sizeof ( int ) * 5 );
    for ( int count = 0; count < 5; count++ ) {
        printf ( "Digite o número a ser armazenado: " );
        scanf ("%d", &inteiros[count]);
    }
    for ( int count = 0; count < 5; count++ ) {
        printf( "%d\n", inteiros[count] );
    }
    free(inteiros);
}