#include "ArbolAVL.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <functional>
#include <chrono>


int ArbolAVL::Altura(NodoAVL* nodo)
{
    int alt;

    if (nodo == nullptr) {
        alt = 0;
    }

    else {
        alt = nodo->altura;
    }

    return alt;

}


int ArbolAVL::FactorEquilibrio(NodoAVL* nodo)
{
    int altIzq = Altura(nodo->izquierda);
    int altDer = Altura(nodo->derecha);
    int diferencia = altIzq - altDer;

    return diferencia;
}


void ArbolAVL::Imprimir(NodoAVL* nodo)
{
    if (nodo == nullptr) {
        return;
    }

    Imprimir(nodo->izquierda);
    std::cout << nodo->Valor << " ";
    Imprimir(nodo->derecha);

}


void ArbolAVL::Buscar(NodoAVL* nodo, int n)
{
    if (n == nodo->Valor) {
        return;
    }

    else if (n < nodo->Valor) {

        return Buscar(nodo->izquierda, n);
    }

    else {

        return Buscar(nodo->derecha, n);

    }

}




NodoAVL* ArbolAVL::Insertar(NodoAVL* arbol, int n)
{
    if (arbol == nullptr) {

        return new NodoAVL(n);
    }

    else {

        if (arbol->Valor > n) {

            arbol->izquierda = Insertar(arbol->izquierda, n);
            arbol->altura = arbol->izquierda->altura + 1;
        }

        else {

            arbol->derecha = Insertar(arbol->derecha, n);
            arbol->altura = arbol->derecha->altura + 1;
        }

        int escenario = DeterminarEscenario(arbol);

        switch (escenario)
        {
        case Izquierda:
            return RotarIzquierda(arbol);
            break;

        case Derecha:
            return RotarDerecha(arbol);
            break;

        case IzquierdaDerecha:
            return RotarIzquierdaDerecha(arbol);
            break;

        case DerechaIzquierda:
            return RotarDerechaIzquierda(arbol);
            break;

        default:
            return arbol;
            break;
        }

    }

}



double ArbolAVL::ExperimentoAVL(int n)
{

    std::vector<int> Num;


    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 1000000);

    auto generador = std::bind(distribution, generator);

    while (n--) {

        Num.push_back(generador());

    }

    NodoAVL* arbol = nullptr;

    for (auto i : Num) {

        arbol = Insertar(arbol, i);

    }

    auto start = std::chrono::high_resolution_clock::now();

    for (auto i : Num) {

        Buscar(arbol, i);

    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    return ((double)duration.count()) / 1000000.0;

}


int ArbolAVL::DeterminarEscenario(NodoAVL* nodo)
{
    if (FactorEquilibrio(nodo) > 1) {

        if (FactorEquilibrio(nodo->izquierda) > 0) {
            return Izquierda;
        }

        else {
            return IzquierdaDerecha;
        }
    }

    else if (FactorEquilibrio(nodo) < -1) {

        if (FactorEquilibrio(nodo->derecha) < 0) {
            return Derecha;
        }

        else {
            return DerechaIzquierda;
        }

    }

    return Nada;
}


NodoAVL* ArbolAVL::RotarIzquierda(NodoAVL* nodo)
{
    NodoAVL* temp = nodo->derecha;

    nodo->derecha = temp->izquierda;

    temp->izquierda = nodo;

    return temp;

}


NodoAVL* ArbolAVL::RotarDerecha(NodoAVL* nodo)
{
    NodoAVL* temp = nodo->izquierda;

    nodo->izquierda = temp->derecha;

    temp->derecha = nodo;

    return temp;
}


NodoAVL* ArbolAVL::RotarIzquierdaDerecha(NodoAVL* nodo)
{
    NodoAVL* temp = nodo->izquierda;

    nodo->izquierda = RotarDerecha(temp);

    return RotarIzquierda(nodo);

}


NodoAVL* ArbolAVL::RotarDerechaIzquierda(NodoAVL* nodo)
{
    NodoAVL* temp = nodo->derecha;

    nodo->derecha = RotarIzquierda(temp);

    return RotarDerecha(nodo);

}


double ArbolAVL::RepetirExperimentoAVL(int n) {
    double tiempo = 0;
    for (int i = 0; i < 30; i++)
    {
        tiempo += ExperimentoAVL(n);
    }

    return (tiempo / 30.0);
}
