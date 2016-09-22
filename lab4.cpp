#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
struct Node{
	int key;
	Node *previous;
	Node *next;
};

void displaymenu();
void printList(Node *top , Node *end);
Node* addNode(int value, Node *end);


int main()
{
	Node *head = new Node;
	Node *tail = new Node;
	head->key = 2;
	head->next = tail;
	head->previous = NULL;
	tail->key = 3;
	tail->previous = head;
	tail->next = NULL;
	
	bool quit;
	int input;
	string s_input;
	while(input != 3){
		quit = false;
		displaymenu();
		getline(cin,s_input);
		input = stoi(s_input);
		if(input == 1)
		{
			int thekey;
			string thekeystring;
			cout << "enter the key of the node:" << endl;
			getline(cin,thekeystring);
			thekey = stoi(thekeystring);
			tail = addNode(thekey, tail);
		}
		else if(input == 2)
		{
			printList(head,tail);
		}
		else if(input == 3)
		{
			quit == true;
			cout << "quit was changed to true" <<endl;
		}
	}
	cout <<"Goodbye!" << endl;
}

void displaymenu()
{
	cout <<"Choose one of the two" << endl;
	cout <<"1.Insert a Node" << endl;
	cout <<"2.Print list"<< endl;
	cout <<"3.Quit" << endl;
}

void printList(Node *top , Node *end)
{
	Node *tmp = new Node;
	tmp = top;
	while(tmp != end){
		cout << tmp->key << " -> ";
		tmp = tmp->next;
	}
	cout << end->key << " -> NULL" << endl;
}

Node* addNode(int value, Node *end)
{
	Node *add = new Node;
	add->key = value;
	add->previous = end;
	end->next = add;
	end = add;
	return end;
}
