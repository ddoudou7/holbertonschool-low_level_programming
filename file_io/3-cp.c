#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * print_error_and_exit - Print error message and exit with code
 * @msg: error message format
 * @arg: string to include
 * @code: exit code
 */
void print_error_and_exit(const char *msg, const char *arg, int code)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * copy_file - Copies the content of one file to another
 * @file_from: source file
 * @file_to: destination file
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, r, w;
	char buf[BUF_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error_and_exit("Error: Can't read from file %s\n", file_from, 98);

	r = read(fd_from, buf, BUF_SIZE);
	if (r == -1)
	{
		close(fd_from);
		print_error_and_exit("Error: Can't read from file %s\n", file_from, 98);
	}

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error_and_exit("Error: Can't write to %s\n", file_to, 99);
	}

	while (r > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
		{
			close(fd_from);
			close(fd_to);
			print_error_and_exit("Error: Can't write to %s\n", file_to, 99);
		}

		r = read(fd_from, buf, BUF_SIZE);
		if (r == -1)
		{
			close(fd_from);
			close(fd_to);
			print_error_and_exit("Error: Can't read from file %s\n", file_from, 98);
		}
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);

	return (0);
}
