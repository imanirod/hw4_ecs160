#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *p1, const void *p2)
{
        const int (*a)[2] = p1;
    const int (*b)[2] = p2;
    if ( (*a)[0] < (*b)[0] ) return -1;
    if ( (*a)[0] > (*b)[0] ) return +1;
    return 0;
}


int main(int argc, char *argv[]){

int count[10][2] = { (1,0),(2,1),(3,2),(4,3),
                (5,4),(4,5),(7,6),(8,7),(9,8),(11,9) };
//qsort(count, 10*2, sizeof count[0], compare);
for(int i = 0; i < 10; i++) {
   printf("Count: %d\n",count[i][0]);
}
return 0;
	
}
