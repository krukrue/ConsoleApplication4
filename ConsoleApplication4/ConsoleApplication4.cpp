#include <iostream>
#include <vector>
#include "CountingSort.h"
#include <algorithm>
#include "FileManager.h"
using namespace std;


vector<char> CreateArrayRandomValues(unsigned int elementsLength) // method for random vector 
{
    vector<char>temp;
    srand(time(0));

    for (int i = 0; i < elementsLength; i++)
    {
        temp.push_back ('a' + (rand() % 26));
    }
    return temp;
}

int main()
{
    vector<int> test = { 52,6,7,8,15,10,1,4,23,5,3,2 };
    vector<char> test1 = { 'a','s','v','c',' ', 'b', 'n', 'x'};
    vector<int> test2 = { 52,17, 8, 9, 20, 100, 73, 92, 9 , 3,5,3,2 };
    vector<int> test3 = { 3,4,5,6,1 };

    CountingSort<int> sort;
    CountingSort<char> sort1;
    CountingSort<int> sort2;

    sort.DistributionCountingSort(test);
    sort.DistributionCountingSort(test2);

    sort.DistributionCountingSort(test3);

    FileManager files;
    vector<char>FileData = files.GetDataFromFile("example.txt");
    sort1.ComparisonCountingSort(test1);
    sort1.ComparisonCountingSort(FileData);
    sort1.ComparisonCountingSort(CreateArrayRandomValues(50));
    files.SaveDataToFile("example1.txt", FileData);

    


}


