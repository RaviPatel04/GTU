/* Print reverse of given number*/

#include <stdio.h>

int main()
{
    int n, rev = 0;
    printf("Enter a number you print reverse:");
    scanf("%d", &n);

    while (n != 0)
    {
        rev = (rev * 10) + (n % 10);
        n = n / 10;
    }
    printf("reverse of entered number : %d", rev);
}