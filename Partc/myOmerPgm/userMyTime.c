#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <sys/unistd.h>
#include <fcntl.h>

#define N 30
#define MAX_LENGTH 400

int main(int argc, char *argv[])
{
	int i, fd, bytes_read;
	struct timeval gtodTimes[N];

	/* allocate memory for character buffers HERE before you use them */
	char *procClockTimes = malloc (sizeof (char) * N);

	fd = open("/dev/mytime", O_RDONLY);
	/* check for errors HERE */
	if(fd < 0)
	{
		perror("Error opening file");
	}

	for(i=0; i<N; i++)
	{
		gettimeofday(&gtodTimes[i], 0);
		bytes_read = read(fd, procClockTimes[i], MAX_LENGTH);
		/* check for errors HERE */
		if(bytes_read < 0)
		{
			perror("Read is wrong");			
		}		
	}	

	close(fd);

	for(i=0; i<N; i++)
	{
		printf("current_kernel_time: %ld\n 
			getnstimeofday: %s\n", gtodTimes[i].tv_usec, procClockTimes[i]);
		/* fix the output format appropriately in the above line */
	}

}
