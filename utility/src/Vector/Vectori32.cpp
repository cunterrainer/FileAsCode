#include "Vectori32.h"

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::int32_t
		Bytes: 4
		Range: -2.147.483.648 to 2.147.483.647
	*/

	// Vector2i32
	inline Vector2i32::Vector2i32(const std::int32_t& x, const std::int32_t& y) noexcept
		: x(x), y(y) {}

	// copy/move constructor and assignment
	inline Vector2i32::Vector2i32(const Vector2i32& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2i32& Vector2i32::operator=(const Vector2i32& other) noexcept {
		x = other.x; y = other.y; return *this;
	}

	inline Vector2i32::Vector2i32(Vector2i32&& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2i32& Vector2i32::operator=(Vector2i32&& other) noexcept {
		x = other.x; y = other.y; return *this;
	}
	// .....................................
	inline Vector2i32& Vector2i32::operator=(const std::int32_t& number) noexcept {
		x = number; y = number; return *this;
	}


	inline Vector2i32 Vector2i32::operator +(const Vector2i32& v) const noexcept {
		return { x + v.x, y + v.y };
	}

	inline Vector2i32 Vector2i32::operator -(const Vector2i32& v) const noexcept {
		return { x - v.x, y - v.y };
	}

	inline Vector2i32 Vector2i32::operator *(const Vector2i32& v) const noexcept {
		return { x * v.x, y * v.y };
	}

	inline Vector2i32 Vector2i32::operator /(const Vector2i32& v) const noexcept {
		return { x / v.x, y / v.y };
	}


	inline Vector2i32 Vector2i32::operator +(const std::int32_t& number) const noexcept {
		return { x + number, y + number };
	}

	inline Vector2i32 Vector2i32::operator -(const std::int32_t& number) const noexcept {
		return { x - number, y - number };
	}

	inline Vector2i32 Vector2i32::operator *(const std::int32_t& number) const noexcept {
		return { x * number, y * number };
	}

	inline Vector2i32 Vector2i32::operator /(const std::int32_t& number) const noexcept {
		return { x / number, y / number };
	}


	// increment / decrement
	inline Vector2i32& Vector2i32::operator++ () noexcept {
		++x; ++y;
		return *this;
	}

	inline Vector2i32& Vector2i32::operator-- ()  noexcept {
		--x; --y;
		return *this;
	}

	inline Vector2i32 Vector2i32::operator++ (int) noexcept {
		Vector2i32 temp = *this;
		++* this;
		return temp;
	}

	inline Vector2i32 Vector2i32::operator-- (int) noexcept {
		Vector2i32 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector2i32& Vector2i32::operator+= (const Vector2i32& right) noexcept {
		x += right.x; y += right.y;
		return *this;
	}

	inline Vector2i32& Vector2i32::operator-= (const Vector2i32& right) noexcept {
		x -= right.x; y -= right.y;
		return *this;
	}

	inline Vector2i32& Vector2i32::operator*= (const Vector2i32& right) noexcept {
		x *= right.x; y *= right.y;
		return *this;
	}

	inline Vector2i32& Vector2i32::operator/= (const Vector2i32& right) noexcept {
		x /= right.x; y /= right.y;
		return *this;
	}


	inline Vector2i32& Vector2i32::operator+= (const std::int32_t& number) noexcept {
		x += number; y += number;
		return *this;
	}

	inline Vector2i32& Vector2i32::operator-= (const std::int32_t& number) noexcept {
		x -= number; y -= number;
		return *this;
	}

	inline Vector2i32& Vector2i32::operator*= (const std::int32_t& number) noexcept {
		x *= number; y *= number;
		return *this;
	}

	inline Vector2i32& Vector2i32::operator/= (const std::int32_t& number) noexcept {
		x /= number; y /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector2i32::operator< (const Vector2i32& other) const noexcept {
		return x < other.x && y < other.y;
	}

	inline bool Vector2i32::operator<= (const Vector2i32& other) const noexcept {
		return x <= other.x && y <= other.y;
	}

	inline bool Vector2i32::operator>  (const Vector2i32& other) const noexcept {
		return x > other.x && y > other.y;
	}

	inline bool Vector2i32::operator>= (const Vector2i32& other) const noexcept {
		return x >= other.x && y >= other.y;
	}


	inline bool Vector2i32::operator<  (const std::int32_t& number) const noexcept {
		return x < number && y < number;
	}

	inline bool Vector2i32::operator<= (const std::int32_t& number) const noexcept {
		return x <= number && y <= number;
	}

	inline bool Vector2i32::operator>  (const std::int32_t& number) const noexcept {
		return x > number && y > number;
	}

	inline bool Vector2i32::operator>= (const std::int32_t& number) const noexcept {
		return x >= number && y >= number;
	}


	// equal / not equal
	inline bool Vector2i32::operator==(const Vector2i32& other) const noexcept {
		return x == other.x && y == other.y;
	}

	inline bool Vector2i32::operator!=(const Vector2i32& other) const noexcept {
		return x != other.x || y != other.y;
	}

	inline bool Vector2i32::operator==(const std::int32_t& number) const noexcept {
		return x == number && y == number;
	}

	inline bool Vector2i32::operator!=(const std::int32_t& number) const noexcept {
		return x != number || y != number;
	}


	inline constexpr std::uint8_t Vector2i32::size() const noexcept { return 2; }
	inline void Vector2i32::reset(const std::int32_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int32_t& Vector2i32::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int32_t& Vector2i32::at(const std::uint8_t& index) noexcept
	{
		std::int32_t* ptr = &x;
		if (index > 1)
			return ptr[0];
		return ptr[index];
	}



	// Vector3i32
	inline Vector3i32::Vector3i32(const std::int32_t& x, const std::int32_t& y, const std::int32_t& z) noexcept
		: x(x), y(y), z(z) {}

	// copy/move constructor and assignment
	inline Vector3i32::Vector3i32(const Vector3i32& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3i32& Vector3i32::operator=(const Vector3i32& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}

	inline Vector3i32::Vector3i32(Vector3i32&& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3i32& Vector3i32::operator=(Vector3i32&& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}
	// .....................................
	inline Vector3i32& Vector3i32::operator=(const std::int32_t& number) noexcept {
		x = number; y = number; z = number; return *this;
	}


	inline Vector3i32 Vector3i32::operator +(const Vector3i32& v) const noexcept {
		return { x + v.x, y + v.y, z + v.z };
	}

	inline Vector3i32 Vector3i32::operator -(const Vector3i32& v) const noexcept {
		return { x - v.x, y - v.y, z - v.z };
	}

	inline Vector3i32 Vector3i32::operator *(const Vector3i32& v) const noexcept {
		return { x * v.x, y * v.y, z * v.z };
	}

	inline Vector3i32 Vector3i32::operator /(const Vector3i32& v) const noexcept {
		return { x / v.x, y / v.y, z / v.z };
	}

 
	inline Vector3i32 Vector3i32::operator +(const std::int32_t& number) const noexcept {
		return { x + number, y + number, z + number };
	}

	inline Vector3i32 Vector3i32::operator -(const std::int32_t& number) const noexcept {
		return { x - number, y - number, z - number };
	}

	inline Vector3i32 Vector3i32::operator *(const std::int32_t& number) const noexcept {
		return { x * number, y * number, z * number };
	}

	inline Vector3i32 Vector3i32::operator /(const std::int32_t& number) const noexcept {
		return { x / number, y / number, z / number };
	}


	// increment / decrement
	inline Vector3i32& Vector3i32::operator++ () noexcept {
		++x; ++y; ++z;
		return *this;
	}

	inline Vector3i32& Vector3i32::operator-- () noexcept {
		--x; --y; --z;
		return *this;
	}

	inline Vector3i32 Vector3i32::operator++ (int) noexcept {
		Vector3i32 temp = *this;
		++* this;
		return temp;
	}

	inline Vector3i32 Vector3i32::operator-- (int) noexcept {
		Vector3i32 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector3i32& Vector3i32::operator+= (const Vector3i32& right) noexcept {
		x += right.x; y += right.y; z += right.z;
		return *this;
	}

	inline Vector3i32& Vector3i32::operator-= (const Vector3i32& right) noexcept {
		x -= right.x; y -= right.y; z -= right.z;
		return *this;
	}

	inline Vector3i32& Vector3i32::operator*= (const Vector3i32& right) noexcept {
		x *= right.x; y *= right.y; z *= right.z;
		return *this;
	}

	inline Vector3i32& Vector3i32::operator/= (const Vector3i32& right) noexcept {
		x /= right.x; y /= right.y; z /= right.z;
		return *this;
	}


	inline Vector3i32& Vector3i32::operator+= (const std::int32_t& number) noexcept {
		x += number; y += number; z += number;
		return *this;
	}

	inline Vector3i32& Vector3i32::operator-= (const std::int32_t& number) noexcept {
		x -= number; y -= number; z -= number;
		return *this;
	}

	inline Vector3i32& Vector3i32::operator*= (const std::int32_t& number) noexcept {
		x *= number; y *= number; z *= number;
		return *this;
	}

	inline Vector3i32& Vector3i32::operator/= (const std::int32_t& number) noexcept {
		x /= number; y /= number; z /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector3i32::operator< (const Vector3i32& other) const noexcept {
		return x < other.x && y < other.y&& z < other.z;
	}

	inline bool Vector3i32::operator<= (const Vector3i32& other) const noexcept {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	inline bool Vector3i32::operator>  (const Vector3i32& other) const noexcept {
		return x > other.x && y > other.y && z > other.z;
	}

	inline bool Vector3i32::operator>= (const Vector3i32& other) const noexcept {
		return x >= other.x && y >= other.y && z >= other.z;
	}


	inline bool Vector3i32::operator<  (const std::int32_t& number) const noexcept {
		return x < number && y < number && z < number;
	}

	inline bool Vector3i32::operator<= (const std::int32_t& number) const noexcept {
		return x <= number && y <= number && z <= number;
	}

	inline bool Vector3i32::operator>  (const std::int32_t& number) const noexcept {
		return x > number && y > number && z > number;
	}

	inline bool Vector3i32::operator>= (const std::int32_t& number) const noexcept {
		return x >= number && y >= number && z >= number;
	}


	// equal / not equal
	inline bool Vector3i32::operator==(const Vector3i32& other) const noexcept {
		return x == other.x && y == other.y && z == other.z;
	}

	inline bool Vector3i32::operator!=(const Vector3i32& other) const noexcept {
		return x != other.x || y != other.y || z != other.z;
	}

	inline bool Vector3i32::operator==(const std::int32_t& number) const noexcept {
		return x == number && y == number && z == number;
	}

	inline bool Vector3i32::operator!=(const std::int32_t& number) const noexcept {
		return x != number || y != number || z != number;
	}


	inline constexpr std::uint8_t Vector3i32::size() const noexcept { return 3; }
	inline void Vector3i32::reset(const std::int32_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int32_t& Vector3i32::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int32_t& Vector3i32::at(const std::uint8_t& index) noexcept
	{
		std::int32_t* ptr = &x;
		if (index > 2)
			return ptr[0];
		return ptr[index];
	}



	// Vector4i32
	inline Vector4i32::Vector4i32(const std::int32_t& a, const std::int32_t& b, const std::int32_t& c, const std::int32_t& d) noexcept
		: a(a), b(b), c(c), d(d) {}

	// copy/move constructor and assignment
	inline Vector4i32::Vector4i32(const Vector4i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4i32& Vector4i32::operator=(const Vector4i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}

	inline Vector4i32::Vector4i32(Vector4i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4i32& Vector4i32::operator=(Vector4i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}
	// .....................................
	inline Vector4i32& Vector4i32::operator=(const std::int32_t& number) noexcept {
		a = number; b = number; c = number; d = number; return *this;
	}


	inline Vector4i32 Vector4i32::operator +(const Vector4i32& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d };
	}

	inline Vector4i32 Vector4i32::operator -(const Vector4i32& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d };
	}

	inline Vector4i32 Vector4i32::operator *(const Vector4i32& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d };
	}

	inline Vector4i32 Vector4i32::operator /(const Vector4i32& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d };
	}


	inline Vector4i32 Vector4i32::operator +(const std::int32_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number };
	}

	inline Vector4i32 Vector4i32::operator -(const std::int32_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number };
	}

	inline Vector4i32 Vector4i32::operator *(const std::int32_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number };
	}

	inline Vector4i32 Vector4i32::operator /(const std::int32_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number };
	}


	// increment / decrement
	inline Vector4i32& Vector4i32::operator++ () noexcept {
		++a; ++b; ++c; ++d;
		return *this;
	}

	inline Vector4i32& Vector4i32::operator-- () noexcept {
		--a; --b; --c; --d;
		return *this;
	}

	inline Vector4i32 Vector4i32::operator++ (int) noexcept {
		Vector4i32 temp = *this;
		++* this;
		return temp;
	}

	inline Vector4i32 Vector4i32::operator-- (int) noexcept {
		Vector4i32 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector4i32& Vector4i32::operator+= (const Vector4i32& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d;
		return *this;
	}

	inline Vector4i32& Vector4i32::operator-= (const Vector4i32& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d;
		return *this;
	}

	inline Vector4i32& Vector4i32::operator*= (const Vector4i32& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d;
		return *this;
	}

	inline Vector4i32& Vector4i32::operator/= (const Vector4i32& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d;
		return *this;
	}


	inline Vector4i32& Vector4i32::operator+= (const std::int32_t& number) noexcept {
		a += number; b += number; c += number; d += number;
		return *this;
	}

	inline Vector4i32& Vector4i32::operator-= (const std::int32_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number;
		return *this;
	}

	inline Vector4i32& Vector4i32::operator*= (const std::int32_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number;
		return *this;
	}

	inline Vector4i32& Vector4i32::operator/= (const std::int32_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector4i32::operator< (const Vector4i32& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d;
	}

	inline bool Vector4i32::operator<= (const Vector4i32& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d;
	}

	inline bool Vector4i32::operator>  (const Vector4i32& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d;
	}

	inline bool Vector4i32::operator>= (const Vector4i32& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d;
	}


	inline bool Vector4i32::operator<  (const std::int32_t& number) const noexcept {
		return a < number && b < number && c < number && d < number;
	}

	inline bool Vector4i32::operator<= (const std::int32_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number;
	}

	inline bool Vector4i32::operator>  (const std::int32_t& number) const noexcept {
		return a > number && b > number && c > number && d > number;
	}

	inline bool Vector4i32::operator>= (const std::int32_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number;
	}


	// equal / not equal
	inline bool Vector4i32::operator==(const Vector4i32& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d;
	}

	inline bool Vector4i32::operator!=(const Vector4i32& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d;
	}

	inline bool Vector4i32::operator==(const std::int32_t& number) const noexcept {
		return a == number && b == number && c == number && d == number;
	}

	inline bool Vector4i32::operator!=(const std::int32_t& number) const noexcept {
		return a != number || b != number || c != number || d != number;
	}


	inline constexpr std::uint8_t Vector4i32::size() const noexcept { return 4; }
	inline void Vector4i32::reset(const std::int32_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int32_t& Vector4i32::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int32_t& Vector4i32::at(const std::uint8_t& index) noexcept
	{
		std::int32_t* ptr = &a;
		if (index > 3)
			return ptr[0];
		return ptr[index];
	}



	// Vector5i32
	inline Vector5i32::Vector5i32(const std::int32_t& a, const std::int32_t& b, const std::int32_t& c, const std::int32_t& d,
		const std::int32_t& e) noexcept
		: a(a), b(b), c(c), d(d), e(e) {}

	// copy/move constructor and assignment
	inline Vector5i32::Vector5i32(const Vector5i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5i32& Vector5i32::operator=(const Vector5i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}

	inline Vector5i32::Vector5i32(Vector5i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5i32& Vector5i32::operator=(Vector5i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}
	// .....................................
	inline Vector5i32& Vector5i32::operator=(const std::int32_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; return *this;
	}


	inline Vector5i32 Vector5i32::operator +(const Vector5i32& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e };
	}

	inline Vector5i32 Vector5i32::operator -(const Vector5i32& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e };
	}

	inline Vector5i32 Vector5i32::operator *(const Vector5i32& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e };
	}

	inline Vector5i32 Vector5i32::operator /(const Vector5i32& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e };
	}


	inline Vector5i32 Vector5i32::operator +(const std::int32_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number };
	}

	inline Vector5i32 Vector5i32::operator -(const std::int32_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number };
	}

	inline Vector5i32 Vector5i32::operator *(const std::int32_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number };
	}

	inline Vector5i32 Vector5i32::operator /(const std::int32_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number };
	}


	// increment / decrement
	inline Vector5i32& Vector5i32::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e;
		return *this;
	}

	inline Vector5i32& Vector5i32::operator-- () noexcept {
		--a; --b; --c; --d; --e;
		return *this;
	}

	inline Vector5i32 Vector5i32::operator++ (int) noexcept {
		Vector5i32 temp = *this;
		++* this;
		return temp;
	}

	inline Vector5i32 Vector5i32::operator-- (int) noexcept {
		Vector5i32 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector5i32& Vector5i32::operator+= (const Vector5i32& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e;
		return *this;
	}

	inline Vector5i32& Vector5i32::operator-= (const Vector5i32& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e;
		return *this;
	}

	inline Vector5i32& Vector5i32::operator*= (const Vector5i32& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e;
		return *this;
	}

	inline Vector5i32& Vector5i32::operator/= (const Vector5i32& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e;
		return *this;
	}


	inline Vector5i32& Vector5i32::operator+= (const std::int32_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number;
		return *this;
	}

	inline Vector5i32& Vector5i32::operator-= (const std::int32_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number;
		return *this;
	}

	inline Vector5i32& Vector5i32::operator*= (const std::int32_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number;
		return *this;
	}

	inline Vector5i32& Vector5i32::operator/= (const std::int32_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector5i32::operator< (const Vector5i32& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e;
	}

	inline bool Vector5i32::operator<= (const Vector5i32& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e;
	}

	inline bool Vector5i32::operator>  (const Vector5i32& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e;
	}

	inline bool Vector5i32::operator>= (const Vector5i32& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e;
	}


	inline bool Vector5i32::operator<  (const std::int32_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number;
	}

	inline bool Vector5i32::operator<= (const std::int32_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number;
	}

	inline bool Vector5i32::operator>  (const std::int32_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number;
	}

	inline bool Vector5i32::operator>= (const std::int32_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number;
	}


	// equal / not equal
	inline bool Vector5i32::operator==(const Vector5i32& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
	}

	inline bool Vector5i32::operator!=(const Vector5i32& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e;
	}

	inline bool Vector5i32::operator==(const std::int32_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number;
	}

	inline bool Vector5i32::operator!=(const std::int32_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number;
	}


	inline constexpr std::uint8_t Vector5i32::size() const noexcept { return 5; }
	inline void Vector5i32::reset(const std::int32_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int32_t& Vector5i32::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int32_t& Vector5i32::at(const std::uint8_t& index) noexcept
	{
		std::int32_t* ptr = &a;
		if (index > 4)
			return ptr[0];
		return ptr[index];
	}



	// Vector6i32
	inline Vector6i32::Vector6i32(const std::int32_t& a, const std::int32_t& b, const std::int32_t& c, const std::int32_t& d,
		const std::int32_t& e, const std::int32_t& f) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f) {}

	// copy/move constructor and assignment
	inline Vector6i32::Vector6i32(const Vector6i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6i32& Vector6i32::operator=(const Vector6i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}

	inline Vector6i32::Vector6i32(Vector6i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6i32& Vector6i32::operator=(Vector6i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}
	// .....................................
	inline Vector6i32& Vector6i32::operator=(const std::int32_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; return *this;
	}


	inline Vector6i32 Vector6i32::operator +(const Vector6i32& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f };
	}

	inline Vector6i32 Vector6i32::operator -(const Vector6i32& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f };
	}

	inline Vector6i32 Vector6i32::operator *(const Vector6i32& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f };
	}

	inline Vector6i32 Vector6i32::operator /(const Vector6i32& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f };
	}


	inline Vector6i32 Vector6i32::operator +(const std::int32_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number };
	}

	inline Vector6i32 Vector6i32::operator -(const std::int32_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number };
	}

	inline Vector6i32 Vector6i32::operator *(const std::int32_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number };
	}

	inline Vector6i32 Vector6i32::operator /(const std::int32_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number };
	}


	// increment / decrement
	inline Vector6i32& Vector6i32::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f;
		return *this;
	}

	inline Vector6i32& Vector6i32::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f;
		return *this;
	}

	inline Vector6i32 Vector6i32::operator++ (int) noexcept {
		Vector6i32 temp = *this;
		++* this;
		return temp;
	}

	inline Vector6i32 Vector6i32::operator-- (int) noexcept {
		Vector6i32 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector6i32& Vector6i32::operator+= (const Vector6i32& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f;
		return *this;
	}

	inline Vector6i32& Vector6i32::operator-= (const Vector6i32& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f;
		return *this;
	}

	inline Vector6i32& Vector6i32::operator*= (const Vector6i32& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f;
		return *this;
	}

	inline Vector6i32& Vector6i32::operator/= (const Vector6i32& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f;
		return *this;
	}


	inline Vector6i32& Vector6i32::operator+= (const std::int32_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number;
		return *this;
	}

	inline Vector6i32& Vector6i32::operator-= (const std::int32_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number;
		return *this;
	}

	inline Vector6i32& Vector6i32::operator*= (const std::int32_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number;
		return *this;
	}

	inline Vector6i32& Vector6i32::operator/= (const std::int32_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector6i32::operator< (const Vector6i32& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f;
	}

	inline bool Vector6i32::operator<= (const Vector6i32& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f;
	}

	inline bool Vector6i32::operator>  (const Vector6i32& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f;
	}

	inline bool Vector6i32::operator>= (const Vector6i32& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f;
	}


	inline bool Vector6i32::operator<  (const std::int32_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number;
	}

	inline bool Vector6i32::operator<= (const std::int32_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number;
	}

	inline bool Vector6i32::operator>  (const std::int32_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number;
	}

	inline bool Vector6i32::operator>= (const std::int32_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number;
	}


	// equal / not equal
	inline bool Vector6i32::operator==(const Vector6i32& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f;
	}

	inline bool Vector6i32::operator!=(const Vector6i32& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f;
	}

	inline bool Vector6i32::operator==(const std::int32_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number;
	}

	inline bool Vector6i32::operator!=(const std::int32_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number;
	}


	inline constexpr std::uint8_t Vector6i32::size() const noexcept { return 6; }
	inline void Vector6i32::reset(const std::int32_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int32_t& Vector6i32::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int32_t& Vector6i32::at(const std::uint8_t& index) noexcept
	{
		std::int32_t* ptr = &a;
		if (index > 5)
			return ptr[0];
		return ptr[index];
	}



	// Vector7i32
	inline Vector7i32::Vector7i32(const std::int32_t& a, const std::int32_t& b, const std::int32_t& c, const std::int32_t& d,
		const std::int32_t& e, const std::int32_t& f, const std::int32_t& g) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g) {}

	// copy/move constructor and assignment
	inline Vector7i32::Vector7i32(const Vector7i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7i32& Vector7i32::operator=(const Vector7i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}

	inline Vector7i32::Vector7i32(Vector7i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7i32& Vector7i32::operator=(Vector7i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}
	// .....................................
	inline Vector7i32& Vector7i32::operator=(const std::int32_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; return *this;
	}


	inline Vector7i32 Vector7i32::operator +(const Vector7i32& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g };
	}

	inline Vector7i32 Vector7i32::operator -(const Vector7i32& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g };
	}

	inline Vector7i32 Vector7i32::operator *(const Vector7i32& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g };
	}

	inline Vector7i32 Vector7i32::operator /(const Vector7i32& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g };
	}


	inline Vector7i32 Vector7i32::operator +(const std::int32_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number };
	}

	inline Vector7i32 Vector7i32::operator -(const std::int32_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number };
	}

	inline Vector7i32 Vector7i32::operator *(const std::int32_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number };
	}

	inline Vector7i32 Vector7i32::operator /(const std::int32_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number };
	}


	// increment / decrement
	inline Vector7i32& Vector7i32::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g;
		return *this;
	}

	inline Vector7i32& Vector7i32::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g;
		return *this;
	}

	inline Vector7i32 Vector7i32::operator++ (int) noexcept {
		Vector7i32 temp = *this;
		++* this;
		return temp;
	}

	inline Vector7i32 Vector7i32::operator-- (int) noexcept {
		Vector7i32 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector7i32& Vector7i32::operator+= (const Vector7i32& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g;
		return *this;
	}

	inline Vector7i32& Vector7i32::operator-= (const Vector7i32& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g;
		return *this;
	}

	inline Vector7i32& Vector7i32::operator*= (const Vector7i32& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g;
		return *this;
	}

	inline Vector7i32& Vector7i32::operator/= (const Vector7i32& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g;
		return *this;
	}


	inline Vector7i32& Vector7i32::operator+= (const std::int32_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number;
		return *this;
	}

	inline Vector7i32& Vector7i32::operator-= (const std::int32_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number;
		return *this;
	}

	inline Vector7i32& Vector7i32::operator*= (const std::int32_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number;
		return *this;
	}

	inline Vector7i32& Vector7i32::operator/= (const std::int32_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector7i32::operator< (const Vector7i32& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g;
	}

	inline bool Vector7i32::operator<= (const Vector7i32& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g;
	}

	inline bool Vector7i32::operator>  (const Vector7i32& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g;
	}

	inline bool Vector7i32::operator>= (const Vector7i32& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g;
	}


	inline bool Vector7i32::operator<  (const std::int32_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number;
	}

	inline bool Vector7i32::operator<= (const std::int32_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number;
	}

	inline bool Vector7i32::operator>  (const std::int32_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number;
	}

	inline bool Vector7i32::operator>= (const std::int32_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number;
	}


	// equal / not equal
	inline bool Vector7i32::operator==(const Vector7i32& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g;
	}

	inline bool Vector7i32::operator!=(const Vector7i32& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g;
	}

	inline bool Vector7i32::operator==(const std::int32_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number;
	}

	inline bool Vector7i32::operator!=(const std::int32_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number;
	}


	inline constexpr std::uint8_t Vector7i32::size() const noexcept { return 7; }
	inline void Vector7i32::reset(const std::int32_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int32_t& Vector7i32::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int32_t& Vector7i32::at(const std::uint8_t& index) noexcept
	{
		std::int32_t* ptr = &a;
		if (index > 6)
			return ptr[0];
		return ptr[index];
	}



	// Vector8i32
	inline Vector8i32::Vector8i32(const std::int32_t& a, const std::int32_t& b, const std::int32_t& c, const std::int32_t& d,
		const std::int32_t& e, const std::int32_t& f, const std::int32_t& g, const std::int32_t& h) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h) {}

	// copy/move constructor and assignment
	inline Vector8i32::Vector8i32(const Vector8i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8i32& Vector8i32::operator=(const Vector8i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}

	inline Vector8i32::Vector8i32(Vector8i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8i32& Vector8i32::operator=(Vector8i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}
	// .....................................
	inline Vector8i32& Vector8i32::operator=(const std::int32_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; return *this;
	}


	inline Vector8i32 Vector8i32::operator +(const Vector8i32& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h };
	}

	inline Vector8i32 Vector8i32::operator -(const Vector8i32& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h };
	}

	inline Vector8i32 Vector8i32::operator *(const Vector8i32& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h };
	}

	inline Vector8i32 Vector8i32::operator /(const Vector8i32& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h };
	}


	inline Vector8i32 Vector8i32::operator +(const std::int32_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number };
	}

	inline Vector8i32 Vector8i32::operator -(const std::int32_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number };
	}

	inline Vector8i32 Vector8i32::operator *(const std::int32_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number };
	}

	inline Vector8i32 Vector8i32::operator /(const std::int32_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number };
	}


	// increment / decrement
	inline Vector8i32& Vector8i32::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h;
		return *this;
	}

	inline Vector8i32& Vector8i32::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h;
		return *this;
	}

	inline Vector8i32 Vector8i32::operator++ (int) noexcept {
		Vector8i32 temp = *this;
		++* this;
		return temp;
	}

	inline Vector8i32 Vector8i32::operator-- (int) noexcept {
		Vector8i32 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector8i32& Vector8i32::operator+= (const Vector8i32& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h;
		return *this;
	}

	inline Vector8i32& Vector8i32::operator-= (const Vector8i32& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h;
		return *this;
	}

	inline Vector8i32& Vector8i32::operator*= (const Vector8i32& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h;
		return *this;
	}

	inline Vector8i32& Vector8i32::operator/= (const Vector8i32& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h;
		return *this;
	}


	inline Vector8i32& Vector8i32::operator+= (const std::int32_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number;
		return *this;
	}

	inline Vector8i32& Vector8i32::operator-= (const std::int32_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number;
		return *this;
	}

	inline Vector8i32& Vector8i32::operator*= (const std::int32_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number;
		return *this;
	}

	inline Vector8i32& Vector8i32::operator/= (const std::int32_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector8i32::operator< (const Vector8i32& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h;
	}

	inline bool Vector8i32::operator<= (const Vector8i32& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h;
	}

	inline bool Vector8i32::operator>  (const Vector8i32& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h;
	}

	inline bool Vector8i32::operator>= (const Vector8i32& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h;
	}


	inline bool Vector8i32::operator<  (const std::int32_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number;
	}

	inline bool Vector8i32::operator<= (const std::int32_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number;
	}

	inline bool Vector8i32::operator>  (const std::int32_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number;
	}

	inline bool Vector8i32::operator>= (const std::int32_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number;
	}


	// equal / not equal
	inline bool Vector8i32::operator==(const Vector8i32& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h;
	}

	inline bool Vector8i32::operator!=(const Vector8i32& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h;
	}

	inline bool Vector8i32::operator==(const std::int32_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number;
	}

	inline bool Vector8i32::operator!=(const std::int32_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number;
	}


	inline constexpr std::uint8_t Vector8i32::size() const noexcept { return 8; }
	inline void Vector8i32::reset(const std::int32_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int32_t& Vector8i32::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int32_t& Vector8i32::at(const std::uint8_t& index) noexcept
	{
		std::int32_t* ptr = &a;
		if (index > 7)
			return ptr[0];
		return ptr[index];
	}



	// Vector9i32
	inline Vector9i32::Vector9i32(const std::int32_t& a, const std::int32_t& b, const std::int32_t& c, const std::int32_t& d,
		const std::int32_t& e, const std::int32_t& f, const std::int32_t& g, const std::int32_t& h,
		const std::int32_t& i) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

	// copy/move constructor and assignment
	inline Vector9i32::Vector9i32(const Vector9i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9i32& Vector9i32::operator=(const Vector9i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}

	inline Vector9i32::Vector9i32(Vector9i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9i32& Vector9i32::operator=(Vector9i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}
	// .....................................
	inline Vector9i32& Vector9i32::operator=(const std::int32_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; return *this;
	}


	inline Vector9i32 Vector9i32::operator +(const Vector9i32& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i };
	}

	inline Vector9i32 Vector9i32::operator -(const Vector9i32& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i };
	}

	inline Vector9i32 Vector9i32::operator *(const Vector9i32& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i };
	}

	inline Vector9i32 Vector9i32::operator /(const Vector9i32& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i };
	}


	inline Vector9i32 Vector9i32::operator +(const std::int32_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number };
	}

	inline Vector9i32 Vector9i32::operator -(const std::int32_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number };
	}

	inline Vector9i32 Vector9i32::operator *(const std::int32_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number };
	}

	inline Vector9i32 Vector9i32::operator /(const std::int32_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number };
	}


	// increment / decrement
	inline Vector9i32& Vector9i32::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i;
		return *this;
	}

	inline Vector9i32& Vector9i32::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i;
		return *this;
	}

	inline Vector9i32 Vector9i32::operator++ (int) noexcept {
		Vector9i32 temp = *this;
		++* this;
		return temp;
	}

	inline Vector9i32 Vector9i32::operator-- (int) noexcept {
		Vector9i32 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector9i32& Vector9i32::operator+= (const Vector9i32& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i;
		return *this;
	}

	inline Vector9i32& Vector9i32::operator-= (const Vector9i32& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i;
		return *this;
	}

	inline Vector9i32& Vector9i32::operator*= (const Vector9i32& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i;
		return *this;
	}

	inline Vector9i32& Vector9i32::operator/= (const Vector9i32& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i;
		return *this;
	}


	inline Vector9i32& Vector9i32::operator+= (const std::int32_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number;
		return *this;
	}

	inline Vector9i32& Vector9i32::operator-= (const std::int32_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number;
		return *this;
	}

	inline Vector9i32& Vector9i32::operator*= (const std::int32_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number;
		return *this;
	}

	inline Vector9i32& Vector9i32::operator/= (const std::int32_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector9i32::operator< (const Vector9i32& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i;
	}

	inline bool Vector9i32::operator<= (const Vector9i32& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i;
	}

	inline bool Vector9i32::operator>  (const Vector9i32& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i;
	}

	inline bool Vector9i32::operator>= (const Vector9i32& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i;
	}


	inline bool Vector9i32::operator<  (const std::int32_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number;
	}

	inline bool Vector9i32::operator<= (const std::int32_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number;
	}

	inline bool Vector9i32::operator>  (const std::int32_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number;
	}

	inline bool Vector9i32::operator>= (const std::int32_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number;
	}


	// equal / not equal
	inline bool Vector9i32::operator==(const Vector9i32& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i;
	}

	inline bool Vector9i32::operator!=(const Vector9i32& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i;
	}

	inline bool Vector9i32::operator==(const std::int32_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number;
	}

	inline bool Vector9i32::operator!=(const std::int32_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number;
	}


	inline constexpr std::uint8_t Vector9i32::size() const noexcept { return 9; }
	inline void Vector9i32::reset(const std::int32_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int32_t& Vector9i32::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int32_t& Vector9i32::at(const std::uint8_t& index) noexcept
	{
		std::int32_t* ptr = &a;
		if (index > 8)
			return ptr[0];
		return ptr[index];
	}



	// Vector10i32
	inline Vector10i32::Vector10i32(const std::int32_t& a, const std::int32_t& b, const std::int32_t& c, const std::int32_t& d,
		const std::int32_t& e, const std::int32_t& f, const std::int32_t& g, const std::int32_t& h,
		const std::int32_t& i, const std::int32_t& j) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {}

	// copy/move constructor and assignment
	inline Vector10i32::Vector10i32(const Vector10i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10i32& Vector10i32::operator=(const Vector10i32& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}

	inline Vector10i32::Vector10i32(Vector10i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10i32& Vector10i32::operator=(Vector10i32&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}
	// .....................................
	inline Vector10i32& Vector10i32::operator=(const std::int32_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; j = number; return *this;
	}


	inline Vector10i32 Vector10i32::operator +(const Vector10i32& v) const noexcept {
		return { a + v.a, b + v.b, c + v.c, d + v.d, e + v.e, f + v.f, g + v.g, h + v.h, i + v.i, j + v.j };
	}

	inline Vector10i32 Vector10i32::operator -(const Vector10i32& v) const noexcept {
		return { a - v.a, b - v.b, c - v.c, d - v.d, e - v.e, f - v.f, g - v.g, h - v.h, i - v.i, j - v.j };
	}

	inline Vector10i32 Vector10i32::operator *(const Vector10i32& v) const noexcept {
		return { a * v.a, b * v.b, c * v.c, d * v.d, e * v.e, f * v.f, g * v.g, h * v.h, i * v.i, j * v.j };
	}

	inline Vector10i32 Vector10i32::operator /(const Vector10i32& v) const noexcept {
		return { a / v.a, b / v.b, c / v.c, d / v.d, e / v.e, f / v.f, g / v.g, h / v.h, i / v.i, j / v.j };
	}


	inline Vector10i32 Vector10i32::operator +(const std::int32_t& number) const noexcept {
		return { a + number, b + number, c + number, d + number, e + number, f + number, g + number, h + number, i + number, j + number };
	}

	inline Vector10i32 Vector10i32::operator -(const std::int32_t& number) const noexcept {
		return { a - number, b - number, c - number, d - number, e - number, f - number, g - number, h - number, i - number, j - number };
	}

	inline Vector10i32 Vector10i32::operator *(const std::int32_t& number) const noexcept {
		return { a * number, b * number, c * number, d * number, e * number, f * number, g * number, h * number, i * number, j * number };
	}

	inline Vector10i32 Vector10i32::operator /(const std::int32_t& number) const noexcept {
		return { a / number, b / number, c / number, d / number, e / number, f / number, g / number, h / number, i / number, j / number };
	}


	// increment / decrement
	inline Vector10i32& Vector10i32::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i; ++j;
		return *this;
	}

	inline Vector10i32& Vector10i32::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i; --j;
		return *this;
	}

	inline Vector10i32 Vector10i32::operator++ (int) noexcept {
		Vector10i32 temp = *this;
		++* this;
		return temp;
	}

	inline Vector10i32 Vector10i32::operator-- (int) noexcept {
		Vector10i32 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector10i32& Vector10i32::operator+= (const Vector10i32& right) noexcept {
		a += right.a; b += right.b; c += right.c; d += right.d; e += right.e; f += right.f; g += right.g; h += right.h; i += right.i; j += right.j;
		return *this;
	}

	inline Vector10i32& Vector10i32::operator-= (const Vector10i32& right) noexcept {
		a -= right.a; b -= right.b; c -= right.c; d -= right.d; e -= right.e; f -= right.f; g -= right.g; h -= right.h; i -= right.i; j -= right.j;
		return *this;
	}

	inline Vector10i32& Vector10i32::operator*= (const Vector10i32& right) noexcept {
		a *= right.a; b *= right.b; c *= right.c; d *= right.d; e *= right.e; f *= right.f; g *= right.g; h *= right.h; i *= right.i; j *= right.j;
		return *this;
	}

	inline Vector10i32& Vector10i32::operator/= (const Vector10i32& right) noexcept {
		a /= right.a; b /= right.b; c /= right.c; d /= right.d; e /= right.e; f /= right.f; g /= right.g; h /= right.h; i /= right.i; j /= right.j;
		return *this;
	}


	inline Vector10i32& Vector10i32::operator+= (const std::int32_t& number) noexcept {
		a += number; b += number; c += number; d += number; e += number; f += number; g += number; h += number; i += number; j += number;
		return *this;
	}

	inline Vector10i32& Vector10i32::operator-= (const std::int32_t& number) noexcept {
		a -= number; b -= number; c -= number; d -= number; e -= number; f -= number; g -= number; h -= number; i -= number; j -= number;
		return *this;
	}

	inline Vector10i32& Vector10i32::operator*= (const std::int32_t& number) noexcept {
		a *= number; b *= number; c *= number; d *= number; e *= number; f *= number; g *= number; h *= number; i *= number; j *= number;
		return *this;
	}

	inline Vector10i32& Vector10i32::operator/= (const std::int32_t& number) noexcept {
		a /= number; b /= number; c /= number; d /= number; e /= number; f /= number; g /= number; h /= number; i /= number; j /= number;
		return *this;
	}


	// less than / greater than
	inline bool Vector10i32::operator< (const Vector10i32& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i&& j < other.j;
	}

	inline bool Vector10i32::operator<= (const Vector10i32& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i && j <= other.j;
	}

	inline bool Vector10i32::operator>  (const Vector10i32& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i && j > other.j;
	}

	inline bool Vector10i32::operator>= (const Vector10i32& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i && j >= other.j;
	}


	inline bool Vector10i32::operator<  (const std::int32_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number && j < number;
	}

	inline bool Vector10i32::operator<= (const std::int32_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number && j <= number;
	}

	inline bool Vector10i32::operator>  (const std::int32_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number && j > number;
	}

	inline bool Vector10i32::operator>= (const std::int32_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number && j >= number;
	}


	// equal / not equal
	inline bool Vector10i32::operator==(const Vector10i32& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i && j == other.j;
	}

	inline bool Vector10i32::operator!=(const Vector10i32& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i || j != other.j;
	}

	inline bool Vector10i32::operator==(const std::int32_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number && j == number;
	}

	inline bool Vector10i32::operator!=(const std::int32_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number || j != number;
	}


	inline constexpr std::uint8_t Vector10i32::size() const noexcept { return 10; }
	inline void Vector10i32::reset(const std::int32_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int32_t& Vector10i32::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int32_t& Vector10i32::at(const std::uint8_t& index) noexcept
	{
		std::int32_t* ptr = &a;
		if (index > 9)
			return ptr[0];
		return ptr[index];
	}
	// End
}