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
   bool Visitado;
   Nodo *next; 
public:
float GetPeso(){
  return Peso;
}
int GetId(){
  return ID;
}
char GetNombre(){
  return NOMBRE;
}
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
    Peso = 0;
    Visitado = false;
  }
  
};

class lista//LISTA DE ADYACENCIA
{
private:
  Nodo *first;
  Nodo *last;
public:
Nodo* GetFirst() {
  return first;
}

int NodoConMayorPeso(){
 Nodo* aux =first;
 int NodoConPesoMax = aux->GetId(); 
 while(aux!=NULL){
    if(aux->GetPeso() < aux->GetNext()->GetPeso()){
      NodoConPesoMax = aux->GetNext()->GetId();
    }
    aux = aux->GetNext();
 }
 return NodoConPesoMax;//aqui me retorna el nodo que tiene el peso maximo en mi lista
}

bool TodosSonSoportes(){
  Nodo *aux = first;
  while(aux != nullptr){
    if (aux->GetNombre() != 'B')
    {
      return false;
    }
    aux = aux->GetNext(); // Update the pointer to avoid infinite loop
  }
  return true;
}


bool PoseeRunasElementales(){
  Nodo *actual = first;
  while(actual != NULL){
    if (actual->GetNombre() == 'I' ||actual->GetNombre() == 'Q' ||actual->GetNombre() == 'T' ||actual->GetNombre() == 'V' ||actual->GetNombre() == 'L' ||actual->GetNombre() == 'O')
    {
      return true;
    }
    actual = actual->GetNext();
  }
  return false;
}
void Add(int nodoB,int Peso,char Nombre){
  Nodo *nuevo = new Nodo();
  nuevo->SetId(nodoB);
  nuevo->SetPeso(Peso);
  nuevo->SetNombre(Nombre);

  Nodo *Aux1 = first;
  Nodo *Aux2;

  while (Aux1!=nullptr && Aux1->GetPeso()< nuevo->GetPeso())
  {
      Aux2 =Aux1;
      Aux1 = Aux1->GetNext();
  }
  if (Aux1 == first)
  {
      first = nuevo;
  }
  else{
      Aux2->SetNext(nuevo);
  }
  
  nuevo->SetNext(Aux1);
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
  bool Visitado;
  lista Adyacencia;
  NodoV2* next;
  NodoV2* prev;
public:
lista& GetAdyacencia() {
  return Adyacencia;
}

bool PoseeRunasElementales(){
  return Adyacencia.PoseeRunasElementales();
}
bool TodosSonSoportes(){
  return Adyacencia.TodosSonSoportes();
}
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
    Visitado = false;
  }
  
};

class ListaV2//GRAFO
{
private:
  NodoV2 *first;

