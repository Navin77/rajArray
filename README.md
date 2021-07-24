# rajArray
header-only C library to manage dynamic arrays.

## Installation
1. download this source code.
2. open the terminal and go to directory where you downloaded.
3. run ``` sudo ./install.sh ```

## Usage
To manage array of integers
```c
#include <rajArray.h>

int main()
{
 //create array
 intArr arrOfInts;
 initArr(arrOfInts, int);
 
 pushArr(34, int, arrOfInts); //this will push 34 to arrOfInts

 int number;
 popArr(number, arrOfInts); //this will pop a element from arrOfInts and store it in number

 //to use in for loops
 for(size_t i = 0; i < arrOfInts.count; i++)
 {
  number = arrOfInts.arr[i];
 }

 //finally free memory
 freeArr(arrOfInts);

 return 0;
}
```
## Concept
A array is a structure which contains array of elements and number of elements in array.
```c
typedef struct intArr
{
    int* arr;
    size_t count;
} intArr;
```
This library contains data types for managing dynamic arrays for common C data types. refer source code.

It eases pushing and popping a element into array.