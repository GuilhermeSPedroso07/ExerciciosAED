#include <stdio.h>
#include <stdlib.h>

//Guilherme Schivittez Pedroso

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    int count = 0, l = 0, r = n - 1, u = 0, d = n - 1;
    int **mat = ( int ** ) malloc ( sizeof ( int * ) * n );
    *returnSize = n;
    *returnColumnSizes = ( int * ) malloc ( sizeof ( int ) * n );
    for ( count = 0; count < n; count++ ) {
        (*returnColumnSizes)[count] = n;
    }
    for ( count = 0; count < n; count++ ) {
        mat[count] = ( int * ) malloc ( sizeof ( int ) * n );
    }
    count = 1;

    while ( l <= r && u <= d ) {
        for ( int temp = l; temp <= r; temp++ ) {
            mat[u][temp] = count++;
        }
        u++;
        for ( int temp = u; temp <= d; temp++ ) {
            mat[temp][r] = count++;
        }
        r--;
        for ( int temp = r; temp >= l ; temp-- ) {
            mat[d][temp] = count++;
        }
        d--;
        for ( int temp = d; temp >= u ; temp-- ) {
            mat[temp][l] = count++;
        }
        l++;
    }
    return mat;
}

int main(int argc, char const *argv[])
{
    int n = 3, returnSize, *returnColumnSizes;
    int **result = generateMatrix(n, &returnSize, &returnColumnSizes);
    for ( int count = 0; count < returnSize; count++) {
        for ( int i = 0; i < returnColumnSizes[count]; i++ ) {
            printf ( "%d ", result[count][i] );
        }
        printf( "\n" );
    }

    for ( int count = 0; count < n; count++ ) {
        free ( result[count] );
    }
    free ( result );
    free ( returnColumnSizes );
}
