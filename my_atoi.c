#include <stdio.h>

unsigned int my_atoi(char *ascii) {
        unsigned int atoi_data = 0;
        while((*ascii >= '0') && (*ascii <= '9') && (ascii)) {
                atoi_data = ((atoi_data * 10) + (*ascii - '0'));
                ascii++;
        }
        return atoi_data;
}

int main(int argc, char *argv[]) {
        printf("%s -> %d\n", argv[1], my_atoi(argv[1]));
        return 0;
}
