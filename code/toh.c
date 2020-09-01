//
//  toh.c
//  
//
//  Created by DLRL on 28/11/19.
//

#include<stdio.h>
void towerOfHanoi(int n, char from_rod, char to_rod, char target_rod)
{
    if (n == 1)
    {
        printf("\nDisk 1 %c to %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, target_rod, to_rod);
    printf("\nDisk %d %c to %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, target_rod, to_rod, from_rod);
}
  
int main()
{
    int n;
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
