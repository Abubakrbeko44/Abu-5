/*Abubakr AbdAlgadir Belle Eissa
*Class:second
*Department:computer engineering
*/
#include <iostream>
using namespace std;
//using std::strack for 
//strack implementation//
//i used interconnected lists to create the stack//
struct Node {
	int data;
	struct Node *next;
};
struct Node* top = NULL;
//Auxiliary function for inserting items into the stack//
void push(int val) {
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->data = val;
	newnode->next = top;
	top = newnode;
// Defining grouped variables under one name, allowing different variables
// to be accessed via the declared name
}
struct node {
	int info;
	struct node *next;
	}*start;
	class list {
// Create object constructor defined by the programmer to be used in the program
		public:
			node* create_node(int);
			void insert_begin();
			void insert_pos();
			void insert_last(); 
			void delete_pos();
			void search();
			void displayo();
			list() {
				start = NULL;
	//A class member that is available from any function
			}
	};
node *list::create_node(int value)
// This is a reference to a pointer to a node object
		{
		struct node *temp;
		temp = new(struct node);
		if (temp == NULL){
			cout<<"\nError"<<endl;
			exit(1);
		}
		else {
			temp->info = value;
			temp->next = NULL;     
			return temp;
		}
		}
//add elements to list
void list::insert_begin()
		{
			int value;
			cout<<"\nEnter the value to be add: ";
			cin>>value;
			struct node *temp, *p;
			temp = create_node(value);
			if (start == NULL) {
				start = temp;
				start->next = NULL;
			}
			else
			{
				p = start;
				start = temp;
				start->next = p;
			}
			cout<<"\nElement Inserted at beginning"<<endl;
		}
		//add elements in last of list
void list::insert_last()
		{
			int value;
			cout<<"\nEnter the value to be inserted: ";
			cin>>value;
			struct node *temp, *s;
			temp = create_node(value);
			s = start;
			while (s->next != NULL)
			{
				s = s->next;
			}
			temp->next = NULL;
			s->next = temp;
			cout << "\nElement Inserted at end" << endl;  
		}
		//add elements in specified postition
void list::insert_pos()
		{
			int value, pos, counter = 0; 
			cout << "\nEnter the value to be inserted: ";
			cin >> value;
			struct node *temp, *s, *ptr;
			temp = create_node(value);
			cout << "\nEnter the postion: ";
			cin >> pos;
			int i;
			s = start;
			while (s != NULL)
			{
				s = s->next;
				counter++;
			}
	//Using while to check to add item next to the said position
			if (pos == 1) {
				if (start == NULL) {
					start = temp;
					start->next = NULL;
				}
				else {
					ptr = start;
					start = temp;
					start->next = ptr;
				}
			}
			else if (pos > 1  && pos <= counter) {
				s = start;
				for (i = 1; i < pos; i++) {
					ptr = s;
					s = s->next;
				}
				ptr->next = temp;
				temp->next = s;
			}
			else {
				cout<<"\nPositon not found"<<endl;
			}
		}
	//delete elements with this function
void list::delete_pos() {
			int pos, i, counter = 0;
			if (start == NULL) {
				cout<<"\nList is empty"<<endl;
				return;
			}
			cout<<"\nEnter the position: ";
			cin>>pos;
			struct node *s, *ptr;
			s = start;
			if (pos == 1) {
				start = s->next;
			}
			else {
				while (s != NULL) {
					s = s->next;
					counter++;  
				}
				if (pos > 0 && pos <= counter) {
					s = start;
					for (i = 1;i < pos;i++) {
						ptr = s;
						s = s->next;
					}
					ptr->next = s->next;
				}
				else {
					cout<<"\nPosition not found"<<endl;
				}
				free(s);
				cout<<"\nElement deleted"<<endl;
			}
		}
	//this function is to search for item in the list and it shows list
