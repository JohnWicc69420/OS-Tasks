#include <stdio.h>
#include <pthread.h>

// function for first thread to write even numbers to a file
void *writeEvens(void *arg) {
    FILE *fp;
    fp = fopen("evens.txt", "w");
    for (int i = 2; i <= 1000; i += 2) {
        fprintf(fp, "%d\n", i);
    }
    fclose(fp);
    pthread_exit(0);
}

// function for second thread to write odd numbers to a file
void *writeOdds(void *arg) {
    FILE *fp;
    fp = fopen("odds.txt", "w");
    for (int i = 1; i <= 1000; i += 2) {
        fprintf(fp, "%d\n", i);
    }
    fclose(fp);
    pthread_exit(0);
}

int main() {
    pthread_t t1, t2;
    void *retval;

    // create first thread
    pthread_create(&t1, NULL, writeEvens, NULL);

    // create second thread
    pthread_create(&t2, NULL, writeOdds, NULL);

    // wait for first thread to finish
    pthread_join(t1, &retval);

    // wait for second thread to finish
    pthread_join(t2, &retval);

    return 0;
}