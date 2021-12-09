#include <stdio.h>

int main(void){
    int *ptr = NULL;
    printf("before SIGSEGV\n");
    printf("%d", ptr[0]);
    printf("after SIGSEGV\n");
    return 0;
}
