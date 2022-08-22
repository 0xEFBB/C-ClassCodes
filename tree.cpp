#include <iostream>
#include "binaryTree.h"
using namespace std;
int main(){
    /*char *command=new char[256];
    char *str1=new char[256];
    char *str2=new char[256];
    cin>>command>>str1>>str2;
    cout<<command<<' '<<str1<<' '<<str2<<endl;
    CTree ctr;
    ctr.pre_in(str1, str2, strlen(str1));
    ctr.postOrder(ctr.getRoot());
    delete [] command;
    delete [] str1;
    delete [] str2;*/
    CTree ctr;
    ctr.m_rootTree=ctr.createNodalPoint('A');
    tnp tr[10];
    for (int i = 0; i < 10; i++)
    {
        tr[i]=ctr.createNodalPoint(char(i+66));
    }
    ctr.connect(ctr.m_rootTree,tr[0],tr[1]);
    ctr.connect(tr[0],tr[2],tr[3]);
    ctr.connect(tr[2],tr[6],tr[8]);
    ctr.connect(tr[3],NULL,tr[9]);
    ctr.connect(tr[1],NULL,tr[4]);
    ctr.connect(tr[4],tr[5],tr[7]);
    ctr.preOrder(ctr.m_rootTree);
    printf("\n");
    ctr.inOrder(ctr.m_rootTree);
    printf("\n");
    ctr.postOrder(ctr.m_rootTree);
    printf("\n");
    ctr.levelOrder(ctr.m_rootTree);
    printf("\n");
    return 0;
}
