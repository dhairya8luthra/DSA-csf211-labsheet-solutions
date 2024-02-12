#include <stdio.h>

int *findCombination(int n, int kira_wins, int nom_wins, int result_arr[])
{
    // base case: when kira_wins and nom_wins are over
    // or when index reaches n
    if (index == n)
    {
        int consWins = countConsecutiveWins();
        int noOfKiraWinsinLeft = KiraWinsInLeft();
        if (consWins < minConsWins)
        {
            if (noOfKiraWinsinLeft < minKiraWinsinLeft)
            {
                return result_arr;
            }
        }
        else
        {
            return [0];
        }
        else
        {
            result_arr[index] = 1;
            findCombination();
            result_arr[index] = 0;
            findCombination();
        }
    }
}

int main()
{
    // taking input
    int n, kira_wins, nom_wins;
    scanf("%d", &n);
    scanf("%d", &kira_wins);
    scanf("%d", &nom_wins);
    //
    // approach no need to simulate strings we take 1 for kira win and 0 for nom win
    // backtrack for all combinations
    // keep in account the minimums
    int result_arr[n] = {-1};
    int index = 0;
    result_arr = findCombination(n, kira_wins, nom_wins, result_arr, index);
}