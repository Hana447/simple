#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/**
  * main - main function
  * @ac: arg1
  * @av: arg2
  * @ev: arg3
  * Return: return 0
  */

int main(int ac, char *av[], char *ev[])
{
	char *cmd;
	size_t size = 0;
	pid_t fid;
	int count = 0;
	ssize_t len;
	 int i;

	while (1)
	{
		i = 0;
		write(STDOUT_FILENO, "sshell$ ", 8);
		len = getline(&cmd, &size, stdin);

		if (len == -1)
		{
			write(STDOUT_FILENO, "\nExiting...\n", 15);
			free(cmd);
			break;
		}
		cmd[len - 1] = '\0';

		fid = fork();
		count++;

		if (fid == -1)
		{
			perror("./sshell ");
			return (1);
		}
		if (fid == 0)
		{
			if (execve(cmd, av, ev) == -1)
				perror("./sshell");
		}
		else
			wait(NULL);
	}
	
	return (0);
}
