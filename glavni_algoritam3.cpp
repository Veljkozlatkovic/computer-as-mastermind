#include<bits/stdc++.h>
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

    //cout << "success" << endl;
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

bool terminal_point(int blackhit){
    if(blackhit == 4) {
        return true;
    }

    else return false; 
}



void tok_igre(vector<int> & sve_varijacije, int brojac){

    int blackhit, whitehit; // brojac broji iz koliko pokusaja je pobedjena igra
    int pokusaj = 1122;
    cout << pokusaj << endl;
    vector<int> skor;
    while(!terminal_point(blackhit)){
        cout << "num of black hits: ";
        cin >> blackhit;
        cout << "num of white hits: ";
        cin >> whitehit;

        if(blackhit + whitehit > 4){
            cout << "pogresan unos" << endl;
            continue;
        } 
        vector<int>trenutne_moguce = sve_varijacije;

        //skorrenutne_moguce.size(); //! vektor koji cuva skor svakog moguceg pokusaja
       
       //*izdvajanje svakog elementa pokusaja racunara da bi se poredilo
        int prvi= pokusaj%10;      // ova 4 upise u nov vektor koji ce se element po element porediti sa svakom mogucom varijacijom k
        int drugi= (pokusaj/10)%10; // prolazi kroz vector sve_varijacije i svaki element stavi u svoj vector i poredi ga sa pogodkom
        int treci= (pokusaj/100)%10;// kad to uradi, one koji se poklapaju u broju bh i wh se stavljaju u vector trenutno moguce
        int cetvrti= pokusaj/1000;   // i posle cu da vidim sta cu za score. // pogledaj svesku

        vector<int> pokusaj_v = {cetvrti, treci, drugi, prvi};

      for(int i = 0; i < trenutne_moguce.size(); i++){ // ovaj for sluzi da smanji broj mogucih varijacija i stavi ih u nov vector
        //svaku mogucu varijaciju podeli na delove radi poredjenja sa pokusajem
        int prvi1 = trenutne_moguce[i] % 10;
        int drugi1 = (trenutne_moguce[i] / 10) % 10;
        int treci1 = (trenutne_moguce[i] / 100) %10;
        int cetvrti1 = trenutne_moguce[i]/1000; 
        vector<int> poredjenje_v = {cetvrti1, treci1, drugi1, prvi1};
        int bh = 0, wh = 0; // zamenske da se ne bi greskom izaslo iz petlje
        bool iskorisceni[4] = {false, false, false, false}; // sluzi da se ne bi slucajno proveravao element varijacije iz poredjenje_v koji vec ima bh      

        //prvo trazi samo bh
        for(int i = 0; i < pokusaj_v.size(); i++){
                if(pokusaj_v[i] == poredjenje_v[i]) {
                    bh++;
                    iskorisceni[i] = true;
                }}

        //zatim trazi samo wh, preskakajuci iskoriscena polja
        for(int i = 0; i < pokusaj_v.size(); i++){
            for(int j = 0; j < poredjenje_v.size(); j++){
                if(iskorisceni[j] != true){
                    if(pokusaj_v[i] == poredjenje_v[j]){
                        wh++;
                        iskorisceni[j] = true;
                    }
                }
            }
        }
        vector<int> nove_moguce;
        if(bh == blackhit && wh == whitehit){
            nove_moguce.push_back(trenutne_moguce[i]);
        }
        trenutne_moguce = nove_moguce;


      }


      // sada se odredjuje skor svakog moguceg koda 
      for(int i = 0; i < trenutne_moguce.size(); i++){

         int prvi1 = trenutne_moguce[i] % 10; // ove se sad koriste umesto onih koje su deklarisane van petlje
        int drugi1 = (trenutne_moguce[i] / 10) % 10;
        int treci1 = (trenutne_moguce[i] / 100) %10;
        int cetvrti1 = trenutne_moguce[i]/1000; 
        vector<int> svi_tacni_v = {cetvrti1, treci1, drugi1, prvi1};
        vector<int> svi_moguci = sve_varijacije;
        int bh = 0, wh = 0; // zamenske da se ne bi greskom izaslo iz petlje
        bool iskorisceni[4] = {false, false, false, false}; // sluzi da se ne bi slucajno proveravao element varijacije iz poredjenje_v koji vec ima bh      

            for(int j = 0; j < sve_varijacije.size(); j++){
                int prvi2 = svi_moguci[j] % 10; 
                 int drugi2 = (svi_moguci[j] / 10) % 10;
                 int treci2 = (svi_moguci[j] / 100) %10;
                 int cetvrti2 = svi_moguci[j]/1000; 
                 vector<int> jedan_pokusaj = {cetvrti2, treci2, drugi2, prvi2};
            //////////////////////////////////////////////////////
                 //prvo trazi samo bh
                for(int i1 = 0; i1 < jedan_pokusaj.size(); i1++){
                        if(jedan_pokusaj[i1] == svi_tacni_v[i1]) {
                            bh++;
                            iskorisceni[i1] = true;
                        }}
                 //samo wh
                for(int i2 = 0; i2 < jedan_pokusaj.size(); i2++){
                    for(int j2 = 0; j2 < svi_tacni_v.size(); j++){
                        if(iskorisceni[j2] != true){
                            if(jedan_pokusaj[i2] == svi_tacni_v[j2]){
                            wh++;
                            iskorisceni[j2] = true;
                            }
                        }
                    }
                }
                ///////////////////////////////////////
            //sad imam bh  i wh umesto blackhit i whitehit
                for(int k = 0; k < sve_varijacije.size(); k++) {
                    int prvi3 = svi_moguci[k] % 10; 
                 int drugi3 = (svi_moguci[k] / 10) % 10;
                 int treci3 = (svi_moguci[k] / 100) %10;
                 int cetvrti3 = svi_moguci[k]/1000; 
                 vector<int> novo_poredjenje = {cetvrti3, treci3, drugi3, prvi3};
                 int bh2 = 0, wh2 = 0;
                    //prvo trazi samo bh2
                for(int i1 = 0; i1 < novo_poredjenje.size(); i1++){
                        if(jedan_pokusaj[i1] == svi_tacni_v[i1]) {
                            bh2++;
                            iskorisceni[i1] = true;
                        }}
                 //samo wh2
                for(int i2 = 0; i2 < novo_poredjenje.size(); i2++){
                    for(int j2 = 0; j2 < svi_tacni_v.size(); j++){ //* new achivement: petostruka petlja
                        if(iskorisceni[j2] != true){
                            if(novo_poredjenje[i2] == svi_tacni_v[j2]){
                            wh2++;
                            iskorisceni[j2] = true;
                            }
                        }
                    }
                }
                vector<int> za_skor;

                    if(bh2 == bh && wh2 == wh){
                     za_skor.push_back(svi_moguci[k]);
                        }

                for( int z = 0; z < trenutne_moguce.size(); z++ ){
                    skor.push_back( sve_varijacije.size() - za_skor.size() );
                    
                }
                    int maxskor = *max_element(skor.begin(), skor.end());

                for( int z = 0; z < trenutne_moguce.size(); z++ ){
                    if(skor[z] == maxskor){
                        cout << trenutne_moguce[z] << endl;
                    }
                    
                }

            }
            brojac +=1;
      }

    
    //* pokusaj = sledeca odabrana varijacija
    }
}
}
int main(){
    const int znak = 6, polja = 4;
    int varijacije_niz[2000];
    vector<int> varijacije_v;
    ifstream fajl;
    int brojac = 0; // broji pokusaje
    upis_u_niz(fajl,varijacije_niz);
    niz_u_vector(varijacije_niz, varijacije_v);
    tok_igre(varijacije_v, brojac);
    cout << "JUPIIIIIII :3\n uspeo sam iz " <<  brojac  << " pokusaja!"<< endl;

    //ovo dole su samo provere da se vidi upisano li je sve kako treba
    //cout << size(varijacije_niz) << endl;
   /* for(int i = 0; i < varijacije_v.size(); i++){
        cout << i << ' ' <<varijacije_v[i] << endl;
    }*/
    return 0;
}
