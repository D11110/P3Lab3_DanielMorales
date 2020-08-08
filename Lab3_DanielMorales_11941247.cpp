#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Libro
{
private:
    string titulo, autor;
    int yearPublicado;

public:
    Libro(string, string, int);
    string getTitulo();
    string getAutor();
    int getYearPublicado();
    void setTitulo(string);
    void setAutor(string);
    void setYearPublicado(int);
    ~Libro();
};

Libro::Libro(string _titulo, string _autor, int _yearPublicado)
{ //constructor libro
    titulo = _titulo;
    autor = _autor;
    yearPublicado = _yearPublicado;
}

string Libro::getTitulo()
{
    return titulo;
}

string Libro::getAutor()
{
    return autor;
}

int Libro::getYearPublicado()
{
    return yearPublicado;
}

void Libro::setTitulo(string _titulo)
{
    titulo = _titulo;
}

void Libro::setAutor(string _autor)
{
    autor = _autor;
}

void Libro::setYearPublicado(int _yearPublicado)
{
    yearPublicado = _yearPublicado;
}

Libro::~Libro()
{
}

class Catalogo
{
private:
    vector<Libro *> libros;

public:
    Catalogo(vector<Libro *>);
    Catalogo();
    void setLibros(vector<Libro *>);
    vector<Libro *> getLibros();
    void addLibro(Libro *);
    ~Catalogo();
};

Catalogo::Catalogo(vector<Libro *> _libros)
{
    libros = _libros;
}

Catalogo::Catalogo()
{
}

Catalogo::~Catalogo() {}

void Catalogo::setLibros(vector<Libro *> _libros)
{
    libros = _libros;
}

vector<Libro *> Catalogo::getLibros()
{

    return libros;
}

void Catalogo::addLibro(Libro *_libro)
{
    libros.push_back(_libro);
}

class Biblioteca
{
private:
    string nombre, ubicacion;
    int pisos, estante, seccion;
    Catalogo ****simulacionBiblio;

public:
    Biblioteca(string, string, int, int, int);
    string getNombre();
    string getUbicacion();
    void setNombre(string);
    void setUbicacion(string);
    int getPisos();
    int getEstantes();
    int getSecciones();
    Catalogo ****getCubo();
    ~Biblioteca();
};

Biblioteca::Biblioteca(string _nombre, string _ubicacion, int _pisos, int _estantes, int _secciones)
{ //Constructor biblioteca
    nombre = _nombre;
    ubicacion = _ubicacion;
    pisos = _pisos;
    estante = _estantes;
    seccion = _secciones;

    simulacionBiblio = new Catalogo ***[_pisos];

    for (int i = 0; i < _pisos; i++)
    {
        simulacionBiblio[i] = new Catalogo **[_estantes];
        for (int j = 0; j < _estantes; j++)
        {
            simulacionBiblio[i][j] = new Catalogo *[_secciones];
            for (int k = 0; k < _secciones; k++)
            {
                simulacionBiblio[i][j][k] = new Catalogo();
            }
        }
    }
}

int Biblioteca::getPisos()
{
    return pisos;
}

int Biblioteca::getEstantes()
{
    return estante;
}

int Biblioteca::getSecciones()
{
    return seccion;
}

Catalogo ****Biblioteca::getCubo()
{
    return simulacionBiblio;
}

string Biblioteca::getNombre()
{ //Inicio getters y setter biblioteca
    return nombre;
}

string Biblioteca::getUbicacion()
{
    return ubicacion;
}

void Biblioteca::setNombre(string _nombre)
{
    nombre = _nombre;
}

void Biblioteca::setUbicacion(string _ubicacion)
{ //fin getters y setters biblioteca
    ubicacion = _ubicacion;
}

Biblioteca::~Biblioteca()
{ //destructor
}

