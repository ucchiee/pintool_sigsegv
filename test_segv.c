#include <stdio.h>

int main(void){
    int *ptr = NULL;
    printf("%d", ptr[0]);
    printf("after SIGSEGV\n");
    return 0;
}
