#include <stdio.h>

void towerOfHanoi(int numDisks, char source, char auxiliary, char destination) {
    if (numDisks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(numDisks - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", numDisks, source, destination);
    towerOfHanoi(numDisks - 1, auxiliary, source, destination);
}

int main() {
    int numDisks ;  // Number of disks
    scanf("%d",&numDisks);
    char source = 'A', auxiliary = 'B', destination = 'C';

    printf("Steps to solve the Tower of Hanoi with %d disks:\n", numDisks);
    towerOfHanoi(numDisks, source, auxiliary, destination);

    return 0;
}
