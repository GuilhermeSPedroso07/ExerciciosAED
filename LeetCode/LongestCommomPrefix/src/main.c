#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if ( strsSize == 0 ) {
        return "";
    }
    int size = strlen ( strs[0] );
    char *prefix = ( char * ) malloc ( sizeof ( char ) * (size + 1 ));
    strcpy ( prefix, strs[0] );
    for ( int i = 1; i < strsSize; i++ ) {
        for ( int j = size; j >= 0; j-- ) {
            if ( strncmp ( prefix, strs[i], j ) == 0 ) {
                prefix[j] = '\0';
                size = j;
                break;
            } else if ( j == 1 ) {
                return "";
            }
        }
    }
    return prefix;
}

int main(int argc, char const *argv[])
{
    char *strs[3];
    char string1[7];
    char string2[5];
    char string3[7];
    strcpy ( string1, "flower" );
    strcpy ( string2, "flow" );
    strcpy ( string3, "flight" );
    strs[0] = string1;
    strs[1] = string2;
    strs[2] = string3;

    char *prefix = longestCommonPrefix(strs, 3 );
    printf ( "%s", prefix);
    free ( prefix );
    return 0;
}
