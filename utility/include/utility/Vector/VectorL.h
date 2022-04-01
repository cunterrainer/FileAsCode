#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : long
		Bytes: 4
		Range: -2.147.483.648 to 2.147.483.647
	*/

	class Vector2l
	{
	public:
		long x, y;
	public:
		inline Vector2l(const long& x = 0L, const long& y = 0L) noexcept;
		// copy
		inline Vector2l(const Vector2l& other) noexcept;
		inline Vector2l& operator=(const Vector2l& other) noexcept;
		// move
		inline Vector2l(Vector2l&& other) noexcept;
		inline Vector2l& operator=(Vector2l&& other) noexcept;
		// assignment
		inline Vector2l& operator=(const long& number) noexcept;

		// math operator
		inline Vector2l operator +(const Vector2l& v) const noexcept;
		inline Vector2l operator -(const Vector2l& v) const noexcept;
		inline Vector2l operator *(const Vector2l& v) const noexcept;
		inline Vector2l operator /(const Vector2l& v) const noexcept;

		inline Vector2l operator +(const long& number) const noexcept;
		inline Vector2l operator -(const long& number) const noexcept;
		inline Vector2l operator *(const long& number) const noexcept;
		inline Vector2l operator /(const long& number) const noexcept;

		// increment / decrement
		inline Vector2l& operator++ () noexcept;		// prefix increment
		inline Vector2l& operator-- () noexcept;		// prefix decrement
		inline Vector2l  operator++ (int) noexcept;		// postfix increment
		inline Vector2l  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2l& operator+= (const Vector2l& right) noexcept;
		inline Vector2l& operator-= (const Vector2l& right) noexcept;
		inline Vector2l& operator*= (const Vector2l& right) noexcept;
		inline Vector2l& operator/= (const Vector2l& right) noexcept;

		inline Vector2l& operator+= (const long& number) noexcept;
		inline Vector2l& operator-= (const long& number) noexcept;
		inline Vector2l& operator*= (const long& number) noexcept;
		inline Vector2l& operator/= (const long& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2l& other) const noexcept;
		inline bool operator<=  (const Vector2l& other) const noexcept;
		inline bool operator>	(const Vector2l& other) const noexcept;
		inline bool operator>=  (const Vector2l& other) const noexcept;

		inline bool operator<	(const long& number) const noexcept;
		inline bool operator<=  (const long& number) const noexcept;
		inline bool operator>	(const long& number) const noexcept;
		inline bool operator>=  (const long& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2l& other) const noexcept;
		inline bool operator!=(const Vector2l& other) const noexcept;
		inline bool operator==(const long& number)  const noexcept;
		inline bool operator!=(const long& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long& stnd_value = 0L) noexcept;
		inline long& operator[](const std::uint8_t& index) noexcept;
		inline long& at(const std::uint8_t& index) noexcept;
	};


	class Vector3l
	{
	public:
		long x, y, z;
	public:
		inline Vector3l(const long& x = 0L, const long& y = 0L, const long& z = 0L) noexcept;
		// copy
		inline Vector3l(const Vector3l& other) noexcept;
		inline Vector3l& operator=(const Vector3l& other) noexcept;
		// move
		inline Vector3l(Vector3l&& other) noexcept;
		inline Vector3l& operator=(Vector3l&& other) noexcept;
		// assignment
		inline Vector3l& operator=(const long& number) noexcept;

		// math operator
		inline Vector3l operator +(const Vector3l& v) const noexcept;
		inline Vector3l operator -(const Vector3l& v) const noexcept;
		inline Vector3l operator *(const Vector3l& v) const noexcept;
		inline Vector3l operator /(const Vector3l& v) const noexcept;

		inline Vector3l operator +(const long& number) const noexcept;
		inline Vector3l operator -(const long& number) const noexcept;
		inline Vector3l operator *(const long& number) const noexcept;
		inline Vector3l operator /(const long& number) const noexcept;

		// increment / decrement
		inline Vector3l& operator++ () noexcept;		// prefix increment
		inline Vector3l& operator-- () noexcept;		// prefix decrement
		inline Vector3l  operator++ (int) noexcept;		// postfix increment
		inline Vector3l  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3l& operator+= (const Vector3l& right) noexcept;
		inline Vector3l& operator-= (const Vector3l& right) noexcept;
		inline Vector3l& operator*= (const Vector3l& right) noexcept;
		inline Vector3l& operator/= (const Vector3l& right) noexcept;

		inline Vector3l& operator+= (const long& number) noexcept;
		inline Vector3l& operator-= (const long& number) noexcept;
		inline Vector3l& operator*= (const long& number) noexcept;
		inline Vector3l& operator/= (const long& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3l& other) const noexcept;
		inline bool operator<=  (const Vector3l& other) const noexcept;
		inline bool operator>	(const Vector3l& other) const noexcept;
		inline bool operator>=  (const Vector3l& other) const noexcept;
		 
		inline bool operator<	(const long& number) const noexcept;
		inline bool operator<=  (const long& number) const noexcept;
		inline bool operator>	(const long& number) const noexcept;
		inline bool operator>=  (const long& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3l& other) const noexcept;
		inline bool operator!=(const Vector3l& other) const noexcept;
		inline bool operator==(const long& number)  const noexcept;
		inline bool operator!=(const long& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long& stnd_value = 0L) noexcept;
		inline long& operator[](const std::uint8_t& index) noexcept;
		inline long& at(const std::uint8_t& index) noexcept;
	};


	class Vector4l
	{
	public:
		long a, b, c, d;
	public:
		inline Vector4l(const long& a = 0L, const long& b = 0L, const long& c = 0L, const long& d = 0L) noexcept;
		// copy
		inline Vector4l(const Vector4l& other) noexcept;
		inline Vector4l& operator=(const Vector4l& other) noexcept;
		// move
		inline Vector4l(Vector4l&& other) noexcept;
		inline Vector4l& operator=(Vector4l&& other) noexcept;
		// assignment
		inline Vector4l& operator=(const long& number) noexcept;
		
		// math operator
		inline Vector4l operator +(const Vector4l& v) const noexcept;
		inline Vector4l operator -(const Vector4l& v) const noexcept;
		inline Vector4l operator *(const Vector4l& v) const noexcept;
		inline Vector4l operator /(const Vector4l& v) const noexcept;
		
		inline Vector4l operator +(const long& number) const noexcept;
		inline Vector4l operator -(const long& number) const noexcept;
		inline Vector4l operator *(const long& number) const noexcept;
		inline Vector4l operator /(const long& number) const noexcept;
		
		// increment / decrement
		inline Vector4l& operator++ () noexcept;		// prefix increment
		inline Vector4l& operator-- () noexcept;		// prefix decrement
		inline Vector4l  operator++ (int) noexcept;		// postfix increment
		inline Vector4l  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4l& operator+= (const Vector4l& right) noexcept;
		inline Vector4l& operator-= (const Vector4l& right) noexcept;
		inline Vector4l& operator*= (const Vector4l& right) noexcept;
		inline Vector4l& operator/= (const Vector4l& right) noexcept;
		
		inline Vector4l& operator+= (const long& number) noexcept;
		inline Vector4l& operator-= (const long& number) noexcept;
		inline Vector4l& operator*= (const long& number) noexcept;
		inline Vector4l& operator/= (const long& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4l& other) const noexcept;
		inline bool operator<=  (const Vector4l& other) const noexcept;
		inline bool operator>	(const Vector4l& other) const noexcept;
		inline bool operator>=  (const Vector4l& other) const noexcept;
		
		inline bool operator<	(const long& number) const noexcept;
		inline bool operator<=  (const long& number) const noexcept;
		inline bool operator>	(const long& number) const noexcept;
		inline bool operator>=  (const long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4l& other) const noexcept;
		inline bool operator!=(const Vector4l& other) const noexcept;
		inline bool operator==(const long& number)  const noexcept;
		inline bool operator!=(const long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long& stnd_value = 0L) noexcept;
		inline long& operator[](const std::uint8_t& index) noexcept;
		inline long& at(const std::uint8_t& index) noexcept;
	};


	class Vector5l
	{
	public:
		long a, b, c, d, e;
	public:
		inline Vector5l(const long& a = 0L, const long& b = 0L, const long& c = 0L, const long& d = 0L,
			const long& e = 0L) noexcept;
		// copy
		inline Vector5l(const Vector5l& other) noexcept;
		inline Vector5l& operator=(const Vector5l& other) noexcept;
		// move
		inline Vector5l(Vector5l&& other) noexcept;
		inline Vector5l& operator=(Vector5l&& other) noexcept;
		// assignment
		inline Vector5l& operator=(const long& number) noexcept;
		 
		// math operator
		inline Vector5l operator +(const Vector5l& v) const noexcept;
		inline Vector5l operator -(const Vector5l& v) const noexcept;
		inline Vector5l operator *(const Vector5l& v) const noexcept;
		inline Vector5l operator /(const Vector5l& v) const noexcept;
		
		inline Vector5l operator +(const long& number) const noexcept;
		inline Vector5l operator -(const long& number) const noexcept;
		inline Vector5l operator *(const long& number) const noexcept;
		inline Vector5l operator /(const long& number) const noexcept;
		
		// increment / decrement
		inline Vector5l& operator++ () noexcept;		// prefix increment
		inline Vector5l& operator-- () noexcept;		// prefix decrement
		inline Vector5l  operator++ (int) noexcept;		// postfix increment
		inline Vector5l  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5l& operator+= (const Vector5l& right) noexcept;
		inline Vector5l& operator-= (const Vector5l& right) noexcept;
		inline Vector5l& operator*= (const Vector5l& right) noexcept;
		inline Vector5l& operator/= (const Vector5l& right) noexcept;
		
		inline Vector5l& operator+= (const long& number) noexcept;
		inline Vector5l& operator-= (const long& number) noexcept;
		inline Vector5l& operator*= (const long& number) noexcept;
		inline Vector5l& operator/= (const long& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5l& other) const noexcept;
		inline bool operator<=  (const Vector5l& other) const noexcept;
		inline bool operator>	(const Vector5l& other) const noexcept;
		inline bool operator>=  (const Vector5l& other) const noexcept;
		
		inline bool operator<	(const long& number) const noexcept;
		inline bool operator<=  (const long& number) const noexcept;
		inline bool operator>	(const long& number) const noexcept;
		inline bool operator>=  (const long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5l& other) const noexcept;
		inline bool operator!=(const Vector5l& other) const noexcept;
		inline bool operator==(const long& number)  const noexcept;
		inline bool operator!=(const long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long& stnd_value = 0L) noexcept;
		inline long& operator[](const std::uint8_t& index) noexcept;
		inline long& at(const std::uint8_t& index) noexcept;
	};


	class Vector6l
	{
	public:
		long a, b, c, d, e, f;
	public:
		inline Vector6l(const long& a = 0L, const long& b = 0L, const long& c = 0L, const long& d = 0L,
			const long& e = 0L, const long& f = 0L) noexcept;
		// copy
		inline Vector6l(const Vector6l& other) noexcept;
		inline Vector6l& operator=(const Vector6l& other) noexcept;
		// move
		inline Vector6l(Vector6l&& other) noexcept;
		inline Vector6l& operator=(Vector6l&& other) noexcept;
		// assignment
		inline Vector6l& operator=(const long& number) noexcept;
		
		// math operator
		inline Vector6l operator +(const Vector6l& v) const noexcept;
		inline Vector6l operator -(const Vector6l& v) const noexcept;
		inline Vector6l operator *(const Vector6l& v) const noexcept;
		inline Vector6l operator /(const Vector6l& v) const noexcept;
		
		inline Vector6l operator +(const long& number) const noexcept;
		inline Vector6l operator -(const long& number) const noexcept;
		inline Vector6l operator *(const long& number) const noexcept;
		inline Vector6l operator /(const long& number) const noexcept;
		
		// increment / decrement
		inline Vector6l& operator++ () noexcept;		// prefix increment
		inline Vector6l& operator-- () noexcept;		// prefix decrement
		inline Vector6l  operator++ (int) noexcept;		// postfix increment
		inline Vector6l  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6l& operator+= (const Vector6l& right) noexcept;
		inline Vector6l& operator-= (const Vector6l& right) noexcept;
		inline Vector6l& operator*= (const Vector6l& right) noexcept;
		inline Vector6l& operator/= (const Vector6l& right) noexcept;
		
		inline Vector6l& operator+= (const long& number) noexcept;
		inline Vector6l& operator-= (const long& number) noexcept;
		inline Vector6l& operator*= (const long& number) noexcept;
		inline Vector6l& operator/= (const long& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6l& other) const noexcept;
		inline bool operator<  (const Vector6l& other) const noexcept;
		inline bool operator>  (const Vector6l& other) const noexcept;
		inline bool operator>= (const Vector6l& other) const noexcept;
		
		inline bool operator<  (const long& number) const noexcept;
		inline bool operator<= (const long& number) const noexcept;
		inline bool operator>  (const long& number) const noexcept;
		inline bool operator>= (const long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6l& other) const noexcept;
		inline bool operator!=(const Vector6l& other) const noexcept;
		inline bool operator==(const long& number)  const noexcept;
		inline bool operator!=(const long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long& stnd_value = 0L) noexcept;
		inline long& operator[](const std::uint8_t& index) noexcept;
		inline long& at(const std::uint8_t& index) noexcept;
	};


	class Vector7l
	{
	public:
		long a, b, c, d, e, f, g;
	public:
		inline Vector7l(const long& a = 0L, const long& b = 0L, const long& c = 0L, const long& d = 0L,
			const long& e = 0L, const long& f = 0L, const long& g = 0L) noexcept;
		// copy
		inline Vector7l(const Vector7l& other) noexcept;
		inline Vector7l& operator=(const Vector7l& other) noexcept;
		// move
		inline Vector7l(Vector7l&& other) noexcept;
		inline Vector7l& operator=(Vector7l&& other) noexcept;
		// assignment
		inline Vector7l& operator=(const long& number) noexcept;
		
		// math operator
		inline Vector7l operator +(const Vector7l& v) const noexcept;
		inline Vector7l operator -(const Vector7l& v) const noexcept;
		inline Vector7l operator *(const Vector7l& v) const noexcept;
		inline Vector7l operator /(const Vector7l& v) const noexcept;
		
		inline Vector7l operator +(const long& number) const noexcept;
		inline Vector7l operator -(const long& number) const noexcept;
		inline Vector7l operator *(const long& number) const noexcept;
		inline Vector7l operator /(const long& number) const noexcept;
		
		// increment / decrement
		inline Vector7l& operator++ () noexcept;		// prefix increment
		inline Vector7l& operator-- () noexcept;		// prefix decrement
		inline Vector7l  operator++ (int) noexcept;		// postfix increment
		inline Vector7l  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7l& operator+= (const Vector7l& right) noexcept;
		inline Vector7l& operator-= (const Vector7l& right) noexcept;
		inline Vector7l& operator*= (const Vector7l& right) noexcept;
		inline Vector7l& operator/= (const Vector7l& right) noexcept;
		
		inline Vector7l& operator+= (const long& number) noexcept;
		inline Vector7l& operator-= (const long& number) noexcept;
		inline Vector7l& operator*= (const long& number) noexcept;
		inline Vector7l& operator/= (const long& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7l& other) const noexcept;
		inline bool operator<  (const Vector7l& other) const noexcept;
		inline bool operator>  (const Vector7l& other) const noexcept;
		inline bool operator>= (const Vector7l& other) const noexcept;
		
		inline bool operator<  (const long& number) const noexcept;
		inline bool operator<= (const long& number) const noexcept;
		inline bool operator>  (const long& number) const noexcept;
		inline bool operator>= (const long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7l& other) const noexcept;
		inline bool operator!=(const Vector7l& other) const noexcept;
		inline bool operator==(const long& number)  const noexcept;
		inline bool operator!=(const long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long& stnd_value = 0L) noexcept;
		inline long& operator[](const std::uint8_t& index) noexcept;
		inline long& at(const std::uint8_t& index) noexcept;
	};


	class Vector8l
	{
	public:
		long a, b, c, d, e, f, g, h;
	public:
		inline Vector8l(const long& a = 0L, const long& b = 0L, const long& c = 0L, const long& d = 0L,
			const long& e = 0L, const long& f = 0L, const long& g = 0L, const long& h = 0L) noexcept;
		// copy
		inline Vector8l(const Vector8l& other) noexcept;
		inline Vector8l& operator=(const Vector8l& other) noexcept;
		// move
		inline Vector8l(Vector8l&& other) noexcept;
		inline Vector8l& operator=(Vector8l&& other) noexcept;
		// assignment
		inline Vector8l& operator=(const long& number) noexcept;
		
		// math operator
		inline Vector8l operator +(const Vector8l& v) const noexcept;
		inline Vector8l operator -(const Vector8l& v) const noexcept;
		inline Vector8l operator *(const Vector8l& v) const noexcept;
		inline Vector8l operator /(const Vector8l& v) const noexcept;
		
		inline Vector8l operator +(const long& number) const noexcept;
		inline Vector8l operator -(const long& number) const noexcept;
		inline Vector8l operator *(const long& number) const noexcept;
		inline Vector8l operator /(const long& number) const noexcept;
		
		// increment / decrement
		inline Vector8l& operator++ () noexcept;		// prefix increment
		inline Vector8l& operator-- () noexcept;		// prefix decrement
		inline Vector8l  operator++ (int) noexcept;		// postfix increment
		inline Vector8l  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8l& operator+= (const Vector8l& right) noexcept;
		inline Vector8l& operator-= (const Vector8l& right) noexcept;
		inline Vector8l& operator*= (const Vector8l& right) noexcept;
		inline Vector8l& operator/= (const Vector8l& right) noexcept;
		
		inline Vector8l& operator+= (const long& number) noexcept;
		inline Vector8l& operator-= (const long& number) noexcept;
		inline Vector8l& operator*= (const long& number) noexcept;
		inline Vector8l& operator/= (const long& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8l& other) const noexcept;
		inline bool operator<  (const Vector8l& other) const noexcept;
		inline bool operator>  (const Vector8l& other) const noexcept;
		inline bool operator>= (const Vector8l& other) const noexcept;
		
		inline bool operator<  (const long& number) const noexcept;
		inline bool operator<= (const long& number) const noexcept;
		inline bool operator>  (const long& number) const noexcept;
		inline bool operator>= (const long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8l& other) const noexcept;
		inline bool operator!=(const Vector8l& other) const noexcept;
		inline bool operator==(const long& number)  const noexcept;
		inline bool operator!=(const long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long& stnd_value = 0L) noexcept;
		inline long& operator[](const std::uint8_t& index) noexcept;
		inline long& at(const std::uint8_t& index) noexcept;
	};


	class Vector9l
	{
	public:
		long a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9l(const long& a = 0L, const long& b = 0L, const long& c = 0L, const long& d = 0L,
			const long& e = 0L, const long& f = 0L, const long& g = 0L, const long& h = 0L,
			const long& i = 0L) noexcept;
		// copy
		inline Vector9l(const Vector9l& other) noexcept;
		inline Vector9l& operator=(const Vector9l& other) noexcept;
		// move
		inline Vector9l(Vector9l&& other) noexcept;
		inline Vector9l& operator=(Vector9l&& other) noexcept;
		// assignment
		inline Vector9l& operator=(const long& number) noexcept;
		
		// math operator
		inline Vector9l operator +(const Vector9l& v) const noexcept;
		inline Vector9l operator -(const Vector9l& v) const noexcept;
		inline Vector9l operator *(const Vector9l& v) const noexcept;
		inline Vector9l operator /(const Vector9l& v) const noexcept;
		
		inline Vector9l operator +(const long& number) const noexcept;
		inline Vector9l operator -(const long& number) const noexcept;
		inline Vector9l operator *(const long& number) const noexcept;
		inline Vector9l operator /(const long& number) const noexcept;
		
		// increment / decrement
		inline Vector9l& operator++ () noexcept;		// prefix increment
		inline Vector9l& operator-- () noexcept;		// prefix decrement
		inline Vector9l  operator++ (int) noexcept;		// postfix increment
		inline Vector9l  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9l& operator+= (const Vector9l& right) noexcept;
		inline Vector9l& operator-= (const Vector9l& right) noexcept;
		inline Vector9l& operator*= (const Vector9l& right) noexcept;
		inline Vector9l& operator/= (const Vector9l& right) noexcept;
		
		inline Vector9l& operator+= (const long& number) noexcept;
		inline Vector9l& operator-= (const long& number) noexcept;
		inline Vector9l& operator*= (const long& number) noexcept;
		inline Vector9l& operator/= (const long& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9l& other) const noexcept;
		inline bool operator<  (const Vector9l& other) const noexcept;
		inline bool operator>  (const Vector9l& other) const noexcept;
		inline bool operator>= (const Vector9l& other) const noexcept;
		
		inline bool operator<  (const long& number) const noexcept;
		inline bool operator<= (const long& number) const noexcept;
		inline bool operator>  (const long& number) const noexcept;
		inline bool operator>= (const long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9l& other) const noexcept;
		inline bool operator!=(const Vector9l& other) const noexcept;
		inline bool operator==(const long& number)  const noexcept;
		inline bool operator!=(const long& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long& stnd_value = 0L) noexcept;
		inline long& operator[](const std::uint8_t& index) noexcept;
		inline long& at(const std::uint8_t& index) noexcept;
	};


	class Vector10l
	{
	public:
		long a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10l(const long& a = 0L, const long& b = 0L, const long& c = 0L, const long& d = 0L,
			const long& e = 0L, const long& f = 0L, const long& g = 0L, const long& h = 0L,
			const long& i = 0L, const long& j = 0L) noexcept;
		// copy
		inline Vector10l(const Vector10l& other) noexcept;
		inline Vector10l& operator=(const Vector10l& other) noexcept;
		// move
		inline Vector10l(Vector10l&& other) noexcept;
		inline Vector10l& operator=(Vector10l&& other) noexcept;
		// assignment
		inline Vector10l& operator=(const long& number) noexcept;
		
		// math operator
		inline Vector10l operator +(const Vector10l& v) const noexcept;
		inline Vector10l operator -(const Vector10l& v) const noexcept;
		inline Vector10l operator *(const Vector10l& v) const noexcept;
		inline Vector10l operator /(const Vector10l& v) const noexcept;
		
		inline Vector10l operator +(const long& number) const noexcept;
		inline Vector10l operator -(const long& number) const noexcept;
		inline Vector10l operator *(const long& number) const noexcept;
		inline Vector10l operator /(const long& number) const noexcept;
		
		// increment / decrement
		inline Vector10l& operator++ () noexcept;		// prefix increment
		inline Vector10l& operator-- () noexcept;		// prefix decrement
		inline Vector10l  operator++ (int) noexcept;	// postfix increment
		inline Vector10l  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10l& operator+= (const Vector10l& right) noexcept;
		inline Vector10l& operator-= (const Vector10l& right) noexcept;
		inline Vector10l& operator*= (const Vector10l& right) noexcept;
		inline Vector10l& operator/= (const Vector10l& right) noexcept;
		
		inline Vector10l& operator+= (const long& number) noexcept;
		inline Vector10l& operator-= (const long& number) noexcept;
		inline Vector10l& operator*= (const long& number) noexcept;
		inline Vector10l& operator/= (const long& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10l& other) const noexcept;
		inline bool operator<  (const Vector10l& other) const noexcept;
		inline bool operator>  (const Vector10l& other) const noexcept;
		inline bool operator>= (const Vector10l& other) const noexcept;

		inline bool operator<  (const long& number) const noexcept;
		inline bool operator<= (const long& number) const noexcept;
		inline bool operator>  (const long& number) const noexcept;
		inline bool operator>= (const long& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10l& other) const noexcept;
		inline bool operator!=(const Vector10l& other) const noexcept;
		inline bool operator==(const long& number)   const noexcept;
		inline bool operator!=(const long& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const long& stnd_value = 0L) noexcept;
		inline long& operator[](const std::uint8_t& index) noexcept;
		inline long& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2l& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3l& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4l& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5l& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6l& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7l& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8l& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9l& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10l& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}