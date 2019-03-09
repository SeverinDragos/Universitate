#include <iostream>
#include <cstring>

using namespace std;

void afisare_string(int i, char* s, int* prev) {
  if (prev[i] > 0)  afisare_string(prev[i], s, prev);
  for (int j = prev[i] + 1; j <= i; j++) {
    cout << s[j - 1];
  }
  cout << " ";
}

int main()
{
  int M[50][50], n, l;
  char* s = new char[50];
  cout << "Introduceti sirul: ";
  cin >> s;
  n = strlen(s);
  for (int i = 0; i < n; i++)
  fill_n (M[i], n, 0);

  /*for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << M[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;*/

  for (l = 0; l <= n; l++) {
    for (int i = 1; i <= n; i++) {
      int j = i + l;
      if (l == 0) {
        M[i][j] = 1;
      }
      else if (l == 1) {
        if (s[i - 1] == s[j - 1])
          M[i][j] = 1;
        else
          M[i][j] = 0;
      }
      else {
        if (s[i - 1] == s[j - 1]) {
          M[i][j] = M[i + 1][j - 1];
        }
        else {
          M[i][j] = 0;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < n; j++) {
      if (i <= j)
        cout << M[i][j] << " ";
      else
        cout << "  ";
    }
    cout << endl;
  }

  int* L = new int[50];
  int* prev = new int[50];

  fill_n(prev, n, -1);
  L[0] = 0;

  for (int i = 1; i <= n; i++) {
    L[i] = i;
    for (int j = i; j > 0; j--) {
      if (M[j][i] == 1)
        if (L[j - 1] + 1 < L[i]) {
          L[i] = L[j - 1] + 1;
          prev[i] = j - 1;
        }
    }
  }

  for (int i = 0; i <= n; i++) {
    cout << L[i];
  }
  cout << endl;

  afisare_string(n, s, prev);

  return 0;
}
