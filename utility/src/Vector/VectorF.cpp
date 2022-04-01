#include "VectorF.h"

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::float_t
		Bytes: 4
		Range: 3.4E +/- 38  precision: (7 digits)
	*/

	// Vector2f
	inline Vector2f::Vector2f(const std::float_t& x, const std::float_t& y) noexcept
		: x(x), y(y) {}

	// copy/move constructor and assignment
	inline Vector2f::Vector2f(const Vector2f& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2f& Vector2f::operator=(const Vector2f& other) noexcept {
		x = other.x; y = other.y; return *this;
	}

	inline Vector2f::Vector2f(Vector2f&& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2f& Vector2f::operator=(Vector2f&& other) noexcept {
		x = other.x; y = other.y; return *this;
	}
	// .....................................
	inline Vector2f& Vector2f::operator=(const std::float_t& number) noexcept {
		x = number; y = number; return *this;
	}


	inline Vector2f Vector2f::operator +(const Vector2f& v) const noexcept {
		return { x + v.x, y + v.y };
	}

	inline Vector2f Vector2f::operator -(const Vector2f& v) const noexcept {
		return { x - v.x, y - v.y };
	}

	inline Vector2f Vector2f::operator *(const Vector2f& v) const noexcept {
		return { x * v.x, y * v.y };
	}

	inline Vector2f Vector2f::operator /(const Vector2f& v) const noexcept {
		return { x / v.x, y / v.y };
	}


	inline Vector2f Vector2f::operator +(const std::float_t& number) const noexcept {
		return { x + number, y + number };
	}

	inline Vector2f Vector2f::operator -(const std::float_t& number) const noexcept {
		return { x - number, y - number };
	}

	inline Vector2f Vector2f::operator *(const std::float_t& number) const noexcept {
		return { x * number, y * number };
	}

	inline Vector2f Vector2f::operator /(const std::float_t& number) const noexcept {
		return { x / number, y / number };
	}


	// increment / decrement
	inline Vector2f& Vector2f::operator++ () noexcept {
		++x; ++y;
		return *this;
	}

	inline Vector2f& Vector2f::operator-- ()  noexcept {
		--x; --y;
		return *this;
	}

	inline Vector2f Vector2f::operator++ (int) noexcept {
		Vector2f temp = *this;
		++* this;
		return temp;
	}

	inline Vector2f Vector2f::operator-- (int) noexcept {
		Vector2f temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector2f& Vector2f::operator+= (const Vector2f& right) noexcept {
		x += right.x; y += right.y;
		return *this;
	}

	inline Vector2f& Vector2f::operator-= (const Vector2f& right) noexcept {
		x -= right.x; y -= right.y;
		return *this;
	}

	inline Vector2f& Vector2f::operator*= (const Vector2f& right) noexcept {
		x *= right.x; y *= right.y;
		return *this;
	}

	inline Vector2f& Vector2f::operator/= (const Vector2f& right) noexcept {
		x /= right.x; y /= right.y;
		return *this;
	}


	inline Vector2f& Vector2f::operator+= (const std::float_t& number) noexcept {
		x += number; y += number;
		return *this;
	}

	inline Vector2f& Vector2f::operator-= (const std::float_t& number) noexcept {
		x -= number; y -= number;
		return *this;
	}

	inline Vector2f& Vector2f::operator*= (const std::float_t& number) noexcept {
		x *= number; y *= number;
		return *this;
	}

	inline Vector2f& Vector2f::operator/= (const std::float_t& number) noexcept {
		x /= number; y /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector2f::operator< (const Vector2f& other) const noexcept {
		return x < other.x && y < other.y;
	}

	inline bool Vector2f::operator<= (const Vector2f& other) const noexcept {
		return x <= other.x && y <= other.y;
	}

	inline bool Vector2f::operator>  (const Vector2f& other) const noexcept {
		return x > other.x && y > other.y;
	}

	inline bool Vector2f::operator>= (const Vector2f& other) const noexcept {
		return x >= other.x && y >= other.y;
	}


	inline bool Vector2f::operator<  (const std::float_t& number) const noexcept {
		return x < number && y < number;
	}

	inline bool Vector2f::operator<= (const std::float_t& number) const noexcept {
		return x <= number && y <= number;
	}

	inline bool Vector2f::operator>  (const std::float_t& number) const noexcept {
		return x > number && y > number;
	}

	inline bool Vector2f::operator>= (const std::float_t& number) const noexcept {
		return x >= number && y >= number;
	}


	// equal / not equal
	inline bool Vector2f::operator==(const Vector2f& other) const noexcept {
		return x == other.x && y == other.y;
	}

	inline bool Vector2f::operator!=(const Vector2f& other) const noexcept {
		return x != other.x || y != other.y;
	}

	inline bool Vector2f::operator==(const std::float_t& number) const noexcept {
		return x == number && y == number;
	}

	inline bool Vector2f::operator!=(const std::float_t& number) const noexcept {
		return x != number || y != number;
	}


	inline constexpr std::uint8_t Vector2f::size() const noexcept { return 2; }
	inline void Vector2f::reset(const std::float_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::float_t& Vector2f::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::float_t& Vector2f::at(const std::uint8_t& index) noexcept
	{
		std::float_t* ptr = &x;
		if (index > 1)
			return ptr[0];
		return ptr[index];
	}



	// Vector3f
	inline Vector3f::Vector3f(const std::float_t& x, const std::float_t& y, const std::float_t& z) noexcept
		: x(x), y(y), z(z) {}

	// copy/move constructor and assignment
	inline Vector3f::Vector3f(const Vector3f& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3f& Vector3f::operator=(const Vector3f& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}

	inline Vector3f::Vector3f(Vector3f&& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3f& Vector3f::operator=(Vector3f&& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}
	// .....................................
	inline Vector3f& Vector3f::operator=(const std::float_t& number) noexcept {
		x = number; y = number; z = number; return *this;
	}


	inline Vector3f Vector3f::operator +(const Vector3f& v) const noexcept {
		return { x + v.x, y + v.y, z + v.z };
	}

	inline Vector3f Vector3f::operator -(const Vector3f& v) const noexcept {
		return { x - v.x, y - v.y, z - v.z };
	}

	inline Vector3f Vector3f::operator *(const Vector3f& v) const noexcept {
		return { x * v.x, y * v.y, z * v.z };
	}

	inline Vector3f Vector3f::operator /(const Vector3f& v) const noexcept {
		return { x / v.x, y / v.y, z / v.z };
	}

 
	inline Vector3f Vector3f::operator +(const std::float_t& number) const noexcept {
		return { x + number, y + number, z + number };
	}

	inline Vector3f Vector3f::operator -(const std::float_t& number) const noexcept {
		return { x - number, y - number, z - number };
	}

	inline Vector3f Vector3f::operator *(const std::float_t& number) const noexcept {
		return { x * number, y * number, z * number };
	}

	inline Vector3f Vector3f::operator /(const std::float_t& number) const noexcept {
		return { x / number, y / number, z / number };
	}


	// increment / decrement
	inline Vector3f& Vector3f::operator++ () noexcept {
		++x; ++y; ++z;
		return *this;
	}

	inline Vector3f& Vector3f::operator-- () noexcept {
		--x; --y; --z;
		return *this;
	}

	inline Vector3f Vector3f::operator++ (int) noexcept {
		Vector3f temp = *this;
		++* this;
		return temp;
	}

	inline Vector3f Vector3f::operator-- (int) noexcept {
		Vector3f temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector3f& Vector3f::operator+= (const Vector3f& right) noexcept {
		x += right.x; y += right.y; z += right.z;
		return *this;
	}

	inline Vector3f& Vector3f::operator-= (const Vector3f& right) noexcept {
		x -= right.x; y -= right.y; z -= right.z;
		return *this;
	}

	inline Vector3f& Vector3f::operator*= (const Vector3f& right) noexcept {
		x *= right.x; y *= right.y; z *= right.z;
		return *this;
	}

	inline Vector3f& Vector3f::operator/= (const Vector3f& right) noexcept {
		x /= right.x; y /= right.y; z /= right.z;
		return *this;
	}


	inline Vector3f& Vector3f::operator+= (const std::float_t& number) noexcept {
		x += number; y += number; z += number;
		return *this;
	}

	inline Vector3f& Vector3f::operator-= (const std::float_t& number) noexcept {
		x -= number; y -= number; z -= number;
		return *this;
	}

	inline Vector3f& Vector3f::operator*= (const std::float_t& number) noexcept {
		x *= number; y *= number; z *= number;
		return *this;
	}

	inline Vector3f& Vector3f::operator/= (const std::float_t& number) noexcept {
		x /= number; y /= number; z /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector3f::operator< (const Vector3f& other) const noexcept {
		return x < other.x && y < other.y&& z < other.z;
	}

	inline bool Vector3f::operator<= (const Vector3f& other) const noexcept {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	inline bool Vector3f::operator>  (const Vector3f& other) const noexcept {
		return x > other.x && y > other.y && z > other.z;
	}

	inline bool Vector3f::operator>= (const Vector3f& other) const noexcept {
		return x >= other.x && y >= other.y && z >= other.z;
	}


	inline bool Vector3f::operator<  (const std::float_t& number) const noexcept {
		return x < number && y < number && z < number;
	}

	inline bool Vector3f::operator<= (const std::float_t& number) const noexcept {
		return x <= number && y <= number && z <= number;
	}

	inline bool Vector3f::operator>  (const std::float_t& number) const noexcept {
		return x > number && y > number && z > number;
	}

	inline bool Vector3f::operator>= (const std::float_t& number) const noexcept {
		return x >= number && y >= number && z >= number;
	}


	// equal / not equal
	inline bool Vector3f::operator==(const Vector3f& other) const noexcept {
		return x == other.x && y == other.y && z == other.z;
	}

	inline bool Vector3f::operator!=(const Vector3f& other) const noexcept {
		return x != other.x || y != other.y || z != other.z;
	}

	inline bool Vector3f::operator==(const std::float_t& number) const noexcept {
		return x == number && y == number && z == number;
	}

	inline bool Vector3f::operator!=(const std::float_t& number) const noexcept {
		return x != number || y != number || z != number;
	}


	inline constexpr std::uint8_t Vector3f::size() const noexcept { return 3; }
	inline void Vector3f::reset(const std::float_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::float_t& Vector3f::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::float_t& Vector3f::at(const std::uint8_t& index) noexcept
	{
		std::float_t* ptr = &x;
		if (index > 2)
			return ptr[0];
		return ptr[index];
	}



	// Vector4f
	inline Vector4f::Vector4f(const std::float_t& a, const std::float_t& b, const std::float_t& c, const std::float_t& d) noexcept
		: a(a), b(b), c(c), d(d) {}

	// copy/move constructor and assignment
	inline Vector4f::Vector4f(const Vector4f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4f& Vector4f::operator=(const Vector4f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}

	inline Vector4f::Vector4f(Vector4f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4f& Vector4f::operator=(Vector4f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}
	// .....................................
	inline Vector4f& Vector4f::operator=(const std::float_t& number) noexcept {
		a = number; b = number; c = number; d = number; return *this;
	}


	inline Vector4f Vector4f::operator +(const Vector4f& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d };
	}

	inline Vector4f Vector4f::operator -(const Vector4f& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d };
	}

	inline Vector4f Vector4f::operator *(const Vector4f& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d };
	}

	inline Vector4f Vector4f::operator /(const Vector4f& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d };
	}


	inline Vector4f Vector4f::operator +(const std::float_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number };
	}

	inline Vector4f Vector4f::operator -(const std::float_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number };
	}

	inline Vector4f Vector4f::operator *(const std::float_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number };
	}

	inline Vector4f Vector4f::operator /(const std::float_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number };
	}


	// increment / decrement
	inline Vector4f& Vector4f::operator++ () noexcept {
		++a; ++b; ++c; ++d;
		return *this;
	}

	inline Vector4f& Vector4f::operator-- () noexcept {
		--a; --b; --c; --d;
		return *this;
	}

	inline Vector4f Vector4f::operator++ (int) noexcept {
		Vector4f temp = *this;
		++* this;
		return temp;
	}

	inline Vector4f Vector4f::operator-- (int) noexcept {
		Vector4f temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector4f& Vector4f::operator+= (const Vector4f& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d;
		return *this;
	}

	inline Vector4f& Vector4f::operator-= (const Vector4f& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d;
		return *this;
	}

	inline Vector4f& Vector4f::operator*= (const Vector4f& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d;
		return *this;
	}

	inline Vector4f& Vector4f::operator/= (const Vector4f& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d;
		return *this;
	}


	inline Vector4f& Vector4f::operator+= (const std::float_t& number) noexcept {
		a += number; b += number; c += number; d += number;
		return *this;
	}

	inline Vector4f& Vector4f::operator-= (const std::float_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number;
		return *this;
	}

	inline Vector4f& Vector4f::operator*= (const std::float_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number;
		return *this;
	}

	inline Vector4f& Vector4f::operator/= (const std::float_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector4f::operator< (const Vector4f& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d;
	}

	inline bool Vector4f::operator<= (const Vector4f& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d;
	}

	inline bool Vector4f::operator>  (const Vector4f& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d;
	}

	inline bool Vector4f::operator>= (const Vector4f& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d;
	}


	inline bool Vector4f::operator<  (const std::float_t& number) const noexcept {
		return a < number && b < number && c < number && d < number;
	}

	inline bool Vector4f::operator<= (const std::float_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number;
	}

	inline bool Vector4f::operator>  (const std::float_t& number) const noexcept {
		return a > number && b > number && c > number && d > number;
	}

	inline bool Vector4f::operator>= (const std::float_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number;
	}


	// equal / not equal
	inline bool Vector4f::operator==(const Vector4f& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d;
	}

	inline bool Vector4f::operator!=(const Vector4f& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d;
	}

	inline bool Vector4f::operator==(const std::float_t& number) const noexcept {
		return a == number && b == number && c == number && d == number;
	}

	inline bool Vector4f::operator!=(const std::float_t& number) const noexcept {
		return a != number || b != number || c != number || d != number;
	}


	inline constexpr std::uint8_t Vector4f::size() const noexcept { return 4; }
	inline void Vector4f::reset(const std::float_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::float_t& Vector4f::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::float_t& Vector4f::at(const std::uint8_t& index) noexcept
	{
		std::float_t* ptr = &a;
		if (index > 3)
			return ptr[0];
		return ptr[index];
	}



	// Vector5f
	inline Vector5f::Vector5f(const std::float_t& a, const std::float_t& b, const std::float_t& c, const std::float_t& d,
		const std::float_t& e) noexcept
		: a(a), b(b), c(c), d(d), e(e) {}

	// copy/move constructor and assignment
	inline Vector5f::Vector5f(const Vector5f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5f& Vector5f::operator=(const Vector5f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}

	inline Vector5f::Vector5f(Vector5f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5f& Vector5f::operator=(Vector5f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}
	// .....................................
	inline Vector5f& Vector5f::operator=(const std::float_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; return *this;
	}


	inline Vector5f Vector5f::operator +(const Vector5f& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e };
	}

	inline Vector5f Vector5f::operator -(const Vector5f& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e };
	}

	inline Vector5f Vector5f::operator *(const Vector5f& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e };
	}

	inline Vector5f Vector5f::operator /(const Vector5f& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e };
	}


	inline Vector5f Vector5f::operator +(const std::float_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number };
	}

	inline Vector5f Vector5f::operator -(const std::float_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number };
	}

	inline Vector5f Vector5f::operator *(const std::float_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number };
	}

	inline Vector5f Vector5f::operator /(const std::float_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number };
	}


	// increment / decrement
	inline Vector5f& Vector5f::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e;
		return *this;
	}

	inline Vector5f& Vector5f::operator-- () noexcept {
		--a; --b; --c; --d; --e;
		return *this;
	}

	inline Vector5f Vector5f::operator++ (int) noexcept {
		Vector5f temp = *this;
		++* this;
		return temp;
	}

	inline Vector5f Vector5f::operator-- (int) noexcept {
		Vector5f temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector5f& Vector5f::operator+= (const Vector5f& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e;
		return *this;
	}

	inline Vector5f& Vector5f::operator-= (const Vector5f& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e;
		return *this;
	}

	inline Vector5f& Vector5f::operator*= (const Vector5f& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e;
		return *this;
	}

	inline Vector5f& Vector5f::operator/= (const Vector5f& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e;
		return *this;
	}


	inline Vector5f& Vector5f::operator+= (const std::float_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number;
		return *this;
	}

	inline Vector5f& Vector5f::operator-= (const std::float_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number;
		return *this;
	}

	inline Vector5f& Vector5f::operator*= (const std::float_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number;
		return *this;
	}

	inline Vector5f& Vector5f::operator/= (const std::float_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector5f::operator< (const Vector5f& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e;
	}

	inline bool Vector5f::operator<= (const Vector5f& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e;
	}

	inline bool Vector5f::operator>  (const Vector5f& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e;
	}

	inline bool Vector5f::operator>= (const Vector5f& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e;
	}


	inline bool Vector5f::operator<  (const std::float_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number;
	}

	inline bool Vector5f::operator<= (const std::float_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number;
	}

	inline bool Vector5f::operator>  (const std::float_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number;
	}

	inline bool Vector5f::operator>= (const std::float_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number;
	}


	// equal / not equal
	inline bool Vector5f::operator==(const Vector5f& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
	}

	inline bool Vector5f::operator!=(const Vector5f& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e;
	}

	inline bool Vector5f::operator==(const std::float_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number;
	}

	inline bool Vector5f::operator!=(const std::float_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number;
	}


	inline constexpr std::uint8_t Vector5f::size() const noexcept { return 5; }
	inline void Vector5f::reset(const std::float_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::float_t& Vector5f::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::float_t& Vector5f::at(const std::uint8_t& index) noexcept
	{
		std::float_t* ptr = &a;
		if (index > 4)
			return ptr[0];
		return ptr[index];
	}



	// Vector6f
	inline Vector6f::Vector6f(const std::float_t& a, const std::float_t& b, const std::float_t& c, const std::float_t& d,
		const std::float_t& e, const std::float_t& f) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f) {}

	// copy/move constructor and assignment
	inline Vector6f::Vector6f(const Vector6f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6f& Vector6f::operator=(const Vector6f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}

	inline Vector6f::Vector6f(Vector6f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6f& Vector6f::operator=(Vector6f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}
	// .....................................
	inline Vector6f& Vector6f::operator=(const std::float_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; return *this;
	}


	inline Vector6f Vector6f::operator +(const Vector6f& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f };
	}

	inline Vector6f Vector6f::operator -(const Vector6f& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f };
	}

	inline Vector6f Vector6f::operator *(const Vector6f& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f };
	}

	inline Vector6f Vector6f::operator /(const Vector6f& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f };
	}


	inline Vector6f Vector6f::operator +(const std::float_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number };
	}

	inline Vector6f Vector6f::operator -(const std::float_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number };
	}

	inline Vector6f Vector6f::operator *(const std::float_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number };
	}

	inline Vector6f Vector6f::operator /(const std::float_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number };
	}


	// increment / decrement
	inline Vector6f& Vector6f::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f;
		return *this;
	}

	inline Vector6f& Vector6f::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f;
		return *this;
	}

	inline Vector6f Vector6f::operator++ (int) noexcept {
		Vector6f temp = *this;
		++* this;
		return temp;
	}

	inline Vector6f Vector6f::operator-- (int) noexcept {
		Vector6f temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector6f& Vector6f::operator+= (const Vector6f& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f;
		return *this;
	}

	inline Vector6f& Vector6f::operator-= (const Vector6f& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f;
		return *this;
	}

	inline Vector6f& Vector6f::operator*= (const Vector6f& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f;
		return *this;
	}

	inline Vector6f& Vector6f::operator/= (const Vector6f& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f;
		return *this;
	}


	inline Vector6f& Vector6f::operator+= (const std::float_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number;
		return *this;
	}

	inline Vector6f& Vector6f::operator-= (const std::float_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number;
		return *this;
	}

	inline Vector6f& Vector6f::operator*= (const std::float_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number;
		return *this;
	}

	inline Vector6f& Vector6f::operator/= (const std::float_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector6f::operator< (const Vector6f& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f;
	}

	inline bool Vector6f::operator<= (const Vector6f& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f;
	}

	inline bool Vector6f::operator>  (const Vector6f& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f;
	}

	inline bool Vector6f::operator>= (const Vector6f& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f;
	}


	inline bool Vector6f::operator<  (const std::float_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number;
	}

	inline bool Vector6f::operator<= (const std::float_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number;
	}

	inline bool Vector6f::operator>  (const std::float_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number;
	}

	inline bool Vector6f::operator>= (const std::float_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number;
	}


	// equal / not equal
	inline bool Vector6f::operator==(const Vector6f& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f;
	}

	inline bool Vector6f::operator!=(const Vector6f& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f;
	}

	inline bool Vector6f::operator==(const std::float_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number;
	}

	inline bool Vector6f::operator!=(const std::float_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number;
	}


	inline constexpr std::uint8_t Vector6f::size() const noexcept { return 6; }
	inline void Vector6f::reset(const std::float_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::float_t& Vector6f::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::float_t& Vector6f::at(const std::uint8_t& index) noexcept
	{
		std::float_t* ptr = &a;
		if (index > 5)
			return ptr[0];
		return ptr[index];
	}



	// Vector7f
	inline Vector7f::Vector7f(const std::float_t& a, const std::float_t& b, const std::float_t& c, const std::float_t& d,
		const std::float_t& e, const std::float_t& f, const std::float_t& g) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g) {}

	// copy/move constructor and assignment
	inline Vector7f::Vector7f(const Vector7f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7f& Vector7f::operator=(const Vector7f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}

	inline Vector7f::Vector7f(Vector7f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7f& Vector7f::operator=(Vector7f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}
	// .....................................
	inline Vector7f& Vector7f::operator=(const std::float_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; return *this;
	}


	inline Vector7f Vector7f::operator +(const Vector7f& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g };
	}

	inline Vector7f Vector7f::operator -(const Vector7f& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g };
	}

	inline Vector7f Vector7f::operator *(const Vector7f& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g };
	}

	inline Vector7f Vector7f::operator /(const Vector7f& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g };
	}


	inline Vector7f Vector7f::operator +(const std::float_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number };
	}

	inline Vector7f Vector7f::operator -(const std::float_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number };
	}

	inline Vector7f Vector7f::operator *(const std::float_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number };
	}

	inline Vector7f Vector7f::operator /(const std::float_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number };
	}


	// increment / decrement
	inline Vector7f& Vector7f::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g;
		return *this;
	}

	inline Vector7f& Vector7f::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g;
		return *this;
	}

	inline Vector7f Vector7f::operator++ (int) noexcept {
		Vector7f temp = *this;
		++* this;
		return temp;
	}

	inline Vector7f Vector7f::operator-- (int) noexcept {
		Vector7f temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector7f& Vector7f::operator+= (const Vector7f& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g;
		return *this;
	}

	inline Vector7f& Vector7f::operator-= (const Vector7f& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g;
		return *this;
	}

	inline Vector7f& Vector7f::operator*= (const Vector7f& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g;
		return *this;
	}

	inline Vector7f& Vector7f::operator/= (const Vector7f& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g;
		return *this;
	}


	inline Vector7f& Vector7f::operator+= (const std::float_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number;
		return *this;
	}

	inline Vector7f& Vector7f::operator-= (const std::float_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number;
		return *this;
	}

	inline Vector7f& Vector7f::operator*= (const std::float_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number;
		return *this;
	}

	inline Vector7f& Vector7f::operator/= (const std::float_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector7f::operator< (const Vector7f& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g;
	}

	inline bool Vector7f::operator<= (const Vector7f& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g;
	}

	inline bool Vector7f::operator>  (const Vector7f& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g;
	}

	inline bool Vector7f::operator>= (const Vector7f& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g;
	}


	inline bool Vector7f::operator<  (const std::float_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number;
	}

	inline bool Vector7f::operator<= (const std::float_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number;
	}

	inline bool Vector7f::operator>  (const std::float_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number;
	}

	inline bool Vector7f::operator>= (const std::float_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number;
	}


	// equal / not equal
	inline bool Vector7f::operator==(const Vector7f& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g;
	}

	inline bool Vector7f::operator!=(const Vector7f& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g;
	}

	inline bool Vector7f::operator==(const std::float_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number;
	}

	inline bool Vector7f::operator!=(const std::float_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number;
	}


	inline constexpr std::uint8_t Vector7f::size() const noexcept { return 7; }
	inline void Vector7f::reset(const std::float_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::float_t& Vector7f::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::float_t& Vector7f::at(const std::uint8_t& index) noexcept
	{
		std::float_t* ptr = &a;
		if (index > 6)
			return ptr[0];
		return ptr[index];
	}



	// Vector8f
	inline Vector8f::Vector8f(const std::float_t& a, const std::float_t& b, const std::float_t& c, const std::float_t& d,
		const std::float_t& e, const std::float_t& f, const std::float_t& g, const std::float_t& h) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h) {}

	// copy/move constructor and assignment
	inline Vector8f::Vector8f(const Vector8f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8f& Vector8f::operator=(const Vector8f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}

	inline Vector8f::Vector8f(Vector8f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8f& Vector8f::operator=(Vector8f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}
	// .....................................
	inline Vector8f& Vector8f::operator=(const std::float_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; return *this;
	}


	inline Vector8f Vector8f::operator +(const Vector8f& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h };
	}

	inline Vector8f Vector8f::operator -(const Vector8f& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h };
	}

	inline Vector8f Vector8f::operator *(const Vector8f& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h };
	}

	inline Vector8f Vector8f::operator /(const Vector8f& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h };
	}


	inline Vector8f Vector8f::operator +(const std::float_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number };
	}

	inline Vector8f Vector8f::operator -(const std::float_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number };
	}

	inline Vector8f Vector8f::operator *(const std::float_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number };
	}

	inline Vector8f Vector8f::operator /(const std::float_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number };
	}


	// increment / decrement
	inline Vector8f& Vector8f::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h;
		return *this;
	}

	inline Vector8f& Vector8f::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h;
		return *this;
	}

	inline Vector8f Vector8f::operator++ (int) noexcept {
		Vector8f temp = *this;
		++* this;
		return temp;
	}

	inline Vector8f Vector8f::operator-- (int) noexcept {
		Vector8f temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector8f& Vector8f::operator+= (const Vector8f& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h;
		return *this;
	}

	inline Vector8f& Vector8f::operator-= (const Vector8f& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h;
		return *this;
	}

	inline Vector8f& Vector8f::operator*= (const Vector8f& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h;
		return *this;
	}

	inline Vector8f& Vector8f::operator/= (const Vector8f& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h;
		return *this;
	}


	inline Vector8f& Vector8f::operator+= (const std::float_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number;
		return *this;
	}

	inline Vector8f& Vector8f::operator-= (const std::float_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number;
		return *this;
	}

	inline Vector8f& Vector8f::operator*= (const std::float_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number;
		return *this;
	}

	inline Vector8f& Vector8f::operator/= (const std::float_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector8f::operator< (const Vector8f& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h;
	}

	inline bool Vector8f::operator<= (const Vector8f& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h;
	}

	inline bool Vector8f::operator>  (const Vector8f& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h;
	}

	inline bool Vector8f::operator>= (const Vector8f& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h;
	}


	inline bool Vector8f::operator<  (const std::float_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number;
	}

	inline bool Vector8f::operator<= (const std::float_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number;
	}

	inline bool Vector8f::operator>  (const std::float_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number;
	}

	inline bool Vector8f::operator>= (const std::float_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number;
	}


	// equal / not equal
	inline bool Vector8f::operator==(const Vector8f& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h;
	}

	inline bool Vector8f::operator!=(const Vector8f& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h;
	}

	inline bool Vector8f::operator==(const std::float_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number;
	}

	inline bool Vector8f::operator!=(const std::float_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number;
	}


	inline constexpr std::uint8_t Vector8f::size() const noexcept { return 8; }
	inline void Vector8f::reset(const std::float_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::float_t& Vector8f::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::float_t& Vector8f::at(const std::uint8_t& index) noexcept
	{
		std::float_t* ptr = &a;
		if (index > 7)
			return ptr[0];
		return ptr[index];
	}



	// Vector9f
	inline Vector9f::Vector9f(const std::float_t& a, const std::float_t& b, const std::float_t& c, const std::float_t& d,
		const std::float_t& e, const std::float_t& f, const std::float_t& g, const std::float_t& h,
		const std::float_t& i) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

	// copy/move constructor and assignment
	inline Vector9f::Vector9f(const Vector9f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9f& Vector9f::operator=(const Vector9f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}

	inline Vector9f::Vector9f(Vector9f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9f& Vector9f::operator=(Vector9f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}
	// .....................................
	inline Vector9f& Vector9f::operator=(const std::float_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; return *this;
	}


	inline Vector9f Vector9f::operator +(const Vector9f& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i };
	}

	inline Vector9f Vector9f::operator -(const Vector9f& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i };
	}

	inline Vector9f Vector9f::operator *(const Vector9f& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i };
	}

	inline Vector9f Vector9f::operator /(const Vector9f& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i };
	}


	inline Vector9f Vector9f::operator +(const std::float_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number };
	}

	inline Vector9f Vector9f::operator -(const std::float_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number };
	}

	inline Vector9f Vector9f::operator *(const std::float_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number };
	}

	inline Vector9f Vector9f::operator /(const std::float_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number };
	}


	// increment / decrement
	inline Vector9f& Vector9f::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i;
		return *this;
	}

	inline Vector9f& Vector9f::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i;
		return *this;
	}

	inline Vector9f Vector9f::operator++ (int) noexcept {
		Vector9f temp = *this;
		++* this;
		return temp;
	}

	inline Vector9f Vector9f::operator-- (int) noexcept {
		Vector9f temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector9f& Vector9f::operator+= (const Vector9f& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i;
		return *this;
	}

	inline Vector9f& Vector9f::operator-= (const Vector9f& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i;
		return *this;
	}

	inline Vector9f& Vector9f::operator*= (const Vector9f& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i;
		return *this;
	}

	inline Vector9f& Vector9f::operator/= (const Vector9f& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i;
		return *this;
	}


	inline Vector9f& Vector9f::operator+= (const std::float_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number;
		return *this;
	}

	inline Vector9f& Vector9f::operator-= (const std::float_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number;
		return *this;
	}

	inline Vector9f& Vector9f::operator*= (const std::float_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number;
		return *this;
	}

	inline Vector9f& Vector9f::operator/= (const std::float_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector9f::operator< (const Vector9f& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i;
	}

	inline bool Vector9f::operator<= (const Vector9f& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i;
	}

	inline bool Vector9f::operator>  (const Vector9f& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i;
	}

	inline bool Vector9f::operator>= (const Vector9f& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i;
	}


	inline bool Vector9f::operator<  (const std::float_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number;
	}

	inline bool Vector9f::operator<= (const std::float_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number;
	}

	inline bool Vector9f::operator>  (const std::float_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number;
	}

	inline bool Vector9f::operator>= (const std::float_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number;
	}


	// equal / not equal
	inline bool Vector9f::operator==(const Vector9f& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i;
	}

	inline bool Vector9f::operator!=(const Vector9f& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i;
	}

	inline bool Vector9f::operator==(const std::float_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number;
	}

	inline bool Vector9f::operator!=(const std::float_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number;
	}


	inline constexpr std::uint8_t Vector9f::size() const noexcept { return 9; }
	inline void Vector9f::reset(const std::float_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::float_t& Vector9f::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::float_t& Vector9f::at(const std::uint8_t& index) noexcept
	{
		std::float_t* ptr = &a;
		if (index > 8)
			return ptr[0];
		return ptr[index];
	}



	// Vector10f
	inline Vector10f::Vector10f(const std::float_t& a, const std::float_t& b, const std::float_t& c, const std::float_t& d,
		const std::float_t& e, const std::float_t& f, const std::float_t& g, const std::float_t& h,
		const std::float_t& i, const std::float_t& j) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {}

	// copy/move constructor and assignment
	inline Vector10f::Vector10f(const Vector10f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10f& Vector10f::operator=(const Vector10f& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}

	inline Vector10f::Vector10f(Vector10f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10f& Vector10f::operator=(Vector10f&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}
	// .....................................
	inline Vector10f& Vector10f::operator=(const std::float_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; j = number; return *this;
	}


	inline Vector10f Vector10f::operator +(const Vector10f& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i, j + v.j };
	}

	inline Vector10f Vector10f::operator -(const Vector10f& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i, j - v.j };
	}

	inline Vector10f Vector10f::operator *(const Vector10f& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i, j * v.j };
	}

	inline Vector10f Vector10f::operator /(const Vector10f& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i, j / v.j };
	}


	inline Vector10f Vector10f::operator +(const std::float_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number, j + number };
	}

	inline Vector10f Vector10f::operator -(const std::float_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number, j - number };
	}

	inline Vector10f Vector10f::operator *(const std::float_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number, j * number };
	}

	inline Vector10f Vector10f::operator /(const std::float_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number, j / number };
	}


	// increment / decrement
	inline Vector10f& Vector10f::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i; ++j;
		return *this;
	}

	inline Vector10f& Vector10f::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i; --j;
		return *this;
	}

	inline Vector10f Vector10f::operator++ (int) noexcept {
		Vector10f temp = *this;
		++* this;
		return temp;
	}

	inline Vector10f Vector10f::operator-- (int) noexcept {
		Vector10f temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector10f& Vector10f::operator+= (const Vector10f& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i; j += right.j;
		return *this;
	}

	inline Vector10f& Vector10f::operator-= (const Vector10f& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i; j -= right.j;
		return *this;
	}

	inline Vector10f& Vector10f::operator*= (const Vector10f& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i; j *= right.j;
		return *this;
	}

	inline Vector10f& Vector10f::operator/= (const Vector10f& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i; j /= right.j;
		return *this;
	}


	inline Vector10f& Vector10f::operator+= (const std::float_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number; j += number;
		return *this;
	}

	inline Vector10f& Vector10f::operator-= (const std::float_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number; j -= number;
		return *this;
	}

	inline Vector10f& Vector10f::operator*= (const std::float_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number; j *= number;
		return *this;
	}

	inline Vector10f& Vector10f::operator/= (const std::float_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number; j /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector10f::operator< (const Vector10f& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i&& j < other.j;
	}

	inline bool Vector10f::operator<= (const Vector10f& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i && j <= other.j;
	}

	inline bool Vector10f::operator>  (const Vector10f& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i && j > other.j;
	}

	inline bool Vector10f::operator>= (const Vector10f& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i && j >= other.j;
	}


	inline bool Vector10f::operator<  (const std::float_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number && j < number;
	}

	inline bool Vector10f::operator<= (const std::float_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number && j <= number;
	}

	inline bool Vector10f::operator>  (const std::float_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number && j > number;
	}

	inline bool Vector10f::operator>= (const std::float_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number && j >= number;
	}


	// equal / not equal
	inline bool Vector10f::operator==(const Vector10f& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i && j == other.j;
	}

	inline bool Vector10f::operator!=(const Vector10f& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i || j != other.j;
	}

	inline bool Vector10f::operator==(const std::float_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number && j == number;
	}

	inline bool Vector10f::operator!=(const std::float_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number || j != number;
	}


	inline constexpr std::uint8_t Vector10f::size() const noexcept { return 10; }
	inline void Vector10f::reset(const std::float_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::float_t& Vector10f::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::float_t& Vector10f::at(const std::uint8_t& index) noexcept
	{
		std::float_t* ptr = &a;
		if (index > 9)
			return ptr[0];
		return ptr[index];
	}
	// End
}