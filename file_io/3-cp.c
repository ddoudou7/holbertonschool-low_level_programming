#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * transfer_data - reads from fd_from, writes to fd_to
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source file name
 * @file_to: destination file name
 */

/**
 * copy_file - performs file copy operations
 * @file_from: source file name
 * @file_to: destination file name
 */

/**
 * transfer_data - reads from fd_from, writes to fd_to
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source file name
 * @file_to: destination file name
 */

/**
 * transfer_data - reads from fd_from, writes to fd_to
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_from: source file name
 * @file_to: destination file name
 */
void transfer_data(int fd_from, int fd_to,
		   const char *file_from, const char *file_to)
{
	ssize_t r;
	char buf[1024];

	while ((r = read(fd_from, buf, sizeof(buf))) > 0)
	{
		ssize_t w, total = 0;

		while (total < r)
		{
			w = write(fd_to, buf + total, r - total);
			if (w == -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
				close(fd_from);
				close(fd_to);
				exit(99);
			}
			total += w;
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		exit(98);
	}
}

/**
 * copy_file - orchestrates the copy process using transfer_data
 * @file_from: source file name
 * @file_to: destination file name
 */

/**
 * copy_file - orchestrates the copy process using transfer_data
 * @file_from: source file name
 * @file_to: destination file name
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	ssize_t test_read;
	char test_buf[1];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	test_read = read(fd_from, test_buf, 0);
	if (test_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(fd_from);
		exit(98);
	}

	fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(fd_from);
		exit(99);
	}

	transfer_data(fd_from, fd_to, file_from, file_to);

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
 * main - Entry point, validates args and calls copy_file
 * @argc: number of arguments
 * @argv: argument vector
 * Return: 0 on success, or exits with appropriate code on error
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
