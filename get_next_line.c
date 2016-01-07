#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define BUF_SIZE 1000

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

char *get_next_line(const int fd)
{
  static char buffer[BUF_SIZE];
  char *str;
  static int compt;
  int i;
  int save;

  read(fd, buffer, BUF_SIZE);
  if (compt != 0)
    compt++;
  save = compt;
  while(buffer[compt] != '\n')
    compt++;
  str = malloc(sizeof(*str) * (compt - save));
  i = 0;
  while ((i + save) != compt)
  {
    str[i] = buffer[save + i];
    i++;
  }
  return(str);
}

int main(int ac, char **av)
{
  int fd;

  fd = open(av[1], O_RDONLY);
//  ft_putstr(get_next_line(fd));
//  ft_putstr(get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));


  //close(fd);
  return(0);
}
