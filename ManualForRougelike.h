#include<windows.h>
#include<iostream>
using namespace std;
 
int main(void)
{
    bool done = false;
 
    while(!done)
        if(GetAsyncKeyState(0x4D) != 0)
            done = true;
     
    cout << "@=character" << endl;
    cout << "G=Goblin" << endl;
    cout << "#=wall" << endl;
    cout << ".= a door or unused" << endl;
    cin.get();
    return 0;
}
