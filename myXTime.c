#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <errno.h>

void main()
{
	struct timespec time; //how does this work 
	syscall(326, &time); //uses the syscall from the syscall table
	printf("%ld\n", time.tv_nsec);
}
