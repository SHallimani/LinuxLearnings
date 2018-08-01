#include <stdlib.h>
#include <string.h>

char *buff = "9+8+7+6-5-4-3-2-1";

int parseandadd(const char *buf) {
        int loop = 0, result;
        const char *tmp = buf;

        //result = atoi(tmp);
        //tmp += 1;

        for(loop = 0; loop < strlen(buf); loop++) {
                switch(*tmp) {
                        case '+':
                                tmp += 1;
                                result += atoi(tmp++);
                                break;
                        case '-':
                                tmp += 1;
                                result -= atoi(tmp++);
                                break;
                        default:
                                if((atoi(tmp) >= 0) && (atoi(tmp) < ))
                                        result = atoi(tmp);
                                tmp += 1;
                                break;
                }
        }
        return result;
}

int parseandadd_rcv(const char *buf, int len) {
        static int result = 0;
        if(len) {
                switch(*buf) {
                        case '+':
                                --len;
                                result += atoi(++buf);
                                --len;
                                break;
                        case '-':
                                --len;
                                result -= atoi(++buf);
                                --len;
                                break;
                        default:
                                result = atoi(buf);
                                --len;
                                break;
                }
                parseandadd_rcv(++buf, len);
        }
        return result;
}

int main() {
        printf("%s == %d\n", buff, parseandadd((const char *)buff));
        printf("%s == %d\n", buff, parseandadd_rcv((const char *)buff, strlen(buff)));
        return 0;
}
