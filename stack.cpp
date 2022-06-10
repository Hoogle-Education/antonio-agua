#include <iostream>

using namespace std;

class Stack
{
private:
  int maxsize;
  int *array; // pointer to elements
  int currentPosition;
public:
  Stack(int maxsize);
  ~Stack();
  void push(int element);
  void pop();
  int top();
  bool empty();
};

// constructor
Stack::Stack(int maxsize)
{
  this->maxsize = maxsize;
  this->array = (int*)malloc(maxsize*sizeof(int)); // array allocation
  this->currentPosition = maxsize; // start in invalid position
}

// destructor
Stack::~Stack()
{
}

void Stack::push(int element){
  if(currentPosition - 1 >= 0){ // not full
    this->currentPosition--; 
    this->array[currentPosition] = element;
  } else cout << "you cannot add more!\n";
}

void Stack::pop(){
  if(currentPosition != maxsize){ // not empty
    this->currentPosition++;
  } else cout << "you cannot remove in an empty stack!\n";
}

int Stack::top(){
  if(currentPosition != maxsize) // stack is not empty
    return this->array[currentPosition];
  else 
    return -1;
}

bool Stack::empty(){
  return currentPosition == maxsize;
}

int main(){

  Stack pilha = Stack(3);

  pilha.push(3);
  pilha.push(4);
  pilha.push(7);
  pilha.push(1);

  cout << pilha.top() << endl; // 4

  pilha.pop();

  cout << pilha.top() << endl;

  return 0;
}