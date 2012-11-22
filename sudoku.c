/*
 *Program		:Sudoku Solver By Backtracking
 *Version		:1.3
 *Author		:Balanarayanan
 *Email			:me@balanarayanan.in
 *Date			:Sunday 18 November 2012 04:48:59 PM IST 
 *Last Revised		:Thursday 22 November 2012 10:54:26 AM IST 
 *Licesne		:MIT license [http://www.opensource.org/licenses/mit-license.php]

*/

#include<stdio.h>
#include<stdlib.h>
int A[9][9];

void printsudoku()		//Function to Print Matrix
{int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("%d ",A[i][j]);
			if((j+1)%3==0)
			printf(" | ");
		}
		printf("\n");
		if((i+1)%3==0)
			printf("--------------------------\n");
	}
	printf("\n");
}
int legal(int x,int y,int key) 	//Function to check if a number is valied at a given position
{int i,j;

		

	for(i=0;i<9;i++)
	{
	 if((A[i][y]==key)||(A[x][i]==key  ))
	 return 0;
	}
	
	for(i=x-x%3;i< (x-x%3) +3;i++)
	{
		for(j=y-y%3 ; j< (y-y%3)+3 ; j++)
		{
			if(A[i][j]==key)
			return 0;
		}
	}
	return 1;
}



int solve(int i,int j)		//Recursive Backtracking Function to find the legal value at a position
{int k;
 if(i==9)
 {
	printsudoku();
	exit(0);
 }
while(A[i][j]!= -1)
{
		if(j==8 )
		{
			if(i<8)			
			{
			 	i=i+1;
		 	 	j=0;
			}
			else
			{	
				printsudoku();
				exit(0);		 
			}
		}
		else
		 	j++;	
}
		if(A[i][j]==-1)
		{for(k=1;k<=9;k++)
			{	
					if(legal(i,j,k))
					{	A[i][j]=k;
						if(j==8)
							solve(i+1,0);
						else
							solve(i,j+1);
					A[i][j]=-1;	
					}	
			}
		}

}
int main()
{	int i,j;		//Input Values into a 9x9 Array. Insert -1 for Blank Characters .
	for(i=0;i<9;i++)
	{	for(j=0;j<9;j++)
		scanf("%d",&A[i][j]);
	}
	solve(0,0);
	return 0;
}
