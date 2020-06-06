#pragma once
#include<string>

class BiGrama
{
public:
	std::string Palabra1;
	std::string Palabra2;

	BiGrama();
	BiGrama(std::string palabra1,std::string palabra2);
	std::string GetPalabra1();
	std::string GetPalabra2();
};

