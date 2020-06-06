#pragma once
#include "ColaBigramas.h"

class ConvertACola
{
public:
	ColaBigramas* StringACola(std::string texto);
	ColaBigramas* ArchivoACola(std::string archivo);
	ColaBigramas* StreamACola(std::stringstream& stream);
};

