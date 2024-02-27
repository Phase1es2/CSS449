/*
 * @Author: your name
 * @Date: 2023-03-30 10:51:38
 * @LastEditTime: 2023-03-30 11:36:41
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /stable_marriage/read_string.cpp
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::ifstream ifs("program1data.txt", std::ios::in);
    if (!ifs.is_open()) {
        std::cerr << "Fail to open file.\n";
        return 1;
    }

    std::stringstream ss;
    ss << ifs.rdbuf();
    std::string line;
    std::getline(ss, line);
    int n = std::stoi(line);
    //std::cout << n << std::endl;

    std::vector<std::string> names(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        std::getline(ss, line);
        names[i] = line;
    }

    std::vector<std::vector<std::string>> preferences(2 * n, std::vector<std::string>(n));
    for (int i = 0; i < 2 * n; ++i) {
        std::string pref_line;
        std::getline(ss, pref_line);
        while (pref_line.empty() && !ss.eof()) {
            std::getline(ss, pref_line);
        }
        std::istringstream pref_stream(pref_line);
        for (int j = 0; j < n; ++j) {
            std::string pref;
            if (pref_stream >> pref) {
                preferences[i][j] = pref;
            }
        }
    }

    ifs.close();

    // Display names
    for (const auto &name : names) {
        std::cout << name << std::endl;
    }

    // Display preferences
   // for (const auto &row : preferences) {
   //     for (const auto &val : row) {
    //        std::cout << val << " ";
     ///   }
      //  std::cout << std::endl;
   // }

    return 0;
}
