// Sliding window
//  Input: [1, 3, -1, -3, 5, 3, 6, 7], k = 3
//  Output: [3, 3, 5, 5, 6, 7]

#include <iostream>
#include <queue>

int getMax(std::queue<int> q)
{
    int max = -100;
    int num = 0;
    while (!q.empty())
    {
        num = q.front();
        q.pop();
        if (max < num)
        {
            max = num;
        }
    }
    return max;
}

int main()
{
    // input array
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    std::queue<int> q;
    for (size_t i = 0; i < k; i++)
    {
        q.push(arr[i]);
    }
    std::cout << '[';
    for (int i = k; i <= size; i++)
    {
        std::cout << getMax(q);
        if (i == size)
        {
            break;
        }
        else
        {
            std::cout << " ";
        }
        q.pop();
        q.push(arr[i]);
    }
    std::cout << ']';

    return 0;
}
