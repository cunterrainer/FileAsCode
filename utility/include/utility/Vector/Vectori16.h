#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::int16_t
		Bytes: 2
		Range: -32.768 to 32.767
	*/

	class Vector2i16
	{
	public:
		std::int16_t x, y;
	public:
		inline Vector2i16(const std::int16_t& x = 0, const std::int16_t& y = 0) noexcept;
		// copy
		inline Vector2i16(const Vector2i16& other) noexcept;
		inline Vector2i16& operator=(const Vector2i16& other) noexcept;
		// move
		inline Vector2i16(Vector2i16&& other) noexcept;
		inline Vector2i16& operator=(Vector2i16&& other) noexcept;
		// assignment
		inline Vector2i16& operator=(const std::int16_t& number) noexcept;

		// math operator
		inline Vector2i16 operator +(const Vector2i16& v) const noexcept;
		inline Vector2i16 operator -(const Vector2i16& v) const noexcept;
		inline Vector2i16 operator *(const Vector2i16& v) const noexcept;
		inline Vector2i16 operator /(const Vector2i16& v) const noexcept;

		inline Vector2i16 operator +(const std::int16_t& number) const noexcept;
		inline Vector2i16 operator -(const std::int16_t& number) const noexcept;
		inline Vector2i16 operator *(const std::int16_t& number) const noexcept;
		inline Vector2i16 operator /(const std::int16_t& number) const noexcept;

		// increment / decrement
		inline Vector2i16& operator++ () noexcept;		// prefix increment
		inline Vector2i16& operator-- () noexcept;		// prefix decrement
		inline Vector2i16  operator++ (int) noexcept;		// postfix increment
		inline Vector2i16  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2i16& operator+= (const Vector2i16& right) noexcept;
		inline Vector2i16& operator-= (const Vector2i16& right) noexcept;
		inline Vector2i16& operator*= (const Vector2i16& right) noexcept;
		inline Vector2i16& operator/= (const Vector2i16& right) noexcept;

		inline Vector2i16& operator+= (const std::int16_t& number) noexcept;
		inline Vector2i16& operator-= (const std::int16_t& number) noexcept;
		inline Vector2i16& operator*= (const std::int16_t& number) noexcept;
		inline Vector2i16& operator/= (const std::int16_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2i16& other) const noexcept;
		inline bool operator<=  (const Vector2i16& other) const noexcept;
		inline bool operator>	(const Vector2i16& other) const noexcept;
		inline bool operator>=  (const Vector2i16& other) const noexcept;

		inline bool operator<	(const std::int16_t& number) const noexcept;
		inline bool operator<=  (const std::int16_t& number) const noexcept;
		inline bool operator>	(const std::int16_t& number) const noexcept;
		inline bool operator>=  (const std::int16_t& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2i16& other) const noexcept;
		inline bool operator!=(const Vector2i16& other) const noexcept;
		inline bool operator==(const std::int16_t& number)  const noexcept;
		inline bool operator!=(const std::int16_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int16_t& stnd_value = 0) noexcept;
		inline std::int16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector3i16
	{
	public:
		std::int16_t x, y, z;
	public:
		inline Vector3i16(const std::int16_t& x = 0, const std::int16_t& y = 0, const std::int16_t& z = 0) noexcept;
		// copy
		inline Vector3i16(const Vector3i16& other) noexcept;
		inline Vector3i16& operator=(const Vector3i16& other) noexcept;
		// move
		inline Vector3i16(Vector3i16&& other) noexcept;
		inline Vector3i16& operator=(Vector3i16&& other) noexcept;
		// assignment
		inline Vector3i16& operator=(const std::int16_t& number) noexcept;

		// math operator
		inline Vector3i16 operator +(const Vector3i16& v) const noexcept;
		inline Vector3i16 operator -(const Vector3i16& v) const noexcept;
		inline Vector3i16 operator *(const Vector3i16& v) const noexcept;
		inline Vector3i16 operator /(const Vector3i16& v) const noexcept;

		inline Vector3i16 operator +(const std::int16_t& number) const noexcept;
		inline Vector3i16 operator -(const std::int16_t& number) const noexcept;
		inline Vector3i16 operator *(const std::int16_t& number) const noexcept;
		inline Vector3i16 operator /(const std::int16_t& number) const noexcept;

		// increment / decrement
		inline Vector3i16& operator++ () noexcept;		// prefix increment
		inline Vector3i16& operator-- () noexcept;		// prefix decrement
		inline Vector3i16  operator++ (int) noexcept;		// postfix increment
		inline Vector3i16  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3i16& operator+= (const Vector3i16& right) noexcept;
		inline Vector3i16& operator-= (const Vector3i16& right) noexcept;
		inline Vector3i16& operator*= (const Vector3i16& right) noexcept;
		inline Vector3i16& operator/= (const Vector3i16& right) noexcept;

		inline Vector3i16& operator+= (const std::int16_t& number) noexcept;
		inline Vector3i16& operator-= (const std::int16_t& number) noexcept;
		inline Vector3i16& operator*= (const std::int16_t& number) noexcept;
		inline Vector3i16& operator/= (const std::int16_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3i16& other) const noexcept;
		inline bool operator<=  (const Vector3i16& other) const noexcept;
		inline bool operator>	(const Vector3i16& other) const noexcept;
		inline bool operator>=  (const Vector3i16& other) const noexcept;
		 
		inline bool operator<	(const std::int16_t& number) const noexcept;
		inline bool operator<=  (const std::int16_t& number) const noexcept;
		inline bool operator>	(const std::int16_t& number) const noexcept;
		inline bool operator>=  (const std::int16_t& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3i16& other) const noexcept;
		inline bool operator!=(const Vector3i16& other) const noexcept;
		inline bool operator==(const std::int16_t& number)  const noexcept;
		inline bool operator!=(const std::int16_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int16_t& stnd_value = 0) noexcept;
		inline std::int16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector4i16
	{
	public:
		std::int16_t a, b, c, d;
	public:
		inline Vector4i16(const std::int16_t& a = 0, const std::int16_t& b = 0, const std::int16_t& c = 0, const std::int16_t& d = 0) noexcept;
		// copy
		inline Vector4i16(const Vector4i16& other) noexcept;
		inline Vector4i16& operator=(const Vector4i16& other) noexcept;
		// move
		inline Vector4i16(Vector4i16&& other) noexcept;
		inline Vector4i16& operator=(Vector4i16&& other) noexcept;
		// assignment
		inline Vector4i16& operator=(const std::int16_t& number) noexcept;
		
		// math operator
		inline Vector4i16 operator +(const Vector4i16& v) const noexcept;
		inline Vector4i16 operator -(const Vector4i16& v) const noexcept;
		inline Vector4i16 operator *(const Vector4i16& v) const noexcept;
		inline Vector4i16 operator /(const Vector4i16& v) const noexcept;
		
		inline Vector4i16 operator +(const std::int16_t& number) const noexcept;
		inline Vector4i16 operator -(const std::int16_t& number) const noexcept;
		inline Vector4i16 operator *(const std::int16_t& number) const noexcept;
		inline Vector4i16 operator /(const std::int16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector4i16& operator++ () noexcept;		// prefix increment
		inline Vector4i16& operator-- () noexcept;		// prefix decrement
		inline Vector4i16  operator++ (int) noexcept;		// postfix increment
		inline Vector4i16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4i16& operator+= (const Vector4i16& right) noexcept;
		inline Vector4i16& operator-= (const Vector4i16& right) noexcept;
		inline Vector4i16& operator*= (const Vector4i16& right) noexcept;
		inline Vector4i16& operator/= (const Vector4i16& right) noexcept;
		
		inline Vector4i16& operator+= (const std::int16_t& number) noexcept;
		inline Vector4i16& operator-= (const std::int16_t& number) noexcept;
		inline Vector4i16& operator*= (const std::int16_t& number) noexcept;
		inline Vector4i16& operator/= (const std::int16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4i16& other) const noexcept;
		inline bool operator<=  (const Vector4i16& other) const noexcept;
		inline bool operator>	(const Vector4i16& other) const noexcept;
		inline bool operator>=  (const Vector4i16& other) const noexcept;
		
		inline bool operator<	(const std::int16_t& number) const noexcept;
		inline bool operator<=  (const std::int16_t& number) const noexcept;
		inline bool operator>	(const std::int16_t& number) const noexcept;
		inline bool operator>=  (const std::int16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4i16& other) const noexcept;
		inline bool operator!=(const Vector4i16& other) const noexcept;
		inline bool operator==(const std::int16_t& number)  const noexcept;
		inline bool operator!=(const std::int16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int16_t& stnd_value = 0) noexcept;
		inline std::int16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector5i16
	{
	public:
		std::int16_t a, b, c, d, e;
	public:
		inline Vector5i16(const std::int16_t& a = 0, const std::int16_t& b = 0, const std::int16_t& c = 0, const std::int16_t& d = 0,
			const std::int16_t& e = 0) noexcept;
		// copy
		inline Vector5i16(const Vector5i16& other) noexcept;
		inline Vector5i16& operator=(const Vector5i16& other) noexcept;
		// move
		inline Vector5i16(Vector5i16&& other) noexcept;
		inline Vector5i16& operator=(Vector5i16&& other) noexcept;
		// assignment
		inline Vector5i16& operator=(const std::int16_t& number) noexcept;
		 
		// math operator
		inline Vector5i16 operator +(const Vector5i16& v) const noexcept;
		inline Vector5i16 operator -(const Vector5i16& v) const noexcept;
		inline Vector5i16 operator *(const Vector5i16& v) const noexcept;
		inline Vector5i16 operator /(const Vector5i16& v) const noexcept;
		
		inline Vector5i16 operator +(const std::int16_t& number) const noexcept;
		inline Vector5i16 operator -(const std::int16_t& number) const noexcept;
		inline Vector5i16 operator *(const std::int16_t& number) const noexcept;
		inline Vector5i16 operator /(const std::int16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector5i16& operator++ () noexcept;		// prefix increment
		inline Vector5i16& operator-- () noexcept;		// prefix decrement
		inline Vector5i16  operator++ (int) noexcept;		// postfix increment
		inline Vector5i16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5i16& operator+= (const Vector5i16& right) noexcept;
		inline Vector5i16& operator-= (const Vector5i16& right) noexcept;
		inline Vector5i16& operator*= (const Vector5i16& right) noexcept;
		inline Vector5i16& operator/= (const Vector5i16& right) noexcept;
		
		inline Vector5i16& operator+= (const std::int16_t& number) noexcept;
		inline Vector5i16& operator-= (const std::int16_t& number) noexcept;
		inline Vector5i16& operator*= (const std::int16_t& number) noexcept;
		inline Vector5i16& operator/= (const std::int16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5i16& other) const noexcept;
		inline bool operator<=  (const Vector5i16& other) const noexcept;
		inline bool operator>	(const Vector5i16& other) const noexcept;
		inline bool operator>=  (const Vector5i16& other) const noexcept;
		
		inline bool operator<	(const std::int16_t& number) const noexcept;
		inline bool operator<=  (const std::int16_t& number) const noexcept;
		inline bool operator>	(const std::int16_t& number) const noexcept;
		inline bool operator>=  (const std::int16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5i16& other) const noexcept;
		inline bool operator!=(const Vector5i16& other) const noexcept;
		inline bool operator==(const std::int16_t& number)  const noexcept;
		inline bool operator!=(const std::int16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int16_t& stnd_value = 0) noexcept;
		inline std::int16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector6i16
	{
	public:
		std::int16_t a, b, c, d, e, f;
	public:
		inline Vector6i16(const std::int16_t& a = 0, const std::int16_t& b = 0, const std::int16_t& c = 0, const std::int16_t& d = 0,
			const std::int16_t& e = 0, const std::int16_t& f = 0) noexcept;
		// copy
		inline Vector6i16(const Vector6i16& other) noexcept;
		inline Vector6i16& operator=(const Vector6i16& other) noexcept;
		// move
		inline Vector6i16(Vector6i16&& other) noexcept;
		inline Vector6i16& operator=(Vector6i16&& other) noexcept;
		// assignment
		inline Vector6i16& operator=(const std::int16_t& number) noexcept;
		
		// math operator
		inline Vector6i16 operator +(const Vector6i16& v) const noexcept;
		inline Vector6i16 operator -(const Vector6i16& v) const noexcept;
		inline Vector6i16 operator *(const Vector6i16& v) const noexcept;
		inline Vector6i16 operator /(const Vector6i16& v) const noexcept;
		
		inline Vector6i16 operator +(const std::int16_t& number) const noexcept;
		inline Vector6i16 operator -(const std::int16_t& number) const noexcept;
		inline Vector6i16 operator *(const std::int16_t& number) const noexcept;
		inline Vector6i16 operator /(const std::int16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector6i16& operator++ () noexcept;		// prefix increment
		inline Vector6i16& operator-- () noexcept;		// prefix decrement
		inline Vector6i16  operator++ (int) noexcept;		// postfix increment
		inline Vector6i16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6i16& operator+= (const Vector6i16& right) noexcept;
		inline Vector6i16& operator-= (const Vector6i16& right) noexcept;
		inline Vector6i16& operator*= (const Vector6i16& right) noexcept;
		inline Vector6i16& operator/= (const Vector6i16& right) noexcept;
		
		inline Vector6i16& operator+= (const std::int16_t& number) noexcept;
		inline Vector6i16& operator-= (const std::int16_t& number) noexcept;
		inline Vector6i16& operator*= (const std::int16_t& number) noexcept;
		inline Vector6i16& operator/= (const std::int16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6i16& other) const noexcept;
		inline bool operator<  (const Vector6i16& other) const noexcept;
		inline bool operator>  (const Vector6i16& other) const noexcept;
		inline bool operator>= (const Vector6i16& other) const noexcept;
		
		inline bool operator<  (const std::int16_t& number) const noexcept;
		inline bool operator<= (const std::int16_t& number) const noexcept;
		inline bool operator>  (const std::int16_t& number) const noexcept;
		inline bool operator>= (const std::int16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6i16& other) const noexcept;
		inline bool operator!=(const Vector6i16& other) const noexcept;
		inline bool operator==(const std::int16_t& number)  const noexcept;
		inline bool operator!=(const std::int16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int16_t& stnd_value = 0) noexcept;
		inline std::int16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector7i16
	{
	public:
		std::int16_t a, b, c, d, e, f, g;
	public:
		inline Vector7i16(const std::int16_t& a = 0, const std::int16_t& b = 0, const std::int16_t& c = 0, const std::int16_t& d = 0,
			const std::int16_t& e = 0, const std::int16_t& f = 0, const std::int16_t& g = 0) noexcept;
		// copy
		inline Vector7i16(const Vector7i16& other) noexcept;
		inline Vector7i16& operator=(const Vector7i16& other) noexcept;
		// move
		inline Vector7i16(Vector7i16&& other) noexcept;
		inline Vector7i16& operator=(Vector7i16&& other) noexcept;
		// assignment
		inline Vector7i16& operator=(const std::int16_t& number) noexcept;
		
		// math operator
		inline Vector7i16 operator +(const Vector7i16& v) const noexcept;
		inline Vector7i16 operator -(const Vector7i16& v) const noexcept;
		inline Vector7i16 operator *(const Vector7i16& v) const noexcept;
		inline Vector7i16 operator /(const Vector7i16& v) const noexcept;
		
		inline Vector7i16 operator +(const std::int16_t& number) const noexcept;
		inline Vector7i16 operator -(const std::int16_t& number) const noexcept;
		inline Vector7i16 operator *(const std::int16_t& number) const noexcept;
		inline Vector7i16 operator /(const std::int16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector7i16& operator++ () noexcept;		// prefix increment
		inline Vector7i16& operator-- () noexcept;		// prefix decrement
		inline Vector7i16  operator++ (int) noexcept;		// postfix increment
		inline Vector7i16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7i16& operator+= (const Vector7i16& right) noexcept;
		inline Vector7i16& operator-= (const Vector7i16& right) noexcept;
		inline Vector7i16& operator*= (const Vector7i16& right) noexcept;
		inline Vector7i16& operator/= (const Vector7i16& right) noexcept;
		
		inline Vector7i16& operator+= (const std::int16_t& number) noexcept;
		inline Vector7i16& operator-= (const std::int16_t& number) noexcept;
		inline Vector7i16& operator*= (const std::int16_t& number) noexcept;
		inline Vector7i16& operator/= (const std::int16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7i16& other) const noexcept;
		inline bool operator<  (const Vector7i16& other) const noexcept;
		inline bool operator>  (const Vector7i16& other) const noexcept;
		inline bool operator>= (const Vector7i16& other) const noexcept;
		
		inline bool operator<  (const std::int16_t& number) const noexcept;
		inline bool operator<= (const std::int16_t& number) const noexcept;
		inline bool operator>  (const std::int16_t& number) const noexcept;
		inline bool operator>= (const std::int16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7i16& other) const noexcept;
		inline bool operator!=(const Vector7i16& other) const noexcept;
		inline bool operator==(const std::int16_t& number)  const noexcept;
		inline bool operator!=(const std::int16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int16_t& stnd_value = 0) noexcept;
		inline std::int16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector8i16
	{
	public:
		std::int16_t a, b, c, d, e, f, g, h;
	public:
		inline Vector8i16(const std::int16_t& a = 0, const std::int16_t& b = 0, const std::int16_t& c = 0, const std::int16_t& d = 0,
			const std::int16_t& e = 0, const std::int16_t& f = 0, const std::int16_t& g = 0, const std::int16_t& h = 0) noexcept;
		// copy
		inline Vector8i16(const Vector8i16& other) noexcept;
		inline Vector8i16& operator=(const Vector8i16& other) noexcept;
		// move
		inline Vector8i16(Vector8i16&& other) noexcept;
		inline Vector8i16& operator=(Vector8i16&& other) noexcept;
		// assignment
		inline Vector8i16& operator=(const std::int16_t& number) noexcept;
		
		// math operator
		inline Vector8i16 operator +(const Vector8i16& v) const noexcept;
		inline Vector8i16 operator -(const Vector8i16& v) const noexcept;
		inline Vector8i16 operator *(const Vector8i16& v) const noexcept;
		inline Vector8i16 operator /(const Vector8i16& v) const noexcept;
		
		inline Vector8i16 operator +(const std::int16_t& number) const noexcept;
		inline Vector8i16 operator -(const std::int16_t& number) const noexcept;
		inline Vector8i16 operator *(const std::int16_t& number) const noexcept;
		inline Vector8i16 operator /(const std::int16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector8i16& operator++ () noexcept;		// prefix increment
		inline Vector8i16& operator-- () noexcept;		// prefix decrement
		inline Vector8i16  operator++ (int) noexcept;		// postfix increment
		inline Vector8i16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8i16& operator+= (const Vector8i16& right) noexcept;
		inline Vector8i16& operator-= (const Vector8i16& right) noexcept;
		inline Vector8i16& operator*= (const Vector8i16& right) noexcept;
		inline Vector8i16& operator/= (const Vector8i16& right) noexcept;
		
		inline Vector8i16& operator+= (const std::int16_t& number) noexcept;
		inline Vector8i16& operator-= (const std::int16_t& number) noexcept;
		inline Vector8i16& operator*= (const std::int16_t& number) noexcept;
		inline Vector8i16& operator/= (const std::int16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8i16& other) const noexcept;
		inline bool operator<  (const Vector8i16& other) const noexcept;
		inline bool operator>  (const Vector8i16& other) const noexcept;
		inline bool operator>= (const Vector8i16& other) const noexcept;
		
		inline bool operator<  (const std::int16_t& number) const noexcept;
		inline bool operator<= (const std::int16_t& number) const noexcept;
		inline bool operator>  (const std::int16_t& number) const noexcept;
		inline bool operator>= (const std::int16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8i16& other) const noexcept;
		inline bool operator!=(const Vector8i16& other) const noexcept;
		inline bool operator==(const std::int16_t& number)  const noexcept;
		inline bool operator!=(const std::int16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int16_t& stnd_value = 0) noexcept;
		inline std::int16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector9i16
	{
	public:
		std::int16_t a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9i16(const std::int16_t& a = 0, const std::int16_t& b = 0, const std::int16_t& c = 0, const std::int16_t& d = 0,
			const std::int16_t& e = 0, const std::int16_t& f = 0, const std::int16_t& g = 0, const std::int16_t& h = 0,
			const std::int16_t& i = 0) noexcept;
		// copy
		inline Vector9i16(const Vector9i16& other) noexcept;
		inline Vector9i16& operator=(const Vector9i16& other) noexcept;
		// move
		inline Vector9i16(Vector9i16&& other) noexcept;
		inline Vector9i16& operator=(Vector9i16&& other) noexcept;
		// assignment
		inline Vector9i16& operator=(const std::int16_t& number) noexcept;
		
		// math operator
		inline Vector9i16 operator +(const Vector9i16& v) const noexcept;
		inline Vector9i16 operator -(const Vector9i16& v) const noexcept;
		inline Vector9i16 operator *(const Vector9i16& v) const noexcept;
		inline Vector9i16 operator /(const Vector9i16& v) const noexcept;
		
		inline Vector9i16 operator +(const std::int16_t& number) const noexcept;
		inline Vector9i16 operator -(const std::int16_t& number) const noexcept;
		inline Vector9i16 operator *(const std::int16_t& number) const noexcept;
		inline Vector9i16 operator /(const std::int16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector9i16& operator++ () noexcept;		// prefix increment
		inline Vector9i16& operator-- () noexcept;		// prefix decrement
		inline Vector9i16  operator++ (int) noexcept;		// postfix increment
		inline Vector9i16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9i16& operator+= (const Vector9i16& right) noexcept;
		inline Vector9i16& operator-= (const Vector9i16& right) noexcept;
		inline Vector9i16& operator*= (const Vector9i16& right) noexcept;
		inline Vector9i16& operator/= (const Vector9i16& right) noexcept;
		
		inline Vector9i16& operator+= (const std::int16_t& number) noexcept;
		inline Vector9i16& operator-= (const std::int16_t& number) noexcept;
		inline Vector9i16& operator*= (const std::int16_t& number) noexcept;
		inline Vector9i16& operator/= (const std::int16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9i16& other) const noexcept;
		inline bool operator<  (const Vector9i16& other) const noexcept;
		inline bool operator>  (const Vector9i16& other) const noexcept;
		inline bool operator>= (const Vector9i16& other) const noexcept;
		
		inline bool operator<  (const std::int16_t& number) const noexcept;
		inline bool operator<= (const std::int16_t& number) const noexcept;
		inline bool operator>  (const std::int16_t& number) const noexcept;
		inline bool operator>= (const std::int16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9i16& other) const noexcept;
		inline bool operator!=(const Vector9i16& other) const noexcept;
		inline bool operator==(const std::int16_t& number)  const noexcept;
		inline bool operator!=(const std::int16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int16_t& stnd_value = 0) noexcept;
		inline std::int16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector10i16
	{
	public:
		std::int16_t a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10i16(const std::int16_t& a = 0, const std::int16_t& b = 0, const std::int16_t& c = 0, const std::int16_t& d = 0,
			const std::int16_t& e = 0, const std::int16_t& f = 0, const std::int16_t& g = 0, const std::int16_t& h = 0,
			const std::int16_t& i = 0, const std::int16_t& j = 0) noexcept;
		// copy
		inline Vector10i16(const Vector10i16& other) noexcept;
		inline Vector10i16& operator=(const Vector10i16& other) noexcept;
		// move
		inline Vector10i16(Vector10i16&& other) noexcept;
		inline Vector10i16& operator=(Vector10i16&& other) noexcept;
		// assignment
		inline Vector10i16& operator=(const std::int16_t& number) noexcept;
		
		// math operator
		inline Vector10i16 operator +(const Vector10i16& v) const noexcept;
		inline Vector10i16 operator -(const Vector10i16& v) const noexcept;
		inline Vector10i16 operator *(const Vector10i16& v) const noexcept;
		inline Vector10i16 operator /(const Vector10i16& v) const noexcept;
		
		inline Vector10i16 operator +(const std::int16_t& number) const noexcept;
		inline Vector10i16 operator -(const std::int16_t& number) const noexcept;
		inline Vector10i16 operator *(const std::int16_t& number) const noexcept;
		inline Vector10i16 operator /(const std::int16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector10i16& operator++ () noexcept;		// prefix increment
		inline Vector10i16& operator-- () noexcept;		// prefix decrement
		inline Vector10i16  operator++ (int) noexcept;	// postfix increment
		inline Vector10i16  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10i16& operator+= (const Vector10i16& right) noexcept;
		inline Vector10i16& operator-= (const Vector10i16& right) noexcept;
		inline Vector10i16& operator*= (const Vector10i16& right) noexcept;
		inline Vector10i16& operator/= (const Vector10i16& right) noexcept;
		
		inline Vector10i16& operator+= (const std::int16_t& number) noexcept;
		inline Vector10i16& operator-= (const std::int16_t& number) noexcept;
		inline Vector10i16& operator*= (const std::int16_t& number) noexcept;
		inline Vector10i16& operator/= (const std::int16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10i16& other) const noexcept;
		inline bool operator<  (const Vector10i16& other) const noexcept;
		inline bool operator>  (const Vector10i16& other) const noexcept;
		inline bool operator>= (const Vector10i16& other) const noexcept;

		inline bool operator<  (const std::int16_t& number) const noexcept;
		inline bool operator<= (const std::int16_t& number) const noexcept;
		inline bool operator>  (const std::int16_t& number) const noexcept;
		inline bool operator>= (const std::int16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10i16& other) const noexcept;
		inline bool operator!=(const Vector10i16& other) const noexcept;
		inline bool operator==(const std::int16_t& number)   const noexcept;
		inline bool operator!=(const std::int16_t& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int16_t& stnd_value = 0) noexcept;
		inline std::int16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int16_t& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2i16& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3i16& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4i16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5i16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6i16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7i16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8i16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9i16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10i16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}