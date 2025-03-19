#include <unistd.h>
#include <stdio.h>

int is_space(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return (1);
    return (0);
}

void print_three()
{
    write (1, " ", 1);
    write (1, " ", 1);
    write (1, " ", 1);
}

void expand(char *str)
{
    unsigned int i;
    int flag;
    i = 0;
    
    while (str[i] && is_space(str[i]))
        i++;

    flag = 0;    
    while (str[i])
    {
        if (is_space(str[i]))
            flag = 1;

        if (!is_space(str[i]))
        {
            if (flag)
                write(1, "   ", 3);
            write (1, &(str[i]), 1);
            flag = 0;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2 || argv[1][0] == 0)
        write(1, "\n", 1);
    else
    {
        expand(argv[1]);
        write(1, "\n", 1);
    }return (0);
}