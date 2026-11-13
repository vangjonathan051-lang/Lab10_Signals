/**
* signal_segfault.c
* Description: Program that dereferences a null pointer causing a segmentation fault,
* with a handler installed for SIGSEGV
* Modified by: Jonathan Vang CPE2600
*
* Brief summary of modifications:
* - Installed a handler for SIGSEGV that prints a message and returns.
*
* Observation: the message prints over and over forever. When a handler
* returns, execution resumes exactly where it left off. That is the
* instruction that dereferences NULL, so it faults again, the OS sends
* SIGSEGV again, the handler runs again, and so on. Stop it with CTRL+C.
*/
#include <stdio.h>
#include <signal.h>

/**
* Signal handler for SIGSEGV - prints a message and returns
*/
void handle_sigsegv(int signum) {
    printf("Segmentation fault received (signal %d)\n", signum);
}

int main (int argc, char* argv[]) {
    // Register the handler for SIGSEGV
    signal(SIGSEGV, handle_sigsegv);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}