//empty when nothing is in list and other conditions
void list::search() {
	int value, pos = 0;
	bool flag = false;
	if (start == NULL) {
		cout<<"\nList is empty"<<endl;
		return;
	}
	cout<<"\nEnter the value: ";
	cin>>value;
	struct node *s;
	s = start;
	while (s != NULL) {
		pos++;
		if (s->info == value) {
			flag = true;
			cout<<"\nElement"<<value<<"is found at position "<<pos<<endl;
		}
		s = s->next;
	}
	if (!flag)
	cout<<"\nElement"<<value<<"not found"<<endl;
}
// This is to display elements in the list
void list::displayo() {
	struct node *temp;
	if (start == NULL) {
		cout<<"\nThe list is empty"<<endl;
		return;
	}
	temp = start;
		cout << "\nElements: " << endl;
		while (temp != NULL) {
			cout << temp->info << "  >>>  ";
			temp = temp->next;
		}
	cout<<"nothing"<<endl;
}
//This for stack to remove from the list
void pop() {
	if (top == NULL){
		cout << "\nStack underflow" << endl;
	}
	else {
		cout << "\nThe popped element: " << top->data << endl;
		top = top->next;
	}
}
//this to display stack elements and it has condition as we see
void display() {
	struct Node* ptr;
	if(top == NULL)
	cout << "\nStack is empty";
	else {
		ptr = top;
		cout << "Stack elements: ";
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	cout << endl;
}
//this function creates a frame of specified capacity 
//And configure the frame to be sized 0//
int queue[50], n = 50, front = - 1, rear = - 1;
void Insert() {
	int val;
	if (rear == n - 1)
	cout << "\nQueu overflow" << endl;
	else {
		if (front == - 1)
		front = 0;
		cout << "\nInsert the element: ";
		cin >> val;
		rear++;
		queue[rear] = val;
	}
}
//delete the function//
//A key from the given frame //
void Delete() {
	if (front == - 1 || front > rear) {
		cout << "\nQueue underflow" << endl;
		return ;
	} else {
		cout << "\nElement deleted from queue is: " << queue[front] << endl;
		front++;;
	}
}
//this to show queue elements with condition in case is empty
void Display() {
	if (front == - 1)
	cout << "\nQueue is empty" << endl;
	else {
	cout << "\nQueue elements are: ";
	for (int i = front; i <= rear; i++)
	cout << queue[i]<<" ";
		cout << endl;
}
}
int A;
//test of previous functions//
int main(){
//This is our main program start and at end we return 0 to success
//it also has choice to select queue or stack or linked list
	cout<<"use 1 and 2 and 3"<<endl;
	cout << "\n\nWhat do you want: ";
	cin>>A;
	if (A == 1){
		int ch;
		cout << "1) add to Queue" << endl;
		cout << "2) delete from Queue" << endl;
		cout << "3) Display all the elements of Queue" << endl;
		cout << "4) Exit" << endl;
		do {
// DO-WHILE is a loop used here to iterate the actual program
// for several times
			cout << "\nEnter your choice : ";
			cin >> ch;
			switch (ch) {
//Switch allows a variable to be tested for equality
				case 1: Insert();
					break;
				case 2: Delete();
					break;
				case 3: Display();
					break;
				case 4:
					exit(1);
				default:
					cout<<"\nInvalid choice"<<endl;
					break;
			}
	} while(ch!=4);
//While loop statement repeatedly executes code when statement is true
//And breaks when is not true
	}
	else if (A == 2){
		int ch, val;
		cout << "(1) Push in Stack" << endl;
		cout << "(2) Pop from Stack" << endl;
		cout << "(3) Display Stack" << endl;
		cout << "(4) Exit" << endl;
		do {
			cout << "\n\nEnter your choice: ";
			cin >> ch;
			switch(ch) {
				case 1: {
					cout << "\nEnter a value to be pushed: ";
					cin >> val;
					push(val);
					break;
				}
				case 2: {
					pop();
					break;
				}
				case 3: {
	// We us case to compare the inserted value with the switch
					display();
					break;
				}
				case 4: {
					exit(1);
				}
				default: {
					cout << "\nInvalid Choice" << endl;
					break;
				}
			}
		} while(ch!=4);
	}
	//Else if used to make another statement if original if failures
	else if (A == 3) {
		int choice;
		list sl;
			start = NULL;
			while (1)
			{
				cout<<"1- add at beginning"<<endl;
				cout<<"2- add at last"<<endl;
				cout<<"3- add at position"<<endl;
				cout<<"4- Delete"<<endl;
				cout<<"5- Search"<<endl;
				cout<<"6- Display"<<endl;
				cout<<"7- Exit"<<endl;
				cout<<"\nEnter your choice: ";
				cin >> choice;
				switch(choice){
				case 1:
					sl.insert_begin();
					cout<<endl;
					break;
				case 2:
					sl.insert_last();
					cout<<endl;
					break;
				case 3:
					sl.insert_pos();
					cout<<endl;
					break;
				case 4:
					sl.delete_pos();
					break;
				case 5:
					sl.search();
					cout<<endl;
					break;
				case 6:
					sl.displayo();
					cout<<endl;
					break;
				case 7:
					exit(1);
				default:
					cout<<"\nWrong"<<endl;
					break;
				}
			}
	}
	else if (A == 4) {
	//Exit program when entering 4
		return 0;
	}
	else {
	//Exits the program when enter wrong key
		cout << "\nWrong\n" << endl;
		exit(1);
	}
	return 0;
	//End of main program
}
