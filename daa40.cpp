#include <stdio.h>
#define INF 999999
int n = 4;
int dist[4][4] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};
int dp[16][4];
int min(int a, int b) {
    return (a < b) ? a : b;
}
int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return dist[pos][0];
    if (dp[mask][pos] != -1)
        return dp[mask][pos];
    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}
int main() {
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    int result = tsp(1, 0);
    printf("The minimum travel cost is: %d\n", result);
    return 0;
}

