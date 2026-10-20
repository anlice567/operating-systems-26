#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
static void signal1_handler(int sig) {
    if (sig == SIGUSR1) {
    printf("You entered negative number, please enter positive number");
    }
}
static void signal2_handler(int sig) {
    if (sig == SIGUSR2) {
    printf("You entered not a number, please enter positive number");
    }
}
int is_number(char n[]) {
    for (int i = 0; i < strlen(n); i++) {
        if (isdigit(n[i])) {
            continue;
        }
        else {
            return 0;
        }
    }
    return 1;
}
int main() {
    char n[256];
    scanf("%s",n);
    if (atoi(n) < 0) {
        signal(SIGUSR1,signal1_handler);
        raise(SIGUSR1);
    }
    else if (is_number(n) == 0) {
        signal(SIGUSR2,signal2_handler);
        raise(SIGUSR2);
    }
    else {
        printf("Everything is correct");
    }
}
