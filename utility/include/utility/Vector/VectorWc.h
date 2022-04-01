#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : wchar_t
		Bytes: 2
		Range: 0 to 65.535
	*/

	class Vector2Wc
	{
	public:
		wchar_t x, y;
	public:
		inline Vector2Wc(const wchar_t& x = 0, const wchar_t& y = 0) noexcept;
		// copy
		inline Vector2Wc(const Vector2Wc& other) noexcept;
		inline Vector2Wc& operator=(const Vector2Wc& other) noexcept;
		// move
		inline Vector2Wc(Vector2Wc&& other) noexcept;
		inline Vector2Wc& operator=(Vector2Wc&& other) noexcept;
		// assignment
		inline Vector2Wc& operator=(const wchar_t& number) noexcept;

		// math operator
		inline Vector2Wc operator +(const Vector2Wc& v) const noexcept;
		inline Vector2Wc operator -(const Vector2Wc& v) const noexcept;
		inline Vector2Wc operator *(const Vector2Wc& v) const noexcept;
		inline Vector2Wc operator /(const Vector2Wc& v) const noexcept;

		inline Vector2Wc operator +(const wchar_t& number) const noexcept;
		inline Vector2Wc operator -(const wchar_t& number) const noexcept;
		inline Vector2Wc operator *(const wchar_t& number) const noexcept;
		inline Vector2Wc operator /(const wchar_t& number) const noexcept;

		// increment / decrement
		inline Vector2Wc& operator++ () noexcept;		// prefix increment
		inline Vector2Wc& operator-- () noexcept;		// prefix decrement
		inline Vector2Wc  operator++ (int) noexcept;		// postfix increment
		inline Vector2Wc  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2Wc& operator+= (const Vector2Wc& right) noexcept;
		inline Vector2Wc& operator-= (const Vector2Wc& right) noexcept;
		inline Vector2Wc& operator*= (const Vector2Wc& right) noexcept;
		inline Vector2Wc& operator/= (const Vector2Wc& right) noexcept;

		inline Vector2Wc& operator+= (const wchar_t& number) noexcept;
		inline Vector2Wc& operator-= (const wchar_t& number) noexcept;
		inline Vector2Wc& operator*= (const wchar_t& number) noexcept;
		inline Vector2Wc& operator/= (const wchar_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2Wc& other) const noexcept;
		inline bool operator<=  (const Vector2Wc& other) const noexcept;
		inline bool operator>	(const Vector2Wc& other) const noexcept;
		inline bool operator>=  (const Vector2Wc& other) const noexcept;

		inline bool operator<	(const wchar_t& number) const noexcept;
		inline bool operator<=  (const wchar_t& number) const noexcept;
		inline bool operator>	(const wchar_t& number) const noexcept;
		inline bool operator>=  (const wchar_t& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2Wc& other) const noexcept;
		inline bool operator!=(const Vector2Wc& other) const noexcept;
		inline bool operator==(const wchar_t& number)  const noexcept;
		inline bool operator!=(const wchar_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const wchar_t& stnd_value = 0) noexcept;
		inline wchar_t& operator[](const std::uint8_t& index) noexcept;
		inline wchar_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector3Wc
	{
	public:
		wchar_t x, y, z;
	public:
		inline Vector3Wc(const wchar_t& x = 0, const wchar_t& y = 0, const wchar_t& z = 0) noexcept;
		// copy
		inline Vector3Wc(const Vector3Wc& other) noexcept;
		inline Vector3Wc& operator=(const Vector3Wc& other) noexcept;
		// move
		inline Vector3Wc(Vector3Wc&& other) noexcept;
		inline Vector3Wc& operator=(Vector3Wc&& other) noexcept;
		// assignment
		inline Vector3Wc& operator=(const wchar_t& number) noexcept;

		// math operator
		inline Vector3Wc operator +(const Vector3Wc& v) const noexcept;
		inline Vector3Wc operator -(const Vector3Wc& v) const noexcept;
		inline Vector3Wc operator *(const Vector3Wc& v) const noexcept;
		inline Vector3Wc operator /(const Vector3Wc& v) const noexcept;

		inline Vector3Wc operator +(const wchar_t& number) const noexcept;
		inline Vector3Wc operator -(const wchar_t& number) const noexcept;
		inline Vector3Wc operator *(const wchar_t& number) const noexcept;
		inline Vector3Wc operator /(const wchar_t& number) const noexcept;

		// increment / decrement
		inline Vector3Wc& operator++ () noexcept;		// prefix increment
		inline Vector3Wc& operator-- () noexcept;		// prefix decrement
		inline Vector3Wc  operator++ (int) noexcept;		// postfix increment
		inline Vector3Wc  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3Wc& operator+= (const Vector3Wc& right) noexcept;
		inline Vector3Wc& operator-= (const Vector3Wc& right) noexcept;
		inline Vector3Wc& operator*= (const Vector3Wc& right) noexcept;
		inline Vector3Wc& operator/= (const Vector3Wc& right) noexcept;

		inline Vector3Wc& operator+= (const wchar_t& number) noexcept;
		inline Vector3Wc& operator-= (const wchar_t& number) noexcept;
		inline Vector3Wc& operator*= (const wchar_t& number) noexcept;
		inline Vector3Wc& operator/= (const wchar_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3Wc& other) const noexcept;
		inline bool operator<=  (const Vector3Wc& other) const noexcept;
		inline bool operator>	(const Vector3Wc& other) const noexcept;
		inline bool operator>=  (const Vector3Wc& other) const noexcept;
		 
		inline bool operator<	(const wchar_t& number) const noexcept;
		inline bool operator<=  (const wchar_t& number) const noexcept;
		inline bool operator>	(const wchar_t& number) const noexcept;
		inline bool operator>=  (const wchar_t& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3Wc& other) const noexcept;
		inline bool operator!=(const Vector3Wc& other) const noexcept;
		inline bool operator==(const wchar_t& number)  const noexcept;
		inline bool operator!=(const wchar_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const wchar_t& stnd_value = 0) noexcept;
		inline wchar_t& operator[](const std::uint8_t& index) noexcept;
		inline wchar_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector4Wc
	{
	public:
		wchar_t a, b, c, d;
	public:
		inline Vector4Wc(const wchar_t& a = 0, const wchar_t& b = 0, const wchar_t& c = 0, const wchar_t& d = 0) noexcept;
		// copy
		inline Vector4Wc(const Vector4Wc& other) noexcept;
		inline Vector4Wc& operator=(const Vector4Wc& other) noexcept;
		// move
		inline Vector4Wc(Vector4Wc&& other) noexcept;
		inline Vector4Wc& operator=(Vector4Wc&& other) noexcept;
		// assignment
		inline Vector4Wc& operator=(const wchar_t& number) noexcept;
		
		// math operator
		inline Vector4Wc operator +(const Vector4Wc& v) const noexcept;
		inline Vector4Wc operator -(const Vector4Wc& v) const noexcept;
		inline Vector4Wc operator *(const Vector4Wc& v) const noexcept;
		inline Vector4Wc operator /(const Vector4Wc& v) const noexcept;
		
		inline Vector4Wc operator +(const wchar_t& number) const noexcept;
		inline Vector4Wc operator -(const wchar_t& number) const noexcept;
		inline Vector4Wc operator *(const wchar_t& number) const noexcept;
		inline Vector4Wc operator /(const wchar_t& number) const noexcept;
		
		// increment / decrement
		inline Vector4Wc& operator++ () noexcept;		// prefix increment
		inline Vector4Wc& operator-- () noexcept;		// prefix decrement
		inline Vector4Wc  operator++ (int) noexcept;		// postfix increment
		inline Vector4Wc  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4Wc& operator+= (const Vector4Wc& right) noexcept;
		inline Vector4Wc& operator-= (const Vector4Wc& right) noexcept;
		inline Vector4Wc& operator*= (const Vector4Wc& right) noexcept;
		inline Vector4Wc& operator/= (const Vector4Wc& right) noexcept;
		
		inline Vector4Wc& operator+= (const wchar_t& number) noexcept;
		inline Vector4Wc& operator-= (const wchar_t& number) noexcept;
		inline Vector4Wc& operator*= (const wchar_t& number) noexcept;
		inline Vector4Wc& operator/= (const wchar_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4Wc& other) const noexcept;
		inline bool operator<=  (const Vector4Wc& other) const noexcept;
		inline bool operator>	(const Vector4Wc& other) const noexcept;
		inline bool operator>=  (const Vector4Wc& other) const noexcept;
		
		inline bool operator<	(const wchar_t& number) const noexcept;
		inline bool operator<=  (const wchar_t& number) const noexcept;
		inline bool operator>	(const wchar_t& number) const noexcept;
		inline bool operator>=  (const wchar_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4Wc& other) const noexcept;
		inline bool operator!=(const Vector4Wc& other) const noexcept;
		inline bool operator==(const wchar_t& number)  const noexcept;
		inline bool operator!=(const wchar_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const wchar_t& stnd_value = 0) noexcept;
		inline wchar_t& operator[](const std::uint8_t& index) noexcept;
		inline wchar_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector5Wc
	{
	public:
		wchar_t a, b, c, d, e;
	public:
		inline Vector5Wc(const wchar_t& a = 0, const wchar_t& b = 0, const wchar_t& c = 0, const wchar_t& d = 0,
			const wchar_t& e = 0) noexcept;
		// copy
		inline Vector5Wc(const Vector5Wc& other) noexcept;
		inline Vector5Wc& operator=(const Vector5Wc& other) noexcept;
		// move
		inline Vector5Wc(Vector5Wc&& other) noexcept;
		inline Vector5Wc& operator=(Vector5Wc&& other) noexcept;
		// assignment
		inline Vector5Wc& operator=(const wchar_t& number) noexcept;
		 
		// math operator
		inline Vector5Wc operator +(const Vector5Wc& v) const noexcept;
		inline Vector5Wc operator -(const Vector5Wc& v) const noexcept;
		inline Vector5Wc operator *(const Vector5Wc& v) const noexcept;
		inline Vector5Wc operator /(const Vector5Wc& v) const noexcept;
		
		inline Vector5Wc operator +(const wchar_t& number) const noexcept;
		inline Vector5Wc operator -(const wchar_t& number) const noexcept;
		inline Vector5Wc operator *(const wchar_t& number) const noexcept;
		inline Vector5Wc operator /(const wchar_t& number) const noexcept;
		
		// increment / decrement
		inline Vector5Wc& operator++ () noexcept;		// prefix increment
		inline Vector5Wc& operator-- () noexcept;		// prefix decrement
		inline Vector5Wc  operator++ (int) noexcept;		// postfix increment
		inline Vector5Wc  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5Wc& operator+= (const Vector5Wc& right) noexcept;
		inline Vector5Wc& operator-= (const Vector5Wc& right) noexcept;
		inline Vector5Wc& operator*= (const Vector5Wc& right) noexcept;
		inline Vector5Wc& operator/= (const Vector5Wc& right) noexcept;
		
		inline Vector5Wc& operator+= (const wchar_t& number) noexcept;
		inline Vector5Wc& operator-= (const wchar_t& number) noexcept;
		inline Vector5Wc& operator*= (const wchar_t& number) noexcept;
		inline Vector5Wc& operator/= (const wchar_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5Wc& other) const noexcept;
		inline bool operator<=  (const Vector5Wc& other) const noexcept;
		inline bool operator>	(const Vector5Wc& other) const noexcept;
		inline bool operator>=  (const Vector5Wc& other) const noexcept;
		
		inline bool operator<	(const wchar_t& number) const noexcept;
		inline bool operator<=  (const wchar_t& number) const noexcept;
		inline bool operator>	(const wchar_t& number) const noexcept;
		inline bool operator>=  (const wchar_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5Wc& other) const noexcept;
		inline bool operator!=(const Vector5Wc& other) const noexcept;
		inline bool operator==(const wchar_t& number)  const noexcept;
		inline bool operator!=(const wchar_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const wchar_t& stnd_value = 0) noexcept;
		inline wchar_t& operator[](const std::uint8_t& index) noexcept;
		inline wchar_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector6Wc
	{
	public:
		wchar_t a, b, c, d, e, f;
	public:
		inline Vector6Wc(const wchar_t& a = 0, const wchar_t& b = 0, const wchar_t& c = 0, const wchar_t& d = 0,
			const wchar_t& e = 0, const wchar_t& f = 0) noexcept;
		// copy
		inline Vector6Wc(const Vector6Wc& other) noexcept;
		inline Vector6Wc& operator=(const Vector6Wc& other) noexcept;
		// move
		inline Vector6Wc(Vector6Wc&& other) noexcept;
		inline Vector6Wc& operator=(Vector6Wc&& other) noexcept;
		// assignment
		inline Vector6Wc& operator=(const wchar_t& number) noexcept;
		
		// math operator
		inline Vector6Wc operator +(const Vector6Wc& v) const noexcept;
		inline Vector6Wc operator -(const Vector6Wc& v) const noexcept;
		inline Vector6Wc operator *(const Vector6Wc& v) const noexcept;
		inline Vector6Wc operator /(const Vector6Wc& v) const noexcept;
		
		inline Vector6Wc operator +(const wchar_t& number) const noexcept;
		inline Vector6Wc operator -(const wchar_t& number) const noexcept;
		inline Vector6Wc operator *(const wchar_t& number) const noexcept;
		inline Vector6Wc operator /(const wchar_t& number) const noexcept;
		
		// increment / decrement
		inline Vector6Wc& operator++ () noexcept;		// prefix increment
		inline Vector6Wc& operator-- () noexcept;		// prefix decrement
		inline Vector6Wc  operator++ (int) noexcept;		// postfix increment
		inline Vector6Wc  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6Wc& operator+= (const Vector6Wc& right) noexcept;
		inline Vector6Wc& operator-= (const Vector6Wc& right) noexcept;
		inline Vector6Wc& operator*= (const Vector6Wc& right) noexcept;
		inline Vector6Wc& operator/= (const Vector6Wc& right) noexcept;
		
		inline Vector6Wc& operator+= (const wchar_t& number) noexcept;
		inline Vector6Wc& operator-= (const wchar_t& number) noexcept;
		inline Vector6Wc& operator*= (const wchar_t& number) noexcept;
		inline Vector6Wc& operator/= (const wchar_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6Wc& other) const noexcept;
		inline bool operator<  (const Vector6Wc& other) const noexcept;
		inline bool operator>  (const Vector6Wc& other) const noexcept;
		inline bool operator>= (const Vector6Wc& other) const noexcept;
		
		inline bool operator<  (const wchar_t& number) const noexcept;
		inline bool operator<= (const wchar_t& number) const noexcept;
		inline bool operator>  (const wchar_t& number) const noexcept;
		inline bool operator>= (const wchar_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6Wc& other) const noexcept;
		inline bool operator!=(const Vector6Wc& other) const noexcept;
		inline bool operator==(const wchar_t& number)  const noexcept;
		inline bool operator!=(const wchar_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const wchar_t& stnd_value = 0) noexcept;
		inline wchar_t& operator[](const std::uint8_t& index) noexcept;
		inline wchar_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector7Wc
	{
	public:
		wchar_t a, b, c, d, e, f, g;
	public:
		inline Vector7Wc(const wchar_t& a = 0, const wchar_t& b = 0, const wchar_t& c = 0, const wchar_t& d = 0,
			const wchar_t& e = 0, const wchar_t& f = 0, const wchar_t& g = 0) noexcept;
		// copy
		inline Vector7Wc(const Vector7Wc& other) noexcept;
		inline Vector7Wc& operator=(const Vector7Wc& other) noexcept;
		// move
		inline Vector7Wc(Vector7Wc&& other) noexcept;
		inline Vector7Wc& operator=(Vector7Wc&& other) noexcept;
		// assignment
		inline Vector7Wc& operator=(const wchar_t& number) noexcept;
		
		// math operator
		inline Vector7Wc operator +(const Vector7Wc& v) const noexcept;
		inline Vector7Wc operator -(const Vector7Wc& v) const noexcept;
		inline Vector7Wc operator *(const Vector7Wc& v) const noexcept;
		inline Vector7Wc operator /(const Vector7Wc& v) const noexcept;
		
		inline Vector7Wc operator +(const wchar_t& number) const noexcept;
		inline Vector7Wc operator -(const wchar_t& number) const noexcept;
		inline Vector7Wc operator *(const wchar_t& number) const noexcept;
		inline Vector7Wc operator /(const wchar_t& number) const noexcept;
		
		// increment / decrement
		inline Vector7Wc& operator++ () noexcept;		// prefix increment
		inline Vector7Wc& operator-- () noexcept;		// prefix decrement
		inline Vector7Wc  operator++ (int) noexcept;		// postfix increment
		inline Vector7Wc  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7Wc& operator+= (const Vector7Wc& right) noexcept;
		inline Vector7Wc& operator-= (const Vector7Wc& right) noexcept;
		inline Vector7Wc& operator*= (const Vector7Wc& right) noexcept;
		inline Vector7Wc& operator/= (const Vector7Wc& right) noexcept;
		
		inline Vector7Wc& operator+= (const wchar_t& number) noexcept;
		inline Vector7Wc& operator-= (const wchar_t& number) noexcept;
		inline Vector7Wc& operator*= (const wchar_t& number) noexcept;
		inline Vector7Wc& operator/= (const wchar_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7Wc& other) const noexcept;
		inline bool operator<  (const Vector7Wc& other) const noexcept;
		inline bool operator>  (const Vector7Wc& other) const noexcept;
		inline bool operator>= (const Vector7Wc& other) const noexcept;
		
		inline bool operator<  (const wchar_t& number) const noexcept;
		inline bool operator<= (const wchar_t& number) const noexcept;
		inline bool operator>  (const wchar_t& number) const noexcept;
		inline bool operator>= (const wchar_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7Wc& other) const noexcept;
		inline bool operator!=(const Vector7Wc& other) const noexcept;
		inline bool operator==(const wchar_t& number)  const noexcept;
		inline bool operator!=(const wchar_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const wchar_t& stnd_value = 0) noexcept;
		inline wchar_t& operator[](const std::uint8_t& index) noexcept;
		inline wchar_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector8Wc
	{
	public:
		wchar_t a, b, c, d, e, f, g, h;
	public:
		inline Vector8Wc(const wchar_t& a = 0, const wchar_t& b = 0, const wchar_t& c = 0, const wchar_t& d = 0,
			const wchar_t& e = 0, const wchar_t& f = 0, const wchar_t& g = 0, const wchar_t& h = 0) noexcept;
		// copy
		inline Vector8Wc(const Vector8Wc& other) noexcept;
		inline Vector8Wc& operator=(const Vector8Wc& other) noexcept;
		// move
		inline Vector8Wc(Vector8Wc&& other) noexcept;
		inline Vector8Wc& operator=(Vector8Wc&& other) noexcept;
		// assignment
		inline Vector8Wc& operator=(const wchar_t& number) noexcept;
		
		// math operator
		inline Vector8Wc operator +(const Vector8Wc& v) const noexcept;
		inline Vector8Wc operator -(const Vector8Wc& v) const noexcept;
		inline Vector8Wc operator *(const Vector8Wc& v) const noexcept;
		inline Vector8Wc operator /(const Vector8Wc& v) const noexcept;
		
		inline Vector8Wc operator +(const wchar_t& number) const noexcept;
		inline Vector8Wc operator -(const wchar_t& number) const noexcept;
		inline Vector8Wc operator *(const wchar_t& number) const noexcept;
		inline Vector8Wc operator /(const wchar_t& number) const noexcept;
		
		// increment / decrement
		inline Vector8Wc& operator++ () noexcept;		// prefix increment
		inline Vector8Wc& operator-- () noexcept;		// prefix decrement
		inline Vector8Wc  operator++ (int) noexcept;		// postfix increment
		inline Vector8Wc  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8Wc& operator+= (const Vector8Wc& right) noexcept;
		inline Vector8Wc& operator-= (const Vector8Wc& right) noexcept;
		inline Vector8Wc& operator*= (const Vector8Wc& right) noexcept;
		inline Vector8Wc& operator/= (const Vector8Wc& right) noexcept;
		
		inline Vector8Wc& operator+= (const wchar_t& number) noexcept;
		inline Vector8Wc& operator-= (const wchar_t& number) noexcept;
		inline Vector8Wc& operator*= (const wchar_t& number) noexcept;
		inline Vector8Wc& operator/= (const wchar_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8Wc& other) const noexcept;
		inline bool operator<  (const Vector8Wc& other) const noexcept;
		inline bool operator>  (const Vector8Wc& other) const noexcept;
		inline bool operator>= (const Vector8Wc& other) const noexcept;
		
		inline bool operator<  (const wchar_t& number) const noexcept;
		inline bool operator<= (const wchar_t& number) const noexcept;
		inline bool operator>  (const wchar_t& number) const noexcept;
		inline bool operator>= (const wchar_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8Wc& other) const noexcept;
		inline bool operator!=(const Vector8Wc& other) const noexcept;
		inline bool operator==(const wchar_t& number)  const noexcept;
		inline bool operator!=(const wchar_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const wchar_t& stnd_value = 0) noexcept;
		inline wchar_t& operator[](const std::uint8_t& index) noexcept;
		inline wchar_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector9Wc
	{
	public:
		wchar_t a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9Wc(const wchar_t& a = 0, const wchar_t& b = 0, const wchar_t& c = 0, const wchar_t& d = 0,
			const wchar_t& e = 0, const wchar_t& f = 0, const wchar_t& g = 0, const wchar_t& h = 0,
			const wchar_t& i = 0) noexcept;
		// copy
		inline Vector9Wc(const Vector9Wc& other) noexcept;
		inline Vector9Wc& operator=(const Vector9Wc& other) noexcept;
		// move
		inline Vector9Wc(Vector9Wc&& other) noexcept;
		inline Vector9Wc& operator=(Vector9Wc&& other) noexcept;
		// assignment
		inline Vector9Wc& operator=(const wchar_t& number) noexcept;
		
		// math operator
		inline Vector9Wc operator +(const Vector9Wc& v) const noexcept;
		inline Vector9Wc operator -(const Vector9Wc& v) const noexcept;
		inline Vector9Wc operator *(const Vector9Wc& v) const noexcept;
		inline Vector9Wc operator /(const Vector9Wc& v) const noexcept;
		
		inline Vector9Wc operator +(const wchar_t& number) const noexcept;
		inline Vector9Wc operator -(const wchar_t& number) const noexcept;
		inline Vector9Wc operator *(const wchar_t& number) const noexcept;
		inline Vector9Wc operator /(const wchar_t& number) const noexcept;
		
		// increment / decrement
		inline Vector9Wc& operator++ () noexcept;		// prefix increment
		inline Vector9Wc& operator-- () noexcept;		// prefix decrement
		inline Vector9Wc  operator++ (int) noexcept;		// postfix increment
		inline Vector9Wc  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9Wc& operator+= (const Vector9Wc& right) noexcept;
		inline Vector9Wc& operator-= (const Vector9Wc& right) noexcept;
		inline Vector9Wc& operator*= (const Vector9Wc& right) noexcept;
		inline Vector9Wc& operator/= (const Vector9Wc& right) noexcept;
		
		inline Vector9Wc& operator+= (const wchar_t& number) noexcept;
		inline Vector9Wc& operator-= (const wchar_t& number) noexcept;
		inline Vector9Wc& operator*= (const wchar_t& number) noexcept;
		inline Vector9Wc& operator/= (const wchar_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9Wc& other) const noexcept;
		inline bool operator<  (const Vector9Wc& other) const noexcept;
		inline bool operator>  (const Vector9Wc& other) const noexcept;
		inline bool operator>= (const Vector9Wc& other) const noexcept;
		
		inline bool operator<  (const wchar_t& number) const noexcept;
		inline bool operator<= (const wchar_t& number) const noexcept;
		inline bool operator>  (const wchar_t& number) const noexcept;
		inline bool operator>= (const wchar_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9Wc& other) const noexcept;
		inline bool operator!=(const Vector9Wc& other) const noexcept;
		inline bool operator==(const wchar_t& number)  const noexcept;
		inline bool operator!=(const wchar_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const wchar_t& stnd_value = 0) noexcept;
		inline wchar_t& operator[](const std::uint8_t& index) noexcept;
		inline wchar_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector10Wc
	{
	public:
		wchar_t a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10Wc(const wchar_t& a = 0, const wchar_t& b = 0, const wchar_t& c = 0, const wchar_t& d = 0,
			const wchar_t& e = 0, const wchar_t& f = 0, const wchar_t& g = 0, const wchar_t& h = 0,
			const wchar_t& i = 0, const wchar_t& j = 0) noexcept;
		// copy
		inline Vector10Wc(const Vector10Wc& other) noexcept;
		inline Vector10Wc& operator=(const Vector10Wc& other) noexcept;
		// move
		inline Vector10Wc(Vector10Wc&& other) noexcept;
		inline Vector10Wc& operator=(Vector10Wc&& other) noexcept;
		// assignment
		inline Vector10Wc& operator=(const wchar_t& number) noexcept;
		
		// math operator
		inline Vector10Wc operator +(const Vector10Wc& v) const noexcept;
		inline Vector10Wc operator -(const Vector10Wc& v) const noexcept;
		inline Vector10Wc operator *(const Vector10Wc& v) const noexcept;
		inline Vector10Wc operator /(const Vector10Wc& v) const noexcept;
		
		inline Vector10Wc operator +(const wchar_t& number) const noexcept;
		inline Vector10Wc operator -(const wchar_t& number) const noexcept;
		inline Vector10Wc operator *(const wchar_t& number) const noexcept;
		inline Vector10Wc operator /(const wchar_t& number) const noexcept;
		
		// increment / decrement
		inline Vector10Wc& operator++ () noexcept;		// prefix increment
		inline Vector10Wc& operator-- () noexcept;		// prefix decrement
		inline Vector10Wc  operator++ (int) noexcept;	// postfix increment
		inline Vector10Wc  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10Wc& operator+= (const Vector10Wc& right) noexcept;
		inline Vector10Wc& operator-= (const Vector10Wc& right) noexcept;
		inline Vector10Wc& operator*= (const Vector10Wc& right) noexcept;
		inline Vector10Wc& operator/= (const Vector10Wc& right) noexcept;
		
		inline Vector10Wc& operator+= (const wchar_t& number) noexcept;
		inline Vector10Wc& operator-= (const wchar_t& number) noexcept;
		inline Vector10Wc& operator*= (const wchar_t& number) noexcept;
		inline Vector10Wc& operator/= (const wchar_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10Wc& other) const noexcept;
		inline bool operator<  (const Vector10Wc& other) const noexcept;
		inline bool operator>  (const Vector10Wc& other) const noexcept;
		inline bool operator>= (const Vector10Wc& other) const noexcept;

		inline bool operator<  (const wchar_t& number) const noexcept;
		inline bool operator<= (const wchar_t& number) const noexcept;
		inline bool operator>  (const wchar_t& number) const noexcept;
		inline bool operator>= (const wchar_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10Wc& other) const noexcept;
		inline bool operator!=(const Vector10Wc& other) const noexcept;
		inline bool operator==(const wchar_t& number)   const noexcept;
		inline bool operator!=(const wchar_t& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const wchar_t& stnd_value = 0) noexcept;
		inline wchar_t& operator[](const std::uint8_t& index) noexcept;
		inline wchar_t& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::wostream& operator<<(std::wostream& os, const Vector2Wc& v) noexcept
	{
		os << "x: " << (int)v.x << " | y: " << (int)v.y;
		return os;
	}

	inline static std::wostream& operator<<(std::wostream& os, const Vector3Wc& v) noexcept
	{
		os << "x: " << (int)v.x << " | y: " << (int)v.y << " | z: " << (int)v.z;
		return os;
	}

	inline static std::wostream& operator<<(std::wostream& os, const Vector4Wc& v) noexcept
	{
		os << "a: " << (int)v.a << " | b: " << (int)v.b << " | c: " << (int)v.c << " | d: " << (int)v.d;
		return os;
	}

	inline static std::wostream& operator<<(std::wostream& os, const Vector5Wc& v) noexcept
	{
		os << "a: " << (int)v.a << " | b: " << (int)v.b << " | c: " << (int)v.c << " | d: " << (int)v.d << " | e: " << (int)v.e;
		return os;
	}

	inline static std::wostream& operator<<(std::wostream& os, const Vector6Wc& v) noexcept
	{
		os << "a: " << (int)v.a << " | b: " << (int)v.b << " | c: " << (int)v.c << " | d: " << (int)v.d << " | e: " << (int)v.e << " | f: " << (int)v.f;
		return os;
	}

	inline static std::wostream& operator<<(std::wostream& os, const Vector7Wc& v) noexcept
	{
		os << "a: " << (int)v.a << " | b: " << (int)v.b << " | c: " << (int)v.c << " | d: " << (int)v.d << " | e: " << (int)v.e << " | f: " << (int)v.f << " | g: " << (int)v.g;
		return os;
	}

	inline static std::wostream& operator<<(std::wostream& os, const Vector8Wc& v) noexcept
	{
		os << "a: " << (int)v.a << " | b: " << (int)v.b << " | c: " << (int)v.c << " | d: " << (int)v.d << " | e: " << (int)v.e << " | f: " << (int)v.f << " | g: " << (int)v.g << " | h: " << (int)v.h;
		return os;
	}

	inline static std::wostream& operator<<(std::wostream& os, const Vector9Wc& v) noexcept
	{
		os << "a: " << (int)v.a << " | b: " << (int)v.b << " | c: " << (int)v.c << " | d: " << (int)v.d << " | e: " << (int)v.e << " | f: " << (int)v.f << " | g: " << (int)v.g << " | h: " << (int)v.h << " | i: " << (int)v.i;
		return os;
	}

	inline static std::wostream& operator<<(std::wostream& os, const Vector10Wc& v) noexcept
	{
		os << "a: " << (int)v.a << " | b: " << (int)v.b << " | c: " << (int)v.c << " | d: " << (int)v.d << " | e: " << (int)v.e << " | f: " << (int)v.f << " | g: " << (int)v.g << " | h: " << (int)v.h << " | i: " << (int)v.i << " | j: " << (int)v.j;
		return os;
	}
	// End
}