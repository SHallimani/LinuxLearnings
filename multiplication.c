/*
 * Multiply two integers without using multiplication, division and bitwise operators, and no loops
 */
unsigned int multiply_num(int x, int y) {
        if(x == 0)
                return 0;
        else if(y > 0)
                return (x + multiply_num(x, (y - 1)));
}

/* Power of number reference example */
int my_pow(int x, int y) {
        int loop, opt;
        for(opt = 1, loop =0 ; loop < y; loop++)
                opt *= x;
        return opt;
}

/* the below function is example for multiplcation table works for 7 only */
#define MUL_WITH_SEVEN 3
#define MUL_WITH_THREE 2
int multiplyBySeven(unsigned int n)
{
    /* Note the inner bracket here. This is needed 
       because precedence of '-' operator is higher 
       than '<<' */
    return ((n << MUL_WITH_SEVEN) - n);
    return ((n << MUL_WITH_THREE) - n);
}


