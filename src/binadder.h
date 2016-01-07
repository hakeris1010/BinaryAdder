/* Swaggy Binary Adder v0.2 by H3nt4iBoY

- Converts any type to binary array
- Converts binary arrays to types
- Can perform binary addition with bit arrays
- Bit arrays can be assigned to class and exported from it.

* TODOS:
- Customizeable arrays count.
*/

#ifndef BINADDER_H_INCLUDED
#define BINADDER_H_INCLUDED

#include <stdint.h>
#include <stdio.h>

class BinAdder
{
private:
    int bitLenght=0;
    int howManyNums=3; //Default

    bool* bits[ 3 ];

public:
    BinAdder();
    BinAdder(int bit_lenght);
    BinAdder(int bit_lenght, int how_many_arrays);
    ~BinAdder();

    void create(int bit_lenght, int how_many_arrays);
    int assignBinaryNumber(int no, const bool binum[], int lenght);
    void reverseBitArray(int no);
    void reverseBitArrayFromGiven(bool **bar, int len);
    void deleteOrCreateNums(int mode, int which= -1);
    bool* getBitArray(int no);
    int getBitLenght();
    void showNumberBits(int no, int mode=0);
    void addNumbers(int no1, int no2, int resno);
    bool* addNumbersReturn(int no1, int no2);
    bool addBits(bool b1, bool b2, bool &q);
    void showBitsFromGiven(bool bits[], int lenght, int mode=0);

    void assignBitsFromUINT_8(uint8_t numb, int no); //Legacy trons
    void assignBitsToArrayUINT_8(uint8_t numb, bool arr[], int arrLenght);
    uint8_t returnBitsAsUINT8(int no);

    template <typename T>
    void assignBitsFromType(T numb, int no);

    template <typename T>
    void assignBitsToArrayFromType(T numb, bool arr[], int arrLenght);

    template <typename T>
    T returnBitsAsValue(int no, T ta);
};

//Implementation section

template <typename T>
void BinAdder::assignBitsFromType(T numb, int no)
{
    if(no >= howManyNums || no<0) return;

    bool barr[bitLenght];
    assignBitsToArrayFromType(numb, barr, bitLenght);

    for(int i=0; i<bitLenght; i++) bits[no][i] = barr[i];
}

template <typename T>
void BinAdder::assignBitsToArrayFromType(T numb, bool arr[], int arrLenghtInBits)
{
    //if(sizeof(T) != arrLenghtInBits);

    bool *bitto = new bool[arrLenghtInBits];

    for(int i=0; i<arrLenghtInBits; i++)
    {
        bitto[i] = (numb & (1 << i)) ? 1 : 0;
    }
    //reverseBitArrayFromGiven(&bitto, bitLenght);

    for(int i=0; i<arrLenghtInBits; i++) arr[i] = bitto[i];

    delete [] bitto;
}

template <typename T>
T BinAdder::returnBitsAsValue(int no, T ta)
{
    if(no >= howManyNums || no<0) return (T)0;
    if(bitLenght%8 != 0) return (T)1;
    if(sizeof(T) != bitLenght/8) return (T)2;

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

    T retval = (T)0;

    for(int i=0; i<bitLenght/8; i++)
    {
        retval = retval | (((T)bytes[i]) << i*8);
    }

    return retval;
}


#endif // BINADDER_H_INCLUDED
