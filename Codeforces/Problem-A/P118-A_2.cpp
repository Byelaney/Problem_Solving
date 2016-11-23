#include <cstdio>
char d[] = "aoyeui";
int flag;
int main() {
    while(1) {
        char ch = getchar();
        if(ch == '\n')
            break;
        if(ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';
        for(int i = 0; i < 6; ++i)
            if(ch == d[i])
                flag = 1;
        if(!flag)
            printf(".%c", ch);
        flag = 0;
    }
    printf("\n");
}
