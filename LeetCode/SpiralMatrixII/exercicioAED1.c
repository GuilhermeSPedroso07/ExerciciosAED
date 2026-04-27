#include <stdio.h>
#include <stdlib.h>

//Guilherme Schivittez Pedroso
//25101669

int** generateMatrix(int n) {
    int x = 0, y = 0;
    int direita = 1, esquerda = 0, cima = 0, baixo = 0;
    int **mat = ( int ** ) malloc ( sizeof ( int * ) * n );
    for ( int count = 0; count < n; count++ ) {
        mat[count] = ( int * ) malloc ( sizeof ( int ) *n );
    }

    for ( int count = 0; count < ( n * n); count++ ) {
        if ( direita == 1 ) {
            if ( x == n - 1 || x < n -1 && mat[x+1][y] != 0 ) {
                direita = 0;
                baixo = 1;
            } else {
                mat[x][y] = count + 1;
                x++;
            }
        }

        if ( baixo == 1 ) {
            if ( y == n - 1 || y < n -1 && mat[x][y+1] != 0 ) {
                baixo = 0;
                esquerda = 1;
            } else {
                mat[x][y] = count + 1;
                y++;
            }
        }

        if ( esquerda == 1 ) {
            if ( x == 0 || x > 0  && mat[x-1][y] != 0 ) {
                esquerda = 0;
                cima = 1;
            } else {
                mat[x][y] = count + 1;
                x--;
            }
        }

        if ( cima == 1 ) {
            if ( y == 1 || y > 1  && mat[x][y-1] != 0 ) {
                cima = 0;
                direita = 1;
            } else {
                mat[x][y] = count + 1;
                y--;
            }
        }
    }


    return mat;
}

int main() {
    int n = 3;
    int returnSize = 0;
    int returnColumnSizes[3];

    int **matriz = generateMatrix(n);

    printf( "%d", matriz[0][0]);
}