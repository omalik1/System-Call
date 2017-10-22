#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <errno.h>

void main()
{
	struct timespec time; // Creating structure variable for time spec 
	syscall(326, &time);  // Passing structure refernce to sys call 326 (myXtime)
	printf("%ld\n", time.tv_nsec);
}
