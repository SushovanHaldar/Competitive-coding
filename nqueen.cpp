//N-Queen problem where N is even.
#include <bits/stdc++.h>
using namespace std;
class nqueen{
  int n;
  int **board;
public:
  nqueen(int m)
  {
    int i,j;
    n = m;
    board = (int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++)
      {
	board[i] = (int *)malloc(m*sizeof(int));
      }
    for(i=0;i<m;i++)
      {
	for(j=0;j<m;j++)
	  {
	    board[i][j] = 0;
	  }
      }
  }
  void printboard()
  {
    int i,j;
    cout << endl;
    for(i=0;i<n;i++)
      {
	for(j=0;j<n;j++)
	  {
	    cout << board[i][j] << " ";
	  }
	cout << endl;
      }
  }
  int horizontal(int **chboard,int a,int b)
  {
    int j;
    for(j=0;j < b;j++)
      {
	    if(chboard[a][j] == 1)
	      return 0;
      }
    return 1;
  }
  int vertical(int **chboard,int a,int b)
  {
    int i;
    for(i=0;i < a;i++)
      {
	    if(chboard[i][b] == 1)
	      return 0;
      }
    return 1;
  }
  int diagonalleft(int **chboard,int a,int b)
  {
    int i,j;
    i = a-1;
    j = b-1;
    while(i >= 0 && j >= 0)
    {
	    if(chboard[i][j] == 1)
	        return 0;
	    i--;
	    j--;
    }
    i = a + 1;
    j = b + 1;
    while(i < n && j < n)
    {
	    if(chboard[i][j] == 1)
	        return 0;
	    i++;
	    j++;
    }
    return 1;
  }
  
  int diagonalright(int **chboard,int a,int b)
  {
    int i,j;
    i = a - 1;
    j = b + 1;
    while(i >= 0 && j < n)
    {
	    if(chboard[i][j] == 1)
	       return 0;
	    i--;
	    j++;
    }
    i = a + 1;
    j = b - 1;
    while(i < n && j >= 0)
    {
	    if(chboard[i][j] == 1)
	       return 0;
	    i++;
	    j--;
    }
    return 1;
  }
  int issafe(int **chboard,int a,int b)
  {
    if(horizontal(chboard,a,b) && vertical(chboard,a,b) && diagonalleft(chboard,a,b) && diagonalright(chboard,a,b))
      return 1;
    else
      return 0;
  }
  int search(int **chboard,int n,int row)
  {
  	int i,j;
    if(row == n)
    	return 1;
    for(j=0;j<n;j++)
    {
    	if(issafe(chboard,row,j))
    	{
    		chboard[row][j] = 1;
    	}
    	else
    		continue;
    	if(search(chboard,n,row+1) == 1)
    		return 1;
    	chboard[row][j] = 0;
    }
    return 0;
  }
  void chessboard(int n)
  {
  	int flag;
  	flag = search(board,n,0);
  	if(flag == 1)
  	{
  		cout << "\nSolution exists\n";
  		printboard();
  	}
  	else
  		cout << "\nNo solution exists\n";
  }
};
int main()
{
  int n,i;
  cout << "Enter the size of the board ";
  cin >> n;
  nqueen queen(n);
  queen.printboard();
  queen.chessboard(n);
  return 0;
}
