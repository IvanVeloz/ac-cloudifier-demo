#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <pigpiod_if2.h>


#define	GPIO_LED_BLUE	22	// Active low blue LED
#define	GPIO_LED_RED	23	// Active low red LED

int main() {
	int r;
	int fd;

	printf("pigpio demo\n");

	fd = pigpio_start(NULL, NULL); 

	if(fd < 0) {
		printf("Failed to initialize pigpio\n");
	}

	r = gpio_write(fd, GPIO_LED_BLUE, PI_HIGH);
	assert(r==0);
	r = set_mode(fd, GPIO_LED_BLUE, PI_OUTPUT);
	assert(r==0);
	r = set_pull_up_down(fd, GPIO_LED_BLUE, PI_PUD_OFF);
	assert(r==0);
	r = gpio_write(fd, GPIO_LED_RED, PI_HIGH);
	assert(r==0);
	r = set_mode(fd, GPIO_LED_RED, PI_OUTPUT);
	assert(r==0);
	r = set_pull_up_down(fd, GPIO_LED_RED, PI_PUD_OFF);
	assert(r==0);

	for(int i = 0; i < 5; i++) {
		gpio_write(fd, GPIO_LED_BLUE, PI_LOW);
		gpio_write(fd, GPIO_LED_RED, PI_HIGH);
		usleep(500000);	// 500ms
		gpio_write(fd, GPIO_LED_BLUE, PI_HIGH);
		gpio_write(fd, GPIO_LED_RED, PI_LOW);
		usleep(500000);	// 500ms
	}
	// turn off LEDs
	r = gpio_write(fd, GPIO_LED_BLUE, PI_HIGH);
	r = gpio_write(fd, GPIO_LED_RED, PI_HIGH);

	pigpio_stop(fd);
	return 0;
}

