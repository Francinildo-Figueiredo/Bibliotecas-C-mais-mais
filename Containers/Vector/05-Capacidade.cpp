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
	// O método empty retorna o número booleano 1 caso o vector esteja vazio e 0 se não estiver.
	if (nums1.empty())
		cout << "O vector nums1 está vazio." << endl;
	/*
	O método size retorna a quantidade de posições do vector que estão sendo utilizadas. Já o método capacity
	retorna a quantidade de posições do vector que estão atualmente alocadas na memória. Como o vector utiliza
	alocação dinâmica de memória, assim que a memória alocada é preenchida ele automaticamente realoca o vector
	com uma reserva de memória o dobro da anterior.
	*/
	cout << "\nnums1 --> tamanho: " << nums1.size() << ", capacidade: " << nums1.capacity() << endl;
	for ( unsigned int i = 0; i < 10; i++ )
	{
		nums1.push_back(i);
		cout << "nums1 --> tamanho: " << nums1.size() << ", capacidade: " << nums1.capacity() << endl;
	}
	/*
	Saída:
	O vector nums está vazio.

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
	Com o método reserve conseguimos definir a quantidade da memoria que será reservada para o vector, se
	a quantidade reservada for menor do que a automática nada o metódo não fará nada.
	*/
	vector<int> nums2;
	// Reservando 8 posições na memória.
	nums2.reserve(8);
	cout << "\nnums2 --> tamanho: " << nums2.size() << ", capacidade: " << nums2.capacity() << endl;
	for ( unsigned int i = 0; i < 10; i++ )
	{
		nums2.push_back(i);
		cout << "nums2 --> tamanho: " << nums2.size() << ", capacidade: " << nums2.capacity() << endl;
	}
	/*
	Saída:
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
	O método shrink_to_fit(encolher para caber) libera a memória reserva, mantendo apenas a capacidade
	que está sendo utilizada no momento.
	O método max_size retorna a quantidade máxima de posições que podem ser alocadas pelo vector.
	*/
	cout << "Capacidade atual de nums2: " << nums2.capacity() << endl;
	// Liberando a memória não utilizada.
	nums2.shrink_to_fit();
	cout << "Capacidade de nums2 após a liberação: " << nums2.capacity() << endl;
	cout << "Tamanho máximo que o vector nums2 pode ter: " << nums2.max_size();
	/*
	Saída:
	Capacidade atual de nums2: 16
	Capacidade de nums2 após a liberação: 10
	Tamanho máximo que o vector nums2 pode ter: 4611686018427387903
	*/
	return 0;
}
