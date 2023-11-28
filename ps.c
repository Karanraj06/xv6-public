#include "types.h"
#include "user.h"
#include "stat.h"
#include "param.h"

void print_infor(struct uproc p)
{
    static char *states[] = {
  [1]    "Unused",
  [2]    "Embryo",
  [3]  "Sleeping",
  [4]  "Runnable",
  [5]   "Running",
  [6]    "Zombie"
  };
    printf(1, "Name: %s ,PID: %d , PPID: %d , ", p.process_name, p.pid, p.ppid);
    printf(1, "Size: %d KB , ", p.size);
    printf(1, "State: %s , ", states[p.state]);
    printf(1, "Waiting : %s , Killed: %d ", p.iswait ? "Yes" : "No",p.iskilled);
}

int main(int argc, char *argv[])
{

    int pid = 1;
    struct uproc up;

    for (pid = 1; pid < NPROC; pid++)
    {
        if (getprocinfo(pid, &up) < 0)
        {
            continue;
        }
        else
        {
            printf(1, "\n----------------\n");
            printf(1, "Info for PID %d\n", pid);
            print_infor(up);
            printf(1, "\n----------------\n");
        }
    }
    exit();
}