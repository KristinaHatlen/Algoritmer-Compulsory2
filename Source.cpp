#define pb push_back
#include <algorithm>
#include <ctime>
#include  <iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

/**
 * \brief Using ShellSort
 * \param vec 
 * \param n 
 * \return 
 */

//void showlist(list<int> g)
//{
//    list<int>::iterator it;
//    for (it = g.begin(); it != g.end(); ++it)
//        cout << '\t' << *it;
//    cout << '\n';
//}

//int Shell_Sort(int vec[], int n)
//{
//	for (int gap = n/2; gap > 0; gap /= 2)
//	{
//		for (int i = gap; i < n; i++)
//		{
//            int x = vec[i];
//            int j;
//            for (j = i; j > gap && vec[j - gap] > x; j -= gap)
//                vec[j] = vec[j - gap];
//            vec[j] = x;
//		}
//	}
//    return 0;
//}

//int main()
//{
//  // list
//    list<int> gqlist1;
//
//    for (int i = 0; i < 10; ++i) {
//        gqlist1.push_back(i * 2);
//    }
//    cout << "\nList 1 (gqlist1) is : ";
//    showlist(gqlist1);




 

 //   for (int i = 0; i < size; i++) 
 //   {
 //       vec[i] = (rand() % 100);
 //   }

	////int vec[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
 //   int n = sizeof(vec) / sizeof(vec[0]), i;
 //   cout << "Unsorted array: \n";
 //   for (int i = 0; i < n; i++) cout << vec[i] << " ";

	//// start timer
 //   std::clock_t start;
 //   start = std::clock();

	//Shell_Sort(vec, n);

	//// end timer and print time
 //   std::clock_t end;
 //   end = std::clock();
 //   std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;


 //   cout << "\nSorted array: \n";
 //   for (int i = 0; i < n; i++) cout << vec[i] << " ";
//    return 0;
//}


/**
 * \brief Using Bucket Sort
 */

//void Bucket_Sort(float arr[], int n)
//{
//	vector<float> bucket[n];
//	for (int i = 0; i < n; i++)
//	{
//		int bi = n * arr[i];
//		bucket[bi].pb(arr[i]);
//	}
//	for (int i = 0; i < n; i++)
//		sort(bucket[i].begin(), bucket[i].end());
//	int pos = 0;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < bucket[i].size(); j++)
//			arr[pos++] = bucket[i][j];
//}
//
//int main()
//{
//	float arr[] = { 0.474, 0.582, 0.452, 0.6194, 0.533, 0.9414 };
//	int n = sizeof(arr) / sizeof(arr[0]);

	//// start timer
//   std::clock_t start;
//   start = std::clock();
	//Bucket_Sort(arr, n);
	//// end timer and print time
 //   std::clock_t end;
 //   end = std::clock();
 //   std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
//
//	cout << "Sorted array is \n";
//	for (int i = 0; i < n; i++)
//		cout << arr[i] << " ";
//	return 0;
//}

/**
 * \brief Using Merge Sort
 */

void merge(int array[], int const left, int const mid,
    int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    // start timer
   std::clock_t start;
   start = std::clock();

    mergeSort(arr, 0, arr_size - 1);

    // end timer and print time
    std::clock_t end;
    end = std::clock();
    std::cout << "Time: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}

// Sources
// https://www.geeksforgeeks.org/list-cpp-stl/
// https://www.crio.do/blog/top-10-sorting-algorithms/
// https://www.geeksforgeeks.org/merge-sort/