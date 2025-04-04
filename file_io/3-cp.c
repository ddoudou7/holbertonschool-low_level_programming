#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * print_error_and_exit - Print error and exit
 * @msg: error message format
 * @arg: argument to print
 * @code: exit status code
 */
void print_error_and_exit(const char *msg, const char *arg, int code)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(code);
}

/**
 * open_file_from - Open source file
 * @filename: source filename
 * Return: file descriptor
 */
int open_file_from(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
		print_error_and_exit("Error: Can't read from file %s\n", filename, 98);
	return (fd);
}

/**
 * open_file_to - Open destination file
 * @filename: destination filename
 * Return: file descriptor
 */
int open_file_to(const char *filename)
{
	int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fd == -1)
		print_error_and_exit("Error: Can't write to %s\n", filename, 99);
	return (fd);
}

/**
 * read_and_write_loop - Copy content from fd_from to fd_to
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @filename_from: name of source file (for error msg)
 * @filename_to: name of destination file (for error msg)
 */
void read_and_write_loop(int fd_from, int fd_to,
			 const char *filename_from, const char *filename_to)
{
	ssize_t r, w;
	char buf[BUF_SIZE];

	while ((r = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w != r)
		{
			close(fd_from);
			close(fd_to);
			print_error_and_exit("Error: Can't write to %s\n", filename_to, 99);
		}
	}
	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		print_error_and_exit("Error: Can't read from file %s\n", filename_from, 98);
	}
}

/**
 * close_files - Close both file descriptors
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 */
void close_files(int fd_from, int fd_to)
{
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
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_file_from(argv[1]);
	fd_to = open_file_to(argv[2]);
	read_and_write_loop(fd_from, fd_to, argv[1], argv[2]);
	close_files(fd_from, fd_to);

	return (0);
}
