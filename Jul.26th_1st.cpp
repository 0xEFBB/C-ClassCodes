#include <iostream>
using namespace::std;
char num[245];
int del,len,*p;
void move_first(int position){
    for (int i=len-position; i>=0; i--) {
        num[position]=num[position+1];
        position++;
    }
}
void way_first(){
    for (int i=0; i<del; i++) {
        int j=0;
        if (num[j]>num[j+1]&&num[j+1]!=-1) {
            move_first(j);
        }
        else {
            j++;
            for (; num[j]<=num[j+1]; j++) {
                ;
            }
            move_first(j);
        }
    }
    cout<<num<<endl;
}
struct tool{
    int index,value;
};
bool cmp(tool x,tool y){
    return x.value<y.value;
}
void move_second(tool tl[],int position){
    for (int i=len-position; i>=0; i--) {
        tl[position]=tl[position+1];
        position++;
    }
}
void way_second(){
    int ans[len-del];
    tool tl[len+1];
    for (int i=0; i<len; i++) {
        tl[i].value=num[i]-'0';
        tl[i].index=i;
    }
    for (int i=0; i<len; i++) {
        cout<<tl[i].value<<' ';
    }
    cout<<endl;
    sort(tl, tl+len, cmp);
    for (int i=0; i<len; i++) {
        cout<<tl[i].value<<' ';
    }
    cout<<endl;
    for (int j=0; j<del; j++) {
        for (int i=0; i<len; i++) {
            if (tl[i].index<=len-del) {
                ans[j]=tl[i].value;
                move_second(tl, i);
                break;
            }
        }
    }
    for (int i=0; i<len; i++) {
        cout<<ans[i]<<' ';
    }
}
int main(int argc, const char * argv[]) {
    cin>>num>>del;
    len=int(strlen(num));
    way_first();
    //cout<<num<<endl;
    //way_second();
    return 0;
}
