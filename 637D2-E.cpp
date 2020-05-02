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
    // bool visit[MAX_M] = {0};
    std::array<int, MAX_M> min_time;
    std::array<int, MAX_M> direction;
    direction.fill(1);
    min_time.fill(MAX_N);
    std::vector<int> stack;
    int g = 0, r = 0;
    for(int i=0;i<m;i++)
        cin >> islands[i];
    cin >> g >> r;
    // dfs 
    left_time[0] = g;
    min_time[0] = 0;
    int current_idx = 0;
    stack.push_back(0);
    bool found = false;
    std::qsort(islands, m, sizeof islands[0], [](const void* a, const void* b)
    {
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);
        if (arg1 < arg2) return -1;
        if (arg1 > arg2) return 1;
        return 0;
    });
    while(!stack.empty())
    {
        if (found)
            break;
        current_idx = stack.back();
        stack.pop_back();
        // visit[current_idx] = true;
        // search for next
        for(int i=0; i<m; i++)
        {
            if (i==current_idx)
                continue;
            int next = islands[i];
            // direction
            int need_time = 0;
            bool mod_dir = false;
            if ((islands[current_idx] - next) > 0)
            {
                // go back & change direction
                need_time = islands[current_idx] - next;
                if (direction[current_idx] != -1)
                {
                    need_time += 1;
                    mod_dir = true;
                }
            }
            if ((islands[current_idx] - next) < 0)
            {
                need_time = abs(islands[current_idx] - next);
                if (direction[current_idx] != 1)
                {
                    need_time += 1;
                    mod_dir = true;
                }
            }
            if ( need_time <= left_time[current_idx] )
            {
                // if (!visit[i])
                {
                    stack.push_back(i);
                    if (mod_dir)
                        direction[i] = -direction[current_idx];
                    left_time[i] = left_time[current_idx] - need_time;
                    if (left_time[i] != 0) //pass by.
                    {
                        min_time[i] = min_time[current_idx] + need_time;
                    }
                    else //arrive at.
                    {
                        min_time[i] = min_time[current_idx] + r + need_time;
                        left_time[i] = g;
                    }
                }
                if (i==m-1)
                {
                    // arrived.
                    cout << min_time[m-1] << endl;
                    found = true;
                    break;
                }
            }
        }
    }
    if (min_time[m-1] == MAX_N)
        cout << -1 << endl;
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