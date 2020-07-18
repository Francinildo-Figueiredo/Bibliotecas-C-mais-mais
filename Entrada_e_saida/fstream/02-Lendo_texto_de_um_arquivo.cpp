#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ifstream;

#include <locale>

int main()
{
	setlocale( LC_ALL, "portuguese" );
	
	// Criando uma variável ifstream para leitura do arquivo.
	ifstream arquivo("Exemplo1.txt");
	char crt;
	
	// Enquanto tiver texto continue imprimindo.
	while(arquivo.get(crt))
		cout << crt;
	
	return 0;
}
