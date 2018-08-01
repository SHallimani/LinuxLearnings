#include <stdio.h>

void display_bits(unsigned int data) {
        static int loop = (sizeof(data) * 8);

        if(--loop >= 0) {
                printf("%d ", ((data >> loop) & 1));
                display_bits(data);
        }
        loop = (sizeof(data) * 8);
}

struct __data {
        unsigned int b1:1;
        unsigned int b2:1;
};

//swap each bit
void swap_bits(unsigned int data) {
        unsigned int loop = (sizeof(data) * 8);
        unsigned int intr = 0;

        struct __data *DATA;

        for(loop = 0; loop < (sizeof(data) * 4); loop++) {
                DATA = (struct __data *)&data;
                intr |= ((((DATA->b2 << 1) | (DATA->b1 << 2)) >> 1) << (loop * 2));
                data = (data >> 2);
        }
        display_bits(intr);
}

int main() {
        display_bits(0x12345678);
        printf("\n");
        swap_bits(0x12345678);
        printf("\n");
        return 0;
}
