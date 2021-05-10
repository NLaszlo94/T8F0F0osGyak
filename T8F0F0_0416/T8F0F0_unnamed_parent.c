#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER 1024

int main()
{
    int pid;
    int fd[2];
    char buf[BUFFER];

    /* pipe elkészítése (névtelen csővezeték) */
    pipe(fd);

    /*gyerek indítása*/
    if((pid=fork()) == 0)
    {
	close(fd[0]);
	write(fd[1], "Novak Laszlo", sizeof("Novak Laszlo"));
	close(fd[1]);
    } else {
	close(fd[1]);
	read(fd[0], buf, BUFFER);
	close(fd[0]);
    }

    /* üzenet fogadasa */
    wait(NULL);
    printf("%s\n",buf);

    return 0;
}
