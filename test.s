# 1 "test.S"
# 1 "/home/xxx//"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "test.S"
# 1 "/usr/include/x86_64-linux-gnu/sys/syscall.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/sys/syscall.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/asm/unistd.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/asm/unistd.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/asm/unistd_64.h" 1 3 4
# 21 "/usr/include/x86_64-linux-gnu/asm/unistd.h" 2 3 4
# 25 "/usr/include/x86_64-linux-gnu/sys/syscall.h" 2 3 4




# 1 "/usr/include/x86_64-linux-gnu/bits/syscall.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/sys/syscall.h" 2 3 4
# 2 "test.S" 2
# 10 "test.S"
.global _start
_start:
    movq $1, %rax; movq $1, %rdi; movq $addr1, %rsi; movq $addr2 - addr1 - 1, %rdx; syscall
    movq $60, %rax; movq $100, %rdi; movq $0, %rsi; movq $0, %rdx; syscall

addr1:
    .ascii "\033[01;31mHello, World\033[0m\n"
addr2:
