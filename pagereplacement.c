#include <stdio.h>

int main() {
    int n, rs[30], f, m[10], count = 0, pf_fifo = 0, pf_lru = 0, pf_lfu = 0;
    printf("\nEnter the length of page string: ");
    scanf("%d", &n);
    printf("Enter the reference page string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    for (int i = 0; i < f; i++) {
        m[i] = -1;
    }

    
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            m[count++] = rs[i];
            pf_fifo++;
            if (count == f) {
                count = 0;
            }
        }
    }
    printf("\nFirst Come First Serve (FIFO)\nNumber of page faults: %d\n", pf_fifo);

   
    for (int i = 0; i < f; i++) {
        m[i] = -1;
    }

   
    int time[10] = {0};
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                found = 1;
                time[j] = i;
                break;
            }
        }
        if (!found) {
            int least_used = 0;
            for (int j = 1; j < f; j++) {
                if (time[j] < time[least_used]) {
                    least_used = j;
                }
            }
            m[least_used] = rs[i];
            time[least_used] = i;
            pf_lru++;
        }
    }
    printf("\nLeast Recently Used (LRU)\nNumber of page faults: %d\n", pf_lru);

    
    for (int i = 0; i < f; i++) {
        m[i] = -1;
    }

    
    int count_lfu[10] = {0};
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                found = 1;
                count_lfu[j]++; 
                break;
            }
        }
        if (!found) {
            int least_used = 0;
            for (int j = 1; j < f; j++) {
                if (count_lfu[j] < count_lfu[least_used]) {
                    least_used = j;
                }
            }
            m[least_used] = rs[i];
            count_lfu[least_used] = 1; 
            pf_lfu++;
        }
    }
    printf("\nLeast Frequently Used (LFU)\nNumber of page faults: %d\n", pf_lfu);

 
}
