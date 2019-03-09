#include <iostream>
#include <cstring>

using namespace std;

struct obiect {
  int profit, greutate;
};

int main()
{
  int n, G;
  cout << "n = ";
  cin >> n;
  cout << "G = ";
  cin >> G;
  struct obiect v[n];
  int D[n][G];
  for(int i = 0; i < n; i++) {
    cout << "Profit = ";
    cin >> v[i].profit;
    cout << "Greutate = ";
    cin >> v[i].greutate;
  }

  for (int i = 0; i <= n; i++)
  fill_n(D[i], G + 1 ,0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= G; j++) {
      if (i == 0) {
        if (j >= v[i].greutate)
          D[i][j] = v[i].profit;
      }
      else {
        if (j < v[i].greutate)
          D[i][j] = D[i - 1][j];
        else {
          D[i][j] = max(D[i - 1][j], v[i].profit + D[i - 1][j - v[i].greutate]);
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= G; j++) {
      cout << D[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
