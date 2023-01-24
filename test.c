#include <unistd.h>
#include <stdio.h>
int main() {
    char *args[] = {"ls", "-l", NULL};
    char *envp[] = {NULL};
    execve("/bin/l", args, envp);
    printf("ok\n");
    return 0;
}