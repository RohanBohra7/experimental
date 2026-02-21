#include<stdio.h>
#include<stdlib.h>

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
}