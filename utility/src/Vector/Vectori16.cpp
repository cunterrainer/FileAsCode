#include "Vectori16.h"

#define cast(x) static_cast<std::int16_t>(x)

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::int16_t
		Bytes: 2
		Range: -32.768 to 32.767
	*/

	// Vector2i16
	inline Vector2i16::Vector2i16(const std::int16_t& x, const std::int16_t& y) noexcept
		: x(x), y(y) {}

	// copy/move constructor and assignment
	inline Vector2i16::Vector2i16(const Vector2i16& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2i16& Vector2i16::operator=(const Vector2i16& other) noexcept {
		x = other.x; y = other.y; return *this;
	}

	inline Vector2i16::Vector2i16(Vector2i16&& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2i16& Vector2i16::operator=(Vector2i16&& other) noexcept {
		x = other.x; y = other.y; return *this;
	}
	// .....................................
	inline Vector2i16& Vector2i16::operator=(const std::int16_t& number) noexcept {
		x = number; y = number; return *this;
	}


	inline Vector2i16 Vector2i16::operator +(const Vector2i16& v) const noexcept {
		return { cast(x + v.x), cast(y + v.y) };
	}

	inline Vector2i16 Vector2i16::operator -(const Vector2i16& v) const noexcept {
		return { cast(x - v.x), cast(y - v.y) };
	}

	inline Vector2i16 Vector2i16::operator *(const Vector2i16& v) const noexcept {
		return { cast(x * v.x), cast(y * v.y) };
	}

	inline Vector2i16 Vector2i16::operator /(const Vector2i16& v) const noexcept {
		return { cast(x / v.x), cast(y / v.y) };
	}


	inline Vector2i16 Vector2i16::operator +(const std::int16_t& number) const noexcept {
		return { cast(x + number), cast(y + number) };
	}

	inline Vector2i16 Vector2i16::operator -(const std::int16_t& number) const noexcept {
		return { cast(x - number), cast(y - number) };
	}

	inline Vector2i16 Vector2i16::operator *(const std::int16_t& number) const noexcept {
		return { cast(x * number), cast(y * number) };
	}

	inline Vector2i16 Vector2i16::operator /(const std::int16_t& number) const noexcept {
		return { cast(x / number), cast(y / number) };
	}


	// increment / decrement
	inline Vector2i16& Vector2i16::operator++ () noexcept {
		++x; ++y;
		return *this;
	}

	inline Vector2i16& Vector2i16::operator-- ()  noexcept {
		--x; --y;
		return *this;
	}

	inline Vector2i16 Vector2i16::operator++ (int) noexcept {
		Vector2i16 temp = *this;
		++* this;
		return temp;
	}

	inline Vector2i16 Vector2i16::operator-- (int) noexcept {
		Vector2i16 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector2i16& Vector2i16::operator+= (const Vector2i16& right) noexcept {
		cast(x += right.x); cast(y += right.y);
		return *this;
	}

	inline Vector2i16& Vector2i16::operator-= (const Vector2i16& right) noexcept {
		cast(x -= right.x); cast(y -= right.y);
		return *this;
	}

	inline Vector2i16& Vector2i16::operator*= (const Vector2i16& right) noexcept {
		cast(x *= right.x); cast(y *= right.y);
		return *this;
	}

	inline Vector2i16& Vector2i16::operator/= (const Vector2i16& right) noexcept {
		cast(x /= right.x); cast(y /= right.y);
		return *this;
	}


	inline Vector2i16& Vector2i16::operator+= (const std::int16_t& number) noexcept {
		cast(x += number); cast(y += number);
		return *this;
	}

	inline Vector2i16& Vector2i16::operator-= (const std::int16_t& number) noexcept {
		cast(x -= number); cast(y -= number);
		return *this;
	}

	inline Vector2i16& Vector2i16::operator*= (const std::int16_t& number) noexcept {
		cast(x *= number); cast(y *= number);
		return *this;
	}

	inline Vector2i16& Vector2i16::operator/= (const std::int16_t& number) noexcept {
		cast(x /= number); cast(y /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector2i16::operator< (const Vector2i16& other) const noexcept {
		return x < other.x && y < other.y;
	}

	inline bool Vector2i16::operator<= (const Vector2i16& other) const noexcept {
		return x <= other.x && y <= other.y;
	}

	inline bool Vector2i16::operator>  (const Vector2i16& other) const noexcept {
		return x > other.x && y > other.y;
	}

	inline bool Vector2i16::operator>= (const Vector2i16& other) const noexcept {
		return x >= other.x && y >= other.y;
	}


	inline bool Vector2i16::operator<  (const std::int16_t& number) const noexcept {
		return x < number && y < number;
	}

	inline bool Vector2i16::operator<= (const std::int16_t& number) const noexcept {
		return x <= number && y <= number;
	}

	inline bool Vector2i16::operator>  (const std::int16_t& number) const noexcept {
		return x > number && y > number;
	}

	inline bool Vector2i16::operator>= (const std::int16_t& number) const noexcept {
		return x >= number && y >= number;
	}


	// equal / not equal
	inline bool Vector2i16::operator==(const Vector2i16& other) const noexcept {
		return x == other.x && y == other.y;
	}

	inline bool Vector2i16::operator!=(const Vector2i16& other) const noexcept {
		return x != other.x || y != other.y;
	}

	inline bool Vector2i16::operator==(const std::int16_t& number) const noexcept {
		return x == number && y == number;
	}

	inline bool Vector2i16::operator!=(const std::int16_t& number) const noexcept {
		return x != number || y != number;
	}


	inline constexpr std::uint8_t Vector2i16::size() const noexcept { return 2; }
	inline void Vector2i16::reset(const std::int16_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int16_t& Vector2i16::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int16_t& Vector2i16::at(const std::uint8_t& index) noexcept
	{
		std::int16_t* ptr = &x;
		if (index > 1)
			return ptr[0];
		return ptr[index];
	}



	// Vector3i16
	inline Vector3i16::Vector3i16(const std::int16_t& x, const std::int16_t& y, const std::int16_t& z) noexcept
		: x(x), y(y), z(z) {}

	// copy/move constructor and assignment
	inline Vector3i16::Vector3i16(const Vector3i16& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3i16& Vector3i16::operator=(const Vector3i16& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}

	inline Vector3i16::Vector3i16(Vector3i16&& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3i16& Vector3i16::operator=(Vector3i16&& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}
	// .....................................
	inline Vector3i16& Vector3i16::operator=(const std::int16_t& number) noexcept {
		x = number; y = number; z = number; return *this;
	}


	inline Vector3i16 Vector3i16::operator +(const Vector3i16& v) const noexcept {
		return { cast(x + v.x), cast(y + v.y), cast(z + v.z) };
	}

	inline Vector3i16 Vector3i16::operator -(const Vector3i16& v) const noexcept {
		return { cast(x - v.x), cast(y - v.y), cast(z - v.z) };
	}

	inline Vector3i16 Vector3i16::operator *(const Vector3i16& v) const noexcept {
		return { cast(x * v.x), cast(y * v.y), cast(z * v.z) };
	}

	inline Vector3i16 Vector3i16::operator /(const Vector3i16& v) const noexcept {
		return { cast(x / v.x), cast(y / v.y), cast(z / v.z) };
	}

 
	inline Vector3i16 Vector3i16::operator +(const std::int16_t& number) const noexcept {
		return { cast(x + number), cast(y + number), cast(z + number) };
	}

	inline Vector3i16 Vector3i16::operator -(const std::int16_t& number) const noexcept {
		return { cast(x - number), cast(y - number), cast(z - number) };
	}

	inline Vector3i16 Vector3i16::operator *(const std::int16_t& number) const noexcept {
		return { cast(x * number), cast(y * number), cast(z * number) };
	}

	inline Vector3i16 Vector3i16::operator /(const std::int16_t& number) const noexcept {
		return { cast(x / number), cast(y / number), cast(z / number) };
	}


	// increment / decrement
	inline Vector3i16& Vector3i16::operator++ () noexcept {
		++x; ++y; ++z;
		return *this;
	}

	inline Vector3i16& Vector3i16::operator-- () noexcept {
		--x; --y; --z;
		return *this;
	}

	inline Vector3i16 Vector3i16::operator++ (int) noexcept {
		Vector3i16 temp = *this;
		++* this;
		return temp;
	}

	inline Vector3i16 Vector3i16::operator-- (int) noexcept {
		Vector3i16 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector3i16& Vector3i16::operator+= (const Vector3i16& right) noexcept {
		cast(x += right.x); cast(y += right.y); cast(z += right.z);
		return *this;
	}

	inline Vector3i16& Vector3i16::operator-= (const Vector3i16& right) noexcept {
		cast(x -= right.x); cast(y -= right.y); cast(z -= right.z);
		return *this;
	}

	inline Vector3i16& Vector3i16::operator*= (const Vector3i16& right) noexcept {
		cast(x *= right.x); cast(y *= right.y); cast(z *= right.z);
		return *this;
	}

	inline Vector3i16& Vector3i16::operator/= (const Vector3i16& right) noexcept {
		cast(x /= right.x); cast(y /= right.y); cast(z /= right.z);
		return *this;
	}


	inline Vector3i16& Vector3i16::operator+= (const std::int16_t& number) noexcept {
		cast(x += number); cast(y += number); cast(z += number);
		return *this;
	}

	inline Vector3i16& Vector3i16::operator-= (const std::int16_t& number) noexcept {
		cast(x -= number); cast(y -= number); cast(z -= number);
		return *this;
	}

	inline Vector3i16& Vector3i16::operator*= (const std::int16_t& number) noexcept {
		cast(x *= number); cast(y *= number); cast(z *= number);
		return *this;
	}

	inline Vector3i16& Vector3i16::operator/= (const std::int16_t& number) noexcept {
		cast(x /= number); cast(y /= number); cast(z /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector3i16::operator< (const Vector3i16& other) const noexcept {
		return x < other.x && y < other.y&& z < other.z;
	}

	inline bool Vector3i16::operator<= (const Vector3i16& other) const noexcept {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	inline bool Vector3i16::operator>  (const Vector3i16& other) const noexcept {
		return x > other.x && y > other.y && z > other.z;
	}

	inline bool Vector3i16::operator>= (const Vector3i16& other) const noexcept {
		return x >= other.x && y >= other.y && z >= other.z;
	}


	inline bool Vector3i16::operator<  (const std::int16_t& number) const noexcept {
		return x < number && y < number && z < number;
	}

	inline bool Vector3i16::operator<= (const std::int16_t& number) const noexcept {
		return x <= number && y <= number && z <= number;
	}

	inline bool Vector3i16::operator>  (const std::int16_t& number) const noexcept {
		return x > number && y > number && z > number;
	}

	inline bool Vector3i16::operator>= (const std::int16_t& number) const noexcept {
		return x >= number && y >= number && z >= number;
	}


	// equal / not equal
	inline bool Vector3i16::operator==(const Vector3i16& other) const noexcept {
		return x == other.x && y == other.y && z == other.z;
	}

	inline bool Vector3i16::operator!=(const Vector3i16& other) const noexcept {
		return x != other.x || y != other.y || z != other.z;
	}

	inline bool Vector3i16::operator==(const std::int16_t& number) const noexcept {
		return x == number && y == number && z == number;
	}

	inline bool Vector3i16::operator!=(const std::int16_t& number) const noexcept {
		return x != number || y != number || z != number;
	}


	inline constexpr std::uint8_t Vector3i16::size() const noexcept { return 3; }
	inline void Vector3i16::reset(const std::int16_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int16_t& Vector3i16::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int16_t& Vector3i16::at(const std::uint8_t& index) noexcept
	{
		std::int16_t* ptr = &x;
		if (index > 2)
			return ptr[0];
		return ptr[index];
	}



	// Vector4i16
	inline Vector4i16::Vector4i16(const std::int16_t& a, const std::int16_t& b, const std::int16_t& c, const std::int16_t& d) noexcept
		: a(a), b(b), c(c), d(d) {}

	// copy/move constructor and assignment
	inline Vector4i16::Vector4i16(const Vector4i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4i16& Vector4i16::operator=(const Vector4i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}

	inline Vector4i16::Vector4i16(Vector4i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4i16& Vector4i16::operator=(Vector4i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}
	// .....................................
	inline Vector4i16& Vector4i16::operator=(const std::int16_t& number) noexcept {
		a = number; b = number; c = number; d = number; return *this;
	}


	inline Vector4i16 Vector4i16::operator +(const Vector4i16& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d) };
	}

	inline Vector4i16 Vector4i16::operator -(const Vector4i16& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d) };
	}

	inline Vector4i16 Vector4i16::operator *(const Vector4i16& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d) };
	}

	inline Vector4i16 Vector4i16::operator /(const Vector4i16& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d) };
	}


	inline Vector4i16 Vector4i16::operator +(const std::int16_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number) };
	}

	inline Vector4i16 Vector4i16::operator -(const std::int16_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number) };
	}

	inline Vector4i16 Vector4i16::operator *(const std::int16_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number) };
	}

	inline Vector4i16 Vector4i16::operator /(const std::int16_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number) };
	}


	// increment / decrement
	inline Vector4i16& Vector4i16::operator++ () noexcept {
		++a; ++b; ++c; ++d;
		return *this;
	}

	inline Vector4i16& Vector4i16::operator-- () noexcept {
		--a; --b; --c; --d;
		return *this;
	}

	inline Vector4i16 Vector4i16::operator++ (int) noexcept {
		Vector4i16 temp = *this;
		++* this;
		return temp;
	}

	inline Vector4i16 Vector4i16::operator-- (int) noexcept {
		Vector4i16 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector4i16& Vector4i16::operator+= (const Vector4i16& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d);
		return *this;
	}

	inline Vector4i16& Vector4i16::operator-= (const Vector4i16& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d);
		return *this;
	}

	inline Vector4i16& Vector4i16::operator*= (const Vector4i16& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d);
		return *this;
	}

	inline Vector4i16& Vector4i16::operator/= (const Vector4i16& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d);
		return *this;
	}


	inline Vector4i16& Vector4i16::operator+= (const std::int16_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number);
		return *this;
	}

	inline Vector4i16& Vector4i16::operator-= (const std::int16_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number);
		return *this;
	}

	inline Vector4i16& Vector4i16::operator*= (const std::int16_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number);
		return *this;
	}

	inline Vector4i16& Vector4i16::operator/= (const std::int16_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector4i16::operator< (const Vector4i16& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d;
	}

	inline bool Vector4i16::operator<= (const Vector4i16& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d;
	}

	inline bool Vector4i16::operator>  (const Vector4i16& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d;
	}

	inline bool Vector4i16::operator>= (const Vector4i16& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d;
	}


	inline bool Vector4i16::operator<  (const std::int16_t& number) const noexcept {
		return a < number && b < number && c < number && d < number;
	}

	inline bool Vector4i16::operator<= (const std::int16_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number;
	}

	inline bool Vector4i16::operator>  (const std::int16_t& number) const noexcept {
		return a > number && b > number && c > number && d > number;
	}

	inline bool Vector4i16::operator>= (const std::int16_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number;
	}


	// equal / not equal
	inline bool Vector4i16::operator==(const Vector4i16& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d;
	}

	inline bool Vector4i16::operator!=(const Vector4i16& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d;
	}

	inline bool Vector4i16::operator==(const std::int16_t& number) const noexcept {
		return a == number && b == number && c == number && d == number;
	}

	inline bool Vector4i16::operator!=(const std::int16_t& number) const noexcept {
		return a != number || b != number || c != number || d != number;
	}


	inline constexpr std::uint8_t Vector4i16::size() const noexcept { return 4; }
	inline void Vector4i16::reset(const std::int16_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int16_t& Vector4i16::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int16_t& Vector4i16::at(const std::uint8_t& index) noexcept
	{
		std::int16_t* ptr = &a;
		if (index > 3)
			return ptr[0];
		return ptr[index];
	}



	// Vector5i16
	inline Vector5i16::Vector5i16(const std::int16_t& a, const std::int16_t& b, const std::int16_t& c, const std::int16_t& d,
		const std::int16_t& e) noexcept
		: a(a), b(b), c(c), d(d), e(e) {}

	// copy/move constructor and assignment
	inline Vector5i16::Vector5i16(const Vector5i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5i16& Vector5i16::operator=(const Vector5i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}

	inline Vector5i16::Vector5i16(Vector5i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5i16& Vector5i16::operator=(Vector5i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}
	// .....................................
	inline Vector5i16& Vector5i16::operator=(const std::int16_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; return *this;
	}


	inline Vector5i16 Vector5i16::operator +(const Vector5i16& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e) };
	}

	inline Vector5i16 Vector5i16::operator -(const Vector5i16& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e) };
	}

	inline Vector5i16 Vector5i16::operator *(const Vector5i16& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e) };
	}

	inline Vector5i16 Vector5i16::operator /(const Vector5i16& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e) };
	}


	inline Vector5i16 Vector5i16::operator +(const std::int16_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number) };
	}

	inline Vector5i16 Vector5i16::operator -(const std::int16_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number) };
	}

	inline Vector5i16 Vector5i16::operator *(const std::int16_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number) };
	}

	inline Vector5i16 Vector5i16::operator /(const std::int16_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number) };
	}


	// increment / decrement
	inline Vector5i16& Vector5i16::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e;
		return *this;
	}

	inline Vector5i16& Vector5i16::operator-- () noexcept {
		--a; --b; --c; --d; --e;
		return *this;
	}

	inline Vector5i16 Vector5i16::operator++ (int) noexcept {
		Vector5i16 temp = *this;
		++* this;
		return temp;
	}

	inline Vector5i16 Vector5i16::operator-- (int) noexcept {
		Vector5i16 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector5i16& Vector5i16::operator+= (const Vector5i16& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e);
		return *this;
	}

	inline Vector5i16& Vector5i16::operator-= (const Vector5i16& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e);
		return *this;
	}

	inline Vector5i16& Vector5i16::operator*= (const Vector5i16& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e);
		return *this;
	}

	inline Vector5i16& Vector5i16::operator/= (const Vector5i16& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e);
		return *this;
	}


	inline Vector5i16& Vector5i16::operator+= (const std::int16_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number);
		return *this;
	}

	inline Vector5i16& Vector5i16::operator-= (const std::int16_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number);
		return *this;
	}

	inline Vector5i16& Vector5i16::operator*= (const std::int16_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number);
		return *this;
	}

	inline Vector5i16& Vector5i16::operator/= (const std::int16_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector5i16::operator< (const Vector5i16& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e;
	}

	inline bool Vector5i16::operator<= (const Vector5i16& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e;
	}

	inline bool Vector5i16::operator>  (const Vector5i16& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e;
	}

	inline bool Vector5i16::operator>= (const Vector5i16& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e;
	}


	inline bool Vector5i16::operator<  (const std::int16_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number;
	}

	inline bool Vector5i16::operator<= (const std::int16_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number;
	}

	inline bool Vector5i16::operator>  (const std::int16_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number;
	}

	inline bool Vector5i16::operator>= (const std::int16_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number;
	}


	// equal / not equal
	inline bool Vector5i16::operator==(const Vector5i16& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
	}

	inline bool Vector5i16::operator!=(const Vector5i16& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e;
	}

	inline bool Vector5i16::operator==(const std::int16_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number;
	}

	inline bool Vector5i16::operator!=(const std::int16_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number;
	}


	inline constexpr std::uint8_t Vector5i16::size() const noexcept { return 5; }
	inline void Vector5i16::reset(const std::int16_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int16_t& Vector5i16::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int16_t& Vector5i16::at(const std::uint8_t& index) noexcept
	{
		std::int16_t* ptr = &a;
		if (index > 4)
			return ptr[0];
		return ptr[index];
	}



	// Vector6i16
	inline Vector6i16::Vector6i16(const std::int16_t& a, const std::int16_t& b, const std::int16_t& c, const std::int16_t& d,
		const std::int16_t& e, const std::int16_t& f) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f) {}

	// copy/move constructor and assignment
	inline Vector6i16::Vector6i16(const Vector6i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6i16& Vector6i16::operator=(const Vector6i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}

	inline Vector6i16::Vector6i16(Vector6i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6i16& Vector6i16::operator=(Vector6i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}
	// .....................................
	inline Vector6i16& Vector6i16::operator=(const std::int16_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; return *this;
	}


	inline Vector6i16 Vector6i16::operator +(const Vector6i16& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f) };
	}

	inline Vector6i16 Vector6i16::operator -(const Vector6i16& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f) };
	}

	inline Vector6i16 Vector6i16::operator *(const Vector6i16& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f) };
	}

	inline Vector6i16 Vector6i16::operator /(const Vector6i16& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f) };
	}


	inline Vector6i16 Vector6i16::operator +(const std::int16_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number) };
	}

	inline Vector6i16 Vector6i16::operator -(const std::int16_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number) };
	}

	inline Vector6i16 Vector6i16::operator *(const std::int16_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number) };
	}

	inline Vector6i16 Vector6i16::operator /(const std::int16_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number) };
	}


	// increment / decrement
	inline Vector6i16& Vector6i16::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f;
		return *this;
	}

	inline Vector6i16& Vector6i16::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f;
		return *this;
	}

	inline Vector6i16 Vector6i16::operator++ (int) noexcept {
		Vector6i16 temp = *this;
		++* this;
		return temp;
	}

	inline Vector6i16 Vector6i16::operator-- (int) noexcept {
		Vector6i16 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector6i16& Vector6i16::operator+= (const Vector6i16& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f);
		return *this;
	}

	inline Vector6i16& Vector6i16::operator-= (const Vector6i16& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f);
		return *this;
	}

	inline Vector6i16& Vector6i16::operator*= (const Vector6i16& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f);
		return *this;
	}

	inline Vector6i16& Vector6i16::operator/= (const Vector6i16& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f);
		return *this;
	}


	inline Vector6i16& Vector6i16::operator+= (const std::int16_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number);
		return *this;
	}

	inline Vector6i16& Vector6i16::operator-= (const std::int16_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number);
		return *this;
	}

	inline Vector6i16& Vector6i16::operator*= (const std::int16_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number);
		return *this;
	}

	inline Vector6i16& Vector6i16::operator/= (const std::int16_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector6i16::operator< (const Vector6i16& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f;
	}

	inline bool Vector6i16::operator<= (const Vector6i16& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f;
	}

	inline bool Vector6i16::operator>  (const Vector6i16& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f;
	}

	inline bool Vector6i16::operator>= (const Vector6i16& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f;
	}


	inline bool Vector6i16::operator<  (const std::int16_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number;
	}

	inline bool Vector6i16::operator<= (const std::int16_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number;
	}

	inline bool Vector6i16::operator>  (const std::int16_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number;
	}

	inline bool Vector6i16::operator>= (const std::int16_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number;
	}


	// equal / not equal
	inline bool Vector6i16::operator==(const Vector6i16& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f;
	}

	inline bool Vector6i16::operator!=(const Vector6i16& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f;
	}

	inline bool Vector6i16::operator==(const std::int16_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number;
	}

	inline bool Vector6i16::operator!=(const std::int16_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number;
	}


	inline constexpr std::uint8_t Vector6i16::size() const noexcept { return 6; }
	inline void Vector6i16::reset(const std::int16_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int16_t& Vector6i16::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int16_t& Vector6i16::at(const std::uint8_t& index) noexcept
	{
		std::int16_t* ptr = &a;
		if (index > 5)
			return ptr[0];
		return ptr[index];
	}



	// Vector7i16
	inline Vector7i16::Vector7i16(const std::int16_t& a, const std::int16_t& b, const std::int16_t& c, const std::int16_t& d,
		const std::int16_t& e, const std::int16_t& f, const std::int16_t& g) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g) {}

	// copy/move constructor and assignment
	inline Vector7i16::Vector7i16(const Vector7i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7i16& Vector7i16::operator=(const Vector7i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}

	inline Vector7i16::Vector7i16(Vector7i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7i16& Vector7i16::operator=(Vector7i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}
	// .....................................
	inline Vector7i16& Vector7i16::operator=(const std::int16_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; return *this;
	}


	inline Vector7i16 Vector7i16::operator +(const Vector7i16& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g) };
	}

	inline Vector7i16 Vector7i16::operator -(const Vector7i16& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g) };
	}

	inline Vector7i16 Vector7i16::operator *(const Vector7i16& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g) };
	}

	inline Vector7i16 Vector7i16::operator /(const Vector7i16& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g) };
	}


	inline Vector7i16 Vector7i16::operator +(const std::int16_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number) };
	}

	inline Vector7i16 Vector7i16::operator -(const std::int16_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number) };
	}

	inline Vector7i16 Vector7i16::operator *(const std::int16_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number) };
	}

	inline Vector7i16 Vector7i16::operator /(const std::int16_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number) };
	}


	// increment / decrement
	inline Vector7i16& Vector7i16::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g;
		return *this;
	}

	inline Vector7i16& Vector7i16::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g;
		return *this;
	}

	inline Vector7i16 Vector7i16::operator++ (int) noexcept {
		Vector7i16 temp = *this;
		++* this;
		return temp;
	}

	inline Vector7i16 Vector7i16::operator-- (int) noexcept {
		Vector7i16 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector7i16& Vector7i16::operator+= (const Vector7i16& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g);
		return *this;
	}

	inline Vector7i16& Vector7i16::operator-= (const Vector7i16& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g);
		return *this;
	}

	inline Vector7i16& Vector7i16::operator*= (const Vector7i16& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g);
		return *this;
	}

	inline Vector7i16& Vector7i16::operator/= (const Vector7i16& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g);
		return *this;
	}


	inline Vector7i16& Vector7i16::operator+= (const std::int16_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number);
		return *this;
	}

	inline Vector7i16& Vector7i16::operator-= (const std::int16_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number);
		return *this;
	}

	inline Vector7i16& Vector7i16::operator*= (const std::int16_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number);
		return *this;
	}

	inline Vector7i16& Vector7i16::operator/= (const std::int16_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector7i16::operator< (const Vector7i16& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g;
	}

	inline bool Vector7i16::operator<= (const Vector7i16& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g;
	}

	inline bool Vector7i16::operator>  (const Vector7i16& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g;
	}

	inline bool Vector7i16::operator>= (const Vector7i16& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g;
	}


	inline bool Vector7i16::operator<  (const std::int16_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number;
	}

	inline bool Vector7i16::operator<= (const std::int16_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number;
	}

	inline bool Vector7i16::operator>  (const std::int16_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number;
	}

	inline bool Vector7i16::operator>= (const std::int16_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number;
	}


	// equal / not equal
	inline bool Vector7i16::operator==(const Vector7i16& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g;
	}

	inline bool Vector7i16::operator!=(const Vector7i16& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g;
	}

	inline bool Vector7i16::operator==(const std::int16_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number;
	}

	inline bool Vector7i16::operator!=(const std::int16_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number;
	}


	inline constexpr std::uint8_t Vector7i16::size() const noexcept { return 7; }
	inline void Vector7i16::reset(const std::int16_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int16_t& Vector7i16::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int16_t& Vector7i16::at(const std::uint8_t& index) noexcept
	{
		std::int16_t* ptr = &a;
		if (index > 6)
			return ptr[0];
		return ptr[index];
	}



	// Vector8i16
	inline Vector8i16::Vector8i16(const std::int16_t& a, const std::int16_t& b, const std::int16_t& c, const std::int16_t& d,
		const std::int16_t& e, const std::int16_t& f, const std::int16_t& g, const std::int16_t& h) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h) {}

	// copy/move constructor and assignment
	inline Vector8i16::Vector8i16(const Vector8i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8i16& Vector8i16::operator=(const Vector8i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}

	inline Vector8i16::Vector8i16(Vector8i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8i16& Vector8i16::operator=(Vector8i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}
	// .....................................
	inline Vector8i16& Vector8i16::operator=(const std::int16_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; return *this;
	}


	inline Vector8i16 Vector8i16::operator +(const Vector8i16& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h) };
	}

	inline Vector8i16 Vector8i16::operator -(const Vector8i16& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h) };
	}

	inline Vector8i16 Vector8i16::operator *(const Vector8i16& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h) };
	}

	inline Vector8i16 Vector8i16::operator /(const Vector8i16& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g), cast(h / v.h) };
	}


	inline Vector8i16 Vector8i16::operator +(const std::int16_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number) };
	}

	inline Vector8i16 Vector8i16::operator -(const std::int16_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number) };
	}

	inline Vector8i16 Vector8i16::operator *(const std::int16_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number) };
	}

	inline Vector8i16 Vector8i16::operator /(const std::int16_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number), cast(h / number) };
	}


	// increment / decrement
	inline Vector8i16& Vector8i16::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h;
		return *this;
	}

	inline Vector8i16& Vector8i16::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h;
		return *this;
	}

	inline Vector8i16 Vector8i16::operator++ (int) noexcept {
		Vector8i16 temp = *this;
		++* this;
		return temp;
	}

	inline Vector8i16 Vector8i16::operator-- (int) noexcept {
		Vector8i16 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector8i16& Vector8i16::operator+= (const Vector8i16& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g); cast(h += right.h);
		return *this;
	}

	inline Vector8i16& Vector8i16::operator-= (const Vector8i16& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g); cast(h -= right.h);
		return *this;
	}

	inline Vector8i16& Vector8i16::operator*= (const Vector8i16& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g); cast(h *= right.h);
		return *this;
	}

	inline Vector8i16& Vector8i16::operator/= (const Vector8i16& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g); cast(h /= right.h);
		return *this;
	}


	inline Vector8i16& Vector8i16::operator+= (const std::int16_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number); cast(h += number);
		return *this;
	}

	inline Vector8i16& Vector8i16::operator-= (const std::int16_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number); cast(h -= number);
		return *this;
	}

	inline Vector8i16& Vector8i16::operator*= (const std::int16_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number); cast(h *= number);
		return *this;
	}

	inline Vector8i16& Vector8i16::operator/= (const std::int16_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number); cast(h /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector8i16::operator< (const Vector8i16& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h;
	}

	inline bool Vector8i16::operator<= (const Vector8i16& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h;
	}

	inline bool Vector8i16::operator>  (const Vector8i16& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h;
	}

	inline bool Vector8i16::operator>= (const Vector8i16& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h;
	}


	inline bool Vector8i16::operator<  (const std::int16_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number;
	}

	inline bool Vector8i16::operator<= (const std::int16_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number;
	}

	inline bool Vector8i16::operator>  (const std::int16_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number;
	}

	inline bool Vector8i16::operator>= (const std::int16_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number;
	}


	// equal / not equal
	inline bool Vector8i16::operator==(const Vector8i16& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h;
	}

	inline bool Vector8i16::operator!=(const Vector8i16& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h;
	}

	inline bool Vector8i16::operator==(const std::int16_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number;
	}

	inline bool Vector8i16::operator!=(const std::int16_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number;
	}


	inline constexpr std::uint8_t Vector8i16::size() const noexcept { return 8; }
	inline void Vector8i16::reset(const std::int16_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int16_t& Vector8i16::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int16_t& Vector8i16::at(const std::uint8_t& index) noexcept
	{
		std::int16_t* ptr = &a;
		if (index > 7)
			return ptr[0];
		return ptr[index];
	}



	// Vector9i16
	inline Vector9i16::Vector9i16(const std::int16_t& a, const std::int16_t& b, const std::int16_t& c, const std::int16_t& d,
		const std::int16_t& e, const std::int16_t& f, const std::int16_t& g, const std::int16_t& h,
		const std::int16_t& i) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

	// copy/move constructor and assignment
	inline Vector9i16::Vector9i16(const Vector9i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9i16& Vector9i16::operator=(const Vector9i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}

	inline Vector9i16::Vector9i16(Vector9i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9i16& Vector9i16::operator=(Vector9i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}
	// .....................................
	inline Vector9i16& Vector9i16::operator=(const std::int16_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; return *this;
	}


	inline Vector9i16 Vector9i16::operator +(const Vector9i16& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h), cast(i + v.i) };
	}

	inline Vector9i16 Vector9i16::operator -(const Vector9i16& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h), cast(i - v.i) };
	}

	inline Vector9i16 Vector9i16::operator *(const Vector9i16& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h), cast(i * v.i) };
	}

	inline Vector9i16 Vector9i16::operator /(const Vector9i16& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g), cast(h / v.h), cast(i / v.i) };
	}


	inline Vector9i16 Vector9i16::operator +(const std::int16_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number), cast(i + number) };
	}

	inline Vector9i16 Vector9i16::operator -(const std::int16_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number), cast(i - number) };
	}

	inline Vector9i16 Vector9i16::operator *(const std::int16_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number), cast(i * number) };
	}

	inline Vector9i16 Vector9i16::operator /(const std::int16_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number), cast(h / number), cast(i / number) };
	}


	// increment / decrement
	inline Vector9i16& Vector9i16::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i;
		return *this;
	}

	inline Vector9i16& Vector9i16::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i;
		return *this;
	}

	inline Vector9i16 Vector9i16::operator++ (int) noexcept {
		Vector9i16 temp = *this;
		++* this;
		return temp;
	}

	inline Vector9i16 Vector9i16::operator-- (int) noexcept {
		Vector9i16 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector9i16& Vector9i16::operator+= (const Vector9i16& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g); cast(h += right.h); cast(i += right.i);
		return *this;
	}

	inline Vector9i16& Vector9i16::operator-= (const Vector9i16& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g); cast(h -= right.h); cast(i -= right.i);
		return *this;
	}

	inline Vector9i16& Vector9i16::operator*= (const Vector9i16& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g); cast(h *= right.h); cast(i *= right.i);
		return *this;
	}

	inline Vector9i16& Vector9i16::operator/= (const Vector9i16& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g); cast(h /= right.h); cast(i /= right.i);
		return *this;
	}


	inline Vector9i16& Vector9i16::operator+= (const std::int16_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number); cast(h += number); cast(i += number);
		return *this;
	}

	inline Vector9i16& Vector9i16::operator-= (const std::int16_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number); cast(h -= number); cast(i -= number);
		return *this;
	}

	inline Vector9i16& Vector9i16::operator*= (const std::int16_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number); cast(h *= number); cast(i *= number);
		return *this;
	}

	inline Vector9i16& Vector9i16::operator/= (const std::int16_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number); cast(h /= number); cast(i /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector9i16::operator< (const Vector9i16& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i;
	}

	inline bool Vector9i16::operator<= (const Vector9i16& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i;
	}

	inline bool Vector9i16::operator>  (const Vector9i16& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i;
	}

	inline bool Vector9i16::operator>= (const Vector9i16& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i;
	}


	inline bool Vector9i16::operator<  (const std::int16_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number;
	}

	inline bool Vector9i16::operator<= (const std::int16_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number;
	}

	inline bool Vector9i16::operator>  (const std::int16_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number;
	}

	inline bool Vector9i16::operator>= (const std::int16_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number;
	}


	// equal / not equal
	inline bool Vector9i16::operator==(const Vector9i16& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i;
	}

	inline bool Vector9i16::operator!=(const Vector9i16& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i;
	}

	inline bool Vector9i16::operator==(const std::int16_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number;
	}

	inline bool Vector9i16::operator!=(const std::int16_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number;
	}


	inline constexpr std::uint8_t Vector9i16::size() const noexcept { return 9; }
	inline void Vector9i16::reset(const std::int16_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int16_t& Vector9i16::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int16_t& Vector9i16::at(const std::uint8_t& index) noexcept
	{
		std::int16_t* ptr = &a;
		if (index > 8)
			return ptr[0];
		return ptr[index];
	}



	// Vector10i16
	inline Vector10i16::Vector10i16(const std::int16_t& a, const std::int16_t& b, const std::int16_t& c, const std::int16_t& d,
		const std::int16_t& e, const std::int16_t& f, const std::int16_t& g, const std::int16_t& h,
		const std::int16_t& i, const std::int16_t& j) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {}

	// copy/move constructor and assignment
	inline Vector10i16::Vector10i16(const Vector10i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10i16& Vector10i16::operator=(const Vector10i16& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}

	inline Vector10i16::Vector10i16(Vector10i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10i16& Vector10i16::operator=(Vector10i16&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}
	// .....................................
	inline Vector10i16& Vector10i16::operator=(const std::int16_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; j = number; return *this;
	}


	inline Vector10i16 Vector10i16::operator +(const Vector10i16& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h), cast(i + v.i), cast(j + v.j) };
	}

	inline Vector10i16 Vector10i16::operator -(const Vector10i16& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h), cast(i - v.i), cast(j - v.j) };
	}

	inline Vector10i16 Vector10i16::operator *(const Vector10i16& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h), cast(i * v.i), cast(j * v.j) };
	}

	inline Vector10i16 Vector10i16::operator /(const Vector10i16& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g), cast(h / v.h), cast(i / v.i), cast(j / v.j) };
	}


	inline Vector10i16 Vector10i16::operator +(const std::int16_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number), cast(i + number), cast(j + number) };
	}

	inline Vector10i16 Vector10i16::operator -(const std::int16_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number), cast(i - number), cast(j - number) };
	}

	inline Vector10i16 Vector10i16::operator *(const std::int16_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number), cast(i * number), cast(j * number) };
	}

	inline Vector10i16 Vector10i16::operator /(const std::int16_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number), cast(h / number), cast(i / number), cast(j / number) };
	}


	// increment / decrement
	inline Vector10i16& Vector10i16::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i; ++j;
		return *this;
	}

	inline Vector10i16& Vector10i16::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i; --j;
		return *this;
	}

	inline Vector10i16 Vector10i16::operator++ (int) noexcept {
		Vector10i16 temp = *this;
		++* this;
		return temp;
	}

	inline Vector10i16 Vector10i16::operator-- (int) noexcept {
		Vector10i16 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector10i16& Vector10i16::operator+= (const Vector10i16& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g); cast(h += right.h); cast(i += right.i); cast(j += right.j);
		return *this;
	}

	inline Vector10i16& Vector10i16::operator-= (const Vector10i16& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g); cast(h -= right.h); cast(i -= right.i); cast(j -= right.j);
		return *this;
	}

	inline Vector10i16& Vector10i16::operator*= (const Vector10i16& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g); cast(h *= right.h); cast(i *= right.i); cast(j *= right.j);
		return *this;
	}

	inline Vector10i16& Vector10i16::operator/= (const Vector10i16& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g); cast(h /= right.h); cast(i /= right.i); cast(j /= right.j);
		return *this;
	}


	inline Vector10i16& Vector10i16::operator+= (const std::int16_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number); cast(h += number); cast(i += number); cast(j += number);
		return *this;
	}

	inline Vector10i16& Vector10i16::operator-= (const std::int16_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number); cast(h -= number); cast(i -= number); cast(j -= number);
		return *this;
	}

	inline Vector10i16& Vector10i16::operator*= (const std::int16_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number); cast(h *= number); cast(i *= number); cast(j *= number);
		return *this;
	}

	inline Vector10i16& Vector10i16::operator/= (const std::int16_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number); cast(h /= number); cast(i /= number); cast(j /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector10i16::operator< (const Vector10i16& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i&& j < other.j;
	}

	inline bool Vector10i16::operator<= (const Vector10i16& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i && j <= other.j;
	}

	inline bool Vector10i16::operator>  (const Vector10i16& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i && j > other.j;
	}

	inline bool Vector10i16::operator>= (const Vector10i16& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i && j >= other.j;
	}


	inline bool Vector10i16::operator<  (const std::int16_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number && j < number;
	}

	inline bool Vector10i16::operator<= (const std::int16_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number && j <= number;
	}

	inline bool Vector10i16::operator>  (const std::int16_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number && j > number;
	}

	inline bool Vector10i16::operator>= (const std::int16_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number && j >= number;
	}


	// equal / not equal
	inline bool Vector10i16::operator==(const Vector10i16& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i && j == other.j;
	}

	inline bool Vector10i16::operator!=(const Vector10i16& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i || j != other.j;
	}

	inline bool Vector10i16::operator==(const std::int16_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number && j == number;
	}

	inline bool Vector10i16::operator!=(const std::int16_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number || j != number;
	}


	inline constexpr std::uint8_t Vector10i16::size() const noexcept { return 10; }
	inline void Vector10i16::reset(const std::int16_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::int16_t& Vector10i16::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::int16_t& Vector10i16::at(const std::uint8_t& index) noexcept
	{
		std::int16_t* ptr = &a;
		if (index > 9)
			return ptr[0];
		return ptr[index];
	}
	// End
}