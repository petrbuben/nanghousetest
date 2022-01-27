#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

void printv(std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); i += 1)
    {
        std::cout << v[i];
    }
}

void permutcountprintv(std::vector<int> v, int& c) {
    do
    {
        printv(v);
        std::cout << "-count:" << ++c << " ";
    } while (std::next_permutation(v.begin(), v.end()));
}

int numberOfArrangements(int n)
{
    //build base vector
    int c{ 0 };
    int m = n / 2;
    std::vector<int> v(m, 2);
    std::cout << "build " << n;
    if(n==1)
        std::cout<< " story" << std::endl;
    else
        std::cout << " stories" << std::endl;

    if (n % 2) { //odd
        v.push_back(1);
        sort(v.begin(), v.end());
        permutcountprintv(v, c);
    }
    else {
        printv(v);  
        std::cout << "-count:" << ++c;
    }
    //replace and count
    for (size_t i = 0; i < v.size(); ++i){
        if (v.at(i) == 2){
            //replace with 1,1
            v.at(i) = 1;
            v.push_back(1);
            sort(v.begin(),v.end());
            std::cout << std::endl;
            //permutcount
            permutcountprintv(v, c);
        }
    }
    std::cout << std::endl << n;
    if(n==1)
        std::cout<< " story, ways to build: ";
    else
        std::cout<< " stories, ways to build: ";
    return c;
}

#ifndef RunTests
int main()
{
    for (int i = 1; i < 8; ++i) {
        std::cout << numberOfArrangements(i)<< std::endl << std::endl;
    }
}
#endif