#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *p1, const void *p2)
{
        const int a = *( const int **)p1;
    const int b = *(const int **)p2;
//printf("count2: %d\n", a);
//printf("count2: %d\n", b);
    if ( a > b ) return -1;
    if ( a < b ) return +1;
    return 0;
}


int main(int argc, char *argv[]){

int count[10][2] = { {-1,0},{-3,1},{-2,2},{-4,3},
                {-5,4},{-4,5},{-17,6},{-8,7},{-9,8},{-11,9} };
qsort(count, 10, sizeof (int*), compare);
//printf("count1: %d\n", count[0][1]);
//printf("count1: %d\n", count[1][1]);
//compare(count[0],count[1]);
for(int i = 0; i < 10; i++) {
   printf("row: %d, ", count[i][1]);
   printf("Count: %d\n",count[i][0]);
}
return 0;

}
