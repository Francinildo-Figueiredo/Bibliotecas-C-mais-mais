#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <stdexcept>
using std::out_of_range; // Excess�o que indica a busca de uma posi��o fora do tamanho do vector.

#include <string>
using std::string;

#include <locale>

int main()
{
	setlocale( LC_ALL, "portuguese" );
	
	vector<string> frase {"Manipular", "vector", "�", "muito", "f�cil."};
	// Impriminto o vector por meio de iterators.
	cout << "Sa�da 1: ";
	for (vector<string>::const_iterator it = frase.begin(); it != frase.end(); it++)
		cout << *it << ' ';
	
	// Utilizando o operedor[] para acessar o vector.
	cout << "\nSa�da 2: " << frase[1] << ' ' << frase[2] << ' ' << frase[4] << endl;
	
	// utilizando  o front, ele acessa o primeiro elemento do vector.
	cout << "Sa�da 3: " << frase.front() << endl;
	
	// utilizando  o back, ele acessa o �ltimo elemento do vector.
	cout << "Sa�da 4: " << frase.back() << endl;
	
	/*
	Sa�da 1: Manipular vector � muito f�cil.
	Sa�da 2: vector � f�cil.
	Sa�da 3: Manipular
	Sa�da 4: f�cil.
	*/
	
	/*
	Utilizando o elemento de acesso at: ele acessa os elementos do vector da mesma maneira que o operador[], s� que antes
	de acessar o valor ele derifica se aquela posi��o do vector existe, se n�o existir ele lan�a uma excess�o. Quando n�o
	fazemos esse tipo de tratamento e tentamos acessar uma posi��o que n�o existe o programa encerra sua execu��o.
	*/
	
	cout << "Sa�da 6: " << frase.at(3) << ' ' << frase.at(4) << endl;
	
	// Agora utilizaremos um tratamento de excess�es para lan�ar-mos a excess�o do at.
	try{
		// Tentando acessar uma posi��o do vector que n�o existe.
		cout << "Sa�da 7: " << frase.at(8) << endl;
	}catch( out_of_range const& exc ){
		// Lan�ando a excess�o "fora do tamanho", que explica o ocorrido sem encerrar a execu��o.
		cout << exc.what() << endl;
	}
	
	/*
	Sa�da 6: muito f�cil.
	vector::_M_range_check: __n (which is 8) >= this->size() (which is 5)
	*/
	
	// Elemento de acesso data: ele retorna um ponteiro que aponta para o primeiro elemento do vector.
	
	// Passando o endere�o da primeira posi��o do vector para um ponteiro auxiliar.
	const string *p = frase.data();
	cout << "Sa�da 8: ";
	for ( unsigned int i = 0; i < frase.size(); i++ )
		cout << p[i] << ' ';
	/*
	Sa�da 8: Manipular vector � muito f�cil.
	*/
	
	return 0;
}
