#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval
{
    int start, end;
};

bool comp(Interval &a, Interval &b)
{
    return a.start < b.start;
}

void merge_intervals(Interval arr[], int n)
{
    sort(arr, arr + n, comp);
    int index = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[index].end >= arr[i].start)
        {
            arr[index].end = max(arr[index].end, arr[i].end);
        }
        else
        {
            ++index;
            arr[index] = arr[i];
        }
    }
    for (int i = 0; i <= index; ++i)
        cout << arr[i].start << " " << arr[i].end << endl;
}

int main()
{
    Interval arr[] = {{1, 6}, {2, 4}, {6, 10}, {10, 11}, {13, 23}};
    int n = sizeof(arr) / sizeof(arr[0]);
    merge_intervals(arr, n);
    return 0;
}