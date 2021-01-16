#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve2(vector<vector<int>>& table, int N, int M) {
    int sum = 0;
    for (int i = 0; i <= (N - 1) / 2; i++) {
        for (int j = 0; j <= (M - 1) / 2; j++) {
            int aver = (table[i][j] + table[N - 1 - i][j] + table[i][M - 1 - j] + table[N - 1 - i][M - 1 - j]) / 4;
            int aver1 = aver + 1;
            int r = (abs(table[i][j] - aver) + abs(table[N - 1 - i][j] - aver) + abs(table[i][M - 1 - j] - aver) + abs(table[N - 1 - i][M - 1 - j] - aver)) > (abs(table[i][j] - aver1) + abs(table[N - 1 - i][j] - aver1) + abs(table[i][M - 1 - j] - aver1) + abs(table[N - 1 - i][M - 1 - j] - aver1)) ? aver1 : aver;
            if (N % 2 && i == (N - 1) / 2) {
                if (M % 2 && j == (M - 1) / 2)
                    sum += abs(table[i][j] - r);
                else
                    sum += abs(table[i][j] - r) + abs(table[i][M - 1 - j] - r);
            }
            else {
                if (M % 2 && j == ((M - 1) / 2))
                    sum += abs(table[i][j] - r) + abs(table[N - 1 - i][j] - r);
                else
                    sum += abs(table[i][j] - r) + abs(table[N - 1 - i][j] - r) + abs(table[i][M - 1 - j] - r) + abs(table[N - 1 - i][M - 1 - j] - r);
            }
            /*else {
                sum += abs(table[i][j] - r) + abs(table[N - 1 - i][j] - r) + abs(table[i][M - 1 - j] - r) + abs(table[N - 1 - i][M - 1 - j] - r);
            }*/
            table[i][j] = r;
            table[N - 1 - i][j] = r;
            table[i][M - 1 - j] = r;
            table[N - 1 - i][M - 1 - j] = r;

        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << table[i][j]<<'\t';
        }
        cout << endl;
    }
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    int N, M;
    int x;
    while (t--) {
        cin >> N >> M;
        vector<vector<int>> table(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> x;
                table[i][j] = x;
            }
        }
        solve2(table, N, M);
    }
}