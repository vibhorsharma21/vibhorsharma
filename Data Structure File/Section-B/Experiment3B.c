#include <stdio.h>

// Function to implement the Tower of Hanoi solution
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        // Base case: If there is only one disk, move it from source to destination
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move top n-1 disks from source to auxiliary peg
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth (largest) disk from source to destination peg
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move the n-1 disks from auxiliary peg to destination peg
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    // Input: number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Call the towerOfHanoi function to solve the problem
    printf("The steps to solve the Tower of Hanoi are:\n");
    towerOfHanoi(n, 'A', 'B', 'C'); // A, B, C are the names of the source, auxiliary, and destination pegs

    return 0;
}
