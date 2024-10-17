
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int index;
    int column;
    int row;
    int length;
    int scale;
    int pos;
    int position[1024];

    length = 100;
    scale = 100 / 32;
    column = atoi(argv[1]); 
    row = atoi(argv[2]);
    pos = atoi(argv[3]);
    index = (column + (row * 32)) % 1024;
    int i = 0;
    int d;
    int num = 0;
    while(i < length)
    {
        d = 0;
        while(d < scale)
        {
            position[i] = num % 32;
            i++;
            d++;
        }
        num++;
    }
    printf("row: %d, column: %d, index: %d\n", row, column, index);
    printf("position %d: %d", pos, position[pos]);
}