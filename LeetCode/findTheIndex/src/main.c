#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int index = -1, needleSize = strlen ( needle );

    for ( int i = 0; haystack[i] != '\0'; i++ ) {
        if ( haystack[i] == needle[0] ) {
            if ( strncmp ( &haystack[i], needle, needleSize ) == 0 ) {
                index = i;
                break;
            }
        }
    }
    return index;
}

int main(int argc, char const *argv[])
{
    char * haystack = ( char * ) malloc ( sizeof ( char ) * 10 );
    char * needle = ( char * ) malloc ( sizeof ( char ) * 4 );
    strcpy ( haystack, "sadbutsad" );
    strcpy ( needle, "sad" );

    printf ( "%d", strStr ( haystack, needle ) );

    return 0;
}
