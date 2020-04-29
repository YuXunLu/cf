#include <iostream>
#include <fstream>
#define MAX_LENGTH 200005
#define SUBMISSION_VER 1

int main(int argc, char* argv[])
{
    #ifndef SUBMISSION_VER
        freopen("637D2B.in", "r", stdin);
        freopen("637D2B.out", "w", stdout);
    #endif
    std::cout << "Testing?" << std::endl;
    int t, n, k;
    std::cin >> t;
    for (int i=0; i<t; i++)
    {
        unsigned long h[MAX_LENGTH] = {0}; // heights
        bool isPeak[MAX_LENGTH] = {false}; 
        unsigned int p[MAX_LENGTH] = {0}; // peaks
        unsigned int p_count[MAX_LENGTH] = {0};
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
        for (int j=0; j<n; j=j++)
        {
            int p_end = j + k - 1;
            if (p_end > n)
                p_end = n;
            for (int ii=j; ii<p_end; ii++)
            {
                if (isPeak[ii])
                    p_count[j] = p_count[j+1];
            }
        }
        // Find maximum.
        unsigned int max = 0;
        unsigned int max_ind = 0;
        for (int ind=0; ind<n; ind++)
        {
            if (p_count[ind] > max)
            {
                max = p_count[ind];
                max_ind = ind;
            }
        }
        
        std::cout << max << " " << max_ind << std::endl;
    }
    return 0;
}