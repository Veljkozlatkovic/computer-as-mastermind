#include<bits/stdc++.h>

using namespace std;
namespace fs=std::filesystem;

// ispisuje tekucu varijaciju na standardni izlaz
void obradi(const vector<int>& varijacija) {

ofstream outputFile("set.txt");

    outputFile.open("set.txt");

 if(outputFile.is_open()) { //! ovde zariba //////////////////
    cout << "uspesno" << endl;
    }
  for (int x : varijacija)
    cout << x;
  cout << " ";

//TODO: kako da se ovi brojevi ispisu u fajl umesto u terminal
//! /////////////////////////////////////////////////////

for (int x : varijacija)
    outputFile << x;
outputFile << ' ';
outputFile.close();
//!


}

// Sve varijacije duzine k elemenata skupa {1, ..., n}
// Data varijacija sa ponavljanjem duzine m se dopunjuje svim mogucim
// varijacijama sa ponavljanjem duzine n-m skupa {1, ..., n} i sve
// tako dobijene varijacije se obrađuju funkcijom obradi

void obradiSveVarijacije(int n, vector<int>& varijacija, int m) {
  // m je n, pa se trenutna varijacija ne moze vise dopuniti
  if (m == varijacija.size())
    obradi(varijacija);
  else
    // na tekucu poziciju postavljamo sve moguce vrednosti od 1 do n i 
    // dobijeni niz onda rekurzivno proširujemo
    for (int nn = 1; nn <= n; nn++) {
       varijacija[m] = nn;
       obradiSveVarijacije(n, varijacija, m+1);
    }
}


// sve varijacije duzine k skupa {1, ..., n}
void obradiSveVarijacije(int k, int n) {
  vector<int> varijacija(k);
  obradiSveVarijacije(n, varijacija, 0);
}


int main() {
  int n = 6, k = 4;
  obradiSveVarijacije(k, n);
  return 0;
}



/*
#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    ofstream outFile;
    outFile.open("setic.txt");

    if(outFile.fail()){
        cout << "error" << endl;
        return 1;
    }

    for(auto element:a){
        outFile << element << endl;
    }

    outFile.close();


}
*/