#include <iostream>

// cpmx. = O(n) (yazdirma haric)

using namespace std;

struct Node{
		int value;
		Node *next;
};

Node *head = NULL;

//head pointer'i otomatik olarak reference seklinde atanir
//func icinde yapilan degisiklik globalde de etkiler.

void insert(int data, int point){ // cpmx. = O(n)

	Node *item = (Node *)malloc(sizeof(Node));
	/*memory dynamic olarak olusturulmazsa scope disina cikinca memory yok edilir
	dongu saglanamaz, devamlilik olmaz. dynamic memory de memory otomatik
	yok edilmiyor, elle yapilmasi lazim. bu sayede devamlilik var.*/
	Node *temp;
	item->value = data;
	if (head == NULL)
	{
		 head = item;
		 item->next = NULL;
		 cout << "data "<<data<<" is succesfully added on list\n";
	}
	else{
		Node *ptr;
		ptr = head;
		
		if (ptr->value == point)
		{
			temp = ptr->next;
			ptr->next = item;
			item->next = temp;
			cout << "data "<<data<<" is succesfully added on list\n";
		}
		else
		{
			
			while(ptr != NULL && ptr->value != point)
			{
				ptr = ptr->next; // cpmx. etkileyen kisim
				//listenin sonuna ulasmak icin bastan baslayarak sona kadar gider
				//cout <<"donguye girdi\n";
			}

			//cout << "item was not in the list, so added in the end\n";
			if (ptr == NULL){

				cout<<"point "<<point<<" is not found so data "<<data<<" is not added on list\n";
			}
			else{
				
				temp = ptr->next;
				ptr->next = item;
				item->next = temp;
				cout<<"data "<<data<<" is succesfully added on list\n";

			}

		}

	}

}

void traverse(){

	Node *tracker;

	tracker = head;
	/*
	eger tracker yerine dogrudan head'in kendisini kullansaydik
	head degiskeni global anlamda etkilenirdi ve listenin sonuna
	gelmis olurdu. bu da ikinci kez traverse edememeye yol acardi.
	*/
	cout << "LIST: Head -> ";

	while(tracker != NULL){

		cout << tracker->value << " -> ";
		tracker = tracker->next;		
	}

	cout << "tail\n";
}


int main(){

	insert(3,3);
	insert(4,3);
	insert(5,4);
	insert(6,5);
	insert(8,4);
	insert(9,11);
	insert(2,4);
	insert(8,2);

	traverse();
	


	return 0;

}



/*SORU: neden degiskeni pointer olarak yaratmak zorundayiz ? normal bir variable
degilde mecburen pointer tipinde olusturuyoruz. bunun sebebi nedir, sonuclari nedir?*/







