#include <stdio.h>

struct info {
        char name[4];
        int junk;
        int trail;
        char class[4];
        float mapper;
        char c;
}__attribute__((packed));

#define offset_of(element, obj) (int)&(((element *)0)->obj)

int main() {
        struct info _info;
        printf("%d\n", offset_of(struct info, c));
        return 0;
}
