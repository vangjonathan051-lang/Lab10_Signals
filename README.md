# Lab10_Signals

CPE 2600 Lab 10 - Signals

Name: Jonathan Vang

Usage
handler
bash
./handler
# CTRL+C or `kill -SIGINT <pid>` prints a message but does not exit
kill -SIGKILL <pid>     # SIGKILL cannot be caught, so this stops it
segfault
bash
./segfault              # stop with CTRL+C
alarm
bash
./alarm                 # prints a message after 5 seconds, then exits
sigaction
bash
./sigaction             # prints its PID
kill -SIGUSR1 <pid>     # from another terminal; prints the sender PID
recv and send (Part 4)
bash
./recv                  # terminal 1, prints its PID
./send <pid>            # terminal 2, prints a random number and sends it

recv prints the same number it received.

Finding a PID
bash
pgrep recv              # by name
ps -C recv
./recv &  echo $!       # PID of a background process
