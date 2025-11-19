#include <stdio.h>

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, target, auxiliary);

    // Move the nth disk from source to target
    printf("Move disk %d from %c to %c\n", n, source, target);

    // Move n-1 disks from auxiliary to target
    towerOfHanoi(n - 1, auxiliary, source, target);
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("The sequence of moves:\n");
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
