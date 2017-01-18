#pragma once

class LIS
{
public:
	LIS( int *arr, int n );
	int doLis( ) const;
	~LIS( );

private:
	int *arrayLis;
	int arrNumber;
	int *array;
};

inline LIS::LIS( int *arr, int n )
: arrNumber( n )
{
	arrayLis = new int( n );
	array = arr;

	for ( int i = 0; i < n; ++i )
	{
		arrayLis[i] = 1;
	}
}

inline int LIS::doLis() const
{
	for ( int i =1; i < arrNumber; ++i )
	{
		for ( int j = 0; j < i; ++j )
		{
			if ( array[i] > array[j] && arrayLis[i] < arrayLis[j] + 1 )
			{
				arrayLis[i] = arrayLis[j] + 1;
			}
		}
	}

	int max = 0;
	for ( int i = 0; i < arrNumber; ++i )
	{
		if ( arrayLis[i] > max )
			max = arrayLis[i];
	}
	return max;
}

inline LIS::~LIS()
{
	delete[] arrayLis;
}
