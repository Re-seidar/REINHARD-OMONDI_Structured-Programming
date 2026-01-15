#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5  // Fixed size of circular buffer

// Structure to represent circular buffer
typedef struct {
    int buffer[BUFFER_SIZE];
    int head;      // Index of oldest element
    int tail;      // Index where next element will be inserted
    int count;     // Number of elements currently in buffer
    int is_full;   // Flag to indicate if buffer is full
} CircularBuffer;

// Initialize circular buffer
void init_buffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
    cb->is_full = 0;

    // Initialize all elements to 0 (optional)
    for(int i = 0; i < BUFFER_SIZE; i++) {
        cb->buffer[i] = 0;
    }
}

// Insert a new sample into circular buffer
void insert_sample(CircularBuffer *cb, int value) {
    // Insert value at tail position
    cb->buffer[cb->tail] = value;

    if(cb->is_full) {
        // Buffer is full, overwrite oldest (move head forward)
        cb->head = (cb->head + 1) % BUFFER_SIZE;
    }

    // Move tail to next position
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;

    // Update count and fullness flag
    if(!cb->is_full) {
        cb->count++;
        if(cb->count == BUFFER_SIZE) {
            cb->is_full = 1;
        }
    }
}

// Print all stored samples in chronological order (oldest → newest)
void print_buffer(const CircularBuffer *cb) {
    if(cb->count == 0) {
        printf("Buffer is empty.\n");
        return;
    }

    printf("Buffer contents (oldest → newest): ");

    if(!cb->is_full) {
        // Buffer not full - simple linear print
        for(int i = 0; i < cb->count; i++) {
            printf("%d ", cb->buffer[i]);
        }
    } else {
        // Buffer is full - circular print starting from head
        int index = cb->head;
        for(int i = 0; i < BUFFER_SIZE; i++) {
            printf("%d ", cb->buffer[index]);
            index = (index + 1) % BUFFER_SIZE;
        }
    }
    printf("\n");
}

// Print buffer in array format for debugging
void print_buffer_debug(const CircularBuffer *cb) {
    printf("\nDebug Info:\n");
    printf("Buffer: [");
    for(int i = 0; i < BUFFER_SIZE; i++) {
        printf("%d", cb->buffer[i]);
        if(i < BUFFER_SIZE - 1) printf(" ");
    }
    printf("]\n");
    printf("Head: %d, Tail: %d, Count: %d, Is Full: %d\n",
           cb->head, cb->tail, cb->count, cb->is_full);
}

// Get the count of elements in buffer
int get_buffer_count(const CircularBuffer *cb) {
    return cb->count;
}

// Check if buffer is empty
int is_buffer_empty(const CircularBuffer *cb) {
    return cb->count == 0;
}

// Check if buffer is full
int is_buffer_full(const CircularBuffer *cb) {
    return cb->is_full;
}

// Main function to test the circular data logger
int main() {
    CircularBuffer data_logger;
    int value, choice;

    // Initialize buffer
    init_buffer(&data_logger);

    printf("=== Circular Data Logger ===\n");
    printf("Buffer Size: %d\n\n", BUFFER_SIZE);

    do {
        printf("\nMenu:\n");
        printf("1. Insert a new sample\n");
        printf("2. Print all samples (oldest → newest)\n");
        printf("3. Print buffer details (debug)\n");
        printf("4. Reset buffer\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter sensor value: ");
                if(scanf("%d", &value) == 1) {
                    insert_sample(&data_logger, value);
                    printf("Value %d inserted.\n", value);

                    if(is_buffer_full(&data_logger)) {
                        printf("Note: Buffer is full. Oldest values will be overwritten.\n");
                    }
                } else {
                    printf("Invalid input!\n");
                    // Clear input buffer
                    while(getchar() != '\n');
                }
                break;

            case 2:
                printf("\n");
                print_buffer(&data_logger);
                break;

            case 3:
                print_buffer_debug(&data_logger);
                break;

            case 4:
                init_buffer(&data_logger);
                printf("Buffer reset successfully.\n");
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}
