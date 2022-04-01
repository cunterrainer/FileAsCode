#include "VectorUl.h"

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : unsigned long
		Bytes: 4
		Range: 0 to 4.294.967.295
	*/

	// Vector2Ul
	inline Vector2Ul::Vector2Ul(const unsigned long& x, const unsigned long& y) noexcept
		: x(x), y(y) {}

	// copy/move constructor and assignment
	inline Vector2Ul::Vector2Ul(const Vector2Ul& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2Ul& Vector2Ul::operator=(const Vector2Ul& other) noexcept {
		x = other.x; y = other.y; return *this;
	}

	inline Vector2Ul::Vector2Ul(Vector2Ul&& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2Ul& Vector2Ul::operator=(Vector2Ul&& other) noexcept {
		x = other.x; y = other.y; return *this;
	}
	// .....................................
	inline Vector2Ul& Vector2Ul::operator=(const unsigned long& number) noexcept {
		x = number; y = number; return *this;
	}


	inline Vector2Ul Vector2Ul::operator +(const Vector2Ul& v) const noexcept {
		return { x + v.x, y + v.y };
	}

	inline Vector2Ul Vector2Ul::operator -(const Vector2Ul& v) const noexcept {
		return { x - v.x, y - v.y };
	}

	inline Vector2Ul Vector2Ul::operator *(const Vector2Ul& v) const noexcept {
		return { x * v.x, y * v.y };
	}

	inline Vector2Ul Vector2Ul::operator /(const Vector2Ul& v) const noexcept {
		return { x / v.x, y / v.y };
	}


	inline Vector2Ul Vector2Ul::operator +(const unsigned long& number) const noexcept {
		return { x + number, y + number };
	}

	inline Vector2Ul Vector2Ul::operator -(const unsigned long& number) const noexcept {
		return { x - number, y - number };
	}

	inline Vector2Ul Vector2Ul::operator *(const unsigned long& number) const noexcept {
		return { x * number, y * number };
	}

	inline Vector2Ul Vector2Ul::operator /(const unsigned long& number) const noexcept {
		return { x / number, y / number };
	}


	// increment / decrement
	inline Vector2Ul& Vector2Ul::operator++ () noexcept {
		++x; ++y;
		return *this;
	}

	inline Vector2Ul& Vector2Ul::operator-- ()  noexcept {
		--x; --y;
		return *this;
	}

	inline Vector2Ul Vector2Ul::operator++ (int) noexcept {
		Vector2Ul temp = *this;
		++* this;
		return temp;
	}

	inline Vector2Ul Vector2Ul::operator-- (int) noexcept {
		Vector2Ul temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector2Ul& Vector2Ul::operator+= (const Vector2Ul& right) noexcept {
		x += right.x; y += right.y;
		return *this;
	}

	inline Vector2Ul& Vector2Ul::operator-= (const Vector2Ul& right) noexcept {
		x -= right.x; y -= right.y;
		return *this;
	}

	inline Vector2Ul& Vector2Ul::operator*= (const Vector2Ul& right) noexcept {
		x *= right.x; y *= right.y;
		return *this;
	}

	inline Vector2Ul& Vector2Ul::operator/= (const Vector2Ul& right) noexcept {
		x /= right.x; y /= right.y;
		return *this;
	}


	inline Vector2Ul& Vector2Ul::operator+= (const unsigned long& number) noexcept {
		x += number; y += number;
		return *this;
	}

	inline Vector2Ul& Vector2Ul::operator-= (const unsigned long& number) noexcept {
		x -= number; y -= number;
		return *this;
	}

	inline Vector2Ul& Vector2Ul::operator*= (const unsigned long& number) noexcept {
		x *= number; y *= number;
		return *this;
	}

	inline Vector2Ul& Vector2Ul::operator/= (const unsigned long& number) noexcept {
		x /= number; y /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector2Ul::operator< (const Vector2Ul& other) const noexcept {
		return x < other.x && y < other.y;
	}

	inline bool Vector2Ul::operator<= (const Vector2Ul& other) const noexcept {
		return x <= other.x && y <= other.y;
	}

	inline bool Vector2Ul::operator>  (const Vector2Ul& other) const noexcept {
		return x > other.x && y > other.y;
	}

	inline bool Vector2Ul::operator>= (const Vector2Ul& other) const noexcept {
		return x >= other.x && y >= other.y;
	}


	inline bool Vector2Ul::operator<  (const unsigned long& number) const noexcept {
		return x < number && y < number;
	}

	inline bool Vector2Ul::operator<= (const unsigned long& number) const noexcept {
		return x <= number && y <= number;
	}

	inline bool Vector2Ul::operator>  (const unsigned long& number) const noexcept {
		return x > number && y > number;
	}

	inline bool Vector2Ul::operator>= (const unsigned long& number) const noexcept {
		return x >= number && y >= number;
	}


	// equal / not equal
	inline bool Vector2Ul::operator==(const Vector2Ul& other) const noexcept {
		return x == other.x && y == other.y;
	}

	inline bool Vector2Ul::operator!=(const Vector2Ul& other) const noexcept {
		return x != other.x || y != other.y;
	}

	inline bool Vector2Ul::operator==(const unsigned long& number) const noexcept {
		return x == number && y == number;
	}

	inline bool Vector2Ul::operator!=(const unsigned long& number) const noexcept {
		return x != number || y != number;
	}


	inline constexpr std::uint8_t Vector2Ul::size() const noexcept { return 2; }
	inline void Vector2Ul::reset(const unsigned long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline unsigned long& Vector2Ul::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline unsigned long& Vector2Ul::at(const std::uint8_t& index) noexcept
	{
		unsigned long* ptr = &x;
		if (index > 1)
			return ptr[0];
		return ptr[index];
	}



	// Vector3Ul
	inline Vector3Ul::Vector3Ul(const unsigned long& x, const unsigned long& y, const unsigned long& z) noexcept
		: x(x), y(y), z(z) {}

	// copy/move constructor and assignment
	inline Vector3Ul::Vector3Ul(const Vector3Ul& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3Ul& Vector3Ul::operator=(const Vector3Ul& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}

	inline Vector3Ul::Vector3Ul(Vector3Ul&& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3Ul& Vector3Ul::operator=(Vector3Ul&& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}
	// .....................................
	inline Vector3Ul& Vector3Ul::operator=(const unsigned long& number) noexcept {
		x = number; y = number; z = number; return *this;
	}


	inline Vector3Ul Vector3Ul::operator +(const Vector3Ul& v) const noexcept {
		return { x + v.x, y + v.y, z + v.z };
	}

	inline Vector3Ul Vector3Ul::operator -(const Vector3Ul& v) const noexcept {
		return { x - v.x, y - v.y, z - v.z };
	}

	inline Vector3Ul Vector3Ul::operator *(const Vector3Ul& v) const noexcept {
		return { x * v.x, y * v.y, z * v.z };
	}

	inline Vector3Ul Vector3Ul::operator /(const Vector3Ul& v) const noexcept {
		return { x / v.x, y / v.y, z / v.z };
	}

 
	inline Vector3Ul Vector3Ul::operator +(const unsigned long& number) const noexcept {
		return { x + number, y + number, z + number };
	}

	inline Vector3Ul Vector3Ul::operator -(const unsigned long& number) const noexcept {
		return { x - number, y - number, z - number };
	}

	inline Vector3Ul Vector3Ul::operator *(const unsigned long& number) const noexcept {
		return { x * number, y * number, z * number };
	}

	inline Vector3Ul Vector3Ul::operator /(const unsigned long& number) const noexcept {
		return { x / number, y / number, z / number };
	}


	// increment / decrement
	inline Vector3Ul& Vector3Ul::operator++ () noexcept {
		++x; ++y; ++z;
		return *this;
	}

	inline Vector3Ul& Vector3Ul::operator-- () noexcept {
		--x; --y; --z;
		return *this;
	}

	inline Vector3Ul Vector3Ul::operator++ (int) noexcept {
		Vector3Ul temp = *this;
		++* this;
		return temp;
	}

	inline Vector3Ul Vector3Ul::operator-- (int) noexcept {
		Vector3Ul temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector3Ul& Vector3Ul::operator+= (const Vector3Ul& right) noexcept {
		x += right.x; y += right.y; z += right.z;
		return *this;
	}

	inline Vector3Ul& Vector3Ul::operator-= (const Vector3Ul& right) noexcept {
		x -= right.x; y -= right.y; z -= right.z;
		return *this;
	}

	inline Vector3Ul& Vector3Ul::operator*= (const Vector3Ul& right) noexcept {
		x *= right.x; y *= right.y; z *= right.z;
		return *this;
	}

	inline Vector3Ul& Vector3Ul::operator/= (const Vector3Ul& right) noexcept {
		x /= right.x; y /= right.y; z /= right.z;
		return *this;
	}


	inline Vector3Ul& Vector3Ul::operator+= (const unsigned long& number) noexcept {
		x += number; y += number; z += number;
		return *this;
	}

	inline Vector3Ul& Vector3Ul::operator-= (const unsigned long& number) noexcept {
		x -= number; y -= number; z -= number;
		return *this;
	}

	inline Vector3Ul& Vector3Ul::operator*= (const unsigned long& number) noexcept {
		x *= number; y *= number; z *= number;
		return *this;
	}

	inline Vector3Ul& Vector3Ul::operator/= (const unsigned long& number) noexcept {
		x /= number; y /= number; z /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector3Ul::operator< (const Vector3Ul& other) const noexcept {
		return x < other.x && y < other.y&& z < other.z;
	}

	inline bool Vector3Ul::operator<= (const Vector3Ul& other) const noexcept {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	inline bool Vector3Ul::operator>  (const Vector3Ul& other) const noexcept {
		return x > other.x && y > other.y && z > other.z;
	}

	inline bool Vector3Ul::operator>= (const Vector3Ul& other) const noexcept {
		return x >= other.x && y >= other.y && z >= other.z;
	}


	inline bool Vector3Ul::operator<  (const unsigned long& number) const noexcept {
		return x < number && y < number && z < number;
	}

	inline bool Vector3Ul::operator<= (const unsigned long& number) const noexcept {
		return x <= number && y <= number && z <= number;
	}

	inline bool Vector3Ul::operator>  (const unsigned long& number) const noexcept {
		return x > number && y > number && z > number;
	}

	inline bool Vector3Ul::operator>= (const unsigned long& number) const noexcept {
		return x >= number && y >= number && z >= number;
	}


	// equal / not equal
	inline bool Vector3Ul::operator==(const Vector3Ul& other) const noexcept {
		return x == other.x && y == other.y && z == other.z;
	}

	inline bool Vector3Ul::operator!=(const Vector3Ul& other) const noexcept {
		return x != other.x || y != other.y || z != other.z;
	}

	inline bool Vector3Ul::operator==(const unsigned long& number) const noexcept {
		return x == number && y == number && z == number;
	}

	inline bool Vector3Ul::operator!=(const unsigned long& number) const noexcept {
		return x != number || y != number || z != number;
	}


	inline constexpr std::uint8_t Vector3Ul::size() const noexcept { return 3; }
	inline void Vector3Ul::reset(const unsigned long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline unsigned long& Vector3Ul::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline unsigned long& Vector3Ul::at(const std::uint8_t& index) noexcept
	{
		unsigned long* ptr = &x;
		if (index > 2)
			return ptr[0];
		return ptr[index];
	}



	// Vector4Ul
	inline Vector4Ul::Vector4Ul(const unsigned long& a, const unsigned long& b, const unsigned long& c, const unsigned long& d) noexcept
		: a(a), b(b), c(c), d(d) {}

	// copy/move constructor and assignment
	inline Vector4Ul::Vector4Ul(const Vector4Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4Ul& Vector4Ul::operator=(const Vector4Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}

	inline Vector4Ul::Vector4Ul(Vector4Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4Ul& Vector4Ul::operator=(Vector4Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}
	// .....................................
	inline Vector4Ul& Vector4Ul::operator=(const unsigned long& number) noexcept {
		a = number; b = number; c = number; d = number; return *this;
	}


	inline Vector4Ul Vector4Ul::operator +(const Vector4Ul& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d };
	}

	inline Vector4Ul Vector4Ul::operator -(const Vector4Ul& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d };
	}

	inline Vector4Ul Vector4Ul::operator *(const Vector4Ul& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d };
	}

	inline Vector4Ul Vector4Ul::operator /(const Vector4Ul& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d };
	}


	inline Vector4Ul Vector4Ul::operator +(const unsigned long& number) const noexcept {
		return { a + number, b + number, c + number, d + number };
	}

	inline Vector4Ul Vector4Ul::operator -(const unsigned long& number) const noexcept {
		return { a - number, b - number, c - number, d - number };
	}

	inline Vector4Ul Vector4Ul::operator *(const unsigned long& number) const noexcept {
		return { a * number, b * number, c * number, d * number };
	}

	inline Vector4Ul Vector4Ul::operator /(const unsigned long& number) const noexcept {
		return { a / number, b / number, c / number, d / number };
	}


	// increment / decrement
	inline Vector4Ul& Vector4Ul::operator++ () noexcept {
		++a; ++b; ++c; ++d;
		return *this;
	}

	inline Vector4Ul& Vector4Ul::operator-- () noexcept {
		--a; --b; --c; --d;
		return *this;
	}

	inline Vector4Ul Vector4Ul::operator++ (int) noexcept {
		Vector4Ul temp = *this;
		++* this;
		return temp;
	}

	inline Vector4Ul Vector4Ul::operator-- (int) noexcept {
		Vector4Ul temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector4Ul& Vector4Ul::operator+= (const Vector4Ul& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d;
		return *this;
	}

	inline Vector4Ul& Vector4Ul::operator-= (const Vector4Ul& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d;
		return *this;
	}

	inline Vector4Ul& Vector4Ul::operator*= (const Vector4Ul& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d;
		return *this;
	}

	inline Vector4Ul& Vector4Ul::operator/= (const Vector4Ul& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d;
		return *this;
	}


	inline Vector4Ul& Vector4Ul::operator+= (const unsigned long& number) noexcept {
		a += number; b += number; c += number; d += number;
		return *this;
	}

	inline Vector4Ul& Vector4Ul::operator-= (const unsigned long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number;
		return *this;
	}

	inline Vector4Ul& Vector4Ul::operator*= (const unsigned long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number;
		return *this;
	}

	inline Vector4Ul& Vector4Ul::operator/= (const unsigned long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector4Ul::operator< (const Vector4Ul& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d;
	}

	inline bool Vector4Ul::operator<= (const Vector4Ul& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d;
	}

	inline bool Vector4Ul::operator>  (const Vector4Ul& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d;
	}

	inline bool Vector4Ul::operator>= (const Vector4Ul& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d;
	}


	inline bool Vector4Ul::operator<  (const unsigned long& number) const noexcept {
		return a < number && b < number && c < number && d < number;
	}

	inline bool Vector4Ul::operator<= (const unsigned long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number;
	}

	inline bool Vector4Ul::operator>  (const unsigned long& number) const noexcept {
		return a > number && b > number && c > number && d > number;
	}

	inline bool Vector4Ul::operator>= (const unsigned long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number;
	}


	// equal / not equal
	inline bool Vector4Ul::operator==(const Vector4Ul& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d;
	}

	inline bool Vector4Ul::operator!=(const Vector4Ul& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d;
	}

	inline bool Vector4Ul::operator==(const unsigned long& number) const noexcept {
		return a == number && b == number && c == number && d == number;
	}

	inline bool Vector4Ul::operator!=(const unsigned long& number) const noexcept {
		return a != number || b != number || c != number || d != number;
	}


	inline constexpr std::uint8_t Vector4Ul::size() const noexcept { return 4; }
	inline void Vector4Ul::reset(const unsigned long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline unsigned long& Vector4Ul::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline unsigned long& Vector4Ul::at(const std::uint8_t& index) noexcept
	{
		unsigned long* ptr = &a;
		if (index > 3)
			return ptr[0];
		return ptr[index];
	}



	// Vector5Ul
	inline Vector5Ul::Vector5Ul(const unsigned long& a, const unsigned long& b, const unsigned long& c, const unsigned long& d,
		const unsigned long& e) noexcept
		: a(a), b(b), c(c), d(d), e(e) {}

	// copy/move constructor and assignment
	inline Vector5Ul::Vector5Ul(const Vector5Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5Ul& Vector5Ul::operator=(const Vector5Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}

	inline Vector5Ul::Vector5Ul(Vector5Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5Ul& Vector5Ul::operator=(Vector5Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}
	// .....................................
	inline Vector5Ul& Vector5Ul::operator=(const unsigned long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; return *this;
	}


	inline Vector5Ul Vector5Ul::operator +(const Vector5Ul& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e };
	}

	inline Vector5Ul Vector5Ul::operator -(const Vector5Ul& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e };
	}

	inline Vector5Ul Vector5Ul::operator *(const Vector5Ul& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e };
	}

	inline Vector5Ul Vector5Ul::operator /(const Vector5Ul& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e };
	}


	inline Vector5Ul Vector5Ul::operator +(const unsigned long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number };
	}

	inline Vector5Ul Vector5Ul::operator -(const unsigned long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number };
	}

	inline Vector5Ul Vector5Ul::operator *(const unsigned long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number };
	}

	inline Vector5Ul Vector5Ul::operator /(const unsigned long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number };
	}


	// increment / decrement
	inline Vector5Ul& Vector5Ul::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e;
		return *this;
	}

	inline Vector5Ul& Vector5Ul::operator-- () noexcept {
		--a; --b; --c; --d; --e;
		return *this;
	}

	inline Vector5Ul Vector5Ul::operator++ (int) noexcept {
		Vector5Ul temp = *this;
		++* this;
		return temp;
	}

	inline Vector5Ul Vector5Ul::operator-- (int) noexcept {
		Vector5Ul temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector5Ul& Vector5Ul::operator+= (const Vector5Ul& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e;
		return *this;
	}

	inline Vector5Ul& Vector5Ul::operator-= (const Vector5Ul& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e;
		return *this;
	}

	inline Vector5Ul& Vector5Ul::operator*= (const Vector5Ul& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e;
		return *this;
	}

	inline Vector5Ul& Vector5Ul::operator/= (const Vector5Ul& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e;
		return *this;
	}


	inline Vector5Ul& Vector5Ul::operator+= (const unsigned long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number;
		return *this;
	}

	inline Vector5Ul& Vector5Ul::operator-= (const unsigned long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number;
		return *this;
	}

	inline Vector5Ul& Vector5Ul::operator*= (const unsigned long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number;
		return *this;
	}

	inline Vector5Ul& Vector5Ul::operator/= (const unsigned long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector5Ul::operator< (const Vector5Ul& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e;
	}

	inline bool Vector5Ul::operator<= (const Vector5Ul& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e;
	}

	inline bool Vector5Ul::operator>  (const Vector5Ul& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e;
	}

	inline bool Vector5Ul::operator>= (const Vector5Ul& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e;
	}


	inline bool Vector5Ul::operator<  (const unsigned long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number;
	}

	inline bool Vector5Ul::operator<= (const unsigned long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number;
	}

	inline bool Vector5Ul::operator>  (const unsigned long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number;
	}

	inline bool Vector5Ul::operator>= (const unsigned long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number;
	}


	// equal / not equal
	inline bool Vector5Ul::operator==(const Vector5Ul& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
	}

	inline bool Vector5Ul::operator!=(const Vector5Ul& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e;
	}

	inline bool Vector5Ul::operator==(const unsigned long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number;
	}

	inline bool Vector5Ul::operator!=(const unsigned long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number;
	}


	inline constexpr std::uint8_t Vector5Ul::size() const noexcept { return 5; }
	inline void Vector5Ul::reset(const unsigned long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline unsigned long& Vector5Ul::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline unsigned long& Vector5Ul::at(const std::uint8_t& index) noexcept
	{
		unsigned long* ptr = &a;
		if (index > 4)
			return ptr[0];
		return ptr[index];
	}



	// Vector6Ul
	inline Vector6Ul::Vector6Ul(const unsigned long& a, const unsigned long& b, const unsigned long& c, const unsigned long& d,
		const unsigned long& e, const unsigned long& f) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f) {}

	// copy/move constructor and assignment
	inline Vector6Ul::Vector6Ul(const Vector6Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6Ul& Vector6Ul::operator=(const Vector6Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}

	inline Vector6Ul::Vector6Ul(Vector6Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6Ul& Vector6Ul::operator=(Vector6Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}
	// .....................................
	inline Vector6Ul& Vector6Ul::operator=(const unsigned long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; return *this;
	}


	inline Vector6Ul Vector6Ul::operator +(const Vector6Ul& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f };
	}

	inline Vector6Ul Vector6Ul::operator -(const Vector6Ul& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f };
	}

	inline Vector6Ul Vector6Ul::operator *(const Vector6Ul& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f };
	}

	inline Vector6Ul Vector6Ul::operator /(const Vector6Ul& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f };
	}


	inline Vector6Ul Vector6Ul::operator +(const unsigned long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number };
	}

	inline Vector6Ul Vector6Ul::operator -(const unsigned long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number };
	}

	inline Vector6Ul Vector6Ul::operator *(const unsigned long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number };
	}

	inline Vector6Ul Vector6Ul::operator /(const unsigned long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number };
	}


	// increment / decrement
	inline Vector6Ul& Vector6Ul::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f;
		return *this;
	}

	inline Vector6Ul& Vector6Ul::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f;
		return *this;
	}

	inline Vector6Ul Vector6Ul::operator++ (int) noexcept {
		Vector6Ul temp = *this;
		++* this;
		return temp;
	}

	inline Vector6Ul Vector6Ul::operator-- (int) noexcept {
		Vector6Ul temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector6Ul& Vector6Ul::operator+= (const Vector6Ul& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f;
		return *this;
	}

	inline Vector6Ul& Vector6Ul::operator-= (const Vector6Ul& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f;
		return *this;
	}

	inline Vector6Ul& Vector6Ul::operator*= (const Vector6Ul& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f;
		return *this;
	}

	inline Vector6Ul& Vector6Ul::operator/= (const Vector6Ul& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f;
		return *this;
	}


	inline Vector6Ul& Vector6Ul::operator+= (const unsigned long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number;
		return *this;
	}

	inline Vector6Ul& Vector6Ul::operator-= (const unsigned long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number;
		return *this;
	}

	inline Vector6Ul& Vector6Ul::operator*= (const unsigned long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number;
		return *this;
	}

	inline Vector6Ul& Vector6Ul::operator/= (const unsigned long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector6Ul::operator< (const Vector6Ul& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f;
	}

	inline bool Vector6Ul::operator<= (const Vector6Ul& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f;
	}

	inline bool Vector6Ul::operator>  (const Vector6Ul& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f;
	}

	inline bool Vector6Ul::operator>= (const Vector6Ul& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f;
	}


	inline bool Vector6Ul::operator<  (const unsigned long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number;
	}

	inline bool Vector6Ul::operator<= (const unsigned long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number;
	}

	inline bool Vector6Ul::operator>  (const unsigned long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number;
	}

	inline bool Vector6Ul::operator>= (const unsigned long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number;
	}


	// equal / not equal
	inline bool Vector6Ul::operator==(const Vector6Ul& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f;
	}

	inline bool Vector6Ul::operator!=(const Vector6Ul& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f;
	}

	inline bool Vector6Ul::operator==(const unsigned long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number;
	}

	inline bool Vector6Ul::operator!=(const unsigned long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number;
	}


	inline constexpr std::uint8_t Vector6Ul::size() const noexcept { return 6; }
	inline void Vector6Ul::reset(const unsigned long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline unsigned long& Vector6Ul::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline unsigned long& Vector6Ul::at(const std::uint8_t& index) noexcept
	{
		unsigned long* ptr = &a;
		if (index > 5)
			return ptr[0];
		return ptr[index];
	}



	// Vector7Ul
	inline Vector7Ul::Vector7Ul(const unsigned long& a, const unsigned long& b, const unsigned long& c, const unsigned long& d,
		const unsigned long& e, const unsigned long& f, const unsigned long& g) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g) {}

	// copy/move constructor and assignment
	inline Vector7Ul::Vector7Ul(const Vector7Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7Ul& Vector7Ul::operator=(const Vector7Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}

	inline Vector7Ul::Vector7Ul(Vector7Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7Ul& Vector7Ul::operator=(Vector7Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}
	// .....................................
	inline Vector7Ul& Vector7Ul::operator=(const unsigned long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; return *this;
	}


	inline Vector7Ul Vector7Ul::operator +(const Vector7Ul& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g };
	}

	inline Vector7Ul Vector7Ul::operator -(const Vector7Ul& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g };
	}

	inline Vector7Ul Vector7Ul::operator *(const Vector7Ul& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g };
	}

	inline Vector7Ul Vector7Ul::operator /(const Vector7Ul& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g };
	}


	inline Vector7Ul Vector7Ul::operator +(const unsigned long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number };
	}

	inline Vector7Ul Vector7Ul::operator -(const unsigned long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number };
	}

	inline Vector7Ul Vector7Ul::operator *(const unsigned long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number };
	}

	inline Vector7Ul Vector7Ul::operator /(const unsigned long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number };
	}


	// increment / decrement
	inline Vector7Ul& Vector7Ul::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g;
		return *this;
	}

	inline Vector7Ul& Vector7Ul::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g;
		return *this;
	}

	inline Vector7Ul Vector7Ul::operator++ (int) noexcept {
		Vector7Ul temp = *this;
		++* this;
		return temp;
	}

	inline Vector7Ul Vector7Ul::operator-- (int) noexcept {
		Vector7Ul temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector7Ul& Vector7Ul::operator+= (const Vector7Ul& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g;
		return *this;
	}

	inline Vector7Ul& Vector7Ul::operator-= (const Vector7Ul& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g;
		return *this;
	}

	inline Vector7Ul& Vector7Ul::operator*= (const Vector7Ul& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g;
		return *this;
	}

	inline Vector7Ul& Vector7Ul::operator/= (const Vector7Ul& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g;
		return *this;
	}


	inline Vector7Ul& Vector7Ul::operator+= (const unsigned long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number;
		return *this;
	}

	inline Vector7Ul& Vector7Ul::operator-= (const unsigned long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number;
		return *this;
	}

	inline Vector7Ul& Vector7Ul::operator*= (const unsigned long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number;
		return *this;
	}

	inline Vector7Ul& Vector7Ul::operator/= (const unsigned long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector7Ul::operator< (const Vector7Ul& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g;
	}

	inline bool Vector7Ul::operator<= (const Vector7Ul& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g;
	}

	inline bool Vector7Ul::operator>  (const Vector7Ul& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g;
	}

	inline bool Vector7Ul::operator>= (const Vector7Ul& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g;
	}


	inline bool Vector7Ul::operator<  (const unsigned long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number;
	}

	inline bool Vector7Ul::operator<= (const unsigned long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number;
	}

	inline bool Vector7Ul::operator>  (const unsigned long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number;
	}

	inline bool Vector7Ul::operator>= (const unsigned long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number;
	}


	// equal / not equal
	inline bool Vector7Ul::operator==(const Vector7Ul& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g;
	}

	inline bool Vector7Ul::operator!=(const Vector7Ul& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g;
	}

	inline bool Vector7Ul::operator==(const unsigned long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number;
	}

	inline bool Vector7Ul::operator!=(const unsigned long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number;
	}


	inline constexpr std::uint8_t Vector7Ul::size() const noexcept { return 7; }
	inline void Vector7Ul::reset(const unsigned long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline unsigned long& Vector7Ul::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline unsigned long& Vector7Ul::at(const std::uint8_t& index) noexcept
	{
		unsigned long* ptr = &a;
		if (index > 6)
			return ptr[0];
		return ptr[index];
	}



	// Vector8Ul
	inline Vector8Ul::Vector8Ul(const unsigned long& a, const unsigned long& b, const unsigned long& c, const unsigned long& d,
		const unsigned long& e, const unsigned long& f, const unsigned long& g, const unsigned long& h) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h) {}

	// copy/move constructor and assignment
	inline Vector8Ul::Vector8Ul(const Vector8Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8Ul& Vector8Ul::operator=(const Vector8Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}

	inline Vector8Ul::Vector8Ul(Vector8Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8Ul& Vector8Ul::operator=(Vector8Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}
	// .....................................
	inline Vector8Ul& Vector8Ul::operator=(const unsigned long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; return *this;
	}


	inline Vector8Ul Vector8Ul::operator +(const Vector8Ul& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h };
	}

	inline Vector8Ul Vector8Ul::operator -(const Vector8Ul& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h };
	}

	inline Vector8Ul Vector8Ul::operator *(const Vector8Ul& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h };
	}

	inline Vector8Ul Vector8Ul::operator /(const Vector8Ul& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h };
	}


	inline Vector8Ul Vector8Ul::operator +(const unsigned long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number };
	}

	inline Vector8Ul Vector8Ul::operator -(const unsigned long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number };
	}

	inline Vector8Ul Vector8Ul::operator *(const unsigned long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number };
	}

	inline Vector8Ul Vector8Ul::operator /(const unsigned long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number };
	}


	// increment / decrement
	inline Vector8Ul& Vector8Ul::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h;
		return *this;
	}

	inline Vector8Ul& Vector8Ul::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h;
		return *this;
	}

	inline Vector8Ul Vector8Ul::operator++ (int) noexcept {
		Vector8Ul temp = *this;
		++* this;
		return temp;
	}

	inline Vector8Ul Vector8Ul::operator-- (int) noexcept {
		Vector8Ul temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector8Ul& Vector8Ul::operator+= (const Vector8Ul& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h;
		return *this;
	}

	inline Vector8Ul& Vector8Ul::operator-= (const Vector8Ul& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h;
		return *this;
	}

	inline Vector8Ul& Vector8Ul::operator*= (const Vector8Ul& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h;
		return *this;
	}

	inline Vector8Ul& Vector8Ul::operator/= (const Vector8Ul& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h;
		return *this;
	}


	inline Vector8Ul& Vector8Ul::operator+= (const unsigned long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number;
		return *this;
	}

	inline Vector8Ul& Vector8Ul::operator-= (const unsigned long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number;
		return *this;
	}

	inline Vector8Ul& Vector8Ul::operator*= (const unsigned long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number;
		return *this;
	}

	inline Vector8Ul& Vector8Ul::operator/= (const unsigned long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector8Ul::operator< (const Vector8Ul& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h;
	}

	inline bool Vector8Ul::operator<= (const Vector8Ul& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h;
	}

	inline bool Vector8Ul::operator>  (const Vector8Ul& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h;
	}

	inline bool Vector8Ul::operator>= (const Vector8Ul& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h;
	}


	inline bool Vector8Ul::operator<  (const unsigned long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number;
	}

	inline bool Vector8Ul::operator<= (const unsigned long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number;
	}

	inline bool Vector8Ul::operator>  (const unsigned long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number;
	}

	inline bool Vector8Ul::operator>= (const unsigned long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number;
	}


	// equal / not equal
	inline bool Vector8Ul::operator==(const Vector8Ul& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h;
	}

	inline bool Vector8Ul::operator!=(const Vector8Ul& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h;
	}

	inline bool Vector8Ul::operator==(const unsigned long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number;
	}

	inline bool Vector8Ul::operator!=(const unsigned long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number;
	}


	inline constexpr std::uint8_t Vector8Ul::size() const noexcept { return 8; }
	inline void Vector8Ul::reset(const unsigned long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline unsigned long& Vector8Ul::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline unsigned long& Vector8Ul::at(const std::uint8_t& index) noexcept
	{
		unsigned long* ptr = &a;
		if (index > 7)
			return ptr[0];
		return ptr[index];
	}



	// Vector9Ul
	inline Vector9Ul::Vector9Ul(const unsigned long& a, const unsigned long& b, const unsigned long& c, const unsigned long& d,
		const unsigned long& e, const unsigned long& f, const unsigned long& g, const unsigned long& h,
		const unsigned long& i) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

	// copy/move constructor and assignment
	inline Vector9Ul::Vector9Ul(const Vector9Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9Ul& Vector9Ul::operator=(const Vector9Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}

	inline Vector9Ul::Vector9Ul(Vector9Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9Ul& Vector9Ul::operator=(Vector9Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}
	// .....................................
	inline Vector9Ul& Vector9Ul::operator=(const unsigned long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; return *this;
	}


	inline Vector9Ul Vector9Ul::operator +(const Vector9Ul& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i };
	}

	inline Vector9Ul Vector9Ul::operator -(const Vector9Ul& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i };
	}

	inline Vector9Ul Vector9Ul::operator *(const Vector9Ul& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i };
	}

	inline Vector9Ul Vector9Ul::operator /(const Vector9Ul& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i };
	}


	inline Vector9Ul Vector9Ul::operator +(const unsigned long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number };
	}

	inline Vector9Ul Vector9Ul::operator -(const unsigned long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number };
	}

	inline Vector9Ul Vector9Ul::operator *(const unsigned long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number };
	}

	inline Vector9Ul Vector9Ul::operator /(const unsigned long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number };
	}


	// increment / decrement
	inline Vector9Ul& Vector9Ul::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i;
		return *this;
	}

	inline Vector9Ul& Vector9Ul::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i;
		return *this;
	}

	inline Vector9Ul Vector9Ul::operator++ (int) noexcept {
		Vector9Ul temp = *this;
		++* this;
		return temp;
	}

	inline Vector9Ul Vector9Ul::operator-- (int) noexcept {
		Vector9Ul temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector9Ul& Vector9Ul::operator+= (const Vector9Ul& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i;
		return *this;
	}

	inline Vector9Ul& Vector9Ul::operator-= (const Vector9Ul& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i;
		return *this;
	}

	inline Vector9Ul& Vector9Ul::operator*= (const Vector9Ul& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i;
		return *this;
	}

	inline Vector9Ul& Vector9Ul::operator/= (const Vector9Ul& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i;
		return *this;
	}


	inline Vector9Ul& Vector9Ul::operator+= (const unsigned long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number;
		return *this;
	}

	inline Vector9Ul& Vector9Ul::operator-= (const unsigned long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number;
		return *this;
	}

	inline Vector9Ul& Vector9Ul::operator*= (const unsigned long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number;
		return *this;
	}

	inline Vector9Ul& Vector9Ul::operator/= (const unsigned long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector9Ul::operator< (const Vector9Ul& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i;
	}

	inline bool Vector9Ul::operator<= (const Vector9Ul& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i;
	}

	inline bool Vector9Ul::operator>  (const Vector9Ul& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i;
	}

	inline bool Vector9Ul::operator>= (const Vector9Ul& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i;
	}


	inline bool Vector9Ul::operator<  (const unsigned long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number;
	}

	inline bool Vector9Ul::operator<= (const unsigned long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number;
	}

	inline bool Vector9Ul::operator>  (const unsigned long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number;
	}

	inline bool Vector9Ul::operator>= (const unsigned long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number;
	}


	// equal / not equal
	inline bool Vector9Ul::operator==(const Vector9Ul& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i;
	}

	inline bool Vector9Ul::operator!=(const Vector9Ul& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i;
	}

	inline bool Vector9Ul::operator==(const unsigned long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number;
	}

	inline bool Vector9Ul::operator!=(const unsigned long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number;
	}


	inline constexpr std::uint8_t Vector9Ul::size() const noexcept { return 9; }
	inline void Vector9Ul::reset(const unsigned long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline unsigned long& Vector9Ul::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline unsigned long& Vector9Ul::at(const std::uint8_t& index) noexcept
	{
		unsigned long* ptr = &a;
		if (index > 8)
			return ptr[0];
		return ptr[index];
	}



	// Vector10Ul
	inline Vector10Ul::Vector10Ul(const unsigned long& a, const unsigned long& b, const unsigned long& c, const unsigned long& d,
		const unsigned long& e, const unsigned long& f, const unsigned long& g, const unsigned long& h,
		const unsigned long& i, const unsigned long& j) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {}

	// copy/move constructor and assignment
	inline Vector10Ul::Vector10Ul(const Vector10Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10Ul& Vector10Ul::operator=(const Vector10Ul& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}

	inline Vector10Ul::Vector10Ul(Vector10Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10Ul& Vector10Ul::operator=(Vector10Ul&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}
	// .....................................
	inline Vector10Ul& Vector10Ul::operator=(const unsigned long& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; j = number; return *this;
	}


	inline Vector10Ul Vector10Ul::operator +(const Vector10Ul& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i, j + v.j };
	}

	inline Vector10Ul Vector10Ul::operator -(const Vector10Ul& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i, j - v.j };
	}

	inline Vector10Ul Vector10Ul::operator *(const Vector10Ul& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i, j * v.j };
	}

	inline Vector10Ul Vector10Ul::operator /(const Vector10Ul& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i, j / v.j };
	}


	inline Vector10Ul Vector10Ul::operator +(const unsigned long& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number, j + number };
	}

	inline Vector10Ul Vector10Ul::operator -(const unsigned long& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number, j - number };
	}

	inline Vector10Ul Vector10Ul::operator *(const unsigned long& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number, j * number };
	}

	inline Vector10Ul Vector10Ul::operator /(const unsigned long& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number, j / number };
	}


	// increment / decrement
	inline Vector10Ul& Vector10Ul::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i; ++j;
		return *this;
	}

	inline Vector10Ul& Vector10Ul::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i; --j;
		return *this;
	}

	inline Vector10Ul Vector10Ul::operator++ (int) noexcept {
		Vector10Ul temp = *this;
		++* this;
		return temp;
	}

	inline Vector10Ul Vector10Ul::operator-- (int) noexcept {
		Vector10Ul temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector10Ul& Vector10Ul::operator+= (const Vector10Ul& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i; j += right.j;
		return *this;
	}

	inline Vector10Ul& Vector10Ul::operator-= (const Vector10Ul& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i; j -= right.j;
		return *this;
	}

	inline Vector10Ul& Vector10Ul::operator*= (const Vector10Ul& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i; j *= right.j;
		return *this;
	}

	inline Vector10Ul& Vector10Ul::operator/= (const Vector10Ul& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i; j /= right.j;
		return *this;
	}


	inline Vector10Ul& Vector10Ul::operator+= (const unsigned long& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number; j += number;
		return *this;
	}

	inline Vector10Ul& Vector10Ul::operator-= (const unsigned long& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number; j -= number;
		return *this;
	}

	inline Vector10Ul& Vector10Ul::operator*= (const unsigned long& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number; j *= number;
		return *this;
	}

	inline Vector10Ul& Vector10Ul::operator/= (const unsigned long& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number; j /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector10Ul::operator< (const Vector10Ul& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i&& j < other.j;
	}

	inline bool Vector10Ul::operator<= (const Vector10Ul& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i && j <= other.j;
	}

	inline bool Vector10Ul::operator>  (const Vector10Ul& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i && j > other.j;
	}

	inline bool Vector10Ul::operator>= (const Vector10Ul& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i && j >= other.j;
	}


	inline bool Vector10Ul::operator<  (const unsigned long& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number && j < number;
	}

	inline bool Vector10Ul::operator<= (const unsigned long& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number && j <= number;
	}

	inline bool Vector10Ul::operator>  (const unsigned long& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number && j > number;
	}

	inline bool Vector10Ul::operator>= (const unsigned long& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number && j >= number;
	}


	// equal / not equal
	inline bool Vector10Ul::operator==(const Vector10Ul& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i && j == other.j;
	}

	inline bool Vector10Ul::operator!=(const Vector10Ul& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i || j != other.j;
	}

	inline bool Vector10Ul::operator==(const unsigned long& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number && j == number;
	}

	inline bool Vector10Ul::operator!=(const unsigned long& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number || j != number;
	}


	inline constexpr std::uint8_t Vector10Ul::size() const noexcept { return 10; }
	inline void Vector10Ul::reset(const unsigned long& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline unsigned long& Vector10Ul::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline unsigned long& Vector10Ul::at(const std::uint8_t& index) noexcept
	{
		unsigned long* ptr = &a;
		if (index > 9)
			return ptr[0];
		return ptr[index];
	}
	// End
}