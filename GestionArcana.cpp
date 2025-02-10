#include <iostream>
#include <fstream>
using namespace std;


//CADA VERTICE POSEE UNA LISTA DE LOS VERTICES ADYACENTES A EL

class Nodo
{
private:
    int valor;
    float peso;
    Nodo* siguiente;
    Nodo* previo;
public:
   
   //GETTERS
   int getValor(){return valor;}
   float getPeso(){return peso;}
   Nodo* getSiguiente(){return siguiente;}
   Nodo* getPrevio(){return previo;}

   //setters
   void setValor(int valor){this->valor = valor;}
   void setPeso(float peso){this->peso = peso;}
   void setSiguiente(Nodo* siguiente){this->siguiente = siguiente;}
   void setPrevio(Nodo* previo){this->previo = previo;}
   

    Nodo(){
        valor = 0;
        peso = 0;
        siguiente = nullptr;
    }
    
};

class ListDoble
{
private:
   Nodo* head;
   Nodo* tail;
public:
bool YaAgregado(int x){
    Nodo* aux = head;
    while (aux != nullptr) {
        if (x == aux->getValor()) 
        {
            return true;
        }
        else{
            aux = aux->getSiguiente();
        }
        
    }
    return false;
}
   void InsertarAlFinal(int X,float peso){
    if (!YaAgregado(X))
    {
             Nodo* nuevoNodo = new Nodo();
            nuevoNodo->setValor(X);
            nuevoNodo->setPeso(peso);
            nuevoNodo->setSiguiente(nullptr);
            if (tail != nullptr) {
                tail->setSiguiente(nuevoNodo);
                nuevoNodo->setPrevio(tail);
            } else {
                head = nuevoNodo;
            }
            tail = nuevoNodo;
    }
   }
   
   void ImprimirLista(){
    Nodo* aux = head;
    while (aux != nullptr) {
        cout << "Valor: " << aux->getValor() << " Peso: "<< aux->getPeso()<<endl;
    }
    cout<<endl;
    cout<<endl;
   }
   
    ListDoble(){
        head = nullptr;
        tail = nullptr;
    }

  
};



//se implementa el sistema de listas y nodos para tener una estructura de datops de una lista doblemente
//ahora se creear una estructura vertice que almacenara una lista de nodos y un peso para cada uno de ellos

class Vertice{
private:
int Id;
char Tipo;
ListDoble listaNodos;
Vertice *next;
Vertice *prev;
public:

   //getters
   int getId(){ return Id; }
   char getTipo(){ return Tipo; }
   Vertice *getNext(){ return next; }
   Vertice *getPrev(){ return prev; }

   //setters 
   void SetNext(Vertice*next){this->next=next;}
   void SetPrev(Vertice*prev){this->prev=prev;}
   void SetId(int Id){this->Id=Id;}
   void SetTipo(char Tipo){this->Tipo=Tipo;}

   
   
   
   void CargarRelaciones(int Y,int Z){
         listaNodos.InsertarAlFinal(Y,Z);
   }
   //constructor

   Vertice(){
    Id = 0;
    listaNodos = ListDoble();
    next = nullptr;
    prev = nullptr;
    Tipo = ' ';
   }
};

class HECHIZO
{
private:
    Vertice *head;
    Vertice *tail;
public:
    //setters
   

    //getters
    Vertice* getHead(){ return head; }
    Vertice* getTail(){ return tail; }


   bool YaAgregado(int X){
    Vertice* aux = head;
    while(aux != nullptr){
        if(aux->getId() == X){

            return true;
        }
        else{
            aux = aux->getNext();
        }
    }
    return false;
   }
   void InsertarAlFinal(int X){
        if (!YaAgregado(X))
        {
               
            Vertice* nuevoVertice = new Vertice();
            nuevoVertice->SetId(X);
            
            nuevoVertice->SetNext(nullptr);
            if (tail != nullptr) {
                tail->SetNext(nuevoVertice);
                nuevoVertice->SetPrev(tail);
            } else {
                head = nuevoVertice;
            }
            tail = nuevoVertice;
        }
        
    
    
   }
   

    
    //constructor
    HECHIZO(){
        head =nullptr;
        tail =nullptr;
        }
   
};

//ya creado el sistema para almacenar los hechizos queda asignarselos a sus respectivos magos




class Mago
{
private:
    string Nombre;
    HECHIZO Encantamiento;
public:

    Mago(){S
        Encantamiento = HECHIZO();
    }
    
};

ifstream SpellList;

int main(){

    return 0;
}DDDDD