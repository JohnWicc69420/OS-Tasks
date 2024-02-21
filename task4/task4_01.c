#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == 0) {
        printf("This is the child process.\n");
        printf("Child process ID: %d\n", getpid());
        printf("Parent process ID: %d\n", getppid());
    } else {
        printf("This is the parent process.\n");
        printf("Parent process ID: %d\n", getpid());
    }
    return 0;
}