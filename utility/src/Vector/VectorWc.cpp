#include "VectorWc.h"

#define cast(x) static_cast<wchar_t>(x)

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : wchar_t
		Bytes: 2
		Range: 0 to 65.535
	*/

	// Vector2Wc
	inline Vector2Wc::Vector2Wc(const wchar_t& x, const wchar_t& y) noexcept
		: x(x), y(y) {}

	// copy/move constructor and assignment
	inline Vector2Wc::Vector2Wc(const Vector2Wc& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2Wc& Vector2Wc::operator=(const Vector2Wc& other) noexcept {
		x = other.x; y = other.y; return *this;
	}

	inline Vector2Wc::Vector2Wc(Vector2Wc&& other) noexcept {
		x = other.x; y = other.y;
	}

	inline Vector2Wc& Vector2Wc::operator=(Vector2Wc&& other) noexcept {
		x = other.x; y = other.y; return *this;
	}
	// .....................................
	inline Vector2Wc& Vector2Wc::operator=(const wchar_t& number) noexcept {
		x = number; y = number; return *this;
	}


	inline Vector2Wc Vector2Wc::operator +(const Vector2Wc& v) const noexcept {
		return { cast(x + v.x), cast(y + v.y) };
	}

	inline Vector2Wc Vector2Wc::operator -(const Vector2Wc& v) const noexcept {
		return { cast(x - v.x), cast(y - v.y) };
	}

	inline Vector2Wc Vector2Wc::operator *(const Vector2Wc& v) const noexcept {
		return { cast(x * v.x), cast(y * v.y) };
	}

	inline Vector2Wc Vector2Wc::operator /(const Vector2Wc& v) const noexcept {
		return { cast(x / v.x), cast(y / v.y) };
	}


	inline Vector2Wc Vector2Wc::operator +(const wchar_t& number) const noexcept {
		return { cast(x + number), cast(y + number) };
	}

	inline Vector2Wc Vector2Wc::operator -(const wchar_t& number) const noexcept {
		return { cast(x - number), cast(y - number) };
	}

	inline Vector2Wc Vector2Wc::operator *(const wchar_t& number) const noexcept {
		return { cast(x * number), cast(y * number) };
	}

	inline Vector2Wc Vector2Wc::operator /(const wchar_t& number) const noexcept {
		return { cast(x / number), cast(y / number) };
	}


	// increment / decrement
	inline Vector2Wc& Vector2Wc::operator++ () noexcept {
		++x; ++y;
		return *this;
	}

	inline Vector2Wc& Vector2Wc::operator-- ()  noexcept {
		--x; --y;
		return *this;
	}

	inline Vector2Wc Vector2Wc::operator++ (int) noexcept {
		Vector2Wc temp = *this;
		++* this;
		return temp;
	}

	inline Vector2Wc Vector2Wc::operator-- (int) noexcept {
		Vector2Wc temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector2Wc& Vector2Wc::operator+= (const Vector2Wc& right) noexcept {
		cast(x += right.x); cast(y += right.y);
		return *this;
	}

	inline Vector2Wc& Vector2Wc::operator-= (const Vector2Wc& right) noexcept {
		cast(x -= right.x); cast(y -= right.y);
		return *this;
	}

	inline Vector2Wc& Vector2Wc::operator*= (const Vector2Wc& right) noexcept {
		cast(x *= right.x); cast(y *= right.y);
		return *this;
	}

	inline Vector2Wc& Vector2Wc::operator/= (const Vector2Wc& right) noexcept {
		cast(x /= right.x); cast(y /= right.y);
		return *this;
	}


	inline Vector2Wc& Vector2Wc::operator+= (const wchar_t& number) noexcept {
		cast(x += number); cast(y += number);
		return *this;
	}

	inline Vector2Wc& Vector2Wc::operator-= (const wchar_t& number) noexcept {
		cast(x -= number); cast(y -= number);
		return *this;
	}

	inline Vector2Wc& Vector2Wc::operator*= (const wchar_t& number) noexcept {
		cast(x *= number); cast(y *= number);
		return *this;
	}

	inline Vector2Wc& Vector2Wc::operator/= (const wchar_t& number) noexcept {
		cast(x /= number); cast(y /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector2Wc::operator< (const Vector2Wc& other) const noexcept {
		return x < other.x && y < other.y;
	}

	inline bool Vector2Wc::operator<= (const Vector2Wc& other) const noexcept {
		return x <= other.x && y <= other.y;
	}

	inline bool Vector2Wc::operator>  (const Vector2Wc& other) const noexcept {
		return x > other.x && y > other.y;
	}

	inline bool Vector2Wc::operator>= (const Vector2Wc& other) const noexcept {
		return x >= other.x && y >= other.y;
	}


	inline bool Vector2Wc::operator<  (const wchar_t& number) const noexcept {
		return x < number && y < number;
	}

	inline bool Vector2Wc::operator<= (const wchar_t& number) const noexcept {
		return x <= number && y <= number;
	}

	inline bool Vector2Wc::operator>  (const wchar_t& number) const noexcept {
		return x > number && y > number;
	}

	inline bool Vector2Wc::operator>= (const wchar_t& number) const noexcept {
		return x >= number && y >= number;
	}


	// equal / not equal
	inline bool Vector2Wc::operator==(const Vector2Wc& other) const noexcept {
		return x == other.x && y == other.y;
	}

	inline bool Vector2Wc::operator!=(const Vector2Wc& other) const noexcept {
		return x != other.x || y != other.y;
	}

	inline bool Vector2Wc::operator==(const wchar_t& number) const noexcept {
		return x == number && y == number;
	}

	inline bool Vector2Wc::operator!=(const wchar_t& number) const noexcept {
		return x != number || y != number;
	}


	inline constexpr std::uint8_t Vector2Wc::size() const noexcept { return 2; }
	inline void Vector2Wc::reset(const wchar_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline wchar_t& Vector2Wc::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline wchar_t& Vector2Wc::at(const std::uint8_t& index) noexcept
	{
		wchar_t* ptr = &x;
		if (index > 1)
			return ptr[0];
		return ptr[index];
	}



	// Vector3Wc
	inline Vector3Wc::Vector3Wc(const wchar_t& x, const wchar_t& y, const wchar_t& z) noexcept
		: x(x), y(y), z(z) {}

	// copy/move constructor and assignment
	inline Vector3Wc::Vector3Wc(const Vector3Wc& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3Wc& Vector3Wc::operator=(const Vector3Wc& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}

	inline Vector3Wc::Vector3Wc(Vector3Wc&& other) noexcept {
		x = other.x; y = other.y; z = other.z;
	}

	inline Vector3Wc& Vector3Wc::operator=(Vector3Wc&& other) noexcept {
		x = other.x; y = other.y; z = other.z; return *this;
	}
	// .....................................
	inline Vector3Wc& Vector3Wc::operator=(const wchar_t& number) noexcept {
		x = number; y = number; z = number; return *this;
	}


	inline Vector3Wc Vector3Wc::operator +(const Vector3Wc& v) const noexcept {
		return { cast(x + v.x), cast(y + v.y), cast(z + v.z) };
	}

	inline Vector3Wc Vector3Wc::operator -(const Vector3Wc& v) const noexcept {
		return { cast(x - v.x), cast(y - v.y), cast(z - v.z) };
	}

	inline Vector3Wc Vector3Wc::operator *(const Vector3Wc& v) const noexcept {
		return { cast(x * v.x), cast(y * v.y), cast(z * v.z) };
	}

	inline Vector3Wc Vector3Wc::operator /(const Vector3Wc& v) const noexcept {
		return { cast(x / v.x), cast(y / v.y), cast(z / v.z) };
	}

 
	inline Vector3Wc Vector3Wc::operator +(const wchar_t& number) const noexcept {
		return { cast(x + number), cast(y + number), cast(z + number) };
	}

	inline Vector3Wc Vector3Wc::operator -(const wchar_t& number) const noexcept {
		return { cast(x - number), cast(y - number), cast(z - number) };
	}

	inline Vector3Wc Vector3Wc::operator *(const wchar_t& number) const noexcept {
		return { cast(x * number), cast(y * number), cast(z * number) };
	}

	inline Vector3Wc Vector3Wc::operator /(const wchar_t& number) const noexcept {
		return { cast(x / number), cast(y / number), cast(z / number) };
	}


	// increment / decrement
	inline Vector3Wc& Vector3Wc::operator++ () noexcept {
		++x; ++y; ++z;
		return *this;
	}

	inline Vector3Wc& Vector3Wc::operator-- () noexcept {
		--x; --y; --z;
		return *this;
	}

	inline Vector3Wc Vector3Wc::operator++ (int) noexcept {
		Vector3Wc temp = *this;
		++* this;
		return temp;
	}

	inline Vector3Wc Vector3Wc::operator-- (int) noexcept {
		Vector3Wc temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector3Wc& Vector3Wc::operator+= (const Vector3Wc& right) noexcept {
		cast(x += right.x); cast(y += right.y); cast(z += right.z);
		return *this;
	}

	inline Vector3Wc& Vector3Wc::operator-= (const Vector3Wc& right) noexcept {
		cast(x -= right.x); cast(y -= right.y); cast(z -= right.z);
		return *this;
	}

	inline Vector3Wc& Vector3Wc::operator*= (const Vector3Wc& right) noexcept {
		cast(x *= right.x); cast(y *= right.y); cast(z *= right.z);
		return *this;
	}

	inline Vector3Wc& Vector3Wc::operator/= (const Vector3Wc& right) noexcept {
		cast(x /= right.x); cast(y /= right.y); cast(z /= right.z);
		return *this;
	}


	inline Vector3Wc& Vector3Wc::operator+= (const wchar_t& number) noexcept {
		cast(x += number); cast(y += number); cast(z += number);
		return *this;
	}

	inline Vector3Wc& Vector3Wc::operator-= (const wchar_t& number) noexcept {
		cast(x -= number); cast(y -= number); cast(z -= number);
		return *this;
	}

	inline Vector3Wc& Vector3Wc::operator*= (const wchar_t& number) noexcept {
		cast(x *= number); cast(y *= number); cast(z *= number);
		return *this;
	}

	inline Vector3Wc& Vector3Wc::operator/= (const wchar_t& number) noexcept {
		cast(x /= number); cast(y /= number); cast(z /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector3Wc::operator< (const Vector3Wc& other) const noexcept {
		return x < other.x && y < other.y&& z < other.z;
	}

	inline bool Vector3Wc::operator<= (const Vector3Wc& other) const noexcept {
		return x <= other.x && y <= other.y && z <= other.z;
	}

	inline bool Vector3Wc::operator>  (const Vector3Wc& other) const noexcept {
		return x > other.x && y > other.y && z > other.z;
	}

	inline bool Vector3Wc::operator>= (const Vector3Wc& other) const noexcept {
		return x >= other.x && y >= other.y && z >= other.z;
	}


	inline bool Vector3Wc::operator<  (const wchar_t& number) const noexcept {
		return x < number && y < number && z < number;
	}

	inline bool Vector3Wc::operator<= (const wchar_t& number) const noexcept {
		return x <= number && y <= number && z <= number;
	}

	inline bool Vector3Wc::operator>  (const wchar_t& number) const noexcept {
		return x > number && y > number && z > number;
	}

	inline bool Vector3Wc::operator>= (const wchar_t& number) const noexcept {
		return x >= number && y >= number && z >= number;
	}


	// equal / not equal
	inline bool Vector3Wc::operator==(const Vector3Wc& other) const noexcept {
		return x == other.x && y == other.y && z == other.z;
	}

	inline bool Vector3Wc::operator!=(const Vector3Wc& other) const noexcept {
		return x != other.x || y != other.y || z != other.z;
	}

	inline bool Vector3Wc::operator==(const wchar_t& number) const noexcept {
		return x == number && y == number && z == number;
	}

	inline bool Vector3Wc::operator!=(const wchar_t& number) const noexcept {
		return x != number || y != number || z != number;
	}


	inline constexpr std::uint8_t Vector3Wc::size() const noexcept { return 3; }
	inline void Vector3Wc::reset(const wchar_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline wchar_t& Vector3Wc::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline wchar_t& Vector3Wc::at(const std::uint8_t& index) noexcept
	{
		wchar_t* ptr = &x;
		if (index > 2)
			return ptr[0];
		return ptr[index];
	}



	// Vector4Wc
	inline Vector4Wc::Vector4Wc(const wchar_t& a, const wchar_t& b, const wchar_t& c, const wchar_t& d) noexcept
		: a(a), b(b), c(c), d(d) {}

	// copy/move constructor and assignment
	inline Vector4Wc::Vector4Wc(const Vector4Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4Wc& Vector4Wc::operator=(const Vector4Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}

	inline Vector4Wc::Vector4Wc(Vector4Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d;
	}

	inline Vector4Wc& Vector4Wc::operator=(Vector4Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; return *this;
	}
	// .....................................
	inline Vector4Wc& Vector4Wc::operator=(const wchar_t& number) noexcept {
		a = number; b = number; c = number; d = number; return *this;
	}


	inline Vector4Wc Vector4Wc::operator +(const Vector4Wc& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d) };
	}

	inline Vector4Wc Vector4Wc::operator -(const Vector4Wc& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d) };
	}

	inline Vector4Wc Vector4Wc::operator *(const Vector4Wc& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d) };
	}

	inline Vector4Wc Vector4Wc::operator /(const Vector4Wc& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d) };
	}


	inline Vector4Wc Vector4Wc::operator +(const wchar_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number) };
	}

	inline Vector4Wc Vector4Wc::operator -(const wchar_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number) };
	}

	inline Vector4Wc Vector4Wc::operator *(const wchar_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number) };
	}

	inline Vector4Wc Vector4Wc::operator /(const wchar_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number) };
	}


	// increment / decrement
	inline Vector4Wc& Vector4Wc::operator++ () noexcept {
		++a; ++b; ++c; ++d;
		return *this;
	}

	inline Vector4Wc& Vector4Wc::operator-- () noexcept {
		--a; --b; --c; --d;
		return *this;
	}

	inline Vector4Wc Vector4Wc::operator++ (int) noexcept {
		Vector4Wc temp = *this;
		++* this;
		return temp;
	}

	inline Vector4Wc Vector4Wc::operator-- (int) noexcept {
		Vector4Wc temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector4Wc& Vector4Wc::operator+= (const Vector4Wc& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d);
		return *this;
	}

	inline Vector4Wc& Vector4Wc::operator-= (const Vector4Wc& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d);
		return *this;
	}

	inline Vector4Wc& Vector4Wc::operator*= (const Vector4Wc& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d);
		return *this;
	}

	inline Vector4Wc& Vector4Wc::operator/= (const Vector4Wc& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d);
		return *this;
	}


	inline Vector4Wc& Vector4Wc::operator+= (const wchar_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number);
		return *this;
	}

	inline Vector4Wc& Vector4Wc::operator-= (const wchar_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number);
		return *this;
	}

	inline Vector4Wc& Vector4Wc::operator*= (const wchar_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number);
		return *this;
	}

	inline Vector4Wc& Vector4Wc::operator/= (const wchar_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector4Wc::operator< (const Vector4Wc& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d;
	}

	inline bool Vector4Wc::operator<= (const Vector4Wc& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d;
	}

	inline bool Vector4Wc::operator>  (const Vector4Wc& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d;
	}

	inline bool Vector4Wc::operator>= (const Vector4Wc& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d;
	}


	inline bool Vector4Wc::operator<  (const wchar_t& number) const noexcept {
		return a < number && b < number && c < number && d < number;
	}

	inline bool Vector4Wc::operator<= (const wchar_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number;
	}

	inline bool Vector4Wc::operator>  (const wchar_t& number) const noexcept {
		return a > number && b > number && c > number && d > number;
	}

	inline bool Vector4Wc::operator>= (const wchar_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number;
	}


	// equal / not equal
	inline bool Vector4Wc::operator==(const Vector4Wc& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d;
	}

	inline bool Vector4Wc::operator!=(const Vector4Wc& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d;
	}

	inline bool Vector4Wc::operator==(const wchar_t& number) const noexcept {
		return a == number && b == number && c == number && d == number;
	}

	inline bool Vector4Wc::operator!=(const wchar_t& number) const noexcept {
		return a != number || b != number || c != number || d != number;
	}


	inline constexpr std::uint8_t Vector4Wc::size() const noexcept { return 4; }
	inline void Vector4Wc::reset(const wchar_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline wchar_t& Vector4Wc::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline wchar_t& Vector4Wc::at(const std::uint8_t& index) noexcept
	{
		wchar_t* ptr = &a;
		if (index > 3)
			return ptr[0];
		return ptr[index];
	}



	// Vector5Wc
	inline Vector5Wc::Vector5Wc(const wchar_t& a, const wchar_t& b, const wchar_t& c, const wchar_t& d,
		const wchar_t& e) noexcept
		: a(a), b(b), c(c), d(d), e(e) {}

	// copy/move constructor and assignment
	inline Vector5Wc::Vector5Wc(const Vector5Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5Wc& Vector5Wc::operator=(const Vector5Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}

	inline Vector5Wc::Vector5Wc(Vector5Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e;
	}

	inline Vector5Wc& Vector5Wc::operator=(Vector5Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; return *this;
	}
	// .....................................
	inline Vector5Wc& Vector5Wc::operator=(const wchar_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; return *this;
	}


	inline Vector5Wc Vector5Wc::operator +(const Vector5Wc& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e) };
	}

	inline Vector5Wc Vector5Wc::operator -(const Vector5Wc& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e) };
	}

	inline Vector5Wc Vector5Wc::operator *(const Vector5Wc& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e) };
	}

	inline Vector5Wc Vector5Wc::operator /(const Vector5Wc& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e) };
	}


	inline Vector5Wc Vector5Wc::operator +(const wchar_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number) };
	}

	inline Vector5Wc Vector5Wc::operator -(const wchar_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number) };
	}

	inline Vector5Wc Vector5Wc::operator *(const wchar_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number) };
	}

	inline Vector5Wc Vector5Wc::operator /(const wchar_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number) };
	}


	// increment / decrement
	inline Vector5Wc& Vector5Wc::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e;
		return *this;
	}

	inline Vector5Wc& Vector5Wc::operator-- () noexcept {
		--a; --b; --c; --d; --e;
		return *this;
	}

	inline Vector5Wc Vector5Wc::operator++ (int) noexcept {
		Vector5Wc temp = *this;
		++* this;
		return temp;
	}

	inline Vector5Wc Vector5Wc::operator-- (int) noexcept {
		Vector5Wc temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector5Wc& Vector5Wc::operator+= (const Vector5Wc& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e);
		return *this;
	}

	inline Vector5Wc& Vector5Wc::operator-= (const Vector5Wc& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e);
		return *this;
	}

	inline Vector5Wc& Vector5Wc::operator*= (const Vector5Wc& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e);
		return *this;
	}

	inline Vector5Wc& Vector5Wc::operator/= (const Vector5Wc& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e);
		return *this;
	}


	inline Vector5Wc& Vector5Wc::operator+= (const wchar_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number);
		return *this;
	}

	inline Vector5Wc& Vector5Wc::operator-= (const wchar_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number);
		return *this;
	}

	inline Vector5Wc& Vector5Wc::operator*= (const wchar_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number);
		return *this;
	}

	inline Vector5Wc& Vector5Wc::operator/= (const wchar_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector5Wc::operator< (const Vector5Wc& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e;
	}

	inline bool Vector5Wc::operator<= (const Vector5Wc& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e;
	}

	inline bool Vector5Wc::operator>  (const Vector5Wc& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e;
	}

	inline bool Vector5Wc::operator>= (const Vector5Wc& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e;
	}


	inline bool Vector5Wc::operator<  (const wchar_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number;
	}

	inline bool Vector5Wc::operator<= (const wchar_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number;
	}

	inline bool Vector5Wc::operator>  (const wchar_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number;
	}

	inline bool Vector5Wc::operator>= (const wchar_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number;
	}


	// equal / not equal
	inline bool Vector5Wc::operator==(const Vector5Wc& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e;
	}

	inline bool Vector5Wc::operator!=(const Vector5Wc& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e;
	}

	inline bool Vector5Wc::operator==(const wchar_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number;
	}

	inline bool Vector5Wc::operator!=(const wchar_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number;
	}


	inline constexpr std::uint8_t Vector5Wc::size() const noexcept { return 5; }
	inline void Vector5Wc::reset(const wchar_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline wchar_t& Vector5Wc::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline wchar_t& Vector5Wc::at(const std::uint8_t& index) noexcept
	{
		wchar_t* ptr = &a;
		if (index > 4)
			return ptr[0];
		return ptr[index];
	}



	// Vector6Wc
	inline Vector6Wc::Vector6Wc(const wchar_t& a, const wchar_t& b, const wchar_t& c, const wchar_t& d,
		const wchar_t& e, const wchar_t& f) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f) {}

	// copy/move constructor and assignment
	inline Vector6Wc::Vector6Wc(const Vector6Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6Wc& Vector6Wc::operator=(const Vector6Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}

	inline Vector6Wc::Vector6Wc(Vector6Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f;
	}

	inline Vector6Wc& Vector6Wc::operator=(Vector6Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; return *this;
	}
	// .....................................
	inline Vector6Wc& Vector6Wc::operator=(const wchar_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; return *this;
	}


	inline Vector6Wc Vector6Wc::operator +(const Vector6Wc& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f) };
	}

	inline Vector6Wc Vector6Wc::operator -(const Vector6Wc& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f) };
	}

	inline Vector6Wc Vector6Wc::operator *(const Vector6Wc& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f) };
	}

	inline Vector6Wc Vector6Wc::operator /(const Vector6Wc& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f) };
	}


	inline Vector6Wc Vector6Wc::operator +(const wchar_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number) };
	}

	inline Vector6Wc Vector6Wc::operator -(const wchar_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number) };
	}

	inline Vector6Wc Vector6Wc::operator *(const wchar_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number) };
	}

	inline Vector6Wc Vector6Wc::operator /(const wchar_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number) };
	}


	// increment / decrement
	inline Vector6Wc& Vector6Wc::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f;
		return *this;
	}

	inline Vector6Wc& Vector6Wc::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f;
		return *this;
	}

	inline Vector6Wc Vector6Wc::operator++ (int) noexcept {
		Vector6Wc temp = *this;
		++* this;
		return temp;
	}

	inline Vector6Wc Vector6Wc::operator-- (int) noexcept {
		Vector6Wc temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector6Wc& Vector6Wc::operator+= (const Vector6Wc& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f);
		return *this;
	}

	inline Vector6Wc& Vector6Wc::operator-= (const Vector6Wc& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f);
		return *this;
	}

	inline Vector6Wc& Vector6Wc::operator*= (const Vector6Wc& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f);
		return *this;
	}

	inline Vector6Wc& Vector6Wc::operator/= (const Vector6Wc& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f);
		return *this;
	}


	inline Vector6Wc& Vector6Wc::operator+= (const wchar_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number);
		return *this;
	}

	inline Vector6Wc& Vector6Wc::operator-= (const wchar_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number);
		return *this;
	}

	inline Vector6Wc& Vector6Wc::operator*= (const wchar_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number);
		return *this;
	}

	inline Vector6Wc& Vector6Wc::operator/= (const wchar_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector6Wc::operator< (const Vector6Wc& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f;
	}

	inline bool Vector6Wc::operator<= (const Vector6Wc& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f;
	}

	inline bool Vector6Wc::operator>  (const Vector6Wc& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f;
	}

	inline bool Vector6Wc::operator>= (const Vector6Wc& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f;
	}


	inline bool Vector6Wc::operator<  (const wchar_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number;
	}

	inline bool Vector6Wc::operator<= (const wchar_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number;
	}

	inline bool Vector6Wc::operator>  (const wchar_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number;
	}

	inline bool Vector6Wc::operator>= (const wchar_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number;
	}


	// equal / not equal
	inline bool Vector6Wc::operator==(const Vector6Wc& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f;
	}

	inline bool Vector6Wc::operator!=(const Vector6Wc& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f;
	}

	inline bool Vector6Wc::operator==(const wchar_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number;
	}

	inline bool Vector6Wc::operator!=(const wchar_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number;
	}


	inline constexpr std::uint8_t Vector6Wc::size() const noexcept { return 6; }
	inline void Vector6Wc::reset(const wchar_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline wchar_t& Vector6Wc::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline wchar_t& Vector6Wc::at(const std::uint8_t& index) noexcept
	{
		wchar_t* ptr = &a;
		if (index > 5)
			return ptr[0];
		return ptr[index];
	}



	// Vector7Wc
	inline Vector7Wc::Vector7Wc(const wchar_t& a, const wchar_t& b, const wchar_t& c, const wchar_t& d,
		const wchar_t& e, const wchar_t& f, const wchar_t& g) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g) {}

	// copy/move constructor and assignment
	inline Vector7Wc::Vector7Wc(const Vector7Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7Wc& Vector7Wc::operator=(const Vector7Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}

	inline Vector7Wc::Vector7Wc(Vector7Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g;
	}

	inline Vector7Wc& Vector7Wc::operator=(Vector7Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; return *this;
	}
	// .....................................
	inline Vector7Wc& Vector7Wc::operator=(const wchar_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; return *this;
	}


	inline Vector7Wc Vector7Wc::operator +(const Vector7Wc& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g) };
	}

	inline Vector7Wc Vector7Wc::operator -(const Vector7Wc& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g) };
	}

	inline Vector7Wc Vector7Wc::operator *(const Vector7Wc& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g) };
	}

	inline Vector7Wc Vector7Wc::operator /(const Vector7Wc& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g) };
	}


	inline Vector7Wc Vector7Wc::operator +(const wchar_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number) };
	}

	inline Vector7Wc Vector7Wc::operator -(const wchar_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number) };
	}

	inline Vector7Wc Vector7Wc::operator *(const wchar_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number) };
	}

	inline Vector7Wc Vector7Wc::operator /(const wchar_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number) };
	}


	// increment / decrement
	inline Vector7Wc& Vector7Wc::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g;
		return *this;
	}

	inline Vector7Wc& Vector7Wc::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g;
		return *this;
	}

	inline Vector7Wc Vector7Wc::operator++ (int) noexcept {
		Vector7Wc temp = *this;
		++* this;
		return temp;
	}

	inline Vector7Wc Vector7Wc::operator-- (int) noexcept {
		Vector7Wc temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector7Wc& Vector7Wc::operator+= (const Vector7Wc& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g);
		return *this;
	}

	inline Vector7Wc& Vector7Wc::operator-= (const Vector7Wc& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g);
		return *this;
	}

	inline Vector7Wc& Vector7Wc::operator*= (const Vector7Wc& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g);
		return *this;
	}

	inline Vector7Wc& Vector7Wc::operator/= (const Vector7Wc& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g);
		return *this;
	}


	inline Vector7Wc& Vector7Wc::operator+= (const wchar_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number);
		return *this;
	}

	inline Vector7Wc& Vector7Wc::operator-= (const wchar_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number);
		return *this;
	}

	inline Vector7Wc& Vector7Wc::operator*= (const wchar_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number);
		return *this;
	}

	inline Vector7Wc& Vector7Wc::operator/= (const wchar_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector7Wc::operator< (const Vector7Wc& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g;
	}

	inline bool Vector7Wc::operator<= (const Vector7Wc& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g;
	}

	inline bool Vector7Wc::operator>  (const Vector7Wc& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g;
	}

	inline bool Vector7Wc::operator>= (const Vector7Wc& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g;
	}


	inline bool Vector7Wc::operator<  (const wchar_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number;
	}

	inline bool Vector7Wc::operator<= (const wchar_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number;
	}

	inline bool Vector7Wc::operator>  (const wchar_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number;
	}

	inline bool Vector7Wc::operator>= (const wchar_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number;
	}


	// equal / not equal
	inline bool Vector7Wc::operator==(const Vector7Wc& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g;
	}

	inline bool Vector7Wc::operator!=(const Vector7Wc& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g;
	}

	inline bool Vector7Wc::operator==(const wchar_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number;
	}

	inline bool Vector7Wc::operator!=(const wchar_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number;
	}


	inline constexpr std::uint8_t Vector7Wc::size() const noexcept { return 7; }
	inline void Vector7Wc::reset(const wchar_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline wchar_t& Vector7Wc::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline wchar_t& Vector7Wc::at(const std::uint8_t& index) noexcept
	{
		wchar_t* ptr = &a;
		if (index > 6)
			return ptr[0];
		return ptr[index];
	}



	// Vector8Wc
	inline Vector8Wc::Vector8Wc(const wchar_t& a, const wchar_t& b, const wchar_t& c, const wchar_t& d,
		const wchar_t& e, const wchar_t& f, const wchar_t& g, const wchar_t& h) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h) {}

	// copy/move constructor and assignment
	inline Vector8Wc::Vector8Wc(const Vector8Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8Wc& Vector8Wc::operator=(const Vector8Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}

	inline Vector8Wc::Vector8Wc(Vector8Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h;
	}

	inline Vector8Wc& Vector8Wc::operator=(Vector8Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; return *this;
	}
	// .....................................
	inline Vector8Wc& Vector8Wc::operator=(const wchar_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; return *this;
	}


	inline Vector8Wc Vector8Wc::operator +(const Vector8Wc& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h) };
	}

	inline Vector8Wc Vector8Wc::operator -(const Vector8Wc& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h) };
	}

	inline Vector8Wc Vector8Wc::operator *(const Vector8Wc& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h) };
	}

	inline Vector8Wc Vector8Wc::operator /(const Vector8Wc& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g), cast(h / v.h) };
	}


	inline Vector8Wc Vector8Wc::operator +(const wchar_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number) };
	}

	inline Vector8Wc Vector8Wc::operator -(const wchar_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number) };
	}

	inline Vector8Wc Vector8Wc::operator *(const wchar_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number) };
	}

	inline Vector8Wc Vector8Wc::operator /(const wchar_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number), cast(h / number) };
	}


	// increment / decrement
	inline Vector8Wc& Vector8Wc::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h;
		return *this;
	}

	inline Vector8Wc& Vector8Wc::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h;
		return *this;
	}

	inline Vector8Wc Vector8Wc::operator++ (int) noexcept {
		Vector8Wc temp = *this;
		++* this;
		return temp;
	}

	inline Vector8Wc Vector8Wc::operator-- (int) noexcept {
		Vector8Wc temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector8Wc& Vector8Wc::operator+= (const Vector8Wc& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g); cast(h += right.h);
		return *this;
	}

	inline Vector8Wc& Vector8Wc::operator-= (const Vector8Wc& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g); cast(h -= right.h);
		return *this;
	}

	inline Vector8Wc& Vector8Wc::operator*= (const Vector8Wc& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g); cast(h *= right.h);
		return *this;
	}

	inline Vector8Wc& Vector8Wc::operator/= (const Vector8Wc& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g); cast(h /= right.h);
		return *this;
	}


	inline Vector8Wc& Vector8Wc::operator+= (const wchar_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number); cast(h += number);
		return *this;
	}

	inline Vector8Wc& Vector8Wc::operator-= (const wchar_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number); cast(h -= number);
		return *this;
	}

	inline Vector8Wc& Vector8Wc::operator*= (const wchar_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number); cast(h *= number);
		return *this;
	}

	inline Vector8Wc& Vector8Wc::operator/= (const wchar_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number); cast(h /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector8Wc::operator< (const Vector8Wc& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h;
	}

	inline bool Vector8Wc::operator<= (const Vector8Wc& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h;
	}

	inline bool Vector8Wc::operator>  (const Vector8Wc& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h;
	}

	inline bool Vector8Wc::operator>= (const Vector8Wc& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h;
	}


	inline bool Vector8Wc::operator<  (const wchar_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number;
	}

	inline bool Vector8Wc::operator<= (const wchar_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number;
	}

	inline bool Vector8Wc::operator>  (const wchar_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number;
	}

	inline bool Vector8Wc::operator>= (const wchar_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number;
	}


	// equal / not equal
	inline bool Vector8Wc::operator==(const Vector8Wc& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h;
	}

	inline bool Vector8Wc::operator!=(const Vector8Wc& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h;
	}

	inline bool Vector8Wc::operator==(const wchar_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number;
	}

	inline bool Vector8Wc::operator!=(const wchar_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number;
	}


	inline constexpr std::uint8_t Vector8Wc::size() const noexcept { return 8; }
	inline void Vector8Wc::reset(const wchar_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline wchar_t& Vector8Wc::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline wchar_t& Vector8Wc::at(const std::uint8_t& index) noexcept
	{
		wchar_t* ptr = &a;
		if (index > 7)
			return ptr[0];
		return ptr[index];
	}



	// Vector9Wc
	inline Vector9Wc::Vector9Wc(const wchar_t& a, const wchar_t& b, const wchar_t& c, const wchar_t& d,
		const wchar_t& e, const wchar_t& f, const wchar_t& g, const wchar_t& h,
		const wchar_t& i) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}

	// copy/move constructor and assignment
	inline Vector9Wc::Vector9Wc(const Vector9Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9Wc& Vector9Wc::operator=(const Vector9Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}

	inline Vector9Wc::Vector9Wc(Vector9Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i;
	}

	inline Vector9Wc& Vector9Wc::operator=(Vector9Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; return *this;
	}
	// .....................................
	inline Vector9Wc& Vector9Wc::operator=(const wchar_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; return *this;
	}


	inline Vector9Wc Vector9Wc::operator +(const Vector9Wc& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h), cast(i + v.i) };
	}

	inline Vector9Wc Vector9Wc::operator -(const Vector9Wc& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h), cast(i - v.i) };
	}

	inline Vector9Wc Vector9Wc::operator *(const Vector9Wc& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h), cast(i * v.i) };
	}

	inline Vector9Wc Vector9Wc::operator /(const Vector9Wc& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g), cast(h / v.h), cast(i / v.i) };
	}


	inline Vector9Wc Vector9Wc::operator +(const wchar_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number), cast(i + number) };
	}

	inline Vector9Wc Vector9Wc::operator -(const wchar_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number), cast(i - number) };
	}

	inline Vector9Wc Vector9Wc::operator *(const wchar_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number), cast(i * number) };
	}

	inline Vector9Wc Vector9Wc::operator /(const wchar_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number), cast(h / number), cast(i / number) };
	}


	// increment / decrement
	inline Vector9Wc& Vector9Wc::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i;
		return *this;
	}

	inline Vector9Wc& Vector9Wc::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i;
		return *this;
	}

	inline Vector9Wc Vector9Wc::operator++ (int) noexcept {
		Vector9Wc temp = *this;
		++* this;
		return temp;
	}

	inline Vector9Wc Vector9Wc::operator-- (int) noexcept {
		Vector9Wc temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector9Wc& Vector9Wc::operator+= (const Vector9Wc& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g); cast(h += right.h); cast(i += right.i);
		return *this;
	}

	inline Vector9Wc& Vector9Wc::operator-= (const Vector9Wc& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g); cast(h -= right.h); cast(i -= right.i);
		return *this;
	}

	inline Vector9Wc& Vector9Wc::operator*= (const Vector9Wc& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g); cast(h *= right.h); cast(i *= right.i);
		return *this;
	}

	inline Vector9Wc& Vector9Wc::operator/= (const Vector9Wc& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g); cast(h /= right.h); cast(i /= right.i);
		return *this;
	}


	inline Vector9Wc& Vector9Wc::operator+= (const wchar_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number); cast(h += number); cast(i += number);
		return *this;
	}

	inline Vector9Wc& Vector9Wc::operator-= (const wchar_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number); cast(h -= number); cast(i -= number);
		return *this;
	}

	inline Vector9Wc& Vector9Wc::operator*= (const wchar_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number); cast(h *= number); cast(i *= number);
		return *this;
	}

	inline Vector9Wc& Vector9Wc::operator/= (const wchar_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number); cast(h /= number); cast(i /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector9Wc::operator< (const Vector9Wc& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i;
	}

	inline bool Vector9Wc::operator<= (const Vector9Wc& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i;
	}

	inline bool Vector9Wc::operator>  (const Vector9Wc& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i;
	}

	inline bool Vector9Wc::operator>= (const Vector9Wc& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i;
	}


	inline bool Vector9Wc::operator<  (const wchar_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number;
	}

	inline bool Vector9Wc::operator<= (const wchar_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number;
	}

	inline bool Vector9Wc::operator>  (const wchar_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number;
	}

	inline bool Vector9Wc::operator>= (const wchar_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number;
	}


	// equal / not equal
	inline bool Vector9Wc::operator==(const Vector9Wc& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i;
	}

	inline bool Vector9Wc::operator!=(const Vector9Wc& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i;
	}

	inline bool Vector9Wc::operator==(const wchar_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number;
	}

	inline bool Vector9Wc::operator!=(const wchar_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number;
	}


	inline constexpr std::uint8_t Vector9Wc::size() const noexcept { return 9; }
	inline void Vector9Wc::reset(const wchar_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline wchar_t& Vector9Wc::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline wchar_t& Vector9Wc::at(const std::uint8_t& index) noexcept
	{
		wchar_t* ptr = &a;
		if (index > 8)
			return ptr[0];
		return ptr[index];
	}



	// Vector10Wc
	inline Vector10Wc::Vector10Wc(const wchar_t& a, const wchar_t& b, const wchar_t& c, const wchar_t& d,
		const wchar_t& e, const wchar_t& f, const wchar_t& g, const wchar_t& h,
		const wchar_t& i, const wchar_t& j) noexcept
		: a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i), j(j) {}

	// copy/move constructor and assignment
	inline Vector10Wc::Vector10Wc(const Vector10Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10Wc& Vector10Wc::operator=(const Vector10Wc& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}

	inline Vector10Wc::Vector10Wc(Vector10Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j;
	}

	inline Vector10Wc& Vector10Wc::operator=(Vector10Wc&& other) noexcept {
		a = other.a; b = other.b; c = other.c; d = other.d; e = other.e; f = other.f; g = other.g; h = other.h; i = other.i; j = other.j; return *this;
	}
	// .....................................
	inline Vector10Wc& Vector10Wc::operator=(const wchar_t& number) noexcept {
		a = number; b = number; c = number; d = number; e = number; f = number; g = number; h = number; i = number; j = number; return *this;
	}


	inline Vector10Wc Vector10Wc::operator +(const Vector10Wc& v) const noexcept {
		return { cast(a + v.a), cast(b + v.b), cast(c + v.c), cast(d + v.d), cast(e + v.e), cast(f + v.f), cast(g + v.g), cast(h + v.h), cast(i + v.i), cast(j + v.j) };
	}

	inline Vector10Wc Vector10Wc::operator -(const Vector10Wc& v) const noexcept {
		return { cast(a - v.a), cast(b - v.b), cast(c - v.c), cast(d - v.d), cast(e - v.e), cast(f - v.f), cast(g - v.g), cast(h - v.h), cast(i - v.i), cast(j - v.j) };
	}

	inline Vector10Wc Vector10Wc::operator *(const Vector10Wc& v) const noexcept {
		return { cast(a * v.a), cast(b * v.b), cast(c * v.c), cast(d * v.d), cast(e * v.e), cast(f * v.f), cast(g * v.g), cast(h * v.h), cast(i * v.i), cast(j * v.j) };
	}

	inline Vector10Wc Vector10Wc::operator /(const Vector10Wc& v) const noexcept {
		return { cast(a / v.a), cast(b / v.b), cast(c / v.c), cast(d / v.d), cast(e / v.e), cast(f / v.f), cast(g / v.g), cast(h / v.h), cast(i / v.i), cast(j / v.j) };
	}


	inline Vector10Wc Vector10Wc::operator +(const wchar_t& number) const noexcept {
		return { cast(a + number), cast(b + number), cast(c + number), cast(d + number), cast(e + number), cast(f + number), cast(g + number), cast(h + number), cast(i + number), cast(j + number) };
	}

	inline Vector10Wc Vector10Wc::operator -(const wchar_t& number) const noexcept {
		return { cast(a - number), cast(b - number), cast(c - number), cast(d - number), cast(e - number), cast(f - number), cast(g - number), cast(h - number), cast(i - number), cast(j - number) };
	}

	inline Vector10Wc Vector10Wc::operator *(const wchar_t& number) const noexcept {
		return { cast(a * number), cast(b * number), cast(c * number), cast(d * number), cast(e * number), cast(f * number), cast(g * number), cast(h * number), cast(i * number), cast(j * number) };
	}

	inline Vector10Wc Vector10Wc::operator /(const wchar_t& number) const noexcept {
		return { cast(a / number), cast(b / number), cast(c / number), cast(d / number), cast(e / number), cast(f / number), cast(g / number), cast(h / number), cast(i / number), cast(j / number) };
	}


	// increment / decrement
	inline Vector10Wc& Vector10Wc::operator++ () noexcept {
		++a; ++b; ++c; ++d; ++e; ++f; ++g; ++h; ++i; ++j;
		return *this;
	}

	inline Vector10Wc& Vector10Wc::operator-- () noexcept {
		--a; --b; --c; --d; --e; --f; --g; --h; --i; --j;
		return *this;
	}

	inline Vector10Wc Vector10Wc::operator++ (int) noexcept {
		Vector10Wc temp = *this;
		++* this;
		return temp;
	}

	inline Vector10Wc Vector10Wc::operator-- (int) noexcept {
		Vector10Wc temp = *this;
		--* this;
		return temp;
	}


	// assignments
	inline Vector10Wc& Vector10Wc::operator+= (const Vector10Wc& right) noexcept {
		cast(a += right.a); cast(b += right.b); cast(c += right.c); cast(d += right.d); cast(e += right.e); cast(f += right.f); cast(g += right.g); cast(h += right.h); cast(i += right.i); cast(j += right.j);
		return *this;
	}

	inline Vector10Wc& Vector10Wc::operator-= (const Vector10Wc& right) noexcept {
		cast(a -= right.a); cast(b -= right.b); cast(c -= right.c); cast(d -= right.d); cast(e -= right.e); cast(f -= right.f); cast(g -= right.g); cast(h -= right.h); cast(i -= right.i); cast(j -= right.j);
		return *this;
	}

	inline Vector10Wc& Vector10Wc::operator*= (const Vector10Wc& right) noexcept {
		cast(a *= right.a); cast(b *= right.b); cast(c *= right.c); cast(d *= right.d); cast(e *= right.e); cast(f *= right.f); cast(g *= right.g); cast(h *= right.h); cast(i *= right.i); cast(j *= right.j);
		return *this;
	}

	inline Vector10Wc& Vector10Wc::operator/= (const Vector10Wc& right) noexcept {
		cast(a /= right.a); cast(b /= right.b); cast(c /= right.c); cast(d /= right.d); cast(e /= right.e); cast(f /= right.f); cast(g /= right.g); cast(h /= right.h); cast(i /= right.i); cast(j /= right.j);
		return *this;
	}


	inline Vector10Wc& Vector10Wc::operator+= (const wchar_t& number) noexcept {
		cast(a += number); cast(b += number); cast(c += number); cast(d += number); cast(e += number); cast(f += number); cast(g += number); cast(h += number); cast(i += number); cast(j += number);
		return *this;
	}

	inline Vector10Wc& Vector10Wc::operator-= (const wchar_t& number) noexcept {
		cast(a -= number); cast(b -= number); cast(c -= number); cast(d -= number); cast(e -= number); cast(f -= number); cast(g -= number); cast(h -= number); cast(i -= number); cast(j -= number);
		return *this;
	}

	inline Vector10Wc& Vector10Wc::operator*= (const wchar_t& number) noexcept {
		cast(a *= number); cast(b *= number); cast(c *= number); cast(d *= number); cast(e *= number); cast(f *= number); cast(g *= number); cast(h *= number); cast(i *= number); cast(j *= number);
		return *this;
	}

	inline Vector10Wc& Vector10Wc::operator/= (const wchar_t& number) noexcept {
		cast(a /= number); cast(b /= number); cast(c /= number); cast(d /= number); cast(e /= number); cast(f /= number); cast(g /= number); cast(h /= number); cast(i /= number); cast(j /= number);
		return *this;
	}


	// less than / greater than
	inline bool Vector10Wc::operator< (const Vector10Wc& other) const noexcept {
		return a < other.a && b < other.b&& c < other.c&& d < other.d&& e < other.e&& f < other.f&& g < other.g&& h < other.h&& i < other.i&& j < other.j;
	}

	inline bool Vector10Wc::operator<= (const Vector10Wc& other) const noexcept {
		return a <= other.a && b <= other.b && c <= other.c && d <= other.d && e <= other.e && f <= other.f && g <= other.g && h <= other.h && i <= other.i && j <= other.j;
	}

	inline bool Vector10Wc::operator>  (const Vector10Wc& other) const noexcept {
		return a > other.a && b > other.b && c > other.c && d > other.d && e > other.e && f > other.f && g > other.g && h > other.h && i > other.i && j > other.j;
	}

	inline bool Vector10Wc::operator>= (const Vector10Wc& other) const noexcept {
		return a >= other.a && b >= other.b && c >= other.c && d >= other.d && e >= other.e && f >= other.f && g >= other.g && h >= other.h && i >= other.i && j >= other.j;
	}


	inline bool Vector10Wc::operator<  (const wchar_t& number) const noexcept {
		return a < number && b < number && c < number && d < number && e < number && f < number && g < number && h < number && i < number && j < number;
	}

	inline bool Vector10Wc::operator<= (const wchar_t& number) const noexcept {
		return a <= number && b <= number && c <= number && d <= number && e <= number && f <= number && g <= number && h <= number && i <= number && j <= number;
	}

	inline bool Vector10Wc::operator>  (const wchar_t& number) const noexcept {
		return a > number && b > number && c > number && d > number && e > number && f > number && g > number && h > number && i > number && j > number;
	}

	inline bool Vector10Wc::operator>= (const wchar_t& number) const noexcept {
		return a >= number && b >= number && c >= number && d >= number && e >= number && f >= number && g >= number && h >= number && i >= number && j >= number;
	}


	// equal / not equal
	inline bool Vector10Wc::operator==(const Vector10Wc& other) const noexcept {
		return a == other.a && b == other.b && c == other.c && d == other.d && e == other.e && f == other.f && g == other.g && h == other.h && i == other.i && j == other.j;
	}

	inline bool Vector10Wc::operator!=(const Vector10Wc& other) const noexcept {
		return a != other.a || b != other.b || c != other.c || d != other.d || e != other.e || f != other.f || g != other.g || h != other.h || i != other.i || j != other.j;
	}

	inline bool Vector10Wc::operator==(const wchar_t& number) const noexcept {
		return a == number && b == number && c == number && d == number && e == number && f == number && g == number && h == number && i == number && j == number;
	}

	inline bool Vector10Wc::operator!=(const wchar_t& number) const noexcept {
		return a != number || b != number || c != number || d != number || e != number || f != number || g != number || h != number || i != number || j != number;
	}


	inline constexpr std::uint8_t Vector10Wc::size() const noexcept { return 10; }
	inline void Vector10Wc::reset(const wchar_t& stnd_value) noexcept {
		for (std::uint8_t i = 0; i < size(); ++i)
			this->at(i) = stnd_value;
	}

	inline wchar_t& Vector10Wc::operator[](const std::uint8_t& index) noexcept {
		return at(index);
	}
	inline wchar_t& Vector10Wc::at(const std::uint8_t& index) noexcept
	{
		wchar_t* ptr = &a;
		if (index > 9)
			return ptr[0];
		return ptr[index];
	}
	// End
}