#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <locale>

int main()
{
	setlocale( LC_ALL, "portuguese" );
	
	// Criando um vector vazio.
	vector<int>nums1;
	// O m�todo empty retorna o n�mero booleano 1 caso o vector esteja vazio e 0 se n�o estiver.
	if (nums1.empty())
		cout << "O vector nums1 est� vazio." << endl;
	/*
	O m�todo size retorna a quantidade de posi��es do vector que est�o sendo utilizadas. J� o m�todo capacity
	retorna a quantidade de posi��es do vector que est�o atualmente alocadas na mem�ria. Como o vector utiliza
	aloca��o din�mica de mem�ria, assim que a mem�ria alocada � preenchida ele automaticamente realoca o vector
	com uma reserva de mem�ria o dobro da anterior.
	*/
	cout << "\nnums1 --> tamanho: " << nums1.size() << ", capacidade: " << nums1.capacity() << endl;
	for ( unsigned int i = 0; i < 10; i++ )
	{
		nums1.push_back(i);
		cout << "nums1 --> tamanho: " << nums1.size() << ", capacidade: " << nums1.capacity() << endl;
	}
	/*
	Sa�da:
	O vector nums est� vazio.

	nums1 --> tamanho: 0, capacidade: 0
	nums1 --> tamanho: 1, capacidade: 1
	nums1 --> tamanho: 2, capacidade: 2
	nums1 --> tamanho: 3, capacidade: 4
	nums1 --> tamanho: 4, capacidade: 4
	nums1 --> tamanho: 5, capacidade: 8
	nums1 --> tamanho: 6, capacidade: 8
	nums1 --> tamanho: 7, capacidade: 8
	nums1 --> tamanho: 8, capacidade: 8
	nums1 --> tamanho: 9, capacidade: 16
	nums1 --> tamanho: 10, capacidade: 16
	*/
	
	/*
	Com o m�todo reserve conseguimos definir a quantidade da memoria que ser� reservada para o vector, se
	a quantidade reservada for menor do que a autom�tica nada o met�do n�o far� nada.
	*/
	vector<int> nums2;
	// Reservando 8 posi��es na mem�ria.
	nums2.reserve(8);
	cout << "\nnums2 --> tamanho: " << nums2.size() << ", capacidade: " << nums2.capacity() << endl;
	for ( unsigned int i = 0; i < 10; i++ )
	{
		nums2.push_back(i);
		cout << "nums2 --> tamanho: " << nums2.size() << ", capacidade: " << nums2.capacity() << endl;
	}
	/*
	Sa�da:
	nums2 --> tamanho: 0, capacidade: 8
	nums2 --> tamanho: 1, capacidade: 8
	nums2 --> tamanho: 2, capacidade: 8
	nums2 --> tamanho: 3, capacidade: 8
	nums2 --> tamanho: 4, capacidade: 8
	nums2 --> tamanho: 5, capacidade: 8
	nums2 --> tamanho: 6, capacidade: 8
	nums2 --> tamanho: 7, capacidade: 8
	nums2 --> tamanho: 8, capacidade: 8
	nums2 --> tamanho: 9, capacidade: 16
	nums2 --> tamanho: 10, capacidade: 16
	*/
	
	/*
	O m�todo shrink_to_fit(encolher para caber) libera a mem�ria reserva, mantendo apenas a capacidade
	que est� sendo utilizada no momento.
	O m�todo max_size retorna a quantidade m�xima de posi��es que podem ser alocadas pelo vector.
	*/
	cout << "Capacidade atual de nums2: " << nums2.capacity() << endl;
	// Liberando a mem�ria n�o utilizada.
	nums2.shrink_to_fit();
	cout << "Capacidade de nums2 ap�s a libera��o: " << nums2.capacity() << endl;
	cout << "Tamanho m�ximo que o vector nums2 pode ter: " << nums2.max_size();
	/*
	Sa�da:
	Capacidade atual de nums2: 16
	Capacidade de nums2 ap�s a libera��o: 10
	Tamanho m�ximo que o vector nums2 pode ter: 4611686018427387903
	*/
	return 0;
}
