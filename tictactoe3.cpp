#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
char game_board[4][4];
int cx,cy;

char comp,hum;

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


int value()
{
  for(int i=1;i<=3;i++)
  {
    if(game_board[i][1]==game_board[i][2]&&game_board[i][2]==game_board[i][3])
    {
      if(game_board[i][1]==comp){return 100;}
	  else if(game_board[i][1]==hum){return -100;}
    }
  }
  
  for(int j=1;j<=3;j++)
  {
    if(game_board[1][j]==game_board[2][j]&&game_board[2][j]==game_board[3][j])
    {
      if(game_board[1][j]==comp){return 100;}
	    else if(game_board[1][j]==hum){return -100;}
    }
  }

  if(game_board[1][1]==game_board[2][2]&&game_board[2][2]==game_board[3][3])
    {
       if(game_board[1][1]==comp){return 100;}
	     else if(game_board[1][1]==hum){return -100;}
    }

    if(game_board[1][3]==game_board[2][2]&&game_board[2][2]==game_board[3][1])
    {
       if(game_board[1][3]==comp){return 100;}
	  else if(game_board[1][3]==hum){return -100;}
    }
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
      if(game_board[i][j]==' '){return -51;}
		}
	}
    return 0;
}

int best_value(int comp_turn,int depth)
{
   int v=value();
   if(v==100){return v-depth;}
   else if(v==-100){return v+depth;}
   else if(v==0){return 0;}
   int z;
   if(comp_turn==0)
   {
      z=9999;
   }
   else
   {
      z=-9999;
   }

   for(int i=1;i<=3;i++)
   {
     for(int j=1;j<=3;j++)
     {
        if(game_board[i][j]==' ')
        {
          if(comp_turn)
          {
            game_board[i][j]=comp;
            z=max(z, best_value(comp_turn^1,depth+1));
            game_board[i][j]=' ';
          }
          else
          {
             game_board[i][j]=hum;
             z=min(z, best_value(comp_turn^1,depth+1));
             game_board[i][j]=' ';
          }
        }
     }
   }
   return z;
}

void best_cell()
{
  int m_val=-999999;
  int c_val;
  for(int i=1;i<=3;i++)
  {
    for(int j=1;j<=3;j++)
    {
      if(game_board[i][j]==' ')
      {
         game_board[i][j]=comp;
         c_val=best_value(0,0);
         if(c_val>m_val)
         {
           m_val=c_val;
           cx=i;
           cy=j;
         }
         game_board[i][j]=' ';
      }
    }
  }
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

    if(game_board[1][3]!=' '&&game_board[1][3]==game_board[2][2]&&game_board[2][2]==game_board[3][1])
    {
      return 1;
    }
    return 0;
}

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

int valid_move(int c,int x,int y)
{
  if(c>9||c<1){cout<<"THE CELL NO IS INVALID ,ENTER CORRECT CELL NO"<<endl;return 0;}
  if(game_board[x][y]!=' '){cout<<"INVALID MOVE!!! IT IS ALREADY OCCUPIED"<<endl;return 0;;}
  return 1;
}

void playgame_comp_human(int p)
{
  if(p)
  {
    comp='O',hum='X';
  }
  else
  {
    comp='X',hum='O';
  }
  int l=1,x,y,c;
  while(l<=9)
  {
    show_game_board();
  if((l+p)%2==0)
  { 
    cout<<"CHOOSE A CELL"<<endl;
   cin>>c;
   x=(c-1)/3+1;
   y=(c-1)%3+1;
   if(!valid_move(c,x,y)){continue;}
   game_board[x][y]=hum;
  }
  else
  {
    best_cell();
    game_board[cx][cy]=comp;
    cout<<"COMPUTER HAS PLAYED ITS MOVE"<<endl;
  }
   if(check_column()||check_row()||check_diagonal()){break;}
   l++;
  }
 show_game_board();
 if(l==10){cout<<"GAME TIED"<<endl;}
 else if((l+p)%2==0){cout<<"PLAYER WINS THE GAME "<<endl;}
 else
 {
   cout<<"COMPUTER WINS THE GAME "<<endl;
 }
}

void playgame_human_human()
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
   if(!valid_move(c,x,y)){continue;}
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
   int i, j, p,x;
    memset(game_board,' ',sizeof(game_board));
    cout<<"TO PLAY HUMAN VS HUMAN ENTER 1 "<<endl;
    cout<<"ENTER 2 TO PLAY AGAINST COMPUTER"<<endl;
    cout<<"ENTER 3 TO SHOW THE RULES OF THE GAME"<<endl;
    cin>>x;
    if(x==1)
    {
       playgame_human_human();
    }
    else if(x==2)
    {
      cout<<"PRESS 1 TO PLAY AS X ,PRESS 2 TO PLAY AS O"<<endl;
      cin>>p;
       p=p%2;
       playgame_comp_human(p);
    }
    else
    {
       rules();
    }
  return 0;
 }