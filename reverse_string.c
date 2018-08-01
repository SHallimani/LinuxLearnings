void reverse_string(char *str, int len) {
        static int loop;

        if(loop < (len/2)) {
                char c;
                c = str[loop];
                str[loop++] = str[strlen(str) - loop];
                str[strlen(str) - loop] = c;
                reverse_string(str, len);
        }
}

int main() {
        char *str;
        str = (char *)malloc(strlen("helloworldhowareyou?"));
        strcpy(str, "helloworldhowareyou?");

        reverse_string(str, strlen(str));
        printf("\nstr: %s\n", str);
        free(str);

        return 0;
}
