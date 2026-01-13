#ifndef PILAAPLICACION_H_INCLUDED
#define PILAAPLICACION_H_INCLUDED

#include <iostream>
#include <exception>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <stdexcept>
enum{
    SALIR,/**< Opcion de salir del programa*/
    DOUBLE,/**< Opcion de impresion de una pila de tipo double */
    ENTERO,/**< Opcion de impresion de una pila de tipo int */
    USUARIO/**< Opcion para que el usuario teclee los valores de la pila */
};

using std::cout;
using std::endl;
using std::cin;
using std::numeric_limits;
using std::max;
using std::runtime_error;
using std::string;
using std::exception;
using std::cerr;

//***************************************************************************************************************************************************************
/** \brief Solicita a usuario un numero entero
 * \param solicitud Una cadena de caracteres que pedira ingresar un numero entero
 * \return Entero ingresado por el usario
 */
int CapturaEntero(const char solicitud[]);
//***************************************************************************************************************************************************************
/** \brief Solicita al usario un numero Real
 * \param solicitud Solicitud de una cadena de caracteres que pedira ingresar un numero real
 * \return El numero ingreado por el usario
 */
long double CapturarRealDoble(const char solicitud[]);
//********************************************************************************************************************************************************************
/** \class Pila
 * Estructura de datos tipo LIFO: @uacute;ltimo en entrar, primero en salir. Puede contener elementos de tipo int.
 * Tiene un tama@ntilde;o m@aacute;ximo definido por TAM.
 * \tparam T Tipo de dato del contenido de la pila
 */
template <typename T>
class Pila{

    /** \brief Operador auxiliar para imprimir la pila (solo para pruebas)
     * Imprime los elementos de la pila desde el fondo hasta el tope
     *
     * \tparam Tipo Tipo de dato del contenido de la pila
     * \param salida Flujo de datos donde se imprimir@aacute; la pila
     * \param p Pila a imprimir
     * \return El mismo flujo recibido. Permite la aplicaci@oacute;n en cascada del operador
     *
     */
     template <typename Tipo>
    friend std::ostream & operator << (std::ostream & salida, const Pila<Tipo> & p);
//********************************************************************************************************************************************************************
public:
    /** \class PilaLlena
     * Escepci@oacute;n lanzada cuando se intente agregar elementos en una pila llena
     */
    class PilaLlena : public std::exception{
    public:
        virtual const char * what() const throw();
    };
//********************************************************************************************************************************************************************
/** \class PilaVacia
     * Escepci@oacute;n lanzada cuando se intente acceder a los elementos de una pila vac@iacute;a
     */
    class PilaVacia : public std::exception{
    public:
        virtual const char * what() const throw();
    };
//********************************************************************************************************************************************************************
    /** \brief Constructor por default. Construye una pila vac@iacute;a
     */
    Pila();
//********************************************************************************************************************************************************************
    /** \brief Constructor de copias, Crea una copia de la pila exacta de otra pila
     *
     * @param otra La pila que desea copiar
     *
     */
    Pila(const Pila<T>& otra);
//********************************************************************************************************************************************************************
    /** \brief Destructor de lapila. Libera memoria que esta reservada de la pila
     *
     */
    ~Pila();
//********************************************************************************************************************************************************************
    /** \brief Operador de asignacion de lacalse
     *
     * \param p La pila que se desea asignar
     * \return Pila<T>& Lapila asignada
     *
     */
    Pila<T>& operator=(const Pila<T>& p);
//********************************************************************************************************************************************************************
    /** \brief Permite agregar un nuevo elemento en la pila
     *
     * \param valor Elemento a agregar
     *
     */
    void Apilar(const T & valor);
//********************************************************************************************************************************************************************
    /** \brief Permite eliminar un elemento de la pila
     *
     * \exception Pila::PilaVacia. Cuando la pila est@aacute; vac@iacute;a
     */
    T Desapilar();
//********************************************************************************************************************************************************************
    /** \brief Obtiene el elemento que se encuentra en el tope de la pila
     *
     * \return El elemento del tope de lapila
     *
     * \exception Pila::PilaVacia. Cuando la pila est@aacute; vac@iacute;a
     */
    const T & ObtenerTope() const;
//********************************************************************************************************************************************************************
    /** \brief Da a conocer si la pila est@aacute; vac@iacute;a
     *
     * \return true si la pila est@aacute; vac@iacute;a
     * \return false si la pila contine un elemento
     */
    bool EstaVacia() const;
//********************************************************************************************************************************************************************
    /** \brief Obtiene el n@uacute;mero de elementos en la pila
     *
     * \return N@uacute;mero de elementos que hay en la pila
     */
    unsigned ObtenerTam() const;
//********************************************************************************************************************************************************************
    /** \brief Vac@iacute;a la pila, es decir, la deja sin elementos
     */
    void Vaciar();
//********************************************************************************************************************************************************************
    /** \brief Imprime los elementos que se encuantran en la pila. Desde el fondo hasta el tope (solo para pruebas)
     */
    void Imprimir() const;
//********************************************************************************************************************************************************************
private:
    /** \brief Estructura que representa un elemento de la pila
     */
    struct Elemento
    {
       Elemento(const T& v, Elemento* sig = NULL) : valor(v), Siguiente(sig) {}/**< Elemento que contienen valor y siguiente */
       T valor;/**< Valor del elementos */
       Elemento* Siguiente;/**< Puntero que apunta  al siguiente elemento de la pila */
    };
    Elemento* tope;/**< Puntero que apunta al elemento superior de la pila */
    unsigned tamanio;/**< Almacena el numero de elementos en la pila */
};

#include "PilaAplicacion.tpp"
//#include "Expresion.tpp"
#endif // PILAAPLICACION_H_INCLUDED
