#include <stdio.h>
#include <conio.h>

int fast_power(int a, int b)
{
    if (0 == b) return 1;
    if (b % 2 == 1)
        return a * fast_power(a, b - 1);
    else
        return fast_power (a * a, b / 2);
}

int calc (int a, int b, char symbol) {
    int flag = 1;
    int c;
    switch (symbol) {
        case '+':
            c = a + b;
            break;
        case '-':
            c = a - b;
            break;
        case '/':
            c = a / b;
            break;
        case '*':
            c = a * b;
            break;
        case '^':
            c = fast_power (a, b);
            break;
        default:
            return 0;
    }
    return c;
}

void main (void) {
    int a, b, c;
    char symbol;
    while (a != 00 || b != 00) {
        printf ("enter a\n");
        scanf ("%d", &a);
        if (a == 0) {
            printf ("Goodbye!");
            break;
        }
        printf ("enter b\n");
        scanf ("%d", &b);
        if (b == 0) {
            printf ("Goodbye!");
            break;
        }
        printf ("enter symbol (+  -  *  / ^)\n");
        symbol = getch();
        c = calc (a, b, symbol);
        if (c == 0) {
            printf("Only the symbols +  -  *  / ^ are available in the program \n");
            continue;
        }
        printf ("%d \n",c);
    } 
}
