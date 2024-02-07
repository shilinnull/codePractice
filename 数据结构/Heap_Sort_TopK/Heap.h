#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<time.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* php);

void HeapDestroy(HP* php);

void HeapPush(HP* php, HPDataType x);


void HeapPop(HP* php);

HPDataType HeapTop(HP* php);

size_t HeapSize(HP* php);

bool HeapEmpty(HP* php);

void Swap(HPDataType* p1, HPDataType* p2);

void AdjustUp(HPDataType* a, int child);

void AdjustUp_Big(HPDataType* a, int child);

void AdjustDown(HPDataType* a, int size, int parent);

void AdjustDown_Big(HPDataType* a, int size, int parent);
