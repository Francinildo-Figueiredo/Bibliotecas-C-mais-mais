#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ofstream;

#include <locale>

int main()
{
	setlocale( LC_ALL, "portuguese" );
	
	// Criando um arquivo txt para receber o texto.
	ofstream arquivo("Exemplo1.txt");
	char crt;
	
	cout << "Pressione CTRL_Z para sair."
			<< "\nDigite um texto: ";
	while(cin.get(crt))
		// Adicionando caractere por caractere ao arquivo, por meio do método put.
		arquivo.put(crt);
	
	return 0;
}
