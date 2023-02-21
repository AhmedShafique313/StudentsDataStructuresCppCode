// Author: Ahmed Shafique.
// Course: Data Structure's & algorithms using (C++).
// Time, Length, Student and subjects.
#include<iostream>
#include<string>
using namespace std;
// I want to collect the data of students, the data should be like names, descipline, rollno, subjects & CGPA's.
struct stu_data{
	string name;
	string discipline;
	int roll;
	int dsa, dm, itc;
	double cgpa;
};
// length of my program
int length=0;
// initialization function
void define(int n, struct stu_data **ptr){
	cout<<"----- ----- ----- -----"<<endl;
	for(int i=0;i<n;i++){
		cout<<"["<<i+1<<"]: "<<"Enter the name of student: ";cin>>ptr[i]->name;cout<<endl;
		cout<<"Enter the discipline of student: ";cin>>ptr[i]->discipline;cout<<endl;
		cout<<"Enter the roll no of student: ";cin>>ptr[i]->roll;cout<<endl;
		cout<<"Enter the DSA marks: ";cin>>ptr[i]->dsa;cout<<endl;
		cout<<"Enter the DM marks: ";cin>>ptr[i]->dm;cout<<endl;
		cout<<"Enter the ITC marks: ";cin>>ptr[i]->itc;cout<<endl;
		cout<<"Enter the CGPA of Student: ";cin>>ptr[i]->cgpa;cout<<endl;	
	}
	length=length+1;
	return;
}
//average of itc, dm and dsa subjects
void aver(int n, struct stu_data **ptr){
	cout<<"--- --- --- --- ---"<<endl;
	int aver_itc, aver_dm,aver_dsa;
	for(int i=0;i<n;i++){
		aver_itc=aver_itc/n;
		aver_dm=aver_dm/n;
		aver_dsa=aver_dsa/n;
	}
	cout<<"The average of ITC marks: "<<aver_itc<<endl;
	cout<<"The average of DM marks: "<<aver_dm<<endl;
	cout<<"The average of DSA marks: "<<aver_dsa<<endl;
	length=length+1;
	return;
}
// sorting them in alphabetically 
void sort(int n, struct stu_data **ptr){
    cout<<"---------- Alphabetized order ----------"<<endl;
	sort(ptr, ptr+n, [](stu_data *a, stu_data *b){
		return a->name<b->name;
	});
}

/*void sort(int n, struct employe **data_arr){
	cout<<"---------- Alphabetized order ----------"<<endl;// data_arr 0 location and next location and points to employe structure with a and b.
	sort(data_arr, data_arr +n, [](employe *a, employe *b){// sorting in accordance to their designations.
		return a->desig<b->desig;
	});
	return;
}*/
// cgpa sorting
void comp(int n, struct stu_data **ptr){
    int temp=0;
	for(int i=0;i<n;i++){
		if(ptr[0]->cgpa<ptr[i]->cgpa){
			temp=ptr[i]->cgpa;
			ptr[i]->cgpa=ptr[0]->cgpa;
			ptr[0]->cgpa=temp;
		}
		cout<<endl;
	}
	cout<<"----- ------ Sorted according to their CGPA ----- ----- "<<endl;
	for(int i=0;i<n;i++){
		cout<<"["<<i+1<<"]: "<<"Name: "<<ptr[i]->name<<" CGPA: "<<ptr[i]->cgpa<<" Roll No: "<<ptr[i]->roll<<" ITC marks: "<<ptr[i]->itc<<" DM marks: "<<ptr[i]->dm<<" DSA marks: "<<ptr[i]->dsa<<endl;
	}
	length=length+1;
	cout<<endl;
	return;
}
// time function
void time(){
	cout<<endl<<"----- -----"<<endl;
	cout<<"Time starts when you press the Enter key."<<endl;
	while(1){
		if(getchar())
			break;
	}
	length=length+1;
	cout<<"Time stops"<<endl;
}
// printing 
void printm(int n, struct stu_data **ptr){
	cout<<"----- -----"<<endl<<"----- ------ ----- ----- "<<endl;
	for(int i=0;i<n;i++){
		cout<<"["<<i+1<<"]: "<<"Name: "<<ptr[i]->name<<" CGPA: "<<ptr[i]->cgpa<<" Roll No: "<<ptr[i]->roll<<" ITC marks: "<<ptr[i]->itc<<" DM marks: "<<ptr[i]->dm<<" DSA marks: "<<ptr[i]->dsa<<endl;
	}
	cout<<endl;
	return;
}
int main (){
	int n;
	cout<<"Enter the number of series: ";cin>>n;cout<<endl;
	stu_data arr[n];
	stu_data *ptr_arr[n];
	for(int i=0;i<n;i++){
		ptr_arr[i]=new stu_data;
	}
	
	// second
	define(n,ptr_arr);
	aver(n,ptr_arr);
	comp(n,ptr_arr);
	sort(n,ptr_arr);
	printm(n,ptr_arr);
	cout<<endl<<"--- Length of Function --- is --- "<<length<<endl;
	clock_t t1,t2;
	t1=clock();
	time();
	t2=clock()-t1;
	double time_taken= ((double)t2)/CLOCKS_PER_SEC;
	cout<<"The time taken by the program to execute it completely is "<<time_taken<<endl;
	cout<<endl;
	return 0;
}
