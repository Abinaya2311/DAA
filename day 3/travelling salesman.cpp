#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 15;
const int INF = 1e9;

int n;
int dist[MAX_N][MAX_N];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    int ans = INF;

    for (int city = 0; city < n; ++city) {
        if (!(mask & (1 << city))) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return ans;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the distance matrix (use INF for unreachable):" << endl;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];

    memset(dist, -1, sizeof(dist));

    cout << "The minimum distance for the TSP is: " << tsp(1, 0) << endl;

    return 0;
}
