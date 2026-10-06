#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#define PATH_LENGTH 200
char cwd[PATH_LENGTH];
int main(int argc, char* argv[]) {
    char* call = argv[1];
    //implementation of command pwd, which shows current working directory
    if (strcmp(call,"pwd") == 0) {
        if (getcwd(cwd,sizeof(cwd)) != NULL) {
    	    printf("%s\n",cwd);
        }
    }
    //implementation of command ls, which shows what's inside the directory
    else if (strcmp(call,"ls") == 0) {
        DIR *dir;
        dir = opendir(getcwd(cwd,sizeof(cwd)));
        struct dirent* current_directory;
        while ((current_directory=readdir(dir)) != NULL) {
            printf("%s\n",current_directory->d_name);
        }
    }
    	
    return 0;
}
