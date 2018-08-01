#include <stdio.h>

int reverse_num(int num) {
        int rnum = 0;
        while(num) {
                rnum = (rnum * 10) + (num%10);
                num = num/10;
        }
        return rnum;
}

int getsize(int num) {
        int rnum = 0;
        while(num) {
                num = num/10;
                ++rnum;
        }
        return rnum;
}

char *my_itoa(int num) {
        int loop;
        char ascii[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char *buf;

        loop = getsize(num);
        printf("len: %d\n", loop);
        buf = malloc(loop);
        while(num) {
                buf[--loop] = ascii[num%10];
                printf("%d -> %d - %c\n", loop, (num%10), ascii[num%10]);
                num = num/10;
        }
        return buf;
}

char *int_to_ascii(int num, int base) {
        static char buf[16];

        char *ptr;

        ptr = &buf[sizeof(buf) - 1];

        do {
                *--ptr="0123456789"[num%base];
                num /= base;
        }while(num);

        return ptr;
}

int main() {
        int num = 1567098760;
        printf("%d - %s\n", num, my_itoa(num));
        printf("%s\n", int_to_ascii(12345, 10));
        return 0;
}
