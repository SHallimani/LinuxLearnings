#include <stdio.h>

unsigned int create_mask(int sp, int ep) {
        unsigned int mask = 0;
        do {
                mask |= (1 << sp);
        }while(sp++ != ep);
        return mask;
}

void swap(unsigned int val, unsigned int new, int sp, int ep) {
        unsigned int mask = create_mask(sp, ep);
        printf("mask: %x\n", mask);
        new = (new & mask);
        printf("new: %x\n", new);
        val = (~mask & val);
        printf("val: %x\n", val);
        val = (val | new);
        printf("val: %x\n", val);
}

int main() {
        swap(0xFFFF00FF, 0x00004500, 4, 23);
        return 0;
}
