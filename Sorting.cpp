class Sorting
{
public:
    static void bubble_flag(int *array, int count)
    {
        bool flag = true;
        for (int i = 0; (i < count) && flag; i++)
        {
            flag = false;
            for (int j = 0; j < count - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    std::swap(array[j], array[j + 1]);
                    flag = true;
                }
            }
        }   
    }

    static void merge_sort(int *array, int count)
    {
        merge(array, 0, count - 1);
    }

private:
    static void merge(int *array, int start, int end)
    {
        if (end - start <= 1)
        {
            if (end - start == 1 && array[start] > array[start + 1])
                std::swap(array[start], array[start + 1]);
            return;
        }

        int middle = (start + end) / 2;

        merge(array, start, middle);
        merge(array, middle, end);

        int *array_sort = new int[end];
        int index = 0;
        int left = start;
        int right = middle;
        while (index < end - start)
        {
            if (right < end && array[left] >= array[right])
            {
                array_sort[index] = array[right];
                right++;
                index++;
            }
            else if (left >= middle)
            {
                array_sort[index] = array[right];
                right++;
                index++;
            }
            else
            {
                array_sort[index] = array[left];
                left++;
                index++;
            }
        }
        for (int i = start; i < end; i++)
            array[i] = array_sort[i - start];
        
        delete[] array_sort;
    }
};