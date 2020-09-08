#include "BinaryString.h"

void BinaryString::callBinary()
{
    A[0] = '0';
    A[1] = '0';
    A[2] = '0';
    A[3] = '0';
    Binary(4);
}

void BinaryString::Binary(int n)
{
    if (n < 1)
     {
        std::cout<<A;
        std::cout<< std::endl;
     }
    else
    {
        A[n-1] = '0';
        Binary(n-1);
        A[n-1] = '1';
        Binary(n-1);
    }
    
}