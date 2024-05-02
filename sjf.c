#include<stdio.h>

struct process {
    int id, at, bt, wt, tat, ct;
} arr[100];

void read(int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter the id, arrival time, and burst time of process %d\n", i + 1);
        scanf("%d %d %d", &arr[i].id, &arr[i].at, &arr[i].bt);
    }
}

void sort(int n) {
    struct process tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) { 
            if (arr[j].bt > arr[j + 1].bt) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void sjf(int n) {
    int tbt = 0, twt = 0, ttat = 0;
    arr[0].wt = 0;
    arr[0].ct = arr[0].bt + arr[0].at;
    if (arr[0].wt < 0) arr[0].wt = 0; // Adjusting negative waiting time
    ttat += arr[0].tat;
    tbt += arr[0].bt;
    for(int i = 1; i < n; i++) {
        arr[i].wt = tbt - arr[i].at;
        if (arr[i].wt < 0) arr[i].wt = 0; // Adjusting negative waiting time
        arr[i].tat = arr[i].bt - arr[i].wt;
        if (arr[i].tat < 0) arr[i].tat = 0; // Adjusting negative turnaround time
        arr[i].ct = arr[i].bt + arr[i].wt + arr[i].at;
        tbt += arr[i].bt;
        ttat += arr[i].tat;
        twt += arr[i].wt;
    }
    float avg_wt = (float)twt / n;
    float avg_tat = (float)ttat / n;
    printf("Average waiting time: %.2f\n", avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tat);
}


int main() {
    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    read(n);
    sort(n);
    sjf(n);

    printf("id \t at \t bt\t tat \t ct\t wt\t\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t %d\t %d\t %d\t %d\t %d\t \n", arr[i].id, arr[i].at, arr[i].bt, arr[i].tat, arr[i].ct, arr[i].wt);
    }
}

