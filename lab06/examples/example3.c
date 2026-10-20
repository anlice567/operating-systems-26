#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void signal1_handler(int sig) {
    printf("%s","Interrupted!");
    exit(sig);
}

void signal2_handler(int sig) {
    exit(sig);
}

int main() {
    //default handler of SIGINT just stops the process, my signal1_handler prints the message and stops the process after it.
    signal(SIGINT,signal1_handler);
    signal(SIGKILL,signal2_handler);
    while (1) {
        printf("Hello world!");
    }
    return 0;
}