int main()
{
    vector<Biblioteca> bibliotecas;

    bool vive = true;
    while (vive)
    {
        std::cout << "Menu" << std::endl;
        std::cout << "1. Crear biblioteca" << std::endl;
        std::cout << "2. Agregar libro" << std::endl;
        std::cout << "3. Buscar por titulo" << std::endl;
        std::cout << "4. Buscar por autor" << std::endl;
        std::cout << "5. Explorar biblioteca" << std::endl;
        std::cout << "0. Salir" << std::endl;
        int opcionSel;

        cin >> opcionSel;
        switch (opcionSel)
        {
        case 1:
        {
            string nombreBiblioteca, ubicacionBiblioteca;
            int pisos, estantes, secciones;
            std::cout << "Ingrese el nombre de la biblioteca: " << std::endl;
            cin >> nombreBiblioteca;
            std::cout << "Ingrese la ubicacion de la biblioteca: " << std::endl;
            cin >> ubicacionBiblioteca;
            std::cout << "Ingrese cuantos pisos tiene: " << std::endl;
            cin >> pisos;
            std::cout << "Ingrese cuantos estantes tiene: " << std::endl;
            cin >> estantes;
            std::cout << "Ingrese cuantas secciones tiene: " << std::endl;
            cin >> secciones;

            Biblioteca biblio(nombreBiblioteca, ubicacionBiblioteca, pisos, estantes, secciones);
            bibliotecas.push_back(biblio);


            std::cout << "La biblioteca fue creada exitosamente. " << std::endl;
        }
        break;

        case 2:
        {
            if (bibliotecas.size() <= 0)
            {
                std::cout << "No hay bibliotecas creadas. " << std::endl;
            }
            else
            {
                string nombre, autor;
                int year;
                std::cout << "Ingrese el nombre del libro: " << std::endl;
                cin >> nombre;
                std::cout << "Ingrese el autor del libro: " << std::endl;
                cin >> autor;
                std::cout << "Ingrese el anio de publicacion del libro: " << std::endl;
                cin >> year;

                //creacion de objeto libro

                std::cout << "Seleccione el indice de la biblioteca a la cual desea agregar el libro: " << std::endl;

                for (int i = 0; i < bibliotecas.size(); i++)
                {
                    std::cout << i << " - " << bibliotecas.at(i).getNombre() << std::endl;
                }

                int indSelBibl, piso, estante, seccion;

                cin >> indSelBibl;

                std::cout << "Ingrese el piso: " << std::endl;
                cin >> piso;

                while (piso > bibliotecas.at(indSelBibl).getPisos())
                {
                    std::cout << "Ingrese el piso: " << std::endl;
                    cin >> piso;
                }

                std::cout << "Ingrese el estante: " << std::endl;
                cin >> estante;

                while (estante > bibliotecas.at(indSelBibl).getEstantes())
                {
                    std::cout << "Ingrese el estante: " << std::endl;
                    cin >> estante;
                }

                std::cout << "Ingrese la seccion: " << std::endl;
                cin >> seccion;

                while (seccion > bibliotecas.at(indSelBibl).getSecciones())
                {
                    std::cout << "Ingrese la seccion: " << std::endl;
                    cin >> seccion;
                }

                Libro* temporal = new Libro(nombre, autor, year);

                bibliotecas.at(indSelBibl).getCubo()[piso][estante][seccion]->addLibro(temporal);


                std::cout << "El libro se agrego exitosamente. " << std::endl;
            }
        }
        break;

        case 3:
        {
            std::cout << "Ingrese el nombre del libro que desea buscar: " << std::endl;
            string nombreLibroABuscar;
            cin >> nombreLibroABuscar;

            for (int i = 0; i < bibliotecas.size(); i++)
            {
                for (int j = 0; j < bibliotecas.at(i).getPisos(); j++)
                {
                    for (int k = 0; k < bibliotecas.at(i).getEstantes(); k++)
                    {
                        for (int l = 0; l < bibliotecas.at(i).getSecciones(); l++)
                        {
                            for (int n = 0; n < bibliotecas.at(i).getCubo()[j][k][l]->getLibros().size(); n++)
                            {
                                if (bibliotecas.at(i).getCubo()[j][k][l]->getLibros().at(n)->getTitulo() == nombreLibroABuscar)
                                {
                                    std::cout << "" << std::endl;
                                    std::cout << "Titulo: " << bibliotecas.at(i).getCubo()[j][k][l]->getLibros().at(n)->getTitulo() << std::endl;
                                    std::cout << "Autor: " << bibliotecas.at(i).getCubo()[j][k][l]->getLibros().at(n)->getAutor() << std::endl;
                                    std::cout << "Anio: " << bibliotecas.at(i).getCubo()[j][k][l]->getLibros().at(n)->getYearPublicado() << std::endl;
                                    std::cout << "Biblioteca: " << bibliotecas.at(i).getNombre() << std::endl;
                                    std::cout << "Ubicado en el piso " << j << " del estante " << k << " de la seccion " << l << " ." << std::endl;
                                    std::cout << "" << std::endl;
                                }
                                else
                                {
                                    std::cout << "No se encontro ningun libro con ese nombre." << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;

        case 4:
        {
            std::cout << "Ingrese el nombre del autor del libro que desea buscar: " << std::endl;
            string nombreAutorABuscar;
            cin >> nombreAutorABuscar;

            for (int i = 0; i < bibliotecas.size(); i++)
            {
                for (int j = 0; j < bibliotecas.at(i).getPisos(); j++)
                {
                    for (int k = 0; k < bibliotecas.at(i).getEstantes(); k++)
                    {
                        for (int l = 0; l < bibliotecas.at(i).getSecciones(); l++)
                        {
                            for (int n = 0; n < bibliotecas.at(i).getCubo()[j][k][l]->getLibros().size(); n++)
                            {
                                if (bibliotecas.at(i).getCubo()[j][k][l]->getLibros().at(n)->getAutor() == nombreAutorABuscar)
                                {
                                    std::cout << "" << std::endl;
                                    std::cout << "Titulo: " << bibliotecas.at(i).getCubo()[j][k][l]->getLibros().at(n)->getTitulo() << std::endl;
                                    std::cout << "Autor: " << bibliotecas.at(i).getCubo()[j][k][l]->getLibros().at(n)->getAutor() << std::endl;
                                    std::cout << "Anio: " << bibliotecas.at(i).getCubo()[j][k][l]->getLibros().at(n)->getYearPublicado() << std::endl;
                                    std::cout << "Biblioteca: " << bibliotecas.at(i).getNombre() << std::endl;
                                    std::cout << "Ubicado en el piso " << j << " del estante " << k << " de la seccion " << l << " ." << std::endl;
                                    std::cout << "" << std::endl;
                                }
                                else
                                {

                                    std::cout << "No se encontro ningun libro con ese autor." << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        break;

        case 5:
        {
            std::cout << "***BIBLIOTECAS***" << std::endl;
            std::cout << "Ingrese el indice de la biblioteca que desea explorar: " << std::endl;
            for (int i = 0; i < bibliotecas.size(); i++)
            {
                std::cout << i << ". " << bibliotecas.at(i).getNombre() << std::endl;
            }
            int indBiblioSel;
            cin >> indBiblioSel;

            int piso, estante, seccion;

            std::cout << "Ingrese el piso: " << std::endl;
            cin >> piso;
            while (piso > bibliotecas.at(indBiblioSel).getPisos())
            {
                std::cout << "Ingrese el piso: " << std::endl;
                cin >> piso;
            }

            std::cout << "Ingrese el estante: " << std::endl;
            cin >> estante;

            while (estante > bibliotecas.at(indBiblioSel).getEstantes())
            {
                std::cout << "Ingrese el estante: " << std::endl;
                cin >> estante;
            }

            std::cout << "Ingrese la seccion: " << std::endl;
            cin >> seccion;

            while (seccion > bibliotecas.at(indBiblioSel).getSecciones())
            {
                std::cout << "Ingrese la seccion: " << std::endl;
                cin >> seccion;
            }

            Libro *objetoTemporal;
            vector<Libro *> librosOrdenados;

            for (int i = 0; i < bibliotecas.at(indBiblioSel).getCubo()[piso][estante][seccion]->getLibros().size(); i++)
            {
                librosOrdenados.push_back(bibliotecas.at(indBiblioSel).getCubo()[piso][estante][seccion]->getLibros().at(i));
            }

            for (int i = 0; i < librosOrdenados.size(); i++)
            {
                for (int j = 0; j < librosOrdenados.size() - 1; j++)
                {
                    if (librosOrdenados[j]->getTitulo() > librosOrdenados[j + 1]->getTitulo())
                    {
                        objetoTemporal = librosOrdenados[j];
                        librosOrdenados[j] = librosOrdenados[j + 1];
                        librosOrdenados[j + 1] = objetoTemporal;
                    }
                }
            }

            // for (int i = 0; i < bibliotecas.at(indBiblioSel).getCubo()[piso][estante][seccion]->getLibros().size(); i++)
            // {
            //     std::cout << "" << std::endl;
            //     std::cout << "Titulo: " << bibliotecas.at(indBiblioSel).getCubo()[piso][estante][seccion]->getLibros().at(i)->getTitulo() << std::endl;
            //     std::cout << "Autor: " << bibliotecas.at(indBiblioSel).getCubo()[piso][estante][seccion]->getLibros().at(i)->getAutor() << std::endl;
            //     std::cout << "Anio de publicacion: " << bibliotecas.at(indBiblioSel).getCubo()[piso][estante][seccion]->getLibros().at(i)->getYearPublicado() << std::endl;
            //     std::cout << "" << std::endl;
            // }

            for (int i = 0; i < librosOrdenados.size(); i++)
            {
                std::cout << "" << std::endl;
                std::cout << "Titulo: " << librosOrdenados.at(i)->getTitulo() << std::endl;
                std::cout << "Autor: " << librosOrdenados.at(i)->getAutor() << std::endl;
                std::cout << "Anio de publicacion: " << librosOrdenados.at(i)->getYearPublicado() << std::endl;
                std::cout << "" << std::endl;
            }
        }
        break;

        default:
            return (0);
            break;
        }
    }
}