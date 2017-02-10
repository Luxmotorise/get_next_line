
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char **line;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, line);
	close(fd);
	return (0);
}