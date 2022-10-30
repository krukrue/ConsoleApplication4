#include "FileManager.h"


	vector<char> FileManager::GetDataFromFile(string FileName) {
		vector<char> symbols; // vector for read characters;
		ifstream myfile(FileName); // open for reading
		char ch;					// temp character
		if (myfile.is_open()) // check if open
		{
			while (myfile >> noskipws >> ch)  // while have ch
			{
				symbols.push_back(ch);        // push to vector
			}
			myfile.close();                 // close when end
		}

		return symbols;						// return vector 
	}


	bool FileManager::SaveDataToFile(string FileName, vector<char> data) {
		fstream myFile; // create for writing 
		myFile.open(FileName, ios::out); // write

		if (myFile.is_open()) { // check if open
			for (int i = 0; i < data.size(); i++) {
				myFile << data[i];  // every character save to file
			}
			myFile.close(); // close when end;
			return true; // if good  
		}

		return false; // was error
	}
