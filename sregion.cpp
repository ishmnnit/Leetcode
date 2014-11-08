#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

struct pairs
{
    int a;
    int b;
};

void display(vector<vector<char> > &board)
{
    //cout<<"Maze:::\n";
    int row=board.size();
    int col=board[0].size();

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<board[i][j]<<"  "<<"\t";
        }
        cout<<"\n";
     }

     cout<<"\n\n\n";
}


void mark(vector<vector<char> > &board,int i,int j,stack<pairs> &s)
{
   // cout<< "Marking:::"<<"i="<<i<<"j="<<j<<"\n";
    pairs p;
    p.a=i;
    p.b=j;
    s.push(p);
    board[i][j]='N';
}


void markBFS(vector<vector<char> > &board ,int i ,int j,int row,int col)
{
   
    //cout<<"i="<<i<<"j="<<j<<"\n";

    pairs p1; p1.a=i;p1.b=j;

    stack<pairs> s;
    s.push(p1);
    
    int i_index[]={-1,1,0,0};
    int j_index[]={0,0,-1,1};

    while(s.empty()==false)
    {
        pairs p2=s.top();
        s.pop();

        if(board[p2.a][p2.b]=='0')
        {
            for(int i=0;i<4;i++)
            {
                if(p2.a-i_index[i] > 0 && p2.a-i_index[i] < row-1  && p2.b-j_index[i] > 0 
                    && p2.b-j_index[i] < col-1 && board[p2.a-i_index[i]][p2.b-j_index[i]]=='0')
                {
                mark(board,p2.a-i_index[i],p2.b-j_index[i],s);
                }
            }

        }

    }

}


void solve(vector<vector<char> > &board)
{
   if( board.size() == 0 )
   {
       return ;
   }

   int row=board.size();
   int col=board[0].size();

   // Run Marking algorithm for 1st and last Row
   for(int i=0;i<col;i++)
   {
       // First Row;
       markBFS(board,0,i,row,col);
       //display(board);
       //Last row 
       markBFS(board,row-1,i,row,col);
       //display(board);

   }

   // Run Marking algorithm for 1st and Last Column
   for(int i=0;i<row;i++)
   {
       //First Column
       markBFS(board,i,0,row,col);
       //display(board);
       //Last Column
       markBFS(board,i,col-1,row,col);
       //display(board);
   }

   // If Even after Marking it left '0' Means this region is surrounded so make it 'X'
   // If any cell is 'N' then make it to '0' beacause this region is not surrounded 
   for(int i=1;i<row-1;i++)
   {
       for(int j=1;j<col-1;j++)
       {
           if(board[i][j] == 'N')
           {
               board[i][j]='0';
           }
           else if(board[i][j] == '0')
           {
               board[i][j]='X';

           }
       }
    }

}



int main()
{

  vector<vector<char> > board;

/*
  vector<char> row1; row1.push_back('X');row1.push_back('X');row1.push_back('X');row1.push_back('X');
  vector<char> row2; row2.push_back('X');row2.push_back('0');row2.push_back('0');row2.push_back('X');
  vector<char> row3; row3.push_back('X');row3.push_back('X');row3.push_back('0');row3.push_back('X');
  vector<char> row4; row4.push_back('X');row4.push_back('0');row4.push_back('X');row4.push_back('X');
  */

  vector<char> row1; row1.push_back('X');row1.push_back('X');row1.push_back('X');
  vector<char> row2; row2.push_back('X');row2.push_back('0');row2.push_back('X');
  vector<char> row3; row3.push_back('X');row3.push_back('X');row3.push_back('X');

  board.push_back(row1);
  board.push_back(row2);
  board.push_back(row3);
 // board.push_back(row4);

  solve(board);
  cout<<"\n\n Final Output :: \n";
  display(board);


}
