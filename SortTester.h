#ifndef SORT_TESTER_H
#define SORT_TESTER_H

#include <string>

class SortTester
{
public:
    static void SetMinCount(int count);
    static void SetMaxCount(int count);
    static void SetSrand(int seed);
    static void FullTest(void (*sort)(int*, int), std::string sortName);
    static void Test(void (*sort)(int *, int), int count, std::string sortName);

private:
    static int minCount;
    static int maxCount;

    static int *CreateArray(int count);
    static void Output(std::string sortName, int count, uint64_t time);
};

#endif