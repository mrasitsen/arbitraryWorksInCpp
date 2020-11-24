#include <iostream>
using namespace std;

class Pqueue{ //default as min
private:
  int data;
  Pqueue *ptr;
public:
  Pqueue();
  void add(int x); //add element to queue
  void compare(Pqueue *pre, Pqueue *after); //compare to sort
  void pop(); //delete the min element
  void show(); //shows all queue
  int top(); //return the top element
  bool IsEmpty(); //return true if empty, false if not
  ~Pqueue();
};

//ilk olusturulan node lsiteye dahil edilmez. bu sayede 

Pqueue::Pqueue(){
  ptr = NULL;
}

Pqueue::~Pqueue(){
}

//heap property korunmasi icin her adimda karsilastirma yapar

void Pqueue::compare(Pqueue *pre, Pqueue *after){
  if (pre->data >= after->data){
      int temp = pre->data;
      pre->data = after->data;
      after->data = temp;
    }
}

//eleman ekler, ekleme asamasinda surekli olarak kontrol ederek sirayi korur

void Pqueue::add(int x){

  Pqueue *newitem = new Pqueue();
  newitem->data = x;

  if (ptr == NULL){
    
    //ilk elemanin eklenmesi ozel olarak gerceklesir

      ptr = newitem;
      newitem->ptr=NULL; 
  }
  else{//ikinci ve daha sonraki elemanlar
    Pqueue *next;
    next = ptr;
    while(next->ptr != NULL){
      Pqueue::compare(next, newitem);
      next = next->ptr;
    }
    Pqueue::compare(next, newitem);
    next->ptr = newitem;
    newitem->ptr = NULL;
 }
}

void Pqueue::pop(){ //en tepedeki elemani cikarir, eger liste bossa yazi cikar
  if (ptr == NULL)
  {
    cout<<"it is already empty\n";
  }
  else{
  Pqueue *next;
  next = ptr;
  ptr = next->ptr;
  delete(next);
  }
}

//tum queue yi yazdirir

void Pqueue::show(){
  Pqueue *next;
  next = ptr;
  //cout << data <<"\n";
  while(next != NULL){
    cout<<next->data<<"\n";
    next = next->ptr;
  }
}

//en tepedeki elemani geri doner

int Pqueue::top(){
  return ptr->data;
}

//eger liste bossa true doner, degilse false

bool Pqueue::IsEmpty(){
  if (ptr == NULL)
  {
    return true;
  }
  return false;
}

int main(){

  Pqueue num;
  num.add(7);
  num.add(2);
  num.add(5);
  num.add(5);
  num.add(11);
  num.add(1);
  num.pop();
  num.pop();
  if (num.IsEmpty())
  {
    num.add(15);
  }
  int y = num.top();
  cout <<y<<"\n";
  num.show();

  return 0;
}