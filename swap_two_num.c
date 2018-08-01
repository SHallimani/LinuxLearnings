#include <stdio.h>

void swap(int x, int y) {
        printf("Befor < x: %d y: %d >\n", x, y);
        x = (x + y);
        y = (x - y);
        x = (x - y);
        printf("After < x: %d y: %d >\n", x, y);
}

void swap1(int x, int y) {
        printf("%s() Befor < x: %d y: %d >\n", __func__, x, y);
        x = (x * y);
        y = (x / y);
        x = (x / y);
        printf("%s() After < x: %d y: %d >\n", __func__, x, y);
}

int main(int argc, char *argv[]) {
    swap(atoi(argv[1], argv[2]);
    swap1(atoi(argv[1], argv[2]);
    return 0;
}
