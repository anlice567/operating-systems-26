#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char* argv[]) {
    //n is input from command line
    int n = atoi(argv[1]);

    for (int i = 0; i < n; i++) {
        fork();
        sleep(5);
    }
}
//For n=3 there will be 8 processes created (2^3 = 8), for n=5 there will be 32 processes created (2^5 = 32)
