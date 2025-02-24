//============================================================================
// Autor: Diardon
// Blog : https://diardon.wordpress.com/
//============================================================================

#include <iostream>
#include "vec3d.h"

void test1();
void test2();
void test3();
void test4();

int main()
{
	//test1();
	//test2();
	//test3();
	test4();

	return 0;
}

void test4()
{
	vec3d vec1(1);
	vec3d vec2(2);

	std::cout << "vec1: " << vec1 << std::endl;
	std::cout << "vec2: " << vec2 << std::endl;

	vec1 *= 5;
	std::cout << "vec1 *= 5: " << vec1 << std::endl;

	vec1 += vec2;
	std::cout << "vec1 += vec2: " << vec1 << std::endl;
}

void test3()
{
	vec3d vec1(1);
	vec3d vec2(2);

	// Suma
	vec3d vec3 = vec1 + vec2;
	double prod = vec1*vec2;
	vec3d vec4 = vec1*5;

	std::cout << "vec1: " << vec1 << std::endl;
	std::cout << "vec2: " << vec2 << std::endl;

	std::cout << "vec1 + vec2: " << vec3 << std::endl;
	std::cout << "vec1*vec2: " << prod << std::endl;
	std::cout << "vec1*5: " << vec4 << std::endl;
}
void test2()
{
	vec3d vec1(3);
	vec3d vec2(5);
	vec3d vec3(3);

	// Acceso a datos
	for(int i = 0; i < 3; ++i)
	{
		std::cout << vec1[i] << " ";
	}
	std::cout << std::endl;

	// Modificar datos
	for(int i = 0; i < 3; ++i)
	{
		vec2[i] = (i + 1)*2;
	}
	std::cout << "vec1: " << vec1 << std::endl;
	std::cout << "vec2: " << vec2 << std::endl;
	std::cout << "vec3: " << vec3 << std::endl;

	// Comparar
	std::cout << "vec1 == vec2: " << ((vec1 == vec2) ? "Iguales" : "Distintos" )<< std::endl;
	std::cout << "vec1 == vec3: " << ((vec1 == vec3) ? "Iguales" : "Distintos" )<< std::endl;
	std::cout << "vec2 == vec2: " << ((vec2 == vec2) ? "Iguales" : "Distintos" )<< std::endl;
}

void test1()
{
	vec3d vec1(1);
	vec3d vec2(2);

	std::cout << "vec1: " << vec1 << std::endl;
	std::cout << "vec2: " << vec2 << std::endl;
	std::cout << std::endl;

	vec1.fill(11);
	vec2.fill(22);

	std::cout << "vec1: " << vec1 << std::endl;
	std::cout << "vec2: " << vec2 << std::endl;
	std::cout << std::endl;

	vec1.fillrnd();
	vec2.fillrnd();

	std::cout << "vec1: " << vec1 << std::endl;
	std::cout << "vec2: " << vec2 << std::endl;
	std::cout << std::endl;
}
