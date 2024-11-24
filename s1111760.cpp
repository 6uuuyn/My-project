#include<iostream>
#include<cstdlib>
#define EAST  MAZE[x][y+1]  
#define WEST  MAZE[x][y-1] 
#define SOUTH MAZE[x+1][y]	
#define NORTH MAZE[x-1][y]	
#define NORTHWEST MAZE[x-1][y-1]  
#define NORTHEAST MAZE[x-1][y+1] 
#define SOUTHWEST MAZE[x+1][y-1]
#define SOUTHEAST MAZE[x+1][y+1] 
#define ExitX 11			
#define ExitY 15			
using namespace std;
typedef struct List{
	int x,y;
	struct List* next;
}Node,*Link;
int MAZE[13][17] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  
                    1,0,1,0,0,1,1,1,0,0,0,1,1,1,1,1,1,  
                    1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1,  
                    1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,  
                    1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1,  
                    1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,0,1,  
                    1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,0,1,  
                    1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,  
                    1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1, 
					1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1,
					1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1,
					1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};

Link push(Link stack,int x,int y)
{
	Link newnode=(Link)malloc(sizeof(Node));
	if(!newnode)
	{
		cout<<"false"<<endl;
		return NULL;
	}
	newnode->x=x;
	newnode->y=y;
	newnode->next=stack;
	stack=newnode;
	return stack;
}
Link pop(Link stack,int* x,int* y)
{
	Link top;
	if(stack!=NULL)
	{
		top=stack;
		stack=stack->next;
		*x=top->x;
		*y=top->y;
		free(top);
		return stack;
	}
	else
		*x--;	// 
		return stack;
}
int checkExit(int x,int y,int ex,int ey)
{
	if(x==ex&&y==ey)
		return 1;
	return 0;
}
int main()
{
	int i,j,x,y;
	Link path=NULL;
	x=1;	
	y=1;    
	
	for(i=0;i<13;i++)
	{
		for(j=0;j<17;j++)
			cout<<" "<<MAZE[i][j];
		cout<<endl;
	}
	while(x<=ExitX&&y<=ExitY)
	{
		MAZE[x][y]=6;	
		if(NORTH==0)	
		{
			x--;
			path=push(path,x,y);
		}
		else if(SOUTH==0)
		{
			x++;
			path=push(path,x,y);
		}
		else if(WEST==0)
		{
			y--;
			path=push(path,x,y);
		}
		else if(EAST==0)
		{
			y++;
			path=push(path,x,y);
		 } 
		 else if(NORTHWEST==0)  
        {  
            x-=1;
			y-=1;  
            path = push(path,x,y);  
        } 
		else if(NORTHEAST==0)  
        {  
            x--;
			y++;  
            path = push(path,x,y);  
        }  
        else if(SOUTHWEST==0)  
        {  
            x++;
			y--;  
            path = push(path,x,y);  
        } 
        else if(SOUTHEAST==0)  
        {  
            x++;
			y++;  
            path = push(path,x,y);  
        } 
		 else if(checkExit(x,y,ExitX,ExitY)==1)	
		 	break;
		else	
		{
			MAZE[x][y]=2;
			path=pop(path,&x,&y);
		 } 
	}
	cout<<"---------------------------"<<endl;
	
	for(i=0;i<13;i++)
	{
		for(j=0;j<17;j++)
		{
			cout<<" ";
			if(MAZE[i][j]==6)
			cout<<"*";
			else
			cout<<"O";	
		}
		cout<<endl;
	}
	return 0;
}
