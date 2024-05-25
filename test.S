#include <sys/syscall.h>

#define syscall3(id, a1, a2, a3) \
    movq $SYS_##id, %rax; \
    movq $a1, %rdi; \
    movq $a2, %rsi; \
    movq $a3, %rdx; \
    syscall

.global _start
_start:
    syscall3(write, 1, addr1, addr2 - addr1 - 1)
    syscall3(exit, 100, 0, 0)

addr1:
    .ascii "\033[01;31mHello, World\033[0m\n"
addr2:
