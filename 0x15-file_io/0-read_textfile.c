#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- to produce STDOUT read name of file
 * @filename: name of textfile to have to be read
 * @letters: letter numbers to be shown
 * Return: w- number of bytes read and printed at a given time
 *        0 filename is NULL at a given period
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
