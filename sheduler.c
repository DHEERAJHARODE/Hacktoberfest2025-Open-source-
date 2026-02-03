// AUTHOR:- SRJ1906359

// Sheduler.c program of operating system


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FCFS_SCHED 0                    // constant to represent the first come, first served algorithm
#define SJF_SCHED 1                     // constant to represent the shortest job first algorithm
#define PRI_SCHED 2                     // constant to represent the priority based algorithm
#define RR_SCHED 3                      // constant to represent the round-robin algorithm

#define PREEMT 0                        // constant to represent if preemption is used
#define NO_PREEMT 1                     // constant to represent if no preemption is used

#define NO_PROCESS 99                   // constant to use when there is no available process to be executed
#define MAX_BURST_TIME 99999            // constant to represent the maximum burst time
#define MAX_ORDER_OR_PRIORITY 99999     // constant to represent the maximum order or priority

// Author: Prof. Jyotiprakash Mishra
// Assistant Professor (II)
// Kalinga Institute of Industrial Technology, Deemed to be University
// Copyright (c) 2021 Jyotiprakash Mishra

typedef struct {
    int process_order;              // order of process arrival. lower numbers mean earlier arrival. must be unique.
    int process_arrival_time;       // arrival time
    int process_priority;           // priority. lower numbers mean higher priority. must be unique.
    int how_much_left;              // CPU time left to complete the process
    int waiting_time;               // how much the process has waited without attention from the CPU
    int response_time;              // how much the process has waited until first attention from the CPU
    int turnaround_time;            // process finish time - process arrival time
    int has_run_at_least_once;      // used to track if the process has already run at least once. used for calculating response times.
    int has_terminated;             // used to track if a process has terminated.
    int time_slice_left;            // used by the round-robin scheduler for tracking how many quanta of time is left for the current slice
    int process_number;             // used to store the process number, just in case we need to sort the process list by some criterion and need to
    // track back to the original process numbers
} pinfo;

pinfo **allocate_mem_for_process_list(int length, int only_outer) {
    pinfo **pinfos = malloc(sizeof(pinfo *) * length);
    if (!only_outer) {
        for (int i = 0; i < length; ++i) {
            pinfos[i] = (pinfo *) malloc(sizeof(pinfo));
        }
    }
    return pinfos;
}

void deallocate_mem_for_process_list(pinfo **pinfos, int length, int only_outer) {
    if (!only_outer) {
        for (int i = 0; i < length; ++i) {
            free(pinfos[i]);
        }
    }
    free(pinfos);
}

void take_input(pinfo ***pinfos_out, int *pinfos_len, int *algorithm, int *preemptive, int *quantum) {
    int nprocs;
    char algo[5];
    char preempt[4];
    pinfo **pinfos = NULL;

    printf("Enter the algorithm (fcfs, sjf, pri, rr): ");
    scanf("%s", algo);

    if (strcmp(algo, "fcfs") == 0) {
        *algorithm = FCFS_SCHED;
    } else if (strcmp(algo, "sjf") == 0) {
        *algorithm = SJF_SCHED;
    } else if (strcmp(algo, "pri") == 0) {
        *algorithm = PRI_SCHED;
    } else if (strcmp(algo, "rr") == 0) {
        *algorithm = RR_SCHED;
    } else {
        exit(1);
    }

    if (*algorithm == SJF_SCHED || *algorithm == PRI_SCHED) {
        printf("Is it preemptive (yes/no)? ");
        scanf("%s", preempt);
    }

    if (strcmp(preempt, "yes") == 0) {
        *preemptive = PREEMT;
    } else if (strcmp(preempt, "no") == 0) {
        *preemptive = NO_PREEMT;
    }

    if (*algorithm == RR_SCHED) {
        printf("Enter time quantum: ");
        scanf("%d", quantum);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &nprocs);
    *pinfos_len = nprocs;

    pinfos = allocate_mem_for_process_list(nprocs, 0);

    for (int i = 0; i < nprocs; ++i) {
        printf("\n");
        pinfos[i]->process_priority = 0;
        pinfos[i]->waiting_time = 0;
        pinfos[i]->response_time = 0;
        pinfos[i]->turnaround_time = 0;
        pinfos[i]->has_run_at_least_once = 0;
        pinfos[i]->has_terminated = 0;
        pinfos[i]->process_number = i;

        if (*algorithm == PRI_SCHED) {
            printf("Enter priority of P%d: ", i);
            scanf("%d", &pinfos[i]->process_priority);
        }

        if ((*algorithm == FCFS_SCHED) || (*algorithm == RR_SCHED)) {
            printf("Enter order of arrival of P%d: ", i);
            scanf("%d", &pinfos[i]->process_order);
        }

        printf("Enter time of arrival of P%d: ", i);
        scanf("%d", &pinfos[i]->process_arrival_time);

        printf("Enter burst time of P%d: ", i);
        scanf("%d", &pinfos[i]->how_much_left);
    }

    if (*algorithm == RR_SCHED) {
        for (int i = 0; i < *pinfos_len; ++i) {
            pinfos[i]->time_slice_left = *quantum;
        }
    }

    *pinfos_out = pinfos;
    printf("\n");
}

