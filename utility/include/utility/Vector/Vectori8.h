#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::int8_t
		Bytes: 1
		Range: -128 to 127
	*/

	class Vector2i8
	{
	public:
		std::int8_t x, y;
	public:
		inline Vector2i8(const std::int8_t& x = 0, const std::int8_t& y = 0) noexcept;
		// copy
		inline Vector2i8(const Vector2i8& other) noexcept;
		inline Vector2i8& operator=(const Vector2i8& other) noexcept;
		// move
		inline Vector2i8(Vector2i8&& other) noexcept;
		inline Vector2i8& operator=(Vector2i8&& other) noexcept;
		// assignment
		inline Vector2i8& operator=(const std::int8_t& number) noexcept;

		// math operator
		inline Vector2i8 operator +(const Vector2i8& v) const noexcept;
		inline Vector2i8 operator -(const Vector2i8& v) const noexcept;
		inline Vector2i8 operator *(const Vector2i8& v) const noexcept;
		inline Vector2i8 operator /(const Vector2i8& v) const noexcept;

		inline Vector2i8 operator +(const std::int8_t& number) const noexcept;
		inline Vector2i8 operator -(const std::int8_t& number) const noexcept;
		inline Vector2i8 operator *(const std::int8_t& number) const noexcept;
		inline Vector2i8 operator /(const std::int8_t& number) const noexcept;

		// increment / decrement
		inline Vector2i8& operator++ () noexcept;		// prefix increment
		inline Vector2i8& operator-- () noexcept;		// prefix decrement
		inline Vector2i8  operator++ (int) noexcept;		// postfix increment
		inline Vector2i8  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2i8& operator+= (const Vector2i8& right) noexcept;
		inline Vector2i8& operator-= (const Vector2i8& right) noexcept;
		inline Vector2i8& operator*= (const Vector2i8& right) noexcept;
		inline Vector2i8& operator/= (const Vector2i8& right) noexcept;

		inline Vector2i8& operator+= (const std::int8_t& number) noexcept;
		inline Vector2i8& operator-= (const std::int8_t& number) noexcept;
		inline Vector2i8& operator*= (const std::int8_t& number) noexcept;
		inline Vector2i8& operator/= (const std::int8_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2i8& other) const noexcept;
		inline bool operator<=  (const Vector2i8& other) const noexcept;
		inline bool operator>	(const Vector2i8& other) const noexcept;
		inline bool operator>=  (const Vector2i8& other) const noexcept;

		inline bool operator<	(const std::int8_t& number) const noexcept;
		inline bool operator<=  (const std::int8_t& number) const noexcept;
		inline bool operator>	(const std::int8_t& number) const noexcept;
		inline bool operator>=  (const std::int8_t& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2i8& other) const noexcept;
		inline bool operator!=(const Vector2i8& other) const noexcept;
		inline bool operator==(const std::int8_t& number)  const noexcept;
		inline bool operator!=(const std::int8_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int8_t& stnd_value = 0) noexcept;
		inline std::int8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector3i8
	{
	public:
		std::int8_t x, y, z;
	public:
		inline Vector3i8(const std::int8_t& x = 0, const std::int8_t& y = 0, const std::int8_t& z = 0) noexcept;
		// copy
		inline Vector3i8(const Vector3i8& other) noexcept;
		inline Vector3i8& operator=(const Vector3i8& other) noexcept;
		// move
		inline Vector3i8(Vector3i8&& other) noexcept;
		inline Vector3i8& operator=(Vector3i8&& other) noexcept;
		// assignment
		inline Vector3i8& operator=(const std::int8_t& number) noexcept;

		// math operator
		inline Vector3i8 operator +(const Vector3i8& v) const noexcept;
		inline Vector3i8 operator -(const Vector3i8& v) const noexcept;
		inline Vector3i8 operator *(const Vector3i8& v) const noexcept;
		inline Vector3i8 operator /(const Vector3i8& v) const noexcept;

		inline Vector3i8 operator +(const std::int8_t& number) const noexcept;
		inline Vector3i8 operator -(const std::int8_t& number) const noexcept;
		inline Vector3i8 operator *(const std::int8_t& number) const noexcept;
		inline Vector3i8 operator /(const std::int8_t& number) const noexcept;

		// increment / decrement
		inline Vector3i8& operator++ () noexcept;		// prefix increment
		inline Vector3i8& operator-- () noexcept;		// prefix decrement
		inline Vector3i8  operator++ (int) noexcept;		// postfix increment
		inline Vector3i8  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3i8& operator+= (const Vector3i8& right) noexcept;
		inline Vector3i8& operator-= (const Vector3i8& right) noexcept;
		inline Vector3i8& operator*= (const Vector3i8& right) noexcept;
		inline Vector3i8& operator/= (const Vector3i8& right) noexcept;

		inline Vector3i8& operator+= (const std::int8_t& number) noexcept;
		inline Vector3i8& operator-= (const std::int8_t& number) noexcept;
		inline Vector3i8& operator*= (const std::int8_t& number) noexcept;
		inline Vector3i8& operator/= (const std::int8_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3i8& other) const noexcept;
		inline bool operator<=  (const Vector3i8& other) const noexcept;
		inline bool operator>	(const Vector3i8& other) const noexcept;
		inline bool operator>=  (const Vector3i8& other) const noexcept;
		 
		inline bool operator<	(const std::int8_t& number) const noexcept;
		inline bool operator<=  (const std::int8_t& number) const noexcept;
		inline bool operator>	(const std::int8_t& number) const noexcept;
		inline bool operator>=  (const std::int8_t& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3i8& other) const noexcept;
		inline bool operator!=(const Vector3i8& other) const noexcept;
		inline bool operator==(const std::int8_t& number)  const noexcept;
		inline bool operator!=(const std::int8_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int8_t& stnd_value = 0) noexcept;
		inline std::int8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector4i8
	{
	public:
		std::int8_t a, b, c, d;
	public:
		inline Vector4i8(const std::int8_t& a = 0, const std::int8_t& b = 0, const std::int8_t& c = 0, const std::int8_t& d = 0) noexcept;
		// copy
		inline Vector4i8(const Vector4i8& other) noexcept;
		inline Vector4i8& operator=(const Vector4i8& other) noexcept;
		// move
		inline Vector4i8(Vector4i8&& other) noexcept;
		inline Vector4i8& operator=(Vector4i8&& other) noexcept;
		// assignment
		inline Vector4i8& operator=(const std::int8_t& number) noexcept;
		
		// math operator
		inline Vector4i8 operator +(const Vector4i8& v) const noexcept;
		inline Vector4i8 operator -(const Vector4i8& v) const noexcept;
		inline Vector4i8 operator *(const Vector4i8& v) const noexcept;
		inline Vector4i8 operator /(const Vector4i8& v) const noexcept;
		
		inline Vector4i8 operator +(const std::int8_t& number) const noexcept;
		inline Vector4i8 operator -(const std::int8_t& number) const noexcept;
		inline Vector4i8 operator *(const std::int8_t& number) const noexcept;
		inline Vector4i8 operator /(const std::int8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector4i8& operator++ () noexcept;		// prefix increment
		inline Vector4i8& operator-- () noexcept;		// prefix decrement
		inline Vector4i8  operator++ (int) noexcept;		// postfix increment
		inline Vector4i8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4i8& operator+= (const Vector4i8& right) noexcept;
		inline Vector4i8& operator-= (const Vector4i8& right) noexcept;
		inline Vector4i8& operator*= (const Vector4i8& right) noexcept;
		inline Vector4i8& operator/= (const Vector4i8& right) noexcept;
		
		inline Vector4i8& operator+= (const std::int8_t& number) noexcept;
		inline Vector4i8& operator-= (const std::int8_t& number) noexcept;
		inline Vector4i8& operator*= (const std::int8_t& number) noexcept;
		inline Vector4i8& operator/= (const std::int8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4i8& other) const noexcept;
		inline bool operator<=  (const Vector4i8& other) const noexcept;
		inline bool operator>	(const Vector4i8& other) const noexcept;
		inline bool operator>=  (const Vector4i8& other) const noexcept;
		
		inline bool operator<	(const std::int8_t& number) const noexcept;
		inline bool operator<=  (const std::int8_t& number) const noexcept;
		inline bool operator>	(const std::int8_t& number) const noexcept;
		inline bool operator>=  (const std::int8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4i8& other) const noexcept;
		inline bool operator!=(const Vector4i8& other) const noexcept;
		inline bool operator==(const std::int8_t& number)  const noexcept;
		inline bool operator!=(const std::int8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int8_t& stnd_value = 0) noexcept;
		inline std::int8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector5i8
	{
	public:
		std::int8_t a, b, c, d, e;
	public:
		inline Vector5i8(const std::int8_t& a = 0, const std::int8_t& b = 0, const std::int8_t& c = 0, const std::int8_t& d = 0,
			const std::int8_t& e = 0) noexcept;
		// copy
		inline Vector5i8(const Vector5i8& other) noexcept;
		inline Vector5i8& operator=(const Vector5i8& other) noexcept;
		// move
		inline Vector5i8(Vector5i8&& other) noexcept;
		inline Vector5i8& operator=(Vector5i8&& other) noexcept;
		// assignment
		inline Vector5i8& operator=(const std::int8_t& number) noexcept;
		 
		// math operator
		inline Vector5i8 operator +(const Vector5i8& v) const noexcept;
		inline Vector5i8 operator -(const Vector5i8& v) const noexcept;
		inline Vector5i8 operator *(const Vector5i8& v) const noexcept;
		inline Vector5i8 operator /(const Vector5i8& v) const noexcept;
		
		inline Vector5i8 operator +(const std::int8_t& number) const noexcept;
		inline Vector5i8 operator -(const std::int8_t& number) const noexcept;
		inline Vector5i8 operator *(const std::int8_t& number) const noexcept;
		inline Vector5i8 operator /(const std::int8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector5i8& operator++ () noexcept;		// prefix increment
		inline Vector5i8& operator-- () noexcept;		// prefix decrement
		inline Vector5i8  operator++ (int) noexcept;		// postfix increment
		inline Vector5i8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5i8& operator+= (const Vector5i8& right) noexcept;
		inline Vector5i8& operator-= (const Vector5i8& right) noexcept;
		inline Vector5i8& operator*= (const Vector5i8& right) noexcept;
		inline Vector5i8& operator/= (const Vector5i8& right) noexcept;
		
		inline Vector5i8& operator+= (const std::int8_t& number) noexcept;
		inline Vector5i8& operator-= (const std::int8_t& number) noexcept;
		inline Vector5i8& operator*= (const std::int8_t& number) noexcept;
		inline Vector5i8& operator/= (const std::int8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5i8& other) const noexcept;
		inline bool operator<=  (const Vector5i8& other) const noexcept;
		inline bool operator>	(const Vector5i8& other) const noexcept;
		inline bool operator>=  (const Vector5i8& other) const noexcept;
		
		inline bool operator<	(const std::int8_t& number) const noexcept;
		inline bool operator<=  (const std::int8_t& number) const noexcept;
		inline bool operator>	(const std::int8_t& number) const noexcept;
		inline bool operator>=  (const std::int8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5i8& other) const noexcept;
		inline bool operator!=(const Vector5i8& other) const noexcept;
		inline bool operator==(const std::int8_t& number)  const noexcept;
		inline bool operator!=(const std::int8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int8_t& stnd_value = 0) noexcept;
		inline std::int8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector6i8
	{
	public:
		std::int8_t a, b, c, d, e, f;
	public:
		inline Vector6i8(const std::int8_t& a = 0, const std::int8_t& b = 0, const std::int8_t& c = 0, const std::int8_t& d = 0,
			const std::int8_t& e = 0, const std::int8_t& f = 0) noexcept;
		// copy
		inline Vector6i8(const Vector6i8& other) noexcept;
		inline Vector6i8& operator=(const Vector6i8& other) noexcept;
		// move
		inline Vector6i8(Vector6i8&& other) noexcept;
		inline Vector6i8& operator=(Vector6i8&& other) noexcept;
		// assignment
		inline Vector6i8& operator=(const std::int8_t& number) noexcept;
		
		// math operator
		inline Vector6i8 operator +(const Vector6i8& v) const noexcept;
		inline Vector6i8 operator -(const Vector6i8& v) const noexcept;
		inline Vector6i8 operator *(const Vector6i8& v) const noexcept;
		inline Vector6i8 operator /(const Vector6i8& v) const noexcept;
		
		inline Vector6i8 operator +(const std::int8_t& number) const noexcept;
		inline Vector6i8 operator -(const std::int8_t& number) const noexcept;
		inline Vector6i8 operator *(const std::int8_t& number) const noexcept;
		inline Vector6i8 operator /(const std::int8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector6i8& operator++ () noexcept;		// prefix increment
		inline Vector6i8& operator-- () noexcept;		// prefix decrement
		inline Vector6i8  operator++ (int) noexcept;		// postfix increment
		inline Vector6i8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6i8& operator+= (const Vector6i8& right) noexcept;
		inline Vector6i8& operator-= (const Vector6i8& right) noexcept;
		inline Vector6i8& operator*= (const Vector6i8& right) noexcept;
		inline Vector6i8& operator/= (const Vector6i8& right) noexcept;
		
		inline Vector6i8& operator+= (const std::int8_t& number) noexcept;
		inline Vector6i8& operator-= (const std::int8_t& number) noexcept;
		inline Vector6i8& operator*= (const std::int8_t& number) noexcept;
		inline Vector6i8& operator/= (const std::int8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6i8& other) const noexcept;
		inline bool operator<  (const Vector6i8& other) const noexcept;
		inline bool operator>  (const Vector6i8& other) const noexcept;
		inline bool operator>= (const Vector6i8& other) const noexcept;
		
		inline bool operator<  (const std::int8_t& number) const noexcept;
		inline bool operator<= (const std::int8_t& number) const noexcept;
		inline bool operator>  (const std::int8_t& number) const noexcept;
		inline bool operator>= (const std::int8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6i8& other) const noexcept;
		inline bool operator!=(const Vector6i8& other) const noexcept;
		inline bool operator==(const std::int8_t& number)  const noexcept;
		inline bool operator!=(const std::int8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int8_t& stnd_value = 0) noexcept;
		inline std::int8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector7i8
	{
	public:
		std::int8_t a, b, c, d, e, f, g;
	public:
		inline Vector7i8(const std::int8_t& a = 0, const std::int8_t& b = 0, const std::int8_t& c = 0, const std::int8_t& d = 0,
			const std::int8_t& e = 0, const std::int8_t& f = 0, const std::int8_t& g = 0) noexcept;
		// copy
		inline Vector7i8(const Vector7i8& other) noexcept;
		inline Vector7i8& operator=(const Vector7i8& other) noexcept;
		// move
		inline Vector7i8(Vector7i8&& other) noexcept;
		inline Vector7i8& operator=(Vector7i8&& other) noexcept;
		// assignment
		inline Vector7i8& operator=(const std::int8_t& number) noexcept;
		
		// math operator
		inline Vector7i8 operator +(const Vector7i8& v) const noexcept;
		inline Vector7i8 operator -(const Vector7i8& v) const noexcept;
		inline Vector7i8 operator *(const Vector7i8& v) const noexcept;
		inline Vector7i8 operator /(const Vector7i8& v) const noexcept;
		
		inline Vector7i8 operator +(const std::int8_t& number) const noexcept;
		inline Vector7i8 operator -(const std::int8_t& number) const noexcept;
		inline Vector7i8 operator *(const std::int8_t& number) const noexcept;
		inline Vector7i8 operator /(const std::int8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector7i8& operator++ () noexcept;		// prefix increment
		inline Vector7i8& operator-- () noexcept;		// prefix decrement
		inline Vector7i8  operator++ (int) noexcept;		// postfix increment
		inline Vector7i8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7i8& operator+= (const Vector7i8& right) noexcept;
		inline Vector7i8& operator-= (const Vector7i8& right) noexcept;
		inline Vector7i8& operator*= (const Vector7i8& right) noexcept;
		inline Vector7i8& operator/= (const Vector7i8& right) noexcept;
		
		inline Vector7i8& operator+= (const std::int8_t& number) noexcept;
		inline Vector7i8& operator-= (const std::int8_t& number) noexcept;
		inline Vector7i8& operator*= (const std::int8_t& number) noexcept;
		inline Vector7i8& operator/= (const std::int8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7i8& other) const noexcept;
		inline bool operator<  (const Vector7i8& other) const noexcept;
		inline bool operator>  (const Vector7i8& other) const noexcept;
		inline bool operator>= (const Vector7i8& other) const noexcept;
		
		inline bool operator<  (const std::int8_t& number) const noexcept;
		inline bool operator<= (const std::int8_t& number) const noexcept;
		inline bool operator>  (const std::int8_t& number) const noexcept;
		inline bool operator>= (const std::int8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7i8& other) const noexcept;
		inline bool operator!=(const Vector7i8& other) const noexcept;
		inline bool operator==(const std::int8_t& number)  const noexcept;
		inline bool operator!=(const std::int8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int8_t& stnd_value = 0) noexcept;
		inline std::int8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector8i8
	{
	public:
		std::int8_t a, b, c, d, e, f, g, h;
	public:
		inline Vector8i8(const std::int8_t& a = 0, const std::int8_t& b = 0, const std::int8_t& c = 0, const std::int8_t& d = 0,
			const std::int8_t& e = 0, const std::int8_t& f = 0, const std::int8_t& g = 0, const std::int8_t& h = 0) noexcept;
		// copy
		inline Vector8i8(const Vector8i8& other) noexcept;
		inline Vector8i8& operator=(const Vector8i8& other) noexcept;
		// move
		inline Vector8i8(Vector8i8&& other) noexcept;
		inline Vector8i8& operator=(Vector8i8&& other) noexcept;
		// assignment
		inline Vector8i8& operator=(const std::int8_t& number) noexcept;
		
		// math operator
		inline Vector8i8 operator +(const Vector8i8& v) const noexcept;
		inline Vector8i8 operator -(const Vector8i8& v) const noexcept;
		inline Vector8i8 operator *(const Vector8i8& v) const noexcept;
		inline Vector8i8 operator /(const Vector8i8& v) const noexcept;
		
		inline Vector8i8 operator +(const std::int8_t& number) const noexcept;
		inline Vector8i8 operator -(const std::int8_t& number) const noexcept;
		inline Vector8i8 operator *(const std::int8_t& number) const noexcept;
		inline Vector8i8 operator /(const std::int8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector8i8& operator++ () noexcept;		// prefix increment
		inline Vector8i8& operator-- () noexcept;		// prefix decrement
		inline Vector8i8  operator++ (int) noexcept;		// postfix increment
		inline Vector8i8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8i8& operator+= (const Vector8i8& right) noexcept;
		inline Vector8i8& operator-= (const Vector8i8& right) noexcept;
		inline Vector8i8& operator*= (const Vector8i8& right) noexcept;
		inline Vector8i8& operator/= (const Vector8i8& right) noexcept;
		
		inline Vector8i8& operator+= (const std::int8_t& number) noexcept;
		inline Vector8i8& operator-= (const std::int8_t& number) noexcept;
		inline Vector8i8& operator*= (const std::int8_t& number) noexcept;
		inline Vector8i8& operator/= (const std::int8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8i8& other) const noexcept;
		inline bool operator<  (const Vector8i8& other) const noexcept;
		inline bool operator>  (const Vector8i8& other) const noexcept;
		inline bool operator>= (const Vector8i8& other) const noexcept;
		
		inline bool operator<  (const std::int8_t& number) const noexcept;
		inline bool operator<= (const std::int8_t& number) const noexcept;
		inline bool operator>  (const std::int8_t& number) const noexcept;
		inline bool operator>= (const std::int8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8i8& other) const noexcept;
		inline bool operator!=(const Vector8i8& other) const noexcept;
		inline bool operator==(const std::int8_t& number)  const noexcept;
		inline bool operator!=(const std::int8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int8_t& stnd_value = 0) noexcept;
		inline std::int8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector9i8
	{
	public:
		std::int8_t a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9i8(const std::int8_t& a = 0, const std::int8_t& b = 0, const std::int8_t& c = 0, const std::int8_t& d = 0,
			const std::int8_t& e = 0, const std::int8_t& f = 0, const std::int8_t& g = 0, const std::int8_t& h = 0,
			const std::int8_t& i = 0) noexcept;
		// copy
		inline Vector9i8(const Vector9i8& other) noexcept;
		inline Vector9i8& operator=(const Vector9i8& other) noexcept;
		// move
		inline Vector9i8(Vector9i8&& other) noexcept;
		inline Vector9i8& operator=(Vector9i8&& other) noexcept;
		// assignment
		inline Vector9i8& operator=(const std::int8_t& number) noexcept;
		
		// math operator
		inline Vector9i8 operator +(const Vector9i8& v) const noexcept;
		inline Vector9i8 operator -(const Vector9i8& v) const noexcept;
		inline Vector9i8 operator *(const Vector9i8& v) const noexcept;
		inline Vector9i8 operator /(const Vector9i8& v) const noexcept;
		
		inline Vector9i8 operator +(const std::int8_t& number) const noexcept;
		inline Vector9i8 operator -(const std::int8_t& number) const noexcept;
		inline Vector9i8 operator *(const std::int8_t& number) const noexcept;
		inline Vector9i8 operator /(const std::int8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector9i8& operator++ () noexcept;		// prefix increment
		inline Vector9i8& operator-- () noexcept;		// prefix decrement
		inline Vector9i8  operator++ (int) noexcept;		// postfix increment
		inline Vector9i8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9i8& operator+= (const Vector9i8& right) noexcept;
		inline Vector9i8& operator-= (const Vector9i8& right) noexcept;
		inline Vector9i8& operator*= (const Vector9i8& right) noexcept;
		inline Vector9i8& operator/= (const Vector9i8& right) noexcept;
		
		inline Vector9i8& operator+= (const std::int8_t& number) noexcept;
		inline Vector9i8& operator-= (const std::int8_t& number) noexcept;
		inline Vector9i8& operator*= (const std::int8_t& number) noexcept;
		inline Vector9i8& operator/= (const std::int8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9i8& other) const noexcept;
		inline bool operator<  (const Vector9i8& other) const noexcept;
		inline bool operator>  (const Vector9i8& other) const noexcept;
		inline bool operator>= (const Vector9i8& other) const noexcept;
		
		inline bool operator<  (const std::int8_t& number) const noexcept;
		inline bool operator<= (const std::int8_t& number) const noexcept;
		inline bool operator>  (const std::int8_t& number) const noexcept;
		inline bool operator>= (const std::int8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9i8& other) const noexcept;
		inline bool operator!=(const Vector9i8& other) const noexcept;
		inline bool operator==(const std::int8_t& number)  const noexcept;
		inline bool operator!=(const std::int8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int8_t& stnd_value = 0) noexcept;
		inline std::int8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector10i8
	{
	public:
		std::int8_t a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10i8(const std::int8_t& a = 0, const std::int8_t& b = 0, const std::int8_t& c = 0, const std::int8_t& d = 0,
			const std::int8_t& e = 0, const std::int8_t& f = 0, const std::int8_t& g = 0, const std::int8_t& h = 0,
			const std::int8_t& i = 0, const std::int8_t& j = 0) noexcept;
		// copy
		inline Vector10i8(const Vector10i8& other) noexcept;
		inline Vector10i8& operator=(const Vector10i8& other) noexcept;
		// move
		inline Vector10i8(Vector10i8&& other) noexcept;
		inline Vector10i8& operator=(Vector10i8&& other) noexcept;
		// assignment
		inline Vector10i8& operator=(const std::int8_t& number) noexcept;
		
		// math operator
		inline Vector10i8 operator +(const Vector10i8& v) const noexcept;
		inline Vector10i8 operator -(const Vector10i8& v) const noexcept;
		inline Vector10i8 operator *(const Vector10i8& v) const noexcept;
		inline Vector10i8 operator /(const Vector10i8& v) const noexcept;
		
		inline Vector10i8 operator +(const std::int8_t& number) const noexcept;
		inline Vector10i8 operator -(const std::int8_t& number) const noexcept;
		inline Vector10i8 operator *(const std::int8_t& number) const noexcept;
		inline Vector10i8 operator /(const std::int8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector10i8& operator++ () noexcept;		// prefix increment
		inline Vector10i8& operator-- () noexcept;		// prefix decrement
		inline Vector10i8  operator++ (int) noexcept;	// postfix increment
		inline Vector10i8  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10i8& operator+= (const Vector10i8& right) noexcept;
		inline Vector10i8& operator-= (const Vector10i8& right) noexcept;
		inline Vector10i8& operator*= (const Vector10i8& right) noexcept;
		inline Vector10i8& operator/= (const Vector10i8& right) noexcept;
		
		inline Vector10i8& operator+= (const std::int8_t& number) noexcept;
		inline Vector10i8& operator-= (const std::int8_t& number) noexcept;
		inline Vector10i8& operator*= (const std::int8_t& number) noexcept;
		inline Vector10i8& operator/= (const std::int8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10i8& other) const noexcept;
		inline bool operator<  (const Vector10i8& other) const noexcept;
		inline bool operator>  (const Vector10i8& other) const noexcept;
		inline bool operator>= (const Vector10i8& other) const noexcept;

		inline bool operator<  (const std::int8_t& number) const noexcept;
		inline bool operator<= (const std::int8_t& number) const noexcept;
		inline bool operator>  (const std::int8_t& number) const noexcept;
		inline bool operator>= (const std::int8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10i8& other) const noexcept;
		inline bool operator!=(const Vector10i8& other) const noexcept;
		inline bool operator==(const std::int8_t& number)   const noexcept;
		inline bool operator!=(const std::int8_t& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int8_t& stnd_value = 0) noexcept;
		inline std::int8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int8_t& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2i8& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3i8& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4i8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5i8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6i8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7i8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8i8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9i8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10i8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}