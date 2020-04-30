#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#define MAX_LENGTH 200005
using std::cin; using std::cout; using std::endl;
const int MAX_SIZE = 1e5+10;
int t = 0, n = 0;
bool solve(std::vector<int> current_p, int target_num, std::vector<int> target_p, int n)
{
    bool res = false;
    // int p_[MAX_SIZE] = {0};
    // std::memcpy(p_, p, sizeof(int) * MAX_SIZE);
    std::vector<int> cnt(n+1);
    std::vector<int> r(n+1);

    // compute r from current_p
    for(int i = 1; i <= n; i++)
    {
        bool flag = true;
        for(int j=i; j<=n; j++)
        {
            if (current_p[j] == 0)
            {
                flag = true;
                r[i] = j;
                break;
            }
        }
        if (!flag)
            r[i] = -1; //indefine.
    }
    for(int t=1; t<=n; t++)
    {
        cnt[t] = std::count(r.begin(), r.end(), t);
    }
    // target location
    // std::vector::iterator
    auto target_ind = std::find(target_p.begin(), target_p.end(), target_num);
    int t_ind = std::distance(target_p.begin(), target_ind);
    int max_count = *std::max_element(cnt.begin(), cnt.end());
    // judge if cnt[target_ind] == max_count.
    // passed -> fill in, go to next round.
    // otherwise -> return false;
    if (cnt[t_ind] == max_count)
    {
        current_p[t_ind] = target_num;
        if (target_num < n)
        {
            target_num = target_num + 1;
            res = solve(current_p, target_num, target_p, n);
        }
        else
        {
            res = true;
        }
        
    }
    else
    {
        res = false;
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
        std::vector<int> p(n+1);
        std::vector<int> init_p(n+1, 0);
        for(int j = 1; j <= n; j++)
            cin >> p[j];
        if (solve(init_p, 1, p, n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}