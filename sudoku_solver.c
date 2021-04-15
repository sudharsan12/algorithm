#include<stdio.h>
#include<stdlib.h>
int is_safe(int row,int col,int size,int value,int board[size][size])
{
	int i,j;
	for(i=0;i<size;i++)
		if(board[row][i]==value)
			return 0;
	for(i=0;i<size;i++)
		if(board[i][col]==value)
			return 0;
	int start_row=row-row%3;
	int start_col=col-col%3;

	for(i=start_row;i<start_row+3;i++)
		for(j=start_col;j<start_col+3;j++)
			if(board[i][j]==value)
				return 0;
return 1;

}

void board_set(int size,int num,int board[size][size])
{

	srand(time(0));
	int i,row,col,value;
	for(i=0;i<num;i++)
	{
		col=rand()%9;
		row=rand()%8+1;
		value=rand()%8+1;
		if(is_safe(row,col,size,value,board))
		board[row][col]=value;
	}
}
int solve_board(int row,int col,int size,int (*board)[size])
{

	if(row==size-1&&col==size -1)
		return 1;
	int i,j,k;
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			if(board[i][j]==0)
			{
				for(k=1;k<=9;k++)
				{
					if(is_safe(i,j,size,k,board))
					{
						board[i][j]=k;
						if(solve_board(i,j,size,board))
							return 1;
						board[i][j]=0;
					}
				}
					
				return 0;

			}

		}
	}
	return 1;
	
}
void print_board(int n,int (*board)[n])
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		if(i%3==0){
			for(k=0;k<6;k++)
			printf("____");
		printf("\n");
		}
		for(j=0;j<n;j++)
		{
		if(j%3==0)
			printf("| ");
			printf("%d ",board[i][j]);
		if(j==n-1)
			printf("| ");
		}
		printf("\n");
		if(i==n-1){
			for(k=0;k<6;k++)
			printf("____");
		}
	}
}
int main()
{
	int board[9][9]={0};
	int n,i,j,k;
	printf("enter the how many starting value passed to the board \n");
	scanf("%d",&n);
	board_set(9,n,board);
	print_board(9,board);
	if(solve_board(0,0,9,board))
	{
	printf("\n\n.......solved sudoku.......... \n");
	print_board(9,board);
		printf("\n");
	}
	else
		printf("\n sudoku not possible\n");

	
}
