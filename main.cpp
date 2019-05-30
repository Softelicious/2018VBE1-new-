//Kūrė Dominykas Rakūnas
#include <bits/stdc++.h>

using namespace std;

int countFlags(int R, int G, int Z);

int main()
{
    ifstream in("U1.txt");
    ofstream out("U1rez.txt");
    int rows;
    int Z = 0;
    int R = 0;
    int G = 0;
    int flags;
    string color;
    int ammount;
    in>>rows;
    for(int i=0; i<rows; i++){ //prasuka cikla ir visas kruveles suprastina iki 3 unikaliu
        in>>color;
        in>>ammount;
        if(color == "R"){
            R+=ammount;
        }else if(color == "G"){
            G+=ammount;
        }else{
            Z+=ammount;
        }
    }
    flags = countFlags(R, G, Z); //grazina veliaveliu skaiciu
    out << flags<<endl;
    out<<"G = "<<G-flags*2<<endl; //likuti gauna is spalvos kruveles atemus kiek prireike veliavelei juosteliu
    out<<"Z = "<<Z-flags*2<<endl;
    out<<"R = "<<R-flags*2<<endl;
    in.close(); //taisyklingai naudojantis fstream reikia uzdaryti
    out.close();
    return 0;
}

int countFlags(int R, int G, int Z){
    if(R<=G && R<=Z){ //randa maziausia kruvele
            return R/2; //tada ja padalina is 2, nes 2 kartono puses
        }else if(G<=R && G<=Z){
            return G/2;
        }else{
            return Z/2;
        }
}
