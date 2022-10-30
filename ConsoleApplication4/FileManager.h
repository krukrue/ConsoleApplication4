#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FileManager

{
public:
	vector<char> GetDataFromFile(string FileName);
	bool SaveDataToFile(string FileName, vector<char> data);


};

