//Testz0r

#include <stdio.h>
#include "binadder.h"

int main()
{
    printf("Juz' testin', noob!\n\n");

    typedef int8_t current;
    typedef uint8_t ucurrent;

    BinAdder bad(sizeof(current)*8);

    current u1=127;

    printf("u1: %d (%d)\n  ", u1, (ucurrent)u1);
    bad.assignBitsFromType(u1, 1);
    bad.showNumberBits(1);

    //printf("\nMaking negative code:");
    printf("\n  ");
    bad.inverseBits(1);

    bad.showNumberBits(1);
    printf("+               1\n  ---------------\n  ");

    bad.assignBitsFromType((current)1, 2);
    bad.addNumbers(1,2,0);
    bad.showNumberBits(0);

    current u2=bad.returnBitsAsValue<current>(0);

    printf("\nu2: %d (%d)\n", u2, (ucurrent)u2);

    /*printf("\nu1: %d\nbits: ", u1);
    bad.assignBitsFromType(u1, 0);
    bad.showNumberBits(0);

    printf("\nu2: %d\nbits: ", u2);
    bad.assignBitsFromType(u2, 1);
    bad.showNumberBits(1);

    printf("\nu1+u2 = \nbits: ");

    bad.addNumbers(0,1,2);
    bad.showNumberBits(2);

    printf( "\n\nreturned: %d\n\n", bad.returnBitsAsValue(2, (char)0) );*/

    /*bool a[4]={1,1,1,1};
    bool b[4]={1,1,1,1};

    bad.assignBinaryNumber(0, a, 4);
    bad.assignBinaryNumber(1, b, 4);

    bad.showNumberBits(0);
    bad.showNumberBits(1);
    printf("\n");

    bad.addNumbers(0,1,2);
    bad.showNumberBits(2);*/

    return 0;
}
