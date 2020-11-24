#include <iostream>

using namespace std;

class circle{
	int num;
	circle *next;
	circle *last;
public:
	circle();
	void show();
	void addElement(int number);
	void deleteElement(int number);
	~circle();
};

circle::circle(){
	next = NULL;
	last = this;
}

circle::~circle(){

}

void circle::addElement(int number){ //tum elemanlar ayni surece tabi
	circle *newElement = new circle() ;
	circle *current = last;
	current->next = newElement;
	newElement->num = number;
	newElement->next = next;
	last = newElement;
}

void circle::deleteElement(int number){
	if (next == NULL){
		cout<<"List is empty\n";
	}
	else{
		circle *current = next;
		if (next->num == number){
			if (next == current->next){
				delete current;
				last = NULL;
				next = NULL;

			}else{
				next = current->next;
				last->next = current->next;
				delete current;
			}
			
		}
		else{
			circle *current = next;
			circle *prev;
			while(current->num != number){
				prev = current;
				current = current->next;
			}
			if (current == last){
				last = prev;
			}
			prev->next = current->next;
			delete current;
		}
	}
}



void circle::show(){
	if (next == NULL){
		cout<<"list is empty\n";
	}
	else{
		circle *current = next;
		while(true){
			cout<<current->num<<" ";
			if (current == last){
				cout<<"\n";
				break;
			}
			current = current->next;			
		}
	}
}

int main(){

	circle firstCircle;
	firstCircle.addElement(1);
	firstCircle.addElement(2);
	firstCircle.addElement(3);
	firstCircle.addElement(4);
	firstCircle.show();
	firstCircle.deleteElement(1);
	firstCircle.deleteElement(3);
	firstCircle.show();
	firstCircle.deleteElement(2);
	firstCircle.show();
	firstCircle.deleteElement(4);
	firstCircle.show();

	return 0;
}