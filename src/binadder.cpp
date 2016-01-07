/* Swaggy Binary Adder v0.2 by H3nt4iBoY
- CPP 1
*/

#include "binadder.h"

BinAdder::BinAdder(){ }

BinAdder::BinAdder(int bit_lenght)
{
    create(bit_lenght, howManyNums);
}

BinAdder::BinAdder(int bit_lenght, int how_many_arrays)
{
    create(bit_lenght, how_many_arrays);
}

BinAdder::~BinAdder()
{
    deleteOrCreateNums(1);
}

void BinAdder::create(int bit_lenght, int how_many_arrays)
{
    bitLenght = bit_lenght;
    deleteOrCreateNums(2);
}

int BinAdder::getBitLenght()
{
    return bitLenght;
}

bool* BinAdder::getBitArray(int no)
{
    if(no >= howManyNums || no<0) return bits[0];
    else return bits[no];
}

void BinAdder::deleteOrCreateNums(int mode, int which)
{
    if(which<0)
    {
        for(int i=0; i<howManyNums; i++)
        {
            printf("deleting number [%d]...\n", i);
            if(bits[i] && (mode==1 || mode==3)) delete [] (bits[i]);
            if(mode==2 || mode==3)
            {
                printf("Creating number [%d]...\n", i);
                bits[i] = new bool[bitLenght];
            }
        }
    }
    else if(which < howManyNums)
    {
        if(bits[which] && (mode==1 || mode==3)) delete [] (bits[which]);
        if(mode==2 || mode==3) bits[which] = new bool[bitLenght];
    }
}

int BinAdder::assignBinaryNumber(int no, const bool binum[], int lenght)
{
    if(no >= howManyNums || no<0) return -1;

    for(int i=0; i<bitLenght; i++)
    {
        if(i<lenght) bits[no][i] = binum[i];
        else bits[no][i] = 0;
    }

    reverseBitArray(no);

    return 0;
}

void BinAdder::reverseBitArrayFromGiven(bool **bar, int len)
{
    for(int i=0; i<len/2; i++)
    {
        bool tmp = *(*bar+i);
        *(*bar+i) = *(*bar+(len-i-1));
        *(*bar+(len-i-1)) = tmp;
    }
}

void BinAdder::reverseBitArray(int no)
{
    if(no >= howManyNums || no<0) return;

    reverseBitArrayFromGiven(&(bits[no]), bitLenght);
}

void BinAdder::showNumberBits(int no, int mode)
{
    if(no >= howManyNums || no<0) return;

    for(int i=0; i<bitLenght; i++)
    {
        if(mode==1) printf("%d ", bits[no][i]);
        else printf("%d ", bits[no][bitLenght-1 - i]);
    }
    printf("\n");
}

void BinAdder::showBitsFromGiven(bool bitto[], int lenght, int mode)
{
    for(int i=0; i<lenght; i++)
    {
        if(mode==1) printf("%d ", bitto[i]);
        else printf("%d ", bitto[lenght-1 - i]);
    }
}

bool BinAdder::addBits(bool b1, bool b2, bool &q)
{
    if(b1 && b2 && q)
    {
        q=1;
        return 1;
    }
    else if((b1 && b2 && !q) || (b1 && !b2 && q) || (!b1 && b2 && q))
    {
        q=1;
        return 0;
    }
    if((b1 && !b2 && !q) || (!b1 && b2 && !q) || (!b1 && !b2 && q))
    {
        q=0;
        return 1;
    }
    q=0;
    return 0;
}

void BinAdder::addNumbers(int no1, int no2, int resno)
{
    if(resno >= howManyNums || resno<0) return;

    bool* rezo = new bool[bitLenght];

    rezo = addNumbersReturn(no1, no2);

    for(int i=0; i<bitLenght; i++)
    {
        bits[resno][i] = rezo[i];
    }

    delete [] rezo;
}

bool* BinAdder::addNumbersReturn(int no1, int no2)
{
    //printf("\nAdding...\n");

    bool *rezo = new bool[bitLenght];

    if(no1 >= howManyNums || no1<0) return rezo;
    if(no2 >= howManyNums || no2<0) return rezo;

    for(int i=0; i<bitLenght; i++) rezo[i] = bits[no1][i];

    bool q=0;
    for(int k=no1+1; k <= no2; k++)
    {
        for(int i=0; i<bitLenght; i++)
        {
            rezo[i]=addBits(bits[k][i], rezo[i], q);
            //printf("rezo[%d]=%d\n", i, (int)rezo[i]);

            //if(i==bitLenght-1 && q) rezo[0]=1;
        }
    }

    //reverseBitArrayFromGiven(&rezo, bitLenght);

    return rezo;
}

void BinAdder::assignBitsFromUINT_8(uint8_t numb, int no)
{
    if(no >= howManyNums || no<0) return;
    if(bitLenght != 8) return;

    bool barr[bitLenght];
    assignBitsToArrayUINT_8(numb, barr, bitLenght);

    for(int i=0; i<bitLenght; i++) bits[no][i] = barr[i];
}

void BinAdder::assignBitsToArrayUINT_8(uint8_t numb, bool arr[], int arrLenght)
{
    bool *bitto = new bool[bitLenght];

    for(int i=0; i<bitLenght; i++)
    {
        bitto[i] = (numb & (1 << i)) ? 1 : 0;
    }
    //reverseBitArrayFromGiven(&bitto, bitLenght);

    for(int i=0; i<arrLenght; i++) arr[i] = bitto[i];

    delete [] bitto;
}

uint8_t BinAdder::returnBitsAsUINT8(int no)
{
    if(no >= howManyNums || no<0) return 0;

    if(bitLenght%8 != 0) return 0;

    uint8_t bytes[bitLenght/8];

    for(int i=0; i<bitLenght/8; i++) bytes[i]=0;

    printf("\nTrying to convert these bits to value:\n");
    showNumberBits(no);

    for(int i=0; i<bitLenght/8; i++)
    {
        printf("Byte no.%d before: ", i);
        bool barr[8];
        assignBitsToArrayUINT_8(bytes[i], barr, 8);
        showBitsFromGiven(barr,8);
        printf("\n");

        for(int j=0; j<8; j++)
        {
            bytes[i] = bytes[i] | (( (uint8_t)bits[no][i*8 + j]) << j );
        }

        printf("Byte no.%d after : ", i);
        assignBitsToArrayUINT_8(bytes[i], barr, 8);
        showBitsFromGiven(barr,8);
    }

    //return &((void)(bytes));

    return bytes[0];
}
