#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER 1024

int main()
{
    int ff, pid;
    char * myfifo = "/tmp/myfifo";
    char buf[BUFFER];

    /* FIFO elkészítése (névvel ellátott csővezeték) */
    mkfifo(myfifo, 0666);

    /*gyerek létrehozása*/
    if((pid=fork()) == 0)
	{
	   execl("./child",  "ls", "-l", (char*)NULL);
	}

    /* üzenet fogadasa */
    ff = open(myfifo, O_RDONLY);
    read(ff, buf, BUFFER);
    printf("%s\n",buf);
    close(ff);

    /* FIFO eltávolítása */
    unlink(myfifo);

    return 0;
}