void display_output(pinfo **pinfos, int pinfos_len, int context_switches) {
    printf("\n");
    for (int i = 0; i < pinfos_len; ++i) {
        printf("\nP%d response time: %d\n", i, pinfos[i]->response_time);
        printf("P%d waiting time: %d\n", i, pinfos[i]->waiting_time);
        printf("P%d turnaround time: %d\n", i, pinfos[i]->turnaround_time);
    }
    printf("\nNumber of Context Switches: %d\n", context_switches);
}

int has_process_arrived(pinfo **pinfos, int process, int time) {
    if (process == NO_PROCESS)
        return 1;
    return pinfos[process]->process_arrival_time <= time;
}

int has_process_finished(pinfo **pinfos, int process) {
    if (process == NO_PROCESS)
        return 1;
    return pinfos[process]->has_terminated;
}

int is_process_available_to_run(pinfo **pinfos, int process, int time) {
    return has_process_arrived(pinfos, process, time) && !has_process_finished(pinfos, process);
}

int next_unfinished_arrived_process_by_order(pinfo **pinfos, int pinfos_len, int current_process, int time) {
    int processes_checked = 0;
    int min_order = MAX_ORDER_OR_PRIORITY;
    int min_process = NO_PROCESS;
    while (processes_checked < pinfos_len) {
        current_process = (current_process + 1) % pinfos_len;
        if (is_process_available_to_run(pinfos, current_process, time))
            if (pinfos[current_process]->process_order < min_order) {
                min_process = current_process;
                min_order = pinfos[current_process]->process_order;
            }
        ++processes_checked;
    }
    return min_process;
}

int next_unfinished_arrived_process_by_priority(pinfo **pinfos, int pinfos_len, int current_process, int time) {
    int processes_checked = 0;
    int min_priority = MAX_ORDER_OR_PRIORITY;
    int min_process = NO_PROCESS;
    while (processes_checked < pinfos_len) {
        current_process = (current_process + 1) % pinfos_len;
        if (is_process_available_to_run(pinfos, current_process, time))
            if (pinfos[current_process]->process_priority < min_priority) {
                min_process = current_process;
                min_priority = pinfos[current_process]->process_priority;
            }
        ++processes_checked;
    }
    return min_process;
}

int next_unfinished_arrived_process_by_shortest_time_remaining(pinfo **pinfos, int pinfos_len, int current_process,int time) {
    int processes_checked = 0;
    int min_process_time = MAX_BURST_TIME;
    int min_process = NO_PROCESS;
    while (processes_checked < pinfos_len) {
        current_process = (current_process + 1) % pinfos_len;
        if (is_process_available_to_run(pinfos, current_process, time))
            if (pinfos[current_process]->how_much_left < min_process_time) {
                min_process = current_process;
                min_process_time = pinfos[current_process]->how_much_left;
            }
        ++processes_checked;
    }
    return min_process;
}

