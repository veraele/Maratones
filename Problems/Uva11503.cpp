#include <bits/stdc++.h>

using namespace std;

int parent[100010];
int childs[100010];

void init(int tam)
{
    while(tam--)
    {
        parent[tam]=tam;
        childs[tam]=1;
    }
}
bool query(int p, int q)
{
    return parent[p]==parent[q];
}
int root(int p)
{
    do
    {
        p=parent[p];
    }while(p!=parent[p]);
    return p;
}
void unionDS(int p, int q)
{
    int proot=root(p);
    int qroot=root(q);
    int pchilds=childs[proot];
    int qchilds=childs[qroot];
    if(!query(p,q)){
        if(pchilds>qchilds)
        {
            parent[q]=proot;
            childs[proot]+=childs[q];
        }else
        {
            parent[p]=qroot;
            childs[qroot]+=childs[p];
        }
    }
}
struct Name {
    string name;
    int id;

    bool operator < (const Name& r) const
    {
        return this->name < r.name;
    }
};

int main()
{
    int index=0,testC,f;
    Name name1,name2;
    set<Name>::iterator it1,it2;
    cin>>testC;
    for(int i=0; i<testC; i++)
    {
        cin>>f;
        set<Name> dictionary2;
        init(100010);
        index=0;
        for(int j=0; j<f; j++)
        {
            cin>>name1.name>>name2.name;
            it1=dictionary2.find(name1);
            if(it1==dictionary2.end())
              {
                  name1.id=index;
                  index++;
                  dictionary2.insert(name1);
                  it1=dictionary2.find(name1);
              }
            it2=dictionary2.find(name2);
            if(it2==dictionary2.end())
            {
                name2.id=index;
                index++;
                dictionary2.insert(name2);
                it2=dictionary2.find(name2);
            }
            if(!query(it1->id, it2->id))
            {
                unionDS(it1->id,it2->id);
            }
            cout<<max(childs[root(it2->id)],childs[root(it1->id)])<<'\n';
        }
    }
    return 0;
}
