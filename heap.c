/*
 * heapsort.c
 *
 *  Created on: Jul 1, 2013
 *      Author:
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	buildHeap(A, n);
	//printf("Initial min heap:\n");
	//printList(A, n);
	for(int i = n - 1; i > 0; i--) {
		//printf("Working on element %d\n", i);
		swap(&A[0], &A[i]); // if the 0 and 1 elements were in order, this will, swap them anyways
		//printf("After swapping:\n");
		//printList(A, n);
		heapify(A, 0, i - 1); // but then heapify considers the array to be of length 1, and so won't swap them back
		//printList(A, n);
	}
	// therefore determine if the first 2 elements are out of order after finishing the sort, and swap if needed
	if(A[0].salary < A[1].salary) swap(&A[0], &A[1]);
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	for(int i = n/2; i >= 0; i--) {
		heapify(A, i, n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{	
	if(i >= (n/2)) return; // current node is a leaf
	int left = 2 * (i+1)-1;
	int right = 2 * (i+1);
	int smaller;
	if(A[left].salary <= A[right].salary) smaller = left;
	else smaller = right;

	if(A[smaller].salary < A[i].salary) {
		swap(&A[i], &A[smaller]);
		heapify(A, smaller, n);
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2)
{
  Employee tmp = *e1;  // dereference x and store value in tmp
  *e1 = *e2;
  *e2 = tmp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	printf("[id=%s sal=%d]", A[0].name, A[0].salary);
	for(int i = 1; i < n; i++) {
		printf(", [id=%s sal=%d]", A[i].name, A[i].salary);
	}
	printf("\n");
}
