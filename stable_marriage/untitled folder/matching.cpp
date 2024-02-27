#include "matching.h"
#include <queue>

std::vector<int> Matching::find_matching(const std::vector<std::vector<int>>& people, const std::vector<std::vector<int>>& pet)
{
	int n = people.size();
	std::vector<int> peoples(n, -1);
	std::vector<int> pets(n, -1);
	std::queue<int> unmatced;

	for (int i = 0; i < n; i++) {
		unmatced.push(i);
	}

	while (unmatced.size()) {
		int ppl = unmatced.front();
		for (int i = 0; i < n; i++) {
			int pt = people[ppl][i] - 1;
			if (pets[pt] == -1) {
				peoples[ppl] = pt;
				pets[pt] = ppl;
				unmatced.pop();
				break;
			}
			else {
				int old_matching = pets[pt]; // old = matching = 0;
				if (check_stable(pet, ppl, pt, old_matching) == true) {
					peoples[old_matching] = -1;
					unmatced.push(old_matching);
					peoples[ppl] = pt;
					pets[pt] = ppl;
					unmatced.pop();
					break;
				}
			}
		}
	}
	return peoples;
}

bool Matching::check_stable(const std::vector<std::vector<int>>& pet, int new_matching,int pets,  int old_matching)
{
	// pet
	//
	// old_matching = 3
	int n = pet[0].size();
	new_matching += 1;
	old_matching += 1;
	for (int i = 0; i < n; i++) {
		if (pet[pets][i] == new_matching) return true;
		if (pet[pets][i] == old_matching) return false;
	}
	return false;
}
