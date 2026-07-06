#include <stdbool.h>

// toggle a bit at a given position
unsigned toggleBit(unsigned n, unsigned position)
{
    return n ^ (1 << position);
}

// set the bit at the given position to 1
// without modifying other bits
unsigned setBit(unsigned n, unsigned position)
{
    return n | (1 << position);
}

// clear bit at given position
// without modifying other bits
unsigned clearBit(unsigned n, unsigned position)
{
    return n & ~(1 << position);
}

// return true if bit is 1
// return flase otherwise
bool isBitSet(unsigned n, unsigned position)
{
    if(n & 1 << position)
    {
        return true;
    }
    else return false;
}

// set bits in n to 1 according to mask
unsigned setMultipleBits(unsigned n, unsigned mask)
{
    return n | mask;
}

// set bits in n to 0 according to mask
unsigned clearMultipleBits(unsigned n, unsigned mask)
{
    return n & ~mask;
}

// toggle bits in n according to mask
unsigned toggleMultipleBits(unsigned n, unsigned mask)
{
    return n ^ mask;
}


/* n --> 11011010
 mask  00001001
 ans   11010001

nand   11011010
       00001001
       11110111

xor    11011010
       00001001
       11010011

*/
