#include <utmp.h>
#include <err.h>

#define NAME_WIDTH  8

    FILE *ufp;
    int numberOfUsers = 0;
    struct utmp usr;
    ufp = file(_PATH_UTMP);
    while (fread((char *)&usr, sizeof(usr), 1, ufp) == 1) {
    if (*usr.ut_name && *usr.ut_line && *usr.ut_line != '~') {
         numberOfUsers++;
        }
    }

    FILE *file(char *name)
    {
        FILE *ufp;

        if (!(ufp = fopen(name, "r"))) {
            err(1, "%s", name);
        }
        return(ufp);
    }
