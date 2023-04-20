#include <bits/stdc++.h>
using namespace std;
 
#define N 7
 
const int dx[]{-1, 1, 0, 0}, dy[]{0, 0, -1, 1};
char letter[]{'U', 'D', 'L', 'R'};
 
string s;
array<bitset<N + 2>, N + 2> visited;
int ans = 0;
 
void bkt(int x, int y, int moves) {
  if (moves == N * N - 1) {
    ans += x == N && y == 1;
    return;
  }
 
  if ((x == N && y == 1) || (N - x + y > N * N - moves))
    return;
 
  bool possible[4];
  for (int i = 0; i < 4; ++i)
    possible[i] = !visited[x + dx[i]][y + dy[i]];
 
  if ((possible[0] && possible[1] && !possible[2] && !possible[3]) ||
      (!possible[0] && !possible[1] && possible[2] && possible[3]))
    return;
 
  visited[x][y] = 1;
 
  for (int i = 0; i < 4; ++i)
    if (possible[i] && (s[moves] == '?' || s[moves] == letter[i]))
      bkt(x + dx[i], y + dy[i], moves + 1);
 
  visited[x][y] = 0;
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  for (int i = 0; i <= N + 1; ++i)
    visited[0][i] = visited[i][0] = visited[N + 1][i] = visited[i][N + 1] = 1;
 
  cin >> s;
 
  bkt(1, 1, 0);
 
  cout << ans << '\n';
}
