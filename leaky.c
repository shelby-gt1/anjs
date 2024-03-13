#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#define BUCKET_SIZE 1000

void bucketOutput(int *bucket, int output) {
    if (*bucket > 0 && *bucket > output) {
        *bucket -= output;
        printf("\n%d units outputted. Remaining: %d", output, *bucket); 
    } else if (*bucket > 0) {
        printf("\nBucket emptied. Remaining: %d", *bucket);
        *bucket = 0;
    } else {
        printf("\nBucket is empty.");
    }
}

int main() {
    int packetSize, waitTime, bucket = 0, outputRate;
    printf("Leaky Bucket Algorithm for Congestion Control\n\n"); 
    printf("Enter the output rate: ");
    scanf("%d", &outputRate);

    while (1) {
        packetSize = rand() % 500; 
        printf("\nNew packet size: %d", packetSize);

        if (bucket + packetSize <= BUCKET_SIZE) {
            bucket += packetSize;
            printf("\nBucket size: %d", bucket);
        } else {
            printf("\nPacket discarded - Bucket overflow!");
            break;
        }

        waitTime = rand() % 5; 
        printf("\nNext packet in %d seconds...\n", waitTime); 
        sleep(waitTime);
        bucketOutput(&bucket, outputRate); 
    }
    return 0;
}
