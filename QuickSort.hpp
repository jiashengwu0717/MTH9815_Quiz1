#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>

template <typename T>
class CQuickSort {
public:
    // Swap two elements in the array
    void Swap(std::vector<T>& array, int index1, int index2) {
        T temp = std::move(array[index1]);
        array[index1] = std::move(array[index2]);
        array[index2] = std::move(temp);
    }

    // Partition the array [startIndex, endIndex) using the pivot at startIndex
    int Partition(std::vector<T>& array, int startIndex, int endIndex) {
        int pivotIndex = startIndex;
        T pivot = array[startIndex];

        for (int currentIndex = startIndex + 1; currentIndex < endIndex; ++currentIndex) {
            // Identify elements smaller than or equal to the pivot
            if (array[currentIndex] <= pivot) {
                // Move the smaller element to the left of the pivot
                for (int backwardIndex = 0; backwardIndex < currentIndex - pivotIndex; ++backwardIndex) {
                    Swap(array, currentIndex - backwardIndex, currentIndex - backwardIndex - 1);
                }
                ++pivotIndex; // Update the index of the pivot
            }
        }
        return pivotIndex;
    }

    // Recursively apply quicksort to the array [startIndex, endIndex)
    std::vector<T>& QuickSort(std::vector<T>& array, int startIndex, int endIndex) {
        if (startIndex < endIndex) {
            int pivotIndex = Partition(array, startIndex, endIndex);
            // Recursively sort the left and right subarrays
            QuickSort(array, startIndex, pivotIndex);
            QuickSort(array, pivotIndex + 1, endIndex);
        }
        return array;
    }

    // Public method to initiate quicksort on the entire array
    std::vector<T>& Sort(std::vector<T>& array) {
        QuickSort(array, 0, array.size());
        return array;
    }
};

#endif