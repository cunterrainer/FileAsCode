#include "VectorUi8.h"

#define cast(x) static_cast<std::uint8_t>(x)

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::uint8_t
		Bytes: 1
		Range: 0 to 255
	*/

	// Vector2ui8
	inline Vector2ui8::Vector2ui8(const std::uint8_t& x, const std::uint8_t& y) noexcept
		: x(x), y(y) {}

	// copy/move constructor and assignment
	inline Vector2ui8::Vector2ui8(const Vector2ui8& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2ui8& Vector2ui8::operator=(const Vector2ui8& other) noexcept {
		x = other.x; y = other.y; return *this;
	}

	inline Vector2ui8::Vector2ui8(Vector2ui8&& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2ui8& Vector2ui8::operator=(Vector2ui8&& other) noexcept {
		x = other.x; y = other.y; return *this;
	}
	// .....................................
	inline Vector2ui8& Vector2ui8::operator=(const std::uint8_t& number) noexcept {
		x = number; y = number; return *this;
	}


	inline Vector2ui8 Vector2ui8::operator +(const Vector2ui8& v) const noexcept {
		return { cast(x + v.x), cast(y + v.y) };
	}

	inline Vector2ui8 Vector2ui8::operator -(const Vector2ui8& v) const noexcept {
		return { cast(x - v.x), cast(y - v.y) };
	}

	inline Vector2ui8 Vector2ui8::operator *(const Vector2ui8& v) const noexcept {
		return { cast(x * v.x), cast(y * v.y) };
	}

	inline Vector2ui8 Vector2ui8::operator /(const Vector2ui8& v) const noexcept {
		return { cast(x / v.x), cast(y / v.y) };
	}


	inline Vector2ui8 Vector2ui8::operator +(const std::uint8_t& number) const noexcept {
		return { cast(x + number), cast(y + number) };
	}

	inline Vector2ui8 Vector2ui8::operator -(const std::uint8_t& number) const noexcept {
		return { cast(x - number), cast(y - number) };
	}

	inline Vector2ui8 Vector2ui8::operator *(const std::uint8_t& number) const noexcept {
		return { cast(x * number), cast(y * number) };
	}

	inline Vector2ui8 Vector2ui8::operator /(const std::uint8_t& number) const noexcept {
		return { cast(x / number), cast(y / number) };
	}


	// increment / decrement
	inline Vector2ui8& Vector2ui8::operator++ () noexcept {
		++x; ++y;
		return *this;
	}

	inline Vector2ui8& Vector2ui8::operator-- ()  noexcept {
		--x; --y;
		return *this;
	}

	inline Vector2ui8 Vector2ui8::operator++ (int) noexcept {
		Vector2ui8 temp = *this;
		++* this;
		return temp;
	}

	inline Vector2ui8 Vector2ui8::operator-- (int) noexcept {
		Vector2ui8 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector2ui8& Vector2ui8::operator+= (const Vector2ui8& right) noexcept {
		cast(x += right.x); cast(y += right.y);
		return *this;
	}

	inline Vector2ui8& Vector2ui8::operator-= (const Vector2ui8& right) noexcept {
		cast(x -= right.x); cast(y -= right.y);
		return *this;
	}

	inline Vector2ui8& Vector2ui8::operator*= (const Vector2ui8& right) noexcept {
		cast(x *= right.x); cast(y *= right.y);
		return *this;
	}

	inline Vector2ui8& Vector2ui8::operator/= (const Vector2ui8& right) noexcept {
		cast(x /= right.x); cast(y /= right.y);
		return *this;
	}


	inline Vector2ui8& Vector2ui8::operator+= (const std::uint8_t& number) noexcept {
		cast(x += number); cast(y += number);
		return *this;
	}

	inline Vector2ui8& Vector2ui8::operator-= (const std::uint8_t& number) noexcept {
		cast(x -= number); cast(y -= number);
		return *this;
	}

	inline Vector2ui8& Vector2ui8::operator*= (const std::uint8_t& number) noexcept {
		cast(x *= number); cast(y *= number);
		return *this;
	}

	inline Vector2ui8& Vector2ui8::operator/= (const std::uint8_t& number) noexcept {
		cast(x /= number); cast(y /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector2ui8::operator< (const Vector2ui8& other) const noexcept {
		return x < other.x && y < other.y;
	}

	inline bool Vector2ui8::operator<= (const Vector2ui8& other) const noexcept {
		return x <= other.x && y <= other.y;
	}

	inline bool Vector2ui8::operator>  (const Vector2ui8& other) const noexcept {
		return x > other.x && y > other.y;
	}

	inline bool Vector2ui8::operator>= (const Vector2ui8& other) const noexcept {
		return x >= other.x && y >= other.y;
	}


	inline bool Vector2ui8::operator<  (const std::uint8_t& number) const noexcept {
		return x < number && y < number;
	}

	inline bool Vector2ui8::operator<= (const std::uint8_t& number) const noexcept {
		return x <= number && y <= number;
	}

	inline bool Vector2ui8::operator>  (const std::uint8_t& number) const noexcept {
		return x > number && y > number;
	}

	inline bool Vector2ui8::operator>= (const std::uint8_t& number) const noexcept {
		return x >= number && y >= number;
	}


	// equal / not equal
	inline bool Vector2ui8::operator==(const Vector2ui8& other) const noexcept {
		return x == other.x && y == other.y;
	}

	inline bool Vector2ui8::operator!=(const Vector2ui8& other) const noexcept {
		return x != other.x || y != other.y;
	}

	inline bool Vector2ui8::operator==(const std::uint8_t& number) const noexcept {
		return x == number && y == number;
	}

	inline bool Vector2ui8::operator!=(const std::uint8_t& number) const noexcept {
		return x != number || y != number;
	}


	inline constexpr std::uint8_t Vector2ui8::size() const noexcept { return 2; }
	inline void Vector2ui8::reset(const std::uint8_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint8_t& Vector2ui8::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint8_t& Vector2ui8::at(const std::uint8_t& index) noexcept
	{
		std::uint8_t* ptr = &x;
		if (index > 1)
			return ptr[0];
		return ptr[index];
	}



	// Vector3ui8
	inline Vector3ui8::Vector3ui8(const std::uint8_t& x, const std::uint8_t& y, const std::uint8_t& z) noexcept
		: x(x), y(y), z(z) {}

	// copy/move constructor and assignment
	inline Vector3ui8::Vector3ui8(const Vector3ui8& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3ui8& Vector3ui8::operator=(const Vector3ui8& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}

	inline Vector3ui8::Vector3ui8(Vector3ui8&& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3ui8& Vector3ui8::operator=(Vector3ui8&& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}
	// .....................................
	inline Vector3ui8& Vector3ui8::operator=(const std::uint8_t& number) noexcept {
		x = number; y = number; z = number; return *this;
	}


	inline Vector3ui8 Vector3ui8::operator +(const Vector3ui8& v) const noexcept {
		return { cast(x + v.x), cast(y + v.y), cast(z + v.z) };
	}

	inline Vector3ui8 Vector3ui8::operator -(const Vector3ui8& v) const noexcept {
		return { cast(x - v.x), cast(y - v.y), cast(z - v.z) };
	}

	inline Vector3ui8 Vector3ui8::operator *(const Vector3ui8& v) const noexcept {
		return { cast(x * v.x), cast(y * v.y), cast(z * v.z) };
	}

	inline Vector3ui8 Vector3ui8::operator /(const Vector3ui8& v) const noexcept {
		return { cast(x / v.x), cast(y / v.y), cast(z / v.z) };
	}

 
	inline Vector3ui8 Vector3ui8::operator +(const std::uint8_t& number) const noexcept {
		return { cast(x + number), cast(y + number), cast(z + number) };
	}

	inline Vector3ui8 Vector3ui8::operator -(const std::uint8_t& number) const noexcept {
		return { cast(x - number), cast(y - number), cast(z - number) };
	}

	inline Vector3ui8 Vector3ui8::operator *(const std::uint8_t& number) const noexcept {
		return { cast(x * number), cast(y * number), cast(z * number) };
	}

	inline Vector3ui8 Vector3ui8::operator /(const std::uint8_t& number) const noexcept {
		return { cast(x / number), cast(y / number), cast(z / number) };
	}


	// increment / decrement
	inline Vector3ui8& Vector3ui8::operator++ () noexcept {
		++x; ++y; ++z;
		return *this;
	}

	inline Vector3ui8& Vector3ui8::operator-- () noexcept {
		--x; --y; --z;
		return *this;
	}

	inline Vector3ui8 Vector3ui8::operator++ (int) noexcept {
		Vector3ui8 temp = *this;
		++* this;
		return temp;
	}

	inline Vector3ui8 Vector3ui8::operator-- (int) noexcept {
		Vector3ui8 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector3ui8& Vector3ui8::operator+= (const Vector3ui8& right) noexcept {
		cast(x += right.x); cast(y += right.y); cast(z += right.z);
		return *this;
	}

	inline Vector3ui8& Vector3ui8::operator-= (const Vector3ui8& right) noexcept {
		cast(x -= right.x); cast(y -= right.y); cast(z -= right.z);
		return *this;
	}

	inline Vector3ui8& Vector3ui8::operator*= (const Vector3ui8& right) noexcept {
		cast(x *= right.x); cast(y *= right.y); cast(z *= right.z);
		return *this;
	}

	inline Vector3ui8& Vector3ui8::operator/= (const Vector3ui8& right) noexcept {
		cast(x /= right.x); cast(y /= right.y); cast(z /= right.z);
		return *this;
	}


	inline Vector3ui8& Vector3ui8::operator+= (const std::uint8_t& number) noexcept {
		cast(x += number); cast(y += number); cast(z += number);
		return *this;
	}

	inline Vector3ui8& Vector3ui8::operator-= (const std::uint8_t& number) noexcept {
		cast(x -= number); cast(y -= number); cast(z -= number);
		return *this;
	}

	inline Vector3ui8& Vector3ui8::operator*= (const std::uint8_t& number) noexcept {
		cast(x *= number); cast(y *= number); cast(z *= number);
		return *this;
	}

	inline Vector3ui8& Vector3ui8::operator/= (const std::uint8_t& number) noexcept {
		cast(x /= number); cast(y /= number); cast(z /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector3ui8::operator< (const Vector3ui8& other) const noexcept {
		return x < other.x && y < other.y&& z < other.z;
	}

	inline bool Vector3ui8::operator<= (const Vector3ui8& other) const noexcept {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	inline bool Vector3ui8::operator>  (const Vector3ui8& other) const noexcept {
		return x > other.x && y > other.y && z > other.z;
	}

	inline bool Vector3ui8::operator>= (const Vector3ui8& other) const noexcept {
		return x >= other.x && y >= other.y && z >= other.z;
	}


	inline bool Vector3ui8::operator<  (const std::uint8_t& number) const noexcept {
		return x < number && y < number && z < number;
	}

	inline bool Vector3ui8::operator<= (const std::uint8_t& number) const noexcept {
		return x <= number && y <= number && z <= number;
	}

	inline bool Vector3ui8::operator>  (const std::uint8_t& number) const noexcept {
		return x > number && y > number && z > number;
	}

	inline bool Vector3ui8::operator>= (const std::uint8_t& number) const noexcept {
		return x >= number && y >= number && z >= number;
	}


	// equal / not equal
	inline bool Vector3ui8::operator==(const Vector3ui8& other) const noexcept {
		return x == other.x && y == other.y && z == other.z;
	}

	inline bool Vector3ui8::operator!=(const Vector3ui8& other) const noexcept {
		return x != other.x || y != other.y || z != other.z;
	}

	inline bool Vector3ui8::operator==(const std::uint8_t& number) const noexcept {
		return x == number && y == number && z == number;
	}

	inline bool Vector3ui8::operator!=(const std::uint8_t& number) const noexcept {
		return x != number || y != number || z != number;
	}


	inline constexpr std::uint8_t Vector3ui8::size() const noexcept { return 3; }
	inline void Vector3ui8::reset(const std::uint8_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint8_t& Vector3ui8::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint8_t& Vector3ui8::at(const std::uint8_t& index) noexcept
	{
		std::uint8_t* ptr = &x;
		if (index > 2)
			return ptr[0];
		return ptr[index];
	}



	// Vector4ui8
	inline Vector4ui8::Vector4ui8(const std::uint8_t& a, const std::uint8_t& b, const std::uint8_t& c, const std::uint8_t& d) noexcept
		: a(a), b(b), c(c), d(d) {}

	// copy/move constructor and assignment
	inline Vector4ui8::Vector4ui8(const Vector4ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4ui8& Vector4ui8::operator=(const Vector4ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}

	inline Vector4ui8::Vector4ui8(Vector4ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4ui8& Vector4ui8::operator=(Vector4ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}
	// .....................................
	inline Vector4ui8& Vector4ui8::operator=(const std::uint8_t& number) noexcept {
		a = number; b = number; c = number; d = number; return *this;
	}


	inline Vector4ui8 Vector4ui8::operator +(const Vector4ui8& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d) };
	}

	inline Vector4ui8 Vector4ui8::operator -(const Vector4ui8& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d) };
	}

	inline Vector4ui8 Vector4ui8::operator *(const Vector4ui8& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d) };
	}

	inline Vector4ui8 Vector4ui8::operator /(const Vector4ui8& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d) };
	}


	inline Vector4ui8 Vector4ui8::operator +(const std::uint8_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number) };
	}

	inline Vector4ui8 Vector4ui8::operator -(const std::uint8_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number) };
	}

	inline Vector4ui8 Vector4ui8::operator *(const std::uint8_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number) };
	}

	inline Vector4ui8 Vector4ui8::operator /(const std::uint8_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number) };
	}


	// increment / decrement
	inline Vector4ui8& Vector4ui8::operator++ () noexcept {
		++a; ++b; ++c; ++d;
		return *this;
	}

	inline Vector4ui8& Vector4ui8::operator-- () noexcept {
		--a; --b; --c; --d;
		return *this;
	}

	inline Vector4ui8 Vector4ui8::operator++ (int) noexcept {
		Vector4ui8 temp = *this;
		++* this;
		return temp;
	}

	inline Vector4ui8 Vector4ui8::operator-- (int) noexcept {
		Vector4ui8 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector4ui8& Vector4ui8::operator+= (const Vector4ui8& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d);
		return *this;
	}

	inline Vector4ui8& Vector4ui8::operator-= (const Vector4ui8& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d);
		return *this;
	}

	inline Vector4ui8& Vector4ui8::operator*= (const Vector4ui8& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d);
		return *this;
	}

	inline Vector4ui8& Vector4ui8::operator/= (const Vector4ui8& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d);
		return *this;
	}


	inline Vector4ui8& Vector4ui8::operator+= (const std::uint8_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number);
		return *this;
	}

	inline Vector4ui8& Vector4ui8::operator-= (const std::uint8_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number);
		return *this;
	}

	inline Vector4ui8& Vector4ui8::operator*= (const std::uint8_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number);
		return *this;
	}

	inline Vector4ui8& Vector4ui8::operator/= (const std::uint8_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector4ui8::operator< (const Vector4ui8& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d;
	}

	inline bool Vector4ui8::operator<= (const Vector4ui8& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d;
	}

	inline bool Vector4ui8::operator>  (const Vector4ui8& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d;
	}

	inline bool Vector4ui8::operator>= (const Vector4ui8& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d;
	}


	inline bool Vector4ui8::operator<  (const std::uint8_t& number) const noexcept {
		return a < number && b < number && c < number && d < number;
	}

	inline bool Vector4ui8::operator<= (const std::uint8_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number;
	}

	inline bool Vector4ui8::operator>  (const std::uint8_t& number) const noexcept {
		return a > number && b > number && c > number && d > number;
	}

	inline bool Vector4ui8::operator>= (const std::uint8_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number;
	}


	// equal / not equal
	inline bool Vector4ui8::operator==(const Vector4ui8& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d;
	}

	inline bool Vector4ui8::operator!=(const Vector4ui8& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d;
	}

	inline bool Vector4ui8::operator==(const std::uint8_t& number) const noexcept {
		return a == number && b == number && c == number && d == number;
	}

	inline bool Vector4ui8::operator!=(const std::uint8_t& number) const noexcept {
		return a != number || b != number || c != number || d != number;
	}


	inline constexpr std::uint8_t Vector4ui8::size() const noexcept { return 4; }
	inline void Vector4ui8::reset(const std::uint8_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint8_t& Vector4ui8::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint8_t& Vector4ui8::at(const std::uint8_t& index) noexcept
	{
		std::uint8_t* ptr = &a;
		if (index > 3)
			return ptr[0];
		return ptr[index];
	}



	// Vector5ui8
	inline Vector5ui8::Vector5ui8(const std::uint8_t& a, const std::uint8_t& b, const std::uint8_t& c, const std::uint8_t& d,
		const std::uint8_t& e) noexcept
		: a(a), b(b), c(c), d(d), e(e) {}

	// copy/move constructor and assignment
	inline Vector5ui8::Vector5ui8(const Vector5ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5ui8& Vector5ui8::operator=(const Vector5ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}

	inline Vector5ui8::Vector5ui8(Vector5ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5ui8& Vector5ui8::operator=(Vector5ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}
	// .....................................
	inline Vector5ui8& Vector5ui8::operator=(const std::uint8_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; return *this;
	}


	inline Vector5ui8 Vector5ui8::operator +(const Vector5ui8& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e) };
	}

	inline Vector5ui8 Vector5ui8::operator -(const Vector5ui8& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e) };
	}

	inline Vector5ui8 Vector5ui8::operator *(const Vector5ui8& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e) };
	}

	inline Vector5ui8 Vector5ui8::operator /(const Vector5ui8& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e) };
	}


	inline Vector5ui8 Vector5ui8::operator +(const std::uint8_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number) };
	}

	inline Vector5ui8 Vector5ui8::operator -(const std::uint8_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number) };
	}

	inline Vector5ui8 Vector5ui8::operator *(const std::uint8_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number) };
	}

	inline Vector5ui8 Vector5ui8::operator /(const std::uint8_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number) };
	}


	// increment / decrement
	inline Vector5ui8& Vector5ui8::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e;
		return *this;
	}

	inline Vector5ui8& Vector5ui8::operator-- () noexcept {
		--a; --b; --c; --d; --e;
		return *this;
	}

	inline Vector5ui8 Vector5ui8::operator++ (int) noexcept {
		Vector5ui8 temp = *this;
		++* this;
		return temp;
	}

	inline Vector5ui8 Vector5ui8::operator-- (int) noexcept {
		Vector5ui8 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector5ui8& Vector5ui8::operator+= (const Vector5ui8& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e);
		return *this;
	}

	inline Vector5ui8& Vector5ui8::operator-= (const Vector5ui8& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e);
		return *this;
	}

	inline Vector5ui8& Vector5ui8::operator*= (const Vector5ui8& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e);
		return *this;
	}

	inline Vector5ui8& Vector5ui8::operator/= (const Vector5ui8& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e);
		return *this;
	}


	inline Vector5ui8& Vector5ui8::operator+= (const std::uint8_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number);
		return *this;
	}

	inline Vector5ui8& Vector5ui8::operator-= (const std::uint8_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number);
		return *this;
	}

	inline Vector5ui8& Vector5ui8::operator*= (const std::uint8_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number);
		return *this;
	}

	inline Vector5ui8& Vector5ui8::operator/= (const std::uint8_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector5ui8::operator< (const Vector5ui8& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e;
	}

	inline bool Vector5ui8::operator<= (const Vector5ui8& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e;
	}

	inline bool Vector5ui8::operator>  (const Vector5ui8& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e;
	}

	inline bool Vector5ui8::operator>= (const Vector5ui8& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e;
	}


	inline bool Vector5ui8::operator<  (const std::uint8_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number;
	}

	inline bool Vector5ui8::operator<= (const std::uint8_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number;
	}

	inline bool Vector5ui8::operator>  (const std::uint8_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number;
	}

	inline bool Vector5ui8::operator>= (const std::uint8_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number;
	}


	// equal / not equal
	inline bool Vector5ui8::operator==(const Vector5ui8& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
	}

	inline bool Vector5ui8::operator!=(const Vector5ui8& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e;
	}

	inline bool Vector5ui8::operator==(const std::uint8_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number;
	}

	inline bool Vector5ui8::operator!=(const std::uint8_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number;
	}


	inline constexpr std::uint8_t Vector5ui8::size() const noexcept { return 5; }
	inline void Vector5ui8::reset(const std::uint8_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint8_t& Vector5ui8::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint8_t& Vector5ui8::at(const std::uint8_t& index) noexcept
	{
		std::uint8_t* ptr = &a;
		if (index > 4)
			return ptr[0];
		return ptr[index];
	}



	// Vector6ui8
	inline Vector6ui8::Vector6ui8(const std::uint8_t& a, const std::uint8_t& b, const std::uint8_t& c, const std::uint8_t& d,
		const std::uint8_t& e, const std::uint8_t& f) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f) {}

	// copy/move constructor and assignment
	inline Vector6ui8::Vector6ui8(const Vector6ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6ui8& Vector6ui8::operator=(const Vector6ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}

	inline Vector6ui8::Vector6ui8(Vector6ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6ui8& Vector6ui8::operator=(Vector6ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}
	// .....................................
	inline Vector6ui8& Vector6ui8::operator=(const std::uint8_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; return *this;
	}


	inline Vector6ui8 Vector6ui8::operator +(const Vector6ui8& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f) };
	}

	inline Vector6ui8 Vector6ui8::operator -(const Vector6ui8& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f) };
	}

	inline Vector6ui8 Vector6ui8::operator *(const Vector6ui8& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f) };
	}

	inline Vector6ui8 Vector6ui8::operator /(const Vector6ui8& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f) };
	}


	inline Vector6ui8 Vector6ui8::operator +(const std::uint8_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number) };
	}

	inline Vector6ui8 Vector6ui8::operator -(const std::uint8_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number) };
	}

	inline Vector6ui8 Vector6ui8::operator *(const std::uint8_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number) };
	}

	inline Vector6ui8 Vector6ui8::operator /(const std::uint8_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number) };
	}


	// increment / decrement
	inline Vector6ui8& Vector6ui8::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f;
		return *this;
	}

	inline Vector6ui8& Vector6ui8::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f;
		return *this;
	}

	inline Vector6ui8 Vector6ui8::operator++ (int) noexcept {
		Vector6ui8 temp = *this;
		++* this;
		return temp;
	}

	inline Vector6ui8 Vector6ui8::operator-- (int) noexcept {
		Vector6ui8 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector6ui8& Vector6ui8::operator+= (const Vector6ui8& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f);
		return *this;
	}

	inline Vector6ui8& Vector6ui8::operator-= (const Vector6ui8& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f);
		return *this;
	}

	inline Vector6ui8& Vector6ui8::operator*= (const Vector6ui8& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f);
		return *this;
	}

	inline Vector6ui8& Vector6ui8::operator/= (const Vector6ui8& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f);
		return *this;
	}


	inline Vector6ui8& Vector6ui8::operator+= (const std::uint8_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number);
		return *this;
	}

	inline Vector6ui8& Vector6ui8::operator-= (const std::uint8_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number);
		return *this;
	}

	inline Vector6ui8& Vector6ui8::operator*= (const std::uint8_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number);
		return *this;
	}

	inline Vector6ui8& Vector6ui8::operator/= (const std::uint8_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector6ui8::operator< (const Vector6ui8& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f;
	}

	inline bool Vector6ui8::operator<= (const Vector6ui8& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f;
	}

	inline bool Vector6ui8::operator>  (const Vector6ui8& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f;
	}

	inline bool Vector6ui8::operator>= (const Vector6ui8& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f;
	}


	inline bool Vector6ui8::operator<  (const std::uint8_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number;
	}

	inline bool Vector6ui8::operator<= (const std::uint8_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number;
	}

	inline bool Vector6ui8::operator>  (const std::uint8_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number;
	}

	inline bool Vector6ui8::operator>= (const std::uint8_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number;
	}


	// equal / not equal
	inline bool Vector6ui8::operator==(const Vector6ui8& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f;
	}

	inline bool Vector6ui8::operator!=(const Vector6ui8& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f;
	}

	inline bool Vector6ui8::operator==(const std::uint8_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number;
	}

	inline bool Vector6ui8::operator!=(const std::uint8_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number;
	}


	inline constexpr std::uint8_t Vector6ui8::size() const noexcept { return 6; }
	inline void Vector6ui8::reset(const std::uint8_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint8_t& Vector6ui8::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint8_t& Vector6ui8::at(const std::uint8_t& index) noexcept
	{
		std::uint8_t* ptr = &a;
		if (index > 5)
			return ptr[0];
		return ptr[index];
	}



	// Vector7ui8
	inline Vector7ui8::Vector7ui8(const std::uint8_t& a, const std::uint8_t& b, const std::uint8_t& c, const std::uint8_t& d,
		const std::uint8_t& e, const std::uint8_t& f, const std::uint8_t& g) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g) {}

	// copy/move constructor and assignment
	inline Vector7ui8::Vector7ui8(const Vector7ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7ui8& Vector7ui8::operator=(const Vector7ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}

	inline Vector7ui8::Vector7ui8(Vector7ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7ui8& Vector7ui8::operator=(Vector7ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}
	// .....................................
	inline Vector7ui8& Vector7ui8::operator=(const std::uint8_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; return *this;
	}


	inline Vector7ui8 Vector7ui8::operator +(const Vector7ui8& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g) };
	}

	inline Vector7ui8 Vector7ui8::operator -(const Vector7ui8& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g) };
	}

	inline Vector7ui8 Vector7ui8::operator *(const Vector7ui8& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g) };
	}

	inline Vector7ui8 Vector7ui8::operator /(const Vector7ui8& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g) };
	}


	inline Vector7ui8 Vector7ui8::operator +(const std::uint8_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number) };
	}

	inline Vector7ui8 Vector7ui8::operator -(const std::uint8_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number) };
	}

	inline Vector7ui8 Vector7ui8::operator *(const std::uint8_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number) };
	}

	inline Vector7ui8 Vector7ui8::operator /(const std::uint8_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number) };
	}


	// increment / decrement
	inline Vector7ui8& Vector7ui8::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g;
		return *this;
	}

	inline Vector7ui8& Vector7ui8::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g;
		return *this;
	}

	inline Vector7ui8 Vector7ui8::operator++ (int) noexcept {
		Vector7ui8 temp = *this;
		++* this;
		return temp;
	}

	inline Vector7ui8 Vector7ui8::operator-- (int) noexcept {
		Vector7ui8 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector7ui8& Vector7ui8::operator+= (const Vector7ui8& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g);
		return *this;
	}

	inline Vector7ui8& Vector7ui8::operator-= (const Vector7ui8& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g);
		return *this;
	}

	inline Vector7ui8& Vector7ui8::operator*= (const Vector7ui8& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g);
		return *this;
	}

	inline Vector7ui8& Vector7ui8::operator/= (const Vector7ui8& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g);
		return *this;
	}


	inline Vector7ui8& Vector7ui8::operator+= (const std::uint8_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number);
		return *this;
	}

	inline Vector7ui8& Vector7ui8::operator-= (const std::uint8_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number);
		return *this;
	}

	inline Vector7ui8& Vector7ui8::operator*= (const std::uint8_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number);
		return *this;
	}

	inline Vector7ui8& Vector7ui8::operator/= (const std::uint8_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector7ui8::operator< (const Vector7ui8& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g;
	}

	inline bool Vector7ui8::operator<= (const Vector7ui8& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g;
	}

	inline bool Vector7ui8::operator>  (const Vector7ui8& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g;
	}

	inline bool Vector7ui8::operator>= (const Vector7ui8& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g;
	}


	inline bool Vector7ui8::operator<  (const std::uint8_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number;
	}

	inline bool Vector7ui8::operator<= (const std::uint8_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number;
	}

	inline bool Vector7ui8::operator>  (const std::uint8_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number;
	}

	inline bool Vector7ui8::operator>= (const std::uint8_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number;
	}


	// equal / not equal
	inline bool Vector7ui8::operator==(const Vector7ui8& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g;
	}

	inline bool Vector7ui8::operator!=(const Vector7ui8& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g;
	}

	inline bool Vector7ui8::operator==(const std::uint8_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number;
	}

	inline bool Vector7ui8::operator!=(const std::uint8_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number;
	}


	inline constexpr std::uint8_t Vector7ui8::size() const noexcept { return 7; }
	inline void Vector7ui8::reset(const std::uint8_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint8_t& Vector7ui8::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint8_t& Vector7ui8::at(const std::uint8_t& index) noexcept
	{
		std::uint8_t* ptr = &a;
		if (index > 6)
			return ptr[0];
		return ptr[index];
	}



	// Vector8ui8
	inline Vector8ui8::Vector8ui8(const std::uint8_t& a, const std::uint8_t& b, const std::uint8_t& c, const std::uint8_t& d,
		const std::uint8_t& e, const std::uint8_t& f, const std::uint8_t& g, const std::uint8_t& h) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h) {}

	// copy/move constructor and assignment
	inline Vector8ui8::Vector8ui8(const Vector8ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8ui8& Vector8ui8::operator=(const Vector8ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}

	inline Vector8ui8::Vector8ui8(Vector8ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8ui8& Vector8ui8::operator=(Vector8ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}
	// .....................................
	inline Vector8ui8& Vector8ui8::operator=(const std::uint8_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; return *this;
	}


	inline Vector8ui8 Vector8ui8::operator +(const Vector8ui8& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h) };
	}

	inline Vector8ui8 Vector8ui8::operator -(const Vector8ui8& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h) };
	}

	inline Vector8ui8 Vector8ui8::operator *(const Vector8ui8& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h) };
	}

	inline Vector8ui8 Vector8ui8::operator /(const Vector8ui8& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g), cast(h / v.h) };
	}


	inline Vector8ui8 Vector8ui8::operator +(const std::uint8_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number) };
	}

	inline Vector8ui8 Vector8ui8::operator -(const std::uint8_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number) };
	}

	inline Vector8ui8 Vector8ui8::operator *(const std::uint8_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number) };
	}

	inline Vector8ui8 Vector8ui8::operator /(const std::uint8_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number), cast(h / number) };
	}


	// increment / decrement
	inline Vector8ui8& Vector8ui8::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h;
		return *this;
	}

	inline Vector8ui8& Vector8ui8::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h;
		return *this;
	}

	inline Vector8ui8 Vector8ui8::operator++ (int) noexcept {
		Vector8ui8 temp = *this;
		++* this;
		return temp;
	}

	inline Vector8ui8 Vector8ui8::operator-- (int) noexcept {
		Vector8ui8 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector8ui8& Vector8ui8::operator+= (const Vector8ui8& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g); cast(h += right.h);
		return *this;
	}

	inline Vector8ui8& Vector8ui8::operator-= (const Vector8ui8& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g); cast(h -= right.h);
		return *this;
	}

	inline Vector8ui8& Vector8ui8::operator*= (const Vector8ui8& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g); cast(h *= right.h);
		return *this;
	}

	inline Vector8ui8& Vector8ui8::operator/= (const Vector8ui8& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g); cast(h /= right.h);
		return *this;
	}


	inline Vector8ui8& Vector8ui8::operator+= (const std::uint8_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number); cast(h += number);
		return *this;
	}

	inline Vector8ui8& Vector8ui8::operator-= (const std::uint8_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number); cast(h -= number);
		return *this;
	}

	inline Vector8ui8& Vector8ui8::operator*= (const std::uint8_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number); cast(h *= number);
		return *this;
	}

	inline Vector8ui8& Vector8ui8::operator/= (const std::uint8_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number); cast(h /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector8ui8::operator< (const Vector8ui8& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h;
	}

	inline bool Vector8ui8::operator<= (const Vector8ui8& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h;
	}

	inline bool Vector8ui8::operator>  (const Vector8ui8& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h;
	}

	inline bool Vector8ui8::operator>= (const Vector8ui8& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h;
	}


	inline bool Vector8ui8::operator<  (const std::uint8_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number;
	}

	inline bool Vector8ui8::operator<= (const std::uint8_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number;
	}

	inline bool Vector8ui8::operator>  (const std::uint8_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number;
	}

	inline bool Vector8ui8::operator>= (const std::uint8_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number;
	}


	// equal / not equal
	inline bool Vector8ui8::operator==(const Vector8ui8& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h;
	}

	inline bool Vector8ui8::operator!=(const Vector8ui8& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h;
	}

	inline bool Vector8ui8::operator==(const std::uint8_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number;
	}

	inline bool Vector8ui8::operator!=(const std::uint8_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number;
	}


	inline constexpr std::uint8_t Vector8ui8::size() const noexcept { return 8; }
	inline void Vector8ui8::reset(const std::uint8_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint8_t& Vector8ui8::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint8_t& Vector8ui8::at(const std::uint8_t& index) noexcept
	{
		std::uint8_t* ptr = &a;
		if (index > 7)
			return ptr[0];
		return ptr[index];
	}



	// Vector9ui8
	inline Vector9ui8::Vector9ui8(const std::uint8_t& a, const std::uint8_t& b, const std::uint8_t& c, const std::uint8_t& d,
		const std::uint8_t& e, const std::uint8_t& f, const std::uint8_t& g, const std::uint8_t& h,
		const std::uint8_t& i) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

	// copy/move constructor and assignment
	inline Vector9ui8::Vector9ui8(const Vector9ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9ui8& Vector9ui8::operator=(const Vector9ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}

	inline Vector9ui8::Vector9ui8(Vector9ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9ui8& Vector9ui8::operator=(Vector9ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}
	// .....................................
	inline Vector9ui8& Vector9ui8::operator=(const std::uint8_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; return *this;
	}


	inline Vector9ui8 Vector9ui8::operator +(const Vector9ui8& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h), cast(i + v.i) };
	}

	inline Vector9ui8 Vector9ui8::operator -(const Vector9ui8& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h), cast(i - v.i) };
	}

	inline Vector9ui8 Vector9ui8::operator *(const Vector9ui8& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h), cast(i * v.i) };
	}

	inline Vector9ui8 Vector9ui8::operator /(const Vector9ui8& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g), cast(h / v.h), cast(i / v.i) };
	}


	inline Vector9ui8 Vector9ui8::operator +(const std::uint8_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number), cast(i + number) };
	}

	inline Vector9ui8 Vector9ui8::operator -(const std::uint8_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number), cast(i - number) };
	}

	inline Vector9ui8 Vector9ui8::operator *(const std::uint8_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number), cast(i * number) };
	}

	inline Vector9ui8 Vector9ui8::operator /(const std::uint8_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number), cast(h / number), cast(i / number) };
	}


	// increment / decrement
	inline Vector9ui8& Vector9ui8::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i;
		return *this;
	}

	inline Vector9ui8& Vector9ui8::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i;
		return *this;
	}

	inline Vector9ui8 Vector9ui8::operator++ (int) noexcept {
		Vector9ui8 temp = *this;
		++* this;
		return temp;
	}

	inline Vector9ui8 Vector9ui8::operator-- (int) noexcept {
		Vector9ui8 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector9ui8& Vector9ui8::operator+= (const Vector9ui8& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g); cast(h += right.h); cast(i += right.i);
		return *this;
	}

	inline Vector9ui8& Vector9ui8::operator-= (const Vector9ui8& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g); cast(h -= right.h); cast(i -= right.i);
		return *this;
	}

	inline Vector9ui8& Vector9ui8::operator*= (const Vector9ui8& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g); cast(h *= right.h); cast(i *= right.i);
		return *this;
	}

	inline Vector9ui8& Vector9ui8::operator/= (const Vector9ui8& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g); cast(h /= right.h); cast(i /= right.i);
		return *this;
	}


	inline Vector9ui8& Vector9ui8::operator+= (const std::uint8_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number); cast(h += number); cast(i += number);
		return *this;
	}

	inline Vector9ui8& Vector9ui8::operator-= (const std::uint8_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number); cast(h -= number); cast(i -= number);
		return *this;
	}

	inline Vector9ui8& Vector9ui8::operator*= (const std::uint8_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number); cast(h *= number); cast(i *= number);
		return *this;
	}

	inline Vector9ui8& Vector9ui8::operator/= (const std::uint8_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number); cast(h /= number); cast(i /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector9ui8::operator< (const Vector9ui8& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i;
	}

	inline bool Vector9ui8::operator<= (const Vector9ui8& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i;
	}

	inline bool Vector9ui8::operator>  (const Vector9ui8& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i;
	}

	inline bool Vector9ui8::operator>= (const Vector9ui8& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i;
	}


	inline bool Vector9ui8::operator<  (const std::uint8_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number;
	}

	inline bool Vector9ui8::operator<= (const std::uint8_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number;
	}

	inline bool Vector9ui8::operator>  (const std::uint8_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number;
	}

	inline bool Vector9ui8::operator>= (const std::uint8_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number;
	}


	// equal / not equal
	inline bool Vector9ui8::operator==(const Vector9ui8& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i;
	}

	inline bool Vector9ui8::operator!=(const Vector9ui8& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i;
	}

	inline bool Vector9ui8::operator==(const std::uint8_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number;
	}

	inline bool Vector9ui8::operator!=(const std::uint8_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number;
	}


	inline constexpr std::uint8_t Vector9ui8::size() const noexcept { return 9; }
	inline void Vector9ui8::reset(const std::uint8_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint8_t& Vector9ui8::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint8_t& Vector9ui8::at(const std::uint8_t& index) noexcept
	{
		std::uint8_t* ptr = &a;
		if (index > 8)
			return ptr[0];
		return ptr[index];
	}



	// Vector10ui8
	inline Vector10ui8::Vector10ui8(const std::uint8_t& a, const std::uint8_t& b, const std::uint8_t& c, const std::uint8_t& d,
		const std::uint8_t& e, const std::uint8_t& f, const std::uint8_t& g, const std::uint8_t& h,
		const std::uint8_t& i, const std::uint8_t& j) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {}

	// copy/move constructor and assignment
	inline Vector10ui8::Vector10ui8(const Vector10ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10ui8& Vector10ui8::operator=(const Vector10ui8& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}

	inline Vector10ui8::Vector10ui8(Vector10ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10ui8& Vector10ui8::operator=(Vector10ui8&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}
	// .....................................
	inline Vector10ui8& Vector10ui8::operator=(const std::uint8_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; j = number; return *this;
	}


	inline Vector10ui8 Vector10ui8::operator +(const Vector10ui8& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h), cast(i + v.i), cast(j + v.j) };
	}

	inline Vector10ui8 Vector10ui8::operator -(const Vector10ui8& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h), cast(i - v.i), cast(j - v.j) };
	}

	inline Vector10ui8 Vector10ui8::operator *(const Vector10ui8& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h), cast(i * v.i), cast(j * v.j) };
	}

	inline Vector10ui8 Vector10ui8::operator /(const Vector10ui8& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g), cast(h / v.h), cast(i / v.i), cast(j / v.j) };
	}


	inline Vector10ui8 Vector10ui8::operator +(const std::uint8_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number), cast(i + number), cast(j + number) };
	}

	inline Vector10ui8 Vector10ui8::operator -(const std::uint8_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number), cast(i - number), cast(j - number) };
	}

	inline Vector10ui8 Vector10ui8::operator *(const std::uint8_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number), cast(i * number), cast(j * number) };
	}

	inline Vector10ui8 Vector10ui8::operator /(const std::uint8_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number), cast(h / number), cast(i / number), cast(j / number) };
	}


	// increment / decrement
	inline Vector10ui8& Vector10ui8::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i; ++j;
		return *this;
	}

	inline Vector10ui8& Vector10ui8::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i; --j;
		return *this;
	}

	inline Vector10ui8 Vector10ui8::operator++ (int) noexcept {
		Vector10ui8 temp = *this;
		++* this;
		return temp;
	}

	inline Vector10ui8 Vector10ui8::operator-- (int) noexcept {
		Vector10ui8 temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector10ui8& Vector10ui8::operator+= (const Vector10ui8& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g); cast(h += right.h); cast(i += right.i); cast(j += right.j);
		return *this;
	}

	inline Vector10ui8& Vector10ui8::operator-= (const Vector10ui8& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g); cast(h -= right.h); cast(i -= right.i); cast(j -= right.j);
		return *this;
	}

	inline Vector10ui8& Vector10ui8::operator*= (const Vector10ui8& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g); cast(h *= right.h); cast(i *= right.i); cast(j *= right.j);
		return *this;
	}

	inline Vector10ui8& Vector10ui8::operator/= (const Vector10ui8& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g); cast(h /= right.h); cast(i /= right.i); cast(j /= right.j);
		return *this;
	}


	inline Vector10ui8& Vector10ui8::operator+= (const std::uint8_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number); cast(h += number); cast(i += number); cast(j += number);
		return *this;
	}

	inline Vector10ui8& Vector10ui8::operator-= (const std::uint8_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number); cast(h -= number); cast(i -= number); cast(j -= number);
		return *this;
	}

	inline Vector10ui8& Vector10ui8::operator*= (const std::uint8_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number); cast(h *= number); cast(i *= number); cast(j *= number);
		return *this;
	}

	inline Vector10ui8& Vector10ui8::operator/= (const std::uint8_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number); cast(h /= number); cast(i /= number); cast(j /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector10ui8::operator< (const Vector10ui8& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i&& j < other.j;
	}

	inline bool Vector10ui8::operator<= (const Vector10ui8& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i && j <= other.j;
	}

	inline bool Vector10ui8::operator>  (const Vector10ui8& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i && j > other.j;
	}

	inline bool Vector10ui8::operator>= (const Vector10ui8& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i && j >= other.j;
	}


	inline bool Vector10ui8::operator<  (const std::uint8_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number && j < number;
	}

	inline bool Vector10ui8::operator<= (const std::uint8_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number && j <= number;
	}

	inline bool Vector10ui8::operator>  (const std::uint8_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number && j > number;
	}

	inline bool Vector10ui8::operator>= (const std::uint8_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number && j >= number;
	}


	// equal / not equal
	inline bool Vector10ui8::operator==(const Vector10ui8& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i && j == other.j;
	}

	inline bool Vector10ui8::operator!=(const Vector10ui8& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i || j != other.j;
	}

	inline bool Vector10ui8::operator==(const std::uint8_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number && j == number;
	}

	inline bool Vector10ui8::operator!=(const std::uint8_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number || j != number;
	}


	inline constexpr std::uint8_t Vector10ui8::size() const noexcept { return 10; }
	inline void Vector10ui8::reset(const std::uint8_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline std::uint8_t& Vector10ui8::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline std::uint8_t& Vector10ui8::at(const std::uint8_t& index) noexcept
	{
		std::uint8_t* ptr = &a;
		if (index > 9)
			return ptr[0];
		return ptr[index];
	}
	// End
}