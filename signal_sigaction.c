/**
*  signal_sigaction.c
* Description: Uses sigaction to register a SIGUSR1 handler that prints the PID of the sending process
* Author: Jonathan Vang CPE2600
* Command to send SIGUSR1 (from another terminal, using the PID printed on
* startup):
*     kill -SIGUSR1 <pid>      (or kill -10 <pid> on Linux)
* The sender PID printed will be the PID of the shell running kill.
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
*  handler registered with SA_SIGINFO
*/
void handle_sigusr1(int signum, siginfo_t *info, void *context) {
    printf("Received SIGUSR1 from process %d\n", info->si_pid);
}

int main() {
    struct sigaction sa;

    // Use the three-argument handler; SA_SIGINFO must be set and must
    // not be overwritten afterwards
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