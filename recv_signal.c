/**
* recv_signal.c
*  Description: Receives SIGUSR1 and prints the integer sent with it via sigqueue
* Author: Jonathan Vang CPE2600
*
* Usage: ./recv_signal   (note the PID it prints)
*        then in another terminal: ./send_signal <pid>
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* SIGUSR1 handler - prints the integer sent with the signal
*/
void handle_sigusr1(int signum, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 with value: %d\n", info->si_value.sival_int);
}

int main() {
    struct sigaction sa;
    sa.sa_sigaction = handle_sigusr1;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("My PID is %d, waiting for SIGUSR1...\n", getpid());

    // Wait forever
    while (1) {
        sleep(1);
    }
    return 0;
}