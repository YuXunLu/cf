#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <array>
#include <string>
#include <intrin.h>
using std::cin; using std::cout; using std::endl;
const int MAX_M = 1e4 + 5;
const int MAX_N = 1e6 + 5;

void solve(int n, int m)
{
    int islands[MAX_M] = {0};
    int left_time[MAX_M] = {0};
    std::array<int, MAX_M> min_time;
    std::array<int, MAX_M> direction;
    direction.fill(1);
    min_time.fill(1e9+5);
    std::vector<std::pair<int, int>> stack;
    int g = 0, r = 0;
    for(int i=0;i<m;i++)
        cin >> islands[i];
    cin >> g >> r;
    // dfs 


    /// This solution's problem is, last_visit will be overwrite!!!
    // If, say, 
    // vertex 0 -> vertex 3 -> vertex 6, 
    // but vertex 0 -> vertex 6 is also ok from 0.
    // then, last_visit will be overwrite from 0 to 3, if the stack is [3,0] -> first arrive 3.
    /// for left_time's bug, consier
    // c -> b -> a -> b 
    // c-> b -> a -> d
    left_time[0] = g;
    min_time[0] = 0;
    stack.push_back(std::make_pair(0,0));
    // cout << g << r;
    std::qsort(islands, m, sizeof islands[0], [](const void* a, const void* b)
    {
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);
        if (arg1 < arg2) return -1;
        if (arg1 > arg2) return 1;
        return 0;
    });
    bool found = false;
    while(!stack.empty())
    {
        auto current_pair = stack.back();
        stack.pop_back();

        int current_idx = current_pair.second;
        int last_idx = current_pair.first;

        if (current_idx != last_idx)
        {
            left_time[current_idx] = left_time[last_idx] - abs(islands[last_idx] - islands[current_idx]);
            if (left_time[current_idx] == 0)
            {
                int t = min_time[last_idx] + abs(islands[last_idx] - islands[current_idx]) + r;
                min_time[current_idx] = t < min_time[current_idx] ? t : min_time[current_idx];
                left_time[current_idx] = g;
            }
            else //passby
            {
                int t =  min_time[last_idx] +  abs(islands[last_idx] - islands[current_idx]);
                min_time[current_idx] = t < min_time[current_idx] ? t : min_time[current_idx];
            }
        }
        
        for(int i=0; i<m; i++)
        {
            if (i==current_idx)
                continue;
            int next = islands[i];
            int need_time = 0;
            need_time = abs(islands[current_idx] - next);

            if ( need_time <= left_time[current_idx] )
            {
                stack.push_back(std::make_pair(current_idx, i));
                if (i==m-1)
                {
                    int t = min_time[current_idx] + abs(islands[current_idx] - islands[m-1]);
                    min_time[m-1] = t < min_time[m-1] ? t : min_time[m-1];
                    found = true;
                    break;
                }
            }
        }
        if (found)
            break;

    }
    if (min_time[m-1] == 1e9+5)
        cout << -1 << endl;
    else
        cout << min_time[m-1] << endl;
}
int main(int argc, char* argv[])
{
    #define SUBMISSION_VER 1
    #ifndef SUBMISSION_VER
        freopen("C:\\Users\\Yuxun Lu\\Code\\cf\\637D2E.in", "r", stdin);
        freopen("C:\\Users\\Yuxun Lu\\Code\\cf\\637D2E.out", "w", stdout);
    #endif
    int n = 0, m =0;
    cin >> n >> m;
    solve(n,m);
    return 0;
}