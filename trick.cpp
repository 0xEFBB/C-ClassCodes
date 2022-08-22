/*#include "iostream"
using namespace std;
#include <windows.h>
int main(){
	char ans[15],*cmd="shutdown -s -t ";
	cout<<"I've controlled your computer.\n"<<
	"Now print'I am a dog'in terminal,and I'll stop this program.\n"<<
	"Or your computer will be turned off in one minutes later,"<<
	"and this window will appear again when your computer restarts!!!"<<endl;
	system("shutdown -s -t 60");
	Sleep(1);
	for (char i = '5'; i > '0'; i--)
	{
		for (char j = '9'; j >= '0'; j--)
		{
			strcmp(cmd,&i);
			strcmp(cmd,&j);
			system(cmd);
			cout<<i<<j<<"seconds later;"<<endl;
			Sleep(1);
		}
		
	}
	gets(ans);
	if(ans=="I am a dog"){
		system("shutdown -a");
		cout<<"All right,you're clever.I'll leave your computer this time.\n";
		return 0;
	}
	cout<<"How foolish you don't listen to me!Now you'll get the punish!!!\n";
	system("shutdown -s -t 3");
	system("pause");
	return 0;
}
*/