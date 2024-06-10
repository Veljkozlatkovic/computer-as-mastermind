#include<bits/stdc++.h> // kod uzet sa petlje, samo je dodat deo za upisivanje u fajl. koji nisam siguran da radi

using namespace std;
namespace fs=std::filesystem;


void obradi(const vector<int>& varijacija) {

ofstream outputFile("set.txt");

    outputFile.open("set.txt");
//! ////////////////////////////////////////////////////
 if(outputFile.is_open()) {
    cout << "uspesno" << endl;
    }
  for (int x : varijacija)
    cout << x;
  cout << " ";
//! /////////////////////////////////////////////////////

for (int x : varijacija)
    outputFile << x;
outputFile << ' ';
outputFile.close();
//!


}

void obradiSveVarijacije(int n, vector<int>& varijacija, int m) {
  if (m == varijacija.size())
    obradi(varijacija);
  else
    for (int nn = 1; nn <= n; nn++) {
       varijacija[m] = nn;
       obradiSveVarijacije(n, varijacija, m+1);
    }
}

void obradiSveVarijacije(int k, int n) {
  vector<int> varijacija(k);
  obradiSveVarijacije(n, varijacija, 0);
}


int main() {
  int n = 6, k = 4;
  obradiSveVarijacije(k, n);
  return 0;
}



outFile.close();


}
*/
