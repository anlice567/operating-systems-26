#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define PATH_LENGTH 200
int main(int argc, char* argv[]) {
    char* call = argv[1];
    if (strcmp(call,"pwd") == 0) {
        char cwd[PATH_LENGTH];
        if (getcwd(cwd,sizeof(cwd)) != NULL) {
    	    printf("%s\n",cwd);
        }
    }
    return 0;
}
