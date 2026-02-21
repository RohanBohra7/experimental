#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int BT[n],waiting_time[n],turnaround_time[n],arrival_time[n],avg_waiting_time = 0, avg_turnaround_time = 0;


    for(i = 0; i < n; i++){
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }


    printf("Enter the burst time for each process:\n");
    for(i = 0; i < n; i++){
        printf("Process %d: ", i + 1);
        scanf("%d", &BT[i]);
    }

    waiting_time[0] = 0;

    
    if(arrival_time[0] > 0){
        waiting_time[0] = arrival_time[0];
    }

    for(i = 1; i < n; i++){
        if(arrival_time[i] > arrival_time[i - 1] + BT[i - 1]){
            waiting_time[i] = arrival_time[i] - (arrival_time[i - 1] + BT[i - 1]);
        } else {
            waiting_time[i] = waiting_time[i - 1] + BT[i - 1];
        }
    }
    
    for(i = 1; i < n; i++){
        waiting_time[i] = waiting_time[i - 1] + BT[i - 1];
    }

    
    for(i = 0; i < n; i++){
        turnaround_time[i] = waiting_time[i] + BT[i];
    }

    
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, BT[i], waiting_time[i], turnaround_time[i]);
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\nAverage Waiting Time: %.2f\n", (float)avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", (float)avg_turnaround_time);
    
    return 0;   
}