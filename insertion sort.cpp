//20192618 ÀÌÀç¿ì

#include <iostream>
using namespace std;

void insertNextItem(int a[], int i);
void insertionSort(int a[], int n);

int main()
{
	cout << "Enter the size of your array. : ";
	int n;
	cin >> n;
	int* myArray = new int[n];

	cout << "Enter the items for your array. : ";
	int i;
	for (i = 0; i < n; i++)
		cin >> myArray[i];

	cout << "Your array is" << endl;
	for (i = 0; i < n; i++)
		cout << myArray[i] << " ";
	cout << endl;

	insertionSort(myArray, n);
	cout << "Your sorted array is" << endl;
	for (i = 0; i < n; i++)
		cout << myArray[i] << " ";
	cout << endl;

	delete[] myArray;

	return 0;
}

void insertNextItem(int a[], int i)
{
	// Precondition: array a is sorted from 0 to i-1
	int newItem = a[i], insertPos = i;
	for (; (insertPos) && (newItem < a[insertPos - 1]); insertPos--)
	{
		// Loop Invariant: newItem <= a[insertPos+1] .. a[i] &&
		//                      a[insertPos+1] .. a[i] are sorted.
		a[insertPos] = a[insertPos - 1];
	}
	a[insertPos] = newItem;
	// Postcondition: array a is sorted from 0 to i
}

void insertionSort(int a[], int n)
{
	// Precondition: a is an array with subscripts ranging from 0 to n-1
	int i;
	for (i = 1; i < n; i++)
	{
		// Loop invariant: items in range from 0 to i-1 are sorted.
		//                      items from i to n-1 have not yet been examined.
		insertNextItem(a, i);
		// Postcondition: array a is sorted.
	}
}