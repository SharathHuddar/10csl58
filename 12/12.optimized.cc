#include<iostream>
using namespace std;
class proc;
class Resource
{
	int nr;
	int Res[10];
	public:
		Resource() {}
		void set(int n,int ty)
		{
			nr=n;
			switch(ty)
			{
				case 0: cout <<"\nEnter the Allocated Resourse\n";
					break;
				case 1: cout <<"\nEnter the Maximum Resourse\n";
					break;
				case 2:cout <<"\nEnter the Available Resourse\n";
					break;
			}
			for(int i=0;i<n;i++)
			{
				cout << "Enter the Value\t";
				cin>> Res[i];
			}
		}
		int operator<=(Resource &x)
	 	{
			int ret=0;
			for(int i=0;i<nr;i++)
				if(Res[i]<=x.Res[i])
					ret=1;
			return ret;
		}
		Resource &operator+=(Resource &x)
	 	{
			for(int i=0;i<nr;i++)
				Res[i]+=x.Res[i];
			return *this;
		}
		Resource operator-(Resource &x) 
		{
			Resource y;
			y.nr=x.nr;
			for(int i=0;i<nr;i++)
				y.Res[i]=Res[i]-x.Res[i];
			return y;
		}
};

class proc 
{
	Resource R[4];
	int finish;
	public:
		proc()	{}
		void set(int rs)
		{
			//0->Allocated 1->Maximum 2->Need
			R[0].set(rs,0);
			R[1].set(rs,1);
			R[2]=R[1]-R[0];
			finish=0;
		}
		friend void banker(proc *p,Resource avail,int n);
};

void banker(proc *p,Resource avail,int n)
{
	int flg=1,cnt=0,cnt1=0;
	while(flg)
	{
		cnt=0;
		for (int i=0;i<n;i++)
		{
			if((p[i].R[2]<=avail) && (p[i].finish==0))  
			{
				p[i].finish=1;
				cnt++;
			  	cnt1++;
				avail+=p[i].R[0];
				cout<<"P["<<i<<"] ";
			}
		}
		if (cnt==0)
			flg=0;
	}
	if (cnt1==n)
		cout<<"\n\nSafe Sequence\n";
	else
		cout<<"Not a safe Sequence\n";
}

int main()
{
	proc P[10];
	int n;
	cout <<"Enter the Number of Process \t";
	cin >>n;
	int rs;
	cout << "Enter the Number of Resources\t";
	cin >> rs;
	for(int i=0;i<n;i++)
		P[i].set(rs);
	Resource av;
	av.set(rs,2);
	cout<<"\n";
	banker(P,av,n);
}
