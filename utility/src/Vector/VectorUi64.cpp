#include "VectorUi64.h"

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::uint64_t
		Bytes: 8
		Range: 0 to 18.446.744.073.709.551.615
	*/

	// Vector2ui64
	inline Vector2ui64::Vector2ui64(const std::uint64_t& x, const std::uint64_t& y) noexcept
		: x(x), y(y) {}

	// copy/move constructor and assignment
	inline Vector2ui64::Vector2ui64(const Vector2ui64& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2ui64& Vector2ui64::operator=(const Vector2ui64& other) noexcept {
		x = other.x; y = other.y; return *this;
	}

	inline Vector2ui64::Vector2ui64(Vector2ui64&& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2ui64& Vector2ui64::operator=(Vector2ui64&& other) noexcept {
		x = other.x; y = other.y; return *this;
	}
	// .....................................
	inline Vector2ui64& Vector2ui64::operator=(const std::uint64_t& number) noexcept {
		x = number; y = number; return *this;
	}


	inline Vector2ui64 Vector2ui64::operator +(const Vector2ui64& v) const noexcept {
		return { x + v.x, y + v.y };
	}

	inline Vector2ui64 Vector2ui64::operator -(const Vector2ui64& v) const noexcept {
		return { x - v.x, y - v.y };
	}

	inline Vector2ui64 Vector2ui64::operator *(const Vector2ui64& v) const noexcept {
		return { x * v.x, y * v.y };
	}

	inline Vector2ui64 Vector2ui64::operator /(const Vector2ui64& v) const noexcept {
		return { x / v.x, y / v.y };
	}


	inline Vector2ui64 Vector2ui64::operator +(const std::uint64_t& number) const noexcept {
		return { x + number, y + number };
	}

	inline Vector2ui64 Vector2ui64::operator -(const std::uint64_t& number) const noexcept {
		return { x - number, y - number };
	}

	inline Vector2ui64 Vector2ui64::operator *(const std::uint64_t& number) const noexcept {
		return { x * number, y * number };
	}

	inline Vector2ui64 Vector2ui64::operator /(const std::uint64_t& number) const noexcept {
		return { x / number, y / number };
	}


	// increment / decrement
	inline Vector2ui64& Vector2ui64::operator++ () noexcept {
		++x; ++y;
		return *this;
	}

	inline Vector2ui64& Vector2ui64::operator-- ()  noexcept {
		--x; --y;
		return *this;
	}

	inline Vector2ui64 Vector2ui64::operator++ (int) noexcept {
		Vector2ui64 temp = *this;
		++* this;
		return temp;
	}

	inline Vector2ui64 Vector2ui64::operator-- (int) noexcept {
		Vector2ui64 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector2ui64& Vector2ui64::operator+= (const Vector2ui64& right) noexcept {
		x += right.x; y += right.y;
		return *this;
	}

	inline Vector2ui64& Vector2ui64::operator-= (const Vector2ui64& right) noexcept {
		x -= right.x; y -= right.y;
		return *this;
	}

	inline Vector2ui64& Vector2ui64::operator*= (const Vector2ui64& right) noexcept {
		x *= right.x; y *= right.y;
		return *this;
	}

	inline Vector2ui64& Vector2ui64::operator/= (const Vector2ui64& right) noexcept {
		x /= right.x; y /= right.y;
		return *this;
	}


	inline Vector2ui64& Vector2ui64::operator+= (const std::uint64_t& number) noexcept {
		x += number; y += number;
		return *this;
	}

	inline Vector2ui64& Vector2ui64::operator-= (const std::uint64_t& number) noexcept {
		x -= number; y -= number;
		return *this;
	}

	inline Vector2ui64& Vector2ui64::operator*= (const std::uint64_t& number) noexcept {
		x *= number; y *= number;
		return *this;
	}

	inline Vector2ui64& Vector2ui64::operator/= (const std::uint64_t& number) noexcept {
		x /= number; y /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector2ui64::operator< (const Vector2ui64& other) const noexcept {
		return x < other.x && y < other.y;
	}

	inline bool Vector2ui64::operator<= (const Vector2ui64& other) const noexcept {
		return x <= other.x && y <= other.y;
	}

	inline bool Vector2ui64::operator>  (const Vector2ui64& other) const noexcept {
		return x > other.x && y > other.y;
	}

	inline bool Vector2ui64::operator>= (const Vector2ui64& other) const noexcept {
		return x >= other.x && y >= other.y;
	}


	inline bool Vector2ui64::operator<  (const std::uint64_t& number) const noexcept {
		return x < number && y < number;
	}

	inline bool Vector2ui64::operator<= (const std::uint64_t& number) const noexcept {
		return x <= number && y <= number;
	}

	inline bool Vector2ui64::operator>  (const std::uint64_t& number) const noexcept {
		return x > number && y > number;
	}

	inline bool Vector2ui64::operator>= (const std::uint64_t& number) const noexcept {
		return x >= number && y >= number;
	}


	// equal / not equal
	inline bool Vector2ui64::operator==(const Vector2ui64& other) const noexcept {
		return x == other.x && y == other.y;
	}

	inline bool Vector2ui64::operator!=(const Vector2ui64& other) const noexcept {
		return x != other.x || y != other.y;
	}

	inline bool Vector2ui64::operator==(const std::uint64_t& number) const noexcept {
		return x == number && y == number;
	}

	inline bool Vector2ui64::operator!=(const std::uint64_t& number) const noexcept {
		return x != number || y != number;
	}


	inline constexpr std::uint8_t Vector2ui64::size() const noexcept { return 2; }
	inline void Vector2ui64::reset(const std::uint64_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint64_t& Vector2ui64::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint64_t& Vector2ui64::at(const std::uint8_t& index) noexcept
	{
		std::uint64_t* ptr = &x;
		if (index > 1)
			return ptr[0];
		return ptr[index];
	}



	// Vector3ui64
	inline Vector3ui64::Vector3ui64(const std::uint64_t& x, const std::uint64_t& y, const std::uint64_t& z) noexcept
		: x(x), y(y), z(z) {}

	// copy/move constructor and assignment
	inline Vector3ui64::Vector3ui64(const Vector3ui64& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3ui64& Vector3ui64::operator=(const Vector3ui64& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}

	inline Vector3ui64::Vector3ui64(Vector3ui64&& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3ui64& Vector3ui64::operator=(Vector3ui64&& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}
	// .....................................
	inline Vector3ui64& Vector3ui64::operator=(const std::uint64_t& number) noexcept {
		x = number; y = number; z = number; return *this;
	}


	inline Vector3ui64 Vector3ui64::operator +(const Vector3ui64& v) const noexcept {
		return { x + v.x, y + v.y, z + v.z };
	}

	inline Vector3ui64 Vector3ui64::operator -(const Vector3ui64& v) const noexcept {
		return { x - v.x, y - v.y, z - v.z };
	}

	inline Vector3ui64 Vector3ui64::operator *(const Vector3ui64& v) const noexcept {
		return { x * v.x, y * v.y, z * v.z };
	}

	inline Vector3ui64 Vector3ui64::operator /(const Vector3ui64& v) const noexcept {
		return { x / v.x, y / v.y, z / v.z };
	}

 
	inline Vector3ui64 Vector3ui64::operator +(const std::uint64_t& number) const noexcept {
		return { x + number, y + number, z + number };
	}

	inline Vector3ui64 Vector3ui64::operator -(const std::uint64_t& number) const noexcept {
		return { x - number, y - number, z - number };
	}

	inline Vector3ui64 Vector3ui64::operator *(const std::uint64_t& number) const noexcept {
		return { x * number, y * number, z * number };
	}

	inline Vector3ui64 Vector3ui64::operator /(const std::uint64_t& number) const noexcept {
		return { x / number, y / number, z / number };
	}


	// increment / decrement
	inline Vector3ui64& Vector3ui64::operator++ () noexcept {
		++x; ++y; ++z;
		return *this;
	}

	inline Vector3ui64& Vector3ui64::operator-- () noexcept {
		--x; --y; --z;
		return *this;
	}

	inline Vector3ui64 Vector3ui64::operator++ (int) noexcept {
		Vector3ui64 temp = *this;
		++* this;
		return temp;
	}

	inline Vector3ui64 Vector3ui64::operator-- (int) noexcept {
		Vector3ui64 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector3ui64& Vector3ui64::operator+= (const Vector3ui64& right) noexcept {
		x += right.x; y += right.y; z += right.z;
		return *this;
	}

	inline Vector3ui64& Vector3ui64::operator-= (const Vector3ui64& right) noexcept {
		x -= right.x; y -= right.y; z -= right.z;
		return *this;
	}

	inline Vector3ui64& Vector3ui64::operator*= (const Vector3ui64& right) noexcept {
		x *= right.x; y *= right.y; z *= right.z;
		return *this;
	}

	inline Vector3ui64& Vector3ui64::operator/= (const Vector3ui64& right) noexcept {
		x /= right.x; y /= right.y; z /= right.z;
		return *this;
	}


	inline Vector3ui64& Vector3ui64::operator+= (const std::uint64_t& number) noexcept {
		x += number; y += number; z += number;
		return *this;
	}

	inline Vector3ui64& Vector3ui64::operator-= (const std::uint64_t& number) noexcept {
		x -= number; y -= number; z -= number;
		return *this;
	}

	inline Vector3ui64& Vector3ui64::operator*= (const std::uint64_t& number) noexcept {
		x *= number; y *= number; z *= number;
		return *this;
	}

	inline Vector3ui64& Vector3ui64::operator/= (const std::uint64_t& number) noexcept {
		x /= number; y /= number; z /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector3ui64::operator< (const Vector3ui64& other) const noexcept {
		return x < other.x && y < other.y&& z < other.z;
	}

	inline bool Vector3ui64::operator<= (const Vector3ui64& other) const noexcept {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	inline bool Vector3ui64::operator>  (const Vector3ui64& other) const noexcept {
		return x > other.x && y > other.y && z > other.z;
	}

	inline bool Vector3ui64::operator>= (const Vector3ui64& other) const noexcept {
		return x >= other.x && y >= other.y && z >= other.z;
	}


	inline bool Vector3ui64::operator<  (const std::uint64_t& number) const noexcept {
		return x < number && y < number && z < number;
	}

	inline bool Vector3ui64::operator<= (const std::uint64_t& number) const noexcept {
		return x <= number && y <= number && z <= number;
	}

	inline bool Vector3ui64::operator>  (const std::uint64_t& number) const noexcept {
		return x > number && y > number && z > number;
	}

	inline bool Vector3ui64::operator>= (const std::uint64_t& number) const noexcept {
		return x >= number && y >= number && z >= number;
	}


	// equal / not equal
	inline bool Vector3ui64::operator==(const Vector3ui64& other) const noexcept {
		return x == other.x && y == other.y && z == other.z;
	}

	inline bool Vector3ui64::operator!=(const Vector3ui64& other) const noexcept {
		return x != other.x || y != other.y || z != other.z;
	}

	inline bool Vector3ui64::operator==(const std::uint64_t& number) const noexcept {
		return x == number && y == number && z == number;
	}

	inline bool Vector3ui64::operator!=(const std::uint64_t& number) const noexcept {
		return x != number || y != number || z != number;
	}


	inline constexpr std::uint8_t Vector3ui64::size() const noexcept { return 3; }
	inline void Vector3ui64::reset(const std::uint64_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint64_t& Vector3ui64::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint64_t& Vector3ui64::at(const std::uint8_t& index) noexcept
	{
		std::uint64_t* ptr = &x;
		if (index > 2)
			return ptr[0];
		return ptr[index];
	}



	// Vector4ui64
	inline Vector4ui64::Vector4ui64(const std::uint64_t& a, const std::uint64_t& b, const std::uint64_t& c, const std::uint64_t& d) noexcept
		: a(a), b(b), c(c), d(d) {}

	// copy/move constructor and assignment
	inline Vector4ui64::Vector4ui64(const Vector4ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4ui64& Vector4ui64::operator=(const Vector4ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}

	inline Vector4ui64::Vector4ui64(Vector4ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4ui64& Vector4ui64::operator=(Vector4ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}
	// .....................................
	inline Vector4ui64& Vector4ui64::operator=(const std::uint64_t& number) noexcept {
		a = number; b = number; c = number; d = number; return *this;
	}


	inline Vector4ui64 Vector4ui64::operator +(const Vector4ui64& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d };
	}

	inline Vector4ui64 Vector4ui64::operator -(const Vector4ui64& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d };
	}

	inline Vector4ui64 Vector4ui64::operator *(const Vector4ui64& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d };
	}

	inline Vector4ui64 Vector4ui64::operator /(const Vector4ui64& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d };
	}


	inline Vector4ui64 Vector4ui64::operator +(const std::uint64_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number };
	}

	inline Vector4ui64 Vector4ui64::operator -(const std::uint64_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number };
	}

	inline Vector4ui64 Vector4ui64::operator *(const std::uint64_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number };
	}

	inline Vector4ui64 Vector4ui64::operator /(const std::uint64_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number };
	}


	// increment / decrement
	inline Vector4ui64& Vector4ui64::operator++ () noexcept {
		++a; ++b; ++c; ++d;
		return *this;
	}

	inline Vector4ui64& Vector4ui64::operator-- () noexcept {
		--a; --b; --c; --d;
		return *this;
	}

	inline Vector4ui64 Vector4ui64::operator++ (int) noexcept {
		Vector4ui64 temp = *this;
		++* this;
		return temp;
	}

	inline Vector4ui64 Vector4ui64::operator-- (int) noexcept {
		Vector4ui64 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector4ui64& Vector4ui64::operator+= (const Vector4ui64& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d;
		return *this;
	}

	inline Vector4ui64& Vector4ui64::operator-= (const Vector4ui64& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d;
		return *this;
	}

	inline Vector4ui64& Vector4ui64::operator*= (const Vector4ui64& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d;
		return *this;
	}

	inline Vector4ui64& Vector4ui64::operator/= (const Vector4ui64& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d;
		return *this;
	}


	inline Vector4ui64& Vector4ui64::operator+= (const std::uint64_t& number) noexcept {
		a += number; b += number; c += number; d += number;
		return *this;
	}

	inline Vector4ui64& Vector4ui64::operator-= (const std::uint64_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number;
		return *this;
	}

	inline Vector4ui64& Vector4ui64::operator*= (const std::uint64_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number;
		return *this;
	}

	inline Vector4ui64& Vector4ui64::operator/= (const std::uint64_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector4ui64::operator< (const Vector4ui64& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d;
	}

	inline bool Vector4ui64::operator<= (const Vector4ui64& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d;
	}

	inline bool Vector4ui64::operator>  (const Vector4ui64& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d;
	}

	inline bool Vector4ui64::operator>= (const Vector4ui64& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d;
	}


	inline bool Vector4ui64::operator<  (const std::uint64_t& number) const noexcept {
		return a < number && b < number && c < number && d < number;
	}

	inline bool Vector4ui64::operator<= (const std::uint64_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number;
	}

	inline bool Vector4ui64::operator>  (const std::uint64_t& number) const noexcept {
		return a > number && b > number && c > number && d > number;
	}

	inline bool Vector4ui64::operator>= (const std::uint64_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number;
	}


	// equal / not equal
	inline bool Vector4ui64::operator==(const Vector4ui64& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d;
	}

	inline bool Vector4ui64::operator!=(const Vector4ui64& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d;
	}

	inline bool Vector4ui64::operator==(const std::uint64_t& number) const noexcept {
		return a == number && b == number && c == number && d == number;
	}

	inline bool Vector4ui64::operator!=(const std::uint64_t& number) const noexcept {
		return a != number || b != number || c != number || d != number;
	}


	inline constexpr std::uint8_t Vector4ui64::size() const noexcept { return 4; }
	inline void Vector4ui64::reset(const std::uint64_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint64_t& Vector4ui64::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint64_t& Vector4ui64::at(const std::uint8_t& index) noexcept
	{
		std::uint64_t* ptr = &a;
		if (index > 3)
			return ptr[0];
		return ptr[index];
	}



	// Vector5ui64
	inline Vector5ui64::Vector5ui64(const std::uint64_t& a, const std::uint64_t& b, const std::uint64_t& c, const std::uint64_t& d,
		const std::uint64_t& e) noexcept
		: a(a), b(b), c(c), d(d), e(e) {}

	// copy/move constructor and assignment
	inline Vector5ui64::Vector5ui64(const Vector5ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5ui64& Vector5ui64::operator=(const Vector5ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}

	inline Vector5ui64::Vector5ui64(Vector5ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5ui64& Vector5ui64::operator=(Vector5ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}
	// .....................................
	inline Vector5ui64& Vector5ui64::operator=(const std::uint64_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; return *this;
	}


	inline Vector5ui64 Vector5ui64::operator +(const Vector5ui64& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e };
	}

	inline Vector5ui64 Vector5ui64::operator -(const Vector5ui64& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e };
	}

	inline Vector5ui64 Vector5ui64::operator *(const Vector5ui64& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e };
	}

	inline Vector5ui64 Vector5ui64::operator /(const Vector5ui64& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e };
	}


	inline Vector5ui64 Vector5ui64::operator +(const std::uint64_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number };
	}

	inline Vector5ui64 Vector5ui64::operator -(const std::uint64_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number };
	}

	inline Vector5ui64 Vector5ui64::operator *(const std::uint64_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number };
	}

	inline Vector5ui64 Vector5ui64::operator /(const std::uint64_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number };
	}


	// increment / decrement
	inline Vector5ui64& Vector5ui64::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e;
		return *this;
	}

	inline Vector5ui64& Vector5ui64::operator-- () noexcept {
		--a; --b; --c; --d; --e;
		return *this;
	}

	inline Vector5ui64 Vector5ui64::operator++ (int) noexcept {
		Vector5ui64 temp = *this;
		++* this;
		return temp;
	}

	inline Vector5ui64 Vector5ui64::operator-- (int) noexcept {
		Vector5ui64 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector5ui64& Vector5ui64::operator+= (const Vector5ui64& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e;
		return *this;
	}

	inline Vector5ui64& Vector5ui64::operator-= (const Vector5ui64& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e;
		return *this;
	}

	inline Vector5ui64& Vector5ui64::operator*= (const Vector5ui64& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e;
		return *this;
	}

	inline Vector5ui64& Vector5ui64::operator/= (const Vector5ui64& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e;
		return *this;
	}


	inline Vector5ui64& Vector5ui64::operator+= (const std::uint64_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number;
		return *this;
	}

	inline Vector5ui64& Vector5ui64::operator-= (const std::uint64_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number;
		return *this;
	}

	inline Vector5ui64& Vector5ui64::operator*= (const std::uint64_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number;
		return *this;
	}

	inline Vector5ui64& Vector5ui64::operator/= (const std::uint64_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector5ui64::operator< (const Vector5ui64& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e;
	}

	inline bool Vector5ui64::operator<= (const Vector5ui64& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e;
	}

	inline bool Vector5ui64::operator>  (const Vector5ui64& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e;
	}

	inline bool Vector5ui64::operator>= (const Vector5ui64& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e;
	}


	inline bool Vector5ui64::operator<  (const std::uint64_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number;
	}

	inline bool Vector5ui64::operator<= (const std::uint64_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number;
	}

	inline bool Vector5ui64::operator>  (const std::uint64_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number;
	}

	inline bool Vector5ui64::operator>= (const std::uint64_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number;
	}


	// equal / not equal
	inline bool Vector5ui64::operator==(const Vector5ui64& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
	}

	inline bool Vector5ui64::operator!=(const Vector5ui64& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e;
	}

	inline bool Vector5ui64::operator==(const std::uint64_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number;
	}

	inline bool Vector5ui64::operator!=(const std::uint64_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number;
	}


	inline constexpr std::uint8_t Vector5ui64::size() const noexcept { return 5; }
	inline void Vector5ui64::reset(const std::uint64_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint64_t& Vector5ui64::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint64_t& Vector5ui64::at(const std::uint8_t& index) noexcept
	{
		std::uint64_t* ptr = &a;
		if (index > 4)
			return ptr[0];
		return ptr[index];
	}



	// Vector6ui64
	inline Vector6ui64::Vector6ui64(const std::uint64_t& a, const std::uint64_t& b, const std::uint64_t& c, const std::uint64_t& d,
		const std::uint64_t& e, const std::uint64_t& f) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f) {}

	// copy/move constructor and assignment
	inline Vector6ui64::Vector6ui64(const Vector6ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6ui64& Vector6ui64::operator=(const Vector6ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}

	inline Vector6ui64::Vector6ui64(Vector6ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6ui64& Vector6ui64::operator=(Vector6ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}
	// .....................................
	inline Vector6ui64& Vector6ui64::operator=(const std::uint64_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; return *this;
	}


	inline Vector6ui64 Vector6ui64::operator +(const Vector6ui64& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f };
	}

	inline Vector6ui64 Vector6ui64::operator -(const Vector6ui64& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f };
	}

	inline Vector6ui64 Vector6ui64::operator *(const Vector6ui64& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f };
	}

	inline Vector6ui64 Vector6ui64::operator /(const Vector6ui64& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f };
	}


	inline Vector6ui64 Vector6ui64::operator +(const std::uint64_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number };
	}

	inline Vector6ui64 Vector6ui64::operator -(const std::uint64_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number };
	}

	inline Vector6ui64 Vector6ui64::operator *(const std::uint64_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number };
	}

	inline Vector6ui64 Vector6ui64::operator /(const std::uint64_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number };
	}


	// increment / decrement
	inline Vector6ui64& Vector6ui64::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f;
		return *this;
	}

	inline Vector6ui64& Vector6ui64::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f;
		return *this;
	}

	inline Vector6ui64 Vector6ui64::operator++ (int) noexcept {
		Vector6ui64 temp = *this;
		++* this;
		return temp;
	}

	inline Vector6ui64 Vector6ui64::operator-- (int) noexcept {
		Vector6ui64 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector6ui64& Vector6ui64::operator+= (const Vector6ui64& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f;
		return *this;
	}

	inline Vector6ui64& Vector6ui64::operator-= (const Vector6ui64& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f;
		return *this;
	}

	inline Vector6ui64& Vector6ui64::operator*= (const Vector6ui64& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f;
		return *this;
	}

	inline Vector6ui64& Vector6ui64::operator/= (const Vector6ui64& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f;
		return *this;
	}


	inline Vector6ui64& Vector6ui64::operator+= (const std::uint64_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number;
		return *this;
	}

	inline Vector6ui64& Vector6ui64::operator-= (const std::uint64_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number;
		return *this;
	}

	inline Vector6ui64& Vector6ui64::operator*= (const std::uint64_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number;
		return *this;
	}

	inline Vector6ui64& Vector6ui64::operator/= (const std::uint64_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector6ui64::operator< (const Vector6ui64& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f;
	}

	inline bool Vector6ui64::operator<= (const Vector6ui64& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f;
	}

	inline bool Vector6ui64::operator>  (const Vector6ui64& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f;
	}

	inline bool Vector6ui64::operator>= (const Vector6ui64& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f;
	}


	inline bool Vector6ui64::operator<  (const std::uint64_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number;
	}

	inline bool Vector6ui64::operator<= (const std::uint64_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number;
	}

	inline bool Vector6ui64::operator>  (const std::uint64_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number;
	}

	inline bool Vector6ui64::operator>= (const std::uint64_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number;
	}


	// equal / not equal
	inline bool Vector6ui64::operator==(const Vector6ui64& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f;
	}

	inline bool Vector6ui64::operator!=(const Vector6ui64& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f;
	}

	inline bool Vector6ui64::operator==(const std::uint64_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number;
	}

	inline bool Vector6ui64::operator!=(const std::uint64_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number;
	}


	inline constexpr std::uint8_t Vector6ui64::size() const noexcept { return 6; }
	inline void Vector6ui64::reset(const std::uint64_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint64_t& Vector6ui64::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint64_t& Vector6ui64::at(const std::uint8_t& index) noexcept
	{
		std::uint64_t* ptr = &a;
		if (index > 5)
			return ptr[0];
		return ptr[index];
	}



	// Vector7ui64
	inline Vector7ui64::Vector7ui64(const std::uint64_t& a, const std::uint64_t& b, const std::uint64_t& c, const std::uint64_t& d,
		const std::uint64_t& e, const std::uint64_t& f, const std::uint64_t& g) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g) {}

	// copy/move constructor and assignment
	inline Vector7ui64::Vector7ui64(const Vector7ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7ui64& Vector7ui64::operator=(const Vector7ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}

	inline Vector7ui64::Vector7ui64(Vector7ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7ui64& Vector7ui64::operator=(Vector7ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}
	// .....................................
	inline Vector7ui64& Vector7ui64::operator=(const std::uint64_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; return *this;
	}


	inline Vector7ui64 Vector7ui64::operator +(const Vector7ui64& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g };
	}

	inline Vector7ui64 Vector7ui64::operator -(const Vector7ui64& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g };
	}

	inline Vector7ui64 Vector7ui64::operator *(const Vector7ui64& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g };
	}

	inline Vector7ui64 Vector7ui64::operator /(const Vector7ui64& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g };
	}


	inline Vector7ui64 Vector7ui64::operator +(const std::uint64_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number };
	}

	inline Vector7ui64 Vector7ui64::operator -(const std::uint64_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number };
	}

	inline Vector7ui64 Vector7ui64::operator *(const std::uint64_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number };
	}

	inline Vector7ui64 Vector7ui64::operator /(const std::uint64_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number };
	}


	// increment / decrement
	inline Vector7ui64& Vector7ui64::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g;
		return *this;
	}

	inline Vector7ui64& Vector7ui64::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g;
		return *this;
	}

	inline Vector7ui64 Vector7ui64::operator++ (int) noexcept {
		Vector7ui64 temp = *this;
		++* this;
		return temp;
	}

	inline Vector7ui64 Vector7ui64::operator-- (int) noexcept {
		Vector7ui64 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector7ui64& Vector7ui64::operator+= (const Vector7ui64& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g;
		return *this;
	}

	inline Vector7ui64& Vector7ui64::operator-= (const Vector7ui64& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g;
		return *this;
	}

	inline Vector7ui64& Vector7ui64::operator*= (const Vector7ui64& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g;
		return *this;
	}

	inline Vector7ui64& Vector7ui64::operator/= (const Vector7ui64& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g;
		return *this;
	}


	inline Vector7ui64& Vector7ui64::operator+= (const std::uint64_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number;
		return *this;
	}

	inline Vector7ui64& Vector7ui64::operator-= (const std::uint64_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number;
		return *this;
	}

	inline Vector7ui64& Vector7ui64::operator*= (const std::uint64_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number;
		return *this;
	}

	inline Vector7ui64& Vector7ui64::operator/= (const std::uint64_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector7ui64::operator< (const Vector7ui64& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g;
	}

	inline bool Vector7ui64::operator<= (const Vector7ui64& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g;
	}

	inline bool Vector7ui64::operator>  (const Vector7ui64& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g;
	}

	inline bool Vector7ui64::operator>= (const Vector7ui64& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g;
	}


	inline bool Vector7ui64::operator<  (const std::uint64_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number;
	}

	inline bool Vector7ui64::operator<= (const std::uint64_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number;
	}

	inline bool Vector7ui64::operator>  (const std::uint64_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number;
	}

	inline bool Vector7ui64::operator>= (const std::uint64_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number;
	}


	// equal / not equal
	inline bool Vector7ui64::operator==(const Vector7ui64& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g;
	}

	inline bool Vector7ui64::operator!=(const Vector7ui64& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g;
	}

	inline bool Vector7ui64::operator==(const std::uint64_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number;
	}

	inline bool Vector7ui64::operator!=(const std::uint64_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number;
	}


	inline constexpr std::uint8_t Vector7ui64::size() const noexcept { return 7; }
	inline void Vector7ui64::reset(const std::uint64_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint64_t& Vector7ui64::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint64_t& Vector7ui64::at(const std::uint8_t& index) noexcept
	{
		std::uint64_t* ptr = &a;
		if (index > 6)
			return ptr[0];
		return ptr[index];
	}



	// Vector8ui64
	inline Vector8ui64::Vector8ui64(const std::uint64_t& a, const std::uint64_t& b, const std::uint64_t& c, const std::uint64_t& d,
		const std::uint64_t& e, const std::uint64_t& f, const std::uint64_t& g, const std::uint64_t& h) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h) {}

	// copy/move constructor and assignment
	inline Vector8ui64::Vector8ui64(const Vector8ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8ui64& Vector8ui64::operator=(const Vector8ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}

	inline Vector8ui64::Vector8ui64(Vector8ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8ui64& Vector8ui64::operator=(Vector8ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}
	// .....................................
	inline Vector8ui64& Vector8ui64::operator=(const std::uint64_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; return *this;
	}


	inline Vector8ui64 Vector8ui64::operator +(const Vector8ui64& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h };
	}

	inline Vector8ui64 Vector8ui64::operator -(const Vector8ui64& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h };
	}

	inline Vector8ui64 Vector8ui64::operator *(const Vector8ui64& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h };
	}

	inline Vector8ui64 Vector8ui64::operator /(const Vector8ui64& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h };
	}


	inline Vector8ui64 Vector8ui64::operator +(const std::uint64_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number };
	}

	inline Vector8ui64 Vector8ui64::operator -(const std::uint64_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number };
	}

	inline Vector8ui64 Vector8ui64::operator *(const std::uint64_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number };
	}

	inline Vector8ui64 Vector8ui64::operator /(const std::uint64_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number };
	}


	// increment / decrement
	inline Vector8ui64& Vector8ui64::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h;
		return *this;
	}

	inline Vector8ui64& Vector8ui64::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h;
		return *this;
	}

	inline Vector8ui64 Vector8ui64::operator++ (int) noexcept {
		Vector8ui64 temp = *this;
		++* this;
		return temp;
	}

	inline Vector8ui64 Vector8ui64::operator-- (int) noexcept {
		Vector8ui64 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector8ui64& Vector8ui64::operator+= (const Vector8ui64& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h;
		return *this;
	}

	inline Vector8ui64& Vector8ui64::operator-= (const Vector8ui64& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h;
		return *this;
	}

	inline Vector8ui64& Vector8ui64::operator*= (const Vector8ui64& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h;
		return *this;
	}

	inline Vector8ui64& Vector8ui64::operator/= (const Vector8ui64& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h;
		return *this;
	}


	inline Vector8ui64& Vector8ui64::operator+= (const std::uint64_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number;
		return *this;
	}

	inline Vector8ui64& Vector8ui64::operator-= (const std::uint64_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number;
		return *this;
	}

	inline Vector8ui64& Vector8ui64::operator*= (const std::uint64_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number;
		return *this;
	}

	inline Vector8ui64& Vector8ui64::operator/= (const std::uint64_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector8ui64::operator< (const Vector8ui64& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h;
	}

	inline bool Vector8ui64::operator<= (const Vector8ui64& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h;
	}

	inline bool Vector8ui64::operator>  (const Vector8ui64& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h;
	}

	inline bool Vector8ui64::operator>= (const Vector8ui64& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h;
	}


	inline bool Vector8ui64::operator<  (const std::uint64_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number;
	}

	inline bool Vector8ui64::operator<= (const std::uint64_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number;
	}

	inline bool Vector8ui64::operator>  (const std::uint64_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number;
	}

	inline bool Vector8ui64::operator>= (const std::uint64_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number;
	}


	// equal / not equal
	inline bool Vector8ui64::operator==(const Vector8ui64& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h;
	}

	inline bool Vector8ui64::operator!=(const Vector8ui64& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h;
	}

	inline bool Vector8ui64::operator==(const std::uint64_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number;
	}

	inline bool Vector8ui64::operator!=(const std::uint64_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number;
	}


	inline constexpr std::uint8_t Vector8ui64::size() const noexcept { return 8; }
	inline void Vector8ui64::reset(const std::uint64_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint64_t& Vector8ui64::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint64_t& Vector8ui64::at(const std::uint8_t& index) noexcept
	{
		std::uint64_t* ptr = &a;
		if (index > 7)
			return ptr[0];
		return ptr[index];
	}



	// Vector9ui64
	inline Vector9ui64::Vector9ui64(const std::uint64_t& a, const std::uint64_t& b, const std::uint64_t& c, const std::uint64_t& d,
		const std::uint64_t& e, const std::uint64_t& f, const std::uint64_t& g, const std::uint64_t& h,
		const std::uint64_t& i) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

	// copy/move constructor and assignment
	inline Vector9ui64::Vector9ui64(const Vector9ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9ui64& Vector9ui64::operator=(const Vector9ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}

	inline Vector9ui64::Vector9ui64(Vector9ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9ui64& Vector9ui64::operator=(Vector9ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}
	// .....................................
	inline Vector9ui64& Vector9ui64::operator=(const std::uint64_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; return *this;
	}


	inline Vector9ui64 Vector9ui64::operator +(const Vector9ui64& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i };
	}

	inline Vector9ui64 Vector9ui64::operator -(const Vector9ui64& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i };
	}

	inline Vector9ui64 Vector9ui64::operator *(const Vector9ui64& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i };
	}

	inline Vector9ui64 Vector9ui64::operator /(const Vector9ui64& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i };
	}


	inline Vector9ui64 Vector9ui64::operator +(const std::uint64_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number };
	}

	inline Vector9ui64 Vector9ui64::operator -(const std::uint64_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number };
	}

	inline Vector9ui64 Vector9ui64::operator *(const std::uint64_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number };
	}

	inline Vector9ui64 Vector9ui64::operator /(const std::uint64_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number };
	}


	// increment / decrement
	inline Vector9ui64& Vector9ui64::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i;
		return *this;
	}

	inline Vector9ui64& Vector9ui64::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i;
		return *this;
	}

	inline Vector9ui64 Vector9ui64::operator++ (int) noexcept {
		Vector9ui64 temp = *this;
		++* this;
		return temp;
	}

	inline Vector9ui64 Vector9ui64::operator-- (int) noexcept {
		Vector9ui64 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector9ui64& Vector9ui64::operator+= (const Vector9ui64& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i;
		return *this;
	}

	inline Vector9ui64& Vector9ui64::operator-= (const Vector9ui64& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i;
		return *this;
	}

	inline Vector9ui64& Vector9ui64::operator*= (const Vector9ui64& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i;
		return *this;
	}

	inline Vector9ui64& Vector9ui64::operator/= (const Vector9ui64& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i;
		return *this;
	}


	inline Vector9ui64& Vector9ui64::operator+= (const std::uint64_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number;
		return *this;
	}

	inline Vector9ui64& Vector9ui64::operator-= (const std::uint64_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number;
		return *this;
	}

	inline Vector9ui64& Vector9ui64::operator*= (const std::uint64_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number;
		return *this;
	}

	inline Vector9ui64& Vector9ui64::operator/= (const std::uint64_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector9ui64::operator< (const Vector9ui64& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i;
	}

	inline bool Vector9ui64::operator<= (const Vector9ui64& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i;
	}

	inline bool Vector9ui64::operator>  (const Vector9ui64& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i;
	}

	inline bool Vector9ui64::operator>= (const Vector9ui64& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i;
	}


	inline bool Vector9ui64::operator<  (const std::uint64_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number;
	}

	inline bool Vector9ui64::operator<= (const std::uint64_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number;
	}

	inline bool Vector9ui64::operator>  (const std::uint64_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number;
	}

	inline bool Vector9ui64::operator>= (const std::uint64_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number;
	}


	// equal / not equal
	inline bool Vector9ui64::operator==(const Vector9ui64& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i;
	}

	inline bool Vector9ui64::operator!=(const Vector9ui64& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i;
	}

	inline bool Vector9ui64::operator==(const std::uint64_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number;
	}

	inline bool Vector9ui64::operator!=(const std::uint64_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number;
	}


	inline constexpr std::uint8_t Vector9ui64::size() const noexcept { return 9; }
	inline void Vector9ui64::reset(const std::uint64_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint64_t& Vector9ui64::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint64_t& Vector9ui64::at(const std::uint8_t& index) noexcept
	{
		std::uint64_t* ptr = &a;
		if (index > 8)
			return ptr[0];
		return ptr[index];
	}



	// Vector10ui64
	inline Vector10ui64::Vector10ui64(const std::uint64_t& a, const std::uint64_t& b, const std::uint64_t& c, const std::uint64_t& d,
		const std::uint64_t& e, const std::uint64_t& f, const std::uint64_t& g, const std::uint64_t& h,
		const std::uint64_t& i, const std::uint64_t& j) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {}

	// copy/move constructor and assignment
	inline Vector10ui64::Vector10ui64(const Vector10ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10ui64& Vector10ui64::operator=(const Vector10ui64& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}

	inline Vector10ui64::Vector10ui64(Vector10ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10ui64& Vector10ui64::operator=(Vector10ui64&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}
	// .....................................
	inline Vector10ui64& Vector10ui64::operator=(const std::uint64_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; j = number; return *this;
	}


	inline Vector10ui64 Vector10ui64::operator +(const Vector10ui64& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i, j + v.j };
	}

	inline Vector10ui64 Vector10ui64::operator -(const Vector10ui64& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i, j - v.j };
	}

	inline Vector10ui64 Vector10ui64::operator *(const Vector10ui64& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i, j * v.j };
	}

	inline Vector10ui64 Vector10ui64::operator /(const Vector10ui64& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i, j / v.j };
	}


	inline Vector10ui64 Vector10ui64::operator +(const std::uint64_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number, j + number };
	}

	inline Vector10ui64 Vector10ui64::operator -(const std::uint64_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number, j - number };
	}

	inline Vector10ui64 Vector10ui64::operator *(const std::uint64_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number, j * number };
	}

	inline Vector10ui64 Vector10ui64::operator /(const std::uint64_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number, j / number };
	}


	// increment / decrement
	inline Vector10ui64& Vector10ui64::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i; ++j;
		return *this;
	}

	inline Vector10ui64& Vector10ui64::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i; --j;
		return *this;
	}

	inline Vector10ui64 Vector10ui64::operator++ (int) noexcept {
		Vector10ui64 temp = *this;
		++* this;
		return temp;
	}

	inline Vector10ui64 Vector10ui64::operator-- (int) noexcept {
		Vector10ui64 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector10ui64& Vector10ui64::operator+= (const Vector10ui64& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i; j += right.j;
		return *this;
	}

	inline Vector10ui64& Vector10ui64::operator-= (const Vector10ui64& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i; j -= right.j;
		return *this;
	}

	inline Vector10ui64& Vector10ui64::operator*= (const Vector10ui64& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i; j *= right.j;
		return *this;
	}

	inline Vector10ui64& Vector10ui64::operator/= (const Vector10ui64& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i; j /= right.j;
		return *this;
	}


	inline Vector10ui64& Vector10ui64::operator+= (const std::uint64_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number; j += number;
		return *this;
	}

	inline Vector10ui64& Vector10ui64::operator-= (const std::uint64_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number; j -= number;
		return *this;
	}

	inline Vector10ui64& Vector10ui64::operator*= (const std::uint64_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number; j *= number;
		return *this;
	}

	inline Vector10ui64& Vector10ui64::operator/= (const std::uint64_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number; j /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector10ui64::operator< (const Vector10ui64& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i&& j < other.j;
	}

	inline bool Vector10ui64::operator<= (const Vector10ui64& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i && j <= other.j;
	}

	inline bool Vector10ui64::operator>  (const Vector10ui64& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i && j > other.j;
	}

	inline bool Vector10ui64::operator>= (const Vector10ui64& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i && j >= other.j;
	}


	inline bool Vector10ui64::operator<  (const std::uint64_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number && j < number;
	}

	inline bool Vector10ui64::operator<= (const std::uint64_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number && j <= number;
	}

	inline bool Vector10ui64::operator>  (const std::uint64_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number && j > number;
	}

	inline bool Vector10ui64::operator>= (const std::uint64_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number && j >= number;
	}


	// equal / not equal
	inline bool Vector10ui64::operator==(const Vector10ui64& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i && j == other.j;
	}

	inline bool Vector10ui64::operator!=(const Vector10ui64& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i || j != other.j;
	}

	inline bool Vector10ui64::operator==(const std::uint64_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number && j == number;
	}

	inline bool Vector10ui64::operator!=(const std::uint64_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number || j != number;
	}


	inline constexpr std::uint8_t Vector10ui64::size() const noexcept { return 10; }
	inline void Vector10ui64::reset(const std::uint64_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint64_t& Vector10ui64::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint64_t& Vector10ui64::at(const std::uint8_t& index) noexcept
	{
		std::uint64_t* ptr = &a;
		if (index > 9)
			return ptr[0];
		return ptr[index];
	}
	// End
}