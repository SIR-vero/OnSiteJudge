#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigproc(int arg)
{
    /**signal(SIGINT, sigproc); /**NOTE some versions of UNIX will reset signal to default
                                after each call. So for portability reset signal each time**/
    printf("ctrl^C dis\n");
}

void quitproc(int arg)
{
    printf ("terminating\n");
    exit(0);
}

    auto fp_sigproc = &sigproc;
    auto fp_quitproc = &quitproc;
    //signal(SIGINT, fp_sigproc);
    //signal(SIGSEGV, fp_quitproc);

int main()
{

    int p[1];
    printf("%d",p[200]);
}
