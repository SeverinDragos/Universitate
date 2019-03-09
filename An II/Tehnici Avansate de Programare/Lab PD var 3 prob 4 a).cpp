#include <iostream>
#include <cstring>

using namespace std;

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

  for (l = 0; l < n; l++) {
    for (int i = 0; i < n; i++) {
      int j = i + l;
      if (l == 0) {
        M[i][j] = 1;
      }
      else if (l == 1) {
        if (s[i] == s[j])
          M[i][j] = 1;
        else
          M[i][j] = 0;
      }
      else {
        if (s[i] == s[j]) {
          M[i][j] = M[i + 1][j - 1];
        }
        else {
          M[i][j] = 0;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i <= j)
        cout << M[i][j] << " ";
      else
        cout << "  ";
    }
    cout << endl;
  }

  return 0;
}
