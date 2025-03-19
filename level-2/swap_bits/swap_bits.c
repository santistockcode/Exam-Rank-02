#include <unistd.h>
#include <limits.h>

// SOLUCIÓN
return ((octet << 4) | (octet >> 4))

// sucio prácticas
unsigned char	swap_bits(unsigned char octet){
    unsigned char no;
    int c;

    no = 0b1111;
    c = 7;
    while (c >= 0)
    {
        no &= (octet << c);
        c--;
    }
    return no;
}

int main(void)
{
    unsigned int c;

    c = 0b0001;

    swap_bits(c);
    return(1);
}


// SOME PREVIOUS QUESTIONS
// how many bytes has unsigned char? 1
// that means? 8 bits

// how many bytes has integer? 4
// that means? 32 bits

// OCHO ASIENTOS TAL QUE 7, 6, 5, 4, 3, 2, 1, 0
// >> mueve la peña a la derecha y rellena con 0
// << mueve la peña a la izquierda y rellena con 0

// THEORY: 
/*
7. Key Takeaways

    Byte = 8 seats: 4 seats on the left, 4 on the right.
    Shifting: “slide” bits left (<<) or right (>>).
    Swapping halves: (octet << 4) + (octet >> 4) → then OR them.
    Bitwise OR: combines the bits from both parts.
    Always watch out for data types (e.g., int vs. unsigned char).
*/

// TRUCOS: 
// p octet & (1 << 0)
// dado que 1 << 0 es 00000001 pues imprimie lo que haya en _ _ _ _ _ _ _ x de octet
// p octet & (1 << 3) imprime por tanto _ _ _ _ x _ _ _ (porque mueve 1 (00000001) tres sitios a la izquierda (00001000))
/*
(lldb) p/x octet
(lldb) p/x result
*/

// es decir, puedo imprimir bits, hex o decimal
/*
EJEMPLO: aquí 'no' es 00000000
(lldb) p (no | 0b00000100)
(int) $23 = 4
(lldb) p/x (no | 0b00000100)
(int) $24 = 0x00000004
(lldb) p/t (no | 0b00000100)
(int) $25 = 0b00000000000000000000000000000100
*/

// EXPLICACIÓN paso a paso

#include <unistd.h>
#include <stdio.h>  // For printf

unsigned char swap_bits(unsigned char octet)
{
    unsigned char left_nibble;
    unsigned char right_nibble;
    unsigned char result;

    // 1. MASK
    left_nibble = octet & 0xF0;   // top 4 bits
    right_nibble = octet & 0x0F; // bottom 4 bits

    // 2. SHIFT
    left_nibble = left_nibble >> 4;   // move to bottom
    right_nibble = right_nibble << 4; // move to top

    // 3. Combine
    result = left_nibble | right_nibble;
    return result;
}

int main(void)
{
    unsigned char c = 'a';  // 'a' is 0x61 -> binary 0110 0001
    unsigned char swapped = swap_bits(c);

    // Just to see the difference:
    // - 'a' (0x61) => swapped is 0x16 (0001 0110)
    // Let's print in hex:
    printf("Original char: %c (0x%02X)\n", c, c);
    printf("Swapped bits:  0x%02X\n", swapped);

    return 0;
}

