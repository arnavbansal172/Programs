#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Allocation {
    string process;
    int size;
};

void contiguousAllocation(vector<int>& freeSpaceBlocks, vector<Allocation>& allocations, char allocationTechnique) {
    sort(freeSpaceBlocks.begin(), freeSpaceBlocks.end(), [](int a, int b) {
        return a > b;  // Descending order for Worst-Fit
    });

    for (const auto& allocation : allocations) {
        bool allocated = false;
        for (int i = 0; i < freeSpaceBlocks.size(); ++i) {
            if (freeSpaceBlocks[i] >= allocation.size) {
                // Update free space after allocation
                freeSpaceBlocks[i] -= allocation.size;
                allocated = true;
                break;
            }
        }

        if (!allocated) {
            cout << "Unable to allocate " << allocation.process << " of size " << allocation.size << endl;
        }
    }
}

void calculateFragmentation(vector<int>& freeSpaceBlocks, int& externalFragmentation, int& internalFragmentation) {
    for (const auto& block : freeSpaceBlocks) {
        if (block == 0) {
            externalFragmentation++;
        } else {
            internalFragmentation += block;
        }
    }
}

int main() {
    // Input free space list of blocks
    cout << "Enter the free space list of blocks (enter -1 to end input):" << endl;
    vector<int> freeSpaceBlocks;
    int block;
    while (true) {
        cin >> block;
        if (block == -1) break;
        freeSpaceBlocks.push_back(block);
    }

    // Input list of processes and files
    cout << "Enter the list of processes and files (process size, enter -1 to end input):" << endl;
    vector<Allocation> allocations;
    string process;
    int size;
    while (true) {
        cin >> process;
        if (process == "-1") break;
        cin >> size;
        allocations.push_back({process, size});
    }

    // Perform contiguous allocation for each technique
    cout << "Performing Worst-Fit Contiguous Allocation:" << endl;
    vector<int> worstFitFreeSpace = freeSpaceBlocks;
    contiguousAllocation(worstFitFreeSpace, allocations, 'W');

    cout << "Performing Best-Fit Contiguous Allocation:" << endl;
    vector<int> bestFitFreeSpace = freeSpaceBlocks;
    contiguousAllocation(bestFitFreeSpace, allocations, 'B');

    cout << "Performing First-Fit Contiguous Allocation:" << endl;
    vector<int> firstFitFreeSpace = freeSpaceBlocks;
    contiguousAllocation(firstFitFreeSpace, allocations, 'F');

    // Calculate fragmentation for each technique
    int worstFitExternalFragmentation = 0, worstFitInternalFragmentation = 0;
    calculateFragmentation(worstFitFreeSpace, worstFitExternalFragmentation, worstFitInternalFragmentation);

    int bestFitExternalFragmentation = 0, bestFitInternalFragmentation = 0;
    calculateFragmentation(bestFitFreeSpace, bestFitExternalFragmentation, bestFitInternalFragmentation);

    int firstFitExternalFragmentation = 0, firstFitInternalFragmentation = 0;
    calculateFragmentation(firstFitFreeSpace, firstFitExternalFragmentation, firstFitInternalFragmentation);

    // Display results
    cout << "Worst-Fit Contiguous Allocation:" << endl;
    cout << "Total External Fragmentation: " << worstFitExternalFragmentation << endl;
    cout << "Total Internal Fragmentation: " << worstFitInternalFragmentation << endl;

    cout << "Best-Fit Contiguous Allocation:" << endl;
    cout << "Total External Fragmentation: " << bestFitExternalFragmentation << endl;
    cout << "Total Internal Fragmentation: " << bestFitInternalFragmentation << endl;

    cout << "First-Fit Contiguous Allocation:" << endl;
    cout << "Total External Fragmentation: " << firstFitExternalFragmentation << endl;
    cout << "Total Internal Fragmentation: " << firstFitInternalFragmentation << endl;

    return 0;
}
