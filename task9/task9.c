#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int buffer[2];
    pid_t pid;

    // create pipe
    if(pipe(buffer) < 0){
        printf("\n\tPipe Function Failed!");
        return 0;
    }

    // create first child process
    pid = fork();
    if (pid == 0){
        char* message = "Message from Child 1: 123";
        printf("\n\t1st Child Process ID: %d\n", getpid());

        // close the read end of the pipe
        close(buffer[0]);

        // write message to the pipe
        write(buffer[1], message, strlen(message));

        // close the write end of the pipe
        close(buffer[1]);

        // exit child process
        exit(0);
    }
    else {
        // create second child process
        pid = fork();
        if (pid == 0){
            char* message = "Message from Child 2: XYZ";
            printf("\n\t2nd Child Process ID: %d\n", getpid());

            // close the read end of the pipe
            close(buffer[0]);

            // write message to the pipe
            write(buffer[1], message, strlen(message));

            // close the write end of the pipe
            close(buffer[1]);

            // exit child process
            exit(0);
        }
        else {
            printf("\n\tParent Process ID: %d\n", getpid());

            // close the write end of the pipe
            close(buffer[1]);

            // wait for child processes to finish
            wait(NULL);
            wait(NULL);

            // read messages from the pipe
            char message[100];
            int n = read(buffer[0], message, 100);
            message[n] = '\0';
            printf("\n\tMessage from Child 1: %s\n", message);

            n = read(buffer[0], message, 100);
            message[n] = '\0';
            printf("\n\tMessage from Child 2: %s\n", message);

            // close the read end of the pipe
            close(buffer[0]);
        }
    }
    return 0;
}