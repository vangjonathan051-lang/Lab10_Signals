/**
*  send_signal.c
 Description: Sends SIGUSR1 plus a random integer to a process using sigqueue
* Author: Jonathan Vang CPE2600 
*
* Usage: ./send_signal <pid of recv_signal>
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    // Convert the command line argument to a process id
    pid_t pid = (pid_t)atoi(argv[1]);

    // Seed the random number generator and pick a number
    srand(time(NULL));
    int number = rand();
    printf("Sending SIGUSR1 with value: %d\n", number);

    // Send the signal along with the number
    union sigval value;
    value.sival_int = number;
    if (sigqueue(pid, SIGUSR1, value) == -1) {
        perror("sigqueue");
        return 1;
    }

    return 0;
}