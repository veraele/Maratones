// LightOJ-1082
#include <bits/stdc++.h>
using namespace std;
class Arbol
{
public:
   Arbol *nodoiz;
   Arbol *nodoDe;
    int dato;
};
void build2(Arbol* n,int ran1,int ran2,vector<int> &vec)
{
    //cout<<" r1 "<<ran1<<" r2 "<<ran2<<'\n';
    if(ran1==ran2)
    {
        n->dato=vec[ran1];
        return;
    }
    n->nodoDe=new Arbol();
    n->nodoiz=new Arbol();
    //cout<<" h ";
    build2(n->nodoiz,ran1,(ran2+ran1)/2,vec);
    build2(n->nodoDe,((ran2+ran1)/2)+1,ran2,vec);
    n->dato=min(n->nodoDe->dato,n->nodoiz->dato);
}

void build(vector<int> &m,Arbol* seg)
{
    build2(seg,0,m.size()-1,m);
}


void imprimir(Arbol* ar)
{
    if(ar!=NULL)
        cout<<ar->dato<<" - ";
    if(ar->nodoiz!=NULL)
        imprimir(ar->nodoiz);
    if(ar->nodoDe!=NULL)
        imprimir(ar->nodoDe);
}

int query(Arbol* ar,int r1,int r2,int rq1,int rq2)
{
    if(rq1<=r1&&rq2>=r2)
        return ar->dato;
    else if(rq1>r2||rq2<r1)
    {
        return 1000000;
    }
    else
        return min(query(ar->nodoiz,r1,(r1+r2)/2,rq1,rq2),query(ar->nodoDe,(((r1+r2)/2)+1),r2,rq1,rq2));
}

void update(int h,Arbol* ar,int r1,int r2,int posV)
{
    if(r1==r2)
        ar->dato=h;
    else
    {
        if((r2+r1)/2>=posV)
            update(h,ar->nodoiz,r1,(r2+r1)/2,posV);
        else
            update(h,ar->nodoDe,((r2+r1)/2)+1,r2,posV);
        ar->dato=min(ar->nodoDe->dato,ar->nodoiz->dato);
    }
}
int main()
{
//ios::sync_with_stdio(false);
 cin.tie(NULL);
//    srand(time(NULL));
int test,n,q,aux,l,r;
cin>>test;
for (int i=1; i<=test; i++)
{
    cout<<"Case "<<i<<":\n";
    vector<int> v;
    cin>>n>>q;
    for(int j=0; j<n; j++)
    {
        cin>>aux;
        v.push_back(aux);
    }
    Arbol *a= new Arbol();
    build(v,a);
    for(int j=0; j<q; j++)
    {
        cin>>l>>r;
        cout<<query(a,0,v.size()-1,l-1,r-1)<<'\n';
    }
}
    return 0;
}


