#include <iostream>
#include <fstream>

using namespace std;

int p[100][100];

void drum (int i, int j) {
  if (i != j)
    drum (i, p[i][j]);
  cout << j << " ";
}

int main()
{
  ifstream fin ("graf.in");
  if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

  int n, m, u, v, cost;
  fin >> n >> m;
  int d[n + 1][n + 1];

  /**Initializare matrice de drumuri */
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = 999999999;
    }
  }

  /**Citire drumuri*/
  for (int i = 0; i < m; i++) {
    fin >> u >> v >> cost;
    d[u][v] = cost;
  }

  /**Initializare matrice de predecesori*/
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d[i][j] != 999999999)
        p[i][j] = i;
    }
  }

  /**Implementare Roy-Floyd*/
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
          p[i][j] = p[k][j];
        }
      }

/* Afisare matrice de drumuri
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << d[i][j] << " ";
    }
    cout << endl;
  }
*/

  fin.close();
  return 0;
}

