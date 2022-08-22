#include <iostream>
using namespace::std;
struct metal
{
    double value,mass,allvalue;
}mtl[105];
bool cmp(metal x,metal y){
    return x.value>y.value;
}
int main(){
    int num;
    cin>>num;
    double maxvalue[num];
    memset(maxvalue,0,sizeof(maxvalue));
    for (int j = 0,n,maxmass,nowmass=0; j < num; j++)
    {
        memset(mtl,0,sizeof(mtl));
        cin>>maxmass>>n;
        int fullmass=0,fullvalue=0;
        for (int i = 0; i < n; i++)
        {
            cin>>mtl[i].mass>>mtl[i].allvalue;
            mtl[i].value=mtl[i].allvalue/mtl[i].mass;
            fullmass+=mtl[i].mass;
            fullvalue+=mtl[i].allvalue;
        }
        if (maxmass>=fullmass) {
            maxvalue[j]=fullvalue;
            break;
        }
        sort(mtl,mtl+n,cmp);
        int k=0;
        while (true)
        {
            if (nowmass+mtl[k].mass<=maxmass)
            {
                maxvalue[j]+=mtl[k].allvalue;
                //cout<<maxvalue[j]<<' '<<mtl[k].allvalue<<endl;
                nowmass+=mtl[k].mass;
                k++;
            }
            else{
                break;
            }
        }
        nowmass=maxmass-nowmass;
        maxvalue[j]+=nowmass*mtl[k].value;
    }
    
    for (int i = 0; i < num; i++)
    {
        printf("%.2lf\n",maxvalue[i]);
    }
    return 0;
}
