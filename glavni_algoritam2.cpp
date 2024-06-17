#include<iostream>
#include<filesystem>
#include<vector>
#include<fstream> 
#include<string>


using namespace std;

void upis_u_niz(ifstream& fajl_varijacije,int niz[2000]){
    int i = 1;
    fajl_varijacije.open("set_tmp.txt");   

    if(fajl_varijacije.is_open()) { 

    //cout << "success" << endl; // provera da je uspesno otvoren fajl
        while (!fajl_varijacije.eof()){
        fajl_varijacije >> niz[i];
        // cout << "ovo je redni broj varijacije i varijacija: " << i << ' ' <<  niz[i] <<'\n'; znam da uspesno upisuje u niz
        if(i==1296) break; // da ne bi ispisao 1297 elemenata
        i=i+1;
        }
    }
    else cout << "error: could not open file" << endl;

        fajl_varijacije.close();
}

void niz_u_vector(int niz[2000], vector<int> &varijacije){
    for(int i = 0; i < 2000; i++){
        varijacije.push_back(niz[i]);
        //cout << "vektor: " << varijacije[i] << endl;
        if(i == 1296) break;   
    }
}

void tok_igre(){
 
}

int main(){
    const int znak = 6, polja = 4;
    int varijacije_niz[2000];
    vector<int> varijacije_v;
    ifstream fajl;

    upis_u_niz(fajl,varijacije_niz);
    niz_u_vector(varijacije_niz, varijacije_v);



    //ovo dole su samo provere da se vidi upisano li je sve kako treba
    //cout << size(varijacije_niz) << endl;
   /* for(int i = 0; i < varijacije_v.size(); i++){
        cout << i << ' ' <<varijacije_v[i] << endl;
    }*/

    return 0;
}
