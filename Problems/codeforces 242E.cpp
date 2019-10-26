// codeforces 242E
#include <bits/stdc++.h>
template<class T>
class Arbol
{
public:
    Arbol<T>* nodoiz;
    Arbol<T>* nodoDe;
    T dato;
};
using namespace std;
template<class T>
void build(vector<int> m,Arbol<T>* seg)
{
    build2(seg,0,m.size()-1,m);
}
template<class T>
void build2(Arbol<T>* n,int ran1,int ran2,vector<T> vec)
{
    //cout<<" r1 "<<ran1<<" r2 "<<ran2<<'\n';
    if(ran1==ran2)
    {
        n->dato=vec[ran1];
        return;
    }
    n->nodoDe=new Arbol<T>();
    n->nodoiz=new Arbol<T>();
    //cout<<" h ";
    build2(n->nodoiz,ran1,(ran2+ran1)/2,vec);
    build2(n->nodoDe,((ran2+ran1)/2)+1,ran2,vec);
    n->dato=n->nodoDe->dato*n->nodoiz->dato;
}
template<class T>
void imprimir(Arbol<T>* ar)
{
    if(ar!=NULL)
        cout<<ar->dato<<" - ";
    if(ar->nodoiz!=NULL)
        imprimir(ar->nodoiz);
    if(ar->nodoDe!=NULL)
        imprimir(ar->nodoDe);
}
template<class T>
T query(Arbol<T>* ar,int r1,int r2,int rq1,int rq2)
{
    if(rq1<=r1&&rq2>=r2)
        return ar->dato;
    else if(rq1>r2||rq2<r1)
    {
        return 1;
    }
    else
        return query(ar->nodoiz,r1,(r1+r2)/2,rq1,rq2)*query(ar->nodoDe,(((r1+r2)/2)+1),r2,rq1,rq2);
}
template<class T>
void update(T h,Arbol<T>* ar,int r1,int r2,int posV)
{
    if(r1==r2)
        ar->dato=h;
    else
    {
        if((r2+r1)/2>=posV)
            update(h,ar->nodoiz,r1,(r2+r1)/2,posV);
        else
            update(h,ar->nodoDe,((r2+r1)/2)+1,r2,posV);
        ar->dato=ar->nodoDe->dato*ar->nodoiz->dato;
    }
}
int main()
{
ios::sync_with_stdio(false); cin.tie(NULL);
//    srand(time(NULL));
    int g,h,i;
    char c;
//    for(int i=0;i<10; i++)
//    {
//        g=rand()%20+1;
//        vec.push_back(g);
//        cout<<g<<'\n';
//    }
//    build(vec,v);
//    //cout<<"arbol\n";
//    imprimir(v);
//    cin>>g>>h;
//    update(g,v,0,vec.size()-1,h);
//    imprimir(v);
//    //cout<<" query "<<query(v,0,vec.size(),g,h)<<'\n';
    while(cin>>g>>h)
    {
        Arbol<int>* v;
        v=new Arbol<int>();
        vector<int> vec;
        while(g--)
        {
            cin>>i;
            if(i<0)
                i=-1;
            if(i>0)
                i=1;
            vec.push_back(i);
        }
        build(vec,v);
        //imprimir(v);
        while(h--)
        {
            cin>>c>>g>>i;
            if(c=='C')
            {
                if(i<0)
                i=-1;
            if(i>0)
                i=1;
                update(i,v,0,vec.size()-1,g-1);
                //imprimir(v);
                //cout<<'\n';
            }
            else
            {
                //cout<<"1";
                int q=query(v,0,vec.size()-1,g-1,i-1);
                //cout<<"2";
                if(q<0)
                    cout<<"-";
                else if(q>0)
                    cout<<"+";
                else
                    cout<<"0";
            }
        }
        cout<<'\n';
    }
    return 0;
}


