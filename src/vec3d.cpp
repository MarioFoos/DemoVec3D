#include "vec3d.h"

#include <ctime>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdint>

using namespace std;

vec3d::vec3d() : vec3d(0)
{
};

vec3d::vec3d(double init)
{
	srand(static_cast<uint32_t>(time(0)));
	fill(init);
};

double& vec3d::operator[](std::size_t pos)
{
	if(pos >= SIZE)
	{
        throw std::out_of_range("Índice fuera de rango");
	}
	return _data[pos];
};

vec3d& vec3d::operator=(const vec3d& other)
{
	if(this != &other)
	{
		for(std::size_t i = 0; i < SIZE; ++i)
		{
			_data[i] = other._data[i];
		}
	}
	return *this;
};

bool vec3d::operator==(const vec3d& other) const
{
	if(this == &other)
	{
		return true;
	}
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		if(_data[i] != other._data[i])
		{
			return false;
		}
	}
	return true;
}

bool vec3d::operator!=(const vec3d& other) const
{
	if(this == &other)
	{
		return false;
	}
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		if(_data[i] != other._data[i])
		{
			return true;
		}
	}
	return false;
}

//-------------------------------------------------------------------------------------------------

vec3d& vec3d::operator+=(const vec3d &other)
{
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		_data[i] += other._data[i];
	};
	return *this;
};

vec3d& vec3d::operator-=(const vec3d &other)
{
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		_data[i] -= other._data[i];
	};
	return *this;
};

vec3d& vec3d::operator*=(double num)
{
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		_data[i] = num*_data[i];
	};
	return *this;
};

vec3d& vec3d::operator/=(double num)
{
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		_data[i] = _data[i]/num;
	};
	return *this;
};

//-------------------------------------------------------------------------------------------------

vec3d vec3d::operator+(const vec3d &other) const
{
	vec3d res;
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		res._data[i] = _data[i] + other._data[i];
	};
	return res;
};

vec3d vec3d::operator-(const vec3d &other) const
{
	vec3d res;
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		res._data[i] = _data[i] - other._data[i];
	};
	return res;
};

double vec3d::operator*(const vec3d& other) const
{
	double res = 0;

	for(std::size_t i = 0; i < SIZE; ++i)
	{
		res += _data[i]*other._data[i];
	};
	return res;
};

vec3d vec3d::operator*(double num) const
{
	vec3d res;
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		res._data[i] = _data[i]*num;
	};
	return res;
}

vec3d vec3d::operator/(double num) const
{
	vec3d res;

	for(std::size_t i = 0; i < SIZE; ++i)
	{
		res._data[i] = _data[i]/num;
	};
	return res;
}

//-------------------------------------------------------------------------------------------------

void vec3d::fill(double value)
{
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		_data[i] = value;
	};
};

void vec3d::fillrnd()
{
	for(std::size_t i = 0; i < SIZE; ++i)
	{
		double range = static_cast<double>(rand())/RAND_MAX*2 - 1;
		_data[i] = range*100;
	};
};

std::string vec3d::to_string()
{
	std::string out;

	for(std::size_t i = 0; i < SIZE; ++i)
	{
		std::string str = std::to_string(_data[i]);
		if(i == 0)
		{
			out.append(1, '{');
		}
		out.append(str);
		if(i == SIZE - 1)
		{
			out.append(1, '}');
		}
		else
		{
			out.append(", ");
		}
	}
	return out;
};

std::ostream& operator<<(std::ostream& os, vec3d& other)
{
	os << other.to_string();
	return os;
};
