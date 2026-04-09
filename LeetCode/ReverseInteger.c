int reverse(int x){
    int resultado = 0, digito = 0;
    while ( x > 0  || x < 0) {
        digito = x % 10;
        if ( resultado > INT_MAX / 10 || resultado < INT_MIN / 10 ) return 0;
        if ( resultado == INT_MAX / 10 && digito > 7 ) {
            return 0;
        }
        if ( resultado == INT_MIN / 10 && digito < -8 ) {
            return 0;
        }
        resultado *= 10;
        resultado += digito;
        x /= 10;
    }

    return resultado;
}
