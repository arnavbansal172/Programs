#include <iostream>
#include <vector>

const int numProcesses = 5;  // Number of processes
const int numResources = 3;  // Number of resource types

int available[numResources];  // Available resources
int maxClaim[numProcesses][numResources];  // Maximum claim of each process
int allocation[numProcesses][numResources];  // Resources allocated to each process

// Calculate the Need matrix
void calculateNeed(int need[numProcesses][numResources]) {
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = maxClaim[i][j] - allocation[i][j];
        }
    }
}

// Check if granting a request would lead to an unsafe state
bool isSafeState(int need[numProcesses][numResources], int work[numResources], bool finish[numProcesses]) {
    bool safe = true;
    int workCopy[numResources];

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

// Request resources for a process
bool requestResources(int process, int request[numResources]) {
    int need[numProcesses][numResources];
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

    bool finish[numProcesses] = {false};
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
        std::cout << "Request granted. System is in a safe state." << std::endl;
    } else {
        std::cout << "Request denied. Request would lead to an unsafe state." << std::endl;
    }

    return 0;
}
