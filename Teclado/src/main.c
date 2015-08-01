#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif

int main(int argc, char** argv)
{
    while (1)
    {
        int selected;
        fd_set set = {0};
        struct timeval tm = {0};

        FD_SET(STDIN_FILENO, &set);
        tm.tv_sec = 3;

        selected = select(1, &set, NULL, NULL, &tm);

        if (selected > 0)
        {
            char msg[256] = {0};

            fgets(msg, 255, stdin);

            printf("Lido: %s\n", msg);
        }
    }

	return 0;
}
