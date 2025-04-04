#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * print_error - prints a formatted error and exits
 * @msg: the error message format
 * @arg: argument for the error message
 * @code: exit code
 */
void print_error(const char *msg, const char *arg, int code)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * close_fd - closes a file descriptor and handles errors
 * @fd: file descriptor to close
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to, r, w;
	char buffer[BUFFER_SIZE];

	if (ac != 3)
		print_error("Usage: cp file_from file_to\n", "", 97);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		print_error("Error: Can't read from file %s\n", av[1], 98);

	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		print_error("Error: Can't write to %s\n", av[2], 99);
	}

	while ((r = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			print_error("Error: Can't write to %s\n", av[2], 99);
		}
	}

	if (r == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		print_error("Error: Can't read from file %s\n", av[1], 98);
	}

	close_fd(fd_from);
	close_fd(fd_to);
	return (0);
}

