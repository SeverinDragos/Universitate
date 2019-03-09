#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

double mediana (int v[], int primul, int ultimul) {
  int n = ultimul - primul + 1;
  int mij = (primul + ultimul) / 2; /// (ultimul - primul) / 2 + primul
  if (n % 2 == 0)
    return (v[mij] + v[mij + 1]) / 2.0;
  return v[mij];
}

double MedianaInterclasare (int A[], int primulA, int ultimulA, int B[], int primulB, int ultimulB) {
  int n = ultimulA - primulA + 1;
  if (n <= 2)
    return (max(A[primulA], B[primulB]) + min(A[ultimulA], B[ultimulB]) ) / 2.0;
  double medA = mediana(A, primulA, ultimulA);
  double medB = mediana(B, primulB, ultimulB);
  if (medA == medB) return medA;
  if (medA > medB)  return MedianaInterclasare(A, primulA, primulA + n / 2, B, primulB + (n - 1) / 2, ultimulB);
  return MedianaInterclasare(A, primulA + (n - 1) / 2, ultimulA, B, primulB, primulB + n / 2);
}

int main()
{
  ifstream fin ("Mediana Interclasata.in");
  ofstream fout ("Mediana Interclasata.out");

  int n;
  fin >> n;
  int A[n], B[n];
  for (int i = 0; i < n; i++) {
    fin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    fin >> B[i];
  }
  cout << mediana(A, 0, n - 1);
  cout << mediana(B, 0, n - 1);

  fout << MedianaInterclasare(A, 0, n - 1, B, 0, n - 1);

  fin.close();
  fout.close();
  return 0;
}
