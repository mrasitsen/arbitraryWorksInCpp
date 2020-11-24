#include <iostream>

/* 
	single linked list imp. 
	class olarak duzenlenmistir, herhangi bir yerde header olarak kullanilabilir.
	istenildigi kadar list yaratilabilir.
	listenin basina, istenilen veriden sonrasina(ortasina), ve sonuna ekleme yapilabilir.
*/

//compx: O(1) - basa eklemek icin
//compx: O(n) - istenilen konuma ve sona eklemek icin

using namespace std;

class List{

		int value;
		List *next;

	public:

		List(int data);
		void insert_begin(int data);
		void insert_end(int data);
		void insert_loc(int data, int location);
		void print();

};

List::List(int data){

	value = data;
	next = NULL;

}

void List::insert_begin(int data){ //comp.O(1)

	/*
	burada yapilan sey: yeni bir node yaratilip ikinci node olarak ekleniyor
	sonrasindaysa bu node ile ilk node'un degerleri degistiriliyor
	bu sayede basa ekleme gerceklesmis oluyor.
	*/

	List *temp;

	List *new_item = (List*)malloc(sizeof(List));
	new_item->value = value;

	value = data;
	
	temp = next;
	next = new_item;
	new_item->next = temp;
	
}

void List::insert_end(int data){ //compx O(n) - sona ulasmak icin listeyi dolasir

	/*
	listenin sonunda bir node olusturur ve oraya baglantilari yaparak ekler
	sonuna kadar gitmesi icin listeyi taramasi gerekir
	*/

	List *new_item = (List*)malloc(sizeof(List));
	new_item->value = data;
	

	if(next == NULL)
	{
		next = new_item;
		new_item->next = NULL;
	}
	else
	{
		List *current_ptr;
		current_ptr = next;

		while(current_ptr->next != NULL)
		{
			current_ptr = current_ptr->next;
		}

		current_ptr->next = new_item;
		new_item->next = NULL;
	}
	
}

void List::insert_loc(int data, int location){ //compx. O(n) - location'i bulmasi icin listeyi taramali

	/*
	datayi istenilen konumdaki verinin arkasina yerlestirir
	istenilen konumu bulmak icin listeyi bastan sonra tarar
	*/


	List *new_item = (List*)malloc(sizeof(List));
	new_item->value = data;
	List *temp;

	if (value == location)
	{
		temp = next;
		next = new_item;
		new_item->next = temp;
	}
	else
	{
		List *current_ptr;
		
		current_ptr = next;
		while(current_ptr->value != location)
		{
			current_ptr = current_ptr->next;
			if (current_ptr == NULL)
			{
				break;
			}
		}

		if (current_ptr != NULL)
		{	
			temp = current_ptr->next;
			current_ptr->next = new_item;
			new_item->next = temp;	
		}
		else
		{	
			char yes_no;
			cout<<"location "<<location <<" is not exist so point did not add!\n";
			cout<<"do you want to add it at the end ? Yes:y, No:n\n";
			cin>>yes_no;
			if (yes_no == 'y' || yes_no == 'Y')
			{
				insert_end(data);
				cout<<"data added in the end\n";
			}
			else
			{
				cout<<"data did not add to list\n";
			}
		}
		
	}

}

void List::print(){ //yazdirir

	List *current_ptr;
	current_ptr = next;
	cout << "LIST: ";
	cout << value << " -> ";
	while(current_ptr != NULL)
	{
		cout<<current_ptr->value<<" -> ";
		current_ptr = current_ptr->next;
	}
	cout<<" END \n";

}

int main(){
	
	List list1(0);
	list1.insert_end(5);
	list1.insert_loc(7,5);
	//list1.insert_loc(8,9);
	list1.insert_begin(20);
	list1.print();



	return 0;
}


/*
soru: compx O(n) olan fonksiyonlar icin listeyi tarama zorunlulugu var.

ortaya eklemek icin belki bu makul olabilir. bu kabul edilebilir.

fakat listenin sonunu isaret eden sabit bir pointer olursa eger, sona eklemek icin 
bundan kacinilabilir. bunu iyilestirmek icin ne yapilabilir ??
*/




