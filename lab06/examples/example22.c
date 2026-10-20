#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
static void alarm_handler(int sig) {
    if (sig == SIGALRM) {
        printf("This process has pid %d", getpid());
    }
    exit(sig);
}
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        printf("Mistake");
    }
    else if (pid == 0) {
        //This causes SIGALRM, it indicates the expiration of the timer, in our case 3 seconds
        signal(SIGALRM,alarm_handler);
        alarm(3);
        while (1) {
            printf("Hello world!");
        }
    }
    else {
        //We also need to wait for child process, otherwise it becomes the orphan process and we won't see handler's message
        waitpid(pid,NULL,0);
    }
}
