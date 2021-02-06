#include "mbed.h"
#include "rtos.h"

BufferedSerial s(PA_2, PA_3, 115200);

FileHandle *mbed::mbed_override_console(int fd) {
    return &s;
}

int main(void) {
	while (true) {
		printf("Hello?\r\n");
		ThisThread::sleep_for(1s);
	}
    return 0;
}
