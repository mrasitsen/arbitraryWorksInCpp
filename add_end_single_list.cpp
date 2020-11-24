#include <iostream>

/* 
	Sadece sonuna eklenilebilen single linked list.
	class seklinde degildir.
	sadece tek bir list yaratilabilir
*/

// cpmx. = O(1) (yazdirma haric)


using namespace std;

struct Node{
		int value;
		Node *next;
};

Node *head = NULL;
Node *tail;

//head pointer'i otomatik olarak reference seklinde atanir
//func icinde yapilan degisiklik globalde de etkiler.

void insert(int data){ // cpmx. = O(1)

	Node *item = (Node *)malloc(sizeof(Node));
	/*memory dynamic olarak olusturulmazsa scope disina cikinca memory yok edilir
	dongu saglanamaz, devamlilik olmaz. dynamic memory de memory otomatik
	yok edilmiyor, elle yapilmasi lazim. bu sayede devamlilik var.*/
	item->value = data;
	if (head == NULL)
	{
		head = item;
		item->next = NULL;
		tail = item;
	}
	else{
		
		tail->next = item;
		item->next = NULL;
		tail = item;		
	}

}

void traverse(){ // cpmx. = O(n)

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

	

	for (int i = 0; i < 100; ++i)
	{
		insert(i);
	}

	traverse();
	


	return 0;

}



/*SORU: neden degiskeni pointer olarak yaratmak zorundayiz ? normal bir variable
degilde mecburen pointer tipinde olusturuyoruz. bunun sebebi nedir, sonuclari nedir?*/







