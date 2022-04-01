#include "VectorD.h"

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::double_t
		Bytes: 8
		Range: 1.7E +/- 308  precision: (15 digits)
	*/

	// Vector2d
	inline Vector2d::Vector2d(const std::double_t& x, const std::double_t& y) noexcept
		: x(x), y(y) {}

	// copy/move constructor and assignment
	inline Vector2d::Vector2d(const Vector2d& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2d& Vector2d::operator=(const Vector2d& other) noexcept {
		x = other.x; y = other.y; return *this;
	}

	inline Vector2d::Vector2d(Vector2d&& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2d& Vector2d::operator=(Vector2d&& other) noexcept {
		x = other.x; y = other.y; return *this;
	}
	// .....................................
	inline Vector2d& Vector2d::operator=(const std::double_t& number) noexcept {
		x = number; y = number; return *this;
	}


	inline Vector2d Vector2d::operator +(const Vector2d& v) const noexcept {
		return { x + v.x, y + v.y };
	}

	inline Vector2d Vector2d::operator -(const Vector2d& v) const noexcept {
		return { x - v.x, y - v.y };
	}

	inline Vector2d Vector2d::operator *(const Vector2d& v) const noexcept {
		return { x * v.x, y * v.y };
	}

	inline Vector2d Vector2d::operator /(const Vector2d& v) const noexcept {
		return { x / v.x, y / v.y };
	}


	inline Vector2d Vector2d::operator +(const std::double_t& number) const noexcept {
		return { x + number, y + number };
	}

	inline Vector2d Vector2d::operator -(const std::double_t& number) const noexcept {
		return { x - number, y - number };
	}

	inline Vector2d Vector2d::operator *(const std::double_t& number) const noexcept {
		return { x * number, y * number };
	}

	inline Vector2d Vector2d::operator /(const std::double_t& number) const noexcept {
		return { x / number, y / number };
	}


	// increment / decrement
	inline Vector2d& Vector2d::operator++ () noexcept {
		++x; ++y;
		return *this;
	}

	inline Vector2d& Vector2d::operator-- ()  noexcept {
		--x; --y;
		return *this;
	}

	inline Vector2d Vector2d::operator++ (int) noexcept {
		Vector2d temp = *this;
		++* this;
		return temp;
	}

	inline Vector2d Vector2d::operator-- (int) noexcept {
		Vector2d temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector2d& Vector2d::operator+= (const Vector2d& right) noexcept {
		x += right.x; y += right.y;
		return *this;
	}

	inline Vector2d& Vector2d::operator-= (const Vector2d& right) noexcept {
		x -= right.x; y -= right.y;
		return *this;
	}

	inline Vector2d& Vector2d::operator*= (const Vector2d& right) noexcept {
		x *= right.x; y *= right.y;
		return *this;
	}

	inline Vector2d& Vector2d::operator/= (const Vector2d& right) noexcept {
		x /= right.x; y /= right.y;
		return *this;
	}


	inline Vector2d& Vector2d::operator+= (const std::double_t& number) noexcept {
		x += number; y += number;
		return *this;
	}

	inline Vector2d& Vector2d::operator-= (const std::double_t& number) noexcept {
		x -= number; y -= number;
		return *this;
	}

	inline Vector2d& Vector2d::operator*= (const std::double_t& number) noexcept {
		x *= number; y *= number;
		return *this;
	}

	inline Vector2d& Vector2d::operator/= (const std::double_t& number) noexcept {
		x /= number; y /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector2d::operator< (const Vector2d& other) const noexcept {
		return x < other.x && y < other.y;
	}

	inline bool Vector2d::operator<= (const Vector2d& other) const noexcept {
		return x <= other.x && y <= other.y;
	}

	inline bool Vector2d::operator>  (const Vector2d& other) const noexcept {
		return x > other.x && y > other.y;
	}

	inline bool Vector2d::operator>= (const Vector2d& other) const noexcept {
		return x >= other.x && y >= other.y;
	}


	inline bool Vector2d::operator<  (const std::double_t& number) const noexcept {
		return x < number && y < number;
	}

	inline bool Vector2d::operator<= (const std::double_t& number) const noexcept {
		return x <= number && y <= number;
	}

	inline bool Vector2d::operator>  (const std::double_t& number) const noexcept {
		return x > number && y > number;
	}

	inline bool Vector2d::operator>= (const std::double_t& number) const noexcept {
		return x >= number && y >= number;
	}


	// equal / not equal
	inline bool Vector2d::operator==(const Vector2d& other) const noexcept {
		return x == other.x && y == other.y;
	}

	inline bool Vector2d::operator!=(const Vector2d& other) const noexcept {
		return x != other.x || y != other.y;
	}

	inline bool Vector2d::operator==(const std::double_t& number) const noexcept {
		return x == number && y == number;
	}

	inline bool Vector2d::operator!=(const std::double_t& number) const noexcept {
		return x != number || y != number;
	}


	inline constexpr std::uint8_t Vector2d::size() const noexcept { return 2; }
	inline void Vector2d::reset(const std::double_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::double_t& Vector2d::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::double_t& Vector2d::at(const std::uint8_t& index) noexcept
	{
		std::double_t* ptr = &x;
		if (index > 1)
			return ptr[0];
		return ptr[index];
	}



	// Vector3d
	inline Vector3d::Vector3d(const std::double_t& x, const std::double_t& y, const std::double_t& z) noexcept
		: x(x), y(y), z(z) {}

	// copy/move constructor and assignment
	inline Vector3d::Vector3d(const Vector3d& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3d& Vector3d::operator=(const Vector3d& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}

	inline Vector3d::Vector3d(Vector3d&& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3d& Vector3d::operator=(Vector3d&& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}
	// .....................................
	inline Vector3d& Vector3d::operator=(const std::double_t& number) noexcept {
		x = number; y = number; z = number; return *this;
	}


	inline Vector3d Vector3d::operator +(const Vector3d& v) const noexcept {
		return { x + v.x, y + v.y, z + v.z };
	}

	inline Vector3d Vector3d::operator -(const Vector3d& v) const noexcept {
		return { x - v.x, y - v.y, z - v.z };
	}

	inline Vector3d Vector3d::operator *(const Vector3d& v) const noexcept {
		return { x * v.x, y * v.y, z * v.z };
	}

	inline Vector3d Vector3d::operator /(const Vector3d& v) const noexcept {
		return { x / v.x, y / v.y, z / v.z };
	}

 
	inline Vector3d Vector3d::operator +(const std::double_t& number) const noexcept {
		return { x + number, y + number, z + number };
	}

	inline Vector3d Vector3d::operator -(const std::double_t& number) const noexcept {
		return { x - number, y - number, z - number };
	}

	inline Vector3d Vector3d::operator *(const std::double_t& number) const noexcept {
		return { x * number, y * number, z * number };
	}

	inline Vector3d Vector3d::operator /(const std::double_t& number) const noexcept {
		return { x / number, y / number, z / number };
	}


	// increment / decrement
	inline Vector3d& Vector3d::operator++ () noexcept {
		++x; ++y; ++z;
		return *this;
	}

	inline Vector3d& Vector3d::operator-- () noexcept {
		--x; --y; --z;
		return *this;
	}

	inline Vector3d Vector3d::operator++ (int) noexcept {
		Vector3d temp = *this;
		++* this;
		return temp;
	}

	inline Vector3d Vector3d::operator-- (int) noexcept {
		Vector3d temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector3d& Vector3d::operator+= (const Vector3d& right) noexcept {
		x += right.x; y += right.y; z += right.z;
		return *this;
	}

	inline Vector3d& Vector3d::operator-= (const Vector3d& right) noexcept {
		x -= right.x; y -= right.y; z -= right.z;
		return *this;
	}

	inline Vector3d& Vector3d::operator*= (const Vector3d& right) noexcept {
		x *= right.x; y *= right.y; z *= right.z;
		return *this;
	}

	inline Vector3d& Vector3d::operator/= (const Vector3d& right) noexcept {
		x /= right.x; y /= right.y; z /= right.z;
		return *this;
	}


	inline Vector3d& Vector3d::operator+= (const std::double_t& number) noexcept {
		x += number; y += number; z += number;
		return *this;
	}

	inline Vector3d& Vector3d::operator-= (const std::double_t& number) noexcept {
		x -= number; y -= number; z -= number;
		return *this;
	}

	inline Vector3d& Vector3d::operator*= (const std::double_t& number) noexcept {
		x *= number; y *= number; z *= number;
		return *this;
	}

	inline Vector3d& Vector3d::operator/= (const std::double_t& number) noexcept {
		x /= number; y /= number; z /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector3d::operator< (const Vector3d& other) const noexcept {
		return x < other.x && y < other.y&& z < other.z;
	}

	inline bool Vector3d::operator<= (const Vector3d& other) const noexcept {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	inline bool Vector3d::operator>  (const Vector3d& other) const noexcept {
		return x > other.x && y > other.y && z > other.z;
	}

	inline bool Vector3d::operator>= (const Vector3d& other) const noexcept {
		return x >= other.x && y >= other.y && z >= other.z;
	}


	inline bool Vector3d::operator<  (const std::double_t& number) const noexcept {
		return x < number && y < number && z < number;
	}

	inline bool Vector3d::operator<= (const std::double_t& number) const noexcept {
		return x <= number && y <= number && z <= number;
	}

	inline bool Vector3d::operator>  (const std::double_t& number) const noexcept {
		return x > number && y > number && z > number;
	}

	inline bool Vector3d::operator>= (const std::double_t& number) const noexcept {
		return x >= number && y >= number && z >= number;
	}


	// equal / not equal
	inline bool Vector3d::operator==(const Vector3d& other) const noexcept {
		return x == other.x && y == other.y && z == other.z;
	}

	inline bool Vector3d::operator!=(const Vector3d& other) const noexcept {
		return x != other.x || y != other.y || z != other.z;
	}

	inline bool Vector3d::operator==(const std::double_t& number) const noexcept {
		return x == number && y == number && z == number;
	}

	inline bool Vector3d::operator!=(const std::double_t& number) const noexcept {
		return x != number || y != number || z != number;
	}


	inline constexpr std::uint8_t Vector3d::size() const noexcept { return 3; }
	inline void Vector3d::reset(const std::double_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::double_t& Vector3d::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::double_t& Vector3d::at(const std::uint8_t& index) noexcept
	{
		std::double_t* ptr = &x;
		if (index > 2)
			return ptr[0];
		return ptr[index];
	}



	// Vector4d
	inline Vector4d::Vector4d(const std::double_t& a, const std::double_t& b, const std::double_t& c, const std::double_t& d) noexcept
		: a(a), b(b), c(c), d(d) {}

	// copy/move constructor and assignment
	inline Vector4d::Vector4d(const Vector4d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4d& Vector4d::operator=(const Vector4d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}

	inline Vector4d::Vector4d(Vector4d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4d& Vector4d::operator=(Vector4d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}
	// .....................................
	inline Vector4d& Vector4d::operator=(const std::double_t& number) noexcept {
		a = number; b = number; c = number; d = number; return *this;
	}


	inline Vector4d Vector4d::operator +(const Vector4d& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d };
	}

	inline Vector4d Vector4d::operator -(const Vector4d& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d };
	}

	inline Vector4d Vector4d::operator *(const Vector4d& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d };
	}

	inline Vector4d Vector4d::operator /(const Vector4d& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d };
	}


	inline Vector4d Vector4d::operator +(const std::double_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number };
	}

	inline Vector4d Vector4d::operator -(const std::double_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number };
	}

	inline Vector4d Vector4d::operator *(const std::double_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number };
	}

	inline Vector4d Vector4d::operator /(const std::double_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number };
	}


	// increment / decrement
	inline Vector4d& Vector4d::operator++ () noexcept {
		++a; ++b; ++c; ++d;
		return *this;
	}

	inline Vector4d& Vector4d::operator-- () noexcept {
		--a; --b; --c; --d;
		return *this;
	}

	inline Vector4d Vector4d::operator++ (int) noexcept {
		Vector4d temp = *this;
		++* this;
		return temp;
	}

	inline Vector4d Vector4d::operator-- (int) noexcept {
		Vector4d temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector4d& Vector4d::operator+= (const Vector4d& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d;
		return *this;
	}

	inline Vector4d& Vector4d::operator-= (const Vector4d& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d;
		return *this;
	}

	inline Vector4d& Vector4d::operator*= (const Vector4d& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d;
		return *this;
	}

	inline Vector4d& Vector4d::operator/= (const Vector4d& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d;
		return *this;
	}


	inline Vector4d& Vector4d::operator+= (const std::double_t& number) noexcept {
		a += number; b += number; c += number; d += number;
		return *this;
	}

	inline Vector4d& Vector4d::operator-= (const std::double_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number;
		return *this;
	}

	inline Vector4d& Vector4d::operator*= (const std::double_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number;
		return *this;
	}

	inline Vector4d& Vector4d::operator/= (const std::double_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector4d::operator< (const Vector4d& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d;
	}

	inline bool Vector4d::operator<= (const Vector4d& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d;
	}

	inline bool Vector4d::operator>  (const Vector4d& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d;
	}

	inline bool Vector4d::operator>= (const Vector4d& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d;
	}


	inline bool Vector4d::operator<  (const std::double_t& number) const noexcept {
		return a < number && b < number && c < number && d < number;
	}

	inline bool Vector4d::operator<= (const std::double_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number;
	}

	inline bool Vector4d::operator>  (const std::double_t& number) const noexcept {
		return a > number && b > number && c > number && d > number;
	}

	inline bool Vector4d::operator>= (const std::double_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number;
	}


	// equal / not equal
	inline bool Vector4d::operator==(const Vector4d& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d;
	}

	inline bool Vector4d::operator!=(const Vector4d& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d;
	}

	inline bool Vector4d::operator==(const std::double_t& number) const noexcept {
		return a == number && b == number && c == number && d == number;
	}

	inline bool Vector4d::operator!=(const std::double_t& number) const noexcept {
		return a != number || b != number || c != number || d != number;
	}


	inline constexpr std::uint8_t Vector4d::size() const noexcept { return 4; }
	inline void Vector4d::reset(const std::double_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::double_t& Vector4d::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::double_t& Vector4d::at(const std::uint8_t& index) noexcept
	{
		std::double_t* ptr = &a;
		if (index > 3)
			return ptr[0];
		return ptr[index];
	}



	// Vector5d
	inline Vector5d::Vector5d(const std::double_t& a, const std::double_t& b, const std::double_t& c, const std::double_t& d,
		const std::double_t& e) noexcept
		: a(a), b(b), c(c), d(d), e(e) {}

	// copy/move constructor and assignment
	inline Vector5d::Vector5d(const Vector5d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5d& Vector5d::operator=(const Vector5d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}

	inline Vector5d::Vector5d(Vector5d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5d& Vector5d::operator=(Vector5d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}
	// .....................................
	inline Vector5d& Vector5d::operator=(const std::double_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; return *this;
	}


	inline Vector5d Vector5d::operator +(const Vector5d& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e };
	}

	inline Vector5d Vector5d::operator -(const Vector5d& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e };
	}

	inline Vector5d Vector5d::operator *(const Vector5d& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e };
	}

	inline Vector5d Vector5d::operator /(const Vector5d& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e };
	}


	inline Vector5d Vector5d::operator +(const std::double_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number };
	}

	inline Vector5d Vector5d::operator -(const std::double_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number };
	}

	inline Vector5d Vector5d::operator *(const std::double_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number };
	}

	inline Vector5d Vector5d::operator /(const std::double_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number };
	}


	// increment / decrement
	inline Vector5d& Vector5d::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e;
		return *this;
	}

	inline Vector5d& Vector5d::operator-- () noexcept {
		--a; --b; --c; --d; --e;
		return *this;
	}

	inline Vector5d Vector5d::operator++ (int) noexcept {
		Vector5d temp = *this;
		++* this;
		return temp;
	}

	inline Vector5d Vector5d::operator-- (int) noexcept {
		Vector5d temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector5d& Vector5d::operator+= (const Vector5d& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e;
		return *this;
	}

	inline Vector5d& Vector5d::operator-= (const Vector5d& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e;
		return *this;
	}

	inline Vector5d& Vector5d::operator*= (const Vector5d& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e;
		return *this;
	}

	inline Vector5d& Vector5d::operator/= (const Vector5d& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e;
		return *this;
	}


	inline Vector5d& Vector5d::operator+= (const std::double_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number;
		return *this;
	}

	inline Vector5d& Vector5d::operator-= (const std::double_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number;
		return *this;
	}

	inline Vector5d& Vector5d::operator*= (const std::double_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number;
		return *this;
	}

	inline Vector5d& Vector5d::operator/= (const std::double_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector5d::operator< (const Vector5d& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e;
	}

	inline bool Vector5d::operator<= (const Vector5d& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e;
	}

	inline bool Vector5d::operator>  (const Vector5d& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e;
	}

	inline bool Vector5d::operator>= (const Vector5d& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e;
	}


	inline bool Vector5d::operator<  (const std::double_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number;
	}

	inline bool Vector5d::operator<= (const std::double_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number;
	}

	inline bool Vector5d::operator>  (const std::double_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number;
	}

	inline bool Vector5d::operator>= (const std::double_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number;
	}


	// equal / not equal
	inline bool Vector5d::operator==(const Vector5d& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
	}

	inline bool Vector5d::operator!=(const Vector5d& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e;
	}

	inline bool Vector5d::operator==(const std::double_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number;
	}

	inline bool Vector5d::operator!=(const std::double_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number;
	}


	inline constexpr std::uint8_t Vector5d::size() const noexcept { return 5; }
	inline void Vector5d::reset(const std::double_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::double_t& Vector5d::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::double_t& Vector5d::at(const std::uint8_t& index) noexcept
	{
		std::double_t* ptr = &a;
		if (index > 4)
			return ptr[0];
		return ptr[index];
	}



	// Vector6d
	inline Vector6d::Vector6d(const std::double_t& a, const std::double_t& b, const std::double_t& c, const std::double_t& d,
		const std::double_t& e, const std::double_t& f) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f) {}

	// copy/move constructor and assignment
	inline Vector6d::Vector6d(const Vector6d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6d& Vector6d::operator=(const Vector6d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}

	inline Vector6d::Vector6d(Vector6d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6d& Vector6d::operator=(Vector6d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}
	// .....................................
	inline Vector6d& Vector6d::operator=(const std::double_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; return *this;
	}


	inline Vector6d Vector6d::operator +(const Vector6d& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f };
	}

	inline Vector6d Vector6d::operator -(const Vector6d& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f };
	}

	inline Vector6d Vector6d::operator *(const Vector6d& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f };
	}

	inline Vector6d Vector6d::operator /(const Vector6d& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f };
	}


	inline Vector6d Vector6d::operator +(const std::double_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number };
	}

	inline Vector6d Vector6d::operator -(const std::double_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number };
	}

	inline Vector6d Vector6d::operator *(const std::double_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number };
	}

	inline Vector6d Vector6d::operator /(const std::double_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number };
	}


	// increment / decrement
	inline Vector6d& Vector6d::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f;
		return *this;
	}

	inline Vector6d& Vector6d::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f;
		return *this;
	}

	inline Vector6d Vector6d::operator++ (int) noexcept {
		Vector6d temp = *this;
		++* this;
		return temp;
	}

	inline Vector6d Vector6d::operator-- (int) noexcept {
		Vector6d temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector6d& Vector6d::operator+= (const Vector6d& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f;
		return *this;
	}

	inline Vector6d& Vector6d::operator-= (const Vector6d& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f;
		return *this;
	}

	inline Vector6d& Vector6d::operator*= (const Vector6d& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f;
		return *this;
	}

	inline Vector6d& Vector6d::operator/= (const Vector6d& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f;
		return *this;
	}


	inline Vector6d& Vector6d::operator+= (const std::double_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number;
		return *this;
	}

	inline Vector6d& Vector6d::operator-= (const std::double_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number;
		return *this;
	}

	inline Vector6d& Vector6d::operator*= (const std::double_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number;
		return *this;
	}

	inline Vector6d& Vector6d::operator/= (const std::double_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector6d::operator< (const Vector6d& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f;
	}

	inline bool Vector6d::operator<= (const Vector6d& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f;
	}

	inline bool Vector6d::operator>  (const Vector6d& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f;
	}

	inline bool Vector6d::operator>= (const Vector6d& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f;
	}


	inline bool Vector6d::operator<  (const std::double_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number;
	}

	inline bool Vector6d::operator<= (const std::double_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number;
	}

	inline bool Vector6d::operator>  (const std::double_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number;
	}

	inline bool Vector6d::operator>= (const std::double_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number;
	}


	// equal / not equal
	inline bool Vector6d::operator==(const Vector6d& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f;
	}

	inline bool Vector6d::operator!=(const Vector6d& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f;
	}

	inline bool Vector6d::operator==(const std::double_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number;
	}

	inline bool Vector6d::operator!=(const std::double_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number;
	}


	inline constexpr std::uint8_t Vector6d::size() const noexcept { return 6; }
	inline void Vector6d::reset(const std::double_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::double_t& Vector6d::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::double_t& Vector6d::at(const std::uint8_t& index) noexcept
	{
		std::double_t* ptr = &a;
		if (index > 5)
			return ptr[0];
		return ptr[index];
	}



	// Vector7d
	inline Vector7d::Vector7d(const std::double_t& a, const std::double_t& b, const std::double_t& c, const std::double_t& d,
		const std::double_t& e, const std::double_t& f, const std::double_t& g) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g) {}

	// copy/move constructor and assignment
	inline Vector7d::Vector7d(const Vector7d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7d& Vector7d::operator=(const Vector7d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}

	inline Vector7d::Vector7d(Vector7d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7d& Vector7d::operator=(Vector7d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}
	// .....................................
	inline Vector7d& Vector7d::operator=(const std::double_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; return *this;
	}


	inline Vector7d Vector7d::operator +(const Vector7d& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g };
	}

	inline Vector7d Vector7d::operator -(const Vector7d& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g };
	}

	inline Vector7d Vector7d::operator *(const Vector7d& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g };
	}

	inline Vector7d Vector7d::operator /(const Vector7d& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g };
	}


	inline Vector7d Vector7d::operator +(const std::double_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number };
	}

	inline Vector7d Vector7d::operator -(const std::double_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number };
	}

	inline Vector7d Vector7d::operator *(const std::double_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number };
	}

	inline Vector7d Vector7d::operator /(const std::double_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number };
	}


	// increment / decrement
	inline Vector7d& Vector7d::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g;
		return *this;
	}

	inline Vector7d& Vector7d::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g;
		return *this;
	}

	inline Vector7d Vector7d::operator++ (int) noexcept {
		Vector7d temp = *this;
		++* this;
		return temp;
	}

	inline Vector7d Vector7d::operator-- (int) noexcept {
		Vector7d temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector7d& Vector7d::operator+= (const Vector7d& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g;
		return *this;
	}

	inline Vector7d& Vector7d::operator-= (const Vector7d& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g;
		return *this;
	}

	inline Vector7d& Vector7d::operator*= (const Vector7d& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g;
		return *this;
	}

	inline Vector7d& Vector7d::operator/= (const Vector7d& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g;
		return *this;
	}


	inline Vector7d& Vector7d::operator+= (const std::double_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number;
		return *this;
	}

	inline Vector7d& Vector7d::operator-= (const std::double_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number;
		return *this;
	}

	inline Vector7d& Vector7d::operator*= (const std::double_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number;
		return *this;
	}

	inline Vector7d& Vector7d::operator/= (const std::double_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector7d::operator< (const Vector7d& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g;
	}

	inline bool Vector7d::operator<= (const Vector7d& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g;
	}

	inline bool Vector7d::operator>  (const Vector7d& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g;
	}

	inline bool Vector7d::operator>= (const Vector7d& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g;
	}


	inline bool Vector7d::operator<  (const std::double_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number;
	}

	inline bool Vector7d::operator<= (const std::double_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number;
	}

	inline bool Vector7d::operator>  (const std::double_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number;
	}

	inline bool Vector7d::operator>= (const std::double_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number;
	}


	// equal / not equal
	inline bool Vector7d::operator==(const Vector7d& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g;
	}

	inline bool Vector7d::operator!=(const Vector7d& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g;
	}

	inline bool Vector7d::operator==(const std::double_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number;
	}

	inline bool Vector7d::operator!=(const std::double_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number;
	}


	inline constexpr std::uint8_t Vector7d::size() const noexcept { return 7; }
	inline void Vector7d::reset(const std::double_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::double_t& Vector7d::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::double_t& Vector7d::at(const std::uint8_t& index) noexcept
	{
		std::double_t* ptr = &a;
		if (index > 6)
			return ptr[0];
		return ptr[index];
	}



	// Vector8d
	inline Vector8d::Vector8d(const std::double_t& a, const std::double_t& b, const std::double_t& c, const std::double_t& d,
		const std::double_t& e, const std::double_t& f, const std::double_t& g, const std::double_t& h) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h) {}

	// copy/move constructor and assignment
	inline Vector8d::Vector8d(const Vector8d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8d& Vector8d::operator=(const Vector8d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}

	inline Vector8d::Vector8d(Vector8d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8d& Vector8d::operator=(Vector8d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}
	// .....................................
	inline Vector8d& Vector8d::operator=(const std::double_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; return *this;
	}


	inline Vector8d Vector8d::operator +(const Vector8d& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h };
	}

	inline Vector8d Vector8d::operator -(const Vector8d& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h };
	}

	inline Vector8d Vector8d::operator *(const Vector8d& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h };
	}

	inline Vector8d Vector8d::operator /(const Vector8d& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h };
	}


	inline Vector8d Vector8d::operator +(const std::double_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number };
	}

	inline Vector8d Vector8d::operator -(const std::double_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number };
	}

	inline Vector8d Vector8d::operator *(const std::double_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number };
	}

	inline Vector8d Vector8d::operator /(const std::double_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number };
	}


	// increment / decrement
	inline Vector8d& Vector8d::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h;
		return *this;
	}

	inline Vector8d& Vector8d::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h;
		return *this;
	}

	inline Vector8d Vector8d::operator++ (int) noexcept {
		Vector8d temp = *this;
		++* this;
		return temp;
	}

	inline Vector8d Vector8d::operator-- (int) noexcept {
		Vector8d temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector8d& Vector8d::operator+= (const Vector8d& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h;
		return *this;
	}

	inline Vector8d& Vector8d::operator-= (const Vector8d& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h;
		return *this;
	}

	inline Vector8d& Vector8d::operator*= (const Vector8d& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h;
		return *this;
	}

	inline Vector8d& Vector8d::operator/= (const Vector8d& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h;
		return *this;
	}


	inline Vector8d& Vector8d::operator+= (const std::double_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number;
		return *this;
	}

	inline Vector8d& Vector8d::operator-= (const std::double_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number;
		return *this;
	}

	inline Vector8d& Vector8d::operator*= (const std::double_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number;
		return *this;
	}

	inline Vector8d& Vector8d::operator/= (const std::double_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector8d::operator< (const Vector8d& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h;
	}

	inline bool Vector8d::operator<= (const Vector8d& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h;
	}

	inline bool Vector8d::operator>  (const Vector8d& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h;
	}

	inline bool Vector8d::operator>= (const Vector8d& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h;
	}


	inline bool Vector8d::operator<  (const std::double_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number;
	}

	inline bool Vector8d::operator<= (const std::double_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number;
	}

	inline bool Vector8d::operator>  (const std::double_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number;
	}

	inline bool Vector8d::operator>= (const std::double_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number;
	}


	// equal / not equal
	inline bool Vector8d::operator==(const Vector8d& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h;
	}

	inline bool Vector8d::operator!=(const Vector8d& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h;
	}

	inline bool Vector8d::operator==(const std::double_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number;
	}

	inline bool Vector8d::operator!=(const std::double_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number;
	}


	inline constexpr std::uint8_t Vector8d::size() const noexcept { return 8; }
	inline void Vector8d::reset(const std::double_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::double_t& Vector8d::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::double_t& Vector8d::at(const std::uint8_t& index) noexcept
	{
		std::double_t* ptr = &a;
		if (index > 7)
			return ptr[0];
		return ptr[index];
	}



	// Vector9d
	inline Vector9d::Vector9d(const std::double_t& a, const std::double_t& b, const std::double_t& c, const std::double_t& d,
		const std::double_t& e, const std::double_t& f, const std::double_t& g, const std::double_t& h,
		const std::double_t& i) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

	// copy/move constructor and assignment
	inline Vector9d::Vector9d(const Vector9d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9d& Vector9d::operator=(const Vector9d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}

	inline Vector9d::Vector9d(Vector9d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9d& Vector9d::operator=(Vector9d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}
	// .....................................
	inline Vector9d& Vector9d::operator=(const std::double_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; return *this;
	}


	inline Vector9d Vector9d::operator +(const Vector9d& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i };
	}

	inline Vector9d Vector9d::operator -(const Vector9d& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i };
	}

	inline Vector9d Vector9d::operator *(const Vector9d& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i };
	}

	inline Vector9d Vector9d::operator /(const Vector9d& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i };
	}


	inline Vector9d Vector9d::operator +(const std::double_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number };
	}

	inline Vector9d Vector9d::operator -(const std::double_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number };
	}

	inline Vector9d Vector9d::operator *(const std::double_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number };
	}

	inline Vector9d Vector9d::operator /(const std::double_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number };
	}


	// increment / decrement
	inline Vector9d& Vector9d::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i;
		return *this;
	}

	inline Vector9d& Vector9d::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i;
		return *this;
	}

	inline Vector9d Vector9d::operator++ (int) noexcept {
		Vector9d temp = *this;
		++* this;
		return temp;
	}

	inline Vector9d Vector9d::operator-- (int) noexcept {
		Vector9d temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector9d& Vector9d::operator+= (const Vector9d& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i;
		return *this;
	}

	inline Vector9d& Vector9d::operator-= (const Vector9d& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i;
		return *this;
	}

	inline Vector9d& Vector9d::operator*= (const Vector9d& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i;
		return *this;
	}

	inline Vector9d& Vector9d::operator/= (const Vector9d& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i;
		return *this;
	}


	inline Vector9d& Vector9d::operator+= (const std::double_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number;
		return *this;
	}

	inline Vector9d& Vector9d::operator-= (const std::double_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number;
		return *this;
	}

	inline Vector9d& Vector9d::operator*= (const std::double_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number;
		return *this;
	}

	inline Vector9d& Vector9d::operator/= (const std::double_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector9d::operator< (const Vector9d& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i;
	}

	inline bool Vector9d::operator<= (const Vector9d& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i;
	}

	inline bool Vector9d::operator>  (const Vector9d& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i;
	}

	inline bool Vector9d::operator>= (const Vector9d& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i;
	}


	inline bool Vector9d::operator<  (const std::double_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number;
	}

	inline bool Vector9d::operator<= (const std::double_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number;
	}

	inline bool Vector9d::operator>  (const std::double_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number;
	}

	inline bool Vector9d::operator>= (const std::double_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number;
	}


	// equal / not equal
	inline bool Vector9d::operator==(const Vector9d& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i;
	}

	inline bool Vector9d::operator!=(const Vector9d& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i;
	}

	inline bool Vector9d::operator==(const std::double_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number;
	}

	inline bool Vector9d::operator!=(const std::double_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number;
	}


	inline constexpr std::uint8_t Vector9d::size() const noexcept { return 9; }
	inline void Vector9d::reset(const std::double_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::double_t& Vector9d::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::double_t& Vector9d::at(const std::uint8_t& index) noexcept
	{
		std::double_t* ptr = &a;
		if (index > 8)
			return ptr[0];
		return ptr[index];
	}



	// Vector10d
	inline Vector10d::Vector10d(const std::double_t& a, const std::double_t& b, const std::double_t& c, const std::double_t& d,
		const std::double_t& e, const std::double_t& f, const std::double_t& g, const std::double_t& h,
		const std::double_t& i, const std::double_t& j) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {}

	// copy/move constructor and assignment
	inline Vector10d::Vector10d(const Vector10d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10d& Vector10d::operator=(const Vector10d& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}

	inline Vector10d::Vector10d(Vector10d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10d& Vector10d::operator=(Vector10d&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}
	// .....................................
	inline Vector10d& Vector10d::operator=(const std::double_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; j = number; return *this;
	}


	inline Vector10d Vector10d::operator +(const Vector10d& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i, j + v.j };
	}

	inline Vector10d Vector10d::operator -(const Vector10d& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i, j - v.j };
	}

	inline Vector10d Vector10d::operator *(const Vector10d& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i, j * v.j };
	}

	inline Vector10d Vector10d::operator /(const Vector10d& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i, j / v.j };
	}


	inline Vector10d Vector10d::operator +(const std::double_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number, j + number };
	}

	inline Vector10d Vector10d::operator -(const std::double_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number, j - number };
	}

	inline Vector10d Vector10d::operator *(const std::double_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number, j * number };
	}

	inline Vector10d Vector10d::operator /(const std::double_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number, j / number };
	}


	// increment / decrement
	inline Vector10d& Vector10d::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i; ++j;
		return *this;
	}

	inline Vector10d& Vector10d::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i; --j;
		return *this;
	}

	inline Vector10d Vector10d::operator++ (int) noexcept {
		Vector10d temp = *this;
		++* this;
		return temp;
	}

	inline Vector10d Vector10d::operator-- (int) noexcept {
		Vector10d temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector10d& Vector10d::operator+= (const Vector10d& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i; j += right.j;
		return *this;
	}

	inline Vector10d& Vector10d::operator-= (const Vector10d& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i; j -= right.j;
		return *this;
	}

	inline Vector10d& Vector10d::operator*= (const Vector10d& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i; j *= right.j;
		return *this;
	}

	inline Vector10d& Vector10d::operator/= (const Vector10d& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i; j /= right.j;
		return *this;
	}


	inline Vector10d& Vector10d::operator+= (const std::double_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number; j += number;
		return *this;
	}

	inline Vector10d& Vector10d::operator-= (const std::double_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number; j -= number;
		return *this;
	}

	inline Vector10d& Vector10d::operator*= (const std::double_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number; j *= number;
		return *this;
	}

	inline Vector10d& Vector10d::operator/= (const std::double_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number; j /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector10d::operator< (const Vector10d& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i&& j < other.j;
	}

	inline bool Vector10d::operator<= (const Vector10d& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i && j <= other.j;
	}

	inline bool Vector10d::operator>  (const Vector10d& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i && j > other.j;
	}

	inline bool Vector10d::operator>= (const Vector10d& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i && j >= other.j;
	}


	inline bool Vector10d::operator<  (const std::double_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number && j < number;
	}

	inline bool Vector10d::operator<= (const std::double_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number && j <= number;
	}

	inline bool Vector10d::operator>  (const std::double_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number && j > number;
	}

	inline bool Vector10d::operator>= (const std::double_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number && j >= number;
	}


	// equal / not equal
	inline bool Vector10d::operator==(const Vector10d& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i && j == other.j;
	}

	inline bool Vector10d::operator!=(const Vector10d& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i || j != other.j;
	}

	inline bool Vector10d::operator==(const std::double_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number && j == number;
	}

	inline bool Vector10d::operator!=(const std::double_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number || j != number;
	}


	inline constexpr std::uint8_t Vector10d::size() const noexcept { return 10; }
	inline void Vector10d::reset(const std::double_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::double_t& Vector10d::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::double_t& Vector10d::at(const std::uint8_t& index) noexcept
	{
		std::double_t* ptr = &a;
		if (index > 9)
			return ptr[0];
		return ptr[index];
	}
	// End
}