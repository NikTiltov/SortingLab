#include "SortTester.cpp"
#include "Sorting.cpp"
#include <fstream>


int main()
{
    std::ofstream file("test.txt");
    file.close();

    SortTester::SetMinCount(1e1);
    SortTester::SetMaxCount(1e5);

    // for (int i = 0; i < 10; i++)
    // {
    //     SortTester::SetSrand(i);
    //     SortTester::FullTest(Sorting::bubble_flag, "bubble");
    // }

    for (int i = 0; i < 10; i++)
    {
        SortTester::SetSrand(i);
        SortTester::FullTest(Sorting::merge_sort, "merge");
    }
}