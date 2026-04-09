bool isPalindrome(int x) {
    if ( x < 0 ) {
        return false;
    }
    int invertida = 0, digito, temp = x;
    while ( temp > 0 ) {
        digito = temp % 10;
        if ( INT_MAX / 10 < invertida ) {
            return false;
        }
        if ( INT_MAX / 10 == invertida && digito > 7 ) {
            return false;
        }

        invertida *= 10;
        invertida += digito;
        temp /= 10;
    }
    if ( invertida == x ) {
        return true;
    } else {
        return false;
    }
}
