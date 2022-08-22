#include "iostream"
using namespace std;
#define π 3.14
class CCylinder
{
private:
    double radius,height,v;
public:
    CCylinder();
    ~CCylinder();
    void compute();
    void print();
};

CCylinder::CCylinder()
{
    cin>>radius>>height;
}

CCylinder::~CCylinder()
{
}
void CCylinder::compute(){
    v=π*radius*radius*height;
}
void CCylinder::print(){
    printf("%gcm^3\n",v);
}
int main(){
    CCylinder cld;
    cld.compute();
    cld.print();
    return 0;
}