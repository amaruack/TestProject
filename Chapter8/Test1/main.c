#include <stdio.h>
#include <encrypt.h>
#include <checksum.h>

int main(){

    char s[] = "speak friend and enter";
    encrypt(s);
    printf("encrypt data '%s' \n", s);
    printf("checksum '%i'\n", checksum(s));
    encrypt(s);
    printf("decrypt data '%s'\n", s);
    printf("checksum '%i'\n", checksum(s));

    return 0;
}
