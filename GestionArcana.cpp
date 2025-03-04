#include <iostream>
#include <fstream>

using namespace std;

ifstream SpellList;

class Mago
{
private:
  string Nombre;
  int CantidadCaracteres;
  string Caracteres;
  int NumeroLineas;
  Mago *next;
public:
void addLinea(string linea){
 int NodoA = linea[0];
 int NodoB = linea[1];
 float Peso = linea[2];
}
// setters
void SetNombre(string Nombre){
  this->Nombre = Nombre;
}
void SetCantidadCaracteres(int  CantidadCaracteres){
  this->CantidadCaracteres = CantidadCaracteres;
}
void SetCaracteres(string Caracteres){
  this->Caracteres = Caracteres;
}
void SerNumeroLineas(int NumeroLineas){
  this->NumeroLineas = NumeroLineas;
}
  Mago(){
     Nombre ="";
     CantidadCaracteres = 0;
     Caracteres = "";
     NumeroLineas = 0;
     next = NULL;

  }
};


class Magos
{
private:

    // Mago *first;.
    // Mago *last;.
public:
void add(){
  SpellList.open("spellList.in",ios::in);
if (SpellList.fail())
{
    cout << "Error: Unable to open the file." << endl;
    return;

  }
  string linea;
  getline(SpellList,linea);
  int CantidadMagos = stoi(linea);
  while (CantidadMagos>0)
  {
    Mago *nuevo = new Mago();
    getline(SpellList,linea);
    nuevo->SetNombre(linea);
    getline(SpellList,linea);
    nuevo->SetCantidadCaracteres(stoi(linea));
    getline(SpellList,linea);
    nuevo->SetCaracteres(linea);
    getline(SpellList,linea);
    nuevo->SerNumeroLineas(stoi(linea));
    int NumeroLineas = stoi(linea);
    while (NumeroLineas>0)
    {
      getline(SpellList,linea);
      nuevo->addLinea(linea);
      NumeroLineas--;
    }
    

    CantidadMagos--;
  }
  


  
}
    Magos(){

        //   first =nullptr;
        // last = nullptr;
    }
            
};

int main(){
Magos pepe;
pepe.add();

    return 0;
}
