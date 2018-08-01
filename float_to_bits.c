#include <stdio.h>

/*
31         30                 23 22                        0
------------------------------------------------------------
| sign bit |  Exponential value |       Mantissa Value     |
------------------------------------------------------------

In order to store a float value in computer memory, a specified algorithm is followed.
Take an example at float value- 3948.125
Covert 3948 to binary. i.e. 111101101100
Convert .125 to binary,
                -----------------------------
                0.125 x 2 = 0.25        0
                0.25 x 2 = 0.5          0
                0.5 x 2 = 1             1
                -----------------------------
                                        = 0.001
                -----------------------------
Now 3948.125 = 111101101100.001
Normalize the number so that the decimal point will be placed after MSB-1. i.e.
111101101100.001 = 1.11101101100001 x 2^11
Now, for this number s=0, as the number is positive.
Exponent' = 11 and
Mantissa = 11101101100001
Bias for single precision used is 127 so,
Final exponent = exponent + 127 i.e.
E= 11 + 127= 138 = 10001010 in binary.

Now the above value will be represented in Physical memory as below displayed

 sign     Expo: 11+127  Man: 11101101100001 * 2^11
-----------------------------------------------------
|   0   |   10001010   |  1110110110000100000000000 |
-----------------------------------------------------
*/

struct __float_rp {
        unsigned int mantissa:23;
        unsigned int exponent:8;
        unsigned int sign_bit:1;
}__attribute__((packed));

union {
        struct __float_rp ieee;
        float data;
}fnum;

void display_bits(struct __float_rp *frp) {
        int loop = 0;
        printf("%d", frp->sign_bit);
        for(loop = 7; loop >= 0; loop--)
                printf("%d", ((frp->exponent >> loop) & 1));
        for(loop = 22; loop >= 0; loop--)
                printf("%d", ((frp->mantissa >> loop) & 1));
}

int main() {
        struct __float_rp *frp;
        struct __float_rp gf;
        struct __dummy dm;
        struct __dummy *DM;
        
        float fp = -3948.125;
        frp = (struct __float_rp *)&fp;
        fnum.data = 3948.125;

        printf("sign    : %d\n", frp->sign_bit);
        printf("exponent: %d\n", frp->exponent);
        printf("mantissa: %d\n", frp->mantissa);
        printf("< sign    : %d\n", fnum.ieee.sign_bit);
        printf("< exponent: %d\n", fnum.ieee.exponent);
        printf("< mantissa: %d\n", fnum.ieee.mantissa);

        display_bits(frp);
        printf("\n");
        //printf("offset: %d\n", my_offsetof(gf, exponent));
        return 0;
}
