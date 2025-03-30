#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <sys/types.h>


static void die (char *msg) {perror(msg); exit(1);}


int main(int argc, char **argv)
{
	int icount = 0;
	int wstatus;
	
	argv++;

	pid_t pid = fork();

	if (pid < 0)
		die("fork");
	if(!pid) {

		ptrace(PTRACE_TRACEME, NULL, NULL, NULL);
		
		execve(*argv, argv, NULL);
		die("execve");
	}


	for(;;) {

		/* after linux 4.7, __WALL is implict on ptraced processes, but
		 * we put it here for clarity
		 */
		if (waitpid(pid, &wstatus, 0) < 0)
			die("waitpid");

		if (WIFEXITED(wstatus))
			break;
		if (WIFSTOPPED(wstatus) && WSTOPSIG(wstatus) == SIGTRAP) {
			icount++;
			if(ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL))
				die("ptrace");
		}
	}
	printf("We counted %d instructions!\n", icount);
	return 0;

}
