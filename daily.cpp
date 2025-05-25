#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
const int N=10000,M=10;
struct acount{string name; double num=0;};
acount m[N];
int n;

bool cmp(acount a,acount b){return a.num>b.num;}

void save(){
    ofstream mem("memory.txt");
    mem<<n<<endl;
    for(int i=0; i<n; i++)
        mem<<m[i].name<<' '<<m[i].num<<endl;
}

void clear(){
    cout<<"Sure?(1/0)";
    char f=_getch();
    if(f!='1') return;
    for(int i=0; i<n; i++) m[i].num=0;
    cout<<"DONE\n";
}

void output(){
    sort(m,m+n,cmp);
    int len=m[0].num/100+1;
    for(int i=0; i<n; i++){
        cout<<m[i].name;
        if(m[i].name.length()>=10) cout<<"\n          ";
        else for(int j=0; j<10-m[i].name.length(); j++) cout<<' ';
        for(int j=0; j<m[i].num/len; j++) cout<<'|';
        cout<<m[i].num<<"\n";
    }
    cout<<"DONE\n";
}

void add(){
    int id;
    double c;
    if(n==0) return;
    cout<<"Which acount?(enter each id)";
    cin>>id;
    if(0>id || id>=n) return;
    cout<<"How much?";
    cin>>c;
    m[id].num+=int(c*100)/100.0;
    cout<<"DONE\n";
}

void dir(){
    if(n==0) {cout<<"no acounts left\n"; return;}
    for(int i=0; i<n; i++)
		cout<<i<<':'<<m[i].name<<endl;
}

int main(){
    ifstream mem("memory.txt");
    char op;
    mem>>n;
    for(int i=0; i<n; i++) mem>>m[i].name>>m[i].num;
    mem.close();
    cout<<"add press 1\nprint press 2\nrestart acount press 3\n";
    while(1){
    	cout<<endl;
        op=_getch();
        if(op=='1'){dir(); add();}
        else if(op=='2') output();
        else if(op=='3') clear();
        save();
    }
    return 0;
}
