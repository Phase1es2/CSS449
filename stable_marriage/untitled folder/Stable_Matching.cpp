// Stable_Matching.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "matching.h"


int main()
{
	std::string fileName = "test2data.txt";
	std::ifstream inputFile(fileName);

	if (!inputFile) {
		std::cerr << "Unable to open the file." << std::endl;
		return 1;
	}
	
	int n;
	inputFile >> n;

	std::vector<std::string> people_names(n);
	for (int i = 0; i < n; i++) {
		inputFile >> people_names[i];
	}

	std::vector<std::vector<int>> people_preferneces(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			inputFile >> people_preferneces[i][j];

	std::vector<std::string> pet_names(n);
	for (int i = 0; i < n; i++) {
		inputFile >> pet_names[i];
	}


	std::vector<std::vector<int>> pet_preferneces(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			inputFile >> pet_preferneces[i][j];

	inputFile.close();

	Matching m;
	std::vector<int> stable_matching = m.find_matching(people_preferneces, pet_preferneces);
	
	for (int i = 0; i < n; i++) {
		//cout << "this is people: " << i << "  this is pet:  "<<stable_matching[i] << endl;
		std::cout << people_names[i] << "/" << pet_names[stable_matching[i]] << std::endl;
	}
	
	

}
