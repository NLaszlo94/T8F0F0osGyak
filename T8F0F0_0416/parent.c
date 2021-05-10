#include<stdio.h>
#include<unistd.h>

int pid, ppid;

void main()
{
ppid=getpid();
if ((pid = fork()) == 0)
	{
	execl("./child", "ls", "-1", (char*)NULL);
	}
}
