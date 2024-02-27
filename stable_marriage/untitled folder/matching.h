#ifndef Matching_H_
#define Matching_H_

#include <vector>


class Matching {
public:
	std::vector<int> find_matching(const std::vector<std::vector<int>>& people, const std::vector<std::vector<int>>& pet);


private:
	bool check_stable(const std::vector<std::vector<int>>& pet, int new_matching, int pets, int old_matching);
};
#endif // !Matching_H
