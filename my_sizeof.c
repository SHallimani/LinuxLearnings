#include <stdio.h>

#define my_seizeof(data_type)   (((char *)&data_type) - ((char *)(&data_type)0))
#define my_sizeof(data_type)    (((char *)(&data_type + 1)) - ((char *)(&data_type)))
#define SIZEOF(object)            (char *)(&object+1) - (char *)(&object)

int main() {
        int x;
        int a[10];
        printf("sizeof: %d\n", my_seizeof(x));
        printf("sizeof: %d\n", my_sizeof(x));
        printf("sizeof: %d\n", my_sizeof(a));
        printf("sizeof: %d\n", SIZEOF(x));
        printf("sizeof: %d\n", SIZEOF(a));
        printf("sizeof: %d\n", SIZEOF(int));
        return 0;
}
