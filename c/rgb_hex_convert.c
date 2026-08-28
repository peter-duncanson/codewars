#include <stdio.h>
#include <string.h>

/*
255, 255, 255 --> "FFFFFF"
255, 255, 300 --> "FFFFFF"
0, 0, 0       --> "000000"
148, 0, 211   --> "9400D3"
*/

void rgb(int r, int g, int b, char hex[6 + 1])
{   
    if (r > 255) r = 255;
    else if (r < 0) r = 0;
    if (g > 255) g = 255;
    else if (g < 0) g = 0;
    if (b > 255) b = 255;
    else if (b < 0) b = 0;
    size_t size = 7;
    snprintf(hex, size, "%02X%02X%02X", r, g, b);
}

int main(void)
{
    char test[7];
    rgb(255, 255, 255, test);
}
