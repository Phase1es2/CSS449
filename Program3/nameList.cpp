/*
 * @Author: Hao Yang
 * @Date: 2023-05-09 14:10:24
 * @LastEditTime: 2023-05-26 21:44:14
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /Program3/nameList.cpp
 */
#include "nameList.h"

#include <fstream>
/**
 * @brief Default constructor for the NameList class.Initializes the name list
 * with an empty string.the indexing the node and name using 1-based indexing.
 */

NameList::NameList() { name_.push_back(""); }

/**
 * @brief Destructor for the NameList class. Clears the name list
 */
NameList::~NameList() { name_.clear(); }

/**
 * @brief RAdd a nmae to the name list.
 *
 * @param name  The name to be added to the list.
 */
void NameList::addToList(std::string name) { name_.push_back(name); }

/**
 * @brief Retrieves a name from teh name list.
 *
 * @param n The index of the name to be retrieved.
 * @return The name at the given index.
 */
std::string NameList::getName(int n) const { return name_[n]; }

/**
 * @brief Retrieves the full name list.
 *
 * @return The full name list.
 */
std::vector<std::string> NameList::getList() { return name_; }

/**
 * @brief Prints the full name list to the standard output.
 */
void NameList::printlist() {
  for (auto& x : name_) printf("%s\n", x.c_str());
}

/**
 * @brief Reads names from a given file and adds them to the name list.
 *
 * @param n fileName The name of the file to be read.
 */
/*
void NameList::readName(const std::string& fileName) {
  std::ifstream file(fileName);
  // if the file cannnot open print Unable to open file.
  if (!file) {
    std::cerr << "Unable to open file " << fileName << std::endl;
    return;
  }
  // The first line will hold the number of nodes n.
  int n;
  file >> n;
  std::string temp;
  while (n--) {
    file >> temp;
    // Add the name to the vector.
    addToList(temp);
  }
  // After read the name, close the file.
  file.close();
}
*/