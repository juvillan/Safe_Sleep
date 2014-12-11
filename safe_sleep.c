#include <errno.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig)
{
	printf("No\n");
}

int main()
{
	signal(SIGTSTP, handler);

	struct timespec now;
	if (clock_gettime(CLOCK_REALTIME, &now) < 0)
	{
		perror("clock_gettime");
		return EXIT_FAILURE;
	}
	now.tv_sec += 5;

	time_t start = time(NULL);
	printf("Start: %s", ctime(&start));

	int result;
	do
	{
		result = clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, 
				                 &now, NULL);
	}
	while (result == EINTR);

	time_t end = time(NULL);
	printf("End: %s", ctime(&end));

}
