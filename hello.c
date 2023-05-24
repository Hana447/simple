#include <stdio.h>
#include <unistd.h>
/**
  * main - main function
  * Return: return 0
  */
int  main(void)
{
	write(STDOUT_FILENO, "HELLO WORLD\n", 15);

	return (0);
}
