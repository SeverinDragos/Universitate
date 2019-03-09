#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int Cauta(char* sir, int lungime, char cautat) {
  for (int i = 0; i < lungime; i++) {
    if (sir[i] == cautat) return i;
  }
  return -1;
}

int main()
{
  ifstream fin ("Mereu.in");
  if (!fin.is_open())
    cout << "Eroare la deschiderea fisierului" << endl;
  int nr_stari, lungime_alfabet, nr_stari_finale, modificat, i, j, aux, ind;
  char *alfabet, *stari, *stari_finale, *p, *s;
  char stare_initiala, caracter;

  /**Citire stari*/
  fin >> nr_stari;
  fin.get();
  stari = new char [nr_stari];
  s = new char [nr_stari * 3];
  fin.getline(s, nr_stari * 3);
  p = strtok(s, " ,;{}");
  i = 0;
  while (p) {
    stari[i++] = p[0];
    p = strtok(NULL, " ,;{}");
  }
  delete []s;

  /**Citire alfabet*/
  fin >> lungime_alfabet;
  fin.get();
  alfabet = new char [lungime_alfabet / 2];
  s = new char [lungime_alfabet * 3];
  fin.getline(s, lungime_alfabet * 3);
  strcpy(alfabet, "");
  p = strtok(s, " ,;{}");
  while (p) {
    strcat(alfabet, p);
    p = strtok(NULL, " ,;{}");
  }
  delete []s;

  /**Citire stare initiala si stari finale*/
  fin >> stare_initiala;
  fin >> nr_stari_finale;
  fin.get();
  stari_finale = new char [nr_stari_finale];
  s = new char [nr_stari_finale * 3];
  fin.getline(s, nr_stari_finale * 3);
  p = strtok(s, " ,;{}");
  i = 0;
  while (p) {
    stari_finale[i++] = p[0];
    p = strtok(NULL, " ,;{}");
  }
  delete []s;

  /**Citire tranzitii*/
  char Tranzitii[nr_stari][lungime_alfabet];
  s = new char [10];
  while (fin.getline(s, 10)) {
  p = strtok(s, " ,;()");
  i = Cauta(stari, nr_stari, p[0]);
  p = strtok(NULL, " ,;()");
  caracter = p[0];
  p = strtok(NULL, " ,;()");
  j = Cauta(alfabet, lungime_alfabet, p[0]);
  Tranzitii[i][j] = caracter;
  }
  delete []s;

  cout << "   ";
  for (i = 0; i < lungime_alfabet; i++)
    cout << alfabet[i] << " ";
  cout << endl;
  for (i = 0; i < nr_stari; i++) {
    cout << stari[i] << ": ";
    for (int j = 0; j < lungime_alfabet; j++) {
      cout << Tranzitii[i][j] << " ";
    }
    cout << endl;
  }

  /**Pasul 1: Completare tabel*/
  int Tabel[nr_stari][nr_stari];
  memset(Tabel, 0, nr_stari * nr_stari * sizeof(int));

  //Starile finale cu nefinale
  for (int y = 0; y < nr_stari_finale; y++) {
    i = Cauta(stari, nr_stari, stari_finale[y]);
    for (j = 0; j < nr_stari; j++) { //linie
      if ( Cauta(stari_finale, nr_stari_finale, stari[j]) == -1 ) {
       (i < j) ? Tabel[j][i] = 1 : Tabel[i][j] = 1;
      }
    }
  }

  //Finalizare tabel
  do {
  modificat = 0;
  for (i = 0; i < nr_stari; i++) {
    for (j = 0; j < nr_stari; j++) {
      if (i > j)
        if (Tabel[i][j] == 0) {
          int indice1, indice2, val;
          for (int alf = 0; alf < lungime_alfabet; alf++) {
            indice1 = Cauta(stari, nr_stari, Tranzitii[i][alf]);
            indice2 = Cauta(stari, nr_stari, Tranzitii[j][alf]);
            val = (indice1 < indice2) ? Tabel[indice2][indice1] : Tabel[indice1][indice2];
            if (val == 1) {
              Tabel[i][j] = 1;
              modificat = 1;
            }
          }
        }
    }
  }
  }while (modificat == 1);

  /*
  for (i = 0; i < nr_stari; i++) {
    for (j = 0; j < nr_stari; j++)
      cout << Tabel[i][j] << " ";
    cout << endl;
  } */

  /**Pasul 2: Determinare stari noi*/
  vector < vector <int> > v;
  vector <int> gol;
  vector <int> avem_0;
  for (i = 0; i < nr_stari; i++) {
    avem_0.clear();
    for (j = 0; j < nr_stari; j++) {
      if (i > j) {
        if (Tabel[i][j] == 0)  avem_0.push_back(j);
      }
    }

    if (avem_0.size() == 0) {
      v.push_back(gol);
      for (int y = 0; y < v.size(); y++) {
        if (v[y].empty())
          v[y].push_back(i);
      }
    }

    else {
      vector <int> aux;
      aux.push_back(i);
      for (int k = 0; k < avem_0.size(); k++) {
      for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
          if (v[i][j] == avem_0[k]) {
            for (int h = 0; h < v[i].size(); h++) {
              aux.push_back(v[i][h]);
            }
            v.erase(v.begin() + i);
          }
        }
      }
      }
      v.push_back(aux);
      aux.clear();
    }
  }

  int stare_initiala_noua, stari_finale_noi[nr_stari_finale];
  aux = Cauta(stari, nr_stari, stare_initiala);
  ind = 0;
  for (int y = 0; y < v.size(); y++) {
    for (int k = 0; k < v[y].size(); k++) {
      int rez = Cauta(stari_finale, nr_stari_finale, stari[v[y][k]]);
      if (rez != -1) {
        stari_finale_noi[ind++] = y;
        break;
      }
    }
  }

  for (int y = 0; y < v.size(); y++)
    for (int k = 0; k < v[y].size(); k++)
      if (v[y][k] == aux)
        stare_initiala_noua = v[y][k];

  cout << "Noile stari: " << endl;
  for (int y = 0; y < v.size(); y++) {
    for (int k = 0; k < v[y].size(); k++) {
      cout << stari[ v[y][k] ] << " ";
    }
    cout << endl;
  }

  /**Pasul 3: Creare automat minimal*/
  int Tranzitii_noi[v.size()][lungime_alfabet];
  int stare_veche, indice;
  for (i = 0; i < v.size(); i++) { // linia: i
    for (int alf = 0; alf < lungime_alfabet; alf++) { // coloana: alf
      stare_veche = Cauta (stari, nr_stari, Tranzitii[ v[i][0] ][alf]);
      if (stare_veche != -1) {
      for (int y = 0; y < v.size(); y++) {
        for (int k = 0; k < v[y].size(); k++) {
          if (v[y][k] == stare_veche) {
            indice = y;
          }
        }
      }
      Tranzitii_noi[i][alf] = indice;
      }
      else
        Tranzitii_noi[i][alf] = -1;
    }
  }

  cout << "   ";
  for (i = 0; i < lungime_alfabet; i++)
    cout << alfabet[i] << " ";
  cout << endl;
  for (i = 0; i < v.size(); i++) {
    cout << stari[i] << ": ";
    for (j = 0; j < lungime_alfabet; j++) {
      if (Tranzitii_noi[i][j] != -1)
      cout << stari[Tranzitii_noi[i][j]] << " ";
      else
      cout << "- ";
    }
    cout << endl;
  }

  cout << "Stare initiala: " << stari[stare_initiala_noua] << endl << "Stari finale: ";
  for (int j = 0; j < ind; j++) {
    cout << stari[stari_finale_noi[j]] << " ";
  }


  /*Afisare Tranzitii
  for (i = 0; i < nr_stari; i++) {
    for (int j = 0; j < lungime_alfabet; j++) {
      cout << Tranzitii[i][j] << " ";
    }
    cout << endl;
  }*/

  /*Afisare Tabel
  for (i = 0; i < nr_stari; i++) {
    for (j = 0; j < nr_stari; j++)
      cout << Tabel[i][j] << " ";
    cout << endl;
  }*/

  delete []alfabet;
  delete []stari;
  delete []stari_finale;
  return 0;
}

