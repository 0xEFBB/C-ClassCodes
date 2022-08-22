#include "cstdio"
#include "iostream"
using namespace std;
int point[103][2],ans[103][2];
bool flag[103];
int main(){
    memset(flag,0,sizeof(flag));
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>point[i][0]>>point[i][1];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(point[j][0]>=point[j+1][0]){
                swap(point[j][0],point[j+1][0]);
                swap(point[j][1],point[j+1][1]);
            }
        }
    }
    for (int i=0; i<n; i++) {
        point[i][0]=point[i+1][0];
        point[i][1]=point[i+1][1];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            }
            if(point[i][0]>=point[j][0]){
                if(point[i][1]>=point[j][1]){
                    flag[j]=true;
                }
            }
            else{
                if(point[i][1]<point[j][1]){
                    flag[i]=1;
                    break;
                }
            }
        }
    }
    int i=0;
    for(;i<n;i++){
        if(flag[i]==0){
            printf("(%d,%d)",point[i][0],point[i][1]);
            break;
        }
    }
    i++;
    for(;i<n;i++){
        if(flag[i]==0){
            printf(",(%d,%d)",point[i][0],point[i][1]);
        }
    }
    cout<<endl;
    //system("pause");
    return 0;
}
