#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int i;

    for (i = 0; i < 4; i++) {
        child_pid = fork();
        if (child_pid == 0) {
            break;
        }
    }

    if (child_pid == 0) {
        if (i == 0) {
            for (int j = 1; j <= 25; j++) {
                printf("Process 0: %d\n", j);
            }
        } else if (i == 1) {
            for (int j = 26; j <= 50; j++) {
                printf("Process 1: %d\n", j);
            }
        } else if (i == 2) {
            for (int j = 51; j <= 75; j++) {
                printf("Process 2: %d\n", j);
            }
        } else if (i == 3) {
            for (int j = 76; j <= 100; j++) {
                printf("Process 3: %d\n", j);
            }
        }
    }
    return 0;
}