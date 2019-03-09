#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

void Completare(int prima_linie, int prima_coloana, int ultima_linie, int ultima_coloana, int** m, int& count) {
  if (ultima_linie - prima_linie == 1)  {
    m[prima_linie][ultima_coloana] = ++count;
    m[ultima_linie][prima_coloana] = ++count;
    m[prima_linie][prima_coloana] = ++count;
    m[ultima_linie][ultima_coloana] = ++count;
  }
  else {
    Completare(prima_linie, (prima_coloana + ultima_coloana) / 2 + 1, (prima_linie + ultima_linie) / 2, ultima_coloana, m, count);///I
    Completare((prima_linie + ultima_linie) / 2 + 1, prima_coloana, ultima_linie, (prima_coloana + ultima_coloana) / 2, m, count);///III
    Completare(prima_linie, prima_coloana, (prima_linie + ultima_linie) / 2, (prima_coloana + ultima_coloana) / 2, m, count);///II
    Completare((prima_linie + ultima_linie) / 2 + 1, (prima_coloana + ultima_coloana) / 2 + 1, ultima_linie, ultima_coloana, m, count);///IV
  }
}

int main()
{
  int n, count = 0, shift;
  cin >> shift;
  n = 1 << shift;
  int** m = new int*[n];
  for (int i = 0; i < n; i++) {
    m[i] = new int[n];
  }
  Completare(0, 0, n - 1, n - 1, m, count);


  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < n; i++) {
    delete m[i];
  }
  delete m;
  return 0;
}
