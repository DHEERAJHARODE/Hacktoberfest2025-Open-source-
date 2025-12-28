#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

class BitVector{
    unsigned char * bytes;
    int nbits;//how many bit present logically
public:
    BitVector(int nb=256){
        nbits=nb;
        int n=ceil(nbits/8.0);
        bytes=new unsigned char[n];
        for(int i=0;i<n;i++)
            bytes[i]=0;//clear everything at start
    }

    void set(int bno){
        int byten=bno/8;
        bno=bno%8;
        unsigned char mask=0x80;//10000000
        mask=mask>>bno;
        bytes[byten]=bytes[byten]|mask;
    }

     void clear(int bno){
        int byten=bno/8;
        bno=bno%8;
        unsigned char mask=0x80;
        mask=~(mask>>bno);//000001000 = 111110111
        bytes[byten]=bytes[byten]&mask;
    }

    bool get(int bno){
        int byten=bno/8;
        bno=bno%8;
        unsigned char mask=0x80;
        mask=mask>>bno;
        int x= bytes[byten]&mask;
        return (x!=0);
    }

};


int main()
{
    BitVector b(20);//aple
    b.set(16);
    b.clear(16);
    cout<<b.get(16)<<endl;

    return 0;
}
