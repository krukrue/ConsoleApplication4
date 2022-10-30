#pragma once
using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

template<typename T> //template for ComparisonCountingSort
class CountingSort {
public: 
	vector<T> intVector;
	vector<int> counter;
	vector<T> sum;
	int max;

	void InitVector(vector<T> vect) { // initializing our vectors
		intVector = vect;
		counter.clear();             // clear vector 
		max = *max_element(vect.begin(), vect.end()); 
		for (int i = 0; i < max + 1; i++) {
			counter.push_back(0);      // init for DistributionCountingSort
		}
	}

	vector<int> DistributionCountingSort(vector<int> temp) {
		InitVector(temp);
		vector<int> sum(intVector.size());

		for (int i = 0; i < intVector.size(); i++) { // compure frequience
			int j = intVector[i];
			counter[j] = counter[j] + 1;
		}
		for (int i = 1; i < max + 1; i++) { // reuse for distribution
			counter[i] = counter[i] + counter[i - 1];
		}


		for (int i = intVector.size() - 1; i > -1; i--) { // compare and final result
			int j = intVector[i];
			counter[j] = counter[j] - 1;
			sum[counter[j]] = intVector[i];
		}


		printResult(sum);
		
		return sum;
	}
	void printResult(vector<T> sum) { // display function
		cout << "Sorted list: " << endl;
		for (int i = 0; i < sum.size(); i++) {
			cout << sum[i] << endl;
		}
	}

	vector<T> ComparisonCountingSort(vector<T> temp) {
		InitVector(temp);
		vector<int> count;
		vector<T> sum(intVector.size());

		for (int i = 0; i < intVector.size(); i++) {
			count.push_back(0);
		}
		for (int i = 0; i < intVector.size() - 1; i++) {
			for (int j = i + 1; j < intVector.size(); j++) {
				if (intVector[i] < intVector[j]) {
					count[j] = count[j] + 1;

				} 
				else {
					count[i] = count[i] + 1;
				}
			}
		}

		for (int i = 0; i < count.size(); i++) {
			sum[count[i]] = intVector[i];
		}
		printResult(sum);

		return sum;	
	}
};