#include "Sort.h"

void Sort::selectionSort(int* arr, int sizeOfArray ) const
{
	for( int it = 0; it < sizeOfArray; ++it)
	{
		int minElementPos = it;
		for ( int it2 = it+1; it2 < sizeOfArray; ++it2 )
		{
			if ( arr[it2] < arr[minElementPos] )
			{
				minElementPos = it2;
			}
		}
		swap( arr, it, minElementPos );
	}
}

void Sort::print(int* arr, int sizeOfArray ) const
{
	for(int it = 0; it < sizeOfArray; ++it )
	{
		printf( "%d\t", arr[it] );
	}
}

void Sort::swap(int* arr, int pos1, int pos2) const
{
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

void Sort::bubbleSort(int* arr, int sizeOfArray) const
{
	for ( int it = 0; it < sizeOfArray - 1; ++it )
	{
		bool swapped = false;
		for ( int it2 = 0; it2 < sizeOfArray - it - 1; ++it2 )
		{
			if ( arr[it2] > arr[it2+1] )
			{
				swap( arr, it2, it2 + 1 );
				swapped = true;
			}
		}
		if ( !swapped )
		{
			break;
		}
	}
}

void Sort::insertionSort( int * arr, int sizeOfArray ) const
{
	for ( int i = 1; i < sizeOfArray; ++i )
	{
		int key = arr[i];
		int j = i - 1;
		while( j >=0 && arr[j] > key )
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j+1] = key;
	}
}

void Sort::mergeSort(int* arr, int sizeofArray) const
{
	mergeSort( arr, 0, sizeofArray - 1 );
}

void Sort::mergeSort(int* arr, int left, int right) const
{
	if ( left < right )
	{
		int mid = ( left + right ) / 2;
		mergeSort( arr, left, mid );
		mergeSort( arr, mid + 1, right );
		merge( arr, left, mid, right );
	}
}

void Sort::merge(int* arr, int left, int mid, int right) const
{
	int leftsize = mid - left + 1;
	int rightsize = right - mid;

	int *arr1 = new int[leftsize];
	int *arr2 = new int[rightsize];

	for ( int m = 0; m < leftsize; ++m )
	{
		arr1[m] = arr[left + m];
	}

	for ( int n = 0; n < rightsize; ++n )
	{
		arr2[n] = arr[mid + 1 + n];
	}

	int i = 0, j = 0, k = left;

	while( i < leftsize && j < rightsize )
	{
		if ( arr1[i] < arr2[j] )
		{
			arr[k] = arr1[i];
			++i;
		}
		else
		{
			arr[k] = arr2[j];
			++j;
		}
		++k;
	}

	if ( i < leftsize )
	{
		for ( ; i < leftsize; ++i )
		{
			arr[k] = arr1[i];
			++k;
		}
	}

	if ( j < rightsize )
	{
		for ( ; j < rightsize; ++j )
		{
			arr[k] = arr2[j];
			++k;
		}
	}
}
