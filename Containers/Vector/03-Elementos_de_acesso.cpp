#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <stdexcept>
using std::out_of_range; // Excessão que indica a busca de uma posição fora do tamanho do vector.

#include <string>
using std::string;

#include <locale>

int main()
{
	setlocale( LC_ALL, "portuguese" );
	
	vector<string> frase {"Manipular", "vector", "é", "muito", "fácil."};
	// Impriminto o vector por meio de iterators.
	cout << "Saída 1: ";
	for (vector<string>::const_iterator it = frase.begin(); it != frase.end(); it++)
		cout << *it << ' ';
	
	// Utilizando o operedor[] para acessar o vector.
	cout << "\nSaída 2: " << frase[1] << ' ' << frase[2] << ' ' << frase[4] << endl;
	
	// utilizando  o front, ele acessa o primeiro elemento do vector.
	cout << "Saída 3: " << frase.front() << endl;
	
	// utilizando  o back, ele acessa o último elemento do vector.
	cout << "Saída 4: " << frase.back() << endl;
	
	/*
	Saída 1: Manipular vector é muito fácil.
	Saída 2: vector é fácil.
	Saída 3: Manipular
	Saída 4: fácil.
	*/
	
	/*
	Utilizando o elemento de acesso at: ele acessa os elementos do vector da mesma maneira que o operador[], só que antes
	de acessar o valor ele derifica se aquela posição do vector existe, se não existir ele lança uma excessão. Quando não
	fazemos esse tipo de tratamento e tentamos acessar uma posição que não existe o programa encerra sua execução.
	*/
	
	cout << "Saída 6: " << frase.at(3) << ' ' << frase.at(4) << endl;
	
	// Agora utilizaremos um tratamento de excessões para lançar-mos a excessão do at.
	try{
		// Tentando acessar uma posição do vector que não existe.
		cout << "Saída 7: " << frase.at(8) << endl;
	}catch( out_of_range const& exc ){
		// Lançando a excessão "fora do tamanho", que explica o ocorrido sem encerrar a execução.
		cout << exc.what() << endl;
	}
	
	/*
	Saída 6: muito fácil.
	vector::_M_range_check: __n (which is 8) >= this->size() (which is 5)
	*/
	
	// Elemento de acesso data: ele retorna um ponteiro que aponta para o primeiro elemento do vector.
	
	// Passando o endereço da primeira posição do vector para um ponteiro auxiliar.
	const string *p = frase.data();
	cout << "Saída 8: ";
	for ( unsigned int i = 0; i < frase.size(); i++ )
		cout << p[i] << ' ';
	/*
	Saída 8: Manipular vector é muito fácil.
	*/
	
	return 0;
}
