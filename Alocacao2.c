#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    printf ( "Digite a quantidade de números a ser lida: " );
    scanf ( "%d", &num );

    int *inteiros = ( int * ) malloc ( sizeof ( int ) * num );
    for ( int count = 0; count < num; count++ ) {
        printf ( "Digite o número a ser armazenado: " );
        scanf ("%d", &inteiros[count]);
    }
    for ( int count = 0; count < num; count++ ) {
        printf( "%d\n", inteiros[count] );
    }
    free(inteiros);
}