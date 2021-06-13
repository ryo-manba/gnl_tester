#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

#define TXT1 "txt_box/a1.txt"
#define TXT2 "txt_box/a2.txt"
#define TXT3 "txt_box/a3.txt"
#define TXT4 "txt_box/a4.txt"

int main(void)
{
	int		fd1, fd2, fd3, fd4, fd5;
	int		return_value;
	char	*line;

	fd1 = open(TXT1, O_RDONLY);
	fd2 = open(TXT2, O_RDONLY);
	fd3 = open(TXT3, O_RDONLY);
	fd4 = open(TXT4, O_RDONLY);
	fd5 = -1;

	while (1)
	{
		int tmp;
		printf("Please select number! (1 ~ 5)\n");

		char c;
		scanf("%c", &c);

		if (c == '1') tmp = fd1;
		if (c == '2') tmp = fd2;
		if (c == '3') tmp = fd3;
		if (c == '4') tmp = fd4;
		if (c == '5') tmp = fd5;

		return_value = get_next_line(tmp, &line);
		printf("fd = %d\n", tmp);
		if (tmp == fd5)
			return (0);
		printf("line = %s\n", line);
		printf("return_value = %d\n\n\n", return_value);
		printf("============================================\n");
		free(line);
		system("leaks bonus");
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	system("leaks bonus");
	return (0);
}
