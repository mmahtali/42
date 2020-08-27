#include <stdlib.h>

int		isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int		isvalid(char c, int base)
{
	char digit[17] = "012346789abcdef";
	char digit2[17] = "0123456789ABCDEF";

	while(base--)
		if (c == digit[base] || c == digit2[base])
			return (1);
	return (0);
}

int		valueof(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int		sign;
	int		result;
	while (isblank (*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (isvalid (*str, str_base))
		result = result * str_base + valueof(*str++);
	return (result * sign);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%d\n", ft_atoi_base(av[1], atoi(av[2])));
	return (0);
}
