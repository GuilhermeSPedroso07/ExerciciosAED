#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = 4;
    int target = 9;

    int returnSize = 0;

    int *resultado = twoSum(nums, numsSize, target, &returnSize);

    if (resultado != NULL && returnSize == 2) {
        printf("Índices encontrados: %d e %d\n", resultado[0], resultado[1]);
    } else {
        printf("Nenhuma solução encontrada\n");
    }

    free(resultado);

    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *arrayOut = ( int * ) malloc ( sizeof ( int ) * 2 );
    if ( arrayOut == NULL ) {
        printf ( "Não foi possível alocar memória\n" );
        return NULL;
    }

    for ( int countTarget = 0; countTarget < numsSize; countTarget++ ) {
        for ( int countSource = 0; countSource < numsSize; countSource++ ) {
            if ( countSource == countTarget ) {
                continue;
            } else {
                if ( nums[countSource] + nums[countTarget] == target ) {
                    arrayOut[0] = countSource;
                    arrayOut[1] = countTarget;
                    *returnSize = 2;
                    return arrayOut;
                }
            }
        }       
    }
}