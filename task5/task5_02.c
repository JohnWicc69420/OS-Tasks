#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // create a text file named data.txt
    FILE *fp;
    fp = fopen("data.txt", "w");
    fprintf(fp, "My name is YOUR_NAME and my roll number is YOUR_ROLL_NUMBER");
    fclose(fp);

    // create a child process
    pid_t child_pid;
    child_pid = fork();
    if (child_pid == -1) {
        printf("Process creation unsuccessful\n");
        exit(1);
    }
    if (child_pid == 0) {
        // in the child process, load the program "test.cpp"
        char *args[] = {"./test", NULL};
        execvp(args[0], args);
        exit(1);
    } else {
        // wait for the child process to finish
        wait(NULL);
    }

    return 0;
}