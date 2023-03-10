#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    FILE *fp = fopen("sample.txt", "r");
    if (fp == NULL)
    {
        printf("Error\n");
        exit(1);
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Child process:\n");
        putchar(fgetc(fp));
        putchar(fgetc(fp));
        printf("\n");
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("Parent process:\n");
        putchar(fgetc(fp));
        putchar(fgetc(fp));
        printf("\n");
        // fclose(fp);
    }
    return 0;
}
