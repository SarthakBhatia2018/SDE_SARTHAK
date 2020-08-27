#include <iostream>
#include <vector>

using namespace std;

struct Intervals
{
    int start;
    int end;
};

vector<Intervals> merge_intervals(vector<Intervals> v)
{
    vector<Intervals> res;
    vector<bool> vis(v.size(), false);
    for (int i = 0; i < v.size(); ++i)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        Intervals temp = v[i];
        for (int j = i + 1; j < v.size(); ++j)
        {
            if ((temp.end >= v[j].start && v[j].start >= temp.start) || (temp.start <= v[j].end && temp.start >= v[j].start))
            {
                vis[j] = true;
                temp.start = min(temp.start, v[j].start);
                temp.end = max(temp.end, v[j].end);
            }
        }
        res.push_back(temp);
    }
    return res;
}

void print(vector<Intervals> res)
{
    for (Intervals it : res)
        cout << it.start << " " << it.end << endl;
    cout << endl;
}

int main()
{
    vector<Intervals> v = {{1, 4}, {3, 6}, {7, 10}, {8, 9}, {9, 11}, {11, 15}, {16, 17}};
    vector<Intervals> res = merge_intervals(v);
    print(res);
    return 0;
}