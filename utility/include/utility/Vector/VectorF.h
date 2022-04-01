#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::float_t
		Bytes: 4
		Range: 3.4E +/- 38  precision: (7 digits)
	*/

	class Vector2f
	{
	public:
		std::float_t x, y;
	public:
		inline Vector2f(const std::float_t& x = 0.f, const std::float_t& y = 0.f) noexcept;
		// copy
		inline Vector2f(const Vector2f& other) noexcept;
		inline Vector2f& operator=(const Vector2f& other) noexcept;
		// move
		inline Vector2f(Vector2f&& other) noexcept;
		inline Vector2f& operator=(Vector2f&& other) noexcept;
		// assignment
		inline Vector2f& operator=(const std::float_t& number) noexcept;

		// math operator
		inline Vector2f operator +(const Vector2f& v) const noexcept;
		inline Vector2f operator -(const Vector2f& v) const noexcept;
		inline Vector2f operator *(const Vector2f& v) const noexcept;
		inline Vector2f operator /(const Vector2f& v) const noexcept;

		inline Vector2f operator +(const std::float_t& number) const noexcept;
		inline Vector2f operator -(const std::float_t& number) const noexcept;
		inline Vector2f operator *(const std::float_t& number) const noexcept;
		inline Vector2f operator /(const std::float_t& number) const noexcept;

		// increment / decrement
		inline Vector2f& operator++ () noexcept;		// prefix increment
		inline Vector2f& operator-- () noexcept;		// prefix decrement
		inline Vector2f  operator++ (int) noexcept;		// postfix increment
		inline Vector2f  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2f& operator+= (const Vector2f& right) noexcept;
		inline Vector2f& operator-= (const Vector2f& right) noexcept;
		inline Vector2f& operator*= (const Vector2f& right) noexcept;
		inline Vector2f& operator/= (const Vector2f& right) noexcept;

		inline Vector2f& operator+= (const std::float_t& number) noexcept;
		inline Vector2f& operator-= (const std::float_t& number) noexcept;
		inline Vector2f& operator*= (const std::float_t& number) noexcept;
		inline Vector2f& operator/= (const std::float_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2f& other) const noexcept;
		inline bool operator<=  (const Vector2f& other) const noexcept;
		inline bool operator>	(const Vector2f& other) const noexcept;
		inline bool operator>=  (const Vector2f& other) const noexcept;

		inline bool operator<	(const std::float_t& number) const noexcept;
		inline bool operator<=  (const std::float_t& number) const noexcept;
		inline bool operator>	(const std::float_t& number) const noexcept;
		inline bool operator>=  (const std::float_t& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2f& other) const noexcept;
		inline bool operator!=(const Vector2f& other) const noexcept;
		inline bool operator==(const std::float_t& number)  const noexcept;
		inline bool operator!=(const std::float_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::float_t& stnd_value = 0.f) noexcept;
		inline std::float_t& operator[](const std::uint8_t& index) noexcept;
		inline std::float_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector3f
	{
	public:
		std::float_t x, y, z;
	public:
		inline Vector3f(const std::float_t& x = 0.f, const std::float_t& y = 0.f, const std::float_t& z = 0.f) noexcept;
		// copy
		inline Vector3f(const Vector3f& other) noexcept;
		inline Vector3f& operator=(const Vector3f& other) noexcept;
		// move
		inline Vector3f(Vector3f&& other) noexcept;
		inline Vector3f& operator=(Vector3f&& other) noexcept;
		// assignment
		inline Vector3f& operator=(const std::float_t& number) noexcept;

		// math operator
		inline Vector3f operator +(const Vector3f& v) const noexcept;
		inline Vector3f operator -(const Vector3f& v) const noexcept;
		inline Vector3f operator *(const Vector3f& v) const noexcept;
		inline Vector3f operator /(const Vector3f& v) const noexcept;

		inline Vector3f operator +(const std::float_t& number) const noexcept;
		inline Vector3f operator -(const std::float_t& number) const noexcept;
		inline Vector3f operator *(const std::float_t& number) const noexcept;
		inline Vector3f operator /(const std::float_t& number) const noexcept;

		// increment / decrement
		inline Vector3f& operator++ () noexcept;		// prefix increment
		inline Vector3f& operator-- () noexcept;		// prefix decrement
		inline Vector3f  operator++ (int) noexcept;		// postfix increment
		inline Vector3f  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3f& operator+= (const Vector3f& right) noexcept;
		inline Vector3f& operator-= (const Vector3f& right) noexcept;
		inline Vector3f& operator*= (const Vector3f& right) noexcept;
		inline Vector3f& operator/= (const Vector3f& right) noexcept;

		inline Vector3f& operator+= (const std::float_t& number) noexcept;
		inline Vector3f& operator-= (const std::float_t& number) noexcept;
		inline Vector3f& operator*= (const std::float_t& number) noexcept;
		inline Vector3f& operator/= (const std::float_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3f& other) const noexcept;
		inline bool operator<=  (const Vector3f& other) const noexcept;
		inline bool operator>	(const Vector3f& other) const noexcept;
		inline bool operator>=  (const Vector3f& other) const noexcept;
		 
		inline bool operator<	(const std::float_t& number) const noexcept;
		inline bool operator<=  (const std::float_t& number) const noexcept;
		inline bool operator>	(const std::float_t& number) const noexcept;
		inline bool operator>=  (const std::float_t& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3f& other) const noexcept;
		inline bool operator!=(const Vector3f& other) const noexcept;
		inline bool operator==(const std::float_t& number)  const noexcept;
		inline bool operator!=(const std::float_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::float_t& stnd_value = 0.f) noexcept;
		inline std::float_t& operator[](const std::uint8_t& index) noexcept;
		inline std::float_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector4f
	{
	public:
		std::float_t a, b, c, d;
	public:
		inline Vector4f(const std::float_t& a = 0.f, const std::float_t& b = 0.f, const std::float_t& c = 0.f, const std::float_t& d = 0.f) noexcept;
		// copy
		inline Vector4f(const Vector4f& other) noexcept;
		inline Vector4f& operator=(const Vector4f& other) noexcept;
		// move
		inline Vector4f(Vector4f&& other) noexcept;
		inline Vector4f& operator=(Vector4f&& other) noexcept;
		// assignment
		inline Vector4f& operator=(const std::float_t& number) noexcept;
		
		// math operator
		inline Vector4f operator +(const Vector4f& v) const noexcept;
		inline Vector4f operator -(const Vector4f& v) const noexcept;
		inline Vector4f operator *(const Vector4f& v) const noexcept;
		inline Vector4f operator /(const Vector4f& v) const noexcept;
		
		inline Vector4f operator +(const std::float_t& number) const noexcept;
		inline Vector4f operator -(const std::float_t& number) const noexcept;
		inline Vector4f operator *(const std::float_t& number) const noexcept;
		inline Vector4f operator /(const std::float_t& number) const noexcept;
		
		// increment / decrement
		inline Vector4f& operator++ () noexcept;		// prefix increment
		inline Vector4f& operator-- () noexcept;		// prefix decrement
		inline Vector4f  operator++ (int) noexcept;		// postfix increment
		inline Vector4f  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4f& operator+= (const Vector4f& right) noexcept;
		inline Vector4f& operator-= (const Vector4f& right) noexcept;
		inline Vector4f& operator*= (const Vector4f& right) noexcept;
		inline Vector4f& operator/= (const Vector4f& right) noexcept;
		
		inline Vector4f& operator+= (const std::float_t& number) noexcept;
		inline Vector4f& operator-= (const std::float_t& number) noexcept;
		inline Vector4f& operator*= (const std::float_t& number) noexcept;
		inline Vector4f& operator/= (const std::float_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4f& other) const noexcept;
		inline bool operator<=  (const Vector4f& other) const noexcept;
		inline bool operator>	(const Vector4f& other) const noexcept;
		inline bool operator>=  (const Vector4f& other) const noexcept;
		
		inline bool operator<	(const std::float_t& number) const noexcept;
		inline bool operator<=  (const std::float_t& number) const noexcept;
		inline bool operator>	(const std::float_t& number) const noexcept;
		inline bool operator>=  (const std::float_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4f& other) const noexcept;
		inline bool operator!=(const Vector4f& other) const noexcept;
		inline bool operator==(const std::float_t& number)  const noexcept;
		inline bool operator!=(const std::float_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::float_t& stnd_value = 0.f) noexcept;
		inline std::float_t& operator[](const std::uint8_t& index) noexcept;
		inline std::float_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector5f
	{
	public:
		std::float_t a, b, c, d, e;
	public:
		inline Vector5f(const std::float_t& a = 0.f, const std::float_t& b = 0.f, const std::float_t& c = 0.f, const std::float_t& d = 0.f,
			const std::float_t& e = 0.f) noexcept;
		// copy
		inline Vector5f(const Vector5f& other) noexcept;
		inline Vector5f& operator=(const Vector5f& other) noexcept;
		// move
		inline Vector5f(Vector5f&& other) noexcept;
		inline Vector5f& operator=(Vector5f&& other) noexcept;
		// assignment
		inline Vector5f& operator=(const std::float_t& number) noexcept;
		 
		// math operator
		inline Vector5f operator +(const Vector5f& v) const noexcept;
		inline Vector5f operator -(const Vector5f& v) const noexcept;
		inline Vector5f operator *(const Vector5f& v) const noexcept;
		inline Vector5f operator /(const Vector5f& v) const noexcept;
		
		inline Vector5f operator +(const std::float_t& number) const noexcept;
		inline Vector5f operator -(const std::float_t& number) const noexcept;
		inline Vector5f operator *(const std::float_t& number) const noexcept;
		inline Vector5f operator /(const std::float_t& number) const noexcept;
		
		// increment / decrement
		inline Vector5f& operator++ () noexcept;		// prefix increment
		inline Vector5f& operator-- () noexcept;		// prefix decrement
		inline Vector5f  operator++ (int) noexcept;		// postfix increment
		inline Vector5f  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5f& operator+= (const Vector5f& right) noexcept;
		inline Vector5f& operator-= (const Vector5f& right) noexcept;
		inline Vector5f& operator*= (const Vector5f& right) noexcept;
		inline Vector5f& operator/= (const Vector5f& right) noexcept;
		
		inline Vector5f& operator+= (const std::float_t& number) noexcept;
		inline Vector5f& operator-= (const std::float_t& number) noexcept;
		inline Vector5f& operator*= (const std::float_t& number) noexcept;
		inline Vector5f& operator/= (const std::float_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5f& other) const noexcept;
		inline bool operator<=  (const Vector5f& other) const noexcept;
		inline bool operator>	(const Vector5f& other) const noexcept;
		inline bool operator>=  (const Vector5f& other) const noexcept;
		
		inline bool operator<	(const std::float_t& number) const noexcept;
		inline bool operator<=  (const std::float_t& number) const noexcept;
		inline bool operator>	(const std::float_t& number) const noexcept;
		inline bool operator>=  (const std::float_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5f& other) const noexcept;
		inline bool operator!=(const Vector5f& other) const noexcept;
		inline bool operator==(const std::float_t& number)  const noexcept;
		inline bool operator!=(const std::float_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::float_t& stnd_value = 0.f) noexcept;
		inline std::float_t& operator[](const std::uint8_t& index) noexcept;
		inline std::float_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector6f
	{
	public:
		std::float_t a, b, c, d, e, f;
	public:
		inline Vector6f(const std::float_t& a = 0.f, const std::float_t& b = 0.f, const std::float_t& c = 0.f, const std::float_t& d = 0.f,
			const std::float_t& e = 0.f, const std::float_t& f = 0.f) noexcept;
		// copy
		inline Vector6f(const Vector6f& other) noexcept;
		inline Vector6f& operator=(const Vector6f& other) noexcept;
		// move
		inline Vector6f(Vector6f&& other) noexcept;
		inline Vector6f& operator=(Vector6f&& other) noexcept;
		// assignment
		inline Vector6f& operator=(const std::float_t& number) noexcept;
		
		// math operator
		inline Vector6f operator +(const Vector6f& v) const noexcept;
		inline Vector6f operator -(const Vector6f& v) const noexcept;
		inline Vector6f operator *(const Vector6f& v) const noexcept;
		inline Vector6f operator /(const Vector6f& v) const noexcept;
		
		inline Vector6f operator +(const std::float_t& number) const noexcept;
		inline Vector6f operator -(const std::float_t& number) const noexcept;
		inline Vector6f operator *(const std::float_t& number) const noexcept;
		inline Vector6f operator /(const std::float_t& number) const noexcept;
		
		// increment / decrement
		inline Vector6f& operator++ () noexcept;		// prefix increment
		inline Vector6f& operator-- () noexcept;		// prefix decrement
		inline Vector6f  operator++ (int) noexcept;		// postfix increment
		inline Vector6f  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6f& operator+= (const Vector6f& right) noexcept;
		inline Vector6f& operator-= (const Vector6f& right) noexcept;
		inline Vector6f& operator*= (const Vector6f& right) noexcept;
		inline Vector6f& operator/= (const Vector6f& right) noexcept;
		
		inline Vector6f& operator+= (const std::float_t& number) noexcept;
		inline Vector6f& operator-= (const std::float_t& number) noexcept;
		inline Vector6f& operator*= (const std::float_t& number) noexcept;
		inline Vector6f& operator/= (const std::float_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6f& other) const noexcept;
		inline bool operator<  (const Vector6f& other) const noexcept;
		inline bool operator>  (const Vector6f& other) const noexcept;
		inline bool operator>= (const Vector6f& other) const noexcept;
		
		inline bool operator<  (const std::float_t& number) const noexcept;
		inline bool operator<= (const std::float_t& number) const noexcept;
		inline bool operator>  (const std::float_t& number) const noexcept;
		inline bool operator>= (const std::float_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6f& other) const noexcept;
		inline bool operator!=(const Vector6f& other) const noexcept;
		inline bool operator==(const std::float_t& number)  const noexcept;
		inline bool operator!=(const std::float_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::float_t& stnd_value = 0.f) noexcept;
		inline std::float_t& operator[](const std::uint8_t& index) noexcept;
		inline std::float_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector7f
	{
	public:
		std::float_t a, b, c, d, e, f, g;
	public:
		inline Vector7f(const std::float_t& a = 0.f, const std::float_t& b = 0.f, const std::float_t& c = 0.f, const std::float_t& d = 0.f,
			const std::float_t& e = 0.f, const std::float_t& f = 0.f, const std::float_t& g = 0.f) noexcept;
		// copy
		inline Vector7f(const Vector7f& other) noexcept;
		inline Vector7f& operator=(const Vector7f& other) noexcept;
		// move
		inline Vector7f(Vector7f&& other) noexcept;
		inline Vector7f& operator=(Vector7f&& other) noexcept;
		// assignment
		inline Vector7f& operator=(const std::float_t& number) noexcept;
		
		// math operator
		inline Vector7f operator +(const Vector7f& v) const noexcept;
		inline Vector7f operator -(const Vector7f& v) const noexcept;
		inline Vector7f operator *(const Vector7f& v) const noexcept;
		inline Vector7f operator /(const Vector7f& v) const noexcept;
		
		inline Vector7f operator +(const std::float_t& number) const noexcept;
		inline Vector7f operator -(const std::float_t& number) const noexcept;
		inline Vector7f operator *(const std::float_t& number) const noexcept;
		inline Vector7f operator /(const std::float_t& number) const noexcept;
		
		// increment / decrement
		inline Vector7f& operator++ () noexcept;		// prefix increment
		inline Vector7f& operator-- () noexcept;		// prefix decrement
		inline Vector7f  operator++ (int) noexcept;		// postfix increment
		inline Vector7f  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7f& operator+= (const Vector7f& right) noexcept;
		inline Vector7f& operator-= (const Vector7f& right) noexcept;
		inline Vector7f& operator*= (const Vector7f& right) noexcept;
		inline Vector7f& operator/= (const Vector7f& right) noexcept;
		
		inline Vector7f& operator+= (const std::float_t& number) noexcept;
		inline Vector7f& operator-= (const std::float_t& number) noexcept;
		inline Vector7f& operator*= (const std::float_t& number) noexcept;
		inline Vector7f& operator/= (const std::float_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7f& other) const noexcept;
		inline bool operator<  (const Vector7f& other) const noexcept;
		inline bool operator>  (const Vector7f& other) const noexcept;
		inline bool operator>= (const Vector7f& other) const noexcept;
		
		inline bool operator<  (const std::float_t& number) const noexcept;
		inline bool operator<= (const std::float_t& number) const noexcept;
		inline bool operator>  (const std::float_t& number) const noexcept;
		inline bool operator>= (const std::float_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7f& other) const noexcept;
		inline bool operator!=(const Vector7f& other) const noexcept;
		inline bool operator==(const std::float_t& number)  const noexcept;
		inline bool operator!=(const std::float_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::float_t& stnd_value = 0.f) noexcept;
		inline std::float_t& operator[](const std::uint8_t& index) noexcept;
		inline std::float_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector8f
	{
	public:
		std::float_t a, b, c, d, e, f, g, h;
	public:
		inline Vector8f(const std::float_t& a = 0.f, const std::float_t& b = 0.f, const std::float_t& c = 0.f, const std::float_t& d = 0.f,
			const std::float_t& e = 0.f, const std::float_t& f = 0.f, const std::float_t& g = 0.f, const std::float_t& h = 0.f) noexcept;
		// copy
		inline Vector8f(const Vector8f& other) noexcept;
		inline Vector8f& operator=(const Vector8f& other) noexcept;
		// move
		inline Vector8f(Vector8f&& other) noexcept;
		inline Vector8f& operator=(Vector8f&& other) noexcept;
		// assignment
		inline Vector8f& operator=(const std::float_t& number) noexcept;
		
		// math operator
		inline Vector8f operator +(const Vector8f& v) const noexcept;
		inline Vector8f operator -(const Vector8f& v) const noexcept;
		inline Vector8f operator *(const Vector8f& v) const noexcept;
		inline Vector8f operator /(const Vector8f& v) const noexcept;
		
		inline Vector8f operator +(const std::float_t& number) const noexcept;
		inline Vector8f operator -(const std::float_t& number) const noexcept;
		inline Vector8f operator *(const std::float_t& number) const noexcept;
		inline Vector8f operator /(const std::float_t& number) const noexcept;
		
		// increment / decrement
		inline Vector8f& operator++ () noexcept;		// prefix increment
		inline Vector8f& operator-- () noexcept;		// prefix decrement
		inline Vector8f  operator++ (int) noexcept;		// postfix increment
		inline Vector8f  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8f& operator+= (const Vector8f& right) noexcept;
		inline Vector8f& operator-= (const Vector8f& right) noexcept;
		inline Vector8f& operator*= (const Vector8f& right) noexcept;
		inline Vector8f& operator/= (const Vector8f& right) noexcept;
		
		inline Vector8f& operator+= (const std::float_t& number) noexcept;
		inline Vector8f& operator-= (const std::float_t& number) noexcept;
		inline Vector8f& operator*= (const std::float_t& number) noexcept;
		inline Vector8f& operator/= (const std::float_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8f& other) const noexcept;
		inline bool operator<  (const Vector8f& other) const noexcept;
		inline bool operator>  (const Vector8f& other) const noexcept;
		inline bool operator>= (const Vector8f& other) const noexcept;
		
		inline bool operator<  (const std::float_t& number) const noexcept;
		inline bool operator<= (const std::float_t& number) const noexcept;
		inline bool operator>  (const std::float_t& number) const noexcept;
		inline bool operator>= (const std::float_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8f& other) const noexcept;
		inline bool operator!=(const Vector8f& other) const noexcept;
		inline bool operator==(const std::float_t& number)  const noexcept;
		inline bool operator!=(const std::float_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::float_t& stnd_value = 0.f) noexcept;
		inline std::float_t& operator[](const std::uint8_t& index) noexcept;
		inline std::float_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector9f
	{
	public:
		std::float_t a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9f(const std::float_t& a = 0.f, const std::float_t& b = 0.f, const std::float_t& c = 0.f, const std::float_t& d = 0.f,
			const std::float_t& e = 0.f, const std::float_t& f = 0.f, const std::float_t& g = 0.f, const std::float_t& h = 0.f,
			const std::float_t& i = 0.f) noexcept;
		// copy
		inline Vector9f(const Vector9f& other) noexcept;
		inline Vector9f& operator=(const Vector9f& other) noexcept;
		// move
		inline Vector9f(Vector9f&& other) noexcept;
		inline Vector9f& operator=(Vector9f&& other) noexcept;
		// assignment
		inline Vector9f& operator=(const std::float_t& number) noexcept;
		
		// math operator
		inline Vector9f operator +(const Vector9f& v) const noexcept;
		inline Vector9f operator -(const Vector9f& v) const noexcept;
		inline Vector9f operator *(const Vector9f& v) const noexcept;
		inline Vector9f operator /(const Vector9f& v) const noexcept;
		
		inline Vector9f operator +(const std::float_t& number) const noexcept;
		inline Vector9f operator -(const std::float_t& number) const noexcept;
		inline Vector9f operator *(const std::float_t& number) const noexcept;
		inline Vector9f operator /(const std::float_t& number) const noexcept;
		
		// increment / decrement
		inline Vector9f& operator++ () noexcept;		// prefix increment
		inline Vector9f& operator-- () noexcept;		// prefix decrement
		inline Vector9f  operator++ (int) noexcept;		// postfix increment
		inline Vector9f  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9f& operator+= (const Vector9f& right) noexcept;
		inline Vector9f& operator-= (const Vector9f& right) noexcept;
		inline Vector9f& operator*= (const Vector9f& right) noexcept;
		inline Vector9f& operator/= (const Vector9f& right) noexcept;
		
		inline Vector9f& operator+= (const std::float_t& number) noexcept;
		inline Vector9f& operator-= (const std::float_t& number) noexcept;
		inline Vector9f& operator*= (const std::float_t& number) noexcept;
		inline Vector9f& operator/= (const std::float_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9f& other) const noexcept;
		inline bool operator<  (const Vector9f& other) const noexcept;
		inline bool operator>  (const Vector9f& other) const noexcept;
		inline bool operator>= (const Vector9f& other) const noexcept;
		
		inline bool operator<  (const std::float_t& number) const noexcept;
		inline bool operator<= (const std::float_t& number) const noexcept;
		inline bool operator>  (const std::float_t& number) const noexcept;
		inline bool operator>= (const std::float_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9f& other) const noexcept;
		inline bool operator!=(const Vector9f& other) const noexcept;
		inline bool operator==(const std::float_t& number)  const noexcept;
		inline bool operator!=(const std::float_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::float_t& stnd_value = 0.f) noexcept;
		inline std::float_t& operator[](const std::uint8_t& index) noexcept;
		inline std::float_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector10f
	{
	public:
		std::float_t a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10f(const std::float_t& a = 0.f, const std::float_t& b = 0.f, const std::float_t& c = 0.f, const std::float_t& d = 0.f,
			const std::float_t& e = 0.f, const std::float_t& f = 0.f, const std::float_t& g = 0.f, const std::float_t& h = 0.f,
			const std::float_t& i = 0.f, const std::float_t& j = 0.f) noexcept;
		// copy
		inline Vector10f(const Vector10f& other) noexcept;
		inline Vector10f& operator=(const Vector10f& other) noexcept;
		// move
		inline Vector10f(Vector10f&& other) noexcept;
		inline Vector10f& operator=(Vector10f&& other) noexcept;
		// assignment
		inline Vector10f& operator=(const std::float_t& number) noexcept;
		
		// math operator
		inline Vector10f operator +(const Vector10f& v) const noexcept;
		inline Vector10f operator -(const Vector10f& v) const noexcept;
		inline Vector10f operator *(const Vector10f& v) const noexcept;
		inline Vector10f operator /(const Vector10f& v) const noexcept;
		
		inline Vector10f operator +(const std::float_t& number) const noexcept;
		inline Vector10f operator -(const std::float_t& number) const noexcept;
		inline Vector10f operator *(const std::float_t& number) const noexcept;
		inline Vector10f operator /(const std::float_t& number) const noexcept;
		
		// increment / decrement
		inline Vector10f& operator++ () noexcept;		// prefix increment
		inline Vector10f& operator-- () noexcept;		// prefix decrement
		inline Vector10f  operator++ (int) noexcept;	// postfix increment
		inline Vector10f  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10f& operator+= (const Vector10f& right) noexcept;
		inline Vector10f& operator-= (const Vector10f& right) noexcept;
		inline Vector10f& operator*= (const Vector10f& right) noexcept;
		inline Vector10f& operator/= (const Vector10f& right) noexcept;
		
		inline Vector10f& operator+= (const std::float_t& number) noexcept;
		inline Vector10f& operator-= (const std::float_t& number) noexcept;
		inline Vector10f& operator*= (const std::float_t& number) noexcept;
		inline Vector10f& operator/= (const std::float_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10f& other) const noexcept;
		inline bool operator<  (const Vector10f& other) const noexcept;
		inline bool operator>  (const Vector10f& other) const noexcept;
		inline bool operator>= (const Vector10f& other) const noexcept;

		inline bool operator<  (const std::float_t& number) const noexcept;
		inline bool operator<= (const std::float_t& number) const noexcept;
		inline bool operator>  (const std::float_t& number) const noexcept;
		inline bool operator>= (const std::float_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10f& other) const noexcept;
		inline bool operator!=(const Vector10f& other) const noexcept;
		inline bool operator==(const std::float_t& number)   const noexcept;
		inline bool operator!=(const std::float_t& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::float_t& stnd_value = 0.f) noexcept;
		inline std::float_t& operator[](const std::uint8_t& index) noexcept;
		inline std::float_t& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2f& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3f& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4f& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5f& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6f& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7f& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8f& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9f& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10f& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}