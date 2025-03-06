#include <iostream>
#include <fstream>
#include <cstdlib>

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
  int NumeroCaracteres;
  string Caracteres;
  ListaV2 Grafo;
  Mago *next;
public:

void CargarGrafo(int NodoA, int NodoB, char NombreA, char NombreB, float Peso){
Grafo.AddNodoA(NodoA,NodoB,NombreA,NombreB,Peso);
}


string GetNombre(){
  return Nombre;
}
int GetNumeroCaracteres(){
  return NumeroCaracteres;
}
string GetCaracteres(){
  return Caracteres;
}
Mago *GetNext(){
  return next;
}

void SetNombre(string Nombre){
this->Nombre=Nombre;
}
void SetNumeroCaracteres(int NumeroCaracteres){
  this->NumeroCaracteres=NumeroCaracteres;
}
void SetCaracteres(string Caracteres){
  this->Caracteres=Caracteres;
}
void SetNext(Mago *next){
  this->next=next;
}
  
void ImprimirGrafo(){
Grafo.ImprimirListaV2();
}


Mago(){
    Nombre = "";
    NumeroCaracteres = 0;
    Caracteres = "";
    next = nullptr;
  }
 
};



int leerEnteroHastaEspacio(const char* str) {
  char numeroStr[1000]; // Asumimos un número máximo de 20 dígitos
  int i = 0;

  // Leer caracteres hasta encontrar un espacio o el fin del string
  while (str[i] != ' ' && str[i] != '\0' && i < 19) {
      numeroStr[i] = str[i];
      i++;
  }

  numeroStr[i] = '\0'; // Terminar el string

  // Convertir el string a entero usando atoi()
  return atoi(numeroStr);
}
int leerEnteroEntreEspacios(const char* str) {
  char numeroStr[1000]; // Asumimos un número máximo de 20 dígitos
  int i = 0, j = 0;
  bool inicioNumero = false;

  // Buscar el primer espacio
  while (str[i] != ' ' && str[i] != '\0') {
      i++;
  }

  // Saltar espacios adicionales
  while (str[i] == ' ') {
      i++;
  }

  // Leer el número entre espacios
  while (str[i] != ' ' && str[i] != '\0' && j < 19) {
      numeroStr[j] = str[i];
      i++;
      j++;
      inicioNumero = true;
  }

  if (!inicioNumero){
      return 0; //devuelve 0 si no encuentra un numero entre los espacios.
  }

  numeroStr[j] = '\0'; // Terminar el string

  // Convertir el string a entero usando atoi()
  return atoi(numeroStr);
}
float leerFlotanteDesdeSegundoEspacio(const char* str) {
  char numeroStr[1000]; // Asumimos un número máximo de 20 dígitos
  int i = 0, j = 0;
  int espaciosEncontrados = 0;
  bool inicioNumero = false;

  // Buscar el segundo espacio
  while (str[i] != '\0') {
      if (str[i] == ' ') {
          espaciosEncontrados++;
          if (espaciosEncontrados == 2) {
              i++; // Empezar a leer después del segundo espacio
              break;
          }
      }
      i++;
  }

  // Leer el número hasta el final del string
  while (str[i] != '\0' && j < 19) {
      numeroStr[j] = str[i];
      i++;
      j++;
      inicioNumero = true;
  }

  if (!inicioNumero){
      return 0; //devuelve 0 si no encuentra un numero despues del segundo espacio.
  }

  numeroStr[j] = '\0'; // Terminar el string

  // Convertir el string a flotante usando atof()
  return atof(numeroStr);
}



class Hechiceros
{
private:
fstream Archivo;
  Mago *first;
  Mago *last;
public:
void CargarDatosSpellList(){
Archivo.open("spellList.in");
    if (Archivo.fail()) {
      cout << "Error al abrir el archivo" << endl;
      return;
    }
    string Linea;
    getline(Archivo, Linea);
    int CantidadMagos = stoi(Linea);
    while (CantidadMagos > 0)
    {
      Mago *nuevo = new Mago();
     
      getline(Archivo,Linea); //NOMBRE DEL MAGO
      nuevo->SetNombre(Linea);

      getline(Archivo,Linea);//CANTIDAD DE CARACTERES
      nuevo->SetNumeroCaracteres(stoi(Linea));

      getline(Archivo,Linea);//CARACTERES
      nuevo->SetCaracteres(Linea);
      string Caracteres = Linea;
      
      getline(Archivo,Linea);//LINEAS DE ENTRADA DELOS NODOS
      int CantidadLineas = stoi(Linea);

      while (CantidadLineas > 0)
      {
        getline(Archivo,Linea);//LINEAS DE ENTRADA DELOS NODOS
        int nodoA =leerEnteroHastaEspacio(Linea.c_str());
        int nodoB = leerEnteroEntreEspacios(Linea.c_str());
        float Peso = leerFlotanteDesdeSegundoEspacio(Linea.c_str());

        nuevo->CargarGrafo(nodoA,nodoB,Caracteres[nodoA-1],Caracteres[nodoB-1],Peso);
        CantidadLineas--;
      }
      
      if (first == nullptr)
      {
        first = nuevo;
      }
      else{
        last->SetNext(nuevo);
      }
     last = nuevo;
      
      CantidadMagos--;
    }
    

 
    Archivo.close();
}  

void ImprimirMagos(){
  Mago *actual = first;
  while (actual != nullptr){
    cout<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"<<endl;
    cout << "Nombre: " << actual->GetNombre() << endl;
    cout << "Caracteres: " << actual->GetCaracteres() << endl;
    cout <<"++++++++++++ Grafo: +++++++++++" << endl;
    actual->ImprimirGrafo();
    cout << "++++++++++++ Fin Grafo: +++++++++++" << endl;
    cout<<endl;
    actual = actual->GetNext();
    cout<<"WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"<<endl;
  }
}
Hechiceros(){
      first = nullptr;
  }
  
};

int main(){
  
Hechiceros MAGOS;
MAGOS.CargarDatosSpellList();
MAGOS.ImprimirMagos();

    return 0;
}
