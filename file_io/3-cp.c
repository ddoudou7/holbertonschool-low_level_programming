#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * open_source_file - opens the source file
 * @file_from: source file name
 * Return: file descriptor
 */
int open_source_file(const char *file_from)
{
	int fd = open(file_from, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	return (fd);
}

/**
 * open_dest_file - opens the destination file
 * @file_to: destination file name
 * @fd_from: fd of source (to close if error)
 * Return: file descriptor
 */
int open_dest_file(const char *file_to, int fd_from)
{
	int fd = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(fd_from);
		exit(99);
	}
	return (fd);
}

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
	ssize_t r, w;
	char buf[BUF_SIZE];

	while ((r = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			exit(99);
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
 * copy_file - performs file copy operations
 * @file_from: source file name
 * @file_to: destination file name
 */
void copy_file(const char *file_from, const char *file_to)
{
	int fd_from, fd_to;
	char test_buf[1];

	fd_from = open_source_file(file_from);

	if (read(fd_from, test_buf, 0) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		close(fd_from);
		exit(98);
	}

	fd_to = open_dest_file(file_to, fd_from);
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
 * main - entry point
 * @argc: argument count
 * @argv: argument values
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
