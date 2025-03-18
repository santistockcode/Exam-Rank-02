#include <stdio.h>
#include <stdlib.h>
void ft_swap(int *a, int *b);

int main()
{
    int a = 10;
    int b = 20;
    int *pa = malloc(sizeof(int));
    int *pb = malloc(sizeof(int));

    *pa = 30;
    *pb = 40;
    printf("Before swap: a = %d, b = %d\n", a, b);
    ft_swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    printf("Before swap: *pa = %d, *pb = %d\n", *pa, *pb);
    ft_swap(pa, pb);
    printf("After swap: *pa = %d, *pb = %d\n", *pa, *pb);

    free(pa);
    free(pb);

    return 0;
}