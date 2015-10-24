// You must define an inline asm function here to solve stage3.

void restorer(void)
{
    __asm__("pop %ebp");
    __asm__("pop %edx");
    __asm__("pop %edx");
    __asm__("pop %ecx");
    __asm__("pop %eax");
    __asm__("ret");

}
