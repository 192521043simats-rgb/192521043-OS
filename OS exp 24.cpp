#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd, n;
    char buf[20];

    fd = open("a.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    if(fd == -1) {
        perror("open");
        return 1;
    }

    write(fd, "Hello UNIX", 10);
    lseek(fd, 0, SEEK_SET);
    n = read(fd, buf, 10);
    buf[n] = '\0';

    printf("File content: %s\n", buf);
    close(fd);
    return 0;
}