#include <stdio.h>

int numProcesses = 5;  // Number of processes
int numResources = 3;  // Number of resource types

int available[3];  // Available resources
int maxClaim[5][3];  // Maximum claim of each process
int allocation[5][3];  // Resources allocated to each process

void calculateNeed(int need[5][3]) {
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = maxClaim[i][j] - allocation[i][j];
        }
    }
}

bool isSafeState(int need[5][3], int work[3], bool finish[5]) {
    bool safe = true;
    int workCopy[3];

    for (int i = 0; i < numResources; i++) {
        workCopy[i] = work[i];
    }

    for (int i = 0; i < numProcesses; i++) {
        if (!finish[i]) {
            bool canAllocate = true;
            for (int j = 0; j < numResources; j++) {
                if (need[i][j] > workCopy[j]) {
                    canAllocate = false;
                    break;
                }
            }

            if (canAllocate) {
                for (int j = 0; j < numResources; j++) {
                    workCopy[j] += allocation[i][j];
                }
                finish[i] = true;
            }
        }
    }

    for (int i = 0; i < numProcesses; i++) {
        if (!finish[i]) {
            safe = false;
            break;
        }
    }

    return safe;
}

bool requestResources(int process, int request[3]) {
    int need[5][3];
    calculateNeed(need);

    // Check if the request is less than or equal to the need
    for (int i = 0; i < numResources; i++) {
        if (request[i] > need[process][i]) {
            return false;
        }
    }

    // Check if the request is less than or equal to the available resources
    for (int i = 0; i < numResources; i++) {
        if (request[i] > available[i]) {
            return false;
        }
    }

    // Temporarily allocate the resources and update the state
    for (int i = 0; i < numResources; i++) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

    bool finish[5] = {false};
    if (isSafeState(need, available, finish)) {
        return true;  // Request is granted, and the system is in a safe state
    } else {
        // Request cannot be granted, so roll back the changes
        for (int i = 0; i < numResources; i++) {
            available[i] += request[i];
            allocation[process][i] -= request[i];
            need[process][i] += request[i];
        }
        return false;  // Request is denied to maintain system safety
    }
}

int main() {
    // Initialize available, maxClaim, and allocation matrices
    // ...

    // Example request for process 0
    int request[3] = {1, 0, 2};
    int requestingProcess = 0;

    if (requestResources(requestingProcess, request)) {
        printf("Request granted. System is in a safe state.\n");
    } else {
        printf("Request denied. Request would lead to an unsafe state.\n");
    }

    return 0;
}
