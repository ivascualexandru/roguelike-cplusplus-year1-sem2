#include<iostream>
using namespace std;
string map[13][13];
class Player{
    public:
        int x,y,speed;
        string face;
        void Move(char input)
        {
            switch(input) {
                case "w"  :
                    y+=1;
                    break; //optional
                case "s"  :
                    cout<<"down";
                    break; //optional
                case "a"  :
                    cout<<"left";
                    break; //optional
                case "d"  :
                    cout<<"right";
                    break; //optional
                default :
                    cout << "Invalid option" << endl; }

            for (int i=0; i<13; i++) {
        for (int j=0; j<13;j++) {
            if ((x==i) && (y==j)) cout<<face;
                else cout<<map[i][j];  }
    cout<<endl;   
}
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

    player.Move("w");
}