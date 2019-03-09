#include <iostream>

using namespace std;

int M[15][15], Cost[15][15], pred[15][15];

void Afisare (int i, int j) {
  if (pred[i][j] != 0)
    if (pred[i][j] == 1)
      Afisare(i - 1, j);
    else
      Afisare(i, j - 1);
  cout << i << " " << j << endl;
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> M[i][j];
  Cost[1][1] = M[1][1];
  pred[1][1] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i - 1 >= 0)
        if (M[i - 1][j] + M[i][j] > Cost[i][j]) {
          pred[i][j] = 1;
          Cost[i][j] = Cost[i - 1][j] + M[i][j];
        }
      if (j - 1 >= 0)
        if (M[i][j - 1] + M[i][j] > Cost[i][j]) {
          pred[i][j] = 2;
          Cost[i][j] = Cost[i][j - 1] + M[i][j];
        }
    }

    cout << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++)
        cout << Cost[i][j] << " ";
      cout << endl;
    }
    cout << endl;
    cout << Cost[n][m] << endl;
    Afisare(n, m);
  return 0;
}
