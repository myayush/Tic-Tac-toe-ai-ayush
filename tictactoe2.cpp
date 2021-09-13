#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N =1e5+7;
char game_board[4][4];
int cx,cy;

char comp,hum;

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
     // cout<<"h1";
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

void playgame_comp(int p)
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

int main()
 {
   int i, j, k, l, p,q,r, sum, t, z,f, n,g,m,d,ans;
    memset(game_board,' ',sizeof(game_board));
    cout<<"PRESS 1 TO PLAY AS X ,PRESS 2 TO PLAY AS O"<<endl;
    cin>>p;
    p=p%2;
    playgame_comp(p);

  return 0;
 }