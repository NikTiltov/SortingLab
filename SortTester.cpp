#include "SortTester.h"

#include <fstream>
#include <chrono>
#include <random>
#include <iomanip>


int SortTester::minCount = 10;
int SortTester::maxCount = 100000;

void SortTester::SetMinCount(int count)
{
    minCount = count;
}

void SortTester::SetMaxCount(int count)
{
    maxCount = count;
}

void SortTester::SetSrand(int seed)
{
    srand(seed);
}

void SortTester::FullTest(void (*sort)(int*, int), std::string sortName)
{   
    for (int i = minCount; i <= maxCount; i *= 10)
        Test(sort, i, sortName);
}

void SortTester::Test(void (*sort)(int *, int), int count, std::string sortName)
{
    using namespace std::chrono;
    int *array = CreateArray(count);

    auto start = high_resolution_clock::now();
    sort(array, count);
    auto end = high_resolution_clock::now();

    delete[] array;

    auto duration = duration_cast<milliseconds>(end - start);
    Output(sortName, count, duration.count());
}

int *SortTester::CreateArray(int count)
{
    int *array = new int[count];
    for (int i = 0; i < count; i++)
        array[i] = rand();
    return array;
}

void SortTester::Output(std::string sortName, int count, uint64_t time)
{
    std::ofstream fout("test.txt", std::ios::app);
    // fout << std::setfill(' ') << std::setw(16);
    fout << sortName << " : " << count << " : " << time << '\n';
    fout.close();
}