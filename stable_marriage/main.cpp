/*
 * @Author: Hao Yang
 * @Date: 2023-03-28 00:21:14
 * @LastEditTime: 2023-04-02 11:46:30
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /stable_marriage/main.cpp
 */

//---------------------------------------------------------------------------
// MAIN.CPP
// Stable_Matching
//---------------------------------------------------------------------------
// This program reads data from a file and performs the Stable Matching
// algorithm to match people with pets.
//
// The input file should be formatted as follows:
// -- The first line contains a single integer, n, representing the number
//    of people/pets
// -- The next n lines contain the names of people
// -- The next n x n lines contain the preferences of each person for pets
// -- The following n lines contain the names of pets
// -- The last n x n lines contain the preferences of each pet for people
//
// The program outputs the resulting stable matching to the console.
//
// Assumptions:
// -- Input file is correctly formatted
// -- The program can handle up to 100 people/pets
//---------------------------------------------------------------------------
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "matching.h"

// Your code should be able to handle at least 100 peopele/pets
// onst int N = 110;

int main() {
  std::string fileName = "program1data.txt";
  std::ifstream inputFile(fileName);

  if (!inputFile) {
    std::cerr << "Unable to open the file.\n" << std::endl;
    return 1;
  }

  int n;
  inputFile >> n;

  std::vector<std::string> people_names(n);
  for (int i = 0; i < n; i++) inputFile >> people_names[i];

  std::vector<std::vector<int>> people_preferneces(n, std::vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) inputFile >> people_preferneces[i][j];

  std::vector<std::string> pet_names(n);
  for (int i = 0; i < n; i++) inputFile >> pet_names[i];

  std::vector<std::vector<int>> pet_preferneces(n, std::vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) inputFile >> pet_preferneces[i][j];

  inputFile.close();

  Matching m;
  auto stable_matching = m.find_matching(people_preferneces, pet_preferneces);

  for (int i = 0; i < n; i++)
    std::cout << people_names[i] << " / " << pet_names[stable_matching[i]]
              << std::endl;
}