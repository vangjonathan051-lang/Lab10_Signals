/**
* signal_handler.c
* Descrition: Sets a signal handler for SIGINT, the handler prints a message and then
* returns (it no longer quits)
* Author: Jonathan Vang CPE2600
*
* Brief summary of modifications:
* - The handler no longer calls exit(), it only prints a message and returns.
*   The program therefore keeps running after SIGINT.
* - Ways to send SIGINT:
*     1. Press CTRL+C in the terminal running the program
*     2. From another terminal: kill -SIGINT <pid>   (or kill -2 <pid>)
* - Since SIGINT is now handled and ignored, CTRL+C no longer stops the
*   program. To stop it, send SIGKILL (it cannot be caught or handled):
*     kill -SIGKILL <pid>   (or kill -9 <pid>)
*   (CTRL+Z / SIGSTOP only suspends it, it does not exit.)
*/
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
*  Signal handler for SIGINT - prints a message and returns
*/
void handle_signal(int signum) {
    printf("Received signal %d\n", signum);
}

int main() {
    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while (1) {
        printf("Sleeping\n");
        sleep(1);
    }
    return 0;
}