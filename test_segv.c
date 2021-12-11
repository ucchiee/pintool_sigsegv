#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void signal_handler(int signo, siginfo_t *info, void *ctx) {
    printf("catched sigsegv in app signal handler\n");  // not guaranteed to work correctly
    exit(-1);
}

int main(void) {
    int *ptr = NULL;
    struct sigaction act, oact;

    // register signal handler
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = signal_handler;
    act.sa_flags = SA_SIGINFO;
    if (sigaction(SIGSEGV, &act, &oact) < 0) {
        return 0;
    }

    printf("before SIGSEGV\n");
    printf("%d", ptr[0]);
    printf("after SIGSEGV\n");
    return 0;
}
