#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

//dynamic array structure for general types

typedef struct charArr
{
    char *arr;
    size_t count;
} charArr;

typedef struct shortArr
{
    short *arr;
    size_t count;
} shortArr;

typedef struct intArr
{
    int *arr;
    size_t count;
} intArr;

typedef struct longArr
{
    long *arr;
    size_t count;
} longArr;

typedef struct floatArr
{
    float *arr;
    size_t count;
} floatArr;

typedef struct doubleArr
{
    double *arr;
    size_t count;
} doubleArr;

//dynamic array structure for unsigned types

typedef struct ucharArr
{
    unsigned char *arr;
    size_t count;
} ucharArr;

typedef struct ushortArr
{
    unsigned short *arr;
    size_t count;
} ushortArr;

typedef struct uintArr
{
    unsigned int *arr;
    size_t count;
} uintArr;

typedef struct ulongArr
{
    unsigned long *arr;
    size_t count;
} ulongArr;

//array of character arrays
typedef struct stringArr
{
    charArr *arr;
    size_t count;
} stringArr;

/**
 * allocate memory
 * @param var name of the array variable
 * @param type data type of the variable
 */
#define initArr(var, type)          \
    var.arr = malloc(sizeof(type)); \
    var.count = 0;

/**
 * increment array count and increment the memory and push element
 * @param element element to push into array
 * @param type data type of the element
 * @param array array in which element to be pushed
 */
#define pushArr(element, type, array)                           \
    array.count += 1;                                           \
    array.arr = realloc(array.arr, array.count * sizeof(type)); \
    array.arr[array.count - 1] = element;

/**
 * increment array count and increment the memory and push element
 * @param element element to push into array
 * @param type data type of the element
 * @param array pointer to array in which element to be pushed
 */
#define pushArrP(element, type, array)                             \
    array->count += 1;                                             \
    array->arr = realloc(array->arr, array->count * sizeof(type)); \
    array->arr[array->count - 1] = element;

/**
 * increment array count and increment the memory and allocate memory for new chararr
 * and copy characters
 * @param element chararray to push
 * @param array array in which element to be pushed
 */
#define pushStr(element, array)                                            \
    array.count += 1;                                                      \
    array.arr = realloc(array.arr, array.count * sizeof(charArr));         \
    array.arr[array.count - 1].count = element.count;                      \
    array.arr[array.count - 1].arr = malloc(element.count * sizeof(char)); \
    strcpy(array.arr[array.count - 1].arr, element.arr);

/**
 * increment array count and increment the memory and allocate memory for new chararr
 * and copy characters
 * @param element chararray to push
 * @param array pointer to array in which element to be pushed
 */
#define pushStrP(element, array)                                             \
    array->count += 1;                                                       \
    array->arr = realloc(array->arr, array->count * sizeof(charArr));        \
    array->arr[array->count - 1].count = element.count;                      \
    array->arr[array->count - 1].arr = malloc(element.count * sizeof(char)); \
    strcpy(array->arr[array->count - 1].arr, element.arr);

/**
 * get the last element and decrement the array count
 * @param out variable to store poped element
 * @param array array to pop
 */
#define popArr(out, array)            \
    if (array.count != 0)             \
    {                                 \
        array.count -= 1;             \
        out = array.arr[array.count]; \
    }

/**
 * get the last element and decrement the array count
 * @param out variable to store poped element
 * @param array pointer to array to pop
 */
#define popArrP(out, array)             \
    if (array->count != 0)              \
    {                                   \
        array->count -= 1;              \
        out = array->arr[array->count]; \
    }

/**
 * de-allocate the memory of the given array
 * @param array array where memory to be deallocated
 */
#define freeArr(array) \
    free(array.arr);   \
    array.count = 0;

/**
 * de-allocate the memory of the given array
 * @param array pointer to array where memory to be deallocated
 */
#define freeArrP(array) \
    free(array->arr);   \
    array->count = 0;

/**
 * de-allocate the memory of the given array
 * @param array array where memory to be deallocated
 */
#define freeStrArr(array)                    \
    for (size_t i = 0; i < array.count; i++) \
    {                                        \
        free(array.arr[i].arr);              \
        array.arr[i].count = 0;              \
    }                                        \
    free(array.arr);                         \
    array.count = 0;

/**
 * de-allocate the memory of the given array
 * @param array pointer to array where memory to be deallocated
 */
#define freeStrArrP(array)                    \
    for (size_t i = 0; i < array->count; i++) \
    {                                         \
        free(array->arr[i].arr);              \
        array->arr[i].count = 0;              \
    }                                         \
    free(array->arr);                         \
    array->count = 0;