/*
 * @Author: your name
 * @Date: 2023-04-01 22:57:22
 * @LastEditTime: 2023-04-01 22:57:22
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /stable_marriage/testcase/testcase.cpp
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

void print_preferences(const std::vector<std::vector<int>>& preferences, std::ofstream& output) {
    for (const auto& pref_list : preferences) {
        for (int i = 0; i < pref_list.size(); ++i) {
            output << pref_list[i];
            if (i != pref_list.size() - 1) {
                output << " ";
            }
        }
        output << std::endl;
    }
}

int main() {
    const int num_participants = 50;
    std::vector<std::vector<int>> men_preferences(num_participants, std::vector<int>(num_participants));
    std::vector<std::vector<int>> women_preferences(num_participants, std::vector<int>(num_participants));

    std::random_device rd;
    std::mt19937 g(rd());

    for (int i = 0; i < num_participants; ++i) {
        for (int j = 0; j < num_participants; ++j) {
            men_preferences[i][j] = j + 1;
            women_preferences[i][j] = j + 1;
        }
        std::shuffle(men_preferences[i].begin(), men_preferences[i].end(), g);
        std::shuffle(women_preferences[i].begin(), women_preferences[i].end(), g);
    }

    std::ofstream output("test_case.txt");
    if (!output) {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
        return 1;
    }

    print_preferences(men_preferences, output);
    output << std::endl;
    print_preferences(women_preferences, output);

    output.close();
    std::cout << "Test case generated and saved to 'test_case.txt'" << std::endl;

    return 0;
}