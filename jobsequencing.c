#include <stdio.h>

// Structure to represent a job
struct Job {
    char id;       
    int deadline;  
    int profit;    
};



int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    // Array of jobs
    struct Job jobs[n];
    printf("Enter details for each job (ID, Deadline, Profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    
    jobSequencing(jobs, n);

    return 0;
}

// Function to perform the job sequencing
void jobSequencing(struct Job jobs[], int n) {
    

    // Sort jobs based on their profits in non-increasing order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    // Array to keep track of slot availability
    int slot[n];
    for (int i = 0; i < n; i++)
        slot[i] = -1; // Initialize all slots as empty

    // Fill the slots
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Display the sequence 
    printf("Sequence of jobs: ");
    for (int i = 0; i < n; i++) {
        if (slot[i] != -1)
            printf("%c ", jobs[slot[i]].id);
    }
    printf("\nTotal profit: %d\n", totalProfit);
}
