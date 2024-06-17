#include<iostream> //GO TO: "glavni_algoritam2.cpp"
#include<filesystem>
#include<vector>
#include<fstream> 
#include<string>
#include<sstream>

using namespace std;



void ispisivanje(int polja, vector<int>&varijacije, string sve_varijacije,
                 string varijacija, ifstream& fajl_varijacije) 
{  
     fajl_varijacije.open("set.txt", ifstream::in);

    if(fajl_varijacije.is_open()) { 
    cout << "success" << endl;

    fajl_varijacije >> sve_varijacije;// cisto radi testa da se vidi radi li
    cout << sve_varijacije << endl;   // iz nekog razloga nece ni ovo ni getline
    getline(fajl_varijacije,sve_varijacije);
    cout << sve_varijacije << endl;
   
        while( getline(fajl_varijacije, sve_varijacije) ){ 

            stringstream varijacije_stream{sve_varijacije};
            cout << "..." << endl; // just to check if it even enters the loop

            while( getline(varijacije_stream, varijacija, ' ')){

                if (varijacija.size() == polja) {                                                               // osigura da se u vektor uvek upise tacan broj znakova
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
    const int znak = 6, polja = 4; /// znak(kao u slagalici), i broj polja koja se unose
    vector<int> varijacije;
    string sve_varijacije; // string u koji ubacimo sve iz txt fajla
    string varijacija; // ovde se izdvajaju posebne varijacije
    std::ifstream fajl_varijacije("set.txt"); 

    ispisivanje(polja, varijacije, sve_varijacije, varijacija, fajl_varijacije);

    for(int i = 0; i < varijacije.size(); i++){ 
        cout << varijacije[i] << '\n';
    }
}
