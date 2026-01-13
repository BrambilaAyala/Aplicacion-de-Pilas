#include "PilaAplicacion.h"
#include "Expresion.h"

int main()
{
    int opcion;


    do{
        do{
            system("cls");
            cout << "Programa que realiza una de las siguientes acciones\n" << endl;
            cout << "Programa que hace varias operaciones que involucra una pila y una expresion matem\xA0tica\n" << endl;

            cout << SALIR << ") Salir del programa" << endl;
            cout << DOUBLE << ") Operaci\xA2n de numeros de tipo double" << endl;
            cout << ENTERO << ") Operaci\xA2n de numeros de tipo int" << endl;
            cout << USUARIO << ") Teclea los volores para la pila" << endl;
            cout << EXPRPRE << ") Opci\xA2n de la clase expresi\xA2n" << endl;
            cout << EXPR << ") Escribe una expresi\xA2n" << endl;

            opcion = CapturaEntero( "\nElija una opci\242n: ");
            if(opcion < SALIR || opcion > EXPR){
                cout << "\nError: Opci\242n no v\240lida" << endl;
                system("pause");
            }
            system("cls");
        }while(opcion < SALIR || opcion > EXPR);

        system("cls");
        switch(opcion){
        case DOUBLE:
            {
                if(opcion==1)
                {
                    Pila<double> p;
                    cout << "Apilar componentes: " << endl;
                    p.Apilar(5.8);
                    p.Apilar(6.0);
                    p.Apilar(4.3);
                    p.Apilar(9.1);
                    p.Imprimir();

                    cout << "Desapilar componentes: " << endl;
                    p.Imprimir();
                    p.Desapilar();
                    cout << endl << endl;
                    cout << "Desapilar componentes: " << endl;
                    p.Imprimir();
                    p.Desapilar();
                    cout << "Vaciar componentes: " << endl;
                    p.Imprimir();
                    p.Vaciar();
                    cout << "Vaciar componentes: " << endl;
                    p.Imprimir();
                    p.Vaciar();
                }
            }
            break;
        case ENTERO:
            {
                if(opcion==2)
                {
                    Pila<int> p;
                    cout << "Apilar componentes: " << endl;
                    p.Apilar(60);
                    p.Apilar(13);
                    p.Apilar(1);
                    p.Apilar(91);
                    p.Imprimir();

                    cout << "Desapilar componentes: " << endl;
                    p.Imprimir();
                    p.Desapilar();
                    cout << endl << endl;
                    cout << "Desapilar componentes: " << endl;
                    p.Imprimir();
                    p.Desapilar();
                    cout << "Vaciar componentes: " << endl;
                    p.Imprimir();
                    p.Vaciar();
                    cout << "Vaciar componentes: " << endl;
                    p.Imprimir();
                    p.Vaciar();
                }
            }
            break;
        case USUARIO:
            {
                if(opcion==3)
                {
                    Pila<int> p1;
                    int n,m,k;
                    cout << "Apilar componentes: " << endl;

                    cout<<"Teclea el primer componente: ";
                    cin>>n;
                    cout<<"Teclea el segundo componente: ";
                    cin>>m;
                    cout<<"Teclea el tercer componente: ";
                    cin>>k;
                    p1.Apilar(n);
                    p1.Apilar(m);
                    p1.Apilar(k);
                    p1.Imprimir();
                    cout << "Desapilar componentes: " << endl;
                    p1.Imprimir();
                    p1.Desapilar();
                    cout << endl << endl;
                    cout << "Desapilar componentes: " << endl;
                    p1.Imprimir();
                    p1.Desapilar();
                    cout << "Vaciar componentes: " << endl;
                    p1.Imprimir();
                    p1.Vaciar();
                    cout << "Vaciar componentes: " << endl;
                    p1.Imprimir();
                    p1.Vaciar();
                }
            }
            break;
            case EXPRPRE:
                ExpresionResultante();
                break;
            case EXPR:
                PedirExpresion();
                break;
        }
        if(opcion != SALIR) system("pause");
    }while(opcion != SALIR);
    system("pause");

    return 0;
}
