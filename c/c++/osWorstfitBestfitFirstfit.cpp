#include<iostream>
using namespace std;

// Function to allocate memory using Worst Fit strategy
void worstFit(int blocks[], int processes[], int n, int m) {
    for (int i=0; i < m; i++) {
        int idx = -1;

        // Iterate through available blocks to find the one with the worst fit
        for (int j=0; j < n; j++) {
            if (blocks[j] >= processes[i]) {
                if (idx == -1)
                    idx = j;
                else if (blocks[idx] < blocks[j])
                    idx = j;
            }
        }

        // If a block is found, allocate memory to the process and update block size
        if (idx != -1) { 
            blocks[idx] -= processes[i];
            cout << "Process " << i+1 << " allocated to block " << idx+1 << endl;
        } else {
            // If no suitable block is found, print a message
            cout << "Not enough memory to allocate Process " << i+1 << endl;
        }
    }
}

// Function to allocate memory using Best Fit strategy
void bestFit(int blocks[], int processes[], int n, int m) {
    for (int i=0; i < m; i++) {
        int idx = -1;

        // Iterate through available blocks to find the one with the best fit
        for (int j=0; j < n; j++) {
            if (blocks[j] >= processes[i]) {
                if (idx == -1)
                    idx = j;
                else if (blocks[idx] > blocks[j])
                    idx = j;
            }
        }

        // If a block is found, allocate memory to the process and update block size
        if (idx != -1) { 
            blocks[idx] -= processes[i];
            cout << "Process " << i+1 << " allocated to block " << idx+1 << endl;
        } else {
            // If no suitable block is found, print a message
            cout << "Not enough memory to allocate Process " << i+1 << endl;
        }
    }
}

// Function to allocate memory using First Fit strategy
void firstFit(int blocks[], int m, int processes[], int n) {
    for (int i = 0; i < n; i++) {
        int idx = -1;

        // Iterate through available blocks to find the first one that fits
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                idx = j;
                break;
            }
        }

        // If a block is found, allocate memory to the process and update block size
        if (idx != -1) {
            blocks[idx] -= processes[i];
            cout << "Process " << i+1 << " allocated to block " << idx+1 << endl;
        } else {
            // If no suitable block is found, print a message
            cout << "Not enough memory to allocate Process " << i+1 << endl;
        }
    }
}

// Main function
int main() {
    // Example data: memory blocks and processes
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    int m = sizeof(blocks)/sizeof(blocks[0]);
    int n = sizeof(processes)/sizeof(processes[0]);

    // Allocate memory using Worst Fit, Best Fit, and First Fit strategies
    cout<<"Worst Fit output"<<endl;
    worstFit(blocks, processes, m, n);
    cout<<"Best Fit output"<<endl;
    bestFit(blocks, processes, m, n);
    cout<<"First Fit output"<<endl;
    firstFit(blocks, m, processes, n);

    return 0;
}
