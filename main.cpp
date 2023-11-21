// main.cpp for Quiz 1
// Author: Jiasheng Wu

#include <iostream>
#include <vector>
#include "QuickSort.hpp"
#include "MaxHeap.hpp"


template <typename T>
std::ostream & operator << (std::ostream& os, std::vector<T>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		os << arr[i] << " ";
	}
	os << std::endl;
	return os;
}


int main() {

	// 1) Write a quicksort algorithm to sort an array of integers
	std::cout << "--------- Exercise 1 ---------" << std::endl;
	std::vector<int> arr1{ 19, 5, 2, 5, 7, 17, 3, -1, 10 };
	std::cout << "Before sorting: " << std::endl;
	std::cout << arr1 << std::endl; // 19 5 2 5 7 17 3 -1 10

	CQuickSort<int> qs;
	qs.Sort(arr1);
	std::cout << "After sorting: " << std::endl;
	std::cout << arr1 << std::endl; // -1 2 3 5 5 7 10 17 19

	// 2) Write a max-heap class (with a left and right child) – you just need to define the Add() method to add an element to the max-heap
	std::cout << "--------- Exercise 2 ---------" << std::endl;
	std::vector<int> arr2{ 19, 5, 2, 5, 7, 17, 3, -1, 10 };
	MaxHeap<int> mp(arr2);
	mp.Print();

	mp.Add(50);
	mp.Add(100);
	mp.Print();

	// 3) Modify the max-heap above to remove an element from the max-heap
	std::cout << "--------- Exercise 3 ---------" << std::endl;
	mp.Remove(3); // remove the 3rd node
	mp.Print();

	return 0;

}