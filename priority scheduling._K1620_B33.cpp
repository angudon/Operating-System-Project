#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class Cpu
{
	int n,Bu[20];
	float Total_wt,Average_wt,A[10],Wt[10],w;
public:
	void Getdata();
	void Priority();
};
void Cpu::Getdata()
{
	int i;
	cout<<"Enter no of processes to run:"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{
	cout<<"Enter burstTime for each process "<<i<<"=	"<<endl;
		cin>>Bu[i];
	}
}

void Cpu::Priority()
{
	int i,B[10],P[10],j;
	w=0.0;
	int maximum;
	Total_wt=0.0;
	maximum=1;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"Burst time for each process p"<<i<<"=	"<<endl;
		cout<<B[i];
		cout<<"Give the  priority for each  process P"<<i<<"=	"<<endl;
		cin>>P[i];
		if(maximum<P[i])
			maximum=P[i];
	}
	j=1;
	while(j<=maximum)
	{
		i=1;
		while(i<=n)
		{
			if(P[i]==j)
			{
				Wt[i]=w;
				w=w+B[i];
			}
			i++;
		}
		j++;
	}


	for(i=1;i<=n;i++)
		Total_wt=Total_wt+Wt[i];
	Average_wt=Total_wt/n;
	cout<<"Total Waiting Time="<<Total_wt<<""<<endl;
	cout<<"Average Wiating Time="<<Average_wt<<""<<endl;
}
int main()
{
	int choice,cho;
	Cpu cpu;
	do
	
		cout<<"	--------------MENU---------------"<<endl;
		cout<<"1.For  process & BurstTime"<<endl;
		cout<<"2.For Priority"<<endl;
		cout<<"3.EXIT"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			cpu.Getdata();
			break;
		case 2:
			cout<<"***********PRIORITY SCHEDULING************"<<endl;
			cpu.Priority();
			break;
		case 3:
			cout<<"";
			break;
		}
	}while(choice<=3);
}

