#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : long double
		Bytes: 8
		Range: 1.7E +/- 308  precision: (15 digits)
	*/

	class Vector2Ld
	{
	public:
		long double x, y;
	public:
		inline Vector2Ld(const long double& x = 0.0L, const long double& y = 0.0L) noexcept;
		// copy
		inline Vector2Ld(const Vector2Ld& other) noexcept;
		inline Vector2Ld& operator=(const Vector2Ld& other) noexcept;
		// move
		inline Vector2Ld(Vector2Ld&& other) noexcept;
		inline Vector2Ld& operator=(Vector2Ld&& other) noexcept;
		// assignment
		inline Vector2Ld& operator=(const long double& number) noexcept;

		// math operator
		inline Vector2Ld operator +(const Vector2Ld& v) const noexcept;
		inline Vector2Ld operator -(const Vector2Ld& v) const noexcept;
		inline Vector2Ld operator *(const Vector2Ld& v) const noexcept;
		inline Vector2Ld operator /(const Vector2Ld& v) const noexcept;

		inline Vector2Ld operator +(const long double& number) const noexcept;
		inline Vector2Ld operator -(const long double& number) const noexcept;
		inline Vector2Ld operator *(const long double& number) const noexcept;
		inline Vector2Ld operator /(const long double& number) const noexcept;

		// increment / decrement
		inline Vector2Ld& operator++ () noexcept;		// prefix increment
		inline Vector2Ld& operator-- () noexcept;		// prefix decrement
		inline Vector2Ld  operator++ (int) noexcept;		// postfix increment
		inline Vector2Ld  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2Ld& operator+= (const Vector2Ld& right) noexcept;
		inline Vector2Ld& operator-= (const Vector2Ld& right) noexcept;
		inline Vector2Ld& operator*= (const Vector2Ld& right) noexcept;
		inline Vector2Ld& operator/= (const Vector2Ld& right) noexcept;

		inline Vector2Ld& operator+= (const long double& number) noexcept;
		inline Vector2Ld& operator-= (const long double& number) noexcept;
		inline Vector2Ld& operator*= (const long double& number) noexcept;
		inline Vector2Ld& operator/= (const long double& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2Ld& other) const noexcept;
		inline bool operator<=  (const Vector2Ld& other) const noexcept;
		inline bool operator>	(const Vector2Ld& other) const noexcept;
		inline bool operator>=  (const Vector2Ld& other) const noexcept;

		inline bool operator<	(const long double& number) const noexcept;
		inline bool operator<=  (const long double& number) const noexcept;
		inline bool operator>	(const long double& number) const noexcept;
		inline bool operator>=  (const long double& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2Ld& other) const noexcept;
		inline bool operator!=(const Vector2Ld& other) const noexcept;
		inline bool operator==(const long double& number)  const noexcept;
		inline bool operator!=(const long double& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long double& stnd_value = 0.0L) noexcept;
		inline long double& operator[](const std::uint8_t& index) noexcept;
		inline long double& at(const std::uint8_t& index) noexcept;
	};


	class Vector3Ld
	{
	public:
		long double x, y, z;
	public:
		inline Vector3Ld(const long double& x = 0.0L, const long double& y = 0.0L, const long double& z = 0.0L) noexcept;
		// copy
		inline Vector3Ld(const Vector3Ld& other) noexcept;
		inline Vector3Ld& operator=(const Vector3Ld& other) noexcept;
		// move
		inline Vector3Ld(Vector3Ld&& other) noexcept;
		inline Vector3Ld& operator=(Vector3Ld&& other) noexcept;
		// assignment
		inline Vector3Ld& operator=(const long double& number) noexcept;

		// math operator
		inline Vector3Ld operator +(const Vector3Ld& v) const noexcept;
		inline Vector3Ld operator -(const Vector3Ld& v) const noexcept;
		inline Vector3Ld operator *(const Vector3Ld& v) const noexcept;
		inline Vector3Ld operator /(const Vector3Ld& v) const noexcept;

		inline Vector3Ld operator +(const long double& number) const noexcept;
		inline Vector3Ld operator -(const long double& number) const noexcept;
		inline Vector3Ld operator *(const long double& number) const noexcept;
		inline Vector3Ld operator /(const long double& number) const noexcept;

		// increment / decrement
		inline Vector3Ld& operator++ () noexcept;		// prefix increment
		inline Vector3Ld& operator-- () noexcept;		// prefix decrement
		inline Vector3Ld  operator++ (int) noexcept;		// postfix increment
		inline Vector3Ld  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3Ld& operator+= (const Vector3Ld& right) noexcept;
		inline Vector3Ld& operator-= (const Vector3Ld& right) noexcept;
		inline Vector3Ld& operator*= (const Vector3Ld& right) noexcept;
		inline Vector3Ld& operator/= (const Vector3Ld& right) noexcept;

		inline Vector3Ld& operator+= (const long double& number) noexcept;
		inline Vector3Ld& operator-= (const long double& number) noexcept;
		inline Vector3Ld& operator*= (const long double& number) noexcept;
		inline Vector3Ld& operator/= (const long double& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3Ld& other) const noexcept;
		inline bool operator<=  (const Vector3Ld& other) const noexcept;
		inline bool operator>	(const Vector3Ld& other) const noexcept;
		inline bool operator>=  (const Vector3Ld& other) const noexcept;
		 
		inline bool operator<	(const long double& number) const noexcept;
		inline bool operator<=  (const long double& number) const noexcept;
		inline bool operator>	(const long double& number) const noexcept;
		inline bool operator>=  (const long double& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3Ld& other) const noexcept;
		inline bool operator!=(const Vector3Ld& other) const noexcept;
		inline bool operator==(const long double& number)  const noexcept;
		inline bool operator!=(const long double& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long double& stnd_value = 0.0L) noexcept;
		inline long double& operator[](const std::uint8_t& index) noexcept;
		inline long double& at(const std::uint8_t& index) noexcept;
	};


	class Vector4Ld
	{
	public:
		long double a, b, c, d;
	public:
		inline Vector4Ld(const long double& a = 0.0L, const long double& b = 0.0L, const long double& c = 0.0L, const long double& d = 0.0L) noexcept;
		// copy
		inline Vector4Ld(const Vector4Ld& other) noexcept;
		inline Vector4Ld& operator=(const Vector4Ld& other) noexcept;
		// move
		inline Vector4Ld(Vector4Ld&& other) noexcept;
		inline Vector4Ld& operator=(Vector4Ld&& other) noexcept;
		// assignment
		inline Vector4Ld& operator=(const long double& number) noexcept;
		
		// math operator
		inline Vector4Ld operator +(const Vector4Ld& v) const noexcept;
		inline Vector4Ld operator -(const Vector4Ld& v) const noexcept;
		inline Vector4Ld operator *(const Vector4Ld& v) const noexcept;
		inline Vector4Ld operator /(const Vector4Ld& v) const noexcept;
		
		inline Vector4Ld operator +(const long double& number) const noexcept;
		inline Vector4Ld operator -(const long double& number) const noexcept;
		inline Vector4Ld operator *(const long double& number) const noexcept;
		inline Vector4Ld operator /(const long double& number) const noexcept;
		
		// increment / decrement
		inline Vector4Ld& operator++ () noexcept;		// prefix increment
		inline Vector4Ld& operator-- () noexcept;		// prefix decrement
		inline Vector4Ld  operator++ (int) noexcept;		// postfix increment
		inline Vector4Ld  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4Ld& operator+= (const Vector4Ld& right) noexcept;
		inline Vector4Ld& operator-= (const Vector4Ld& right) noexcept;
		inline Vector4Ld& operator*= (const Vector4Ld& right) noexcept;
		inline Vector4Ld& operator/= (const Vector4Ld& right) noexcept;
		
		inline Vector4Ld& operator+= (const long double& number) noexcept;
		inline Vector4Ld& operator-= (const long double& number) noexcept;
		inline Vector4Ld& operator*= (const long double& number) noexcept;
		inline Vector4Ld& operator/= (const long double& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4Ld& other) const noexcept;
		inline bool operator<=  (const Vector4Ld& other) const noexcept;
		inline bool operator>	(const Vector4Ld& other) const noexcept;
		inline bool operator>=  (const Vector4Ld& other) const noexcept;
		
		inline bool operator<	(const long double& number) const noexcept;
		inline bool operator<=  (const long double& number) const noexcept;
		inline bool operator>	(const long double& number) const noexcept;
		inline bool operator>=  (const long double& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4Ld& other) const noexcept;
		inline bool operator!=(const Vector4Ld& other) const noexcept;
		inline bool operator==(const long double& number)  const noexcept;
		inline bool operator!=(const long double& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long double& stnd_value = 0.0L) noexcept;
		inline long double& operator[](const std::uint8_t& index) noexcept;
		inline long double& at(const std::uint8_t& index) noexcept;
	};


	class Vector5Ld
	{
	public:
		long double a, b, c, d, e;
	public:
		inline Vector5Ld(const long double& a = 0.0L, const long double& b = 0.0L, const long double& c = 0.0L, const long double& d = 0.0L,
			const long double& e = 0.0L) noexcept;
		// copy
		inline Vector5Ld(const Vector5Ld& other) noexcept;
		inline Vector5Ld& operator=(const Vector5Ld& other) noexcept;
		// move
		inline Vector5Ld(Vector5Ld&& other) noexcept;
		inline Vector5Ld& operator=(Vector5Ld&& other) noexcept;
		// assignment
		inline Vector5Ld& operator=(const long double& number) noexcept;
		 
		// math operator
		inline Vector5Ld operator +(const Vector5Ld& v) const noexcept;
		inline Vector5Ld operator -(const Vector5Ld& v) const noexcept;
		inline Vector5Ld operator *(const Vector5Ld& v) const noexcept;
		inline Vector5Ld operator /(const Vector5Ld& v) const noexcept;
		
		inline Vector5Ld operator +(const long double& number) const noexcept;
		inline Vector5Ld operator -(const long double& number) const noexcept;
		inline Vector5Ld operator *(const long double& number) const noexcept;
		inline Vector5Ld operator /(const long double& number) const noexcept;
		
		// increment / decrement
		inline Vector5Ld& operator++ () noexcept;		// prefix increment
		inline Vector5Ld& operator-- () noexcept;		// prefix decrement
		inline Vector5Ld  operator++ (int) noexcept;		// postfix increment
		inline Vector5Ld  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5Ld& operator+= (const Vector5Ld& right) noexcept;
		inline Vector5Ld& operator-= (const Vector5Ld& right) noexcept;
		inline Vector5Ld& operator*= (const Vector5Ld& right) noexcept;
		inline Vector5Ld& operator/= (const Vector5Ld& right) noexcept;
		
		inline Vector5Ld& operator+= (const long double& number) noexcept;
		inline Vector5Ld& operator-= (const long double& number) noexcept;
		inline Vector5Ld& operator*= (const long double& number) noexcept;
		inline Vector5Ld& operator/= (const long double& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5Ld& other) const noexcept;
		inline bool operator<=  (const Vector5Ld& other) const noexcept;
		inline bool operator>	(const Vector5Ld& other) const noexcept;
		inline bool operator>=  (const Vector5Ld& other) const noexcept;
		
		inline bool operator<	(const long double& number) const noexcept;
		inline bool operator<=  (const long double& number) const noexcept;
		inline bool operator>	(const long double& number) const noexcept;
		inline bool operator>=  (const long double& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5Ld& other) const noexcept;
		inline bool operator!=(const Vector5Ld& other) const noexcept;
		inline bool operator==(const long double& number)  const noexcept;
		inline bool operator!=(const long double& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long double& stnd_value = 0.0L) noexcept;
		inline long double& operator[](const std::uint8_t& index) noexcept;
		inline long double& at(const std::uint8_t& index) noexcept;
	};


	class Vector6Ld
	{
	public:
		long double a, b, c, d, e, f;
	public:
		inline Vector6Ld(const long double& a = 0.0L, const long double& b = 0.0L, const long double& c = 0.0L, const long double& d = 0.0L,
			const long double& e = 0.0L, const long double& f = 0.0L) noexcept;
		// copy
		inline Vector6Ld(const Vector6Ld& other) noexcept;
		inline Vector6Ld& operator=(const Vector6Ld& other) noexcept;
		// move
		inline Vector6Ld(Vector6Ld&& other) noexcept;
		inline Vector6Ld& operator=(Vector6Ld&& other) noexcept;
		// assignment
		inline Vector6Ld& operator=(const long double& number) noexcept;
		
		// math operator
		inline Vector6Ld operator +(const Vector6Ld& v) const noexcept;
		inline Vector6Ld operator -(const Vector6Ld& v) const noexcept;
		inline Vector6Ld operator *(const Vector6Ld& v) const noexcept;
		inline Vector6Ld operator /(const Vector6Ld& v) const noexcept;
		
		inline Vector6Ld operator +(const long double& number) const noexcept;
		inline Vector6Ld operator -(const long double& number) const noexcept;
		inline Vector6Ld operator *(const long double& number) const noexcept;
		inline Vector6Ld operator /(const long double& number) const noexcept;
		
		// increment / decrement
		inline Vector6Ld& operator++ () noexcept;		// prefix increment
		inline Vector6Ld& operator-- () noexcept;		// prefix decrement
		inline Vector6Ld  operator++ (int) noexcept;		// postfix increment
		inline Vector6Ld  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6Ld& operator+= (const Vector6Ld& right) noexcept;
		inline Vector6Ld& operator-= (const Vector6Ld& right) noexcept;
		inline Vector6Ld& operator*= (const Vector6Ld& right) noexcept;
		inline Vector6Ld& operator/= (const Vector6Ld& right) noexcept;
		
		inline Vector6Ld& operator+= (const long double& number) noexcept;
		inline Vector6Ld& operator-= (const long double& number) noexcept;
		inline Vector6Ld& operator*= (const long double& number) noexcept;
		inline Vector6Ld& operator/= (const long double& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6Ld& other) const noexcept;
		inline bool operator<  (const Vector6Ld& other) const noexcept;
		inline bool operator>  (const Vector6Ld& other) const noexcept;
		inline bool operator>= (const Vector6Ld& other) const noexcept;
		
		inline bool operator<  (const long double& number) const noexcept;
		inline bool operator<= (const long double& number) const noexcept;
		inline bool operator>  (const long double& number) const noexcept;
		inline bool operator>= (const long double& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6Ld& other) const noexcept;
		inline bool operator!=(const Vector6Ld& other) const noexcept;
		inline bool operator==(const long double& number)  const noexcept;
		inline bool operator!=(const long double& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long double& stnd_value = 0.0L) noexcept;
		inline long double& operator[](const std::uint8_t& index) noexcept;
		inline long double& at(const std::uint8_t& index) noexcept;
	};


	class Vector7Ld
	{
	public:
		long double a, b, c, d, e, f, g;
	public:
		inline Vector7Ld(const long double& a = 0.0L, const long double& b = 0.0L, const long double& c = 0.0L, const long double& d = 0.0L,
			const long double& e = 0.0L, const long double& f = 0.0L, const long double& g = 0.0L) noexcept;
		// copy
		inline Vector7Ld(const Vector7Ld& other) noexcept;
		inline Vector7Ld& operator=(const Vector7Ld& other) noexcept;
		// move
		inline Vector7Ld(Vector7Ld&& other) noexcept;
		inline Vector7Ld& operator=(Vector7Ld&& other) noexcept;
		// assignment
		inline Vector7Ld& operator=(const long double& number) noexcept;
		
		// math operator
		inline Vector7Ld operator +(const Vector7Ld& v) const noexcept;
		inline Vector7Ld operator -(const Vector7Ld& v) const noexcept;
		inline Vector7Ld operator *(const Vector7Ld& v) const noexcept;
		inline Vector7Ld operator /(const Vector7Ld& v) const noexcept;
		
		inline Vector7Ld operator +(const long double& number) const noexcept;
		inline Vector7Ld operator -(const long double& number) const noexcept;
		inline Vector7Ld operator *(const long double& number) const noexcept;
		inline Vector7Ld operator /(const long double& number) const noexcept;
		
		// increment / decrement
		inline Vector7Ld& operator++ () noexcept;		// prefix increment
		inline Vector7Ld& operator-- () noexcept;		// prefix decrement
		inline Vector7Ld  operator++ (int) noexcept;		// postfix increment
		inline Vector7Ld  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7Ld& operator+= (const Vector7Ld& right) noexcept;
		inline Vector7Ld& operator-= (const Vector7Ld& right) noexcept;
		inline Vector7Ld& operator*= (const Vector7Ld& right) noexcept;
		inline Vector7Ld& operator/= (const Vector7Ld& right) noexcept;
		
		inline Vector7Ld& operator+= (const long double& number) noexcept;
		inline Vector7Ld& operator-= (const long double& number) noexcept;
		inline Vector7Ld& operator*= (const long double& number) noexcept;
		inline Vector7Ld& operator/= (const long double& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7Ld& other) const noexcept;
		inline bool operator<  (const Vector7Ld& other) const noexcept;
		inline bool operator>  (const Vector7Ld& other) const noexcept;
		inline bool operator>= (const Vector7Ld& other) const noexcept;
		
		inline bool operator<  (const long double& number) const noexcept;
		inline bool operator<= (const long double& number) const noexcept;
		inline bool operator>  (const long double& number) const noexcept;
		inline bool operator>= (const long double& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7Ld& other) const noexcept;
		inline bool operator!=(const Vector7Ld& other) const noexcept;
		inline bool operator==(const long double& number)  const noexcept;
		inline bool operator!=(const long double& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long double& stnd_value = 0.0L) noexcept;
		inline long double& operator[](const std::uint8_t& index) noexcept;
		inline long double& at(const std::uint8_t& index) noexcept;
	};


	class Vector8Ld
	{
	public:
		long double a, b, c, d, e, f, g, h;
	public:
		inline Vector8Ld(const long double& a = 0.0L, const long double& b = 0.0L, const long double& c = 0.0L, const long double& d = 0.0L,
			const long double& e = 0.0L, const long double& f = 0.0L, const long double& g = 0.0L, const long double& h = 0.0L) noexcept;
		// copy
		inline Vector8Ld(const Vector8Ld& other) noexcept;
		inline Vector8Ld& operator=(const Vector8Ld& other) noexcept;
		// move
		inline Vector8Ld(Vector8Ld&& other) noexcept;
		inline Vector8Ld& operator=(Vector8Ld&& other) noexcept;
		// assignment
		inline Vector8Ld& operator=(const long double& number) noexcept;
		
		// math operator
		inline Vector8Ld operator +(const Vector8Ld& v) const noexcept;
		inline Vector8Ld operator -(const Vector8Ld& v) const noexcept;
		inline Vector8Ld operator *(const Vector8Ld& v) const noexcept;
		inline Vector8Ld operator /(const Vector8Ld& v) const noexcept;
		
		inline Vector8Ld operator +(const long double& number) const noexcept;
		inline Vector8Ld operator -(const long double& number) const noexcept;
		inline Vector8Ld operator *(const long double& number) const noexcept;
		inline Vector8Ld operator /(const long double& number) const noexcept;
		
		// increment / decrement
		inline Vector8Ld& operator++ () noexcept;		// prefix increment
		inline Vector8Ld& operator-- () noexcept;		// prefix decrement
		inline Vector8Ld  operator++ (int) noexcept;		// postfix increment
		inline Vector8Ld  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8Ld& operator+= (const Vector8Ld& right) noexcept;
		inline Vector8Ld& operator-= (const Vector8Ld& right) noexcept;
		inline Vector8Ld& operator*= (const Vector8Ld& right) noexcept;
		inline Vector8Ld& operator/= (const Vector8Ld& right) noexcept;
		
		inline Vector8Ld& operator+= (const long double& number) noexcept;
		inline Vector8Ld& operator-= (const long double& number) noexcept;
		inline Vector8Ld& operator*= (const long double& number) noexcept;
		inline Vector8Ld& operator/= (const long double& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8Ld& other) const noexcept;
		inline bool operator<  (const Vector8Ld& other) const noexcept;
		inline bool operator>  (const Vector8Ld& other) const noexcept;
		inline bool operator>= (const Vector8Ld& other) const noexcept;
		
		inline bool operator<  (const long double& number) const noexcept;
		inline bool operator<= (const long double& number) const noexcept;
		inline bool operator>  (const long double& number) const noexcept;
		inline bool operator>= (const long double& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8Ld& other) const noexcept;
		inline bool operator!=(const Vector8Ld& other) const noexcept;
		inline bool operator==(const long double& number)  const noexcept;
		inline bool operator!=(const long double& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long double& stnd_value = 0.0L) noexcept;
		inline long double& operator[](const std::uint8_t& index) noexcept;
		inline long double& at(const std::uint8_t& index) noexcept;
	};


	class Vector9Ld
	{
	public:
		long double a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9Ld(const long double& a = 0.0L, const long double& b = 0.0L, const long double& c = 0.0L, const long double& d = 0.0L,
			const long double& e = 0.0L, const long double& f = 0.0L, const long double& g = 0.0L, const long double& h = 0.0L,
			const long double& i = 0.0L) noexcept;
		// copy
		inline Vector9Ld(const Vector9Ld& other) noexcept;
		inline Vector9Ld& operator=(const Vector9Ld& other) noexcept;
		// move
		inline Vector9Ld(Vector9Ld&& other) noexcept;
		inline Vector9Ld& operator=(Vector9Ld&& other) noexcept;
		// assignment
		inline Vector9Ld& operator=(const long double& number) noexcept;
		
		// math operator
		inline Vector9Ld operator +(const Vector9Ld& v) const noexcept;
		inline Vector9Ld operator -(const Vector9Ld& v) const noexcept;
		inline Vector9Ld operator *(const Vector9Ld& v) const noexcept;
		inline Vector9Ld operator /(const Vector9Ld& v) const noexcept;
		
		inline Vector9Ld operator +(const long double& number) const noexcept;
		inline Vector9Ld operator -(const long double& number) const noexcept;
		inline Vector9Ld operator *(const long double& number) const noexcept;
		inline Vector9Ld operator /(const long double& number) const noexcept;
		
		// increment / decrement
		inline Vector9Ld& operator++ () noexcept;		// prefix increment
		inline Vector9Ld& operator-- () noexcept;		// prefix decrement
		inline Vector9Ld  operator++ (int) noexcept;		// postfix increment
		inline Vector9Ld  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9Ld& operator+= (const Vector9Ld& right) noexcept;
		inline Vector9Ld& operator-= (const Vector9Ld& right) noexcept;
		inline Vector9Ld& operator*= (const Vector9Ld& right) noexcept;
		inline Vector9Ld& operator/= (const Vector9Ld& right) noexcept;
		
		inline Vector9Ld& operator+= (const long double& number) noexcept;
		inline Vector9Ld& operator-= (const long double& number) noexcept;
		inline Vector9Ld& operator*= (const long double& number) noexcept;
		inline Vector9Ld& operator/= (const long double& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9Ld& other) const noexcept;
		inline bool operator<  (const Vector9Ld& other) const noexcept;
		inline bool operator>  (const Vector9Ld& other) const noexcept;
		inline bool operator>= (const Vector9Ld& other) const noexcept;
		
		inline bool operator<  (const long double& number) const noexcept;
		inline bool operator<= (const long double& number) const noexcept;
		inline bool operator>  (const long double& number) const noexcept;
		inline bool operator>= (const long double& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9Ld& other) const noexcept;
		inline bool operator!=(const Vector9Ld& other) const noexcept;
		inline bool operator==(const long double& number)  const noexcept;
		inline bool operator!=(const long double& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long double& stnd_value = 0.0L) noexcept;
		inline long double& operator[](const std::uint8_t& index) noexcept;
		inline long double& at(const std::uint8_t& index) noexcept;
	};


	class Vector10Ld
	{
	public:
		long double a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10Ld(const long double& a = 0.0L, const long double& b = 0.0L, const long double& c = 0.0L, const long double& d = 0.0L,
			const long double& e = 0.0L, const long double& f = 0.0L, const long double& g = 0.0L, const long double& h = 0.0L,
			const long double& i = 0.0L, const long double& j = 0.0L) noexcept;
		// copy
		inline Vector10Ld(const Vector10Ld& other) noexcept;
		inline Vector10Ld& operator=(const Vector10Ld& other) noexcept;
		// move
		inline Vector10Ld(Vector10Ld&& other) noexcept;
		inline Vector10Ld& operator=(Vector10Ld&& other) noexcept;
		// assignment
		inline Vector10Ld& operator=(const long double& number) noexcept;
		
		// math operator
		inline Vector10Ld operator +(const Vector10Ld& v) const noexcept;
		inline Vector10Ld operator -(const Vector10Ld& v) const noexcept;
		inline Vector10Ld operator *(const Vector10Ld& v) const noexcept;
		inline Vector10Ld operator /(const Vector10Ld& v) const noexcept;
		
		inline Vector10Ld operator +(const long double& number) const noexcept;
		inline Vector10Ld operator -(const long double& number) const noexcept;
		inline Vector10Ld operator *(const long double& number) const noexcept;
		inline Vector10Ld operator /(const long double& number) const noexcept;
		
		// increment / decrement
		inline Vector10Ld& operator++ () noexcept;		// prefix increment
		inline Vector10Ld& operator-- () noexcept;		// prefix decrement
		inline Vector10Ld  operator++ (int) noexcept;	// postfix increment
		inline Vector10Ld  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10Ld& operator+= (const Vector10Ld& right) noexcept;
		inline Vector10Ld& operator-= (const Vector10Ld& right) noexcept;
		inline Vector10Ld& operator*= (const Vector10Ld& right) noexcept;
		inline Vector10Ld& operator/= (const Vector10Ld& right) noexcept;
		
		inline Vector10Ld& operator+= (const long double& number) noexcept;
		inline Vector10Ld& operator-= (const long double& number) noexcept;
		inline Vector10Ld& operator*= (const long double& number) noexcept;
		inline Vector10Ld& operator/= (const long double& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10Ld& other) const noexcept;
		inline bool operator<  (const Vector10Ld& other) const noexcept;
		inline bool operator>  (const Vector10Ld& other) const noexcept;
		inline bool operator>= (const Vector10Ld& other) const noexcept;

		inline bool operator<  (const long double& number) const noexcept;
		inline bool operator<= (const long double& number) const noexcept;
		inline bool operator>  (const long double& number) const noexcept;
		inline bool operator>= (const long double& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10Ld& other) const noexcept;
		inline bool operator!=(const Vector10Ld& other) const noexcept;
		inline bool operator==(const long double& number)   const noexcept;
		inline bool operator!=(const long double& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long double& stnd_value = 0.0L) noexcept;
		inline long double& operator[](const std::uint8_t& index) noexcept;
		inline long double& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2Ld& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3Ld& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4Ld& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5Ld& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6Ld& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7Ld& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8Ld& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9Ld& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10Ld& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}