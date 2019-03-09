#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int contor = 1;

void Completare(int prima_linie, int prima_coloana, int ultima_linie, int ultima_coloana, int linie_lipsa, int coloana_lipsa, int** m) {
  if (ultima_linie - prima_linie == 1) {
    if (m[prima_linie][prima_coloana] == 0) m[prima_linie][prima_coloana] = contor;
    if (m[prima_linie][ultima_coloana] == 0) m[prima_linie][ultima_coloana] = contor;
    if (m[ultima_linie][prima_coloana] == 0) m[ultima_linie][prima_coloana] = contor;
    if (m[ultima_linie][ultima_coloana] == 0) m[ultima_linie][ultima_coloana] = contor;
    contor++;
  }
  else {
    if (linie_lipsa <= ultima_linie / 2 && coloana_lipsa <= ultima_coloana / 2) {/// II trigonometric
      m[(ultima_linie + prima_linie) / 2 + 1][(ultima_coloana + prima_coloana) / 2] = contor;
      m[(ultima_linie + prima_linie) / 2 + 1][(ultima_coloana + prima_coloana) / 2 + 1] = contor;
      m[(ultima_linie + prima_linie) / 2][(ultima_coloana + prima_coloana) / 2 + 1] = contor;
      contor++;
      Completare(prima_linie, prima_coloana, ultima_linie / 2, ultima_coloana / 2, linie_lipsa, coloana_lipsa, m);
      Completare(prima_linie, (prima_coloana + ultima_coloana) / 2 + 1, (prima_linie + ultima_linie) / 2, ultima_coloana, (ultima_linie + prima_linie) / 2, (ultima_coloana + prima_coloana) / 2 + 1, m);

    }
    if (linie_lipsa <= ultima_linie / 2 && coloana_lipsa > ultima_coloana / 2) {/// I
      m[(ultima_linie + prima_linie) / 2 + 1][(ultima_coloana + prima_coloana) / 2] = contor;
      m[(ultima_linie + prima_linie) / 2 + 1][(ultima_coloana + prima_coloana) / 2 + 1] = contor;
      m[(ultima_linie + prima_linie) / 2][(ultima_coloana + prima_coloana) / 2] = contor;
      contor++;
    }
    if (linie_lipsa > ultima_linie / 2 && coloana_lipsa <= ultima_coloana / 2) {/// III
      m[(ultima_linie + prima_linie) / 2][(ultima_coloana + prima_coloana) / 2 + 1] = contor;
      m[(ultima_linie + prima_linie) / 2 + 1][(ultima_coloana + prima_coloana) / 2 + 1] = contor;
      m[(ultima_linie + prima_linie) / 2][(ultima_coloana + prima_coloana) / 2] = contor;
      contor++;
    }
    if (linie_lipsa > ultima_linie / 2 && coloana_lipsa > ultima_coloana / 2) {
      m[(ultima_linie + prima_linie) / 2][(ultima_coloana + prima_coloana) / 2] = contor;
      m[(ultima_linie + prima_linie) / 2][(ultima_coloana + prima_coloana) / 2 + 1] = contor;
      m[(ultima_linie + prima_linie) / 2 + 1][(ultima_coloana + prima_coloana) / 2] = contor;
      contor++;
    }
  }
}

int main()
{
  ifstream fin ("piese.in");
  ofstream fout ("piese.out");
  int n, linie_lipsa, coloana_lipsa;
  fin >> n >> linie_lipsa >> coloana_lipsa;
  int** m = new int*[n];
  for (int i = 0; i < n; i++) {
    m[i] = new int[n];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      m[i][j] = 0;
    }
  }
  m[linie_lipsa][coloana_lipsa] = -1;

  Completare(0, 0, n - 1, n - 1, linie_lipsa, coloana_lipsa, m);

  for (int i = 0; i < n; i++) {
    delete m[i];
  }
  delete m;
  fin.close();
  fout.close();
  return 0;
}
