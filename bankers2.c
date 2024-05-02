#include<stdio.h>
#define max_resource 2
#define max_process 2

int need[max_process][max_resource];
int available[max_resource];
int allocation[max_process][max_resource];
int need_sum[max_resource];
int work[max_resource], finish[max_process];

int is_safe() {
    int i, j, k, flag;
    for (i = 0; i < max_process; i++) {
        if (finish[i] == 0) {
            flag = 1;
            for (k = 0; k < max_resource; k++) {
                if (need[i][k] > work[k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                for (k = 0; k < max_resource; k++) {
                    work[k] += allocation[i][k];
                }
                finish[i] = 1;
            }
        }
    }
    for (i = 0; i < max_process; i++) {
        if (finish[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i, j;
    printf("Enter allocation matrix:\n");
    for (i = 0; i < max_process; i++) {
        for (j = 0; j < max_resource; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter need matrix:\n");
    for (i = 0; i < max_process; i++) {
        for (j = 0; j < max_resource; j++) {
            scanf("%d", &need[i][j]);
        }
    }
    printf("Enter the available vector:\n");
    for (i = 0; i < max_resource; i++) {
        scanf("%d", &available[i]);
    }
    for (i = 0; i < max_process; i++) {
        for (j = 0; j < max_resource; j++) {
            need_sum[j] += need[i][j];
        }
    }
    for (i = 0; i < max_resource; i++) {
        if (available[i] < need_sum[i]) {
            printf("System is in an unsafe state\n");
            return 0;
        }
    }
    for (i = 0; i < max_process; i++) {
        finish[i] = 0;
        for (j = 0; j < max_resource; j++) {
            work[j] = available[j];
        }
       
    }
     if (is_safe() == 1) {
            printf("System is in a safe state\n");
        } else {
            printf("System is in an unsafe state\n");
        }
    return 0;
}

