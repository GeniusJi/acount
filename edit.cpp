#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
const int N=10000,M=10;
struct acount{string name; int num=0;} m[N];
int n;

void dir(){
    if(n==0) {cout<<"no acounts left\n"; return;}
    for(int i=0; i<n; i++)
		if(m[i].name[0]!='X') cout<<i<<':'<<m[i].name<<endl;
}

void save(){
    ofstream mem("memory.txt");
    mem<<n<<endl;
    for(int i=0; i<n; i++)
        mem<<m[i].name<<' '<<m[i].num<<endl;
}

void change(){
    string s;
    int id=0,f;
    cin>>s;
    if(s[0]=='-') return;
    else if('0'<=s[0] && s[0]<='9'){
        for(int i=0; ('0'<=s[i] && s[i]<='9') && s[i]; i++)
            id=id*10+(s[i]-'0');
        if(0>id || id>=n) return;
        cout<<"Delet "<<m[id].name<<"?(1/0)";
        f=_getch(); if(f!='1') return;
        for(int i=id+1; i<n; i++)m[i-1]=m[i];
        n--;
    }else{
        for(int i=0; i<n; i++)
            if(m[i].name.compare(s)==0) return;
        m[n++].name=s;
    }
}

int main(){
    ifstream mem("memory.txt");
    int op;
    mem>>n;
    for(int i=0; i<n; i++) mem>>m[i].name>>m[i].num;
    mem.close();
    cout<<"new acount name/delet acount id\n";
    while(1){
        dir();
        change();
        save();
        cout<<endl;
    }
    return 0;
}
