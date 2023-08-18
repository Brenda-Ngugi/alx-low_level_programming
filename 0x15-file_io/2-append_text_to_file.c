#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file.
 * @text_content: added text content.
 *
 * Return: 1 if the file exists. -1 if the file does not exist
 * or if it fails.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int bn;
	int nletters;
	int rwr;

	if (!filename)
		return (-1);

	bn = open(filename, O_WRONLY | O_APPEND);

	if (bn == -1)
		return (-1);

	if (text_content)
	{
		for (nletters = 0; text_content[nletters]; nletters++)
			;

		rwr = write(bn, text_content, nletters);

		if (rwr == -1)
			return (-1);
	}

	close(bn);

	return (1);
}
