#include <iostream>

using namespace std;

struct punct {
  float x, y, z;
};

int coordonate_identice(struct punct& A1, struct punct& A2) {
  if (A1.x != A2.x)  return 0;
  if (A1.y != A2.y)  return 0;
  if (A1.z != A2.z)  return 0;
  return 1;
}

int main()
{
  punct A[4];
  for (int i = 1; i <= 3; i++) {
    cout << "Punctul A" << i << ":";
    cin >> A[i].x >> A[i].y >> A[i].z;
  }

  if (coordonate_identice(A[1], A[2]))  cout << "Punctele sunt coliniare" << endl << "A1 = 1 * A2 + 0 * A3" << endl;
  else
    if (coordonate_identice(A[1], A[3]))  cout << "Punctele sunt coliniare" << endl << "A1 = 1 * A3 + 0 * A2" << endl;
    else
      if (coordonate_identice(A[2], A[3]))  cout << "Punctele sunt coliniare" << endl << "A2 = 1 * A3 + 0 * A1" << endl;

      else { ///Suntem pe cazul I

        if (A[2].x - A[1].x) {
          float a = (A[3].x - A[1].x) / (A[2].x - A[1].x);
          if (A[3].y - A[1].y == a * (A[2].y - A[1].y))
            if (A[3].z - A[1].z == a * (A[2].z - A[1].z)) {
              cout << "Punctele sunt coloniare" << endl << "A3 = (1 - " << a << ") * A1 + " << a << " * A2";
              return 0;
            }
        }

        else
          if (A[2].y - A[1].y) {
            float a = (A[3].y - A[1].y) / (A[2].y - A[1].y);
            if (A[3].x - A[1].x == a * (A[2].x - A[1].x))
              if (A[3].z - A[1].z == a * (A[2].z - A[1].z)) {
                cout << "Punctele sunt coloniare" << endl << "A3 = (1 - " << a << ") * A1 + " << a << " * A2";
                return 0;
              }
          }

          else
            if (A[2].z - A[1].z) {
            float a = (A[3].z - A[1].z) / (A[2].z - A[1].z);
            if (A[3].x - A[1].x == a * (A[2].x - A[1].x))
              if (A[3].y - A[1].y == a * (A[2].y - A[1].y)) {
                cout << "Punctele sunt coloniare" << endl << "A3 = (1 - " << a << ") * A1 + " << a << " * A2";
                return 0;
              }
            }

        cout << "Punctele nu sunt coliniare";
      }
  return 0;
}
