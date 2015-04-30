// CMPT225_Assignment2.cpp : Defines the entry point for the console application.
#include "Deque.h"
#include <iostream>
#include <string>
void printDeque(Deque<int> dq);
void printDequeChar(Deque<char> dq);
void printDequeString(Deque<string> dq);
void TestDequeInt();
void TestDequeChar();
void TestDequeString();
void TestDequeFloat();
void SimpleTest();
int main()
{
	TestDequeInt();
	TestDequeChar();
	TestDequeString();
	TestDequeFloat();
	SimpleTest();
	cout<<"DONE"<<endl;
}
void TestDequeInt(){

Deque<int> dq;
cout<<dq.empty()<<"-1"<<endl;

dq.insert_back(1);


cout<<dq.peek_back()<<"-1"<<endl;
cout<<dq.peek_front()<<"-1"<<endl;
dq.insert_back(2);

cout<<dq.empty()<<"-0"<<endl;
dq.insert_back(3);


cout<<dq.remove_back()<<"-3"<<endl;
cout<<dq.remove_back()<<"-2"<<endl;
cout<<dq.remove_back()<<"-1"<<endl;
cout<<dq.empty()<<"-1"<<endl;
try{
dq.remove_back();
}catch (std::exception &e) {
		cout<<"Caught exception: "<<e.what()<<"\n";
	}

try{
dq.remove_front();
}catch (std::exception &e) {
		cout<<"Caught exception: "<<e.what()<<"\n";
	}


dq.insert_front(4);


cout<<dq.remove_front()<<"-4"<<endl;


dq.insert_front(7);
dq.insert_front(3);
dq.insert_front(6);

cout<<dq.remove_back()<<"-7"<<endl;


Deque<int> dq2(dq);

//printDeque(dq2);
dq2.insert_front(8);
cout<<dq2.size()<<"-3"<<endl;
cout<<dq2.peek_front()<<"-8"<<endl;
cout<<dq2.peek_back()<<"-3"<<endl;
//printDeque(dq2);

Deque<int> dq3;
dq3.insert_front(1);
dq3.insert_front(2);
dq3.insert_front(3);
dq3.insert_front(4);
dq3.insert_front(5);
//printDeque(dq3);
cout<<"-5 4 3 2 1"<<endl;
Deque<int> dq4;
dq4 = dq3;
//printDeque(dq4);
cout<<dq4.size()<<"-5"<<endl;
cout<<dq4.peek_front()<<"-5"<<endl;
cout<<dq4.peek_back()<<"-1"<<endl;

Deque<int> dq5;
Deque<int> dq6 = dq5 = dq4;
//printDeque(dq5);
//printDeque(dq6);
}
//void printDeque(Deque<int> dq){
//	
//	if (!dq.empty()){
//	Node<int>* temp = dq.front;
//	
//
//	// Iterate through list deleting Nodes
//	while(temp != NULL){
//		cout << temp->data <<",";
//		temp = temp->next;
//		
//	}
//	cout<<endl;
//	}
//}
void TestDequeChar(){

	Deque<char> dq;
	cout<<dq.empty()<<"-1"<<endl;

dq.insert_back('a');
cout<<dq.empty()<<"-0"<<endl;

cout<<dq.peek_back()<<"-a"<<endl;
dq.insert_back('b');


dq.insert_back('c');


cout<<dq.remove_back()<<"-c"<<endl;
cout<<dq.remove_back()<<"-b"<<endl;
cout<<dq.remove_back()<<"-a"<<endl;
try{
dq.remove_back();
}catch (std::exception &e) {
		cout<<"Caught exception: "<<e.what()<<"\n";
	}

try{
dq.remove_front();
}catch (std::exception &e) {
		cout<<"Caught exception: "<<e.what()<<"\n";
	}


dq.insert_front('d');


cout<<dq.remove_front()<<"-d"<<endl;


dq.insert_front('d');
dq.insert_front('c');
dq.insert_front('g');

cout<<dq.remove_back()<<"-d"<<endl;


Deque<char> dq2(dq);

//printDequeChar(dq2);
cout<<"-g c"<<endl;
dq2.insert_front('l');
cout<<dq2.size()<<"-3"<<endl;
cout<<dq2.peek_front()<<"-l"<<endl;
cout<<dq2.peek_back()<<"-c"<<endl;


Deque<char> dq3;
dq3.insert_front('a');
dq3.insert_front('b');
dq3.insert_front('c');
dq3.insert_front('d');
dq3.insert_front('e');
//printDeque(dq3);
Deque<char> dq4;
dq4 = dq3;
//printDequeChar(dq4);
cout<<"-e d c b a"<<endl;
cout<<dq4.size()<<"-5"<<endl;
cout<<dq4.peek_front()<<"-e"<<endl;
cout<<dq4.peek_back()<<"-a"<<endl;
Deque<char> dq5;
Deque<char> dq6;
dq6 = dq5 = dq4;
//printDequeChar(dq5);
//printDequeChar(dq6);
cout<<"-e d c b a"<<endl;
}
void TestDequeString(){

		Deque<string> dq;
		cout<<dq.empty()<<"-1"<<endl;

dq.insert_back("HE");
cout<<dq.empty()<<"-0"<<endl;

cout<<dq.peek_back()<<"-HE"<<endl;
dq.insert_back("she");


dq.insert_back("hell");


cout<<dq.remove_back()<<"-hell"<<endl;
cout<<dq.remove_back()<<"-she"<<endl;
cout<<dq.remove_back()<<"-HE"<<endl;
try{
dq.remove_back();
}catch (std::exception &e) {
		cout<<"Caught exception: "<<e.what()<<"\n";
	}

try{
dq.remove_front();
}catch (std::exception &e) {
		cout<<"Caught exception: "<<e.what()<<"\n";
	}

cout<<dq.empty()<<"-1"<<endl;
dq.insert_front("sal");


cout<<dq.remove_front()<<"-sal"<<endl;


dq.insert_front("sal");
dq.insert_front("hell");
dq.insert_front("testing");

cout<<dq.remove_back()<<"-sal"<<endl;


Deque<string> dq2(dq);

//printDequeString(dq2);
cout<<"-testing hell"<<endl;
dq2.insert_front("father");
cout<<dq2.size()<<"-3"<<endl;
cout<<dq2.peek_front()<<"-father"<<endl;
cout<<dq2.peek_back()<<"-hell"<<endl;


Deque<string> dq3;
dq3.insert_front("al");
dq3.insert_front("milad");
dq3.insert_front("mike");
dq3.insert_front("amir");
dq3.insert_front("shayan");

Deque<string> dq4;
dq4 = dq3;
//printDequeString(dq4);
cout<<"-shayan amir mike milad al"<<endl;
cout<<dq4.size()<<"-5"<<endl;
cout<<dq4.peek_front()<<"-shayan"<<endl;
cout<<dq4.peek_back()<<"-al"<<endl;

Deque<string> dq5;
Deque<string> dq6;
dq6 = dq5 = dq4;
//printDequeString(dq5);
//printDequeString(dq6);
cout<<"-shayan amir mike milad al"<<endl;
}
//void printDequeChar(Deque<char> dq){
//	
//	if (!dq.empty()){
//	Node<char>* temp = dq.front;
//	
//
//	// Iterate through list deleting Nodes
//	while(temp != NULL){
//		cout << temp->data <<",";
//		temp = temp->next;
//		
//	}
//	cout<<endl;
//	}
//}
//void printDequeString(Deque<string> dq){
//	
//	if (!dq.empty()){
//	Node<string>* temp = dq.front;
//	
//
//	// Iterate through list deleting Nodes
//	while(temp != NULL){
//		cout << temp->data <<",";
//		temp = temp->next;
//		
//	}
//	cout<<endl;
//	}
//}
void SimpleTest(){

 Deque<int> dq1;

      cout << dq1.empty() << " - 1" << endl;

 

      dq1.insert_front(42);

      dq1.insert_back(216);

 

      cout << dq1.peek_front() << " - 42" << endl;

      cout << dq1.peek_back() << " - 216" << endl;

      cout << dq1.size() << " - 2" << endl;

 

      Deque<int> dq2(dq1);

      Deque<int> dq3;

      dq3 = dq1;

 

      cout << dq1.remove_front() << " - 42" << endl;

      cout << dq1.remove_back() << " - 216" << endl;

 

      cout << dq2.peek_front() << " - 42" << endl;

      cout << dq2.peek_back() << " - 216" << endl;

 

      cout << dq3.peek_front() << " - 42" << endl;

      cout << dq3.peek_back() << " - 216" << endl;

}
void TestDequeFloat(){
Deque<float> dq;

cout<<dq.empty()<<"-1"<<endl;
cout<<dq.size()<<"-0"<<endl;
dq.insert_front(3.14);
cout<<dq.size()<<"-1"<<endl;
cout<<dq.peek_back()<<"-3.14"<<endl;
cout<<dq.peek_front()<<"-3.14"<<endl;

cout<<dq.remove_back()<<"-3.14"<<endl;
cout<<dq.size()<<"-0"<<endl;
try{
	cout<<dq.peek_back()<<endl;
}catch(exception e){
cout<<"caught exception: "<<e.what()<<endl;
}
try{
	cout<<dq.peek_front()<<endl;
}catch(exception e){
cout<<"caught exception: "<<e.what()<<endl;
}

}