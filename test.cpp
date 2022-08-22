#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char *s = "0123456789012345678901234567890";
    char *p;
    p = strchr(s, '4');  
    cout<<s[strlen(s)-1];
    //printf("%s\n%ld\n%d\n%c\n%d\n",p,p,*p,*p,(p-s));
    //printf("%s\n%c\n%c\n%c\n", s,*s,*(s+1),*(s+1+4));  // 输出：134513940
    return 0;
}