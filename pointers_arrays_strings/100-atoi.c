#include "main.h"
#include <limits.h> /* Pour INT_MAX et INT_MIN */

/**
 * _atoi - Converts a string to an integer
 * @s: The string to be converted
 *
 * Return: The integer value of the string
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, digit_found = 0;
	unsigned int num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');
			digit_found = 1;

			/* Vérification de dépassement */
			if ((sign == 1 && num > INT_MAX) ||
			    (sign == -1 && num > (unsigned int)INT_MAX + 1))
				return (sign == 1 ? INT_MAX : INT_MIN);
		}
		else if (digit_found)
			break;

		i++;
	}

	return (sign * num);
}
