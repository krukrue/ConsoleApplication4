#pragma once
using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

template<typename T> //template for ComparisonCountingSort
class CountingSort {
public: 
	vector<T> InputVector;
	vector<int> counter;
	vector<T> sum;
	int max;

	void InitVector(vector<T> vect); // initializing our vectors

	vector<int> DistributionCountingSort(vector<int> temp);
	void printResult(vector<T> sum);  // display function

	vector<T> ComparisonCountingSort(vector<T> temp);
};

//Slozitost Algoritmu = O(n)
template<typename T>
void CountingSort<T>::InitVector(vector<T> vect)
{
	InputVector = vect;
	counter.clear();             // clear vector 
	max = *max_element(vect.begin(), vect.end());
	for (int i = 0; i < max + 1; i++) {
		counter.push_back(0);      // init for DistributionCountingSort
	}
}

//Slozitost Algoritmu = O(n)
inline vector<int> CountingSort<int>::DistributionCountingSort(vector<int> temp)
{
	InitVector(temp);
	vector<int> sum(InputVector.size());

	for (int i = 0; i < InputVector.size(); i++) { // compure frequience
		int j = InputVector[i];
		counter[j] = counter[j] + 1;
	}
	for (int i = 1; i < max + 1; i++) { // reuse for distribution
		counter[i] = counter[i] + counter[i - 1];
	}


	for (int i = InputVector.size() - 1; i > -1; i--) { // compare and final result
		int j = InputVector[i];
		counter[j] = counter[j] - 1;
		sum[counter[j]] = InputVector[i];
	}


	printResult(sum);

	return sum;
}

template<typename T>
inline void CountingSort<T>::printResult(vector<T> sum) 
{
	cout << "Sorted list: " << endl;
	for (int i = 0; i < sum.size(); i++) {
		cout << sum[i] << endl;
	}
}

//Slozitost Algoritmu = O(n^2)
template<typename T>
inline vector<T> CountingSort<T>::ComparisonCountingSort(vector<T> temp)
{
	{
		InitVector(temp);
		vector<int> count;
		vector<T> sum(InputVector.size());

		for (int i = 0; i < InputVector.size(); i++) {
			count.push_back(0);
		}
		for (int i = 0; i < InputVector.size() - 1; i++) {
			for (int j = i + 1; j < InputVector.size(); j++) {
				if (InputVector[i] < InputVector[j]) {
					count[j] = count[j] + 1;

				}
				else {
					count[i] = count[i] + 1;
				}
			}
		}

		for (int i = 0; i < count.size(); i++) {
			sum[count[i]] = InputVector[i];
		}
		printResult(sum);

		return sum;
	}
}
