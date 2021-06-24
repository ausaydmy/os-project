#include <stdio.h>

const int process = 5;
const int resourc = 3;

bool checkState(int processes[], int available[], int maximum[][resourc], int allocated[][resourc]) {
    int needed[process][resourc];
    

    for (int i = 0; i < process; i++)
        for (int j = 0; j < resourc; j++)
            needed[i][j] = maximum[i][j] - allocated[i][j];

    bool finished[process] = {0};
    int safeSequence[process] = {0};
    
    int work[resourc];
    for (int i = 0; i < resourc; i++) 
        work[i] = available[i];
    
    int count = 0;
    while (count < process) {
        bool found = false;
        for (int i = 0; i < process; i++) {
            if(finished[i] == 0) {
                int j;
                for (j = 0; j < resourc; j++)
                    if (needed[i][j] > work[j])
                        break;
                if (j == resourc) {
                    for (int k = 0; k < resourc; k++)
                        work[k] += allocated[i][k];

                    safeSequence[count++] = i;
                    finished[i] = 1;
                    found = true;
                }
            }
        }
        if (found == false) {
            printf("Not in safe state, Unsuccessful");
            return false;
        }
    }

    printf("System is in safe state and is successfull\n");
    printf("Sequence is: ");
    for (int i = 0; i < process; i++)
        printf("Process %i, ", safeSequence[i]);

    return true;
}

int main() {
    int processes[] = {0, 1, 2, 3, 4};
    int available[] = {10, 5, 7};
    int maximum[][resourc] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int allocated[][resourc] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};

    checkState(processes, available, maximum, allocated);


    int input[4];
    while (true) {
    printf("\nEnter Input (thread, {input}):\n");
    scanf("%i %i %i %i", &input[0],&input[1],&input[2],&input[3]);
    for (int i = 1; i < resourc + 1; i++)
        maximum[input[0] - 1][i - 1] = input[i];
        // printf("%i", input[i]);

    printf("Max:");
    for (int i = 0; i < process; i++) {
        printf("\n| ");
        for (int j = 0; j < resourc; j++)
            printf("%i ", maximum[i][j]);
        printf("|");
    }
    printf("\nAllocated:\n");
    for (int i = 0; i < process; i++) {
        printf("| ");
        for (int j = 0; j < resourc; j++)
            printf("%i ", allocated[i][j]);
        printf("|\n");
    }
    
    printf("\n");
    checkState(processes, available, maximum, allocated);
    }


}
