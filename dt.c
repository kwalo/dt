#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

static inline void
print_help()
{
        fprintf(stderr, "Usage: dt command [argument...]\n");
}

int
main(int argc, char *const argv[])
{
        if (argc < 2) {
                print_help();
                return 1;
        }

        if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
                print_help();
                return 0;
        }

        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        if (open("/dev/null", O_RDONLY) < 0)
                return 1;

        if (open("/dev/null", O_WRONLY) < 0)
                return 1;

        if (dup2(STDIN_FILENO, STDERR_FILENO) < 0)
                return 1;

        signal(SIGHUP, SIG_IGN);

        argv++;
        switch (fork()) {
        case 0:
                execvp(argv[0], argv);
                break;
        case -1:
                return 1;
        default:
                ;
        }

        return 0;
}
