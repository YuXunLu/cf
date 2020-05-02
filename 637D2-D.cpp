#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <intrin.h>


using std::cin; using std::cout; using std::endl;
const int nums[10] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, \
0b0111010,0b1101011,0b1101111,0b1010010,0b1111111,0b1111011};
const int MAX_N = 2e3+3;
int cap[MAX_N][MAX_N] = {0}; //short for capability
int ans[MAX_N] = {0};
const int mask[7] = {0b0000001, 0b0000010, 0b0000100, 0b0001000, 0b0010000, 0b0100000, 0b1000000};
bool legal_trans(int target, int source)
{
    for(int i = 0; i < 7; i++)
    {
        if  ( ( (target & mask[i] ) == mask[i]) && ( (source & mask[i]) == 0) ) 
            return false;
    }
    return true;
}
bool dp(int given[], int pos, int k, int n)
{
    if (!cap[pos][k]) //state visited before
        return false;
    // new state.
    // greedy search.
    for(int i=9; i>=0; i--)
    {
        if (pos == n-1) //last layer
        {
            int used_stick = __popcnt(given[pos]^nums[i]);
            if ( (used_stick == k) && legal_trans(given[pos], nums[i]) )
            {
                ans[pos] = i;
                cap[pos][k] = true; // not necessary?
                return true;
            }
        }
        else //mio steps.
        {
            int used_stick = __popcnt(given[pos]^nums[i]);
            // legal_trans could be optimized to !(given[pos] & ~num[i])
            if( ( used_stick <= k) && legal_trans(given[pos], nums[i]) )
            {
                if (dp(given, pos+1, k-used_stick,n))
                {
                    ans[pos] = i;
                    cap[pos][k] = true;
                    return true;
                }
            }
        }
    }
     //all searched, no result.
     cap[pos][k] = false;
     return false;
}
void solve(const int n, int k)
{
    int given[MAX_N] = {0};
    for(int i=0; i<n; i++)
    {
        std::string num;
        cin >> num;
        int num_ = std::stoi(num, 0, 2);
        given[i] = num_;
    }
    memset(cap, 1, sizeof cap);
    if ( dp(given, 0, k, n) )
    {
        for(int i = 0; i < n; i++)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
int main(int argc, char* argv[])
{
    #define SUBMISSION_VER 1
    #ifndef SUBMISSION_VER
        freopen("C:\\Users\\Yuxun Lu\\Code\\cf\\637D2D.in", "r", stdin);
        freopen("C:\\Users\\Yuxun Lu\\Code\\cf\\637D2D.out", "w", stdout);
    #endif
    int n = 0;
    int k = 0;
    cin >> n >> k;
    solve(n,k);
    return 0;
}