int next_unfinished_arrived_process_by_order_for_rr(pinfo **pinfos, int pinfos_len, int current_process, int time) {
    int processes_checked = 0;
    while (processes_checked < pinfos_len) {
        current_process = (current_process + 1) % pinfos_len;
        if (is_process_available_to_run(pinfos, current_process, time))
            return current_process;
        ++processes_checked;
    }
    return NO_PROCESS;
}

int order_comparator(const void *x, const void *y) {
    pinfo *x_ptr = *(pinfo **) x;
    pinfo *y_ptr = *(pinfo **) y;
    int x_order = x_ptr->process_order;
    int y_order = y_ptr->process_order;
    return (x_order - y_order);
}

void sort_by_order(pinfo **pinfos, int pinfos_len) {
    qsort((void **) pinfos, pinfos_len, sizeof(pinfo *), order_comparator);
}

int fcfs(int last_process_running, pinfo **pinfos, int pinfos_len, int time) {
    if (!has_process_finished(pinfos, last_process_running))
        return last_process_running;
    else return next_unfinished_arrived_process_by_order(pinfos, pinfos_len, last_process_running, time);
}

int sjf_nonpreempt(int last_process_running, pinfo **pinfos, int pinfos_len, int time) {
    if (!has_process_finished(pinfos, last_process_running))
        return last_process_running;
    else
        return next_unfinished_arrived_process_by_shortest_time_remaining(pinfos, pinfos_len, last_process_running,
                                                                          time);
}

int sjf_preempt(int last_process_running, pinfo **pinfos, int pinfos_len, int time) {
    return next_unfinished_arrived_process_by_shortest_time_remaining(pinfos, pinfos_len, last_process_running, time);
}

int pri_nonpreempt(int last_process_running, pinfo **pinfos, int pinfos_len, int time) {
    if (!has_process_finished(pinfos, last_process_running))
        return last_process_running;
    else return next_unfinished_arrived_process_by_priority(pinfos, pinfos_len, last_process_running, time);
}

int pri_preempt(int last_process_running, pinfo **pinfos, int pinfos_len, int time) {
    return next_unfinished_arrived_process_by_priority(pinfos, pinfos_len, last_process_running, time);
}

int rr(int last_process_running, pinfo **pinfos, int pinfos_len, int quantum, int time, int *context_switches) {
    pinfo **sorted_pinfos = allocate_mem_for_process_list(pinfos_len, 1);
    for (int i = 0; i < pinfos_len; ++i)
        sorted_pinfos[i] = pinfos[i];
    sort_by_order(sorted_pinfos, pinfos_len);

    if (last_process_running != NO_PROCESS) {
        if (is_process_available_to_run(pinfos, last_process_running, time)) {
            if (--pinfos[last_process_running]->time_slice_left) {
                deallocate_mem_for_process_list(sorted_pinfos, pinfos_len, 1);
                return last_process_running;
            } else {
                pinfos[last_process_running]->time_slice_left = quantum;
                ++*context_switches;
                printf("Context switch after time slice expired\n");
            }
        } else if (pinfos[last_process_running]->time_slice_left) {
            ++*context_switches;
            printf("Context switch after process finished but time slice still left\n");
        }
    }

    int last_process_running_in_sorted_pinfos = -1;
    for (int i = 0; i < pinfos_len; ++i) {
        if (sorted_pinfos[i]->process_number == last_process_running) {
            last_process_running_in_sorted_pinfos = i;
            break;
        }
    }

    int to_return = next_unfinished_arrived_process_by_order_for_rr(sorted_pinfos, pinfos_len,
                                                                    last_process_running_in_sorted_pinfos, time);

    if (to_return == NO_PROCESS) {
        deallocate_mem_for_process_list(sorted_pinfos, pinfos_len, 1);
        return to_return;
    } else {
        to_return = sorted_pinfos[to_return]->process_number;
        if (last_process_running == NO_PROCESS) {
            ++*context_switches;
            printf("Context switch transfer from NO PROCESS to a concrete process\n");
        }
        deallocate_mem_for_process_list(sorted_pinfos, pinfos_len, 1);
        return to_return;
    }
}

