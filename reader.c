#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Shared resource
int data = 0;
int reader_count = 0; // Keeps track of the number of readers

// Semaphores and mutex
sem_t rw_mutex; // Controls access to the data for readers and writers
pthread_mutex_t mutex; // Controls access to reader_count

// Reader function
void* reader(void* arg) {
    int id = ((int)arg);
    
    while (1) {
        // Entry section
        pthread_mutex_lock(&mutex);
        reader_count++;
        if (reader_count == 1) {
            // First reader locks the resource
            sem_wait(&rw_mutex);
        }
        pthread_mutex_unlock(&mutex);

        // Critical section
        printf("Reader %d is reading data: %d\n", id, data);

        // Exit section
        pthread_mutex_lock(&mutex);
        reader_count--;
        if (reader_count == 0) {
            // Last reader unlocks the resource
            sem_post(&rw_mutex);
        }
        pthread_mutex_unlock(&mutex);

        sleep(1); // Simulate reading time
    }
}

// Writer function
void* writer(void* arg) {
    int id = ((int)arg);
    
    while (1) {
        // Entry section
        sem_wait(&rw_mutex);

        // Critical section
        data = rand() % 100; // Simulate writing
        printf("Writer %d is writing data: %d\n", id, data);

        // Exit section
        sem_post(&rw_mutex);

        sleep(2); // Simulate writing time
    }
}

int main() {
    pthread_t readers[5], writers[2];
    int ids[5];
    
    // Initialize semaphores and mutex
    sem_init(&rw_mutex, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    // Create writer threads
    for (int i = 0; i < 2; i++) {
        ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &ids[i]);
    }

    // Create reader threads
    for (int i = 0; i < 5; i++) {
        ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &ids[i]);
    }

    // Join threads (this program runs indefinitely, so technically unreachable)
    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }

    // Destroy semaphores and mutex
    sem_destroy(&rw_mutex);
    pthread_mutex_destroy(&mutex);

    return 0;
}