#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("pid=%d uid=%d euid=%d gid=%d\n",
           getpid(), getuid(), geteuid(), getgid());
    return 0;
}
