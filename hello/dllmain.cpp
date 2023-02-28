#include "pch.h"
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define DLL_EXPORT extern "C" __declspec(dllexport)
#define CALL __cdecl


/*

DLL_EXPORT int CALL add(int a, int b);
DLL_EXPORT int CALL str(char* s, char s1[255]);
DLL_EXPORT int CALL str2(wchar_t* s, wchar_t s1[255]);
DLL_EXPORT float CALL number(float a, double b);
DLL_EXPORT int CALL swap(int* a, int* b, int& c);
DLL_EXPORT int CALL array(int arr1[], int arr1Len, int arr2[][4], int arr2Len);

*/


typedef struct
{
    char name[255];
    int age;
} student;

typedef void(*Callback)(int);
typedef int(*getNextValue)(int);

DLL_EXPORT int* CALL TestCallback2(int* arr, int arrSize, getNextValue fun) {
    for (int i= 0; i < arrSize; i++) {
        arr[i] = fun(i);
    }

    return arr;
}

DLL_EXPORT void CALL TestCallback(int* arr, int size, Callback call)
{
    for (int i = 0; i < size; i++)
    {
        call(arr[i]);
    }
}


DLL_EXPORT int CALL vtest(void** p, const char *p1)
{
    if (p == NULL)
        return -1;
    void* a = *p;
    if (a == NULL)
        return -2;
    int* b = (int*)a;

    printf("s:%s\n", p1);
    return *b;
}

DLL_EXPORT int CALL vtest1(void** p)
{
    int a = 100;
    int* p1 = &a;
    int** p2 = &p1;

    return 0;
}

DLL_EXPORT void** CALL vtest2(void** p)
{
    return p;
}


DLL_EXPORT bool CALL bs(bool v) {
    return v;
}

DLL_EXPORT int CALL add(int a, int b) {
    return a + b;
}

DLL_EXPORT int CALL str(char* s, char s1[255]) {
    printf("s:%s, s1:%s\n", s, s1);
    return 100;
}

DLL_EXPORT int CALL str2(wchar_t* s, wchar_t s1[255]) {
    printf("s1:%ls, s2:%ls\n", s, s1);

    return 100;
}

DLL_EXPORT float CALL number(float a, double b) {
    printf("para1:%f, para2:%g\n", a, b);

    return 3.14;
}

DLL_EXPORT int CALL swap(int* a, int* b, int& c) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    c = 100;

    return 250;
}

DLL_EXPORT int CALL array(int arr1[], int arr1Len, int arr2[][4], int arr2Len) {
    for (int i = 0; i < arr1Len; i++) {
        printf("a[%d]: %d\n", i, arr1[i]);
    }

    for (int i = 0; i < arr2Len; i++) {
        for (int j = 0; j < 4; j++) {
            printf("b[%d][%d]: %d\n", i, j, arr2[i][j]);
        }

    }

    return 300;
}

DLL_EXPORT student  CALL st() {
    student su2 = { "chenjie", 18 };
    printf("name:%s, age:%d\n", su2.name, su2.age);
    return su2;
}

DLL_EXPORT student* CALL st1(student* p) {
    strcpy_s(p->name, "jim");
    p->age = 100;
    return p;
}


