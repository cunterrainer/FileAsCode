#include "VectorLd.h"

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : long double
		Bytes: 8
		Range: 1.7E +/- 308  precision: (15 digits)
	*/

	// Vector2Ld
	inline Vector2Ld::Vector2Ld(const long double& x, const long double& y) noexcept
		: x(x), y(y) {}

	// copy/move constructor and assignment
	inline Vector2Ld::Vector2Ld(const Vector2Ld& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2Ld& Vector2Ld::operator=(const Vector2Ld& other) noexcept {
		x = other.x; y = other.y; return *this;
	}

	inline Vector2Ld::Vector2Ld(Vector2Ld&& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2Ld& Vector2Ld::operator=(Vector2Ld&& other) noexcept {
		x = other.x; y = other.y; return *this;
	}
	// .....................................
	inline Vector2Ld& Vector2Ld::operator=(const long double& number) noexcept {
		x = number; y = number; return *this;
	}


	inline Vector2Ld Vector2Ld::operator +(const Vector2Ld& v) const noexcept {
		return { x + v.x, y + v.y };
	}

	inline Vector2Ld Vector2Ld::operator -(const Vector2Ld& v) const noexcept {
		return { x - v.x, y - v.y };
	}

	inline Vector2Ld Vector2Ld::operator *(const Vector2Ld& v) const noexcept {
		return { x * v.x, y * v.y };
	}

	inline Vector2Ld Vector2Ld::operator /(const Vector2Ld& v) const noexcept {
		return { x / v.x, y / v.y };
	}


	inline Vector2Ld Vector2Ld::operator +(const long double& number) const noexcept {
		return { x + number, y + number };
	}

	inline Vector2Ld Vector2Ld::operator -(const long double& number) const noexcept {
		return { x - number, y - number };
	}

	inline Vector2Ld Vector2Ld::operator *(const long double& number) const noexcept {
		return { x * number, y * number };
	}

	inline Vector2Ld Vector2Ld::operator /(const long double& number) const noexcept {
		return { x / number, y / number };
	}


	// increment / decrement
	inline Vector2Ld& Vector2Ld::operator++ () noexcept {
		++x; ++y;
		return *this;
	}

	inline Vector2Ld& Vector2Ld::operator-- ()  noexcept {
		--x; --y;
		return *this;
	}

	inline Vector2Ld Vector2Ld::operator++ (int) noexcept {
		Vector2Ld temp = *this;
		++* this;
		return temp;
	}

	inline Vector2Ld Vector2Ld::operator-- (int) noexcept {
		Vector2Ld temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector2Ld& Vector2Ld::operator+= (const Vector2Ld& right) noexcept {
		x += right.x; y += right.y;
		return *this;
	}

	inline Vector2Ld& Vector2Ld::operator-= (const Vector2Ld& right) noexcept {
		x -= right.x; y -= right.y;
		return *this;
	}

	inline Vector2Ld& Vector2Ld::operator*= (const Vector2Ld& right) noexcept {
		x *= right.x; y *= right.y;
		return *this;
	}

	inline Vector2Ld& Vector2Ld::operator/= (const Vector2Ld& right) noexcept {
		x /= right.x; y /= right.y;
		return *this;
	}


	inline Vector2Ld& Vector2Ld::operator+= (const long double& number) noexcept {
		x += number; y += number;
		return *this;
	}

	inline Vector2Ld& Vector2Ld::operator-= (const long double& number) noexcept {
		x -= number; y -= number;
		return *this;
	}

	inline Vector2Ld& Vector2Ld::operator*= (const long double& number) noexcept {
		x *= number; y *= number;
		return *this;
	}

	inline Vector2Ld& Vector2Ld::operator/= (const long double& number) noexcept {
		x /= number; y /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector2Ld::operator< (const Vector2Ld& other) const noexcept {
		return x < other.x && y < other.y;
	}

	inline bool Vector2Ld::operator<= (const Vector2Ld& other) const noexcept {
		return x <= other.x && y <= other.y;
	}

	inline bool Vector2Ld::operator>  (const Vector2Ld& other) const noexcept {
		return x > other.x && y > other.y;
	}

	inline bool Vector2Ld::operator>= (const Vector2Ld& other) const noexcept {
		return x >= other.x && y >= other.y;
	}


	inline bool Vector2Ld::operator<  (const long double& number) const noexcept {
		return x < number && y < number;
	}

	inline bool Vector2Ld::operator<= (const long double& number) const noexcept {
		return x <= number && y <= number;
	}

	inline bool Vector2Ld::operator>  (const long double& number) const noexcept {
		return x > number && y > number;
	}

	inline bool Vector2Ld::operator>= (const long double& number) const noexcept {
		return x >= number && y >= number;
	}


	// equal / not equal
	inline bool Vector2Ld::operator==(const Vector2Ld& other) const noexcept {
		return x == other.x && y == other.y;
	}

	inline bool Vector2Ld::operator!=(const Vector2Ld& other) const noexcept {
		return x != other.x || y != other.y;
	}

	inline bool Vector2Ld::operator==(const long double& number) const noexcept {
		return x == number && y == number;
	}

	inline bool Vector2Ld::operator!=(const long double& number) const noexcept {
		return x != number || y != number;
	}


	inline constexpr std::uint8_t Vector2Ld::size() const noexcept { return 2; }
	inline void Vector2Ld::reset(const long double& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long double& Vector2Ld::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long double& Vector2Ld::at(const std::uint8_t& index) noexcept
	{
		long double* ptr = &x;
		if (index > 1)
			return ptr[0];
		return ptr[index];
	}



	// Vector3Ld
	inline Vector3Ld::Vector3Ld(const long double& x, const long double& y, const long double& z) noexcept
		: x(x), y(y), z(z) {}

	// copy/move constructor and assignment
	inline Vector3Ld::Vector3Ld(const Vector3Ld& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3Ld& Vector3Ld::operator=(const Vector3Ld& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}

	inline Vector3Ld::Vector3Ld(Vector3Ld&& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3Ld& Vector3Ld::operator=(Vector3Ld&& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}
	// .....................................
	inline Vector3Ld& Vector3Ld::operator=(const long double& number) noexcept {
		x = number; y = number; z = number; return *this;
	}


	inline Vector3Ld Vector3Ld::operator +(const Vector3Ld& v) const noexcept {
		return { x + v.x, y + v.y, z + v.z };
	}

	inline Vector3Ld Vector3Ld::operator -(const Vector3Ld& v) const noexcept {
		return { x - v.x, y - v.y, z - v.z };
	}

	inline Vector3Ld Vector3Ld::operator *(const Vector3Ld& v) const noexcept {
		return { x * v.x, y * v.y, z * v.z };
	}

	inline Vector3Ld Vector3Ld::operator /(const Vector3Ld& v) const noexcept {
		return { x / v.x, y / v.y, z / v.z };
	}

 
	inline Vector3Ld Vector3Ld::operator +(const long double& number) const noexcept {
		return { x + number, y + number, z + number };
	}

	inline Vector3Ld Vector3Ld::operator -(const long double& number) const noexcept {
		return { x - number, y - number, z - number };
	}

	inline Vector3Ld Vector3Ld::operator *(const long double& number) const noexcept {
		return { x * number, y * number, z * number };
	}

	inline Vector3Ld Vector3Ld::operator /(const long double& number) const noexcept {
		return { x / number, y / number, z / number };
	}


	// increment / decrement
	inline Vector3Ld& Vector3Ld::operator++ () noexcept {
		++x; ++y; ++z;
		return *this;
	}

	inline Vector3Ld& Vector3Ld::operator-- () noexcept {
		--x; --y; --z;
		return *this;
	}

	inline Vector3Ld Vector3Ld::operator++ (int) noexcept {
		Vector3Ld temp = *this;
		++* this;
		return temp;
	}

	inline Vector3Ld Vector3Ld::operator-- (int) noexcept {
		Vector3Ld temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector3Ld& Vector3Ld::operator+= (const Vector3Ld& right) noexcept {
		x += right.x; y += right.y; z += right.z;
		return *this;
	}

	inline Vector3Ld& Vector3Ld::operator-= (const Vector3Ld& right) noexcept {
		x -= right.x; y -= right.y; z -= right.z;
		return *this;
	}

	inline Vector3Ld& Vector3Ld::operator*= (const Vector3Ld& right) noexcept {
		x *= right.x; y *= right.y; z *= right.z;
		return *this;
	}

	inline Vector3Ld& Vector3Ld::operator/= (const Vector3Ld& right) noexcept {
		x /= right.x; y /= right.y; z /= right.z;
		return *this;
	}


	inline Vector3Ld& Vector3Ld::operator+= (const long double& number) noexcept {
		x += number; y += number; z += number;
		return *this;
	}

	inline Vector3Ld& Vector3Ld::operator-= (const long double& number) noexcept {
		x -= number; y -= number; z -= number;
		return *this;
	}

	inline Vector3Ld& Vector3Ld::operator*= (const long double& number) noexcept {
		x *= number; y *= number; z *= number;
		return *this;
	}

	inline Vector3Ld& Vector3Ld::operator/= (const long double& number) noexcept {
		x /= number; y /= number; z /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector3Ld::operator< (const Vector3Ld& other) const noexcept {
		return x < other.x && y < other.y&& z < other.z;
	}

	inline bool Vector3Ld::operator<= (const Vector3Ld& other) const noexcept {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	inline bool Vector3Ld::operator>  (const Vector3Ld& other) const noexcept {
		return x > other.x && y > other.y && z > other.z;
	}

	inline bool Vector3Ld::operator>= (const Vector3Ld& other) const noexcept {
		return x >= other.x && y >= other.y && z >= other.z;
	}


	inline bool Vector3Ld::operator<  (const long double& number) const noexcept {
		return x < number && y < number && z < number;
	}

	inline bool Vector3Ld::operator<= (const long double& number) const noexcept {
		return x <= number && y <= number && z <= number;
	}

	inline bool Vector3Ld::operator>  (const long double& number) const noexcept {
		return x > number && y > number && z > number;
	}

	inline bool Vector3Ld::operator>= (const long double& number) const noexcept {
		return x >= number && y >= number && z >= number;
	}


	// equal / not equal
	inline bool Vector3Ld::operator==(const Vector3Ld& other) const noexcept {
		return x == other.x && y == other.y && z == other.z;
	}

	inline bool Vector3Ld::operator!=(const Vector3Ld& other) const noexcept {
		return x != other.x || y != other.y || z != other.z;
	}

	inline bool Vector3Ld::operator==(const long double& number) const noexcept {
		return x == number && y == number && z == number;
	}

	inline bool Vector3Ld::operator!=(const long double& number) const noexcept {
		return x != number || y != number || z != number;
	}


	inline constexpr std::uint8_t Vector3Ld::size() const noexcept { return 3; }
	inline void Vector3Ld::reset(const long double& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long double& Vector3Ld::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long double& Vector3Ld::at(const std::uint8_t& index) noexcept
	{
		long double* ptr = &x;
		if (index > 2)
			return ptr[0];
		return ptr[index];
	}



	// Vector4Ld
	inline Vector4Ld::Vector4Ld(const long double& a, const long double& b, const long double& c, const long double& d) noexcept
		: a(a), b(b), c(c), d(d) {}

	// copy/move constructor and assignment
	inline Vector4Ld::Vector4Ld(const Vector4Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4Ld& Vector4Ld::operator=(const Vector4Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}

	inline Vector4Ld::Vector4Ld(Vector4Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4Ld& Vector4Ld::operator=(Vector4Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}
	// .....................................
	inline Vector4Ld& Vector4Ld::operator=(const long double& number) noexcept {
		a = number; b = number; c = number; d = number; return *this;
	}


	inline Vector4Ld Vector4Ld::operator +(const Vector4Ld& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d };
	}

	inline Vector4Ld Vector4Ld::operator -(const Vector4Ld& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d };
	}

	inline Vector4Ld Vector4Ld::operator *(const Vector4Ld& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d };
	}

	inline Vector4Ld Vector4Ld::operator /(const Vector4Ld& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d };
	}


	inline Vector4Ld Vector4Ld::operator +(const long double& number) const noexcept {
		return { a + number, b + number, c + number, d + number };
	}

	inline Vector4Ld Vector4Ld::operator -(const long double& number) const noexcept {
		return { a - number, b - number, c - number, d - number };
	}

	inline Vector4Ld Vector4Ld::operator *(const long double& number) const noexcept {
		return { a * number, b * number, c * number, d * number };
	}

	inline Vector4Ld Vector4Ld::operator /(const long double& number) const noexcept {
		return { a / number, b / number, c / number, d / number };
	}


	// increment / decrement
	inline Vector4Ld& Vector4Ld::operator++ () noexcept {
		++a; ++b; ++c; ++d;
		return *this;
	}

	inline Vector4Ld& Vector4Ld::operator-- () noexcept {
		--a; --b; --c; --d;
		return *this;
	}

	inline Vector4Ld Vector4Ld::operator++ (int) noexcept {
		Vector4Ld temp = *this;
		++* this;
		return temp;
	}

	inline Vector4Ld Vector4Ld::operator-- (int) noexcept {
		Vector4Ld temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector4Ld& Vector4Ld::operator+= (const Vector4Ld& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d;
		return *this;
	}

	inline Vector4Ld& Vector4Ld::operator-= (const Vector4Ld& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d;
		return *this;
	}

	inline Vector4Ld& Vector4Ld::operator*= (const Vector4Ld& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d;
		return *this;
	}

	inline Vector4Ld& Vector4Ld::operator/= (const Vector4Ld& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d;
		return *this;
	}


	inline Vector4Ld& Vector4Ld::operator+= (const long double& number) noexcept {
		a += number; b += number; c += number; d += number;
		return *this;
	}

	inline Vector4Ld& Vector4Ld::operator-= (const long double& number) noexcept {
		a -= number; b -= number; c -= number; d -= number;
		return *this;
	}

	inline Vector4Ld& Vector4Ld::operator*= (const long double& number) noexcept {
		a *= number; b *= number; c *= number; d *= number;
		return *this;
	}

	inline Vector4Ld& Vector4Ld::operator/= (const long double& number) noexcept {
		a /= number; b /= number; c /= number; d /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector4Ld::operator< (const Vector4Ld& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d;
	}

	inline bool Vector4Ld::operator<= (const Vector4Ld& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d;
	}

	inline bool Vector4Ld::operator>  (const Vector4Ld& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d;
	}

	inline bool Vector4Ld::operator>= (const Vector4Ld& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d;
	}


	inline bool Vector4Ld::operator<  (const long double& number) const noexcept {
		return a < number && b < number && c < number && d < number;
	}

	inline bool Vector4Ld::operator<= (const long double& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number;
	}

	inline bool Vector4Ld::operator>  (const long double& number) const noexcept {
		return a > number && b > number && c > number && d > number;
	}

	inline bool Vector4Ld::operator>= (const long double& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number;
	}


	// equal / not equal
	inline bool Vector4Ld::operator==(const Vector4Ld& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d;
	}

	inline bool Vector4Ld::operator!=(const Vector4Ld& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d;
	}

	inline bool Vector4Ld::operator==(const long double& number) const noexcept {
		return a == number && b == number && c == number && d == number;
	}

	inline bool Vector4Ld::operator!=(const long double& number) const noexcept {
		return a != number || b != number || c != number || d != number;
	}


	inline constexpr std::uint8_t Vector4Ld::size() const noexcept { return 4; }
	inline void Vector4Ld::reset(const long double& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long double& Vector4Ld::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long double& Vector4Ld::at(const std::uint8_t& index) noexcept
	{
		long double* ptr = &a;
		if (index > 3)
			return ptr[0];
		return ptr[index];
	}



	// Vector5Ld
	inline Vector5Ld::Vector5Ld(const long double& a, const long double& b, const long double& c, const long double& d,
		const long double& e) noexcept
		: a(a), b(b), c(c), d(d), e(e) {}

	// copy/move constructor and assignment
	inline Vector5Ld::Vector5Ld(const Vector5Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5Ld& Vector5Ld::operator=(const Vector5Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}

	inline Vector5Ld::Vector5Ld(Vector5Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5Ld& Vector5Ld::operator=(Vector5Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}
	// .....................................
	inline Vector5Ld& Vector5Ld::operator=(const long double& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; return *this;
	}


	inline Vector5Ld Vector5Ld::operator +(const Vector5Ld& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e };
	}

	inline Vector5Ld Vector5Ld::operator -(const Vector5Ld& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e };
	}

	inline Vector5Ld Vector5Ld::operator *(const Vector5Ld& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e };
	}

	inline Vector5Ld Vector5Ld::operator /(const Vector5Ld& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e };
	}


	inline Vector5Ld Vector5Ld::operator +(const long double& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number };
	}

	inline Vector5Ld Vector5Ld::operator -(const long double& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number };
	}

	inline Vector5Ld Vector5Ld::operator *(const long double& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number };
	}

	inline Vector5Ld Vector5Ld::operator /(const long double& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number };
	}


	// increment / decrement
	inline Vector5Ld& Vector5Ld::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e;
		return *this;
	}

	inline Vector5Ld& Vector5Ld::operator-- () noexcept {
		--a; --b; --c; --d; --e;
		return *this;
	}

	inline Vector5Ld Vector5Ld::operator++ (int) noexcept {
		Vector5Ld temp = *this;
		++* this;
		return temp;
	}

	inline Vector5Ld Vector5Ld::operator-- (int) noexcept {
		Vector5Ld temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector5Ld& Vector5Ld::operator+= (const Vector5Ld& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e;
		return *this;
	}

	inline Vector5Ld& Vector5Ld::operator-= (const Vector5Ld& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e;
		return *this;
	}

	inline Vector5Ld& Vector5Ld::operator*= (const Vector5Ld& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e;
		return *this;
	}

	inline Vector5Ld& Vector5Ld::operator/= (const Vector5Ld& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e;
		return *this;
	}


	inline Vector5Ld& Vector5Ld::operator+= (const long double& number) noexcept {
		a += number; b += number; c += number; d += number; e += number;
		return *this;
	}

	inline Vector5Ld& Vector5Ld::operator-= (const long double& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number;
		return *this;
	}

	inline Vector5Ld& Vector5Ld::operator*= (const long double& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number;
		return *this;
	}

	inline Vector5Ld& Vector5Ld::operator/= (const long double& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector5Ld::operator< (const Vector5Ld& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e;
	}

	inline bool Vector5Ld::operator<= (const Vector5Ld& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e;
	}

	inline bool Vector5Ld::operator>  (const Vector5Ld& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e;
	}

	inline bool Vector5Ld::operator>= (const Vector5Ld& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e;
	}


	inline bool Vector5Ld::operator<  (const long double& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number;
	}

	inline bool Vector5Ld::operator<= (const long double& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number;
	}

	inline bool Vector5Ld::operator>  (const long double& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number;
	}

	inline bool Vector5Ld::operator>= (const long double& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number;
	}


	// equal / not equal
	inline bool Vector5Ld::operator==(const Vector5Ld& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
	}

	inline bool Vector5Ld::operator!=(const Vector5Ld& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e;
	}

	inline bool Vector5Ld::operator==(const long double& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number;
	}

	inline bool Vector5Ld::operator!=(const long double& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number;
	}


	inline constexpr std::uint8_t Vector5Ld::size() const noexcept { return 5; }
	inline void Vector5Ld::reset(const long double& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long double& Vector5Ld::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long double& Vector5Ld::at(const std::uint8_t& index) noexcept
	{
		long double* ptr = &a;
		if (index > 4)
			return ptr[0];
		return ptr[index];
	}



	// Vector6Ld
	inline Vector6Ld::Vector6Ld(const long double& a, const long double& b, const long double& c, const long double& d,
		const long double& e, const long double& f) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f) {}

	// copy/move constructor and assignment
	inline Vector6Ld::Vector6Ld(const Vector6Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6Ld& Vector6Ld::operator=(const Vector6Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}

	inline Vector6Ld::Vector6Ld(Vector6Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6Ld& Vector6Ld::operator=(Vector6Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}
	// .....................................
	inline Vector6Ld& Vector6Ld::operator=(const long double& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; return *this;
	}


	inline Vector6Ld Vector6Ld::operator +(const Vector6Ld& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f };
	}

	inline Vector6Ld Vector6Ld::operator -(const Vector6Ld& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f };
	}

	inline Vector6Ld Vector6Ld::operator *(const Vector6Ld& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f };
	}

	inline Vector6Ld Vector6Ld::operator /(const Vector6Ld& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f };
	}


	inline Vector6Ld Vector6Ld::operator +(const long double& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number };
	}

	inline Vector6Ld Vector6Ld::operator -(const long double& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number };
	}

	inline Vector6Ld Vector6Ld::operator *(const long double& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number };
	}

	inline Vector6Ld Vector6Ld::operator /(const long double& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number };
	}


	// increment / decrement
	inline Vector6Ld& Vector6Ld::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f;
		return *this;
	}

	inline Vector6Ld& Vector6Ld::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f;
		return *this;
	}

	inline Vector6Ld Vector6Ld::operator++ (int) noexcept {
		Vector6Ld temp = *this;
		++* this;
		return temp;
	}

	inline Vector6Ld Vector6Ld::operator-- (int) noexcept {
		Vector6Ld temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector6Ld& Vector6Ld::operator+= (const Vector6Ld& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f;
		return *this;
	}

	inline Vector6Ld& Vector6Ld::operator-= (const Vector6Ld& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f;
		return *this;
	}

	inline Vector6Ld& Vector6Ld::operator*= (const Vector6Ld& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f;
		return *this;
	}

	inline Vector6Ld& Vector6Ld::operator/= (const Vector6Ld& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f;
		return *this;
	}


	inline Vector6Ld& Vector6Ld::operator+= (const long double& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number;
		return *this;
	}

	inline Vector6Ld& Vector6Ld::operator-= (const long double& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number;
		return *this;
	}

	inline Vector6Ld& Vector6Ld::operator*= (const long double& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number;
		return *this;
	}

	inline Vector6Ld& Vector6Ld::operator/= (const long double& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector6Ld::operator< (const Vector6Ld& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f;
	}

	inline bool Vector6Ld::operator<= (const Vector6Ld& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f;
	}

	inline bool Vector6Ld::operator>  (const Vector6Ld& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f;
	}

	inline bool Vector6Ld::operator>= (const Vector6Ld& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f;
	}


	inline bool Vector6Ld::operator<  (const long double& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number;
	}

	inline bool Vector6Ld::operator<= (const long double& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number;
	}

	inline bool Vector6Ld::operator>  (const long double& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number;
	}

	inline bool Vector6Ld::operator>= (const long double& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number;
	}


	// equal / not equal
	inline bool Vector6Ld::operator==(const Vector6Ld& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f;
	}

	inline bool Vector6Ld::operator!=(const Vector6Ld& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f;
	}

	inline bool Vector6Ld::operator==(const long double& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number;
	}

	inline bool Vector6Ld::operator!=(const long double& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number;
	}


	inline constexpr std::uint8_t Vector6Ld::size() const noexcept { return 6; }
	inline void Vector6Ld::reset(const long double& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long double& Vector6Ld::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long double& Vector6Ld::at(const std::uint8_t& index) noexcept
	{
		long double* ptr = &a;
		if (index > 5)
			return ptr[0];
		return ptr[index];
	}



	// Vector7Ld
	inline Vector7Ld::Vector7Ld(const long double& a, const long double& b, const long double& c, const long double& d,
		const long double& e, const long double& f, const long double& g) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g) {}

	// copy/move constructor and assignment
	inline Vector7Ld::Vector7Ld(const Vector7Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7Ld& Vector7Ld::operator=(const Vector7Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}

	inline Vector7Ld::Vector7Ld(Vector7Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7Ld& Vector7Ld::operator=(Vector7Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}
	// .....................................
	inline Vector7Ld& Vector7Ld::operator=(const long double& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; return *this;
	}


	inline Vector7Ld Vector7Ld::operator +(const Vector7Ld& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g };
	}

	inline Vector7Ld Vector7Ld::operator -(const Vector7Ld& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g };
	}

	inline Vector7Ld Vector7Ld::operator *(const Vector7Ld& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g };
	}

	inline Vector7Ld Vector7Ld::operator /(const Vector7Ld& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g };
	}


	inline Vector7Ld Vector7Ld::operator +(const long double& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number };
	}

	inline Vector7Ld Vector7Ld::operator -(const long double& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number };
	}

	inline Vector7Ld Vector7Ld::operator *(const long double& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number };
	}

	inline Vector7Ld Vector7Ld::operator /(const long double& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number };
	}


	// increment / decrement
	inline Vector7Ld& Vector7Ld::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g;
		return *this;
	}

	inline Vector7Ld& Vector7Ld::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g;
		return *this;
	}

	inline Vector7Ld Vector7Ld::operator++ (int) noexcept {
		Vector7Ld temp = *this;
		++* this;
		return temp;
	}

	inline Vector7Ld Vector7Ld::operator-- (int) noexcept {
		Vector7Ld temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector7Ld& Vector7Ld::operator+= (const Vector7Ld& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g;
		return *this;
	}

	inline Vector7Ld& Vector7Ld::operator-= (const Vector7Ld& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g;
		return *this;
	}

	inline Vector7Ld& Vector7Ld::operator*= (const Vector7Ld& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g;
		return *this;
	}

	inline Vector7Ld& Vector7Ld::operator/= (const Vector7Ld& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g;
		return *this;
	}


	inline Vector7Ld& Vector7Ld::operator+= (const long double& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number;
		return *this;
	}

	inline Vector7Ld& Vector7Ld::operator-= (const long double& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number;
		return *this;
	}

	inline Vector7Ld& Vector7Ld::operator*= (const long double& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number;
		return *this;
	}

	inline Vector7Ld& Vector7Ld::operator/= (const long double& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector7Ld::operator< (const Vector7Ld& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g;
	}

	inline bool Vector7Ld::operator<= (const Vector7Ld& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g;
	}

	inline bool Vector7Ld::operator>  (const Vector7Ld& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g;
	}

	inline bool Vector7Ld::operator>= (const Vector7Ld& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g;
	}


	inline bool Vector7Ld::operator<  (const long double& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number;
	}

	inline bool Vector7Ld::operator<= (const long double& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number;
	}

	inline bool Vector7Ld::operator>  (const long double& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number;
	}

	inline bool Vector7Ld::operator>= (const long double& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number;
	}


	// equal / not equal
	inline bool Vector7Ld::operator==(const Vector7Ld& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g;
	}

	inline bool Vector7Ld::operator!=(const Vector7Ld& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g;
	}

	inline bool Vector7Ld::operator==(const long double& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number;
	}

	inline bool Vector7Ld::operator!=(const long double& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number;
	}


	inline constexpr std::uint8_t Vector7Ld::size() const noexcept { return 7; }
	inline void Vector7Ld::reset(const long double& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long double& Vector7Ld::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long double& Vector7Ld::at(const std::uint8_t& index) noexcept
	{
		long double* ptr = &a;
		if (index > 6)
			return ptr[0];
		return ptr[index];
	}



	// Vector8Ld
	inline Vector8Ld::Vector8Ld(const long double& a, const long double& b, const long double& c, const long double& d,
		const long double& e, const long double& f, const long double& g, const long double& h) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h) {}

	// copy/move constructor and assignment
	inline Vector8Ld::Vector8Ld(const Vector8Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8Ld& Vector8Ld::operator=(const Vector8Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}

	inline Vector8Ld::Vector8Ld(Vector8Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8Ld& Vector8Ld::operator=(Vector8Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}
	// .....................................
	inline Vector8Ld& Vector8Ld::operator=(const long double& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; return *this;
	}


	inline Vector8Ld Vector8Ld::operator +(const Vector8Ld& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h };
	}

	inline Vector8Ld Vector8Ld::operator -(const Vector8Ld& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h };
	}

	inline Vector8Ld Vector8Ld::operator *(const Vector8Ld& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h };
	}

	inline Vector8Ld Vector8Ld::operator /(const Vector8Ld& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h };
	}


	inline Vector8Ld Vector8Ld::operator +(const long double& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number };
	}

	inline Vector8Ld Vector8Ld::operator -(const long double& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number };
	}

	inline Vector8Ld Vector8Ld::operator *(const long double& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number };
	}

	inline Vector8Ld Vector8Ld::operator /(const long double& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number };
	}


	// increment / decrement
	inline Vector8Ld& Vector8Ld::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h;
		return *this;
	}

	inline Vector8Ld& Vector8Ld::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h;
		return *this;
	}

	inline Vector8Ld Vector8Ld::operator++ (int) noexcept {
		Vector8Ld temp = *this;
		++* this;
		return temp;
	}

	inline Vector8Ld Vector8Ld::operator-- (int) noexcept {
		Vector8Ld temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector8Ld& Vector8Ld::operator+= (const Vector8Ld& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h;
		return *this;
	}

	inline Vector8Ld& Vector8Ld::operator-= (const Vector8Ld& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h;
		return *this;
	}

	inline Vector8Ld& Vector8Ld::operator*= (const Vector8Ld& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h;
		return *this;
	}

	inline Vector8Ld& Vector8Ld::operator/= (const Vector8Ld& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h;
		return *this;
	}


	inline Vector8Ld& Vector8Ld::operator+= (const long double& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number;
		return *this;
	}

	inline Vector8Ld& Vector8Ld::operator-= (const long double& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number;
		return *this;
	}

	inline Vector8Ld& Vector8Ld::operator*= (const long double& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number;
		return *this;
	}

	inline Vector8Ld& Vector8Ld::operator/= (const long double& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector8Ld::operator< (const Vector8Ld& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h;
	}

	inline bool Vector8Ld::operator<= (const Vector8Ld& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h;
	}

	inline bool Vector8Ld::operator>  (const Vector8Ld& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h;
	}

	inline bool Vector8Ld::operator>= (const Vector8Ld& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h;
	}


	inline bool Vector8Ld::operator<  (const long double& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number;
	}

	inline bool Vector8Ld::operator<= (const long double& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number;
	}

	inline bool Vector8Ld::operator>  (const long double& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number;
	}

	inline bool Vector8Ld::operator>= (const long double& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number;
	}


	// equal / not equal
	inline bool Vector8Ld::operator==(const Vector8Ld& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h;
	}

	inline bool Vector8Ld::operator!=(const Vector8Ld& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h;
	}

	inline bool Vector8Ld::operator==(const long double& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number;
	}

	inline bool Vector8Ld::operator!=(const long double& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number;
	}


	inline constexpr std::uint8_t Vector8Ld::size() const noexcept { return 8; }
	inline void Vector8Ld::reset(const long double& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long double& Vector8Ld::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long double& Vector8Ld::at(const std::uint8_t& index) noexcept
	{
		long double* ptr = &a;
		if (index > 7)
			return ptr[0];
		return ptr[index];
	}



	// Vector9Ld
	inline Vector9Ld::Vector9Ld(const long double& a, const long double& b, const long double& c, const long double& d,
		const long double& e, const long double& f, const long double& g, const long double& h,
		const long double& i) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

	// copy/move constructor and assignment
	inline Vector9Ld::Vector9Ld(const Vector9Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9Ld& Vector9Ld::operator=(const Vector9Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}

	inline Vector9Ld::Vector9Ld(Vector9Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9Ld& Vector9Ld::operator=(Vector9Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}
	// .....................................
	inline Vector9Ld& Vector9Ld::operator=(const long double& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; return *this;
	}


	inline Vector9Ld Vector9Ld::operator +(const Vector9Ld& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i };
	}

	inline Vector9Ld Vector9Ld::operator -(const Vector9Ld& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i };
	}

	inline Vector9Ld Vector9Ld::operator *(const Vector9Ld& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i };
	}

	inline Vector9Ld Vector9Ld::operator /(const Vector9Ld& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i };
	}


	inline Vector9Ld Vector9Ld::operator +(const long double& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number };
	}

	inline Vector9Ld Vector9Ld::operator -(const long double& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number };
	}

	inline Vector9Ld Vector9Ld::operator *(const long double& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number };
	}

	inline Vector9Ld Vector9Ld::operator /(const long double& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number };
	}


	// increment / decrement
	inline Vector9Ld& Vector9Ld::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i;
		return *this;
	}

	inline Vector9Ld& Vector9Ld::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i;
		return *this;
	}

	inline Vector9Ld Vector9Ld::operator++ (int) noexcept {
		Vector9Ld temp = *this;
		++* this;
		return temp;
	}

	inline Vector9Ld Vector9Ld::operator-- (int) noexcept {
		Vector9Ld temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector9Ld& Vector9Ld::operator+= (const Vector9Ld& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i;
		return *this;
	}

	inline Vector9Ld& Vector9Ld::operator-= (const Vector9Ld& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i;
		return *this;
	}

	inline Vector9Ld& Vector9Ld::operator*= (const Vector9Ld& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i;
		return *this;
	}

	inline Vector9Ld& Vector9Ld::operator/= (const Vector9Ld& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i;
		return *this;
	}


	inline Vector9Ld& Vector9Ld::operator+= (const long double& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number;
		return *this;
	}

	inline Vector9Ld& Vector9Ld::operator-= (const long double& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number;
		return *this;
	}

	inline Vector9Ld& Vector9Ld::operator*= (const long double& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number;
		return *this;
	}

	inline Vector9Ld& Vector9Ld::operator/= (const long double& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector9Ld::operator< (const Vector9Ld& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i;
	}

	inline bool Vector9Ld::operator<= (const Vector9Ld& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i;
	}

	inline bool Vector9Ld::operator>  (const Vector9Ld& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i;
	}

	inline bool Vector9Ld::operator>= (const Vector9Ld& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i;
	}


	inline bool Vector9Ld::operator<  (const long double& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number;
	}

	inline bool Vector9Ld::operator<= (const long double& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number;
	}

	inline bool Vector9Ld::operator>  (const long double& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number;
	}

	inline bool Vector9Ld::operator>= (const long double& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number;
	}


	// equal / not equal
	inline bool Vector9Ld::operator==(const Vector9Ld& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i;
	}

	inline bool Vector9Ld::operator!=(const Vector9Ld& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i;
	}

	inline bool Vector9Ld::operator==(const long double& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number;
	}

	inline bool Vector9Ld::operator!=(const long double& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number;
	}


	inline constexpr std::uint8_t Vector9Ld::size() const noexcept { return 9; }
	inline void Vector9Ld::reset(const long double& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long double& Vector9Ld::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long double& Vector9Ld::at(const std::uint8_t& index) noexcept
	{
		long double* ptr = &a;
		if (index > 8)
			return ptr[0];
		return ptr[index];
	}



	// Vector10Ld
	inline Vector10Ld::Vector10Ld(const long double& a, const long double& b, const long double& c, const long double& d,
		const long double& e, const long double& f, const long double& g, const long double& h,
		const long double& i, const long double& j) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {}

	// copy/move constructor and assignment
	inline Vector10Ld::Vector10Ld(const Vector10Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10Ld& Vector10Ld::operator=(const Vector10Ld& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}

	inline Vector10Ld::Vector10Ld(Vector10Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10Ld& Vector10Ld::operator=(Vector10Ld&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}
	// .....................................
	inline Vector10Ld& Vector10Ld::operator=(const long double& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; j = number; return *this;
	}


	inline Vector10Ld Vector10Ld::operator +(const Vector10Ld& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i, j + v.j };
	}

	inline Vector10Ld Vector10Ld::operator -(const Vector10Ld& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i, j - v.j };
	}

	inline Vector10Ld Vector10Ld::operator *(const Vector10Ld& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i, j * v.j };
	}

	inline Vector10Ld Vector10Ld::operator /(const Vector10Ld& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i, j / v.j };
	}


	inline Vector10Ld Vector10Ld::operator +(const long double& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number, j + number };
	}

	inline Vector10Ld Vector10Ld::operator -(const long double& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number, j - number };
	}

	inline Vector10Ld Vector10Ld::operator *(const long double& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number, j * number };
	}

	inline Vector10Ld Vector10Ld::operator /(const long double& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number, j / number };
	}


	// increment / decrement
	inline Vector10Ld& Vector10Ld::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i; ++j;
		return *this;
	}

	inline Vector10Ld& Vector10Ld::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i; --j;
		return *this;
	}

	inline Vector10Ld Vector10Ld::operator++ (int) noexcept {
		Vector10Ld temp = *this;
		++* this;
		return temp;
	}

	inline Vector10Ld Vector10Ld::operator-- (int) noexcept {
		Vector10Ld temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector10Ld& Vector10Ld::operator+= (const Vector10Ld& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i; j += right.j;
		return *this;
	}

	inline Vector10Ld& Vector10Ld::operator-= (const Vector10Ld& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i; j -= right.j;
		return *this;
	}

	inline Vector10Ld& Vector10Ld::operator*= (const Vector10Ld& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i; j *= right.j;
		return *this;
	}

	inline Vector10Ld& Vector10Ld::operator/= (const Vector10Ld& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i; j /= right.j;
		return *this;
	}


	inline Vector10Ld& Vector10Ld::operator+= (const long double& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number; j += number;
		return *this;
	}

	inline Vector10Ld& Vector10Ld::operator-= (const long double& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number; j -= number;
		return *this;
	}

	inline Vector10Ld& Vector10Ld::operator*= (const long double& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number; j *= number;
		return *this;
	}

	inline Vector10Ld& Vector10Ld::operator/= (const long double& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number; j /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector10Ld::operator< (const Vector10Ld& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i&& j < other.j;
	}

	inline bool Vector10Ld::operator<= (const Vector10Ld& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i && j <= other.j;
	}

	inline bool Vector10Ld::operator>  (const Vector10Ld& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i && j > other.j;
	}

	inline bool Vector10Ld::operator>= (const Vector10Ld& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i && j >= other.j;
	}


	inline bool Vector10Ld::operator<  (const long double& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number && j < number;
	}

	inline bool Vector10Ld::operator<= (const long double& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number && j <= number;
	}

	inline bool Vector10Ld::operator>  (const long double& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number && j > number;
	}

	inline bool Vector10Ld::operator>= (const long double& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number && j >= number;
	}


	// equal / not equal
	inline bool Vector10Ld::operator==(const Vector10Ld& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i && j == other.j;
	}

	inline bool Vector10Ld::operator!=(const Vector10Ld& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i || j != other.j;
	}

	inline bool Vector10Ld::operator==(const long double& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number && j == number;
	}

	inline bool Vector10Ld::operator!=(const long double& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number || j != number;
	}


	inline constexpr std::uint8_t Vector10Ld::size() const noexcept { return 10; }
	inline void Vector10Ld::reset(const long double& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long double& Vector10Ld::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long double& Vector10Ld::at(const std::uint8_t& index) noexcept
	{
		long double* ptr = &a;
		if (index > 9)
			return ptr[0];
		return ptr[index];
	}
	// End
}