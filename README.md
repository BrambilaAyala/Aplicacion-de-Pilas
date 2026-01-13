# Aplicación de Pilas – Evaluador de Expresiones Aritméticas en C++

## Descripción del Proyecto

Este proyecto implementa una **aplicación en C++** que permite **validar, convertir y evaluar expresiones aritméticas** usando el concepto de **pilas (stacks)**.  

La aplicación trabaja con expresiones en **notación infija**, las convierte a **notación posfija (Polaca Inversa)** y posteriormente las evalúa utilizando una estructura de datos tipo **pila enlazada** (`Pila<>`).

El objetivo principal es demostrar el uso de pilas para el manejo de expresiones matemáticas, así como el diseño de una clase orientada a objetos para su procesamiento.

---

## Conceptos Utilizados

- Estructuras de datos (Pilas)
- Expresiones aritméticas
- Notación infija y posfija
- Programación orientada a objetos
- Plantillas (`templates`)
- Manejo de cadenas (`std::string`)
- Algoritmos de conversión y evaluación

---

## Clase `Expresion`

La clase `Expresion` es el núcleo del sistema. Representa una expresión matemática y proporciona métodos para validarla, convertirla y evaluarla.

### Atributos

| Atributo | Descripción |
|--------|-------------|
| `string infija` | Almacena la expresión original en notación infija |
| `bool valida` | Indica si la expresión es válida (`true` o `false`) |
| `string posfija` | Almacena la expresión convertida a notación posfija |

---

### Métodos Públicos

| Método | Descripción |
|------|-------------|
| `Expresion()` | Constructor por defecto. Inicializa una expresión vacía e inválida |
| `Expresion(string expr)` | Constructor que recibe una expresión, la valida y la convierte a posfija |
| `capturar()` | Permite ingresar una nueva expresión, la valida y la convierte |
| `imprimirInfija()` | Muestra la expresión en notación infija |
| `evaluar()` | Evalúa la expresión usando su forma posfija |
| Otros auxiliares | Para validación, conversión y manejo de operadores |

---

## Operaciones Aritméticas Soportadas

| Operación | Operador |
|----------|---------|
| Suma | `+` |
| Resta | `-` |
| Multiplicación | `*` |
| División | `/` |
| Potencia | `^` (puntos extra) |

🔹 Los operadores `+` y `-` se usan **solo en forma binaria**.  
Si se usan como unarios (`-a` o `+a`), se transforman a `(0 - a)` o `(0 + a)` para facilitar el procesamiento.

---

## Proceso del Sistema

1. El usuario ingresa una expresión en notación infija  
2. Se valida la expresión usando una pila  
3. Si es válida:
   - Se convierte a notación posfija  
   - Se evalúa usando otra pila  
4. Se muestra el resultado

---

## Uso de la Pila

Para todas las etapas del proceso se utiliza la plantilla:


Implementada como **estructura enlazada**, proveniente de una tarea anterior.

Se utiliza para:

- Validar paréntesis
- Controlar operadores
- Convertir infija → posfija
- Evaluar la expresión posfija

---

## Compilación

Ejemplo usando `g++`:

```bash
g++ main.cpp Expresion.cpp Pila.cpp -o app
./app


