/**

Good parents don't let their children become zombies!

Note, the word 'zombie' in this instance sheds some light as to what they actually represent.
When a child finishes (or terminates) it still takes up a slot in the kernel process table.
Furthermore, they still contain information about the process that got terminated,
such as process id, exit status, etc. (i.e. a skeleton of the original process still remains).
Only when the child has been 'waited on' will the slot be available and the remaining information can be accessed by the parent

A long running program could create many zombies by continually creating processes and never wait-ing for them.


What would be effect of too many zombies?
Eventually there would be insufficient space in the kernel process table to create a new processes.
Thus fork() would fail and could make the system difficult / impossible to use - 
for example just logging in requires a new process!


How do I prevent zombies? (Warning: Simplified answer)
Wait on your child!
waitpid(child, &status, 0); // Clean up and wait for my child process to finish.

How can I asynchronously wait for my child using SIGCHLD? (ADVANCED)
Warning: This section uses signals which we have not yet fully introduced. The parent gets the signal SIGCHLD when a child completes, so the signal handler can wait on the process. A slightly simplified version is shown below.

***/
#include <stdio.h>

pid_t child;

void cleanup(int signal) {
  int status;
  waitpid(child, &status, 0);
  write(1,"cleanup!\n",9);
}

int main() {
   // Register signal handler BEFORE the child can finish
   signal(SIGCHLD, cleanup); // or better - sigaction
   child = fork();
   if (child == -1) { exit(EXIT_FAILURE);}

   if (child == 0) { /* I am the child!*/
     // Do background stuff e.g. call exec   
   } else { /* I'm the parent! */
      sleep(4); // so we can see the cleanup
      puts("Parent is done");
   }
   return 0;
} 
