#include "VectorL.h"

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : long
		Bytes: 4
		Range: -2.147.483.648 to 2.147.483.647
	*/

	// Vector2l
	inline Vector2l::Vector2l(const long& x, const long& y) noexcept
		: x(x), y(y) {}

	// copy/move constructor and assignment
	inline Vector2l::Vector2l(const Vector2l& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2l& Vector2l::operator=(const Vector2l& other) noexcept {
		x = other.x; y = other.y; return *this;
	}

	inline Vector2l::Vector2l(Vector2l&& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2l& Vector2l::operator=(Vector2l&& other) noexcept {
		x = other.x; y = other.y; return *this;
	}
	// .....................................
	inline Vector2l& Vector2l::operator=(const long& number) noexcept {
		x = number; y = number; return *this;
	}


	inline Vector2l Vector2l::operator +(const Vector2l& v) const noexcept {
		return { x + v.x, y + v.y };
	}

	inline Vector2l Vector2l::operator -(const Vector2l& v) const noexcept {
		return { x - v.x, y - v.y };
	}

	inline Vector2l Vector2l::operator *(const Vector2l& v) const noexcept {
		return { x * v.x, y * v.y };
	}

	inline Vector2l Vector2l::operator /(const Vector2l& v) const noexcept {
		return { x / v.x, y / v.y };
	}


	inline Vector2l Vector2l::operator +(const long& number) const noexcept {
		return { x + number, y + number };
	}

	inline Vector2l Vector2l::operator -(const long& number) const noexcept {
		return { x - number, y - number };
	}

	inline Vector2l Vector2l::operator *(const long& number) const noexcept {
		return { x * number, y * number };
	}

	inline Vector2l Vector2l::operator /(const long& number) const noexcept {
		return { x / number, y / number };
	}


	// increment / decrement
	inline Vector2l& Vector2l::operator++ () noexcept {
		++x; ++y;
		return *this;
	}

	inline Vector2l& Vector2l::operator-- ()  noexcept {
		--x; --y;
		return *this;
	}

	inline Vector2l Vector2l::operator++ (int) noexcept {
		Vector2l temp = *this;
		++* this;
		return temp;
	}

	inline Vector2l Vector2l::operator-- (int) noexcept {
		Vector2l temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector2l& Vector2l::operator+= (const Vector2l& right) noexcept {
		x += right.x; y += right.y;
		return *this;
	}

	inline Vector2l& Vector2l::operator-= (const Vector2l& right) noexcept {
		x -= right.x; y -= right.y;
		return *this;
	}

	inline Vector2l& Vector2l::operator*= (const Vector2l& right) noexcept {
		x *= right.x; y *= right.y;
		return *this;
	}

	inline Vector2l& Vector2l::operator/= (const Vector2l& right) noexcept {
		x /= right.x; y /= right.y;
		return *this;
	}


	inline Vector2l& Vector2l::operator+= (const long& number) noexcept {
		x += number; y += number;
		return *this;
	}

	inline Vector2l& Vector2l::operator-= (const long& number) noexcept {
		x -= number; y -= number;
		return *this;
	}

	inline Vector2l& Vector2l::operator*= (const long& number) noexcept {
		x *= number; y *= number;
		return *this;
	}

	inline Vector2l& Vector2l::operator/= (const long& number) noexcept {
		x /= number; y /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector2l::operator< (const Vector2l& other) const noexcept {
		return x < other.x && y < other.y;
	}

	inline bool Vector2l::operator<= (const Vector2l& other) const noexcept {
		return x <= other.x && y <= other.y;
	}

	inline bool Vector2l::operator>  (const Vector2l& other) const noexcept {
		return x > other.x && y > other.y;
	}

	inline bool Vector2l::operator>= (const Vector2l& other) const noexcept {
		return x >= other.x && y >= other.y;
	}


	inline bool Vector2l::operator<  (const long& number) const noexcept {
		return x < number && y < number;
	}

	inline bool Vector2l::operator<= (const long& number) const noexcept {
		return x <= number && y <= number;
	}

	inline bool Vector2l::operator>  (const long& number) const noexcept {
		return x > number && y > number;
	}

	inline bool Vector2l::operator>= (const long& number) const noexcept {
		return x >= number && y >= number;
	}


	// equal / not equal
	inline bool Vector2l::operator==(const Vector2l& other) const noexcept {
		return x == other.x && y == other.y;
	}

	inline bool Vector2l::operator!=(const Vector2l& other) const noexcept {
		return x != other.x || y != other.y;
	}

	inline bool Vector2l::operator==(const long& number) const noexcept {
		return x == number && y == number;
	}

	inline bool Vector2l::operator!=(const long& number) const noexcept {
		return x != number || y != number;
	}


	inline constexpr std::uint8_t Vector2l::size() const noexcept { return 2; }
	inline void Vector2l::reset(const long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long& Vector2l::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long& Vector2l::at(const std::uint8_t& index) noexcept
	{
		long* ptr = &x;
		if (index > 1)
			return ptr[0];
		return ptr[index];
	}



	// Vector3l
	inline Vector3l::Vector3l(const long& x, const long& y, const long& z) noexcept
		: x(x), y(y), z(z) {}

	// copy/move constructor and assignment
	inline Vector3l::Vector3l(const Vector3l& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3l& Vector3l::operator=(const Vector3l& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}

	inline Vector3l::Vector3l(Vector3l&& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3l& Vector3l::operator=(Vector3l&& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}
	// .....................................
	inline Vector3l& Vector3l::operator=(const long& number) noexcept {
		x = number; y = number; z = number; return *this;
	}


	inline Vector3l Vector3l::operator +(const Vector3l& v) const noexcept {
		return { x + v.x, y + v.y, z + v.z };
	}

	inline Vector3l Vector3l::operator -(const Vector3l& v) const noexcept {
		return { x - v.x, y - v.y, z - v.z };
	}

	inline Vector3l Vector3l::operator *(const Vector3l& v) const noexcept {
		return { x * v.x, y * v.y, z * v.z };
	}

	inline Vector3l Vector3l::operator /(const Vector3l& v) const noexcept {
		return { x / v.x, y / v.y, z / v.z };
	}

 
	inline Vector3l Vector3l::operator +(const long& number) const noexcept {
		return { x + number, y + number, z + number };
	}

	inline Vector3l Vector3l::operator -(const long& number) const noexcept {
		return { x - number, y - number, z - number };
	}

	inline Vector3l Vector3l::operator *(const long& number) const noexcept {
		return { x * number, y * number, z * number };
	}

	inline Vector3l Vector3l::operator /(const long& number) const noexcept {
		return { x / number, y / number, z / number };
	}


	// increment / decrement
	inline Vector3l& Vector3l::operator++ () noexcept {
		++x; ++y; ++z;
		return *this;
	}

	inline Vector3l& Vector3l::operator-- () noexcept {
		--x; --y; --z;
		return *this;
	}

	inline Vector3l Vector3l::operator++ (int) noexcept {
		Vector3l temp = *this;
		++* this;
		return temp;
	}

	inline Vector3l Vector3l::operator-- (int) noexcept {
		Vector3l temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector3l& Vector3l::operator+= (const Vector3l& right) noexcept {
		x += right.x; y += right.y; z += right.z;
		return *this;
	}

	inline Vector3l& Vector3l::operator-= (const Vector3l& right) noexcept {
		x -= right.x; y -= right.y; z -= right.z;
		return *this;
	}

	inline Vector3l& Vector3l::operator*= (const Vector3l& right) noexcept {
		x *= right.x; y *= right.y; z *= right.z;
		return *this;
	}

	inline Vector3l& Vector3l::operator/= (const Vector3l& right) noexcept {
		x /= right.x; y /= right.y; z /= right.z;
		return *this;
	}


	inline Vector3l& Vector3l::operator+= (const long& number) noexcept {
		x += number; y += number; z += number;
		return *this;
	}

	inline Vector3l& Vector3l::operator-= (const long& number) noexcept {
		x -= number; y -= number; z -= number;
		return *this;
	}

	inline Vector3l& Vector3l::operator*= (const long& number) noexcept {
		x *= number; y *= number; z *= number;
		return *this;
	}

	inline Vector3l& Vector3l::operator/= (const long& number) noexcept {
		x /= number; y /= number; z /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector3l::operator< (const Vector3l& other) const noexcept {
		return x < other.x && y < other.y&& z < other.z;
	}

	inline bool Vector3l::operator<= (const Vector3l& other) const noexcept {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	inline bool Vector3l::operator>  (const Vector3l& other) const noexcept {
		return x > other.x && y > other.y && z > other.z;
	}

	inline bool Vector3l::operator>= (const Vector3l& other) const noexcept {
		return x >= other.x && y >= other.y && z >= other.z;
	}


	inline bool Vector3l::operator<  (const long& number) const noexcept {
		return x < number && y < number && z < number;
	}

	inline bool Vector3l::operator<= (const long& number) const noexcept {
		return x <= number && y <= number && z <= number;
	}

	inline bool Vector3l::operator>  (const long& number) const noexcept {
		return x > number && y > number && z > number;
	}

	inline bool Vector3l::operator>= (const long& number) const noexcept {
		return x >= number && y >= number && z >= number;
	}


	// equal / not equal
	inline bool Vector3l::operator==(const Vector3l& other) const noexcept {
		return x == other.x && y == other.y && z == other.z;
	}

	inline bool Vector3l::operator!=(const Vector3l& other) const noexcept {
		return x != other.x || y != other.y || z != other.z;
	}

	inline bool Vector3l::operator==(const long& number) const noexcept {
		return x == number && y == number && z == number;
	}

	inline bool Vector3l::operator!=(const long& number) const noexcept {
		return x != number || y != number || z != number;
	}


	inline constexpr std::uint8_t Vector3l::size() const noexcept { return 3; }
	inline void Vector3l::reset(const long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long& Vector3l::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long& Vector3l::at(const std::uint8_t& index) noexcept
	{
		long* ptr = &x;
		if (index > 2)
			return ptr[0];
		return ptr[index];
	}



	// Vector4l
	inline Vector4l::Vector4l(const long& a, const long& b, const long& c, const long& d) noexcept
		: a(a), b(b), c(c), d(d) {}

	// copy/move constructor and assignment
	inline Vector4l::Vector4l(const Vector4l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4l& Vector4l::operator=(const Vector4l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}

	inline Vector4l::Vector4l(Vector4l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4l& Vector4l::operator=(Vector4l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}
	// .....................................
	inline Vector4l& Vector4l::operator=(const long& number) noexcept {
		a = number; b = number; c = number; d = number; return *this;
	}


	inline Vector4l Vector4l::operator +(const Vector4l& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d };
	}

	inline Vector4l Vector4l::operator -(const Vector4l& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d };
	}

	inline Vector4l Vector4l::operator *(const Vector4l& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d };
	}

	inline Vector4l Vector4l::operator /(const Vector4l& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d };
	}


	inline Vector4l Vector4l::operator +(const long& number) const noexcept {
		return { a + number, b + number, c + number, d + number };
	}

	inline Vector4l Vector4l::operator -(const long& number) const noexcept {
		return { a - number, b - number, c - number, d - number };
	}

	inline Vector4l Vector4l::operator *(const long& number) const noexcept {
		return { a * number, b * number, c * number, d * number };
	}

	inline Vector4l Vector4l::operator /(const long& number) const noexcept {
		return { a / number, b / number, c / number, d / number };
	}


	// increment / decrement
	inline Vector4l& Vector4l::operator++ () noexcept {
		++a; ++b; ++c; ++d;
		return *this;
	}

	inline Vector4l& Vector4l::operator-- () noexcept {
		--a; --b; --c; --d;
		return *this;
	}

	inline Vector4l Vector4l::operator++ (int) noexcept {
		Vector4l temp = *this;
		++* this;
		return temp;
	}

	inline Vector4l Vector4l::operator-- (int) noexcept {
		Vector4l temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector4l& Vector4l::operator+= (const Vector4l& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d;
		return *this;
	}

	inline Vector4l& Vector4l::operator-= (const Vector4l& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d;
		return *this;
	}

	inline Vector4l& Vector4l::operator*= (const Vector4l& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d;
		return *this;
	}

	inline Vector4l& Vector4l::operator/= (const Vector4l& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d;
		return *this;
	}


	inline Vector4l& Vector4l::operator+= (const long& number) noexcept {
		a += number; b += number; c += number; d += number;
		return *this;
	}

	inline Vector4l& Vector4l::operator-= (const long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number;
		return *this;
	}

	inline Vector4l& Vector4l::operator*= (const long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number;
		return *this;
	}

	inline Vector4l& Vector4l::operator/= (const long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector4l::operator< (const Vector4l& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d;
	}

	inline bool Vector4l::operator<= (const Vector4l& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d;
	}

	inline bool Vector4l::operator>  (const Vector4l& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d;
	}

	inline bool Vector4l::operator>= (const Vector4l& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d;
	}


	inline bool Vector4l::operator<  (const long& number) const noexcept {
		return a < number && b < number && c < number && d < number;
	}

	inline bool Vector4l::operator<= (const long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number;
	}

	inline bool Vector4l::operator>  (const long& number) const noexcept {
		return a > number && b > number && c > number && d > number;
	}

	inline bool Vector4l::operator>= (const long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number;
	}


	// equal / not equal
	inline bool Vector4l::operator==(const Vector4l& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d;
	}

	inline bool Vector4l::operator!=(const Vector4l& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d;
	}

	inline bool Vector4l::operator==(const long& number) const noexcept {
		return a == number && b == number && c == number && d == number;
	}

	inline bool Vector4l::operator!=(const long& number) const noexcept {
		return a != number || b != number || c != number || d != number;
	}


	inline constexpr std::uint8_t Vector4l::size() const noexcept { return 4; }
	inline void Vector4l::reset(const long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long& Vector4l::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long& Vector4l::at(const std::uint8_t& index) noexcept
	{
		long* ptr = &a;
		if (index > 3)
			return ptr[0];
		return ptr[index];
	}



	// Vector5l
	inline Vector5l::Vector5l(const long& a, const long& b, const long& c, const long& d,
		const long& e) noexcept
		: a(a), b(b), c(c), d(d), e(e) {}

	// copy/move constructor and assignment
	inline Vector5l::Vector5l(const Vector5l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5l& Vector5l::operator=(const Vector5l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}

	inline Vector5l::Vector5l(Vector5l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5l& Vector5l::operator=(Vector5l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}
	// .....................................
	inline Vector5l& Vector5l::operator=(const long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; return *this;
	}


	inline Vector5l Vector5l::operator +(const Vector5l& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e };
	}

	inline Vector5l Vector5l::operator -(const Vector5l& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e };
	}

	inline Vector5l Vector5l::operator *(const Vector5l& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e };
	}

	inline Vector5l Vector5l::operator /(const Vector5l& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e };
	}


	inline Vector5l Vector5l::operator +(const long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number };
	}

	inline Vector5l Vector5l::operator -(const long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number };
	}

	inline Vector5l Vector5l::operator *(const long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number };
	}

	inline Vector5l Vector5l::operator /(const long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number };
	}


	// increment / decrement
	inline Vector5l& Vector5l::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e;
		return *this;
	}

	inline Vector5l& Vector5l::operator-- () noexcept {
		--a; --b; --c; --d; --e;
		return *this;
	}

	inline Vector5l Vector5l::operator++ (int) noexcept {
		Vector5l temp = *this;
		++* this;
		return temp;
	}

	inline Vector5l Vector5l::operator-- (int) noexcept {
		Vector5l temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector5l& Vector5l::operator+= (const Vector5l& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e;
		return *this;
	}

	inline Vector5l& Vector5l::operator-= (const Vector5l& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e;
		return *this;
	}

	inline Vector5l& Vector5l::operator*= (const Vector5l& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e;
		return *this;
	}

	inline Vector5l& Vector5l::operator/= (const Vector5l& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e;
		return *this;
	}


	inline Vector5l& Vector5l::operator+= (const long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number;
		return *this;
	}

	inline Vector5l& Vector5l::operator-= (const long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number;
		return *this;
	}

	inline Vector5l& Vector5l::operator*= (const long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number;
		return *this;
	}

	inline Vector5l& Vector5l::operator/= (const long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector5l::operator< (const Vector5l& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e;
	}

	inline bool Vector5l::operator<= (const Vector5l& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e;
	}

	inline bool Vector5l::operator>  (const Vector5l& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e;
	}

	inline bool Vector5l::operator>= (const Vector5l& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e;
	}


	inline bool Vector5l::operator<  (const long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number;
	}

	inline bool Vector5l::operator<= (const long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number;
	}

	inline bool Vector5l::operator>  (const long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number;
	}

	inline bool Vector5l::operator>= (const long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number;
	}


	// equal / not equal
	inline bool Vector5l::operator==(const Vector5l& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
	}

	inline bool Vector5l::operator!=(const Vector5l& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e;
	}

	inline bool Vector5l::operator==(const long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number;
	}

	inline bool Vector5l::operator!=(const long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number;
	}


	inline constexpr std::uint8_t Vector5l::size() const noexcept { return 5; }
	inline void Vector5l::reset(const long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long& Vector5l::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long& Vector5l::at(const std::uint8_t& index) noexcept
	{
		long* ptr = &a;
		if (index > 4)
			return ptr[0];
		return ptr[index];
	}



	// Vector6l
	inline Vector6l::Vector6l(const long& a, const long& b, const long& c, const long& d,
		const long& e, const long& f) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f) {}

	// copy/move constructor and assignment
	inline Vector6l::Vector6l(const Vector6l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6l& Vector6l::operator=(const Vector6l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}

	inline Vector6l::Vector6l(Vector6l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6l& Vector6l::operator=(Vector6l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}
	// .....................................
	inline Vector6l& Vector6l::operator=(const long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; return *this;
	}


	inline Vector6l Vector6l::operator +(const Vector6l& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f };
	}

	inline Vector6l Vector6l::operator -(const Vector6l& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f };
	}

	inline Vector6l Vector6l::operator *(const Vector6l& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f };
	}

	inline Vector6l Vector6l::operator /(const Vector6l& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f };
	}


	inline Vector6l Vector6l::operator +(const long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number };
	}

	inline Vector6l Vector6l::operator -(const long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number };
	}

	inline Vector6l Vector6l::operator *(const long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number };
	}

	inline Vector6l Vector6l::operator /(const long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number };
	}


	// increment / decrement
	inline Vector6l& Vector6l::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f;
		return *this;
	}

	inline Vector6l& Vector6l::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f;
		return *this;
	}

	inline Vector6l Vector6l::operator++ (int) noexcept {
		Vector6l temp = *this;
		++* this;
		return temp;
	}

	inline Vector6l Vector6l::operator-- (int) noexcept {
		Vector6l temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector6l& Vector6l::operator+= (const Vector6l& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f;
		return *this;
	}

	inline Vector6l& Vector6l::operator-= (const Vector6l& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f;
		return *this;
	}

	inline Vector6l& Vector6l::operator*= (const Vector6l& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f;
		return *this;
	}

	inline Vector6l& Vector6l::operator/= (const Vector6l& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f;
		return *this;
	}


	inline Vector6l& Vector6l::operator+= (const long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number;
		return *this;
	}

	inline Vector6l& Vector6l::operator-= (const long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number;
		return *this;
	}

	inline Vector6l& Vector6l::operator*= (const long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number;
		return *this;
	}

	inline Vector6l& Vector6l::operator/= (const long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector6l::operator< (const Vector6l& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f;
	}

	inline bool Vector6l::operator<= (const Vector6l& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f;
	}

	inline bool Vector6l::operator>  (const Vector6l& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f;
	}

	inline bool Vector6l::operator>= (const Vector6l& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f;
	}


	inline bool Vector6l::operator<  (const long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number;
	}

	inline bool Vector6l::operator<= (const long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number;
	}

	inline bool Vector6l::operator>  (const long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number;
	}

	inline bool Vector6l::operator>= (const long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number;
	}


	// equal / not equal
	inline bool Vector6l::operator==(const Vector6l& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f;
	}

	inline bool Vector6l::operator!=(const Vector6l& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f;
	}

	inline bool Vector6l::operator==(const long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number;
	}

	inline bool Vector6l::operator!=(const long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number;
	}


	inline constexpr std::uint8_t Vector6l::size() const noexcept { return 6; }
	inline void Vector6l::reset(const long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long& Vector6l::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long& Vector6l::at(const std::uint8_t& index) noexcept
	{
		long* ptr = &a;
		if (index > 5)
			return ptr[0];
		return ptr[index];
	}



	// Vector7l
	inline Vector7l::Vector7l(const long& a, const long& b, const long& c, const long& d,
		const long& e, const long& f, const long& g) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g) {}

	// copy/move constructor and assignment
	inline Vector7l::Vector7l(const Vector7l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7l& Vector7l::operator=(const Vector7l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}

	inline Vector7l::Vector7l(Vector7l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7l& Vector7l::operator=(Vector7l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}
	// .....................................
	inline Vector7l& Vector7l::operator=(const long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; return *this;
	}


	inline Vector7l Vector7l::operator +(const Vector7l& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g };
	}

	inline Vector7l Vector7l::operator -(const Vector7l& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g };
	}

	inline Vector7l Vector7l::operator *(const Vector7l& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g };
	}

	inline Vector7l Vector7l::operator /(const Vector7l& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g };
	}


	inline Vector7l Vector7l::operator +(const long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number };
	}

	inline Vector7l Vector7l::operator -(const long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number };
	}

	inline Vector7l Vector7l::operator *(const long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number };
	}

	inline Vector7l Vector7l::operator /(const long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number };
	}


	// increment / decrement
	inline Vector7l& Vector7l::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g;
		return *this;
	}

	inline Vector7l& Vector7l::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g;
		return *this;
	}

	inline Vector7l Vector7l::operator++ (int) noexcept {
		Vector7l temp = *this;
		++* this;
		return temp;
	}

	inline Vector7l Vector7l::operator-- (int) noexcept {
		Vector7l temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector7l& Vector7l::operator+= (const Vector7l& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g;
		return *this;
	}

	inline Vector7l& Vector7l::operator-= (const Vector7l& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g;
		return *this;
	}

	inline Vector7l& Vector7l::operator*= (const Vector7l& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g;
		return *this;
	}

	inline Vector7l& Vector7l::operator/= (const Vector7l& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g;
		return *this;
	}


	inline Vector7l& Vector7l::operator+= (const long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number;
		return *this;
	}

	inline Vector7l& Vector7l::operator-= (const long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number;
		return *this;
	}

	inline Vector7l& Vector7l::operator*= (const long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number;
		return *this;
	}

	inline Vector7l& Vector7l::operator/= (const long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector7l::operator< (const Vector7l& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g;
	}

	inline bool Vector7l::operator<= (const Vector7l& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g;
	}

	inline bool Vector7l::operator>  (const Vector7l& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g;
	}

	inline bool Vector7l::operator>= (const Vector7l& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g;
	}


	inline bool Vector7l::operator<  (const long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number;
	}

	inline bool Vector7l::operator<= (const long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number;
	}

	inline bool Vector7l::operator>  (const long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number;
	}

	inline bool Vector7l::operator>= (const long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number;
	}


	// equal / not equal
	inline bool Vector7l::operator==(const Vector7l& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g;
	}

	inline bool Vector7l::operator!=(const Vector7l& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g;
	}

	inline bool Vector7l::operator==(const long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number;
	}

	inline bool Vector7l::operator!=(const long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number;
	}


	inline constexpr std::uint8_t Vector7l::size() const noexcept { return 7; }
	inline void Vector7l::reset(const long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long& Vector7l::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long& Vector7l::at(const std::uint8_t& index) noexcept
	{
		long* ptr = &a;
		if (index > 6)
			return ptr[0];
		return ptr[index];
	}



	// Vector8l
	inline Vector8l::Vector8l(const long& a, const long& b, const long& c, const long& d,
		const long& e, const long& f, const long& g, const long& h) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h) {}

	// copy/move constructor and assignment
	inline Vector8l::Vector8l(const Vector8l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8l& Vector8l::operator=(const Vector8l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}

	inline Vector8l::Vector8l(Vector8l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8l& Vector8l::operator=(Vector8l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}
	// .....................................
	inline Vector8l& Vector8l::operator=(const long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; return *this;
	}


	inline Vector8l Vector8l::operator +(const Vector8l& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h };
	}

	inline Vector8l Vector8l::operator -(const Vector8l& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h };
	}

	inline Vector8l Vector8l::operator *(const Vector8l& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h };
	}

	inline Vector8l Vector8l::operator /(const Vector8l& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h };
	}


	inline Vector8l Vector8l::operator +(const long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number };
	}

	inline Vector8l Vector8l::operator -(const long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number };
	}

	inline Vector8l Vector8l::operator *(const long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number };
	}

	inline Vector8l Vector8l::operator /(const long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number };
	}


	// increment / decrement
	inline Vector8l& Vector8l::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h;
		return *this;
	}

	inline Vector8l& Vector8l::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h;
		return *this;
	}

	inline Vector8l Vector8l::operator++ (int) noexcept {
		Vector8l temp = *this;
		++* this;
		return temp;
	}

	inline Vector8l Vector8l::operator-- (int) noexcept {
		Vector8l temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector8l& Vector8l::operator+= (const Vector8l& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h;
		return *this;
	}

	inline Vector8l& Vector8l::operator-= (const Vector8l& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h;
		return *this;
	}

	inline Vector8l& Vector8l::operator*= (const Vector8l& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h;
		return *this;
	}

	inline Vector8l& Vector8l::operator/= (const Vector8l& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h;
		return *this;
	}


	inline Vector8l& Vector8l::operator+= (const long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number;
		return *this;
	}

	inline Vector8l& Vector8l::operator-= (const long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number;
		return *this;
	}

	inline Vector8l& Vector8l::operator*= (const long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number;
		return *this;
	}

	inline Vector8l& Vector8l::operator/= (const long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector8l::operator< (const Vector8l& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h;
	}

	inline bool Vector8l::operator<= (const Vector8l& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h;
	}

	inline bool Vector8l::operator>  (const Vector8l& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h;
	}

	inline bool Vector8l::operator>= (const Vector8l& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h;
	}


	inline bool Vector8l::operator<  (const long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number;
	}

	inline bool Vector8l::operator<= (const long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number;
	}

	inline bool Vector8l::operator>  (const long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number;
	}

	inline bool Vector8l::operator>= (const long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number;
	}


	// equal / not equal
	inline bool Vector8l::operator==(const Vector8l& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h;
	}

	inline bool Vector8l::operator!=(const Vector8l& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h;
	}

	inline bool Vector8l::operator==(const long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number;
	}

	inline bool Vector8l::operator!=(const long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number;
	}


	inline constexpr std::uint8_t Vector8l::size() const noexcept { return 8; }
	inline void Vector8l::reset(const long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long& Vector8l::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long& Vector8l::at(const std::uint8_t& index) noexcept
	{
		long* ptr = &a;
		if (index > 7)
			return ptr[0];
		return ptr[index];
	}



	// Vector9l
	inline Vector9l::Vector9l(const long& a, const long& b, const long& c, const long& d,
		const long& e, const long& f, const long& g, const long& h,
		const long& i) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

	// copy/move constructor and assignment
	inline Vector9l::Vector9l(const Vector9l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9l& Vector9l::operator=(const Vector9l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}

	inline Vector9l::Vector9l(Vector9l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9l& Vector9l::operator=(Vector9l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}
	// .....................................
	inline Vector9l& Vector9l::operator=(const long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; return *this;
	}


	inline Vector9l Vector9l::operator +(const Vector9l& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i };
	}

	inline Vector9l Vector9l::operator -(const Vector9l& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i };
	}

	inline Vector9l Vector9l::operator *(const Vector9l& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i };
	}

	inline Vector9l Vector9l::operator /(const Vector9l& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i };
	}


	inline Vector9l Vector9l::operator +(const long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number };
	}

	inline Vector9l Vector9l::operator -(const long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number };
	}

	inline Vector9l Vector9l::operator *(const long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number };
	}

	inline Vector9l Vector9l::operator /(const long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number };
	}


	// increment / decrement
	inline Vector9l& Vector9l::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i;
		return *this;
	}

	inline Vector9l& Vector9l::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i;
		return *this;
	}

	inline Vector9l Vector9l::operator++ (int) noexcept {
		Vector9l temp = *this;
		++* this;
		return temp;
	}

	inline Vector9l Vector9l::operator-- (int) noexcept {
		Vector9l temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector9l& Vector9l::operator+= (const Vector9l& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i;
		return *this;
	}

	inline Vector9l& Vector9l::operator-= (const Vector9l& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i;
		return *this;
	}

	inline Vector9l& Vector9l::operator*= (const Vector9l& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i;
		return *this;
	}

	inline Vector9l& Vector9l::operator/= (const Vector9l& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i;
		return *this;
	}


	inline Vector9l& Vector9l::operator+= (const long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number;
		return *this;
	}

	inline Vector9l& Vector9l::operator-= (const long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number;
		return *this;
	}

	inline Vector9l& Vector9l::operator*= (const long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number;
		return *this;
	}

	inline Vector9l& Vector9l::operator/= (const long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector9l::operator< (const Vector9l& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i;
	}

	inline bool Vector9l::operator<= (const Vector9l& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i;
	}

	inline bool Vector9l::operator>  (const Vector9l& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i;
	}

	inline bool Vector9l::operator>= (const Vector9l& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i;
	}


	inline bool Vector9l::operator<  (const long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number;
	}

	inline bool Vector9l::operator<= (const long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number;
	}

	inline bool Vector9l::operator>  (const long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number;
	}

	inline bool Vector9l::operator>= (const long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number;
	}


	// equal / not equal
	inline bool Vector9l::operator==(const Vector9l& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i;
	}

	inline bool Vector9l::operator!=(const Vector9l& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i;
	}

	inline bool Vector9l::operator==(const long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number;
	}

	inline bool Vector9l::operator!=(const long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number;
	}


	inline constexpr std::uint8_t Vector9l::size() const noexcept { return 9; }
	inline void Vector9l::reset(const long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long& Vector9l::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long& Vector9l::at(const std::uint8_t& index) noexcept
	{
		long* ptr = &a;
		if (index > 8)
			return ptr[0];
		return ptr[index];
	}



	// Vector10l
	inline Vector10l::Vector10l(const long& a, const long& b, const long& c, const long& d,
		const long& e, const long& f, const long& g, const long& h,
		const long& i, const long& j) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {}

	// copy/move constructor and assignment
	inline Vector10l::Vector10l(const Vector10l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10l& Vector10l::operator=(const Vector10l& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}

	inline Vector10l::Vector10l(Vector10l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10l& Vector10l::operator=(Vector10l&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}
	// .....................................
	inline Vector10l& Vector10l::operator=(const long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; j = number; return *this;
	}


	inline Vector10l Vector10l::operator +(const Vector10l& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i, j + v.j };
	}

	inline Vector10l Vector10l::operator -(const Vector10l& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i, j - v.j };
	}

	inline Vector10l Vector10l::operator *(const Vector10l& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i, j * v.j };
	}

	inline Vector10l Vector10l::operator /(const Vector10l& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i, j / v.j };
	}


	inline Vector10l Vector10l::operator +(const long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number, j + number };
	}

	inline Vector10l Vector10l::operator -(const long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number, j - number };
	}

	inline Vector10l Vector10l::operator *(const long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number, j * number };
	}

	inline Vector10l Vector10l::operator /(const long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number, j / number };
	}


	// increment / decrement
	inline Vector10l& Vector10l::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i; ++j;
		return *this;
	}

	inline Vector10l& Vector10l::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i; --j;
		return *this;
	}

	inline Vector10l Vector10l::operator++ (int) noexcept {
		Vector10l temp = *this;
		++* this;
		return temp;
	}

	inline Vector10l Vector10l::operator-- (int) noexcept {
		Vector10l temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector10l& Vector10l::operator+= (const Vector10l& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i; j += right.j;
		return *this;
	}

	inline Vector10l& Vector10l::operator-= (const Vector10l& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i; j -= right.j;
		return *this;
	}

	inline Vector10l& Vector10l::operator*= (const Vector10l& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i; j *= right.j;
		return *this;
	}

	inline Vector10l& Vector10l::operator/= (const Vector10l& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i; j /= right.j;
		return *this;
	}


	inline Vector10l& Vector10l::operator+= (const long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number; j += number;
		return *this;
	}

	inline Vector10l& Vector10l::operator-= (const long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number; j -= number;
		return *this;
	}

	inline Vector10l& Vector10l::operator*= (const long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number; j *= number;
		return *this;
	}

	inline Vector10l& Vector10l::operator/= (const long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number; j /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector10l::operator< (const Vector10l& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i&& j < other.j;
	}

	inline bool Vector10l::operator<= (const Vector10l& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i && j <= other.j;
	}

	inline bool Vector10l::operator>  (const Vector10l& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i && j > other.j;
	}

	inline bool Vector10l::operator>= (const Vector10l& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i && j >= other.j;
	}


	inline bool Vector10l::operator<  (const long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number && j < number;
	}

	inline bool Vector10l::operator<= (const long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number && j <= number;
	}

	inline bool Vector10l::operator>  (const long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number && j > number;
	}

	inline bool Vector10l::operator>= (const long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number && j >= number;
	}


	// equal / not equal
	inline bool Vector10l::operator==(const Vector10l& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i && j == other.j;
	}

	inline bool Vector10l::operator!=(const Vector10l& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i || j != other.j;
	}

	inline bool Vector10l::operator==(const long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number && j == number;
	}

	inline bool Vector10l::operator!=(const long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number || j != number;
	}


	inline constexpr std::uint8_t Vector10l::size() const noexcept { return 10; }
	inline void Vector10l::reset(const long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline long& Vector10l::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline long& Vector10l::at(const std::uint8_t& index) noexcept
	{
		long* ptr = &a;
		if (index > 9)
			return ptr[0];
		return ptr[index];
	}
	// End
}