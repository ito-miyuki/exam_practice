#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
    char *b = (char *)malloc(sizeof(char) * 10000), *y = b;
    while (read(fd, y, 1) > 0 && *y++ != '\n');
    return y > b ? (*y = 0, b) : (free(b), NULL);
}
