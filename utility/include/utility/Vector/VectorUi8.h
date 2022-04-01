#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::uint8_t
		Bytes: 1
		Range: 0 to 255
	*/

	class Vector2ui8
	{
	public:
		std::uint8_t x, y;
	public:
		inline Vector2ui8(const std::uint8_t& x = 0, const std::uint8_t& y = 0) noexcept;
		// copy
		inline Vector2ui8(const Vector2ui8& other) noexcept;
		inline Vector2ui8& operator=(const Vector2ui8& other) noexcept;
		// move
		inline Vector2ui8(Vector2ui8&& other) noexcept;
		inline Vector2ui8& operator=(Vector2ui8&& other) noexcept;
		// assignment
		inline Vector2ui8& operator=(const std::uint8_t& number) noexcept;

		// math operator
		inline Vector2ui8 operator +(const Vector2ui8& v) const noexcept;
		inline Vector2ui8 operator -(const Vector2ui8& v) const noexcept;
		inline Vector2ui8 operator *(const Vector2ui8& v) const noexcept;
		inline Vector2ui8 operator /(const Vector2ui8& v) const noexcept;

		inline Vector2ui8 operator +(const std::uint8_t& number) const noexcept;
		inline Vector2ui8 operator -(const std::uint8_t& number) const noexcept;
		inline Vector2ui8 operator *(const std::uint8_t& number) const noexcept;
		inline Vector2ui8 operator /(const std::uint8_t& number) const noexcept;

		// increment / decrement
		inline Vector2ui8& operator++ () noexcept;		// prefix increment
		inline Vector2ui8& operator-- () noexcept;		// prefix decrement
		inline Vector2ui8  operator++ (int) noexcept;		// postfix increment
		inline Vector2ui8  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2ui8& operator+= (const Vector2ui8& right) noexcept;
		inline Vector2ui8& operator-= (const Vector2ui8& right) noexcept;
		inline Vector2ui8& operator*= (const Vector2ui8& right) noexcept;
		inline Vector2ui8& operator/= (const Vector2ui8& right) noexcept;

		inline Vector2ui8& operator+= (const std::uint8_t& number) noexcept;
		inline Vector2ui8& operator-= (const std::uint8_t& number) noexcept;
		inline Vector2ui8& operator*= (const std::uint8_t& number) noexcept;
		inline Vector2ui8& operator/= (const std::uint8_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2ui8& other) const noexcept;
		inline bool operator<=  (const Vector2ui8& other) const noexcept;
		inline bool operator>	(const Vector2ui8& other) const noexcept;
		inline bool operator>=  (const Vector2ui8& other) const noexcept;

		inline bool operator<	(const std::uint8_t& number) const noexcept;
		inline bool operator<=  (const std::uint8_t& number) const noexcept;
		inline bool operator>	(const std::uint8_t& number) const noexcept;
		inline bool operator>=  (const std::uint8_t& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2ui8& other) const noexcept;
		inline bool operator!=(const Vector2ui8& other) const noexcept;
		inline bool operator==(const std::uint8_t& number)  const noexcept;
		inline bool operator!=(const std::uint8_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint8_t& stnd_value = 0) noexcept;
		inline std::uint8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector3ui8
	{
	public:
		std::uint8_t x, y, z;
	public:
		inline Vector3ui8(const std::uint8_t& x = 0, const std::uint8_t& y = 0, const std::uint8_t& z = 0) noexcept;
		// copy
		inline Vector3ui8(const Vector3ui8& other) noexcept;
		inline Vector3ui8& operator=(const Vector3ui8& other) noexcept;
		// move
		inline Vector3ui8(Vector3ui8&& other) noexcept;
		inline Vector3ui8& operator=(Vector3ui8&& other) noexcept;
		// assignment
		inline Vector3ui8& operator=(const std::uint8_t& number) noexcept;

		// math operator
		inline Vector3ui8 operator +(const Vector3ui8& v) const noexcept;
		inline Vector3ui8 operator -(const Vector3ui8& v) const noexcept;
		inline Vector3ui8 operator *(const Vector3ui8& v) const noexcept;
		inline Vector3ui8 operator /(const Vector3ui8& v) const noexcept;

		inline Vector3ui8 operator +(const std::uint8_t& number) const noexcept;
		inline Vector3ui8 operator -(const std::uint8_t& number) const noexcept;
		inline Vector3ui8 operator *(const std::uint8_t& number) const noexcept;
		inline Vector3ui8 operator /(const std::uint8_t& number) const noexcept;

		// increment / decrement
		inline Vector3ui8& operator++ () noexcept;		// prefix increment
		inline Vector3ui8& operator-- () noexcept;		// prefix decrement
		inline Vector3ui8  operator++ (int) noexcept;		// postfix increment
		inline Vector3ui8  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3ui8& operator+= (const Vector3ui8& right) noexcept;
		inline Vector3ui8& operator-= (const Vector3ui8& right) noexcept;
		inline Vector3ui8& operator*= (const Vector3ui8& right) noexcept;
		inline Vector3ui8& operator/= (const Vector3ui8& right) noexcept;

		inline Vector3ui8& operator+= (const std::uint8_t& number) noexcept;
		inline Vector3ui8& operator-= (const std::uint8_t& number) noexcept;
		inline Vector3ui8& operator*= (const std::uint8_t& number) noexcept;
		inline Vector3ui8& operator/= (const std::uint8_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3ui8& other) const noexcept;
		inline bool operator<=  (const Vector3ui8& other) const noexcept;
		inline bool operator>	(const Vector3ui8& other) const noexcept;
		inline bool operator>=  (const Vector3ui8& other) const noexcept;
		 
		inline bool operator<	(const std::uint8_t& number) const noexcept;
		inline bool operator<=  (const std::uint8_t& number) const noexcept;
		inline bool operator>	(const std::uint8_t& number) const noexcept;
		inline bool operator>=  (const std::uint8_t& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3ui8& other) const noexcept;
		inline bool operator!=(const Vector3ui8& other) const noexcept;
		inline bool operator==(const std::uint8_t& number)  const noexcept;
		inline bool operator!=(const std::uint8_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint8_t& stnd_value = 0) noexcept;
		inline std::uint8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector4ui8
	{
	public:
		std::uint8_t a, b, c, d;
	public:
		inline Vector4ui8(const std::uint8_t& a = 0, const std::uint8_t& b = 0, const std::uint8_t& c = 0, const std::uint8_t& d = 0) noexcept;
		// copy
		inline Vector4ui8(const Vector4ui8& other) noexcept;
		inline Vector4ui8& operator=(const Vector4ui8& other) noexcept;
		// move
		inline Vector4ui8(Vector4ui8&& other) noexcept;
		inline Vector4ui8& operator=(Vector4ui8&& other) noexcept;
		// assignment
		inline Vector4ui8& operator=(const std::uint8_t& number) noexcept;
		
		// math operator
		inline Vector4ui8 operator +(const Vector4ui8& v) const noexcept;
		inline Vector4ui8 operator -(const Vector4ui8& v) const noexcept;
		inline Vector4ui8 operator *(const Vector4ui8& v) const noexcept;
		inline Vector4ui8 operator /(const Vector4ui8& v) const noexcept;
		
		inline Vector4ui8 operator +(const std::uint8_t& number) const noexcept;
		inline Vector4ui8 operator -(const std::uint8_t& number) const noexcept;
		inline Vector4ui8 operator *(const std::uint8_t& number) const noexcept;
		inline Vector4ui8 operator /(const std::uint8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector4ui8& operator++ () noexcept;		// prefix increment
		inline Vector4ui8& operator-- () noexcept;		// prefix decrement
		inline Vector4ui8  operator++ (int) noexcept;		// postfix increment
		inline Vector4ui8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4ui8& operator+= (const Vector4ui8& right) noexcept;
		inline Vector4ui8& operator-= (const Vector4ui8& right) noexcept;
		inline Vector4ui8& operator*= (const Vector4ui8& right) noexcept;
		inline Vector4ui8& operator/= (const Vector4ui8& right) noexcept;
		
		inline Vector4ui8& operator+= (const std::uint8_t& number) noexcept;
		inline Vector4ui8& operator-= (const std::uint8_t& number) noexcept;
		inline Vector4ui8& operator*= (const std::uint8_t& number) noexcept;
		inline Vector4ui8& operator/= (const std::uint8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4ui8& other) const noexcept;
		inline bool operator<=  (const Vector4ui8& other) const noexcept;
		inline bool operator>	(const Vector4ui8& other) const noexcept;
		inline bool operator>=  (const Vector4ui8& other) const noexcept;
		
		inline bool operator<	(const std::uint8_t& number) const noexcept;
		inline bool operator<=  (const std::uint8_t& number) const noexcept;
		inline bool operator>	(const std::uint8_t& number) const noexcept;
		inline bool operator>=  (const std::uint8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4ui8& other) const noexcept;
		inline bool operator!=(const Vector4ui8& other) const noexcept;
		inline bool operator==(const std::uint8_t& number)  const noexcept;
		inline bool operator!=(const std::uint8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint8_t& stnd_value = 0) noexcept;
		inline std::uint8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector5ui8
	{
	public:
		std::uint8_t a, b, c, d, e;
	public:
		inline Vector5ui8(const std::uint8_t& a = 0, const std::uint8_t& b = 0, const std::uint8_t& c = 0, const std::uint8_t& d = 0,
			const std::uint8_t& e = 0) noexcept;
		// copy
		inline Vector5ui8(const Vector5ui8& other) noexcept;
		inline Vector5ui8& operator=(const Vector5ui8& other) noexcept;
		// move
		inline Vector5ui8(Vector5ui8&& other) noexcept;
		inline Vector5ui8& operator=(Vector5ui8&& other) noexcept;
		// assignment
		inline Vector5ui8& operator=(const std::uint8_t& number) noexcept;
		 
		// math operator
		inline Vector5ui8 operator +(const Vector5ui8& v) const noexcept;
		inline Vector5ui8 operator -(const Vector5ui8& v) const noexcept;
		inline Vector5ui8 operator *(const Vector5ui8& v) const noexcept;
		inline Vector5ui8 operator /(const Vector5ui8& v) const noexcept;
		
		inline Vector5ui8 operator +(const std::uint8_t& number) const noexcept;
		inline Vector5ui8 operator -(const std::uint8_t& number) const noexcept;
		inline Vector5ui8 operator *(const std::uint8_t& number) const noexcept;
		inline Vector5ui8 operator /(const std::uint8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector5ui8& operator++ () noexcept;		// prefix increment
		inline Vector5ui8& operator-- () noexcept;		// prefix decrement
		inline Vector5ui8  operator++ (int) noexcept;		// postfix increment
		inline Vector5ui8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5ui8& operator+= (const Vector5ui8& right) noexcept;
		inline Vector5ui8& operator-= (const Vector5ui8& right) noexcept;
		inline Vector5ui8& operator*= (const Vector5ui8& right) noexcept;
		inline Vector5ui8& operator/= (const Vector5ui8& right) noexcept;
		
		inline Vector5ui8& operator+= (const std::uint8_t& number) noexcept;
		inline Vector5ui8& operator-= (const std::uint8_t& number) noexcept;
		inline Vector5ui8& operator*= (const std::uint8_t& number) noexcept;
		inline Vector5ui8& operator/= (const std::uint8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5ui8& other) const noexcept;
		inline bool operator<=  (const Vector5ui8& other) const noexcept;
		inline bool operator>	(const Vector5ui8& other) const noexcept;
		inline bool operator>=  (const Vector5ui8& other) const noexcept;
		
		inline bool operator<	(const std::uint8_t& number) const noexcept;
		inline bool operator<=  (const std::uint8_t& number) const noexcept;
		inline bool operator>	(const std::uint8_t& number) const noexcept;
		inline bool operator>=  (const std::uint8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5ui8& other) const noexcept;
		inline bool operator!=(const Vector5ui8& other) const noexcept;
		inline bool operator==(const std::uint8_t& number)  const noexcept;
		inline bool operator!=(const std::uint8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint8_t& stnd_value = 0) noexcept;
		inline std::uint8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector6ui8
	{
	public:
		std::uint8_t a, b, c, d, e, f;
	public:
		inline Vector6ui8(const std::uint8_t& a = 0, const std::uint8_t& b = 0, const std::uint8_t& c = 0, const std::uint8_t& d = 0,
			const std::uint8_t& e = 0, const std::uint8_t& f = 0) noexcept;
		// copy
		inline Vector6ui8(const Vector6ui8& other) noexcept;
		inline Vector6ui8& operator=(const Vector6ui8& other) noexcept;
		// move
		inline Vector6ui8(Vector6ui8&& other) noexcept;
		inline Vector6ui8& operator=(Vector6ui8&& other) noexcept;
		// assignment
		inline Vector6ui8& operator=(const std::uint8_t& number) noexcept;
		
		// math operator
		inline Vector6ui8 operator +(const Vector6ui8& v) const noexcept;
		inline Vector6ui8 operator -(const Vector6ui8& v) const noexcept;
		inline Vector6ui8 operator *(const Vector6ui8& v) const noexcept;
		inline Vector6ui8 operator /(const Vector6ui8& v) const noexcept;
		
		inline Vector6ui8 operator +(const std::uint8_t& number) const noexcept;
		inline Vector6ui8 operator -(const std::uint8_t& number) const noexcept;
		inline Vector6ui8 operator *(const std::uint8_t& number) const noexcept;
		inline Vector6ui8 operator /(const std::uint8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector6ui8& operator++ () noexcept;		// prefix increment
		inline Vector6ui8& operator-- () noexcept;		// prefix decrement
		inline Vector6ui8  operator++ (int) noexcept;		// postfix increment
		inline Vector6ui8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6ui8& operator+= (const Vector6ui8& right) noexcept;
		inline Vector6ui8& operator-= (const Vector6ui8& right) noexcept;
		inline Vector6ui8& operator*= (const Vector6ui8& right) noexcept;
		inline Vector6ui8& operator/= (const Vector6ui8& right) noexcept;
		
		inline Vector6ui8& operator+= (const std::uint8_t& number) noexcept;
		inline Vector6ui8& operator-= (const std::uint8_t& number) noexcept;
		inline Vector6ui8& operator*= (const std::uint8_t& number) noexcept;
		inline Vector6ui8& operator/= (const std::uint8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6ui8& other) const noexcept;
		inline bool operator<  (const Vector6ui8& other) const noexcept;
		inline bool operator>  (const Vector6ui8& other) const noexcept;
		inline bool operator>= (const Vector6ui8& other) const noexcept;
		
		inline bool operator<  (const std::uint8_t& number) const noexcept;
		inline bool operator<= (const std::uint8_t& number) const noexcept;
		inline bool operator>  (const std::uint8_t& number) const noexcept;
		inline bool operator>= (const std::uint8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6ui8& other) const noexcept;
		inline bool operator!=(const Vector6ui8& other) const noexcept;
		inline bool operator==(const std::uint8_t& number)  const noexcept;
		inline bool operator!=(const std::uint8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint8_t& stnd_value = 0) noexcept;
		inline std::uint8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector7ui8
	{
	public:
		std::uint8_t a, b, c, d, e, f, g;
	public:
		inline Vector7ui8(const std::uint8_t& a = 0, const std::uint8_t& b = 0, const std::uint8_t& c = 0, const std::uint8_t& d = 0,
			const std::uint8_t& e = 0, const std::uint8_t& f = 0, const std::uint8_t& g = 0) noexcept;
		// copy
		inline Vector7ui8(const Vector7ui8& other) noexcept;
		inline Vector7ui8& operator=(const Vector7ui8& other) noexcept;
		// move
		inline Vector7ui8(Vector7ui8&& other) noexcept;
		inline Vector7ui8& operator=(Vector7ui8&& other) noexcept;
		// assignment
		inline Vector7ui8& operator=(const std::uint8_t& number) noexcept;
		
		// math operator
		inline Vector7ui8 operator +(const Vector7ui8& v) const noexcept;
		inline Vector7ui8 operator -(const Vector7ui8& v) const noexcept;
		inline Vector7ui8 operator *(const Vector7ui8& v) const noexcept;
		inline Vector7ui8 operator /(const Vector7ui8& v) const noexcept;
		
		inline Vector7ui8 operator +(const std::uint8_t& number) const noexcept;
		inline Vector7ui8 operator -(const std::uint8_t& number) const noexcept;
		inline Vector7ui8 operator *(const std::uint8_t& number) const noexcept;
		inline Vector7ui8 operator /(const std::uint8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector7ui8& operator++ () noexcept;		// prefix increment
		inline Vector7ui8& operator-- () noexcept;		// prefix decrement
		inline Vector7ui8  operator++ (int) noexcept;		// postfix increment
		inline Vector7ui8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7ui8& operator+= (const Vector7ui8& right) noexcept;
		inline Vector7ui8& operator-= (const Vector7ui8& right) noexcept;
		inline Vector7ui8& operator*= (const Vector7ui8& right) noexcept;
		inline Vector7ui8& operator/= (const Vector7ui8& right) noexcept;
		
		inline Vector7ui8& operator+= (const std::uint8_t& number) noexcept;
		inline Vector7ui8& operator-= (const std::uint8_t& number) noexcept;
		inline Vector7ui8& operator*= (const std::uint8_t& number) noexcept;
		inline Vector7ui8& operator/= (const std::uint8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7ui8& other) const noexcept;
		inline bool operator<  (const Vector7ui8& other) const noexcept;
		inline bool operator>  (const Vector7ui8& other) const noexcept;
		inline bool operator>= (const Vector7ui8& other) const noexcept;
		
		inline bool operator<  (const std::uint8_t& number) const noexcept;
		inline bool operator<= (const std::uint8_t& number) const noexcept;
		inline bool operator>  (const std::uint8_t& number) const noexcept;
		inline bool operator>= (const std::uint8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7ui8& other) const noexcept;
		inline bool operator!=(const Vector7ui8& other) const noexcept;
		inline bool operator==(const std::uint8_t& number)  const noexcept;
		inline bool operator!=(const std::uint8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint8_t& stnd_value = 0) noexcept;
		inline std::uint8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector8ui8
	{
	public:
		std::uint8_t a, b, c, d, e, f, g, h;
	public:
		inline Vector8ui8(const std::uint8_t& a = 0, const std::uint8_t& b = 0, const std::uint8_t& c = 0, const std::uint8_t& d = 0,
			const std::uint8_t& e = 0, const std::uint8_t& f = 0, const std::uint8_t& g = 0, const std::uint8_t& h = 0) noexcept;
		// copy
		inline Vector8ui8(const Vector8ui8& other) noexcept;
		inline Vector8ui8& operator=(const Vector8ui8& other) noexcept;
		// move
		inline Vector8ui8(Vector8ui8&& other) noexcept;
		inline Vector8ui8& operator=(Vector8ui8&& other) noexcept;
		// assignment
		inline Vector8ui8& operator=(const std::uint8_t& number) noexcept;
		
		// math operator
		inline Vector8ui8 operator +(const Vector8ui8& v) const noexcept;
		inline Vector8ui8 operator -(const Vector8ui8& v) const noexcept;
		inline Vector8ui8 operator *(const Vector8ui8& v) const noexcept;
		inline Vector8ui8 operator /(const Vector8ui8& v) const noexcept;
		
		inline Vector8ui8 operator +(const std::uint8_t& number) const noexcept;
		inline Vector8ui8 operator -(const std::uint8_t& number) const noexcept;
		inline Vector8ui8 operator *(const std::uint8_t& number) const noexcept;
		inline Vector8ui8 operator /(const std::uint8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector8ui8& operator++ () noexcept;		// prefix increment
		inline Vector8ui8& operator-- () noexcept;		// prefix decrement
		inline Vector8ui8  operator++ (int) noexcept;		// postfix increment
		inline Vector8ui8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8ui8& operator+= (const Vector8ui8& right) noexcept;
		inline Vector8ui8& operator-= (const Vector8ui8& right) noexcept;
		inline Vector8ui8& operator*= (const Vector8ui8& right) noexcept;
		inline Vector8ui8& operator/= (const Vector8ui8& right) noexcept;
		
		inline Vector8ui8& operator+= (const std::uint8_t& number) noexcept;
		inline Vector8ui8& operator-= (const std::uint8_t& number) noexcept;
		inline Vector8ui8& operator*= (const std::uint8_t& number) noexcept;
		inline Vector8ui8& operator/= (const std::uint8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8ui8& other) const noexcept;
		inline bool operator<  (const Vector8ui8& other) const noexcept;
		inline bool operator>  (const Vector8ui8& other) const noexcept;
		inline bool operator>= (const Vector8ui8& other) const noexcept;
		
		inline bool operator<  (const std::uint8_t& number) const noexcept;
		inline bool operator<= (const std::uint8_t& number) const noexcept;
		inline bool operator>  (const std::uint8_t& number) const noexcept;
		inline bool operator>= (const std::uint8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8ui8& other) const noexcept;
		inline bool operator!=(const Vector8ui8& other) const noexcept;
		inline bool operator==(const std::uint8_t& number)  const noexcept;
		inline bool operator!=(const std::uint8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint8_t& stnd_value = 0) noexcept;
		inline std::uint8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector9ui8
	{
	public:
		std::uint8_t a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9ui8(const std::uint8_t& a = 0, const std::uint8_t& b = 0, const std::uint8_t& c = 0, const std::uint8_t& d = 0,
			const std::uint8_t& e = 0, const std::uint8_t& f = 0, const std::uint8_t& g = 0, const std::uint8_t& h = 0,
			const std::uint8_t& i = 0) noexcept;
		// copy
		inline Vector9ui8(const Vector9ui8& other) noexcept;
		inline Vector9ui8& operator=(const Vector9ui8& other) noexcept;
		// move
		inline Vector9ui8(Vector9ui8&& other) noexcept;
		inline Vector9ui8& operator=(Vector9ui8&& other) noexcept;
		// assignment
		inline Vector9ui8& operator=(const std::uint8_t& number) noexcept;
		
		// math operator
		inline Vector9ui8 operator +(const Vector9ui8& v) const noexcept;
		inline Vector9ui8 operator -(const Vector9ui8& v) const noexcept;
		inline Vector9ui8 operator *(const Vector9ui8& v) const noexcept;
		inline Vector9ui8 operator /(const Vector9ui8& v) const noexcept;
		
		inline Vector9ui8 operator +(const std::uint8_t& number) const noexcept;
		inline Vector9ui8 operator -(const std::uint8_t& number) const noexcept;
		inline Vector9ui8 operator *(const std::uint8_t& number) const noexcept;
		inline Vector9ui8 operator /(const std::uint8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector9ui8& operator++ () noexcept;		// prefix increment
		inline Vector9ui8& operator-- () noexcept;		// prefix decrement
		inline Vector9ui8  operator++ (int) noexcept;		// postfix increment
		inline Vector9ui8  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9ui8& operator+= (const Vector9ui8& right) noexcept;
		inline Vector9ui8& operator-= (const Vector9ui8& right) noexcept;
		inline Vector9ui8& operator*= (const Vector9ui8& right) noexcept;
		inline Vector9ui8& operator/= (const Vector9ui8& right) noexcept;
		
		inline Vector9ui8& operator+= (const std::uint8_t& number) noexcept;
		inline Vector9ui8& operator-= (const std::uint8_t& number) noexcept;
		inline Vector9ui8& operator*= (const std::uint8_t& number) noexcept;
		inline Vector9ui8& operator/= (const std::uint8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9ui8& other) const noexcept;
		inline bool operator<  (const Vector9ui8& other) const noexcept;
		inline bool operator>  (const Vector9ui8& other) const noexcept;
		inline bool operator>= (const Vector9ui8& other) const noexcept;
		
		inline bool operator<  (const std::uint8_t& number) const noexcept;
		inline bool operator<= (const std::uint8_t& number) const noexcept;
		inline bool operator>  (const std::uint8_t& number) const noexcept;
		inline bool operator>= (const std::uint8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9ui8& other) const noexcept;
		inline bool operator!=(const Vector9ui8& other) const noexcept;
		inline bool operator==(const std::uint8_t& number)  const noexcept;
		inline bool operator!=(const std::uint8_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint8_t& stnd_value = 0) noexcept;
		inline std::uint8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint8_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector10ui8
	{
	public:
		std::uint8_t a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10ui8(const std::uint8_t& a = 0, const std::uint8_t& b = 0, const std::uint8_t& c = 0, const std::uint8_t& d = 0,
			const std::uint8_t& e = 0, const std::uint8_t& f = 0, const std::uint8_t& g = 0, const std::uint8_t& h = 0,
			const std::uint8_t& i = 0, const std::uint8_t& j = 0) noexcept;
		// copy
		inline Vector10ui8(const Vector10ui8& other) noexcept;
		inline Vector10ui8& operator=(const Vector10ui8& other) noexcept;
		// move
		inline Vector10ui8(Vector10ui8&& other) noexcept;
		inline Vector10ui8& operator=(Vector10ui8&& other) noexcept;
		// assignment
		inline Vector10ui8& operator=(const std::uint8_t& number) noexcept;
		
		// math operator
		inline Vector10ui8 operator +(const Vector10ui8& v) const noexcept;
		inline Vector10ui8 operator -(const Vector10ui8& v) const noexcept;
		inline Vector10ui8 operator *(const Vector10ui8& v) const noexcept;
		inline Vector10ui8 operator /(const Vector10ui8& v) const noexcept;
		
		inline Vector10ui8 operator +(const std::uint8_t& number) const noexcept;
		inline Vector10ui8 operator -(const std::uint8_t& number) const noexcept;
		inline Vector10ui8 operator *(const std::uint8_t& number) const noexcept;
		inline Vector10ui8 operator /(const std::uint8_t& number) const noexcept;
		
		// increment / decrement
		inline Vector10ui8& operator++ () noexcept;		// prefix increment
		inline Vector10ui8& operator-- () noexcept;		// prefix decrement
		inline Vector10ui8  operator++ (int) noexcept;	// postfix increment
		inline Vector10ui8  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10ui8& operator+= (const Vector10ui8& right) noexcept;
		inline Vector10ui8& operator-= (const Vector10ui8& right) noexcept;
		inline Vector10ui8& operator*= (const Vector10ui8& right) noexcept;
		inline Vector10ui8& operator/= (const Vector10ui8& right) noexcept;
		
		inline Vector10ui8& operator+= (const std::uint8_t& number) noexcept;
		inline Vector10ui8& operator-= (const std::uint8_t& number) noexcept;
		inline Vector10ui8& operator*= (const std::uint8_t& number) noexcept;
		inline Vector10ui8& operator/= (const std::uint8_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10ui8& other) const noexcept;
		inline bool operator<  (const Vector10ui8& other) const noexcept;
		inline bool operator>  (const Vector10ui8& other) const noexcept;
		inline bool operator>= (const Vector10ui8& other) const noexcept;

		inline bool operator<  (const std::uint8_t& number) const noexcept;
		inline bool operator<= (const std::uint8_t& number) const noexcept;
		inline bool operator>  (const std::uint8_t& number) const noexcept;
		inline bool operator>= (const std::uint8_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10ui8& other) const noexcept;
		inline bool operator!=(const Vector10ui8& other) const noexcept;
		inline bool operator==(const std::uint8_t& number)   const noexcept;
		inline bool operator!=(const std::uint8_t& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint8_t& stnd_value = 0) noexcept;
		inline std::uint8_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint8_t& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2ui8& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3ui8& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4ui8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5ui8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6ui8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7ui8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8ui8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9ui8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10ui8& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}