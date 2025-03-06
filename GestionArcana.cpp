#include <iostream>
#include <fstream>

using namespace std;

class Nodo
{
private:
   int ID;
   char NOMBRE;
   float Peso;
   Nodo *next; 
public:
 void SetId(int ID){
  this->ID = ID;
 }
 void SetNombre(char NOMBRE){
  this->NOMBRE = NOMBRE;
 }
 void SetPeso(float Peso){
  this->Peso = Peso;
 }
 void SetNext(Nodo *next){
  this->next = next;
 }
  Nodo* GetNext(){
return next;
  }
 void Datos(){
  cout << "ID: " << ID << endl;
  cout << "Nombre: " << NOMBRE << endl;
  cout << "Peso: " << Peso << endl;
}
  Nodo(){
    ID = 0;
    NOMBRE = ' ';
    next = NULL;
  }
  
};

class lista
{
private:
  Nodo *first;
  Nodo *last;
public:


void Add(int nodoB,int Peso,char Nombre){
  Nodo *nuevo = new Nodo();
 nuevo->SetId(nodoB);
 nuevo->SetNombre(Nombre);
 nuevo->SetPeso(Peso);

 if (first == nullptr)
 {
  first=nuevo;
 }
 else{
  last->SetNext(nuevo);
 }
 last = nuevo;
}
 void ImprimirInfo(){
  Nodo *aux = first;
  while (aux!=nullptr)
  {
    cout<<"NODO ADYACENTE"<<endl;
    aux->Datos();
    aux = aux->GetNext();
  }
  
 }
lista(){
  first = NULL;
  last = NULL;
 }
};

class NodoV2
{
private:
  int NodoA;
  char Nombre;
  lista Adyacencia;
  NodoV2* next;
  NodoV2* prev;
public:
void SetNodoA(int id){
  NodoA = id;
}
void SetNombre(char nombre){
  Nombre = nombre;
}
void SetNext(NodoV2 *next){
this->next = next;
}
void SetPrev(NodoV2 *prev){
  this->prev = prev;
}

int GetNodoA(){
  return NodoA;
}
char GetNombre(){
  return Nombre;
}


void ImprimirAdyacencias(){
  Adyacencia.ImprimirInfo();
}
NodoV2* GetNext(){
  return next;
}
NodoV2* GetPrev(){
  return prev;
}
void SetAdyacencia(int NodoB,char Nombre,float Peso){
  Adyacencia.Add(NodoB,Peso,Nombre);
}

  NodoV2(){
    NodoA = 0;
    Adyacencia = lista();
    next = nullptr;
    prev = nullptr;
  }
  
};

class ListaV2
{
private:
  NodoV2 *first;
public:

bool NodoAAGREGADO(int ID){
  for (NodoV2 *aux = first; aux != nullptr; aux = aux->GetNext())
  {
    if (aux->GetNodoA() == ID)
    {
      return true;
    }
    
  }
  return false;
}
void AgregarRelacion(int NodoOrigen, int NodoDestino, char NombreOrigen, char NombreDestino, float Peso) {
  if (!NodoAAGREGADO(NodoOrigen)) {
      NodoV2* nuevo = new NodoV2();
      nuevo->SetNodoA(NodoOrigen);
      nuevo->SetNombre(NombreOrigen);
      nuevo->SetAdyacencia(NodoDestino, NombreDestino, Peso);

      NodoV2* aux1 = first;
      NodoV2* aux2 = nullptr;
      while ((aux1 != nullptr) && (aux1->GetNodoA() < nuevo->GetNodoA())) {
          aux2 = aux1;
          aux1 = aux1->GetNext();
      }
      if (aux1 == first) {
          first = nuevo;
      } else {
          aux2->SetNext(nuevo);
      }
      nuevo->SetNext(aux1);
      nuevo->SetPrev(aux2);
  } else {
      NodoV2* aux = first;
      while (aux->GetNodoA() != NodoOrigen) {
          aux = aux->GetNext();
      }
      aux->SetAdyacencia(NodoDestino, NombreDestino, Peso);
  }
}

void AddNodoA(int NodoA,int NodoB,char NombreA,char NombreB,float Peso){
  
  // Añadir NodoA -> NodoB
  AgregarRelacion(NodoA, NodoB, NombreA, NombreB, Peso);
  // Añadir NodoB -> NodoA
  AgregarRelacion(NodoB, NodoA, NombreB, NombreA, Peso);
}
  
void ImprimirListaV2(){
  NodoV2 *aux = first;
  while (aux != nullptr){
    cout << "Nodo BASE: " << aux->GetNodoA() << endl;
    cout << "Nombre: " << aux->GetNombre() << endl;
    cout << "Adyacencia: " << endl;
    aux->ImprimirAdyacencias();
    cout << endl;
    cout<<"=========================================="<<endl;
    aux = aux->GetNext();

  }
}
ListaV2(){
    first = nullptr;
  }
};


class Mago
{
private:
  string Nombre;
public:
  Mago(/* args */){

  }
 
};



int main(){
  ListaV2 test;
  string Letras = "ABFBDB";
  test.AddNodoA(6,1,Letras[6-1],Letras[1-1],2);
  test.AddNodoA(6,4,Letras[6-1],Letras[4-1],1);
  test.AddNodoA(1,2,Letras[1-1],Letras[2-1],1);
  test.AddNodoA(1,4,Letras[1-1],Letras[4-1],4);
  test.AddNodoA(2,4,Letras[2-1],Letras[4-1],7);
  test.AddNodoA(2,5,Letras[2-1],Letras[5-1],2);
  test.AddNodoA(5,3,Letras[5-1],Letras[3-1],1);
  test.AddNodoA(4,3,Letras[4-1],Letras[3-1],3);
  //el nodo 1 deberia estar relacionado con los nodos 2 7 9  3

  test.ImprimirListaV2();
    return 0;
}
