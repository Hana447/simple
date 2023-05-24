#include <stdio.h>
#include <unistd.h>
/**
  * main - main function
  * Return: return 0
  */
int main(void)
{
	write(STDOUT_FILENO, "Hello world \n", 18);

	return (0);
}
