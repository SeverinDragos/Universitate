#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin ("Distanta Levenstein.in");
ofstream fout ("Distanta Levenstein.out");
int pred[100][100];

int min(int x, int y, int z)
{
  return min(min(x, y), z);
}

void Afisare(char s1[], char s2[], int i, int j) {
  switch(pred[i][j]) {
    case 1:
      Afisare(s1, s2, i - 1, j - 1);
      fout << "Pastram " << s1[i - 1] << "\n";
      break;
    case 2:
      Afisare(s1, s2, i, j - 1);
      fout << "Inseram " << s2[j - 1] << "\n";
      break;
    case 3:
      Afisare(s1, s2, i - 1, j);
      fout << "Stergem " << s1[i - 1] << "\n";
      break;
    case 4:
      Afisare(s1, s2, i - 1, j - 1);
      fout << "Inlocuim " << s1[i - 1] << " cu " << s2[j - 1] << "\n";
      break;
    case 0:
      break;
  }
}

int main()
{
  char s1[100], s2[100];
  fin.get(s1, 100);
  fin.get();
  fin.get(s2, 100);
  int n = strlen(s1);
  int m = strlen(s2);

  int dp[n + 1][m + 1];
  int cost[3];
  for (int i = 0; i < 3; i++) {
    fin >> cost[i];
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0)  dp[i][j] = max(i,j);
      else if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
        pred[i][j] = 1; ///Pastrare
      }
      else {
        int minim = 999999;
        if (dp[i][j - 1] < minim) {
          minim = dp[i][j - 1];
          pred[i][j] = 2; ///Inserare
        }
        if (dp[i - 1][j] < minim) {
          minim = dp[i - 1][j];
          pred[i][j] = 3; ///Stergere
        }
        if (dp[i - 1][j - 1] < minim) {
          minim = dp[i - 1][j - 1];
          pred[i][j] = 4; ///Inlocuire
        }
        dp[i][j] = cost[pred[i][j] - 2] + minim;
      }
        /*dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                              dp[i-1][j],  // Remove
                              dp[i-1][j-1]); // Replace*/
    }
  }

  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < m + 1; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  fout << dp[n][m] << "\n";
  Afisare(s1, s2, n, m);

  fin.close();
  fout.close();
  return 0;
}
