
#include "get_next_line.h"

int main() {
    int fd;          // File descriptor
    char *line;

    // Open a file for reading (replace 'your_file.txt' with your file)
    fd = open("testfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening the file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
    }
    return 0;
}