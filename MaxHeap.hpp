#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include <vector>
#include <iostream>

template <typename T>
class MaxHeap {
public:
    std::vector<T> heapTree; // A heap tree where the node at index i has subnodes at indices 2i+1 and 2i+2

    MaxHeap(std::vector<T> initialTree) : heapTree(initialTree) {}

    // Swap elements at indices i and j in the tree
    void Swap(int i, int j) {
        T temp = std::move(heapTree[i]);
        heapTree[i] = std::move(heapTree[j]);
        heapTree[j] = std::move(temp);
    }

    // Heapify the subtree rooted at index i
    void Heapify(int i) {
        int treeSize = heapTree.size();
        int largerIndex = i;
        int leftChildIndex = 2 * i + 1, rightChildIndex = 2 * i + 2; // Left and right child indices

        // Compare with left child
        if (leftChildIndex < treeSize && heapTree[leftChildIndex] > heapTree[largerIndex]) {
            largerIndex = leftChildIndex;
        }

        // Compare with right child
        if (rightChildIndex < treeSize && heapTree[rightChildIndex] > heapTree[largerIndex]) {
            largerIndex = rightChildIndex;
        }

        // Swap if necessary and recursively heapify the affected subtree
        if (i != largerIndex) {
            Swap(i, largerIndex);
            Heapify(largerIndex);
        }
    }

    // Build a max heap from the given tree
    std::vector<T>& BuildMaxHeap() {
        // Start from the last non-leaf node and apply heapify to each
        int treeSize = heapTree.size();
        int startIndex = (treeSize - 2 - treeSize % 2) / 2;

        for (int index = startIndex; index >= 0; --index) {
            Heapify(index);
        }
        return heapTree;
    }

    // Add an element to the max heap
    void Add(T value) {
        heapTree.push_back(value);
        BuildMaxHeap();
    }

    // Remove the element at index i from the max heap
    void Remove(int index) {
        heapTree.erase(heapTree.begin() + index);
        BuildMaxHeap();
    }

    // Print the elements of the max heap in a structured format
    void Print() {
        BuildMaxHeap();
        int treeSize = heapTree.size();
        int threshold = 1;
        int currentCount = 0;

        for (int i = 0; i < treeSize; ++i) {
            std::cout << heapTree[i] << " ";
            ++currentCount;

            if (currentCount == threshold) {
                std::cout << std::endl;
                threshold *= 2;
                currentCount = 0;
            }
        }

        if (currentCount != 0) {
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif