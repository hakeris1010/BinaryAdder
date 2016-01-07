#include <stdio.h>
#include "binadder.h"

int main()
{
    printf("Juz' testin', noob!\n");

    BinAdder bad(8);

    char u1=150;
    char u2=-50;

    printf("\nu1: %d\nbits: ", u1);
    bad.assignBitsFromType(u1, 0);
    bad.showNumberBits(0);

    printf("\nu2: %d\nbits: ", u2);
    bad.assignBitsFromType(u2, 1);
    bad.showNumberBits(1);

    printf("\nu1+u2 = \nbits: ");

    bad.addNumbers(0,1,2);
    bad.showNumberBits(2);

    printf( "\n\nreturned: %d\n\n", bad.returnBitsAsValue(2, (char)0) );

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
