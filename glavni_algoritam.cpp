#include<iostream>
#include<filesystem>
#include<vector>
#include<fstream> 
#include<string>
#include<sstream>

using namespace std;

const int znak = 6, polja = 4; /// znak(kao u slagalici), i broj polja koja se unose
vector<int> varijacije;
string sve_varijacije; // string u koji ubacimo sve iz txt fajla
string varijacija; // ovde se izdvajaju posebne varijacije


std::ifstream fajl_varijacije("set.txt"); 


void ispisivanje() 
{  
     fajl_varijacije.open("set.txt", ifstream::in);

    if(fajl_varijacije.is_open()) { 
    cout << "uspesno" << endl;
   
    stringstream varijacije_stream(sve_varijacije); 

    while( getline(fajl_varijacije, sve_varijacije)){ 

        while( getline(varijacije_stream, varijacija, ' ')){

            if (varijacija.size() == polja) { // osigura da se u vektor uvek upise tacan broj znakova
            int varijacija_int = stoi(varijacija);
            varijacije.push_back(varijacija_int);
            }


        }
    }


    }
    
    else cout << "error: could not open file" << endl;

        fajl_varijacije.close();
    } 



int main()
{
    ispisivanje();
    for(int i = 0; i < varijacije.size(); i++){ //cisto radi provere da li se upisalo u vektor, za sad nije... // pogledati u "dokumentacija.txt"
        cout << varijacije[i] << '\n';
    }
}
