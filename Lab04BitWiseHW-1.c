#include <stdio.h>
#include <stdlib.h>

unsigned int add(unsigned int, unsigned int);
unsigned int sub(unsigned int, unsigned int);
unsigned int mul(unsigned int, unsigned int);
unsigned int lt(unsigned int, unsigned int);
unsigned int gt(unsigned int, unsigned int);
unsigned int getByte(unsigned int, unsigned int);

int main(int argc, char **argv){

 unsigned int i, j;

 printf("Enter an integer i: ");
 scanf("%u", &i);
 printf("Enter another integer j: ");
 scanf("%u", &j);
 printf("\ni + j = %u\n", add(i,j));
 printf("i - j = %u\n", sub(i,j));
 printf("i * j = %u\n", mul(i,j));
 printf("i > j = %s\n", (gt(i,j) ? "TRUE" : "FALSE"));
 printf("i < j = %s\n", (lt(i,j) ? "TRUE" : "FALSE"));
 printf("jth byte of i = %ux\n", getByte(i,j));

 return 0;
}

unsigned int add(unsigned int i, unsigned int j){
    /* can be done in a total of 7 lines, including one to declare an unsigned int, */
    /* two for a while loop, and one for the return */

    /*unsigned int sum, carry;

    while(i != 0){
        carry = i & j;
        sum = i ^ j;
        i = carry << 1;
        j = sum;
    }
    return i + j;*/

    unsigned int x, sum, carry;
    x = i & j;
    sum = i ^ j;
    while(x != 0){
        carry = x << 1;
        x = sum & carry;
        sum ^= carry;
    }
    return sum;
}

unsigned int sub(unsigned int i, unsigned int j){
    /* Similar 7 lines, although there is a shorter way */
    j = add(~j, 1);
    return add(i,j);
}

unsigned int mul(unsigned int i, unsigned int j){
    /* can be done in a total of 8 lines including one to declare unsigned ints */
    /* two for a for loop, and one for the return */
    unsigned int x = 0;

    while (j){
        if(j & 1)
            x = add(x, i);
        i <<= 1;
        j >>= 1;
    }
    return x;
}

/* returns non-zero if i is less than j or zero otherwise ...
    it literally see who has a 1 at the start and thats the 
    greater then */
unsigned int lt(unsigned int i, unsigned int j){
    while (i != 0 && j != 0) {
		i = i >> 1;
		j = j >> 1;
	}
	return (i == 0) ? 1 : 0;
}

/* returns non-zero if i is greater than j or zero otherwise...
    it sees the later has a 1 and knows its the less than */
unsigned int gt(unsigned int i, unsigned int j){
	while (i != 0 && j != 0) {
		i = i >> 1;
		j = j >> 1;
	}
	return i;
}

/* returns the jth byte of i */
unsigned int getByte(unsigned int i, unsigned int j){
	int x;
    x = (i >> mul(8,j)) & 0x000000FF;
    return x;
} 