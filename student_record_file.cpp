#include<iostream>
#include<fstream>
#include<cstdio>

using namespace std;

class student{
public:
	int roll_no;
	char name[40];
	char addrress[80];

	void set_data(){
		cout<<"Enter Roll no :- ";
		cin>>roll_no;
		cout<<endl;
		cin.ignore();		
		cout<<"Enter the name of the Student :- ";
		cin.getline(name,100);
		cout<<endl;
		cout<<"Enter you Addrress :- ";
		cin.getline(addrress,80);
		cout<<endl;
	}

	void show_data(){
		cout<<"**********Student Details**********"<<endl;
		cout<<endl<<"Name of the student is :- "<<name<<endl;
		cout<<"Roll no is :- "<<roll_no<<endl;
		cout<<"Addrress :- "<<addrress<<endl;
	}

};

void insert_data(){
	
	ofstream newfile;
	newfile.open("student_data.txt",ios::binary | ios::app);
	
	student object;
	object.set_data();

	newfile.write((char*)&object, sizeof(object));

	newfile.close();
}

void display_data(){

	ifstream input_file;
	input_file.open("student_data.txt",ios::binary);

	student object;

	while(input_file.read((char*)&object, sizeof(object))){
		object.show_data();
	}

	input_file.close();
}

bool search_rollno(int n){

	ifstream input_file;
	bool flag = false;
	input_file.open("student_data.txt",ios::binary);

	student object;

	while(input_file.read((char*)&object, sizeof(object))){

		if(object.roll_no == n){
			flag = true;
			object.show_data();
			return true;
			break;
		}
	}

		cout<<"Record of Roll No "<<n<<" not found in the database"<<endl;
		return false;

}

void delete_record(int n){

	student object;

	ifstream input_file;
	input_file.open("student_data.txt",ios::binary);

	ofstream output_file;
	output_file.open("temp.txt",ios::out | ios::binary);

	int a = search_rollno(n);
	if(a){
		while(input_file.read((char*)&object, sizeof(object))){

			if(object.roll_no != n){
				output_file.write((char*)&object, sizeof(object));
			}
		}
		input_file.close();
		output_file.close();
		remove("student_data.txt");
		rename("temp.txt" , "student_data.txt");
	}
	else{
		cout<<" Data of Roll No "<<n<<" Not present , Hence canot perform delete operation"<<endl;
	}

}
int main(){

	int choice;

	do{
		cout<<endl<<"Enter The File Operation that you want to perform"<<endl<<endl;
		cout<<"1. Add Data to file"<<endl;
		cout<<"2. Display Data of file"<<endl;
		cout<<"3. Search Data "<<endl;
		cout<<"4. Delete Data of a student"<<endl;
		cout<<"5. Exit"<<endl;

		cout<<endl<<"Enter you choice :- ";
		cin>>choice;
		cout<<endl;

		switch(choice){
			case 1:cout<<"Enter number of Records you want to Add :- ";
			int num;
			cin>>num;
			cout<<endl;
			for(int i=0;i<num;i++){
				insert_data();
			}
			break;

			case 2: cout<<endl<<" List Of Students and thier Data"<<endl;
					display_data();
					break;

			case 3:cout<<"Enter Roll No of student :- ";
			int rollno;cin>>rollno;
			cout<<endl;
			search_rollno(rollno);
			break;

			case 4:cout<<"Enter the roll no to be deleted :- ";
				   int roll;cin>>roll;
				   delete_record(roll);
				   break;

		}
	}while(choice<5);

	cout<<endl<<"Successfully Performed the Operations"<<endl;

	return 0;
}
