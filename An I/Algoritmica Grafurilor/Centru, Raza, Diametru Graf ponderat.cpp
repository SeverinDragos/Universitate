#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

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
  int* excentricitate = new int [n + 1];
  memset(excentricitate, 0, sizeof(int) * (n + 1));

  /**Initializare matrice de drumuri */
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[i][j] = 999999;
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
      if (d[i][j] != 999999)
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

  /**Determinare excentricitati*/
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        if (d[i][j] != 999999)
          if (d[i][j] > excentricitate[i])
            excentricitate[i] = d[i][j];
      }
    }
  }

  int diam = 0, raza = 999999, retin;
  for (int i = 1; i <= n; i++) {
    if (excentricitate[i] > diam) {
      diam = excentricitate[i];
      retin = i;
    }
    if (excentricitate[i] < raza)
      raza = excentricitate[i];
  }
  vector <int> centru;
  for (int i = 1; i <= n; i++) {
    if (excentricitate[i] == raza)
    centru.push_back(i);
  }

  cout << "Diametru: " << diam << endl << "Raza: " << raza << endl << "Centru: ";
  for (int i = 0; i < centru.size(); i++) {
    cout << centru[i] << " ";
  }

  cout << "Lant diametral: ";
  for (int i = 1; i <= n; i++)
    if (d[retin][i] == diam)  drum(retin, i);
/* Afisare matrice de drumuri
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << d[i][j] << " ";
    }
    cout << endl;
  }
*/

  delete []excentricitate;
  fin.close();
  return 0;
}

