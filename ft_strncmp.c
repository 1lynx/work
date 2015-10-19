#include <stdio.h>


int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int i = 0;

	while(s1[i] != '\0' && s1[i] == s2[i] && i < (n-1))
	{
		i++;
	}

	if(s1[i] < s2[i] && n != 0)
	{
		return (-1);
	}
	else if(s2[i] < s1[i] && n != 0)
	{
		return (1);
	}

	return (0);
}


int main(void)
{
	char *str;
	char *strr;
	str = "colinonono";
	strr = "colinono";
	printf("%d", ft_strncmp(str, strr, 1));
	return (0);
}
