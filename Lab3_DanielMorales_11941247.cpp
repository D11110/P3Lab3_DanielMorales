#include <iostream>

using namespace std;

class Biblioteca{
    private:
        string nombre, ubicacion;
    public:
        Biblioteca(string, string);
        string getNombre();
        string getUbicacion();
        void setNombre();
        void setUbicacion();
};

Biblioteca::Biblioteca(string _nombre, string _ubicacion){
    nombre = _nombre;
    ubicacion = _ubicacion;
}

string Biblioteca::getNombre(){
    return nombre;
}

string Biblioteca::getUbicacion(){
    return ubicacion;
}

void Biblioteca::setNombre(){
    
}


int main(){
    
}