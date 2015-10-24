#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

static int count;

void handle_signal(int signum)
{
         if (count <10000)
         {
            //printf(1, "count = %d", count);
            count++;
            /*__asm__("mov  0x4(%ebp), %eax");
            __asm__("mov  %eax, 0x8(%ebp)");
            __asm__("mov  0x0(%ebp), %eax");
            __asm__("mov  %eax, 0x4(%ebp)"); */
            *((int *)&signum) = *(((int *)&signum)-1);
            *(((int *)&signum)-1) = *(((int *)&signum)-2); 
            __asm__("addl $0x4, %ebp");

         }
         else
         {
             printf(1, "");
             __asm__("addl $0x11, 0x4(%ebp)");
         }
}

int main(int argc, char *argv[])
{

        int x = 5;
        int y = 0;
        uint tick1 = 0;
        uint tick2 = 0;
        uint tickr = 0;
        uint rtime = 0;

        //tick1 = uptime();

	signal(SIGFPE, handle_signal);
 
        tick1 = uptime();

        x= x/y;	

        tick2 = uptime();

        tickr = (tick2 - tick1);
       
        rtime = ((tick2 - tick1)*10000)/count;                
    
	printf(1, "Traps Performed = %d\n", count);
	printf(1, "Total Elapsed Time: %d\n", tickr*10000);
	printf(1, "Average Time Per Trap: %d us\n", rtime);

	exit();
}
