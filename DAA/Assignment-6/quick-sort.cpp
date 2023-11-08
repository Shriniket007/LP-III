#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to partition the array for quicksort
int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Deterministic Quick Sort
void quickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Randomized Quick Sort
int randomPartition(std::vector<int> &arr, int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    std::swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

void randomizedQuickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = randomPartition(arr, low, high);
        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Original Array: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr1 = arr; // Create a copy for deterministic quicksort
    quickSort(arr1, 0, arr1.size() - 1);

    std::cout << "Deterministic Quick Sort: ";
    for (int num : arr1)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = arr; // Create a copy for randomized quicksort
    randomizedQuickSort(arr2, 0, arr2.size() - 1);

    std::cout << "Randomized Quick Sort: ";
    for (int num : arr2)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
