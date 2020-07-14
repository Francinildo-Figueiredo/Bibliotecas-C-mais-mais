#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::for_each;

#include <numeric>
using std::accumulate;

#include <locale>

int main()
{
	setlocale( LC_ALL, "portuguese" );
	
	vector<int> nums {23, 4, 30 , 13};
	vector<string> frutas {"manga", "ma��", "banana"};
	vector<char> vazio;
	/*
	O itarador begin retorna um iterator contendo a primeira posi��o do vector, caso o vector esteja vazio ele retorna um iterator
	igual a end.
	J� o iterador end retorna um iterator com a �ltima posi��o do vector.
	*/
	
	// Usando um for_each para imprimir o vector.
	cout << "nums: ";
	for_each(nums.begin(), nums.end(), [](const int n) { cout << n << ' '; });
	cout << '\n';
	
	// Usando accumulate para realizar a soma dos valores do vector.
	cout << "Soma dos valores de nums: " << accumulate(nums.begin(), nums.end(), 0) << endl;
	
	if ( !frutas.empty() )
		cout << "Primeira fruta: " << *frutas.begin() << endl;
	// Testando se realmente begin retorna end quando utilizado em um vector vazio.
	if ( vazio.begin() == vazio.end() )
		cout << "S�o iguais!" << endl;
	/*
	Sa�da:
	23 4 30 13
	Soma dos valores de nums: 70
	Primeira fruta: manga
	S�o iguais!
	*/
	
	/*
	Para que possamos trabalhar facilmente com um vector em sua ordem inversa, temos os iteradores reversos. Podemos realizar
	as mesmas manipula��es dos iteradores comuns, por�m na ordem inversa.
	O rbegin retorna um reverse_iterator contendo a �ltima posi��o do vector. E retorna rend caso seja utilizado em um vector
	vazio.
	J� o rend retorna um reverse_iterator contendo a primeira posi��o do vector.
	*/
	
	cout << "\nAgora na ordem inversa: ";
	for_each(nums.rbegin(), nums.rend(), [](const int n) { cout << n << ' ';});
	if ( vazio.rbegin() == vazio.rend() )
		cout << "\n�ltima fruta: " << *frutas.rbegin() << endl;
	/*
	Sa�da:
	Agora na ordem inversa: 13 30 4 23
	�ltima fruta: banana
	*/
	return 0;
}
