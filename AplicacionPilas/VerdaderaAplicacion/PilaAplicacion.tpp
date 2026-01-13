#include "PilaAplicacion.h"
#include "Expresion.h"
//*********************************************************************************************************
long double CapturarRealDoble(const char solicitud[])
{
    long double numero;
    do{
        cout << solicitud;
        cin >> numero;

        if(cin.bad()){
            throw "P\202rdida de datos en el flujo";
        }

        if(cin.fail()){
            cout << "Error: El dato ingreado no es un n\243mero, porfavor vuela a teclear el valor: ";
            cin.clear();
            cin.ignore(numeric_limits<int>::max(),'\n');
            continue;
        }

        break;
    }while(true);;
    return numero;
}
//***********************************************************************************************************************
int CapturaEntero(const char solicitud[])
{
    int numero;
    long double aux;

    do {
        aux = CapturarRealDoble(solicitud);
        numero = (int) aux;
        if(numero != aux) {
            cout << "  Error: Debe ser un n\xA3mero entero" << endl;
        } else if(numero < 0) {
            cout << "Error: Debe ser un n\xA3mero entero positivo" << endl;
            cout << "Vuelva a teclear el valor: ";

        }
    } while(numero != aux || numero < 0);

    return numero;
}
//**********************************************************************************************************************************************
template <typename T>
Pila<T>::Pila():tope(NULL), tamanio(0) {}
//**********************************************************************************************************************************************
template <typename T>
Pila<T>::Pila(const Pila<T>& otra) : tope(NULL), tamanio(0)
{
    Elemento* aux = otra.tope;
    while(aux != NULL)
    {
        this->Apilar(aux->valor);
        aux = aux->Siguiente;
    }
}
//**********************************************************************************************************************************************
template<typename T>
Pila<T>::~Pila()
{
    this->Vaciar();
}
//**********************************************************************************************************************************************
template <typename T>
void Pila<T>::Apilar(const T & valor)
{

    Elemento* nuevo = new Elemento(valor, tope);
    tope = nuevo;
    ++tamanio;
}
//**********************************************************************************************************************************************
template <typename T>
T Pila<T>::Desapilar()
{
    if(EstaVacia()) throw PilaVacia();

    Elemento* eliminar = tope;
    tope = tope->Siguiente;
    T valor = eliminar->valor;
    delete eliminar;
    --tamanio;
    return valor;
}
//**********************************************************************************************************************************************
template <typename T>
const T & Pila<T>::ObtenerTope() const
{
   if(EstaVacia()) throw PilaVacia();

   return tope->valor;
}
//**********************************************************************************************************************************************
template <typename T>
bool Pila<T>::EstaVacia() const
{
    return tope == NULL;
}
//**********************************************************************************************************************************************
template <typename T>
unsigned Pila<T>::ObtenerTam() const
{
    return tamanio;
}
//**********************************************************************************************************************************************
template <typename T>
void Pila<T>::Vaciar()
{
    while(tope !=NULL)
    {
        Elemento* eliminar = tope;
        tope = tope->Siguiente;
        delete eliminar;
    }
}
//**********************************************************************************************************************************************
template <typename T>
void Pila<T>::Imprimir() const
{
    cout << endl;
    if(!EstaVacia()) cout << ObtenerTope() << " <- Tope " << endl;
    Elemento* aux = tope;
    while(aux != NULL)
    {
        cout << aux->valor << endl;
        aux = aux->Siguiente;
    }
    cout << "__________" << endl;
}
//**********************************************************************************************************************************************
template <typename T>
Pila<T>& Pila<T>::operator=(const Pila<T>& p)
{
    if(this == &p) return *this;

    Vaciar();
    Pila pilaAux;
    Elemento *aux = p.tope;
    while(aux != NULL)
    {
        pilaAux.Apilar(aux->valor);
        aux = aux->Siguiente;
    }
    while(!pilaAux.EstaVacia())
    {
        Apilar(pilaAux.ObtenerTope());
        pilaAux.Desapilar();
    }
    return *this;
}
//**********************************************************************************************************************************************
//**********************************************************************************************************************************************
// Funciones de clases anidadas en Pila
//**********************************************************************************************************************************************
//**********************************************************************************************************************************************
template <typename T>
const char * Pila<T>::PilaLlena::what() const throw()
{
    return "La pila est\240 llena";
}
//**********************************************************************************************************************************************
template <typename T>
const char * Pila<T>::PilaVacia::what() const throw()
{
    return "La pila est\240 vac\241a";
}
//**********************************************************************************************************************************************
//**********************************************************************************************************************************************
// Funciones amigas
//**********************************************************************************************************************************************
//**********************************************************************************************************************************************
template <typename Tipo>
std::ostream & operator << (std::ostream & salida, const Pila<Tipo> & p)
{
    salida << endl;
    if(!p.EstaVacia()) salida << p.ObtenerTope() << " <- Tope" << endl;
    typename Pila<Tipo>::Elemento* aux = p.tope;
    while(aux != NULL)
    {
        salida << aux->valor << endl;
        aux = aux->Siguiente;
    }
    return salida << "__________" << endl;
}
