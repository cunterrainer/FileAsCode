#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : unsigned long
		Bytes: 4
		Range: 0 to 4.294.967.295
	*/

	class Vector2Ul
	{
	public:
		unsigned long x, y;
	public:
		inline Vector2Ul(const unsigned long& x = 0Ul, const unsigned long& y = 0Ul) noexcept;
		// copy
		inline Vector2Ul(const Vector2Ul& other) noexcept;
		inline Vector2Ul& operator=(const Vector2Ul& other) noexcept;
		// move
		inline Vector2Ul(Vector2Ul&& other) noexcept;
		inline Vector2Ul& operator=(Vector2Ul&& other) noexcept;
		// assignment
		inline Vector2Ul& operator=(const unsigned long& number) noexcept;

		// math operator
		inline Vector2Ul operator +(const Vector2Ul& v) const noexcept;
		inline Vector2Ul operator -(const Vector2Ul& v) const noexcept;
		inline Vector2Ul operator *(const Vector2Ul& v) const noexcept;
		inline Vector2Ul operator /(const Vector2Ul& v) const noexcept;

		inline Vector2Ul operator +(const unsigned long& number) const noexcept;
		inline Vector2Ul operator -(const unsigned long& number) const noexcept;
		inline Vector2Ul operator *(const unsigned long& number) const noexcept;
		inline Vector2Ul operator /(const unsigned long& number) const noexcept;

		// increment / decrement
		inline Vector2Ul& operator++ () noexcept;		// prefix increment
		inline Vector2Ul& operator-- () noexcept;		// prefix decrement
		inline Vector2Ul  operator++ (int) noexcept;		// postfix increment
		inline Vector2Ul  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2Ul& operator+= (const Vector2Ul& right) noexcept;
		inline Vector2Ul& operator-= (const Vector2Ul& right) noexcept;
		inline Vector2Ul& operator*= (const Vector2Ul& right) noexcept;
		inline Vector2Ul& operator/= (const Vector2Ul& right) noexcept;

		inline Vector2Ul& operator+= (const unsigned long& number) noexcept;
		inline Vector2Ul& operator-= (const unsigned long& number) noexcept;
		inline Vector2Ul& operator*= (const unsigned long& number) noexcept;
		inline Vector2Ul& operator/= (const unsigned long& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2Ul& other) const noexcept;
		inline bool operator<=  (const Vector2Ul& other) const noexcept;
		inline bool operator>	(const Vector2Ul& other) const noexcept;
		inline bool operator>=  (const Vector2Ul& other) const noexcept;

		inline bool operator<	(const unsigned long& number) const noexcept;
		inline bool operator<=  (const unsigned long& number) const noexcept;
		inline bool operator>	(const unsigned long& number) const noexcept;
		inline bool operator>=  (const unsigned long& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2Ul& other) const noexcept;
		inline bool operator!=(const Vector2Ul& other) const noexcept;
		inline bool operator==(const unsigned long& number)  const noexcept;
		inline bool operator!=(const unsigned long& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const unsigned long& stnd_value = 0Ul) noexcept;
		inline unsigned long& operator[](const std::uint8_t& index) noexcept;
		inline unsigned long& at(const std::uint8_t& index) noexcept;
	};


	class Vector3Ul
	{
	public:
		unsigned long x, y, z;
	public:
		inline Vector3Ul(const unsigned long& x = 0Ul, const unsigned long& y = 0Ul, const unsigned long& z = 0Ul) noexcept;
		// copy
		inline Vector3Ul(const Vector3Ul& other) noexcept;
		inline Vector3Ul& operator=(const Vector3Ul& other) noexcept;
		// move
		inline Vector3Ul(Vector3Ul&& other) noexcept;
		inline Vector3Ul& operator=(Vector3Ul&& other) noexcept;
		// assignment
		inline Vector3Ul& operator=(const unsigned long& number) noexcept;

		// math operator
		inline Vector3Ul operator +(const Vector3Ul& v) const noexcept;
		inline Vector3Ul operator -(const Vector3Ul& v) const noexcept;
		inline Vector3Ul operator *(const Vector3Ul& v) const noexcept;
		inline Vector3Ul operator /(const Vector3Ul& v) const noexcept;

		inline Vector3Ul operator +(const unsigned long& number) const noexcept;
		inline Vector3Ul operator -(const unsigned long& number) const noexcept;
		inline Vector3Ul operator *(const unsigned long& number) const noexcept;
		inline Vector3Ul operator /(const unsigned long& number) const noexcept;

		// increment / decrement
		inline Vector3Ul& operator++ () noexcept;		// prefix increment
		inline Vector3Ul& operator-- () noexcept;		// prefix decrement
		inline Vector3Ul  operator++ (int) noexcept;		// postfix increment
		inline Vector3Ul  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3Ul& operator+= (const Vector3Ul& right) noexcept;
		inline Vector3Ul& operator-= (const Vector3Ul& right) noexcept;
		inline Vector3Ul& operator*= (const Vector3Ul& right) noexcept;
		inline Vector3Ul& operator/= (const Vector3Ul& right) noexcept;

		inline Vector3Ul& operator+= (const unsigned long& number) noexcept;
		inline Vector3Ul& operator-= (const unsigned long& number) noexcept;
		inline Vector3Ul& operator*= (const unsigned long& number) noexcept;
		inline Vector3Ul& operator/= (const unsigned long& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3Ul& other) const noexcept;
		inline bool operator<=  (const Vector3Ul& other) const noexcept;
		inline bool operator>	(const Vector3Ul& other) const noexcept;
		inline bool operator>=  (const Vector3Ul& other) const noexcept;
		 
		inline bool operator<	(const unsigned long& number) const noexcept;
		inline bool operator<=  (const unsigned long& number) const noexcept;
		inline bool operator>	(const unsigned long& number) const noexcept;
		inline bool operator>=  (const unsigned long& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3Ul& other) const noexcept;
		inline bool operator!=(const Vector3Ul& other) const noexcept;
		inline bool operator==(const unsigned long& number)  const noexcept;
		inline bool operator!=(const unsigned long& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const unsigned long& stnd_value = 0Ul) noexcept;
		inline unsigned long& operator[](const std::uint8_t& index) noexcept;
		inline unsigned long& at(const std::uint8_t& index) noexcept;
	};


	class Vector4Ul
	{
	public:
		unsigned long a, b, c, d;
	public:
		inline Vector4Ul(const unsigned long& a = 0Ul, const unsigned long& b = 0Ul, const unsigned long& c = 0Ul, const unsigned long& d = 0Ul) noexcept;
		// copy
		inline Vector4Ul(const Vector4Ul& other) noexcept;
		inline Vector4Ul& operator=(const Vector4Ul& other) noexcept;
		// move
		inline Vector4Ul(Vector4Ul&& other) noexcept;
		inline Vector4Ul& operator=(Vector4Ul&& other) noexcept;
		// assignment
		inline Vector4Ul& operator=(const unsigned long& number) noexcept;
		
		// math operator
		inline Vector4Ul operator +(const Vector4Ul& v) const noexcept;
		inline Vector4Ul operator -(const Vector4Ul& v) const noexcept;
		inline Vector4Ul operator *(const Vector4Ul& v) const noexcept;
		inline Vector4Ul operator /(const Vector4Ul& v) const noexcept;
		
		inline Vector4Ul operator +(const unsigned long& number) const noexcept;
		inline Vector4Ul operator -(const unsigned long& number) const noexcept;
		inline Vector4Ul operator *(const unsigned long& number) const noexcept;
		inline Vector4Ul operator /(const unsigned long& number) const noexcept;
		
		// increment / decrement
		inline Vector4Ul& operator++ () noexcept;		// prefix increment
		inline Vector4Ul& operator-- () noexcept;		// prefix decrement
		inline Vector4Ul  operator++ (int) noexcept;		// postfix increment
		inline Vector4Ul  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4Ul& operator+= (const Vector4Ul& right) noexcept;
		inline Vector4Ul& operator-= (const Vector4Ul& right) noexcept;
		inline Vector4Ul& operator*= (const Vector4Ul& right) noexcept;
		inline Vector4Ul& operator/= (const Vector4Ul& right) noexcept;
		
		inline Vector4Ul& operator+= (const unsigned long& number) noexcept;
		inline Vector4Ul& operator-= (const unsigned long& number) noexcept;
		inline Vector4Ul& operator*= (const unsigned long& number) noexcept;
		inline Vector4Ul& operator/= (const unsigned long& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4Ul& other) const noexcept;
		inline bool operator<=  (const Vector4Ul& other) const noexcept;
		inline bool operator>	(const Vector4Ul& other) const noexcept;
		inline bool operator>=  (const Vector4Ul& other) const noexcept;
		
		inline bool operator<	(const unsigned long& number) const noexcept;
		inline bool operator<=  (const unsigned long& number) const noexcept;
		inline bool operator>	(const unsigned long& number) const noexcept;
		inline bool operator>=  (const unsigned long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4Ul& other) const noexcept;
		inline bool operator!=(const Vector4Ul& other) const noexcept;
		inline bool operator==(const unsigned long& number)  const noexcept;
		inline bool operator!=(const unsigned long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const unsigned long& stnd_value = 0Ul) noexcept;
		inline unsigned long& operator[](const std::uint8_t& index) noexcept;
		inline unsigned long& at(const std::uint8_t& index) noexcept;
	};


	class Vector5Ul
	{
	public:
		unsigned long a, b, c, d, e;
	public:
		inline Vector5Ul(const unsigned long& a = 0Ul, const unsigned long& b = 0Ul, const unsigned long& c = 0Ul, const unsigned long& d = 0Ul,
			const unsigned long& e = 0Ul) noexcept;
		// copy
		inline Vector5Ul(const Vector5Ul& other) noexcept;
		inline Vector5Ul& operator=(const Vector5Ul& other) noexcept;
		// move
		inline Vector5Ul(Vector5Ul&& other) noexcept;
		inline Vector5Ul& operator=(Vector5Ul&& other) noexcept;
		// assignment
		inline Vector5Ul& operator=(const unsigned long& number) noexcept;
		 
		// math operator
		inline Vector5Ul operator +(const Vector5Ul& v) const noexcept;
		inline Vector5Ul operator -(const Vector5Ul& v) const noexcept;
		inline Vector5Ul operator *(const Vector5Ul& v) const noexcept;
		inline Vector5Ul operator /(const Vector5Ul& v) const noexcept;
		
		inline Vector5Ul operator +(const unsigned long& number) const noexcept;
		inline Vector5Ul operator -(const unsigned long& number) const noexcept;
		inline Vector5Ul operator *(const unsigned long& number) const noexcept;
		inline Vector5Ul operator /(const unsigned long& number) const noexcept;
		
		// increment / decrement
		inline Vector5Ul& operator++ () noexcept;		// prefix increment
		inline Vector5Ul& operator-- () noexcept;		// prefix decrement
		inline Vector5Ul  operator++ (int) noexcept;		// postfix increment
		inline Vector5Ul  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5Ul& operator+= (const Vector5Ul& right) noexcept;
		inline Vector5Ul& operator-= (const Vector5Ul& right) noexcept;
		inline Vector5Ul& operator*= (const Vector5Ul& right) noexcept;
		inline Vector5Ul& operator/= (const Vector5Ul& right) noexcept;
		
		inline Vector5Ul& operator+= (const unsigned long& number) noexcept;
		inline Vector5Ul& operator-= (const unsigned long& number) noexcept;
		inline Vector5Ul& operator*= (const unsigned long& number) noexcept;
		inline Vector5Ul& operator/= (const unsigned long& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5Ul& other) const noexcept;
		inline bool operator<=  (const Vector5Ul& other) const noexcept;
		inline bool operator>	(const Vector5Ul& other) const noexcept;
		inline bool operator>=  (const Vector5Ul& other) const noexcept;
		
		inline bool operator<	(const unsigned long& number) const noexcept;
		inline bool operator<=  (const unsigned long& number) const noexcept;
		inline bool operator>	(const unsigned long& number) const noexcept;
		inline bool operator>=  (const unsigned long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5Ul& other) const noexcept;
		inline bool operator!=(const Vector5Ul& other) const noexcept;
		inline bool operator==(const unsigned long& number)  const noexcept;
		inline bool operator!=(const unsigned long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const unsigned long& stnd_value = 0Ul) noexcept;
		inline unsigned long& operator[](const std::uint8_t& index) noexcept;
		inline unsigned long& at(const std::uint8_t& index) noexcept;
	};


	class Vector6Ul
	{
	public:
		unsigned long a, b, c, d, e, f;
	public:
		inline Vector6Ul(const unsigned long& a = 0Ul, const unsigned long& b = 0Ul, const unsigned long& c = 0Ul, const unsigned long& d = 0Ul,
			const unsigned long& e = 0Ul, const unsigned long& f = 0Ul) noexcept;
		// copy
		inline Vector6Ul(const Vector6Ul& other) noexcept;
		inline Vector6Ul& operator=(const Vector6Ul& other) noexcept;
		// move
		inline Vector6Ul(Vector6Ul&& other) noexcept;
		inline Vector6Ul& operator=(Vector6Ul&& other) noexcept;
		// assignment
		inline Vector6Ul& operator=(const unsigned long& number) noexcept;
		
		// math operator
		inline Vector6Ul operator +(const Vector6Ul& v) const noexcept;
		inline Vector6Ul operator -(const Vector6Ul& v) const noexcept;
		inline Vector6Ul operator *(const Vector6Ul& v) const noexcept;
		inline Vector6Ul operator /(const Vector6Ul& v) const noexcept;
		
		inline Vector6Ul operator +(const unsigned long& number) const noexcept;
		inline Vector6Ul operator -(const unsigned long& number) const noexcept;
		inline Vector6Ul operator *(const unsigned long& number) const noexcept;
		inline Vector6Ul operator /(const unsigned long& number) const noexcept;
		
		// increment / decrement
		inline Vector6Ul& operator++ () noexcept;		// prefix increment
		inline Vector6Ul& operator-- () noexcept;		// prefix decrement
		inline Vector6Ul  operator++ (int) noexcept;		// postfix increment
		inline Vector6Ul  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6Ul& operator+= (const Vector6Ul& right) noexcept;
		inline Vector6Ul& operator-= (const Vector6Ul& right) noexcept;
		inline Vector6Ul& operator*= (const Vector6Ul& right) noexcept;
		inline Vector6Ul& operator/= (const Vector6Ul& right) noexcept;
		
		inline Vector6Ul& operator+= (const unsigned long& number) noexcept;
		inline Vector6Ul& operator-= (const unsigned long& number) noexcept;
		inline Vector6Ul& operator*= (const unsigned long& number) noexcept;
		inline Vector6Ul& operator/= (const unsigned long& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6Ul& other) const noexcept;
		inline bool operator<  (const Vector6Ul& other) const noexcept;
		inline bool operator>  (const Vector6Ul& other) const noexcept;
		inline bool operator>= (const Vector6Ul& other) const noexcept;
		
		inline bool operator<  (const unsigned long& number) const noexcept;
		inline bool operator<= (const unsigned long& number) const noexcept;
		inline bool operator>  (const unsigned long& number) const noexcept;
		inline bool operator>= (const unsigned long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6Ul& other) const noexcept;
		inline bool operator!=(const Vector6Ul& other) const noexcept;
		inline bool operator==(const unsigned long& number)  const noexcept;
		inline bool operator!=(const unsigned long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const unsigned long& stnd_value = 0Ul) noexcept;
		inline unsigned long& operator[](const std::uint8_t& index) noexcept;
		inline unsigned long& at(const std::uint8_t& index) noexcept;
	};


	class Vector7Ul
	{
	public:
		unsigned long a, b, c, d, e, f, g;
	public:
		inline Vector7Ul(const unsigned long& a = 0Ul, const unsigned long& b = 0Ul, const unsigned long& c = 0Ul, const unsigned long& d = 0Ul,
			const unsigned long& e = 0Ul, const unsigned long& f = 0Ul, const unsigned long& g = 0Ul) noexcept;
		// copy
		inline Vector7Ul(const Vector7Ul& other) noexcept;
		inline Vector7Ul& operator=(const Vector7Ul& other) noexcept;
		// move
		inline Vector7Ul(Vector7Ul&& other) noexcept;
		inline Vector7Ul& operator=(Vector7Ul&& other) noexcept;
		// assignment
		inline Vector7Ul& operator=(const unsigned long& number) noexcept;
		
		// math operator
		inline Vector7Ul operator +(const Vector7Ul& v) const noexcept;
		inline Vector7Ul operator -(const Vector7Ul& v) const noexcept;
		inline Vector7Ul operator *(const Vector7Ul& v) const noexcept;
		inline Vector7Ul operator /(const Vector7Ul& v) const noexcept;
		
		inline Vector7Ul operator +(const unsigned long& number) const noexcept;
		inline Vector7Ul operator -(const unsigned long& number) const noexcept;
		inline Vector7Ul operator *(const unsigned long& number) const noexcept;
		inline Vector7Ul operator /(const unsigned long& number) const noexcept;
		
		// increment / decrement
		inline Vector7Ul& operator++ () noexcept;		// prefix increment
		inline Vector7Ul& operator-- () noexcept;		// prefix decrement
		inline Vector7Ul  operator++ (int) noexcept;		// postfix increment
		inline Vector7Ul  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7Ul& operator+= (const Vector7Ul& right) noexcept;
		inline Vector7Ul& operator-= (const Vector7Ul& right) noexcept;
		inline Vector7Ul& operator*= (const Vector7Ul& right) noexcept;
		inline Vector7Ul& operator/= (const Vector7Ul& right) noexcept;
		
		inline Vector7Ul& operator+= (const unsigned long& number) noexcept;
		inline Vector7Ul& operator-= (const unsigned long& number) noexcept;
		inline Vector7Ul& operator*= (const unsigned long& number) noexcept;
		inline Vector7Ul& operator/= (const unsigned long& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7Ul& other) const noexcept;
		inline bool operator<  (const Vector7Ul& other) const noexcept;
		inline bool operator>  (const Vector7Ul& other) const noexcept;
		inline bool operator>= (const Vector7Ul& other) const noexcept;
		
		inline bool operator<  (const unsigned long& number) const noexcept;
		inline bool operator<= (const unsigned long& number) const noexcept;
		inline bool operator>  (const unsigned long& number) const noexcept;
		inline bool operator>= (const unsigned long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7Ul& other) const noexcept;
		inline bool operator!=(const Vector7Ul& other) const noexcept;
		inline bool operator==(const unsigned long& number)  const noexcept;
		inline bool operator!=(const unsigned long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const unsigned long& stnd_value = 0Ul) noexcept;
		inline unsigned long& operator[](const std::uint8_t& index) noexcept;
		inline unsigned long& at(const std::uint8_t& index) noexcept;
	};


	class Vector8Ul
	{
	public:
		unsigned long a, b, c, d, e, f, g, h;
	public:
		inline Vector8Ul(const unsigned long& a = 0Ul, const unsigned long& b = 0Ul, const unsigned long& c = 0Ul, const unsigned long& d = 0Ul,
			const unsigned long& e = 0Ul, const unsigned long& f = 0Ul, const unsigned long& g = 0Ul, const unsigned long& h = 0Ul) noexcept;
		// copy
		inline Vector8Ul(const Vector8Ul& other) noexcept;
		inline Vector8Ul& operator=(const Vector8Ul& other) noexcept;
		// move
		inline Vector8Ul(Vector8Ul&& other) noexcept;
		inline Vector8Ul& operator=(Vector8Ul&& other) noexcept;
		// assignment
		inline Vector8Ul& operator=(const unsigned long& number) noexcept;
		
		// math operator
		inline Vector8Ul operator +(const Vector8Ul& v) const noexcept;
		inline Vector8Ul operator -(const Vector8Ul& v) const noexcept;
		inline Vector8Ul operator *(const Vector8Ul& v) const noexcept;
		inline Vector8Ul operator /(const Vector8Ul& v) const noexcept;
		
		inline Vector8Ul operator +(const unsigned long& number) const noexcept;
		inline Vector8Ul operator -(const unsigned long& number) const noexcept;
		inline Vector8Ul operator *(const unsigned long& number) const noexcept;
		inline Vector8Ul operator /(const unsigned long& number) const noexcept;
		
		// increment / decrement
		inline Vector8Ul& operator++ () noexcept;		// prefix increment
		inline Vector8Ul& operator-- () noexcept;		// prefix decrement
		inline Vector8Ul  operator++ (int) noexcept;		// postfix increment
		inline Vector8Ul  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8Ul& operator+= (const Vector8Ul& right) noexcept;
		inline Vector8Ul& operator-= (const Vector8Ul& right) noexcept;
		inline Vector8Ul& operator*= (const Vector8Ul& right) noexcept;
		inline Vector8Ul& operator/= (const Vector8Ul& right) noexcept;
		
		inline Vector8Ul& operator+= (const unsigned long& number) noexcept;
		inline Vector8Ul& operator-= (const unsigned long& number) noexcept;
		inline Vector8Ul& operator*= (const unsigned long& number) noexcept;
		inline Vector8Ul& operator/= (const unsigned long& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8Ul& other) const noexcept;
		inline bool operator<  (const Vector8Ul& other) const noexcept;
		inline bool operator>  (const Vector8Ul& other) const noexcept;
		inline bool operator>= (const Vector8Ul& other) const noexcept;
		
		inline bool operator<  (const unsigned long& number) const noexcept;
		inline bool operator<= (const unsigned long& number) const noexcept;
		inline bool operator>  (const unsigned long& number) const noexcept;
		inline bool operator>= (const unsigned long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8Ul& other) const noexcept;
		inline bool operator!=(const Vector8Ul& other) const noexcept;
		inline bool operator==(const unsigned long& number)  const noexcept;
		inline bool operator!=(const unsigned long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const unsigned long& stnd_value = 0Ul) noexcept;
		inline unsigned long& operator[](const std::uint8_t& index) noexcept;
		inline unsigned long& at(const std::uint8_t& index) noexcept;
	};


	class Vector9Ul
	{
	public:
		unsigned long a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9Ul(const unsigned long& a = 0Ul, const unsigned long& b = 0Ul, const unsigned long& c = 0Ul, const unsigned long& d = 0Ul,
			const unsigned long& e = 0Ul, const unsigned long& f = 0Ul, const unsigned long& g = 0Ul, const unsigned long& h = 0Ul,
			const unsigned long& i = 0Ul) noexcept;
		// copy
		inline Vector9Ul(const Vector9Ul& other) noexcept;
		inline Vector9Ul& operator=(const Vector9Ul& other) noexcept;
		// move
		inline Vector9Ul(Vector9Ul&& other) noexcept;
		inline Vector9Ul& operator=(Vector9Ul&& other) noexcept;
		// assignment
		inline Vector9Ul& operator=(const unsigned long& number) noexcept;
		
		// math operator
		inline Vector9Ul operator +(const Vector9Ul& v) const noexcept;
		inline Vector9Ul operator -(const Vector9Ul& v) const noexcept;
		inline Vector9Ul operator *(const Vector9Ul& v) const noexcept;
		inline Vector9Ul operator /(const Vector9Ul& v) const noexcept;
		
		inline Vector9Ul operator +(const unsigned long& number) const noexcept;
		inline Vector9Ul operator -(const unsigned long& number) const noexcept;
		inline Vector9Ul operator *(const unsigned long& number) const noexcept;
		inline Vector9Ul operator /(const unsigned long& number) const noexcept;
		
		// increment / decrement
		inline Vector9Ul& operator++ () noexcept;		// prefix increment
		inline Vector9Ul& operator-- () noexcept;		// prefix decrement
		inline Vector9Ul  operator++ (int) noexcept;		// postfix increment
		inline Vector9Ul  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9Ul& operator+= (const Vector9Ul& right) noexcept;
		inline Vector9Ul& operator-= (const Vector9Ul& right) noexcept;
		inline Vector9Ul& operator*= (const Vector9Ul& right) noexcept;
		inline Vector9Ul& operator/= (const Vector9Ul& right) noexcept;
		
		inline Vector9Ul& operator+= (const unsigned long& number) noexcept;
		inline Vector9Ul& operator-= (const unsigned long& number) noexcept;
		inline Vector9Ul& operator*= (const unsigned long& number) noexcept;
		inline Vector9Ul& operator/= (const unsigned long& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9Ul& other) const noexcept;
		inline bool operator<  (const Vector9Ul& other) const noexcept;
		inline bool operator>  (const Vector9Ul& other) const noexcept;
		inline bool operator>= (const Vector9Ul& other) const noexcept;
		
		inline bool operator<  (const unsigned long& number) const noexcept;
		inline bool operator<= (const unsigned long& number) const noexcept;
		inline bool operator>  (const unsigned long& number) const noexcept;
		inline bool operator>= (const unsigned long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9Ul& other) const noexcept;
		inline bool operator!=(const Vector9Ul& other) const noexcept;
		inline bool operator==(const unsigned long& number)  const noexcept;
		inline bool operator!=(const unsigned long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const unsigned long& stnd_value = 0Ul) noexcept;
		inline unsigned long& operator[](const std::uint8_t& index) noexcept;
		inline unsigned long& at(const std::uint8_t& index) noexcept;
	};


	class Vector10Ul
	{
	public:
		unsigned long a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10Ul(const unsigned long& a = 0Ul, const unsigned long& b = 0Ul, const unsigned long& c = 0Ul, const unsigned long& d = 0Ul,
			const unsigned long& e = 0Ul, const unsigned long& f = 0Ul, const unsigned long& g = 0Ul, const unsigned long& h = 0Ul,
			const unsigned long& i = 0Ul, const unsigned long& j = 0Ul) noexcept;
		// copy
		inline Vector10Ul(const Vector10Ul& other) noexcept;
		inline Vector10Ul& operator=(const Vector10Ul& other) noexcept;
		// move
		inline Vector10Ul(Vector10Ul&& other) noexcept;
		inline Vector10Ul& operator=(Vector10Ul&& other) noexcept;
		// assignment
		inline Vector10Ul& operator=(const unsigned long& number) noexcept;
		
		// math operator
		inline Vector10Ul operator +(const Vector10Ul& v) const noexcept;
		inline Vector10Ul operator -(const Vector10Ul& v) const noexcept;
		inline Vector10Ul operator *(const Vector10Ul& v) const noexcept;
		inline Vector10Ul operator /(const Vector10Ul& v) const noexcept;
		
		inline Vector10Ul operator +(const unsigned long& number) const noexcept;
		inline Vector10Ul operator -(const unsigned long& number) const noexcept;
		inline Vector10Ul operator *(const unsigned long& number) const noexcept;
		inline Vector10Ul operator /(const unsigned long& number) const noexcept;
		
		// increment / decrement
		inline Vector10Ul& operator++ () noexcept;		// prefix increment
		inline Vector10Ul& operator-- () noexcept;		// prefix decrement
		inline Vector10Ul  operator++ (int) noexcept;	// postfix increment
		inline Vector10Ul  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10Ul& operator+= (const Vector10Ul& right) noexcept;
		inline Vector10Ul& operator-= (const Vector10Ul& right) noexcept;
		inline Vector10Ul& operator*= (const Vector10Ul& right) noexcept;
		inline Vector10Ul& operator/= (const Vector10Ul& right) noexcept;
		
		inline Vector10Ul& operator+= (const unsigned long& number) noexcept;
		inline Vector10Ul& operator-= (const unsigned long& number) noexcept;
		inline Vector10Ul& operator*= (const unsigned long& number) noexcept;
		inline Vector10Ul& operator/= (const unsigned long& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10Ul& other) const noexcept;
		inline bool operator<  (const Vector10Ul& other) const noexcept;
		inline bool operator>  (const Vector10Ul& other) const noexcept;
		inline bool operator>= (const Vector10Ul& other) const noexcept;

		inline bool operator<  (const unsigned long& number) const noexcept;
		inline bool operator<= (const unsigned long& number) const noexcept;
		inline bool operator>  (const unsigned long& number) const noexcept;
		inline bool operator>= (const unsigned long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10Ul& other) const noexcept;
		inline bool operator!=(const Vector10Ul& other) const noexcept;
		inline bool operator==(const unsigned long& number)   const noexcept;
		inline bool operator!=(const unsigned long& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const unsigned long& stnd_value = 0Ul) noexcept;
		inline unsigned long& operator[](const std::uint8_t& index) noexcept;
		inline unsigned long& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2Ul& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3Ul& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4Ul& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5Ul& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6Ul& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7Ul& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8Ul& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9Ul& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10Ul& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}