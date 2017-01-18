#pragma once
#include<stdio.h>

class Sort
{
public:
	void selectionSort( int *arr, int sizeOfArray ) const;
	void print( int *arr, int sizeOfArray ) const;
	void swap( int *arr, int pos1, int pos2 ) const;
	void bubbleSort( int *arr, int sizeOfArray ) const;
	void insertionSort( int *arr, int sizeOfArray ) const;
	void mergeSort( int *arr, int sizeofArray ) const;
	void mergeSort( int *arr, int left, int right ) const;
	void merge( int *arr, int left, int mid, int right ) const;
};
