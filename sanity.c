#include "types.h"
#include "user.h"

enum types { CPU, SCPU, IO, NUMTYPES };

void run_cpu_bound_process();
void run_light_cpu_bound_process();
void run_io_bound_process();

struct totals
{
  int stime;
  int retime;
  int rutime;
};

void
sanity(int n)
{
  int pid, i, type;
  struct totals totalsByType[NUMTYPES];

  for (type = 0; type < NUMTYPES; type++)
  {
    totalsByType[type].stime = 0;
    totalsByType[type].retime = 0;
    totalsByType[type].rutime = 0;
  }

  for (i = 0; i < NUMTYPES*n; i++)
  {
    pid = fork();

    if (pid > 0)
      continue;

    pid = getpid();
    type = pid % NUMTYPES;

    switch(type)
    {
      case CPU:
        run_cpu_bound_process();
        break;
      case SCPU:
        run_light_cpu_bound_process();
        break;
      case IO:
        run_io_bound_process();
        break;
    }

    totalsByType[type].stime += getstime();
    totalsByType[type].retime += getretime();
    totalsByType[type].rutime += getrutime();

    exit();
  }

  for (; i > 0; i--)
  {
    wait();
  }

  for (type = 0; type < NUMTYPES; type++)
  {
    switch(type)
    {
      case CPU:
        printf(1, "Stats for CPU-boud processes:\n");
        break;
      case SCPU:
        printf(1, "Stats for short-task based CPU-bound processes:\n");
        break;
      case IO:
        printf(1, "Stats for IO-bound processes:\n");
        break;
    }
    
    printf(1, "Average time spent sleeping: %d\n", (totalsByType[type].stime / n));
    printf(1, "Average time spent ready: %d\n", (totalsByType[type].retime / n));
    printf(1, "Average time spent running: %d\n", (totalsByType[type].rutime / n));
  }
}

void
run_cpu_bound_process()
{
  int i, j;
  for (i = 0; i < 100; i++)
    for (j = 0; j < 1000000; j++)
      ;
}

void
run_light_cpu_bound_process()
{
  int i, j;
  for (i = 0; i < 100; i++)
  {
    for (j = 0; j < 1000000; j++)
      ;
    yield();
  }
}

void
run_io_bound_process()
{
  int i;
  for (i = 0; i < 100; i++)
    sleep(1);
}

int
main(int argc, char *argv[])
{
  int n;

  if(argc != 2){
    printf(2, "usage: sanity <n>\n");
    exit();
  }
  
  n = atoi(argv[1]);
  sanity(n);
  exit();
}
