#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#define MAX_LENGTH 200005
using std::cin; using std::cout; using std::endl;
const int MAX_SIZE = 1e5+10;
int t = 0, n = 0;
bool solve(int n)
{
    bool res = true;
    std::vector<int> p(n+1);
    std::vector<int> pos(n+1);
    std::vector<int> cnt(n+1);

    // init.
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        pos[p[i]]=i;
        cnt[i] = 1;
    }
    int maximal=1;
    for(int i=1; i<=n; i++)
    {
        if (cnt[pos[i]] != 0)
        {
            if (cnt[pos[i]] != maximal) 
            {
                res = false;
                break;
            }
            else // pos[i] = maximal
            {
                if (pos[i] != n)
                {
                    if (cnt[pos[i]+1] != 0)
                    {
                        cnt[pos[i]+1] = cnt[pos[i]] + 1;
                        maximal = cnt[pos[i]+1];
                    }
                    else
                    {
                        maximal = 1;
                    }
                }
                else
                {
                    maximal = 1;
                }
            }
            // reset
            cnt[pos[i]] = 0;
        }
        else
        {
            res = false;
            break;
        }
    }

    return res;
}
int main(int argc, char* argv[])
{
    #define SUBMISSION_VER 1
    #ifndef SUBMISSION_VER
        freopen("C:\\Users\\Yuxun Lu\\Code\\cf\\637D2C.in", "r", stdin);
        freopen("C:\\Users\\Yuxun Lu\\Code\\cf\\637D2C.out", "w", stdout);
    #endif
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        if (solve(n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}