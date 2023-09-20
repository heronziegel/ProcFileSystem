#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Week 1

    // Create struct for flags, use getopt() to fill
    struct flags {
        int v_opt;
        int p_opt;
        int PID_opt;
        int c_opt;
        int U_opt;
        int S_opt;
        int s_opt;
    };

    // Create second struct for proc options
    struct proc {
        int pid;
        char state;
        char cmd[4096];
        unsigned int utime;
        unsigned int vtime;
    };

    // Parse proc/PID/stat

    // Parse proc/PID/statm

    // Parse proc/PID/cmdline

    exit(0);
}