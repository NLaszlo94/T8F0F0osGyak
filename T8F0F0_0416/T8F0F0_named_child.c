#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER 1024

int main()
{
    	int ff;
    	char * myfifo = "/tmp/myfifo";
        char buf[BUFFER];

        /* Adott szöveg a fifoba */
        ff = open(myfifo, O_WRONLY);
        write(ff, "Novak Laszlo", sizeof("Novak Laszlo"));
        close(ff);

    	return 0;
}
