/*
 * @Author: Hao Yang
 * @Date: 2023-03-28 00:21:40
 * @LastEditTime: 2023-04-02 13:44:14
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /stable_marriage/stable_matching.h
 */
//---------------------------------------------------------------------------
// MATCHING.H
// Stable Matching Algorithm Class
//---------------------------------------------------------------------------
// Matching class: This class implements the Stable Matching algorithm to match
// people with pets based on their preferences.
//
// Public member functions:
// -- find_matching(): takes the preferences of people and pets as input and
//    returns a vector of integer indices representing stable matching
//
// Private member functions:
// -- check_stable(): checks whether a proposed matching is stable by
//    comparing the preference ranks of the new and old matchings
//
// Usage:
// -- Instantiate the Matching class
// -- Call the find_matching() function with people and pet preference matrices
// -- Use the returned matching vector to display or process results
//---------------------------------------------------------------------------

#ifndef Matching_H_
#define Matching_H_

#include <vector>

class Matching {
 public:
  /**
   * @brief Find a stable matching between people and pets based on their
   * preferences.
   *
   * This function implements a variant of the Gale-Shapley algorithm to find
   * a stable matching between people and pets, where no person-pet pair prefers
   * another pair over their current match.
   *
   * @param people A 2D vector where each row represents a person and the
   * columns represent their pet preferences in decreasing order of preference.
   * @param pet    A 2D vector where each row represents a pet and the columns
   *               represent their person preferences in decreasing order of
   * preference.
   * @return       A vector of integers where the ith element represents the
   * index of the pet matched with person i.
   */
  std::vector<int> find_matching(const std::vector<std::vector<int>>& people,
                                 const std::vector<std::vector<int>>& pet);

 private:
  /**
   * @brief Check if the new matching is more preferred by the pet than the old
   * matching.
   *
   * This function determines whether the new matching is stable for the given
   * pet, i.e., whether the pet prefers the new person over the old one. It
   * returns true if the new matching is more preferred, and false otherwise.
   *
   * @param pet         A 2D vector where each row represents a pet and the
   * columns represent their person preferences in decreasing order of
   * preference.
   * @param new_matching The index of the new person being considered for
   * matching with the pet.
   * @param pets        The index of the pet for which the stability check is
   * being performed.
   * @param old_matching The index of the old person currently matched with the
   * pet.
   * @return            Returns true if the new matching is more preferred by
   * the pet than the old matching, false otherwise.
   */
  bool check_stable(const std::vector<std::vector<int>>& pet, int new_matching,
                    int pets, int old_matching);
};
#endif  // !Matching_H
