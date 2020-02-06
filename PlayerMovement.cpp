#include<iostream>
using namespace std;
string map[13][13];
class Player{
    public:
        int x,y,speed;
        string face;
        void Move(char input)
        {
            int inputNumber, newInput;

            if (input=='w') inputNumber=0;
            if (input=='s') inputNumber=1;
            if (input=='a') inputNumber=2;
            if (input=='d') inputNumber=3;
            
            switch(inputNumber) {                      //0 is up, 1 is down, 2 is left, 3 is right
                case 0  :
                    x-=1;
                    break; //optional
                case 1  :
                    x+=1;
                    break; //optional
                case 2  :
                    y-=1;
                    break; //optional
                case 3  :
                    y+=1;
                    break; //optional
                default :
                    cout << "Invalid option" << endl; }

            for (int i=0; i<13; i++) {
        for (int j=0; j<13;j++) {
            if ((x==i) && (y==j)) cout<<face;
                else cout<<map[i][j];  }
    cout<<endl;   
}
    cin>>newInput;
    Move(newInput);
    }
};
int main()
{
    Player player;
    player.x=1;
    player.y=1;
    player.face="a";
    for (int i=0; i<13; i++) {
        for (int j=0; j<13;j++) {
         map[i][j]="0";
     }
    cout<<endl;}

    for (int i=0; i<13; i++) 
    {
        for (int j=0; j<13;j++) 
        {
            if ((player.x==i) && (player.y==j)) 
                cout<<player.face;
            else
                    cout<<map[i][j];
                
            
        }
    cout<<endl;   
   }
   cout<<endl;
   cout<<endl;
   cout<<endl;

    player.Move('d');
}