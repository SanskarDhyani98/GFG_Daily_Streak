#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>  // For sleep function

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;  // Current buffer count

// Semaphores
sem_t empty;  // Counts empty slots in the buffer
sem_t full;   // Counts full slots in the buffer
pthread_mutex_t mutex;  // Mutex for critical section

// Function for producer
void* producer(void* arg) {
    int item, i;
    for (i = 0; i < 10; i++) {
        // Produce an item
        item = rand() % 100;

        // Wait for an empty slot
        sem_wait(&empty);

        // Lock the buffer
        pthread_mutex_lock(&mutex);

        // Critical section: Add item to the buffer
        buffer[count] = item;
        count++;
        printf("Producer produced: %d\n", item);

        // Unlock the buffer
        pthread_mutex_unlock(&mutex);

        // Signal that there is a full slot
        sem_post(&full);

        // Simulate production time
        sleep(2);
    }
    pthread_exit(NULL);
}

// Function for consumer
void* consumer(void* arg) {
    int item, i;
    for (i = 0; i < 10; i++) {
        // Wait for a full slot
        sem_wait(&full);

        // Lock the buffer
        pthread_mutex_lock(&mutex);

        // Critical section: Remove item from the buffer
        item = buffer[count - 1];
        count--;
        printf("Consumer consumed: %d\n", item);

        // Unlock the buffer
        pthread_mutex_unlock(&mutex);

        // Signal that there is an empty slot
        sem_post(&empty);

        // Simulate consumption time
        sleep(2);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t prod, cons;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);  // Initially, buffer is empty
    sem_init(&full, 0, 0);  // Initially, no items in the buffer
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}