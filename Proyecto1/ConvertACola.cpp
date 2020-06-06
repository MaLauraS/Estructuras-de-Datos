#include "ConvertACola.h"
#include <sstream>
#include <fstream>


ColaBigramas* ConvertACola::StringACola(std::string texto)
{
	return StreamACola(std::stringstream (texto));
}


// https://stackoverflow.com/questions/132358/how-to-read-file-content-into-istringstream
ColaBigramas* ConvertACola::ArchivoACola(std::string archivo)
{
	std::ifstream file(archivo);

	std::stringstream buffer;

	buffer << file.rdbuf();
	auto res = StreamACola(buffer);

	file.close();

	return res;
}

ColaBigramas* ConvertACola::StreamACola(std::stringstream& stream)
{
	std::string actual;
	std::string anterior;
	stream >> anterior;
	ColaBigramas* res = new ColaBigramas();

	while (stream >> actual){

		BiGrama nuevo(anterior,actual);
		res->Encolar(nuevo);
		anterior = actual; 
	}
	return res;
}
