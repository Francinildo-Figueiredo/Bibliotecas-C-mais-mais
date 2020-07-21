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
	
	// Criando uma variável do tipo ofstream para criação e gravação do texto.
	ofstream arquivo("Exemplo1.txt"); // Arquivo criado por meio do construtor.
	char crt;
	
	cout << "Pressione CTRL_Z para sair."
			<< "\nDigite um texto: ";
	while(cin.get(crt))
		// Adicionando caractere por caractere ao arquivo, por meio do método put.
		arquivo.put(crt);
	
	return 0;
}
