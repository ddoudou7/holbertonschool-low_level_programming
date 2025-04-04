#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
 * print_error - Print to stderr and exit
 * @code: exit code
 * @msg: message format
 * @arg: filename
 */
void print_error(int code, const char *msg, const char *arg)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * close_fd - Close file descriptor
 * @fd: file descriptor
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
 * transfer - Read from fd_from and write to fd_to
 * Always exits with 98 on any read OR write failure
 * @fd_from: source fd
 * @fd_to: destination fd
 * @file_from: file name (source)
 * @file_to: file name (unused, but required)
 */
void transfer(int fd_from, int fd_to,
	const char *file_from, const char *file_to __attribute__((unused)))
{
	ssize_t r, w;
	char buffer[BUF_SIZE];

	while ((r = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w != r)
		{
			close_fd(fd_from);
			close_fd(fd_to);
			print_error(98, "Error: Can't read from file %s\n", file_from);
		}
	}

	if (r == -1)
	{
		close_fd(fd_from);
		close_fd(fd_to);
		print_error(98, "Error: Can't read from file %s\n", file_from);
	}
}

/**
 * copy_file - Open files and transfer contents
 * @file_from: source file name
 * @file_to: destination file name
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file %s\n", file_from);

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		print_error(99, "Error: Can't write to %s\n", file_to);
	}

	transfer(fd_from, fd_to, file_from, file_to);

	close_fd(fd_from);
	close_fd(fd_to);
}

/**
 * main - Entry point
 * @argc: number of args
 * @argv: array of args
 * Return: 0 or exits with code
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to\n", "");

	copy_file(argv[1], argv[2]);
	return (0);
}

