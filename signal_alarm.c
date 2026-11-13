/**
* signal_alarm.c
* Description: Schedules a SIGALRM after 5 seconds and handles it
* Author: Jonathan Vang CPE2600
*
* Notes: alarm(5) asks the OS to send SIGALRM to this process in 5 seconds.
* The handler prints a message, then the program exits.
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/**
* Signal handler for SIGALRM - prints that the alarm was received
*/
void handle_alarm(int signum) {
    printf("Received SIGALRM (signal %d)\n", signum);
}

int main() {
    // Register the handler
    signal(SIGALRM, handle_alarm);

    // Schedule the alarm for 5 seconds from now
    alarm(5);
    printf("Alarm scheduled for 5 seconds...\n");

    // Suspend until a signal is received
    pause();

    printf("Done.\n");
    return 0;
}