 // Función auxiliar para encontrar el ciclo más largo usando backtracking
   void encontrarCicloMasLargo(NodoV2* nodoActual, NodoV2* nodoAnterior, int longitudActual, int& longitudMaxima, bool visitados[]) {
    visitados[nodoActual->GetNodoA() - 1] = true; // Marcar el nodo como visitado

    // Recorrer todos los nodos adyacentes
    Nodo* adyacente = nodoActual->GetAdyacencia().GetFirst();
    while (adyacente != nullptr) {
      int nodoAdyacenteID = adyacente->GetId();
      NodoV2* nodoAdyacenteV2 = GetNodoPorID(nodoAdyacenteID); // Obtener el NodoV2 correspondiente

      if (nodoAdyacenteV2 != nullptr) {
        if (!visitados[nodoAdyacenteID - 1]) {
          // Si el nodo adyacente no ha sido visitado, continuar la búsqueda
          encontrarCicloMasLargo(nodoAdyacenteV2, nodoActual, longitudActual + 1, longitudMaxima, visitados);
        } else if (nodoAdyacenteID != nodoAnterior->GetNodoA()) {
          // Si encontramos un ciclo, actualizar la longitud máxima
          if (longitudActual + 1 > longitudMaxima) {
            longitudMaxima = longitudActual + 1;
          }
        }
      }

      adyacente = adyacente->GetNext();
    }

    visitados[nodoActual->GetNodoA() - 1] = false; // Desmarcar el nodo para permitir otros caminos
  }
  
  
  public:
    // Función para obtener un NodoV2 por su ID
  NodoV2 *GetNodoPorID(int id) {
      NodoV2* actual = first;
      while (actual != nullptr) {
        if (actual->GetNodoA() == id) {
          return actual;
        }
        actual = actual->GetNext();
      }
      return nullptr; // Si no se encuentra el nodo
    }
  // Función para verificar si el ciclo más largo es par
  bool Articulo5Valido() {
    int longitudMaxima = 0;
    bool visitados[100] = {false}; // Asumimos un máximo de 100 nodos

    // Iniciar la búsqueda desde cada nodo
    NodoV2* actual = first;
    while (actual != nullptr) {
      encontrarCicloMasLargo(actual, nullptr, 0, longitudMaxima, visitados);
      actual = actual->GetNext();
    }
     // Verificar si la longitud del ciclo más largo es par
     cout<<"LongitudMaxima: "<<longitudMaxima<<endl;
     return (longitudMaxima % 2 == 0);
    }
  // Función para verificar si el hechizo es válido según todos los artículos
  bool HechizoValido() {
    return Articulo1Valido() && Articulo2Valido() && Articulo3Valido() && Articulo4Valido() && Articulo5Valido();
  }




void DesplazarseIzquierda(NodoV2 *actual,int Objetivo){
  
  while (actual->GetNodoA() != Objetivo ){
  {
    actual =actual->GetPrev();
  }
  
 }
}
void DesplazarseDerecha(NodoV2 *actual,int Objetivo){
  while (actual->GetNodoA() != Objetivo ){
    {
      actual =actual->GetNext();
    }
    
   }
}



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
int CantidadRunasElementales(){
  int runas = 0;
  for (NodoV2 *actual = first; actual != nullptr; actual = actual->GetNext()){
    if (actual->GetNombre() == 'I' ||actual->GetNombre() == 'Q' ||actual->GetNombre() == 'T' ||actual->GetNombre() == 'V' ||actual->GetNombre() == 'L' ||actual->GetNombre() == 'O'){
   
      runas++;
     }
  }
  return runas;
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

bool PoseeConfluencia(){
  NodoV2* actual = first;
  while (actual != nullptr) {
    if (actual->GetNombre() == 'A'){
     return true;
    }
    actual = actual->GetNext();
  }

  return false;
}

bool Articulo1Valido(){//SOLO UN NODO CON CARACTER A ?
  NodoV2 *actual = first;
  int Contador = 0;
  while (actual != nullptr) {
    if (actual->GetNombre() == 'A'){
   
     Contador++;
    }
    actual = actual->GetNext();
  }

  if (Contador >1)
  {
    return false;
  }
  return true;
}
bool Articulo2Valido(){//DEL NODO DE CARACTER A SUS NODOS ADYACENTES TODOS DEBEN SER DE CARACTER B
  if (!PoseeConfluencia())
  {
    return true;
  }
  NodoV2 *actual = first;
  while (actual != nullptr) {
    if (actual->GetNombre() == 'A'){
        if (actual->TodosSonSoportes())
        {
          return true;
        }
        else{
          return false;
        }
    }
    actual = actual->GetNext();
  }
  return false;
}
bool Articulo3Valido(){//EL HECHIZO SOLO PUEDE TENER 3 RUNAS ELEMENTALES
  NodoV2 *actual = first;
  int Contador = 0;
if (CantidadRunasElementales() < 3)
{
  return true;
}
return false;

}
bool Articulo4Valido(){//VALIDA QUE UNA RANA CATALITICA NO ESTE ADYACENTE A UNA RUNA ELEMENTAL
  NodoV2 *actual = first;
  
  while (actual != nullptr) {
    if (actual->GetNombre() == 'D'){
      if (actual->PoseeRunasElementales())
      {
        return false;
      }
    }
    actual = actual->GetNext();
  }

 
  return true;
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

bool HechizoValido(){
  return Grafo.HechizoValido();
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
void MagosValido(){
  Mago *actual = first;
  while (actual != nullptr){
    if (actual->HechizoValido())
    {
      cout<<"Hechizo valido"<<endl;
    }
    else{
      cout<<"Hechizo invalido"<<endl;
    }
    

    actual = actual->GetNext();
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
MAGOS.MagosValido();  

    return 0;
}
