#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct data
{
    string name;
    int level;
};

int cmp (data a, data b)
{
    return a.level<b.level;
}

int main ()
{
    vector <data> u;
    ifstream fpi ("Problem.txt", ios::in);
    while (!fpi.eof())
    {
        data tmp;
        fpi>>tmp.name>>tmp.level;
        u.push_back(tmp);
    }
    fpi.close();
    
    vector <string> v;
    ifstream fpi2 ("LIST.txt", ios::in);
    while (!fpi2.eof())
    {
        string tmp;
        getline(fpi2, tmp);
        v.push_back(tmp);
    }
    fpi2.close();
    
    vector <data> out;
    
    for (int i=0; i<u.size(); i++)
    {
        int kt = 0;
        for (int j=0; j<v.size(); j++)
        {
            if (v[j].find(u[i].name)!=-1)
            {
                kt=1;
                break;
            }
        }
        if (kt==0)
            out.push_back(u[i]);
    }
    sort(out.begin(), out.end(), cmp);
    
    ofstream fpo ("OUT.txt", ios::out);
    for (int i=0; i<out.size(); i++)
    {
        fpo<<out[i].name<<" "<<out[i].level<<endl;
    }
    fpo.close();
    return 0;
}
