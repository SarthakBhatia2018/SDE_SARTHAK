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

vector<Interval> merge_intervals(Interval arr[], int n)
{
    vector<Interval> res;
    sort(arr, arr + n, comp);
    Interval temp = arr[0];
    for (int i = 0; i < n; ++i)
    {
        if (temp.end >= arr[i].start)
        {
            temp.end = max(temp.end, arr[i].end);
        }
        else
        {
            res.push_back(temp);
            temp = arr[i];
        }
    }
    res.push_back(temp);
    return res;
}

int main()
{
    Interval arr[] = {{1, 6}, {2, 4}, {6, 7}, {10, 11}, {13, 23}};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<Interval> res = merge_intervals(arr, n);
    for (int i = 0; i < res.size(); ++i)
        cout << res[i].start << " " << res[i].end << endl;
    return 0;
}