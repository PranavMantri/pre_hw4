#include <unistd.h>

int main() {
    asm("mov $1, %rax\n"      // syscall number for write
        "mov $1, %rdi\n"      // file descriptor (stdout)
        "lea msg(%rip), %rsi\n" // pointer to message
        "mov $1, %rdx\n"      // message length
        "syscall\n"
        "mov $60, %rax\n"     // syscall number for exit
        "xor %rdi, %rdi\n"    // status code 0
        "syscall\n"
        "msg: .ascii \"a\"");
    return 0;
}
