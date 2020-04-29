#include <iostream>
#include <fstream>
#define MAX_LENGTH 200005
unsigned long h[MAX_LENGTH] = { 0 }; // heights
bool isPeak[MAX_LENGTH] = { 0 };
unsigned int p[MAX_LENGTH] = { 0 }; // peaks
unsigned int p_count[MAX_LENGTH] = { 0 };
int main(int argc, char* argv[])
{
    #define SUBMISSION_VER 1
    #ifndef SUBMISSION_VER
        freopen("C:\\Users\\Yuxun Lu\\Code\\cf\\637D2B.in", "r", stdin);
        freopen("C:\\Users\\Yuxun Lu\\Code\\cf\\637D2B.out", "w", stdout);
    #endif
    int t=0, n=0, k=0;
    std::cin >> t;
    for (int i=0; i<t; i++)
    {
        std::memset(h, 0, sizeof h);
        std::memset(isPeak, 0, sizeof isPeak);
        std::memset(p, 0, sizeof p);
        std::memset(p_count, 0, sizeof p_count);

        std::cin >> n >> k;
        for (int j=0; j<n; j++)
            std::cin >> h[j];
        // Pick up peaks.
        for (int j=1; j<n-1; j++)
        {
            if ( (h[j] > h[j-1]) && (h[j] > h[j+1]) )
                isPeak[j]=true;
            else
                isPeak[j]=false;
        }
        // Couting peaks.

        unsigned int max = 0;
        unsigned int max_ind = 0;

        for (unsigned int j=0; j<n; j++)
        {
            int p_end = j + k - 1;
            if (p_end > n)
                break;
            for (int ii=j+1; ii<=p_end-1; ii++)
            {
                if (isPeak[ii])
                    p_count[j] = p_count[j]+1;
            }
            if ( p_count[j] > max )
            {
                max = p_count[j];
                max_ind = j;
            }
        }        
        std::cout << max + 1 << " " << max_ind + 1 << std::endl;     
    }
    return 0;
}