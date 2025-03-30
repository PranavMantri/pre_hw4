#include <unistd.h>
#include <sys/syscall.h>
#include <linux/syscall.h>

int main() {
	syscall(SYS_write, 1, "a\n", 2);
	return 0;
}
