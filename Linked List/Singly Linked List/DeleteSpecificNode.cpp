#include <iostream>
using namespace std;

struct student{
    string studentName;
    string phoneNumber;
    float gpa; 
    student *next = NULL;
};

student *first = NULL;
student *last = NULL;

//methods
void insert_end();
void display();

void delete_specific();

//global variable
int opt;
string name;

int main(){

do{
		
		cout<<"\n\n0.Exit";
		cout<<"\n1.Insert at end";
		cout<<"\n2.Display";
		cout<<"\n3.Delete specific";
		
		cout<<"\n\n\nEnter your choice: ";
		cin>> opt;
		
		switch(opt){
			
			case 1:{
				insert_end();
				break;
			}
			
			case 2:{
				
				display();
				break;
			}
			
			case 3:{
				delete_specific();
				break;
			}
		}
		
	}
	while(opt != 0);
	
	return 0;
}

void insert_end(){
	
	student *current = new student;
	
	cout<<"Enter the student Name: ";
	cin>>current->studentName;
	
	cout<<"Enter the student gpa: ";
	cin>>current->gpa;
	
	cout<<"Enter the student phone number: ";
	cin>>current->phoneNumber;
	
	
	if(first == NULL){
		cout<<"\n\nEmpty linked list";
		first = last = current;
	}
	else{	//if linked list is non empty
	
		last->next = current; 
		last = current; 
	}
	
}

void display(){
	
	student *p = first;
	
	if(first == NULL){
		cout<<"\n\nEmpty linked list";
	}
	
	else{
		
		while(p != NULL){
			
			cout<<"\nThe student name is: " << p->studentName<<endl;
			cout<<"\nThe student gpa is: " << p->gpa<<endl;
			cout<<"\nThe student phone number is: " << p->phoneNumber;
			
			p = p->next;
		}
		
	}
	
}

void delete_specific(){
	
	
	student *p = first;
	student *p1 = NULL;
	
	cout<<"\n\nEnter the student name: ";
	cin>>name;
	
	//searching the student name
	while(p->studentName != name && p != NULL){
		cout<<"\n\nStudent "<<name<<" is Found in the linked list";
		p1 = p;
		p = p->next;
	}
	
	p1->next = p->next;
	delete p;
	
}