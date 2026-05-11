#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MENU(p) ( * ( int* ) ( p ) )
#define TAM(p)  ( * ( int* ) ( ( char* ) ( p ) + sizeof ( int) ) )
#define QTD(p)  ( * ( int* ) ( ( char* ) ( p ) + sizeof ( int ) * 2 ) )

void addPessoa  ( void **pBuffer );
void listPessoas ( void **pBuffer );
void removerPessoa ( void **pBuffer );
void buscarPessoa ( void **pBuffer );

int main ( int argc, char const *argv[] )
{
    void *pBuffer = malloc( sizeof ( int ) * 3 );
    if ( pBuffer == NULL ) {
        printf ( "Impossível alocar a memória" );
        return 0;
    }

    MENU ( pBuffer ) = 0;
    TAM ( pBuffer )  = sizeof ( int ) * 3;
    QTD ( pBuffer )  = 0;

    do {
        printf( "1 - Adicionar Pessoa\n2 - Remover Pessoa\n3 - Buscar Pessoa\n4 - Listar Todos\n5 - Sair\n" );
        printf ( "Opção: " );
        scanf( "%d", ( int* ) pBuffer );

        switch ( MENU ( pBuffer ) ) {
            case 1:
                addPessoa( &pBuffer );
                break;
            case 2:
                removerPessoa( &pBuffer );
                break;
            case 3:
                buscarPessoa( &pBuffer );
                break;
            case 4:
                listPessoas( &pBuffer );
                break;
            case 5:
                break;
        }

    } while ( MENU ( pBuffer ) != 5 );

    free ( pBuffer );
    return 0;
}

void addPessoa( void **pBuffer ) {
    char *pNomeTemp  = malloc( sizeof(char) * 100 );
    if ( pNomeTemp == NULL ) {
        printf ( "Impossível alocar a memória" );
        return;
    }
    char *pEmailTemp = malloc( sizeof(char) * 100 );
    if ( pEmailTemp == NULL ) {
        printf ( "Impossível alocar a memória" );
        return;
    }

    printf( "\nNome: " );
    scanf( " %[^\n]", pNomeTemp );
    printf( "Email: " );
    scanf( " %[^\n]", pEmailTemp );

    *pBuffer = realloc( *pBuffer,
        TAM ( *pBuffer ) +
        sizeof ( int ) * 3 +
        strlen ( pNomeTemp )  + 1 +
        strlen ( pEmailTemp ) + 1
    );
    if ( pBuffer == NULL ) {
        printf ( "Impossível realocar a memória" );
        return;
    }

    char *ptr = ( char* ) ( *pBuffer ) + TAM( *pBuffer );

    printf( "Idade: " );
    scanf( "%d", ( int* )ptr );
    ptr += sizeof ( int );

    * ( int* ) ptr = strlen ( pNomeTemp ) + 1;
    ptr += sizeof ( int );

    memcpy( ptr, pNomeTemp, strlen ( pNomeTemp ) + 1 );
    ptr += strlen ( pNomeTemp ) + 1;

    * ( int* ) ptr = strlen ( pEmailTemp ) + 1;
    ptr += sizeof ( int );

    memcpy( ptr, pEmailTemp, strlen ( pEmailTemp ) + 1 );
    ptr += strlen ( pEmailTemp ) + 1;

    QTD ( *pBuffer ) += 1;
    TAM ( *pBuffer )  = ptr - ( char* ) ( *pBuffer );

    free ( pNomeTemp );
    free ( pEmailTemp );
}

void listPessoas( void **pBuffer ) {
    char *ptr = ( char* ) ( *pBuffer ) + sizeof ( int ) * 3;

    while ( ptr < ( char* ) ( *pBuffer ) + TAM ( *pBuffer ) ) {

        printf ( "\n--- Pessoa ---" );

        printf ( "\nIdade: %d", * ( int* ) ptr );
        ptr += sizeof ( int );

        printf ( "\nNome:  %s", ptr + sizeof ( int ) );
        ptr += sizeof ( int ) + * ( int* ) ptr;

        printf ( "\nEmail: %s", ptr + sizeof ( int ) );
        ptr += sizeof ( int ) + * ( int* ) ptr;

        printf ( "\n" );
    }
}

void removerPessoa( void **pBuffer ) {
    char *pEmailTemp = malloc( sizeof ( char ) * 100 );
    if ( pEmailTemp == NULL ) {
        printf ( "Impossível alocar a memória" );
        return;
    }

    printf("\nEmail para remover: ");
    scanf(" %[^\n]", pEmailTemp);

    char *ptr     = ( char* ) ( *pBuffer ) + sizeof ( int ) * 3;
    char *pEnd    = ( char* ) ( *pBuffer ) + TAM ( *pBuffer );

    while ( ptr < pEnd ) {
        char *pRegistro = ptr;

        ptr += sizeof ( int );

        ptr += sizeof ( int );
        ptr += * ( int* ) ( ptr - sizeof ( int ) );

        ptr += sizeof ( int );
        char *pEmail = ptr;
        ptr += * ( int* ) ( ptr - sizeof ( int ) );

        if ( strcmp ( pEmail, pEmailTemp ) == 0 ) {
            memmove ( pRegistro, ptr, pEnd - ptr );
            TAM ( *pBuffer ) -= ptr - pRegistro;
            QTD ( *pBuffer ) -= 1;
            *pBuffer = realloc( *pBuffer, TAM ( *pBuffer ) );
            free( pEmailTemp );
            printf ( "\nPessoa removida com sucesso.\n" );
            return;
        }
    }

    printf ( "\nEmail não encontrado.\n" );
    free ( pEmailTemp );
}

void buscarPessoa( void **pBuffer ) {
    char *pEmailTemp = malloc( sizeof ( char ) * 100 );
    if ( pEmailTemp == NULL ) {
        printf ( "Impossível alocar a memória" );
        return;
    }

    printf( "\nEmail para buscar: " );
    scanf ( " %[^\n]", pEmailTemp );

    char *ptr  = ( char* ) ( *pBuffer ) + sizeof ( int ) * 3;
    char *pEnd = ( char* ) ( *pBuffer ) + TAM ( *pBuffer );

    while ( ptr < pEnd ) {
        char *pIdade = ptr;
        ptr += sizeof ( int );

        char *pNome = ptr + sizeof ( int );
        ptr += sizeof ( int ) + * ( int* ) ptr;

        char *pEmail = ptr + sizeof ( int );
        ptr += sizeof ( int ) + * ( int* ) ptr;

        if ( strcmp ( pEmail, pEmailTemp ) == 0 ) {
            printf ( "\n%s\n%d\n%s\n", pNome, * ( int* ) pIdade, pEmail );
            free ( pEmailTemp );
            return;
        }
    }

    printf ( "\nEmail não encontrado.\n" );
    free ( pEmailTemp );
}