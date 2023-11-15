#include "monty.h"
/**
*isDigit - check if the input is digit
*@str: input
*Return: returns 1 if str is digit
 */
int isDigit(char *str)
{
	if (*str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
