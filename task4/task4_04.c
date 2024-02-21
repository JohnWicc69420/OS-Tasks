#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    pid_t child_pid;
    int i, count = 0;

    for (i = 0; i < 4; i++) {
        child_pid = fork();
        if (child_pid == 0) {
            break;
        }
    }

    if (child_pid == 0) {
        if (i == 0) {
            for (int j = 2; j <= 25001; j++) {
                count += is_prime(j);
            }
            printf("Process 0: %d prime numbers between 2 and 25,001\n", count);
        } else if (i == 1) {
            for (int j = 25002; j <= 50001; j++) {
                count += is_prime(j);
            }
            printf("Process 1: %d prime numbers between 25,002 and 50,001\n", count);
        } else if (i == 2) {
            for (int j = 50002; j <= 75001; j++) {
                count += is_prime(j);
            }
            printf("Process 2: %d prime numbers between 50,002 and 75,001\n", count);
        } else if (i == 3) {
            for (int j = 75002; j <= 100001; j++) {
                count += is_prime(j);
            }
            printf("Process 3: %d prime numbers between 75,002 and 100,001\n", count);
        }
    }
    return 0;
}