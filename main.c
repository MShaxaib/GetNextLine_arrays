
#include "get_next_line.h"

int main()
{
    char *str;
    int fd;

fd = open("testfile.txt", O_RDONLY);

    while((str = get_next_line(fd)) != NULL)
    {
        printf("%s", str);
        free(str);
    }
return(0);
}
