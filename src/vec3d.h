#ifndef SRC_VEC3D_H_
#define SRC_VEC3D_H_

#pragma once

#include <iostream>

class vec3d
{
	private:
		static const std::size_t SIZE = 3;
		double _data[SIZE];
	public:
		vec3d();
		vec3d(double init);
		virtual ~vec3d(){};

		// Acceso, asignación, comparación
		double& operator[](std::size_t _pos);
		vec3d& operator=(const vec3d& other);
		bool operator==(const vec3d& other) const;
		bool operator!=(const vec3d& other) const;

		// Aritméticos
		vec3d operator+(const vec3d& other) const;
		vec3d operator-(const vec3d& other) const;
		double operator*(const vec3d& other) const;
		vec3d operator*(double num) const;
		vec3d operator/(double num) const;

		// Aritméticos y de asignación
		vec3d& operator+=(const vec3d& other);
		vec3d& operator-=(const vec3d& other);
		vec3d& operator*=(double num);
		vec3d& operator/=(double num);

		// Relleno
		void fill(double value);
		void fillrnd();
		void clear(){ fill(0); };

		std::string to_string();
};

std::ostream& operator<<(std::ostream& os, vec3d& other);

#endif /* SRC_VEC3D_H_ */
