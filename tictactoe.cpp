#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N =1e5+7;
char game_board[4][4];



void show_game_board()
{
    cout<<"............."<<endl;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
          cout<<"| "<<game_board[i][j]<<" ";
        }
        cout<<"|"<<endl;
         if(i==1||i==2)
        {
           cout<<"............."<<endl;  
        }
    }
    cout<<"............."<<endl;
}

void rules()
{
  cout<<endl;
  cout<<"THE RULES OF THE GAME ARE AS FOLLWS"<<endl;
  cout<<"X STARTS FIRSTS"<<endl;
  cout<<"X AND O TAKE ALTERNATE TURNS"<<endl;
  cout<<"A PLAYER WINS WHEN EITHER A ROW ,COLUMN OR DIAGONAL HAS HIS MARKS"<<endl;
  cout<<"GAME IS TIED WHEN THERE IS NO WINNER IN 9 MOVES"<<endl;
 
 char c='1';
  for(int i=1;i<=3;i++)
  {
    for(int j=1;j<=3;j++)
    {
      game_board[i][j]=c;
      c++;
    }
  }
  
  cout<<"THE CELLS ARE MARKED AS FOLLOWS"<<endl;
    cout<<"............."<<endl;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
          cout<<"| "<<game_board[i][j]<<" ";
        }
        cout<<"|"<<endl;
         if(i==1||i==2)
        {
           cout<<"............."<<endl;  
        }
    }
    cout<<"............."<<endl;
}

int check_row()
{
  for(int i=1;i<=3;i++)
  {
    if(game_board[i][1]!=' '&&game_board[i][1]==game_board[i][2]&&game_board[i][2]==game_board[i][3])
    {
      return 1;
    }
  }
  return 0;
}

int check_column()
{
  for(int j=1;j<=3;j++)
  {
    if(game_board[1][j]!=' '&&game_board[1][j]==game_board[2][j]&&game_board[2][j]==game_board[3][j])
    {
      return 1;
    }
  }
  return 0;
}

int check_diagonal()
{
  if(game_board[1][1]!=' '&&game_board[1][1]==game_board[2][2]&&game_board[2][2]==game_board[3][3])
    {
      return 1;
    }

    if(game_board[1][3]!=' '&&game_board[2][2]==game_board[2][2]&&game_board[2][2]==game_board[3][1])
    {
      return 1;
    }

    return 0;
}

void playgame_2()
{
  int l=1,x,y,c;
  while(l<=9)
  {
   if(l%2)
   {
    cout<<"IT IS PLAYER X TURN ,CHOOSE A CELL"<<endl;
   }
   else
   {
    cout<<"IT IS PLAYER O TURN , CHOOSE A CELL"<<endl;
   }
  show_game_board();
  cin>>c;
  x=(c-1)/3+1;
  y=(c-1)%3+1;

   if(c>9||c<1){cout<<"THE CELL NO is INVALID ,ENTER CORRECT CELL"<<endl;continue;}
  if(game_board[x][y]!=' '){cout<<"INVALID MOVE!!! IT IS ALREADY OCCUPIED"<<endl;continue;}
  if(l%2)
  { game_board[x][y]='X';}

  else
  {
     game_board[x][y]='O';
  }

   if(check_column()||check_row()||check_diagonal()){break;}
   l++;
 }

 if(l==10){cout<<"GAME TIED"<<endl;}
 else if(l%2){cout<<"PLAYER X WINS THE GAME "<<endl;}
 else
 {
   cout<<"PLAYER O WINS THE GAME "<<endl;
 }
}

int main()
 {
   int i, j, k, l, p,q,r, sum, t, z,f, n,x1,y1,g,m,d,x,y,ans;
   
   while(1)
  {
       cout<<"TO PLAY TIC-TAC-TOE PLEASE ENTER 1"<<endl;
       cout<<"ENTER 2 TO EXIT THE GAME"<<endl;
       cin>>x;
       if(x==2){break;}
       cout<<"TO PLAY 2 vs 2 ENTER 1"<<endl;
       cin>>x;
       if(x!=1)
       {
          break;
       }
       cout<<"TO SHOW THE RULES OF GAME ENTER 1"<<endl;
       cin>>x;
       if(x==1)
      { rules();}
      memset(game_board,' ',sizeof(game_board));
      
       playgame_2();
   }
    
  return 0;
 }