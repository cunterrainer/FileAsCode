#include "VectorB.h"

#define cast(x) static_cast<bool>(x)

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : bool
		Bytes: 1
		Range: true or false
	*/

	// Vector2b
	inline Vector2b::Vector2b(const bool& x, const bool& y) noexcept
		: x(x), y(y) {}

	// copy/move constructor and assignment
	inline Vector2b::Vector2b(const Vector2b& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2b& Vector2b::operator=(const Vector2b& other) noexcept {
		x = other.x; y = other.y; return *this;
	}

	inline Vector2b::Vector2b(Vector2b&& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2b& Vector2b::operator=(Vector2b&& other) noexcept {
		x = other.x; y = other.y; return *this;
	}
	// .....................................
	inline Vector2b& Vector2b::operator=(const bool& number) noexcept {
		x = number; y = number; return *this;
	}


	inline Vector2b Vector2b::operator +(const Vector2b& v) const noexcept {
		return { cast(x + v.x), cast(y + v.y) };
	}

	inline Vector2b Vector2b::operator -(const Vector2b& v) const noexcept {
		return { cast(x - v.x), cast(y - v.y) };
	}

	inline Vector2b Vector2b::operator *(const Vector2b& v) const noexcept {
		return { cast(x * v.x), cast(y * v.y) };
	}

	inline Vector2b Vector2b::operator /(const Vector2b& v) const noexcept {
		return {   };
	}


	inline Vector2b Vector2b::operator +(const bool& number) const noexcept {
		return { cast(x + number), cast(y + number) };
	}

	inline Vector2b Vector2b::operator -(const bool& number) const noexcept {
		return { cast(x - number), cast(y - number) };
	}

	inline Vector2b Vector2b::operator *(const bool& number) const noexcept {
		return { cast(x * number), cast(y * number) };
	}

	inline Vector2b Vector2b::operator /(const bool& number) const noexcept {
		return {   };
	}


	// increment / decrement
	inline Vector2b& Vector2b::operator++ () noexcept {
		 
		return *this;
	}

	inline Vector2b& Vector2b::operator-- ()  noexcept {
		 
		return *this;
	}

	inline Vector2b Vector2b::operator++ (int) noexcept {
		Vector2b temp = *this;
		++* this;
		return temp;
	}

	inline Vector2b Vector2b::operator-- (int) noexcept {
		Vector2b temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector2b& Vector2b::operator+= (const Vector2b& right) noexcept {
		 
		return *this;
	}

	inline Vector2b& Vector2b::operator-= (const Vector2b& right) noexcept {
		 
		return *this;
	}

	inline Vector2b& Vector2b::operator*= (const Vector2b& right) noexcept {
		 
		return *this;
	}

	inline Vector2b& Vector2b::operator/= (const Vector2b& right) noexcept {
		 
		return *this;
	}


	inline Vector2b& Vector2b::operator+= (const bool& number) noexcept {
		 
		return *this;
	}

	inline Vector2b& Vector2b::operator-= (const bool& number) noexcept {
		 
		return *this;
	}

	inline Vector2b& Vector2b::operator*= (const bool& number) noexcept {
		 
		return *this;
	}

	inline Vector2b& Vector2b::operator/= (const bool& number) noexcept {
		 
		return *this;
	}


	// less than / greater than
	inline bool Vector2b::operator< (const Vector2b& other) const noexcept {
		return x < other.x && y < other.y;
	}

	inline bool Vector2b::operator<= (const Vector2b& other) const noexcept {
		return x <= other.x && y <= other.y;
	}

	inline bool Vector2b::operator>  (const Vector2b& other) const noexcept {
		return x > other.x && y > other.y;
	}

	inline bool Vector2b::operator>= (const Vector2b& other) const noexcept {
		return x >= other.x && y >= other.y;
	}


	inline bool Vector2b::operator<  (const bool& number) const noexcept {
		return x < number && y < number;
	}

	inline bool Vector2b::operator<= (const bool& number) const noexcept {
		return x <= number && y <= number;
	}

	inline bool Vector2b::operator>  (const bool& number) const noexcept {
		return x > number && y > number;
	}

	inline bool Vector2b::operator>= (const bool& number) const noexcept {
		return x >= number && y >= number;
	}


	// equal / not equal
	inline bool Vector2b::operator==(const Vector2b& other) const noexcept {
		return x == other.x && y == other.y;
	}

	inline bool Vector2b::operator!=(const Vector2b& other) const noexcept {
		return x != other.x || y != other.y;
	}

	inline bool Vector2b::operator==(const bool& number) const noexcept {
		return x == number && y == number;
	}

	inline bool Vector2b::operator!=(const bool& number) const noexcept {
		return x != number || y != number;
	}


	inline constexpr std::uint8_t Vector2b::size() const noexcept { return 2; }
	inline void Vector2b::reset(const bool& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline bool& Vector2b::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline bool& Vector2b::at(const std::uint8_t& index) noexcept
	{
		bool* ptr = &x;
		if (index > 1)
			return ptr[0];
		return ptr[index];
	}



	// Vector3b
	inline Vector3b::Vector3b(const bool& x, const bool& y, const bool& z) noexcept
		: x(x), y(y), z(z) {}

	// copy/move constructor and assignment
	inline Vector3b::Vector3b(const Vector3b& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3b& Vector3b::operator=(const Vector3b& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}

	inline Vector3b::Vector3b(Vector3b&& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3b& Vector3b::operator=(Vector3b&& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}
	// .....................................
	inline Vector3b& Vector3b::operator=(const bool& number) noexcept {
		x = number; y = number; z = number; return *this;
	}


	inline Vector3b Vector3b::operator +(const Vector3b& v) const noexcept {
		return { cast(x + v.x), cast(y + v.y), cast(z + v.z) };
	}

	inline Vector3b Vector3b::operator -(const Vector3b& v) const noexcept {
		return { cast(x - v.x), cast(y - v.y), cast(z - v.z) };
	}

	inline Vector3b Vector3b::operator *(const Vector3b& v) const noexcept {
		return { cast(x * v.x), cast(y * v.y), cast(z * v.z) };
	}

	inline Vector3b Vector3b::operator /(const Vector3b& v) const noexcept {
		return {    };
	}

 
	inline Vector3b Vector3b::operator +(const bool& number) const noexcept {
		return { cast(x + number), cast(y + number), cast(z + number) };
	}

	inline Vector3b Vector3b::operator -(const bool& number) const noexcept {
		return { cast(x - number), cast(y - number), cast(z - number) };
	}

	inline Vector3b Vector3b::operator *(const bool& number) const noexcept {
		return { cast(x * number), cast(y * number), cast(z * number) };
	}

	inline Vector3b Vector3b::operator /(const bool& number) const noexcept {
		return {    };
	}


	// increment / decrement
	inline Vector3b& Vector3b::operator++ () noexcept {
		  
		return *this;
	}

	inline Vector3b& Vector3b::operator-- () noexcept {
		  
		return *this;
	}

	inline Vector3b Vector3b::operator++ (int) noexcept {
		Vector3b temp = *this;
		++* this;
		return temp;
	}

	inline Vector3b Vector3b::operator-- (int) noexcept {
		Vector3b temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector3b& Vector3b::operator+= (const Vector3b& right) noexcept {
		  
		return *this;
	}

	inline Vector3b& Vector3b::operator-= (const Vector3b& right) noexcept {
		  
		return *this;
	}

	inline Vector3b& Vector3b::operator*= (const Vector3b& right) noexcept {
		  
		return *this;
	}

	inline Vector3b& Vector3b::operator/= (const Vector3b& right) noexcept {
		  
		return *this;
	}


	inline Vector3b& Vector3b::operator+= (const bool& number) noexcept {
		  
		return *this;
	}

	inline Vector3b& Vector3b::operator-= (const bool& number) noexcept {
		  
		return *this;
	}

	inline Vector3b& Vector3b::operator*= (const bool& number) noexcept {
		  
		return *this;
	}

	inline Vector3b& Vector3b::operator/= (const bool& number) noexcept {
		  
		return *this;
	}


	// less than / greater than
	inline bool Vector3b::operator< (const Vector3b& other) const noexcept {
		return x < other.x && y < other.y&& z < other.z;
	}

	inline bool Vector3b::operator<= (const Vector3b& other) const noexcept {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	inline bool Vector3b::operator>  (const Vector3b& other) const noexcept {
		return x > other.x && y > other.y && z > other.z;
	}

	inline bool Vector3b::operator>= (const Vector3b& other) const noexcept {
		return x >= other.x && y >= other.y && z >= other.z;
	}


	inline bool Vector3b::operator<  (const bool& number) const noexcept {
		return x < number && y < number && z < number;
	}

	inline bool Vector3b::operator<= (const bool& number) const noexcept {
		return x <= number && y <= number && z <= number;
	}

	inline bool Vector3b::operator>  (const bool& number) const noexcept {
		return x > number && y > number && z > number;
	}

	inline bool Vector3b::operator>= (const bool& number) const noexcept {
		return x >= number && y >= number && z >= number;
	}


	// equal / not equal
	inline bool Vector3b::operator==(const Vector3b& other) const noexcept {
		return x == other.x && y == other.y && z == other.z;
	}

	inline bool Vector3b::operator!=(const Vector3b& other) const noexcept {
		return x != other.x || y != other.y || z != other.z;
	}

	inline bool Vector3b::operator==(const bool& number) const noexcept {
		return x == number && y == number && z == number;
	}

	inline bool Vector3b::operator!=(const bool& number) const noexcept {
		return x != number || y != number || z != number;
	}


	inline constexpr std::uint8_t Vector3b::size() const noexcept { return 3; }
	inline void Vector3b::reset(const bool& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline bool& Vector3b::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline bool& Vector3b::at(const std::uint8_t& index) noexcept
	{
		bool* ptr = &x;
		if (index > 2)
			return ptr[0];
		return ptr[index];
	}



	// Vector4b
	inline Vector4b::Vector4b(const bool& a, const bool& b, const bool& c, const bool& d) noexcept
		: a(a), b(b), c(c), d(d) {}

	// copy/move constructor and assignment
	inline Vector4b::Vector4b(const Vector4b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4b& Vector4b::operator=(const Vector4b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}

	inline Vector4b::Vector4b(Vector4b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4b& Vector4b::operator=(Vector4b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}
	// .....................................
	inline Vector4b& Vector4b::operator=(const bool& number) noexcept {
		a = number; b = number; c = number; d = number; return *this;
	}


	inline Vector4b Vector4b::operator +(const Vector4b& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d) };
	}

	inline Vector4b Vector4b::operator -(const Vector4b& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d) };
	}

	inline Vector4b Vector4b::operator *(const Vector4b& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d) };
	}

	inline Vector4b Vector4b::operator /(const Vector4b& v) const noexcept {
		return {     };
	}


	inline Vector4b Vector4b::operator +(const bool& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number) };
	}

	inline Vector4b Vector4b::operator -(const bool& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number) };
	}

	inline Vector4b Vector4b::operator *(const bool& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number) };
	}

	inline Vector4b Vector4b::operator /(const bool& number) const noexcept {
		return {     };
	}


	// increment / decrement
	inline Vector4b& Vector4b::operator++ () noexcept {
		   
		return *this;
	}

	inline Vector4b& Vector4b::operator-- () noexcept {
		   
		return *this;
	}

	inline Vector4b Vector4b::operator++ (int) noexcept {
		Vector4b temp = *this;
		++* this;
		return temp;
	}

	inline Vector4b Vector4b::operator-- (int) noexcept {
		Vector4b temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector4b& Vector4b::operator+= (const Vector4b& right) noexcept {
		   
		return *this;
	}

	inline Vector4b& Vector4b::operator-= (const Vector4b& right) noexcept {
		   
		return *this;
	}

	inline Vector4b& Vector4b::operator*= (const Vector4b& right) noexcept {
		   
		return *this;
	}

	inline Vector4b& Vector4b::operator/= (const Vector4b& right) noexcept {
		   
		return *this;
	}


	inline Vector4b& Vector4b::operator+= (const bool& number) noexcept {
		   
		return *this;
	}

	inline Vector4b& Vector4b::operator-= (const bool& number) noexcept {
		   
		return *this;
	}

	inline Vector4b& Vector4b::operator*= (const bool& number) noexcept {
		   
		return *this;
	}

	inline Vector4b& Vector4b::operator/= (const bool& number) noexcept {
		   
		return *this;
	}


	// less than / greater than
	inline bool Vector4b::operator< (const Vector4b& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d;
	}

	inline bool Vector4b::operator<= (const Vector4b& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d;
	}

	inline bool Vector4b::operator>  (const Vector4b& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d;
	}

	inline bool Vector4b::operator>= (const Vector4b& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d;
	}


	inline bool Vector4b::operator<  (const bool& number) const noexcept {
		return a < number && b < number && c < number && d < number;
	}

	inline bool Vector4b::operator<= (const bool& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number;
	}

	inline bool Vector4b::operator>  (const bool& number) const noexcept {
		return a > number && b > number && c > number && d > number;
	}

	inline bool Vector4b::operator>= (const bool& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number;
	}


	// equal / not equal
	inline bool Vector4b::operator==(const Vector4b& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d;
	}

	inline bool Vector4b::operator!=(const Vector4b& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d;
	}

	inline bool Vector4b::operator==(const bool& number) const noexcept {
		return a == number && b == number && c == number && d == number;
	}

	inline bool Vector4b::operator!=(const bool& number) const noexcept {
		return a != number || b != number || c != number || d != number;
	}


	inline constexpr std::uint8_t Vector4b::size() const noexcept { return 4; }
	inline void Vector4b::reset(const bool& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline bool& Vector4b::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline bool& Vector4b::at(const std::uint8_t& index) noexcept
	{
		bool* ptr = &a;
		if (index > 3)
			return ptr[0];
		return ptr[index];
	}



	// Vector5b
	inline Vector5b::Vector5b(const bool& a, const bool& b, const bool& c, const bool& d,
		const bool& e) noexcept
		: a(a), b(b), c(c), d(d), e(e) {}

	// copy/move constructor and assignment
	inline Vector5b::Vector5b(const Vector5b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5b& Vector5b::operator=(const Vector5b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}

	inline Vector5b::Vector5b(Vector5b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5b& Vector5b::operator=(Vector5b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}
	// .....................................
	inline Vector5b& Vector5b::operator=(const bool& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; return *this;
	}


	inline Vector5b Vector5b::operator +(const Vector5b& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e) };
	}

	inline Vector5b Vector5b::operator -(const Vector5b& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e) };
	}

	inline Vector5b Vector5b::operator *(const Vector5b& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e) };
	}

	inline Vector5b Vector5b::operator /(const Vector5b& v) const noexcept {
		return {      };
	}


	inline Vector5b Vector5b::operator +(const bool& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number) };
	}

	inline Vector5b Vector5b::operator -(const bool& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number) };
	}

	inline Vector5b Vector5b::operator *(const bool& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number) };
	}

	inline Vector5b Vector5b::operator /(const bool& number) const noexcept {
		return {      };
	}


	// increment / decrement
	inline Vector5b& Vector5b::operator++ () noexcept {
		    
		return *this;
	}

	inline Vector5b& Vector5b::operator-- () noexcept {
		    
		return *this;
	}

	inline Vector5b Vector5b::operator++ (int) noexcept {
		Vector5b temp = *this;
		++* this;
		return temp;
	}

	inline Vector5b Vector5b::operator-- (int) noexcept {
		Vector5b temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector5b& Vector5b::operator+= (const Vector5b& right) noexcept {
		    
		return *this;
	}

	inline Vector5b& Vector5b::operator-= (const Vector5b& right) noexcept {
		    
		return *this;
	}

	inline Vector5b& Vector5b::operator*= (const Vector5b& right) noexcept {
		    
		return *this;
	}

	inline Vector5b& Vector5b::operator/= (const Vector5b& right) noexcept {
		    
		return *this;
	}


	inline Vector5b& Vector5b::operator+= (const bool& number) noexcept {
		    
		return *this;
	}

	inline Vector5b& Vector5b::operator-= (const bool& number) noexcept {
		    
		return *this;
	}

	inline Vector5b& Vector5b::operator*= (const bool& number) noexcept {
		    
		return *this;
	}

	inline Vector5b& Vector5b::operator/= (const bool& number) noexcept {
		    
		return *this;
	}


	// less than / greater than
	inline bool Vector5b::operator< (const Vector5b& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e;
	}

	inline bool Vector5b::operator<= (const Vector5b& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e;
	}

	inline bool Vector5b::operator>  (const Vector5b& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e;
	}

	inline bool Vector5b::operator>= (const Vector5b& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e;
	}


	inline bool Vector5b::operator<  (const bool& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number;
	}

	inline bool Vector5b::operator<= (const bool& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number;
	}

	inline bool Vector5b::operator>  (const bool& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number;
	}

	inline bool Vector5b::operator>= (const bool& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number;
	}


	// equal / not equal
	inline bool Vector5b::operator==(const Vector5b& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
	}

	inline bool Vector5b::operator!=(const Vector5b& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e;
	}

	inline bool Vector5b::operator==(const bool& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number;
	}

	inline bool Vector5b::operator!=(const bool& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number;
	}


	inline constexpr std::uint8_t Vector5b::size() const noexcept { return 5; }
	inline void Vector5b::reset(const bool& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline bool& Vector5b::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline bool& Vector5b::at(const std::uint8_t& index) noexcept
	{
		bool* ptr = &a;
		if (index > 4)
			return ptr[0];
		return ptr[index];
	}



	// Vector6b
	inline Vector6b::Vector6b(const bool& a, const bool& b, const bool& c, const bool& d,
		const bool& e, const bool& f) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f) {}

	// copy/move constructor and assignment
	inline Vector6b::Vector6b(const Vector6b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6b& Vector6b::operator=(const Vector6b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}

	inline Vector6b::Vector6b(Vector6b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6b& Vector6b::operator=(Vector6b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}
	// .....................................
	inline Vector6b& Vector6b::operator=(const bool& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; return *this;
	}


	inline Vector6b Vector6b::operator +(const Vector6b& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f) };
	}

	inline Vector6b Vector6b::operator -(const Vector6b& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f) };
	}

	inline Vector6b Vector6b::operator *(const Vector6b& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f) };
	}

	inline Vector6b Vector6b::operator /(const Vector6b& v) const noexcept {
		return {       };
	}


	inline Vector6b Vector6b::operator +(const bool& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number) };
	}

	inline Vector6b Vector6b::operator -(const bool& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number) };
	}

	inline Vector6b Vector6b::operator *(const bool& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number) };
	}

	inline Vector6b Vector6b::operator /(const bool& number) const noexcept {
		return {       };
	}


	// increment / decrement
	inline Vector6b& Vector6b::operator++ () noexcept {
		     
		return *this;
	}

	inline Vector6b& Vector6b::operator-- () noexcept {
		     
		return *this;
	}

	inline Vector6b Vector6b::operator++ (int) noexcept {
		Vector6b temp = *this;
		++* this;
		return temp;
	}

	inline Vector6b Vector6b::operator-- (int) noexcept {
		Vector6b temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector6b& Vector6b::operator+= (const Vector6b& right) noexcept {
		     
		return *this;
	}

	inline Vector6b& Vector6b::operator-= (const Vector6b& right) noexcept {
		     
		return *this;
	}

	inline Vector6b& Vector6b::operator*= (const Vector6b& right) noexcept {
		     
		return *this;
	}

	inline Vector6b& Vector6b::operator/= (const Vector6b& right) noexcept {
		     
		return *this;
	}


	inline Vector6b& Vector6b::operator+= (const bool& number) noexcept {
		     
		return *this;
	}

	inline Vector6b& Vector6b::operator-= (const bool& number) noexcept {
		     
		return *this;
	}

	inline Vector6b& Vector6b::operator*= (const bool& number) noexcept {
		     
		return *this;
	}

	inline Vector6b& Vector6b::operator/= (const bool& number) noexcept {
		     
		return *this;
	}


	// less than / greater than
	inline bool Vector6b::operator< (const Vector6b& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f;
	}

	inline bool Vector6b::operator<= (const Vector6b& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f;
	}

	inline bool Vector6b::operator>  (const Vector6b& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f;
	}

	inline bool Vector6b::operator>= (const Vector6b& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f;
	}


	inline bool Vector6b::operator<  (const bool& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number;
	}

	inline bool Vector6b::operator<= (const bool& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number;
	}

	inline bool Vector6b::operator>  (const bool& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number;
	}

	inline bool Vector6b::operator>= (const bool& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number;
	}


	// equal / not equal
	inline bool Vector6b::operator==(const Vector6b& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f;
	}

	inline bool Vector6b::operator!=(const Vector6b& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f;
	}

	inline bool Vector6b::operator==(const bool& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number;
	}

	inline bool Vector6b::operator!=(const bool& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number;
	}


	inline constexpr std::uint8_t Vector6b::size() const noexcept { return 6; }
	inline void Vector6b::reset(const bool& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline bool& Vector6b::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline bool& Vector6b::at(const std::uint8_t& index) noexcept
	{
		bool* ptr = &a;
		if (index > 5)
			return ptr[0];
		return ptr[index];
	}



	// Vector7b
	inline Vector7b::Vector7b(const bool& a, const bool& b, const bool& c, const bool& d,
		const bool& e, const bool& f, const bool& g) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g) {}

	// copy/move constructor and assignment
	inline Vector7b::Vector7b(const Vector7b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7b& Vector7b::operator=(const Vector7b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}

	inline Vector7b::Vector7b(Vector7b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7b& Vector7b::operator=(Vector7b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}
	// .....................................
	inline Vector7b& Vector7b::operator=(const bool& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; return *this;
	}


	inline Vector7b Vector7b::operator +(const Vector7b& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g) };
	}

	inline Vector7b Vector7b::operator -(const Vector7b& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g) };
	}

	inline Vector7b Vector7b::operator *(const Vector7b& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g) };
	}

	inline Vector7b Vector7b::operator /(const Vector7b& v) const noexcept {
		return {        };
	}


	inline Vector7b Vector7b::operator +(const bool& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number) };
	}

	inline Vector7b Vector7b::operator -(const bool& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number) };
	}

	inline Vector7b Vector7b::operator *(const bool& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number) };
	}

	inline Vector7b Vector7b::operator /(const bool& number) const noexcept {
		return {        };
	}


	// increment / decrement
	inline Vector7b& Vector7b::operator++ () noexcept {
		      
		return *this;
	}

	inline Vector7b& Vector7b::operator-- () noexcept {
		      
		return *this;
	}

	inline Vector7b Vector7b::operator++ (int) noexcept {
		Vector7b temp = *this;
		++* this;
		return temp;
	}

	inline Vector7b Vector7b::operator-- (int) noexcept {
		Vector7b temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector7b& Vector7b::operator+= (const Vector7b& right) noexcept {
		      
		return *this;
	}

	inline Vector7b& Vector7b::operator-= (const Vector7b& right) noexcept {
		      
		return *this;
	}

	inline Vector7b& Vector7b::operator*= (const Vector7b& right) noexcept {
		      
		return *this;
	}

	inline Vector7b& Vector7b::operator/= (const Vector7b& right) noexcept {
		      
		return *this;
	}


	inline Vector7b& Vector7b::operator+= (const bool& number) noexcept {
		      
		return *this;
	}

	inline Vector7b& Vector7b::operator-= (const bool& number) noexcept {
		      
		return *this;
	}

	inline Vector7b& Vector7b::operator*= (const bool& number) noexcept {
		      
		return *this;
	}

	inline Vector7b& Vector7b::operator/= (const bool& number) noexcept {
		      
		return *this;
	}


	// less than / greater than
	inline bool Vector7b::operator< (const Vector7b& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g;
	}

	inline bool Vector7b::operator<= (const Vector7b& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g;
	}

	inline bool Vector7b::operator>  (const Vector7b& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g;
	}

	inline bool Vector7b::operator>= (const Vector7b& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g;
	}


	inline bool Vector7b::operator<  (const bool& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number;
	}

	inline bool Vector7b::operator<= (const bool& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number;
	}

	inline bool Vector7b::operator>  (const bool& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number;
	}

	inline bool Vector7b::operator>= (const bool& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number;
	}


	// equal / not equal
	inline bool Vector7b::operator==(const Vector7b& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g;
	}

	inline bool Vector7b::operator!=(const Vector7b& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g;
	}

	inline bool Vector7b::operator==(const bool& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number;
	}

	inline bool Vector7b::operator!=(const bool& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number;
	}


	inline constexpr std::uint8_t Vector7b::size() const noexcept { return 7; }
	inline void Vector7b::reset(const bool& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline bool& Vector7b::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline bool& Vector7b::at(const std::uint8_t& index) noexcept
	{
		bool* ptr = &a;
		if (index > 6)
			return ptr[0];
		return ptr[index];
	}



	// Vector8b
	inline Vector8b::Vector8b(const bool& a, const bool& b, const bool& c, const bool& d,
		const bool& e, const bool& f, const bool& g, const bool& h) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h) {}

	// copy/move constructor and assignment
	inline Vector8b::Vector8b(const Vector8b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8b& Vector8b::operator=(const Vector8b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}

	inline Vector8b::Vector8b(Vector8b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8b& Vector8b::operator=(Vector8b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}
	// .....................................
	inline Vector8b& Vector8b::operator=(const bool& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; return *this;
	}


	inline Vector8b Vector8b::operator +(const Vector8b& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h) };
	}

	inline Vector8b Vector8b::operator -(const Vector8b& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h) };
	}

	inline Vector8b Vector8b::operator *(const Vector8b& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h) };
	}

	inline Vector8b Vector8b::operator /(const Vector8b& v) const noexcept {
		return {         };
	}


	inline Vector8b Vector8b::operator +(const bool& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number) };
	}

	inline Vector8b Vector8b::operator -(const bool& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number) };
	}

	inline Vector8b Vector8b::operator *(const bool& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number) };
	}

	inline Vector8b Vector8b::operator /(const bool& number) const noexcept {
		return {         };
	}


	// increment / decrement
	inline Vector8b& Vector8b::operator++ () noexcept {
		       
		return *this;
	}

	inline Vector8b& Vector8b::operator-- () noexcept {
		       
		return *this;
	}

	inline Vector8b Vector8b::operator++ (int) noexcept {
		Vector8b temp = *this;
		++* this;
		return temp;
	}

	inline Vector8b Vector8b::operator-- (int) noexcept {
		Vector8b temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector8b& Vector8b::operator+= (const Vector8b& right) noexcept {
		       
		return *this;
	}

	inline Vector8b& Vector8b::operator-= (const Vector8b& right) noexcept {
		       
		return *this;
	}

	inline Vector8b& Vector8b::operator*= (const Vector8b& right) noexcept {
		       
		return *this;
	}

	inline Vector8b& Vector8b::operator/= (const Vector8b& right) noexcept {
		       
		return *this;
	}


	inline Vector8b& Vector8b::operator+= (const bool& number) noexcept {
		       
		return *this;
	}

	inline Vector8b& Vector8b::operator-= (const bool& number) noexcept {
		       
		return *this;
	}

	inline Vector8b& Vector8b::operator*= (const bool& number) noexcept {
		       
		return *this;
	}

	inline Vector8b& Vector8b::operator/= (const bool& number) noexcept {
		       
		return *this;
	}


	// less than / greater than
	inline bool Vector8b::operator< (const Vector8b& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h;
	}

	inline bool Vector8b::operator<= (const Vector8b& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h;
	}

	inline bool Vector8b::operator>  (const Vector8b& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h;
	}

	inline bool Vector8b::operator>= (const Vector8b& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h;
	}


	inline bool Vector8b::operator<  (const bool& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number;
	}

	inline bool Vector8b::operator<= (const bool& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number;
	}

	inline bool Vector8b::operator>  (const bool& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number;
	}

	inline bool Vector8b::operator>= (const bool& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number;
	}


	// equal / not equal
	inline bool Vector8b::operator==(const Vector8b& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h;
	}

	inline bool Vector8b::operator!=(const Vector8b& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h;
	}

	inline bool Vector8b::operator==(const bool& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number;
	}

	inline bool Vector8b::operator!=(const bool& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number;
	}


	inline constexpr std::uint8_t Vector8b::size() const noexcept { return 8; }
	inline void Vector8b::reset(const bool& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline bool& Vector8b::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline bool& Vector8b::at(const std::uint8_t& index) noexcept
	{
		bool* ptr = &a;
		if (index > 7)
			return ptr[0];
		return ptr[index];
	}



	// Vector9b
	inline Vector9b::Vector9b(const bool& a, const bool& b, const bool& c, const bool& d,
		const bool& e, const bool& f, const bool& g, const bool& h,
		const bool& i) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

	// copy/move constructor and assignment
	inline Vector9b::Vector9b(const Vector9b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9b& Vector9b::operator=(const Vector9b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}

	inline Vector9b::Vector9b(Vector9b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9b& Vector9b::operator=(Vector9b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}
	// .....................................
	inline Vector9b& Vector9b::operator=(const bool& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; return *this;
	}


	inline Vector9b Vector9b::operator +(const Vector9b& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h), cast(i + v.i) };
	}

	inline Vector9b Vector9b::operator -(const Vector9b& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h), cast(i - v.i) };
	}

	inline Vector9b Vector9b::operator *(const Vector9b& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h), cast(i * v.i) };
	}

	inline Vector9b Vector9b::operator /(const Vector9b& v) const noexcept {
		return {          };
	}


	inline Vector9b Vector9b::operator +(const bool& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number), cast(i + number) };
	}

	inline Vector9b Vector9b::operator -(const bool& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number), cast(i - number) };
	}

	inline Vector9b Vector9b::operator *(const bool& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number), cast(i * number) };
	}

	inline Vector9b Vector9b::operator /(const bool& number) const noexcept {
		return {          };
	}


	// increment / decrement
	inline Vector9b& Vector9b::operator++ () noexcept {
		        
		return *this;
	}

	inline Vector9b& Vector9b::operator-- () noexcept {
		        
		return *this;
	}

	inline Vector9b Vector9b::operator++ (int) noexcept {
		Vector9b temp = *this;
		++* this;
		return temp;
	}

	inline Vector9b Vector9b::operator-- (int) noexcept {
		Vector9b temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector9b& Vector9b::operator+= (const Vector9b& right) noexcept {
		        
		return *this;
	}

	inline Vector9b& Vector9b::operator-= (const Vector9b& right) noexcept {
		        
		return *this;
	}

	inline Vector9b& Vector9b::operator*= (const Vector9b& right) noexcept {
		        
		return *this;
	}

	inline Vector9b& Vector9b::operator/= (const Vector9b& right) noexcept {
		        
		return *this;
	}


	inline Vector9b& Vector9b::operator+= (const bool& number) noexcept {
		        
		return *this;
	}

	inline Vector9b& Vector9b::operator-= (const bool& number) noexcept {
		        
		return *this;
	}

	inline Vector9b& Vector9b::operator*= (const bool& number) noexcept {
		        
		return *this;
	}

	inline Vector9b& Vector9b::operator/= (const bool& number) noexcept {
		        
		return *this;
	}


	// less than / greater than
	inline bool Vector9b::operator< (const Vector9b& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i;
	}

	inline bool Vector9b::operator<= (const Vector9b& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i;
	}

	inline bool Vector9b::operator>  (const Vector9b& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i;
	}

	inline bool Vector9b::operator>= (const Vector9b& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i;
	}


	inline bool Vector9b::operator<  (const bool& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number;
	}

	inline bool Vector9b::operator<= (const bool& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number;
	}

	inline bool Vector9b::operator>  (const bool& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number;
	}

	inline bool Vector9b::operator>= (const bool& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number;
	}


	// equal / not equal
	inline bool Vector9b::operator==(const Vector9b& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i;
	}

	inline bool Vector9b::operator!=(const Vector9b& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i;
	}

	inline bool Vector9b::operator==(const bool& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number;
	}

	inline bool Vector9b::operator!=(const bool& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number;
	}


	inline constexpr std::uint8_t Vector9b::size() const noexcept { return 9; }
	inline void Vector9b::reset(const bool& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline bool& Vector9b::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline bool& Vector9b::at(const std::uint8_t& index) noexcept
	{
		bool* ptr = &a;
		if (index > 8)
			return ptr[0];
		return ptr[index];
	}



	// Vector10b
	inline Vector10b::Vector10b(const bool& a, const bool& b, const bool& c, const bool& d,
		const bool& e, const bool& f, const bool& g, const bool& h,
		const bool& i, const bool& j) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {}

	// copy/move constructor and assignment
	inline Vector10b::Vector10b(const Vector10b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10b& Vector10b::operator=(const Vector10b& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}

	inline Vector10b::Vector10b(Vector10b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10b& Vector10b::operator=(Vector10b&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}
	// .....................................
	inline Vector10b& Vector10b::operator=(const bool& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; j = number; return *this;
	}


	inline Vector10b Vector10b::operator +(const Vector10b& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h), cast(i + v.i), cast(j + v.j) };
	}

	inline Vector10b Vector10b::operator -(const Vector10b& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h), cast(i - v.i), cast(j - v.j) };
	}

	inline Vector10b Vector10b::operator *(const Vector10b& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h), cast(i * v.i), cast(j * v.j) };
	}

	inline Vector10b Vector10b::operator /(const Vector10b& v) const noexcept {
		return {           };
	}


	inline Vector10b Vector10b::operator +(const bool& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number), cast(i + number), cast(j + number) };
	}

	inline Vector10b Vector10b::operator -(const bool& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number), cast(i - number), cast(j - number) };
	}

	inline Vector10b Vector10b::operator *(const bool& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number), cast(i * number), cast(j * number) };
	}

	inline Vector10b Vector10b::operator /(const bool& number) const noexcept {
		return {           };
	}


	// increment / decrement
	inline Vector10b& Vector10b::operator++ () noexcept {
		         
		return *this;
	}

	inline Vector10b& Vector10b::operator-- () noexcept {
		         
		return *this;
	}

	inline Vector10b Vector10b::operator++ (int) noexcept {
		Vector10b temp = *this;
		++* this;
		return temp;
	}

	inline Vector10b Vector10b::operator-- (int) noexcept {
		Vector10b temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector10b& Vector10b::operator+= (const Vector10b& right) noexcept {
		         
		return *this;
	}

	inline Vector10b& Vector10b::operator-= (const Vector10b& right) noexcept {
		         
		return *this;
	}

	inline Vector10b& Vector10b::operator*= (const Vector10b& right) noexcept {
		         
		return *this;
	}

	inline Vector10b& Vector10b::operator/= (const Vector10b& right) noexcept {
		         
		return *this;
	}


	inline Vector10b& Vector10b::operator+= (const bool& number) noexcept {
		         
		return *this;
	}

	inline Vector10b& Vector10b::operator-= (const bool& number) noexcept {
		         
		return *this;
	}

	inline Vector10b& Vector10b::operator*= (const bool& number) noexcept {
		         
		return *this;
	}

	inline Vector10b& Vector10b::operator/= (const bool& number) noexcept {
		         
		return *this;
	}


	// less than / greater than
	inline bool Vector10b::operator< (const Vector10b& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i&& j < other.j;
	}

	inline bool Vector10b::operator<= (const Vector10b& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i && j <= other.j;
	}

	inline bool Vector10b::operator>  (const Vector10b& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i && j > other.j;
	}

	inline bool Vector10b::operator>= (const Vector10b& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i && j >= other.j;
	}


	inline bool Vector10b::operator<  (const bool& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number && j < number;
	}

	inline bool Vector10b::operator<= (const bool& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number && j <= number;
	}

	inline bool Vector10b::operator>  (const bool& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number && j > number;
	}

	inline bool Vector10b::operator>= (const bool& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number && j >= number;
	}


	// equal / not equal
	inline bool Vector10b::operator==(const Vector10b& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i && j == other.j;
	}

	inline bool Vector10b::operator!=(const Vector10b& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i || j != other.j;
	}

	inline bool Vector10b::operator==(const bool& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number && j == number;
	}

	inline bool Vector10b::operator!=(const bool& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number || j != number;
	}


	inline constexpr std::uint8_t Vector10b::size() const noexcept { return 10; }
	inline void Vector10b::reset(const bool& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline bool& Vector10b::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline bool& Vector10b::at(const std::uint8_t& index) noexcept
	{
		bool* ptr = &a;
		if (index > 9)
			return ptr[0];
		return ptr[index];
	}
	// End
}