#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED

#include <string>

using std::to_string;
//********************************************************************************************************************************************************************
enum{
    EXPRPRE=4,/**< Expresion preescrita */
    EXPR=5/**< Expresion desde el teclado */
    };
//********************************************************************************************************************************************************************
/** \brief Imprime la expresion en posfijo y en infijo
 *
 * \param Imprime el resultado y la expresion en posfijo y en infijo
 *
 */
int ExpresionResultante();
//********************************************************************************************************************************************************************
/** \brief Pide la expresion desde el teclado y evalua si esta bien escrita
 *
 * \param Imprime la expresion en infijo y en posfijo, con el resultado de la expresion
 *
 */
double PedirExpresion();
//********************************************************************************************************************************************************************
/** \class Expresion
 * \param Clase que verifica si una explexion matematica dada esta bien escrita
 */
class Expresion{
/** \enum class
 * \param Operadores, tokens y numero que va a aceptar la expresion
 */
//********************************************************************************************************************************************************************
enum class TipoToken{
    numero,/**< Numero que se verificara antes de ver si hay un token */
    operador,/**< Oeradores que hay */
    parentesis_abierto,/**< El parentesis de la izquieda */
    parentesis_cierra,/**< El parentesis de la derecha */
    llave_abre,/**< La llaves de la izquieda */
    llave_cierra,/**< La llave de la derecha */
    corchete_abre,/**< Corchete de la izquierda */
    corchete_cierra,/**< Corchete de la derecha */
    desconocido/**< Token desconocido */
    };
//********************************************************************************************************************************************************************
public:
    /** \struct Token
     * \param Estructura que permite verificar el valor de la expresion
     */
    struct Token{
        TipoToken tipo;/**< Tokens permitidos de la clase */
        string valor;/**< Variable que verificara la expresion */
    };
//********************************************************************************************************************************************************************
    /** \brief Constructor por defaut de la clase Expresion
     *
     */
    Expresion();
//********************************************************************************************************************************************************************
    /** \brief Constructor de copia.
     * Construye una expresion a partir de una cademna
     *
     */
    Expresion(std::string expresion);
//********************************************************************************************************************************************************************
    /** \brief Captura una exprexion de tipo cadena
     *
     * \param expresion La expresion que representara una cadena
     * \return void
     *
     */
    void Capturar(std::string expresion);
//********************************************************************************************************************************************************************
    /** \brief La exprexion evaluada en insfijo
     *
     * \return string Devuelve la expresion en notacion infija
     *
     */
    string EnInfijo();
//********************************************************************************************************************************************************************
    /** \brief La exprexion evaluada en posfijo
     *
     * \return string Devuelve la expresion en nostacion posfija
     *
     */
    string EnPosfijo();
//********************************************************************************************************************************************************************
    /** \brief Evalua la expresion
     *
     * \return Dvuelve el resultado de la expresion dada
     *
     */
    double Evaluar();
//********************************************************************************************************************************************************************
private:
    /** \brief Valida que la expresion este bien balanceada con los simbolos
     *
     */
    void ValidarExpresion();
//********************************************************************************************************************************************************************
    /** \brief Analiza los token de la expresion
     *
     * \param input Ingresa el flujo de entrada
     * \param token Se analiza el token entrado
     * \return true Cuando el toquen no es desconocido
     * \return false Cuando no puede leer el ttoken
     *
     */
    bool SiguienteToken(std::istringstream& input, Token& token);
//********************************************************************************************************************************************************************
    /** \brief Determina si el token tiene precedencia
     *
     * \param input std::istringstream&
     * \param token token es el operador
     * \return true Si la precedencia del operador es mayor que el tope de la pila
     * \return false Si la precedencia no es mayor
     *
     */
    bool Precedencia(Token token);
//********************************************************************************************************************************************************************
    /** \brief Convierte la expresion a posfija
     *
     */
    void ConvertirAPosfija();
//********************************************************************************************************************************************************************
    std::string expresion;/**< Expresion que se leera */
    bool valida;/**< Se lanzara cuando la espresion es valida */
    std::string posfija;/**< La expresion converida a posfija */

};
#include "Expresion.tpp"

#endif // EXPRESION_H_INCLUDED
