/*
ISBN-10 identifiers are ten digits long.
The first nine characters are digits 0-9.
The last digit can be 0-9 or X, to indicate a value of 10.

An ISBN-10 number is valid if the sum of the digits multiplied 
by their position modulo 11 equals zero.

1112223339   -->  true
111222333    -->  false
1112223339X  -->  false
1234554321   -->  true
1234512345   -->  false
048665088X   -->  true
X123456788   -->  false

*/

#include <stdbool.h>
#include <string.h>

bool is_valid_ISBN_10(const char *ISBN)
{
    if (strlen(ISBN) != 10) return false;
    
    int sum = 0, digit = 0, i = 0;

    for (const char *p = ISBN; p < ISBN + 10; p++)
    {
        if (*p == 'X' && i == 9) digit = 10;
        else digit = *p - 48;
      
        if (digit < 0 || digit > 10) return false;

        sum += (++i * digit);
    }
    
    if ((sum % 11) == 0) return true;
    return false;
}

int main(void)
{

    return 0;
}

