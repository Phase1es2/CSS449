/*
 * @Author: Hao Yang
 * @Date: 2023-05-09 12:59:44
 * @LastEditTime: 2023-05-26 21:54:49
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /Program3/nameList.h
 */

// NameList Class
// NmaeList calss help to sort the node names form the graph class using vector
// addTolist allow to add a new name in to the name list
// readName read the name from the input file and add them to the list
// getNmae helps to find a name based on the providing index
// getList return the sorted vector to the user
// printList print out the sorted list
#ifndef NAMELIST_H_
#define NAMELIST_H_
#include <iostream>
#include <string>
#include <vector>
class NameList {
 public:
  // Constructor for the NameList class
  NameList();
  // Destructor for the NameList class.
  ~NameList();
  // Function to add a name to the name_ vector.
  void addToList(std::string name);
  // Fucntion to read the name from the input file.
  //void readName(const std::string& fileName);
  // Function to get a name from base on the input index.
  std::string getName(int n) const;
  // Function that return the name_ vector.
  std::vector<std::string> getList();
  // FUcntion that print the name the listed in the vector.
  void printlist();

 private:
  std::vector<std::string> name_;
};

#endif