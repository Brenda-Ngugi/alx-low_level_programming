#include "main.h"

/**
 * _puts_recursion - Print a string follo
 * wed by a new line
 * @s: the string to print
 *
 * Return: Nothing
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar(*s);
		return;
	}
	_putchar(*s);
	s++;
	_puts_recursion(s);
}
