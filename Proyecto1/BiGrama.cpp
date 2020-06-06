#include "BiGrama.h"

BiGrama::BiGrama()
{
}

BiGrama::BiGrama(std::string palabra1, std::string palabra2)
{
	Palabra1 = palabra1;
	Palabra2 = palabra2;
}

std::string BiGrama::GetPalabra1()
{
	return Palabra1;
}

std::string BiGrama::GetPalabra2()
{
	return Palabra2;
}


