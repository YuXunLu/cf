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
    // compute r from current_p

    // initialize stage.
    std::vector<int> r(n+1);
    std::vector<std::vector<int>> aux_vec(n+1);
    std::vector<int> cnt(n+1);
    for(int i = 1; i <= n; i++)
    {
        r[i] = i;
        aux_vec[i].push_back(i);
        cnt[i] = 1;
    }
    
    for(int nmsl=0; nmsl < n; nmsl++)
    {
        // compute cnt
        /* for(int t=1; t<=n; t++)
        {
            cnt[t] = std::count(r.begin(), r.end(), t);
        } */
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
            // update r
            if (t_ind + 1 <= n)
            {
                r[t_ind] = r[t_ind + 1];
                aux_vec[t_ind+1].push_back(t_ind);
            }
            else
                r[t_ind] = -1;
            cnt[t_ind] = 0; //since it's taken.
            while(!aux_vec[t_ind].empty())
            {
                int ptr = aux_vec[t_ind].front();
                r[ptr] = r[t_ind];
                if (r[ptr] != -1)
                {
                    aux_vec[r[ptr]].push_back(ptr);
                    cnt[r[ptr]] = cnt[r[ptr]] + 1;
                }
                aux_vec[t_ind].pop_back();
            }
            // update r ends.
            if (target_num < n)
                target_num = target_num + 1;
            else
            {
                res = true;
                break;
            }
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