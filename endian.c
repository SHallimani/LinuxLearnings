#include <stdio.h>

typedef enum {
        little_endian,
        big_endian,
}end_type;

char *identify_endian() {
        int i = 0x1A2B3C4D;

        if((*(char *)&i) == 0x0D)
                return "little";
        else
                return "big";
}

typedef union {
        unsigned int word;
        unsigned char by[4];
}end;

unsigned int exchange_byte(unsigned int word) {
        end *eword = &word;
        printf("%s() %x. < %x %x %x %x >\n", __func__, eword->word, eword->by[0], eword->by[1], eword->by[2], eword->by[3]);
        eword->by[0] = (((eword->by[0] & 0x0F) << 4) | ((eword->by[0] & 0xF0) >> 4));
        eword->by[1] = (((eword->by[1] & 0x0F) << 4) | ((eword->by[1] & 0xF0) >> 4));
        eword->by[2] = (((eword->by[2] & 0x0F) << 4) | ((eword->by[2] & 0xF0) >> 4));
        eword->by[3] = (((eword->by[3] & 0x0F) << 4) | ((eword->by[3] & 0xF0) >> 4));
        printf("%s() %x. < %x %x %x %x >\n", __func__, eword->word, eword->by[0], eword->by[1], eword->by[2], eword->by[3]);
}

unsigned int convert_endian(unsigned int ed, end_type t) {
        char *ptr;
        ptr = (char *)&ed;
        char tmp;

        end *eword;
        eword = (end *)&ed;

        if(t == little_endian) {
                printf("%x. < %x %x %x %x >\n", eword->word, eword->by[0], eword->by[1], eword->by[2], eword->by[3]);
                printf("converting led to bed\n");
                tmp = *(ptr + 0);
                *(ptr + 0) = *(ptr + 3);
                *(ptr + 3) = tmp;

                tmp = *(ptr + 1);
                *(ptr + 1) = *(ptr + 2);
                *(ptr + 2) = tmp;
                printf("%x. < %x %x %x %x >\n", eword->word, eword->by[0], eword->by[1], eword->by[2], eword->by[3]);
        }
        else {
                printf("%x. < %x %x %x %x >\n", eword->word, eword->by[0], eword->by[1], eword->by[2], eword->by[3]);
                printf("converting bed to led\n");
                unsigned int tmp;
                tmp = ((eword->by[0] << 24) | (eword->by[1] << 16) | (eword->by[2] << 8) | (eword->by[3]));
                eword = (end *)&tmp;
                printf("%x. < %x %x %x %x >\n", eword->word, eword->by[0], eword->by[1], eword->by[2], eword->by[3]);
        }
}

int ed_main() {
        convert_endian(0x0A0B0C0D, little_endian);
        convert_endian(0x0A0B0C0D, big_endian);
        return printf("%s endianess\n", identify_endian());
}
