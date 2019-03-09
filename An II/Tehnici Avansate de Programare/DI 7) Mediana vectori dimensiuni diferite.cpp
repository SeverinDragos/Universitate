#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

double MedianaDupaInterclasare (int A[], int n, int primulA, int ultimulA, int B[], int m) {
  if (primulA <= ultimulA) {
    int partitionA = (primulA + ultimulA + 1) / 2;
    int partitionB = (n + m + 1) / 2 - partitionA;
    int maxleftA = (partitionA == 0) ? INT_MIN : A[partitionA - 1];
    int minrightA = (partitionA == n) ? INT_MAX : A[partitionA];
    int maxleftB = (partitionB == 0) ? INT_MIN : B[partitionB - 1];
    int minrightB = (partitionB == m) ? INT_MAX : B[partitionB];
    cout << maxleftA << " " << minrightA << endl << maxleftB << " " << minrightB << endl;
    if (maxleftA <= minrightB && maxleftB <= minrightA) {
      if ((n + m) % 2 == 0)
        return (max(maxleftA, maxleftB) + min(minrightA, minrightB) ) / 2.0;
      return max(maxleftA, maxleftB);
    }
    if (maxleftA > minrightB)
      return MedianaDupaInterclasare(A, n, primulA, partitionA - 1, B, m);
    return MedianaDupaInterclasare(A, n, partitionA + 1, ultimulA, B, m);
  }
}

int main()
{
  ifstream fin ("Mediana interclasata de dimensiuni diferite.in");
  ofstream fout ("Mediana interclasata de dimensiuni diferite.out");

  int n, m;
  fin >> n >> m;
  int A[n], B[m];
  for (int i = 0; i < n; i++) {
    fin >> A[i];
  }
  for (int i = 0; i < m; i++) {
    fin >> B[i];
  }

  if (n > m)
  fout << MedianaDupaInterclasare(B, m, 0, m - 1, A, n);
  else
  fout << MedianaDupaInterclasare(A, n, 0, n - 1, B, m);

  fin.close();
  fout.close();
  return 0;
}
