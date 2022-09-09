#include<iostream>
#include<iostream>
void printtable();
int check_if_occupied(int);
void assign(int,char);
int winner(char);
char a[3][3];
using namespace std;
int main()
{
	int pos1,pos2, win;
	int i,j;
	int counter=0;
	char p1[30],p2[30];
	cout<<"enter name of player one(your symbol is cross)"<<"\n";
	cin>>p1;
	cout<<"enter name of player two(your symbol is circle)"<<"\n";
	cin>>p2;
	for(i=0;i<3;i++)
	{
		for( j=0;j<3;j++)
		{
			a[i][j]='.';
		}
	}
	printtable();
	while(counter<10)
	{
		cout<<p1<<", enter position of your cross"<<"\n";
		cin>>pos1;
		while (check_if_occupied(pos1)!=0)
		{
		cout<<"Sorry, re-enter position of your cross"<<"\n";
		cin>>pos1;	
		}
		assign(pos1,'X');
		
		printtable();
		win = winner('X');
		//cout << win ;
		if(win ==1)
		{
		cout<<"heyyy!! congratulations to you "<<" "<<p1;
		return 0;
		}
	
		counter++;
		
		if ( counter >= 9) 
		{ cout << "sorry , no winner";
		  return 0;
		}
		cout<<p2<<", enter position of your circle"<<"\n";
		cin>>pos2;
		
		while (check_if_occupied(pos2)!=0)
		{
		cout<<"Sorry, re-enter position of your circle "<<"\n";
		cin>>pos2;	
		}
		assign(pos2,'O');
		printtable();
		if(winner('O')==1)
		{
		cout<<"heyyy!! congratulations to you "<<" "<<p2;
		return 0;}
		counter++;
	}
	return 0;
}
void printtable()
{
	
	int i,j,k;
	for(k=0;k<4;k++)
		cout<<"-  ";
			cout<<"\n" <<"\n";
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<a[i][j]<<" | ";
			
		}
		cout<<"\n"<<"\n";
		for(k=0;k<4;k++)
		cout<<"-  ";
		cout<<"\n";
	}
	
}
int check_if_occupied(int pos)
{
    char v;
    //cout<<"in check"<<"\n";
	switch(pos)
	{
		case 1:v=a[0][0];
		       break;
		case 2:v=a[0][1];
		       break;
        case 3:v=a[0][2];
		       break;
		case 4:v=a[1][0];
		       break;
		case 5:v=a[1][1];
		       break;
	    case 6:v=a[1][2];
		       break;
		case 7:v=a[2][0];
		       break;
		case 8:v=a[2][1];
		       break;
		case 9:v=a[2][2];
		       break;       
	}
	//cout<<v;
	if(v=='.')
	return 0;
	else 
	return 1;
}
void assign(int pos,char p)
{
	//cout<<"in assign"<<"\n";
	//cout<<pos<<"\t"<<p<< "\n";
		switch(pos)
	{
		case 1:a[0][0]=p;
		       break;
		case 2:a[0][1]=p;
		       break;
        case 3:a[0][2]=p;
		       break;
		case 4:a[1][0]=p;
		       break;
		case 5:a[1][1]=p;
		       break;
	    case 6:a[1][2]=p;
		       break;
		case 7:a[2][0]=p;
		       break;
		case 8:a[2][1]=p;
		       break;
		case 9:a[2][2]=p;
		       break;       
	}
}

int winner(char sym)
{
	int flag=0;
	//cout << " in winner" << a[0][0]<< a[1][0]<< a[2][0]<< sym << "\n";
	if(a[0][0]==sym&&a[0][1]==sym&&a[0][2]==sym) flag=1;
	if(a[1][0]==sym&&a[1][1]==sym&&a[1][2]==sym) flag=1;
	if(a[2][0]==sym&&a[2][1]==sym&&a[2][2]==sym) flag=1;
	if(a[0][0]==sym&&a[1][0]==sym&&a[2][0]==sym) flag=1;
	if(a[0][1]==sym&&a[1][1]==sym&&a[2][1]==sym) flag=1;
	if(a[0][2]==sym&&a[1][2]==sym&&a[2][2]==sym) flag=1;
	if(a[0][0]==sym&&a[1][1]==sym&&a[2][2]==sym) flag=1;
	if(a[0][2]==sym&&a[1][1]==sym&&a[2][0]==sym) flag=1;
	//cout << "flag is " << flag << "\n";
	return flag;
}

