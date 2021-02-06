#include "mbed.h"
#include "rtos.h"
#include "USBSerial.h"

//USBHID hid(8, 8);
BufferedSerial s(PA_2, PA_3, 115200);
USBSerial u(false);

FileHandle *mbed::mbed_override_console(int fd) {
    return &s;
}

Thread thread;

void usb_thread() {
	int i = 0;
	while (true) {
		u.printf("Hello USB %d\r\n", i++);
		ThisThread::sleep_for(100ms);
	}
}

int main(void) {
	thread.start(usb_thread);
	
	u.set_blocking(false);
	u.connect();
	
	int i = 0;
	while (true) {
		printf("Hello? %d\r\n", i++);
		ThisThread::sleep_for(100ms);
	}
    return 0;
}
