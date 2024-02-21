#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <cmath>

using namespace std;

int isPrime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}

int nthreads;
long long int count = 0;
pthread_mutex_t lock;

void *findPrime(void *start) {
    int *startNum = (int *) start;
    for (int i = *startNum; i <= 100009; i += nthreads) {
        if (isPrime(i)) {
            pthread_mutex_lock(&lock);
            count++;
            pthread_mutex_unlock(&lock);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Please provide the number of threads to use as an argument." << endl;
        return -1;
    }
    nthreads = atoi(argv[1]);
    pthread_t threads[nthreads];
    pthread_mutex_init(&lock, NULL);
    int startNum[nthreads];
    for (int i = 0; i < nthreads; i++) {
        startNum[i] = i + 2;
        if (pthread_create(&threads[i], NULL, findPrime, (void *) &startNum[i])) {
            cout << "Error creating thread" << endl;
            return -1;
        }
    }

    for (int i = 0; i < nthreads; i++) {
        if (pthread_join(threads[i], NULL)) {
            cout << "Error joining thread" << endl;
            return -1;
        }
    }

    pthread_mutex_destroy(&lock);
    cout << "Number of prime numbers between 1 and 100009: " << count << endl;

    return 0;
}