#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int Creare_Matrice_Adiacenta_Orientat (int** &v, int n, int m, ifstream& fin) {
    int i, j;
    for (int it = 0; it < m; it++) {
        fin >> i >> j;
        v[i][j] = 1;
    }
    return 0;
}

int Creare_Matrice_Adiacenta_Neorientat (int** &v, int n, int m, ifstream& fin) {
    v = new int* [n];
    int i, j;
    for (i = 0; i < n; i++) {
        v[i] = new int [n] ();
    }
    for (int it = 0; it < m; it++) {
        fin >> i >> j;
        v[i][j] = 1;
        v[j][i] = 1;
    }
    return 0;
}

int Afisare_Matrice_Adiacenta (int** &v, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int Creare_Lista_Adiacenta_Orientat (vector <int> v[], int m, ifstream &fin) {
    int i, j;
    for (int it = 0; it < m; it++) {
        fin >> i >> j;
        v[i].push_back(j);
    }
    return 0;
}

int Creare_Lista_Adiacenta_Neorientat (vector <int> v[], int m, ifstream &fin) {
    int i, j;
    for (int it = 0; it < m; it++) {
        fin >> i >> j;
        v[i].push_back(j);
        v[j].push_back(i);
    }
    return 0;
}

int Afisare_Lista_Adiacenta (vector <int> v[], int n) {
    for (int i = 1; i < n; i++) {
            cout << i << ": ";
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";

            cout << endl;
    }
    return 0;
}

int Trecere_Matrice_la_Lista (int** v, int n, vector <int> vlist[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1)  vlist[i].push_back(j);
        }
    }
    return 0;
}

int Trecere_Lista_la_Matrice (vector <int> vlist[], int nlist, int** v) {
    for (int i = 0; i < nlist; i++) {
        for (int j = 0; j < vlist[i].size(); j++) {
            v[i][ vlist[i][j] ] = 1;
        }
    }
}

int main()
{
    ifstream fin ("graf.in");
    if (!fin.is_open())  cout << "Eroare la deschiderea fisierului!" << endl;

    int n, m;
    fin >> n;
    n++;
    fin >> m;

    vector <int> vlist[n];
    int** v;
    v = new int* [n];
    for (int i = 0; i < n; i++) {
        v[i] = new int [n] ();
    }

    Creare_Lista_Adiacenta_Neorientat(vlist, m, fin);
    Afisare_Lista_Adiacenta(vlist, n);
    Trecere_Lista_la_Matrice(vlist, n, v);
    Afisare_Matrice_Adiacenta(v, n);

    for (int i = 0; i < n; i++) {
        delete [] v[i];
    }
    delete []v;
    return 0;
}
