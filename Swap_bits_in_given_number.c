#include <stdio.h>

void execcc(unsigned int val, unsigned int p1, unsigned int p2, unsigned int n) {
        unsigned int p1mask = (((1 << n) - 1) << p1);
        unsigned int p2mask = (((1 << n) - 1) << p2);
        unsigned int p1set, p2set;

        printf("mas1: %X mas2: %X\n", p1mask, p2mask);
        p1set = (val & p1mask);
        p2set = (val & p2mask);
        printf("p1set: %X p2set: %X\n", p1set, p2set);

        val = (~p1mask & val);
        printf("val: %x\n", val);
        val = (~p2mask & val);
        printf("val: %x\n", val);

        p1set = (p1set << (p2 - p1));
        p2set = (p2set >> (p2 - p1));
        printf("val: %x p1set: %X p2set: %X\n", val, p1set, p2set);
        val = (val | p1set | p2set);
        printf("val: %x\n", val);
}

int main() {
        execcc(0xF0, 1, 5, 3);
        return 0;
}
