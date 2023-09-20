#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if(argc > 8){
        perror("too many arguments");
        exit(1);
    }

    // Create struct for flags, use getopt() to fill
    struct flags {
        int v_opt; // turn on virtual memory information
        int p_opt; // require PID
        int PID_opt; // print only the file with this PID
        int c_opt; // turn off command line information
        int U_opt; // turn off utime information
        int S_opt; // turn on stime information
        int s_opt; // turn on state information
    } flagStruct = {0,0,0,1,1,0,0};

    int c;
    while ((c = getopt (argc, argv, "vcUSsp:")) != -1)
        switch (c)
        {
        case 'v':
            flagStruct.v_opt = 1;
            break;
        case 'p':
            flagStruct.p_opt = 1;
            flagStruct.PID_opt = atoi(optarg);
            break;
        case 'c':
            flagStruct.c_opt = 0;
            break;
        case 'U':
            flagStruct.U_opt = 0;
            break;
        case 'S':
            flagStruct.S_opt = 1;
            break;
        case 's':
            flagStruct.s_opt = 1;
            break;
        case '?':
            if (optopt == 'p')
            fprintf (stderr, "Option -%c requires an argument.\n", optopt);
            else if (isprint (optopt))
            fprintf (stderr, "Unknown option `-%c'.\n", optopt);
            else
            fprintf (stderr,
                    "Unknown option character `\\x%x'.\n",
                    optopt);
            exit(1);
        default:
            abort ();
        }

        // printf("Struct values:");
        // printf("\nv_opt: %d", flagStruct.v_opt);
        // printf("\np_opt: %d", flagStruct.p_opt);
        // printf("\nPID_opt: %d", flagStruct.PID_opt);
        // printf("\nc_opt: %d", flagStruct.c_opt);
        // printf("\nU_opt: %d", flagStruct.U_opt);
        // printf("\nS_opt: %d", flagStruct.S_opt);
        // printf("\ns_opt: %d", flagStruct.s_opt);


    // Create second struct to capture process information
    struct proc {
        int pid;
        char state;
        char cmd[4096];
        unsigned int utime;
        unsigned int vtime;
    };

    if(flagStruct.p_opt == 1){
        // If PID specified, get info for that process
    } else {
        // Else iterate through all processes
    }

    // Parse proc/PID/stat

    // Parse proc/PID/statm

    // Parse proc/PID/cmdline

    exit(0);
}