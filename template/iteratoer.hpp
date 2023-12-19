#pragma once

#include <vector>
#include <iostream>
#include <unordered_set>
#include <iterator>

template <typename T , typename Container>
Container createVector()
{
  Container resultVector ={1,2,3,4,5,6,7,8,9,9};
  return resultVector;
}

template <typename T>
typename T::value_type findFirstDuplicate(T begin, T end)
{
  std::unordered_set<typename T::value_type> seenTable;
  typename T::value_type duplicate ;
  for (auto it = end; it != begin; --it)
  {
    if (seenTable.find(*it) != seenTable.end())
    {
      duplicate = *it;
    }
    else
    {
      seenTable.insert(*it);
    }
  }
  return duplicate;
}

