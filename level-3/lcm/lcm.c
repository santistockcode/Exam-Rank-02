unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int lcm; // mínimo común múltiplo

    if (a == 0 || b == 0)
        return (0);
    if (a > b)
        lcm = a;
    else
        lcm = b;

    while (1)
    {
        if (lcm & a == 0 && lcm & b == 0)
            return (lcm);
        lcm++;
    }
    return (0);
}