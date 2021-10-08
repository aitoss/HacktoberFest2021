// C++ program for Merge Sort
 #include <iostream>
 using namespace std;

                    // Merges two subarrays of array[].
// First subarray is arr[begin..mid]        // Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
	auto const subArray1 = mid - left + 1;
	auto const subArray2 = right - mid;

	// Creating temp arrays
	auto *L_Array = new int[subArray1],
		*R_Array = new int[subArray2];

	// Copy data to temp arrays L_Array[] and R_Array[]
	for (auto i = 0; i < subArray1; i++)
		L_Array[i] = array[left + i];
	for (auto j = 0; j < subArray2; j++)
		R_Array[j] = array[mid + 1 + j];

	auto index_Of_SubArray_One = 0, // Initial index of first sub-array
		index_Of_SubArray_Two = 0; // Initial index of second sub-array
	int index_Of_Merged_Array = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (index_Of_SubArray_One < subArray1 && index_Of_SubArray_Two < subArray2) {
		if (L_Array[index_Of_SubArray_One] <= R_Array[index_Of_SubArray_Two]) {
			array[index_Of_Merged_Array] = L_Array[index_Of_SubArray_One];
			index_Of_SubArray_One++;
		}
		else {
			array[index_Of_Merged_Array] = R_Array[index_Of_SubArray_Two];
			index_Of_SubArray_Two++;
		}
		index_Of_Merged_Array++;
	}
	/* Copy the remaining elements of
	left[], if there are any*/
	while (index_Of_SubArray_One < subArray1) {
		array[index_Of_Merged_Array] = L_Array[index_Of_SubArray_One];
		index_Of_SubArray_One++;
		index_Of_Merged_Array++;
	}
	/* Copy the remaining elements of
	 right[], if there are any*/
	while (index_Of_SubArray_Two < subArray2) {
		array[index_Of_Merged_Array] = R_Array[index_Of_SubArray_Two];
		index_Of_SubArray_Two++;
		index_Of_Merged_Array++;
	}
}

/* begin is for left index and end is
 right index of the sub-array
 of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
      if (begin >= end)
        return; // Returns recursively

      auto mid = begin + (end - begin) / 2;
      mergeSort(array, begin, mid);
      mergeSort(array, mid + 1, end);
      merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
      for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

// Driver code
int main()
{
    int arr[] = { 17,47,93,82,43,13,56 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}



