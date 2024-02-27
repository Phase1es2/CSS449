/*
 * @Author: Hao Yang
 * @Date: 2023-03-28 00:21:51
 * @LastEditTime: 2023-04-02 02:34:48
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /stable_marriage/stable_matching.cpp
 */

//---------------------------------------------------------------------------
// MATCHING.CPP
// Member function definitions for class Matching
//---------------------------------------------------------------------------
// Matching class: Implements a stable matching algorithm to match people and
// pets based on their preferences:
// -- Allows to find a stable matching between people and pets
//
// Assumptions:
// -- Input vectors for people and pet preferences are properly formatted
// -- The number of people is equal to the number of pets
// -- Preferences are 1-indexed
//---------------------------------------------------------------------------
#include "matching.h"

#include <queue>
// Find a stable matching between people and pets using their preferences
// Preconditions: people and pet are 2D vectors with equal dimensions,
// representing the preferences of people and pets, respectively
// Postconditions: Returns a vector of integers where each element represents
// the index of the pet that the person is matched with
std::vector<int> Matching::find_matching(
    const std::vector<std::vector<int>>& people,
    const std::vector<std::vector<int>>& pet) {
  int n = people.size();
  std::vector<int> peoples(n, -1);
  std::vector<int> pets(n, -1);
  std::queue<int> unmatced;

  for (int i = 0; i < n; i++) unmatced.push(i);

  while (unmatced.size()) {
    int ppl = unmatced.front();
    for (int i = 0; i < n; i++) {
      int pt = people[ppl][i] - 1;
      if (pets[pt] == -1) {
        peoples[ppl] = pt;
        pets[pt] = ppl;
        unmatced.pop();
        break;
      } else {
        int old_matching = pets[pt];
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

// Check if the new matching is better for the pet than the old matching
// Preconditions: pet is a 2D vector representing the preferences of pets,
// new_matching and old_matching are valid indices for the preferences,
// pets is a valid index for the pet
// Postconditions: Returns true if the new matching is more preferred by the
// pet than the old matching, false otherwise
bool Matching::check_stable(const std::vector<std::vector<int>>& pet,
                            int new_matching, int pets, int old_matching) {
  int n = pet[0].size();
  new_matching += 1;
  old_matching += 1;
  for (int i = 0; i < n; i++) {
    if (pet[pets][i] == new_matching) return true;
    if (pet[pets][i] == old_matching) return false;
  }
  return false;
}
