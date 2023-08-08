#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: the file name.
 * @letters: number of letters printed.
 *
 * Return: number of letters printed. If it fails, return 0.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int bn;
	ssize_t nrd, nwr;
	char *buffer;

	if (!filename)
		return (0);

	bn = open(filename, O_RDONLY);

	if (bn == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
		return (0);

	nrd = read(bn, buffer, letters);
	nwr = write(STDOUT_FILENO, buffer, nrd);

	close(bn);

	free(buffer);

	return (nwr);
}
