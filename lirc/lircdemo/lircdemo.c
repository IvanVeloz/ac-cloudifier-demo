#ifdef HAVE_CONFIG_H
# include <config.h>	// this is LIRC code
#endif

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <lirc_client.h>

int main()
{
	printf("LIRC demonstration\n");
	int r;
	int fd = lirc_get_local_socket(NULL, 0);
	if(fd<0) {
		printf("Failed to open local socket\n");
		return -1;
	}
	if(r = lirc_send_one(fd, "GE-AHP05LZQ2", "KEY_POWER")) goto fail;
	sleep(3);
	if(r = lirc_send_one(fd, "GE-AHP05LZQ2", "KEY_POWER")) goto fail;
	printf("Done.\n");
	return 0;
	fail:
	printf("Failed to send IR command. %s\n",strerror(r));
	return -1;
}
