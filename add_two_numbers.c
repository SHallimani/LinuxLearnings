int addnum(int x, int y) {
        return ((x&y) + (x^y));
}

int add_num(int x, int y) {
        /*
         * Identical to the previous case, but the number to be used is given as parameter right before the value.
         * For example printf("%*d", 5, 10) prints number 10 left-padded up to five digits.
         */
        return printf("%*c%*c", x, ' ', y, ' ');
}

int ADD_NUM(int x, int y) {
  // Iterate till there is no carry  
    while (y != 0) {
        // carry now contains common 
        //set bits of x and y
        int carry = x & y;
        printf("carry: %d\n", carry);

        // Sum of bits of x and y where at 
        //least one of the bits is not set
        x = x ^ y;
        printf("x: %d\n", x);

        // Carry is shifted by one so that adding
        // it to x gives the required sum
        y = carry << 1;
        printf("y: %d\n", y);
    }
    return x;
}
