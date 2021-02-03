#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char source[100];
    puts("input the string:");
    gets(source);
    int avg = 0;
    for (int i = 0; i < strlen(source); i++)
    {
        avg += source[i];
    }
    avg /= strlen(source);
    int a = avg / 10;
    int b = avg % 10;
    for (int i = 0; i < a; i++)
    {
        putchar('+');
    }
    printf("[>++++++++++<-]>");
    for (int i = 0; i < b; i++)
    {
        putchar('+');
    }
    for (int i = 0; i < strlen(source); i++)
    {
        int dis = source[i] - avg;
        int a1 = abs(dis) / 5;
        int b1 = abs(dis) % 5;
        char amp = '-';
        if (dis > 0)
        {
            amp = '+';
        }
        printf(">+++++[<");
        //十位(5)
        for (int j = 0; j < a1; j++)
        {
            putchar(amp);
        }
        printf(">-]<");
        for (int j = 0; j < b1; j++)
        {
            putchar(amp);
        }
        putchar('.');
        avg = source[i];
    }
    return 0;
}