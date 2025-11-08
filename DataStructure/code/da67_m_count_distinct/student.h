#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include<set>

template <typename T>
size_t CP::vector<T>::count_distinct(CP::vector<T>::iterator a, CP::vector<T>::iterator b)
{
    // Write your code here
    std::set<T> s;
    while(a < b){
        s.insert(*a);
        a++;
    }
    size_t res = s.size();
    return res;
}

#endif