#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <iostream>
using std::ostream;

// Sobrecarregando o operador de saída <<, para que possa imprimir o vector entre conchetes e separado por vírgulas.
ostream& operator<<(ostream& s, const vector<int> v) 
{
   	s.put('[');
   	char virgula[3] = { '\0', ' ', '\0'};
   	for ( int e : v) {
       	s << virgula << e;
       	virgula[0] = ',';
   	}
   	return s << ']';
}

// Definindo um tipo de vector que só recebe inteiros.
typedef vector<int> intVector;

int main()
{	
	// Construindo um vector vazio.
	intVector numbers1;
	cout << "numbers1: " << numbers1 << endl;
	
	// Construindo um vector com valores específicos.
	intVector numbers2 { 1, 2, 3, 4, 5 };
	cout << "numbers2: " << numbers2 << endl;
	
	// Construindo um vector com os valores de outro vector do primeiro ao último.
	intVector numbers3( numbers2.begin(), numbers2.end() );
	cout << "numbers3: " << numbers3 << endl;
	
	// Construindo um vector apartir dos valores de outro.
	intVector numbers4( numbers3 );
	cout << "numbers4: " << numbers4 << endl;
	
	// Construindo um vector com 5 posições, cada uma inicializada com 0.
	intVector numbers5( 5, 0 );
	cout << "numbers5: " << numbers5 << endl;
	
	/*
	Saída:
	
	numbers1: 1
	numbers2: [1, 2, 3, 4, 5]
	numbers3: [1, 2, 3, 4, 5]
	numbers4: [1, 2, 3, 4, 5]
	numbers5: [0, 0, 0, 0, 0]
	*/
	
	return 0;
}