int next_process_to_run(int last_process_running, pinfo **pinfos, int pinfos_len, int algorithm, int preemptive, int time,int quantum, int *context_switches) {
    switch (algorithm) {
        case FCFS_SCHED:
            return fcfs(last_process_running, pinfos, pinfos_len, time);
        case SJF_SCHED:
            switch (preemptive) {
                case NO_PREEMT:
                    return sjf_nonpreempt(last_process_running, pinfos, pinfos_len, time);
                case PREEMT:
                    return sjf_preempt(last_process_running, pinfos, pinfos_len, time);
                default:
                    return NO_PROCESS;
            }
        case PRI_SCHED:
            switch (preemptive) {
                case NO_PREEMT:
                    return pri_nonpreempt(last_process_running, pinfos, pinfos_len, time);
                case PREEMT:
                    return pri_preempt(last_process_running, pinfos, pinfos_len, time);
                default:
                    return NO_PROCESS;
            }
        case RR_SCHED:
            return rr(last_process_running, pinfos, pinfos_len, quantum, time, context_switches);
        default:
            return NO_PROCESS;
    }
}

void run_process_and_update_structs(int process_to_run, pinfo **pinfos, int pinfos_len, int *time) {
    if (process_to_run != NO_PROCESS) {
        --pinfos[process_to_run]->how_much_left;
        pinfos[process_to_run]->has_run_at_least_once = 1;
        if (pinfos[process_to_run]->how_much_left <= 0) {
            pinfos[process_to_run]->has_terminated = 1;
            pinfos[process_to_run]->turnaround_time = *time - pinfos[process_to_run]->process_arrival_time + 1;
        }
    }

    for (int i = 0; i < pinfos_len; ++i) {
        if (i == process_to_run)
            continue;

        if (has_process_arrived(pinfos, i, *time) && (!pinfos[i]->has_run_at_least_once)) {
            ++pinfos[i]->response_time;
        }

        if (has_process_arrived(pinfos, i, *time) && (!pinfos[i]->has_terminated)) {
            ++pinfos[i]->waiting_time;
        }
    }
    ++*time;
}

int all_processes_have_finished(pinfo **pinfos, int pinfos_len) {
    for (int i = 0; i < pinfos_len; ++i) {
        if (!pinfos[i]->has_terminated)
            return 0;
    }
    return 1;
}

int main() {
    pinfo **pinfos = NULL;
    int pinfos_len, time = 0, next_process = NO_PROCESS, algorithm, preemptive, context_switches = 0, previous_process, quantum;

    take_input(&pinfos, &pinfos_len, &algorithm, &preemptive, &quantum);

    while (!all_processes_have_finished(pinfos, pinfos_len)) {
        previous_process = next_process;
        next_process = next_process_to_run(next_process, pinfos, pinfos_len, algorithm, preemptive, time, quantum,&context_switches);
        if (next_process == NO_PROCESS && previous_process != NO_PROCESS && algorithm != RR_SCHED) {
            printf("Context switch from a concrete process to NO PROCESS\n");
            ++context_switches;
        } else if (next_process != NO_PROCESS && previous_process == NO_PROCESS && algorithm != RR_SCHED) {
            printf("Context switch from NO PROCESS to a concrete process\n");
            ++context_switches;
        } else if (next_process != NO_PROCESS && previous_process != NO_PROCESS && next_process != previous_process && algorithm != RR_SCHED) {
            printf("Context switch from one process to another\n");
            ++context_switches;
        }
        if (next_process == NO_PROCESS)
            printf("From time = %d to time = %d. No Process\n", time, time + 1);
        else
            printf("From time = %d to time = %d. Running P%d\n", time, time + 1, next_process);
        run_process_and_update_structs(next_process, pinfos, pinfos_len, &time);
    }

    display_output(pinfos, pinfos_len, context_switches);
    deallocate_mem_for_process_list(pinfos, pinfos_len, 0);
}
