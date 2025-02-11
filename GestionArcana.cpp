#include <iostream>
#include <fstream>
using namespace std;

ifstream SpellList;

//CADA VERTICE POSEE UNA LISTA DE LOS VERTICES ADYACENTES A EL
struct Nodo{
    int Id;
    char Tipo;
    float peso;
    Nodo *siguiente;
    void ImprimirDatos(){
        cout << "Id: " << Id << endl;
        cout << "Tipo: " << Tipo << endl;
        cout << "Peso: " << peso << endl;
        cout << "///---///---///---///---///---///---///"<<endl;
        cout<<endl;
    }
    //CARACTER 0 CORRESPONDE AL VERTICE 1

    Nodo(int Id,int peso,char tipo){
        this->Id = Id;
        this->Tipo = tipo;
        this->peso = peso;
    }
    Nodo(){
        Id = 0;
        Tipo = ' ';
        peso = 0;
        siguiente = NULL;
    }
};
struct Lista
{
    Nodo *primero;
    Nodo *ultimo;
    
    bool YaAgregado(int Id){
       Nodo *aux = primero;
       while(aux != NULL){
        if(aux->Id == Id){
           return true;
        }
       }
       return false;
    }
    void InsertarNodo(int Id,int peso,char tipo){
        if (!YaAgregado(Id))
        {
            Nodo *nuevo = new Nodo(Id,peso,tipo);
         
            if (ultimo!=nullptr)
            {
                ultimo->siguiente = nuevo;
            }else{
                primero = nuevo;
            }
            ultimo = nuevo;
        }
        
        
        
      
    }
    void MostrarLista(){
      Nodo *aux = primero;
      while (aux != nullptr){
        aux->ImprimirDatos();
        aux = aux->siguiente;

      }
    }
    void EliminarItem(){
        cout<<"Diga el id del elemento que quiera eliminar: ";
        int id;
        cin>>id;
        Nodo *aux = primero;
         Nodo *aux2;
        while (aux->Id != id)
        {   aux2 = aux;
            aux =aux->siguiente;
        }
        
        if (aux ==primero)
        {
            primero = primero->siguiente;
            delete aux;
        }
        else{
               aux2->siguiente = aux->siguiente;
               delete aux;

        }
        
    }

  Lista(){
    primero = nullptr;
    ultimo = nullptr;
  }

};

//IMPLEMENTACION DE LAS LISTA DE ADYACENCIA 
struct Vertice
{
    int Id;
    char Tipo;
    Lista Adyacencia;
    Vertice *siguiente;
    void ImprimirDatos(){
        cout << "Id: " << Id << endl;
        cout << "Tipo: " << Tipo << endl;
        cout << "Adyacencias: " ; Adyacencia.MostrarLista();  cout<<endl;
        
        cout << "///---///---///---///---///---///---///"<<endl;
        cout<<endl;
    }
    //CARACTER 0 CORRESPONDE AL VERTICE 1
    void CargarOrigen(int Origen,char Tipo){
       Id = Origen;
       this->Tipo = Tipo;
    }
    void CargarDatos(int Destino,float Peso,char Tipo){
       Adyacencia.InsertarNodo(Destino,Peso,Tipo);
    }
    
    Vertice(int Origen,char Tipo){
        CargarOrigen(Origen,Tipo);
    }
    Vertice(){
        Id = 0;
        Tipo = ' ';
        Adyacencia = Lista();
        siguiente = NULL;
    }
};


struct Hechizo
{
    Vertice *primero;
    Vertice *ultimo;

    bool YaAgregado(int Id){
        Vertice *aux = primero;
        while(aux != NULL){
         if(aux->Id == Id){
            return true;
         }
        }
        return false;
     }
    void InsertarNodo(int Origen,char Tipo){
        if (!YaAgregado(Origen))
        {
            Vertice *nuevo = new Vertice(Origen,Tipo);
         
            if (ultimo!=nullptr)
            {
              ultimo->siguiente = nuevo;
            }else{
                primero = nuevo;
            }
            ultimo = nuevo;
        }
        
      
        
      
    }
    void CargarListasDeAdyacencia(int Origen,int Destino,float peso,char Tipo){
        Vertice *aux =primero;
        while(aux!=nullptr){
            if (aux->Id ==Origen)
            {
                aux->CargarDatos(Destino,peso,Tipo);
                
            }
            aux = aux->siguiente;
            
        }
     }
     void ImprimirListasDeAdyacencia(){
        Vertice *aux = primero;
        while(aux != NULL){
            cout << "Vertice: " << aux->Id << endl;
            cout << "Tipo: " << aux->Tipo << endl;
            cout << "Peso con: ";
            aux->ImprimirDatos();
            cout<<endl;
            aux = aux->siguiente;
        }
     }
    
    
    void EliminarItem(){
        cout<<"Diga el id del elemento que quiera eliminar: ";
        int id;
        cin>>id;
        Vertice *aux = primero;
         Vertice *aux2;
        while (aux->Id != id)
        {   aux2 = aux;
            aux =aux->siguiente;
        }
        
        if (aux ==primero)
        {
            primero = primero->siguiente;
            delete aux;
        }
        else{
               aux2->siguiente = aux->siguiente;
               delete aux;

        }
        
    }

  Hechizo(){
    primero=nullptr;
    ultimo=nullptr;
  }

};

struct Mago{

    string Nombre;
    int CantidadVertices;
    string Caracteres;
    int CantidadDeLineas;
    Hechizo Encantamiento;
    Mago *next;


     
     void LoadPrimary(string Nombre, string Caracteres, int CantidadVertices, int CantidadDeLineas){
              this->Nombre = Nombre;
              this->CantidadVertices = CantidadVertices;
              this->Caracteres = Caracteres;
              this->CantidadDeLineas = CantidadDeLineas;
     }
     void CargarPrincipales(int &Origen,int &Destino,float &Peso,string Arr[],int i){
        string aux;
        aux = Arr[i][0];
        Origen = stoi(aux);
        aux = Arr[i][1];
        Destino = stoi(aux);
        aux = Arr[i][2];
        Peso = stoi(aux);
     }
     void CargarHechizo(string Arr[]){
        
        for (int i = 0; i < CantidadDeLineas; i++)
        {   int Origen,Destino;
            float Peso;
            CargarPrincipales(Origen,Destino,Peso,Arr,i);
            Encantamiento.InsertarNodo(Origen,Caracteres[Origen-1]); 
        }

        for (int i = 0; i < CantidadDeLineas; i++)
        {   
            int Origen,Destino;
            float Peso;
            CargarPrincipales(Origen,Destino,Peso,Arr,i);
            Encantamiento.CargarListasDeAdyacencia(Origen,Destino,Peso,Caracteres[Destino-1]); 
        }
        
     }
     void ImprimirHechizo(){
        Encantamiento.ImprimirListasDeAdyacencia();
     }

     Mago(){
        Nombre = "";
        CantidadVertices = 0;
        Caracteres = "";
        next = nullptr;
        CantidadDeLineas = 0;
        Encantamiento = Hechizo();
    }
};







int NumeroHechizos(){
    SpellList.open("spellList.in", ios::in);
    if (SpellList.fail()) {
        cout << "Error al abrir el archivo" << endl;
        return 0;
    }
    string line;
    getline(SpellList, line);
    
    SpellList.close();
    
    return stoi(line);
}



int main(){
int N = NumeroHechizos();


    return 0;
}