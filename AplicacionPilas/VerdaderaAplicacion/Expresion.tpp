#include "PilaAplicacion.h"
#include "Expresion.h"

//*********************************************************************************************************************************************************
Expresion::Expresion()
{
    expresion = "";
    valida = false;
    posfija = "";
}
//*****************************************************************************************************************************************************
Expresion::Expresion(std::string expresion)
{
    this->expresion = expresion;
    ValidarExpresion();
    if(valida)
    {
        ConvertirAPosfija();
    }
}
//*****************************************************************************************************************************************************
void Expresion::Capturar(std::string expresion)
{
    this->expresion = expresion;
    ValidarExpresion();
    if(valida)
    {
        ConvertirAPosfija();
    }
}
//*****************************************************************************************************************************************************
std::string Expresion::EnInfijo()
{
    return expresion;
}
//*****************************************************************************************************************************************************
std::string Expresion::EnPosfijo()
{
    return posfija;
}
//*****************************************************************************************************************************************************
double Expresion::Evaluar()
{
    Pila<double> pila_numeros;

    std::istringstream input(posfija);

    Token token;

    while(SiguienteToken(input, token))
    {
        switch(token.tipo)
        {
            case TipoToken::numero:
                pila_numeros.Apilar(stod(token.valor));
                break;
            case TipoToken::operador:
            {
                double b = pila_numeros.Desapilar();
                double a = pila_numeros.Desapilar();
                double resultado;
                switch(token.valor[0])
                {
                    case '+':
                        resultado = a + b;
                        pila_numeros.Apilar(resultado);
                        break;
                    case '-':
                        resultado = a - b;
                        pila_numeros.Apilar(resultado);
                        break;
                    case '*':
                        resultado = a * b;
                        pila_numeros.Apilar(resultado);
                        break;
                    case '/':
                        if(b == 0)
                        {
                            throw runtime_error("Error: Se esta dividiendo entre cero");
                        }
                        resultado = a / b;
                        pila_numeros.Apilar(resultado);
                        break;
                    case '^':
                        resultado = pow(a, b);
                        pila_numeros.Apilar(resultado);
                        break;
                }
                break;
            }
            default:
                throw std::runtime_error("Error: La expresi\xA2n est\xA0 mal escrita");
        }
    }
    if(pila_numeros.ObtenerTam() == 1)
    {
        return pila_numeros.Desapilar();
    }
    else
    {
        throw std::runtime_error("Error: La expresi\xA2n est\xA0 mal escrita");
    }
    return 0;
}
//*********************************************************************************************************************************************************
void Expresion::ValidarExpresion()
{
    Pila<char> pila_parentesis;
    Pila<char> pila_corchetes;
    Pila<char> pila_llaves;

    for(char c : expresion)
    {
        if(c == '(')
        {
            pila_parentesis.Apilar(c);
        }
        else if(c == ')')
        {
            if(pila_parentesis.EstaVacia())
            {
                valida = false;
                return;
            }
            pila_parentesis.Desapilar();
        }
        else if(c == '[')
        {
            pila_corchetes.Apilar(c);
        }
        else if(c == ']')
        {
            if(pila_corchetes.EstaVacia())
            {
                valida = false;
                return;
            }
            pila_corchetes.Desapilar();
        }
        else if(c == '{')
        {
            pila_llaves.Apilar(c);
        }
        else if(c == '}')
        {
            if(pila_llaves.EstaVacia())
            {
                valida = false;
                return;
            }
            pila_llaves.Desapilar();
        }
    }
    valida = pila_parentesis.EstaVacia() && pila_corchetes.EstaVacia() && pila_llaves.EstaVacia();
}
//*********************************************************************************************************************************************************
bool Expresion::SiguienteToken(std::istringstream& input, Token& token)
{
    char c;
    while(input.get(c))
    {
        if(isspace(c))
        {
            continue;
        }
        if(isdigit(c) || c == '.')
        {
            token.tipo = TipoToken::numero;
            token.valor = c;
            while(input.get(c))
            {
                if(isdigit(c) || c == '.')
                {
                    token.valor += c;
                }
                else
                {
                    input.unget();
                    break;
                }
            }
            return true;
        }
        switch(c)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                token.tipo = TipoToken::operador;
                token.valor = c;
                return true;
            case '(':
                token.tipo = TipoToken::parentesis_abierto;
                token.valor = c;
                return true;
            case ')':
                token.tipo = TipoToken::parentesis_cierra;
                token.valor = c;
                return true;
            case '{':
                token.tipo = TipoToken::llave_abre;
                token.valor = c;
                return true;
            case '}':
                token.tipo = TipoToken::llave_cierra;
                token.valor = c;
                return true;
            case '[':
                token.tipo = TipoToken::corchete_abre;
                token.valor = c;
                return true;
            case ']':
                token.tipo = TipoToken::corchete_cierra;
                token.valor = c;
                return true;
            default:
                token.tipo = TipoToken::desconocido;
                token.valor = c;
                return true;
        }
    }
    return false;
}
//*********************************************************************************************************************************************************
bool Expresion::Precedencia(Token token)
{
    switch(token.tipo)
    {
        case TipoToken::numero:
            return true;
        case TipoToken::operador:
            switch(token.valor[0])
            {
                case '+':
                case '-':
                    return false;
                case '*':
                case '/':
                    return true;
                case '^':
                    return true;
                default:
                    throw std::runtime_error("Se desconoce este operador: " + token.valor);
            }
            break;
        case TipoToken::parentesis_abierto:
            return false;
        case TipoToken::parentesis_cierra:
            throw std::runtime_error("Par\x82ntesis desbalanceados");
        case TipoToken::llave_abre:
            return false;
        case TipoToken::llave_cierra:
            throw std::runtime_error("Llaves desvanlaciadas");
        case TipoToken::corchete_abre:
            return false;
        case TipoToken::corchete_cierra:
            throw std::runtime_error("Corchetes desvanlaceados");
        default:
            throw std::runtime_error("Token desconocido: " + token.valor);
    }
}
//*********************************************************************************************************************************************************
void Expresion::ConvertirAPosfija()
{
    posfija = "";

    Pila<Token> pila_tokens;

    std::istringstream input(expresion);

    Token token;
    while(SiguienteToken(input, token))
    {
        switch(token.tipo)
        {
            case TipoToken::numero:
                posfija += token.valor + " ";
                break;
            case TipoToken::operador:
            {
                while (!pila_tokens.EstaVacia() && pila_tokens.ObtenerTope().tipo == TipoToken::operador &&
                Precedencia(token) <= Precedencia(pila_tokens.ObtenerTope()))
                {
                    posfija += pila_tokens.Desapilar().valor + " ";
                }
                pila_tokens.Apilar(token);
                break;
            }
            case TipoToken::parentesis_abierto:
                pila_tokens.Apilar(token);
                break;
            case TipoToken::parentesis_cierra:
            {
                while (!pila_tokens.EstaVacia() && pila_tokens.ObtenerTope().tipo != TipoToken::parentesis_abierto)
                {
                    posfija += pila_tokens.Desapilar().valor + " ";
                }
                if (pila_tokens.EstaVacia())
                {
                    throw std::runtime_error("Los par\x82ntesis estan desbalanceados");
                }
                pila_tokens.Desapilar();
                break;
            }
            case TipoToken::llave_abre:
                pila_tokens.Apilar(token);
                break;
            case TipoToken::llave_cierra:
                {
                    while (!pila_tokens.EstaVacia() && pila_tokens.ObtenerTope().tipo != TipoToken::llave_abre)
                    {
                        posfija += pila_tokens.Desapilar().valor + " ";
                    }
                    if (pila_tokens.EstaVacia())
                    {
                        throw std::runtime_error("Las llves estan desbalanceadas");
                    }
                    pila_tokens.Desapilar();
                    break;
                }
            case TipoToken::corchete_abre:
                pila_tokens.Apilar(token);
                break;
            case TipoToken::corchete_cierra:
                {
                    while (!pila_tokens.EstaVacia() && pila_tokens.ObtenerTope().tipo != TipoToken::corchete_abre)
                    {
                        posfija += pila_tokens.Desapilar().valor + " ";
                    }
                    if (pila_tokens.EstaVacia())
                    {
                        throw std::runtime_error("Los corchetes est\xA0n desbalanceados");
                    }
                    pila_tokens.Desapilar();
                    break;

                }
            default:
                throw std::runtime_error("Token desconocido: " + token.valor);
        }
    }
    while(!pila_tokens.EstaVacia())
    {
        if(pila_tokens.ObtenerTope().tipo == TipoToken::parentesis_abierto)
        {
            throw std::runtime_error("Los par\x82ntesis est\xA0n desbalanceados");
        }

        if(pila_tokens.ObtenerTope().tipo == TipoToken::llave_abre)
        {
            throw std::runtime_error("Las llaves est\xA0n desbalanceadas");
        }

        if(pila_tokens.ObtenerTope().tipo == TipoToken::corchete_abre)
        {
            throw std::runtime_error("Los corchetes est\xA0n desbalanceados");
        }
        posfija += pila_tokens.Desapilar().valor + " ";
    }
}
//*******************************************************************************************************************************************************************
int ExpresionResultante()
{
  std::string expresion = "3 + 4 * (2 - 1) / 5";
  try{
      Expresion e(expresion);
      std::string infija = e.EnInfijo();
      std::string posfija = e.EnPosfijo();
      cout << "Expresi\xA2n en notaci\xA2n infija: " << infija << endl;
      cout << "Expresi\xA2n en notaci\xA2n posfija: " << posfija << endl;
      cout << "El resultado es: " << e.Evaluar() << endl;
    }catch(std::exception& e){
        cout << e.what() << std::endl;
        return 0;
    }
    return 0;
}

//*******************************************************************************************************************************************************************
double PedirExpresion()
{
    std::string expresion;
    cout << "Teclea la expresi\xA2n: ";
    std::cin.ignore();
    getline(std::cin, expresion);//Lee la entrada completa del usuario como una línea

    try {
        Expresion e(expresion);
        std::string infija = e.EnInfijo();
        std::string posfija = e.EnPosfijo();
        cout << "La expresi\xA2n en notaci\xA2n infija es: " << infija << endl;
        cout << "La expresi\xA2n en notaci\xA2n posfija es: " << posfija << endl;
        double resultado = e.Evaluar();
        if (std::isnan(resultado)) {
            cout << "Error: la expresi\xA2n no se puede evaluar" << endl;
            return 0.0;
        } else {
            cout << "El resultado es: " << resultado << endl;
            return resultado;
        }
    }catch (std::exception& e) {
        cout << "Error: " << e.what() << endl;
        return 0.0;
    }
}
