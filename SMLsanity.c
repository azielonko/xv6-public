#include "types.h"
#include "stat.h"
#include "user.h"

#define LOTS 20

void
do_work()
{
  int i, j;

  for (i = 0; i < 100; i++)
    for (j = 0; j < 1000000; j++)
      ;
}

int
main(int argc, char *argv[])
{
  int i, pid, prio;

  for (i = 0; i < LOTS; i++)
  {
    pid = fork();
    if (pid > 0)
      continue;

    pid = getpid();
    prio = pid % NQUEUES;
    set_prio(prio);
    do_work();
    printf(1, "Process with priority %d exiting.\n", prio);
    exit();
  }

  for(; i > 0; i--)
    wait();

  exit();
}
