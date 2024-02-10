#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void divisori(unsigned n,vector<unsigned> &a){
    for(int i=2;i<n;i++){
        if(n%i==0)
            a.push_back(i);
    }
}

void numeri_primi(unsigned n,vector<unsigned> &v){
    divisori(n,v);
    int N=v.size();
    for(int i=0;i<N;i++){
         for(int j=2;j<=sqrt(v[i]);j++){
            if(v[i]%j==0){
               v[i]=0;
               break;
            }
        }
    }
    vector<unsigned> w;
    for(int i=0;i<N;i++){
        if(v[i]>0){
                w.push_back(v[i]);
        }
        v=w;
    }
}



void fattorizzazione(unsigned n,vector<unsigned> &v,vector<unsigned> &w){
    numeri_primi(n,v);

        int p,tot,i=0;
        while(p!=1){
            int r=0;
            int k=0;
            while (p!=1 && r==0 && v[i]>0 ){
                p=n/v[i];
                r=p%v[i];
                k++;
                n=p;
                tot=k;

            }
            p=n;
            if(v[i]>0)
                w.push_back(tot);
            i++;
       }
}

vector<unsigned> associatore(unsigned n,vector<unsigned> v,vector<unsigned> w,int i){
    fattorizzazione(n,v,w);
    vector<unsigned> b;
    b.push_back(v[i]);
    b.push_back(w[i]);
    return b;
}

int main(){
    vector<unsigned> v;
    vector<unsigned> w;
    unsigned n;
    cout<<"Inserisci un numero naturale ";
    cin>>n;
    fattorizzazione(n,v,w);

    cout<<"Il vettore dato dalla scomposizione in fattori primi è; "<<endl;
    cout<<"{";
    for(int i=0;i<w.size();i++){
        cout<<"(";
        for(int j=0;j<associatore(n,v,w,i).size();j++)
                    cout<<" "<<associatore(n,v,w,i)[j]<<","<<" ";
        cout<<")"<<",";
    }
    cout<<"}"<<endl;
}
