#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>
using namespace std;

struct allocated
{
 string borrow[10];
 int size;
 allocated()
 {
 	size=0;
 }
 void get_input(string x)
 {
 	borrow[size]=x;
	size++;  
 } 	
};

struct inventoryitem
{
	string name;
	int id;
	string category;
	int count;
	allocated obj;
	
	void get_input()
	{
		cout<<"enter the name of item     ";
		cin>>name;
		ifstream file;
		file.open("count.txt");
		file>>id;
		file.close();
		cout<<"enter item category   ";
		cin>>category;
		cout<<"enter count ";
		cin>>count;
		ofstream afile;
		afile.open("count.txt");
		afile<<id+1;
		afile.close();
	}
};

void add_item()
{
		inventoryitem obj2;
		obj2.get_input();
		fstream file("inventory.txt",ios :: in|ios :: out| ios :: app);
		file <<obj2.id << "\t" << obj2.name<<"\t"<<"\t"<<obj2.category<<"\t"<<obj2.count<<endl;
		file.close();
}

void view_inventory()
{
	int total;
	ifstream file;
	file.open("count.txt");	
	file>>total;
	file.close();
	int id;
	string name;
	string category;
	ifstream afile;
	afile.open("inventory.txt");
	int count;
	for(int a=0;a<total;a++)
	{
		afile>> id >> name >>category >>count;
		cout<<"ID= "<<id<<"	NAME= "<<name<<" category= "<<category<<" count= "<<count<<endl;
	}
	afile.close();
}
void searching()
{
		int total;
		ifstream file;
		file.open("count.txt");	
		file>>total;
		file.close();
		ifstream afile;
		afile.open("inventory.txt");
		string search;
		cout<<"type name from the list that you want to search"<<endl;
		cin>>search;
		string name;
		int id;
		string category;
		int count;
		bool found=false;
		for(int a=0;a<total;a++)
		{
			afile>> id >> name >>category >>count;
			if(name==search)
			{found=true;}
		}
		if(found)
		{
			cout<<"IT IS PRESENT"<<endl;
		}
		else
		{
			cout<<"IT IS NOT PRESENT"<<endl;
		}
	
		
}
void delete_item()
{
		int total;
		ifstream file;
		file.open("count.txt");
		file>>total;
		file.close();
		inventoryitem *arr=new inventoryitem[total];
		ifstream afile;
		afile.open("inventory.txt");
		string iname;
		int iid;
		string icategory;
		int icount;
		for(int a=0;a<total;a++)
		{
			afile>> iid >> iname >>icategory >>icount;
			arr[a].name=iname;
			arr[a].id=iid;
			arr[a].category=icategory;
			arr[a].count=icount;
		}
		afile.close();
		int d;
		cout<<"enter ID that you want to delete"<<endl;
		cin>>d;
		while(d>=total||d<0)
		{
			cout<<"ENTER AGAIN"<<endl;
			cin>>d;
		}
		ofstream xfile;
		xfile.open("inventory.txt");
		int r=0;
		for(int a=0;a<total;a++)
		{
			if(a!=d)
			{
				xfile<< r <<"  "<<arr[a].name<<"  "<<arr[a].category<<"  "<<arr[a].count<<endl;
				r++;
			}
		}
		xfile.close();
		total--;
		ofstream yfile;
		yfile.open("count.txt");
		yfile<<total;
		yfile.close();
}
void update_item()
{
	    int total;
		ifstream file;
		file.open("count.txt");
		file>>total;
		file.close();
		inventoryitem *arr=new inventoryitem[total];
		ifstream afile;
		afile.open("inventory.txt");
		string iname;
		int iid;
		string icategory;
		int icount;
		for(int a=0;a<total;a++)
		{
			afile>> iid >> iname >>icategory >>icount;
			arr[a].name=iname;
			arr[a].id=iid;
			arr[a].category=icategory;
			arr[a].count=icount;
		}
		afile.close();
		int d;
		cout<<"enter ID that you want to update"<<endl;
		cin>>d;
		while(d>=total||d<0)
		{
			cout<<"ENTER AGAIN"<<endl;
			cin>>d;
		}
		string nname;
		cout<<"enter name of new item"<<endl;
		cin>>nname;
		int ncount;
		cout<<"enter the count of new item"<<endl;
		cin>>ncount;
		string ncategory;
		cout<<"enter the category of new item"<<endl;
		cin>>ncategory;
		arr[d].name=nname;
		arr[d].count=ncount;
		arr[d].category=ncategory;
		ofstream xfile;
		xfile.open("inventory.txt");
		for(int a=0;a<total;a++)
		{
			xfile<<arr[a].id<<"  "<<arr[a].name<<"  "<<arr[a].category<<"  "<<arr[a].count<<endl;	
		}
		xfile.close();
}
int main()
{
int search;
do
{
	cout<<"Add inventory (Enter 1)"<<endl<<endl;
	cout<<"View inventory (Enter 2)"<<endl<<endl;
	cout<<"Edit inventory (Enter 3)"<<endl<<endl;
	cout<<"delete inventory (Enter 4)"<<endl<<endl;
	cout<<"Search inventory (Enter 5)"<<endl<<endl;
	cout<<"Assign inventory (Enter 6)"<<endl<<endl;
	cout<<"retrive inventory (Enter 7)"<<endl<<endl;
	cout<<"view list of assigned inventory (Enter 8)"<<endl<<endl;
	cout<<"---------------------Exit-----------------------(Enter 0)"<<endl<<endl;
	cin>> search;

	if(search==1){add_item();}
	if(search==2){view_inventory();}
	if(search==3){update_item();}
	if(search==4){delete_item();}
	if(search==5){searching();}
	// if(search==6){}
	// if(search==7){}
	// if(search==8){}
	if(search==0){break;}


} while (search !=0);


return 0;
}
