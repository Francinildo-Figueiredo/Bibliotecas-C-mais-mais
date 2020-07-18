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
	
	ifstream arquivo("Exemplo1.txt");
	char crt;
	
	while(arquivo.get(crt))
		cout << crt;
	
	return 0;
}
