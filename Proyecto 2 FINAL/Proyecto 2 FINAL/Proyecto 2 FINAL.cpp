#include <iostream>
#include "ArbolAVL.h"
#include "ArbolBB.h"
#include "ThePowerfulList.h"

#include <iostream>

int main()
{
    std::cout << "Lista(10): " << ThePowerfulList::RepetirExperimentoList(10) << "\n";
    std::cout << "Lista(1000): " << ThePowerfulList::RepetirExperimentoList(1000) << "\n";
    std::cout << "Lista(100.000): " << ThePowerfulList::RepetirExperimentoList(100000) << "\n";

    std::cout << "ArbolAVL(10): " << ArbolAVL::RepetirExperimentoAVL(10) << "\n";
    std::cout << "ArbolAVL(1000): " << ArbolAVL::RepetirExperimentoAVL(1000) << "\n";
    std::cout << "ArbolAVL(100.000): " << ArbolAVL::RepetirExperimentoAVL(100000) << "\n";

    std::cout << "ArbolABB(10): " << ArbolBB::RepetirExperimentoABB(10) << "\n";
    std::cout << "ArbolBB(1000): " << ArbolBB::RepetirExperimentoABB(1000) << "\n";
    std::cout << "ArbolBB(100.000): " << ArbolBB::RepetirExperimentoABB(100000) << "\n";

}