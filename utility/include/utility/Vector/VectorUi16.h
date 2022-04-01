#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::uint16_t
		Bytes: 2
		Range: 0 to 65.535
	*/

	class Vector2ui16
	{
	public:
		std::uint16_t x, y;
	public:
		inline Vector2ui16(const std::uint16_t& x = 0, const std::uint16_t& y = 0) noexcept;
		// copy
		inline Vector2ui16(const Vector2ui16& other) noexcept;
		inline Vector2ui16& operator=(const Vector2ui16& other) noexcept;
		// move
		inline Vector2ui16(Vector2ui16&& other) noexcept;
		inline Vector2ui16& operator=(Vector2ui16&& other) noexcept;
		// assignment
		inline Vector2ui16& operator=(const std::uint16_t& number) noexcept;

		// math operator
		inline Vector2ui16 operator +(const Vector2ui16& v) const noexcept;
		inline Vector2ui16 operator -(const Vector2ui16& v) const noexcept;
		inline Vector2ui16 operator *(const Vector2ui16& v) const noexcept;
		inline Vector2ui16 operator /(const Vector2ui16& v) const noexcept;

		inline Vector2ui16 operator +(const std::uint16_t& number) const noexcept;
		inline Vector2ui16 operator -(const std::uint16_t& number) const noexcept;
		inline Vector2ui16 operator *(const std::uint16_t& number) const noexcept;
		inline Vector2ui16 operator /(const std::uint16_t& number) const noexcept;

		// increment / decrement
		inline Vector2ui16& operator++ () noexcept;		// prefix increment
		inline Vector2ui16& operator-- () noexcept;		// prefix decrement
		inline Vector2ui16  operator++ (int) noexcept;		// postfix increment
		inline Vector2ui16  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2ui16& operator+= (const Vector2ui16& right) noexcept;
		inline Vector2ui16& operator-= (const Vector2ui16& right) noexcept;
		inline Vector2ui16& operator*= (const Vector2ui16& right) noexcept;
		inline Vector2ui16& operator/= (const Vector2ui16& right) noexcept;

		inline Vector2ui16& operator+= (const std::uint16_t& number) noexcept;
		inline Vector2ui16& operator-= (const std::uint16_t& number) noexcept;
		inline Vector2ui16& operator*= (const std::uint16_t& number) noexcept;
		inline Vector2ui16& operator/= (const std::uint16_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2ui16& other) const noexcept;
		inline bool operator<=  (const Vector2ui16& other) const noexcept;
		inline bool operator>	(const Vector2ui16& other) const noexcept;
		inline bool operator>=  (const Vector2ui16& other) const noexcept;

		inline bool operator<	(const std::uint16_t& number) const noexcept;
		inline bool operator<=  (const std::uint16_t& number) const noexcept;
		inline bool operator>	(const std::uint16_t& number) const noexcept;
		inline bool operator>=  (const std::uint16_t& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2ui16& other) const noexcept;
		inline bool operator!=(const Vector2ui16& other) const noexcept;
		inline bool operator==(const std::uint16_t& number)  const noexcept;
		inline bool operator!=(const std::uint16_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint16_t& stnd_value = 0) noexcept;
		inline std::uint16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector3ui16
	{
	public:
		std::uint16_t x, y, z;
	public:
		inline Vector3ui16(const std::uint16_t& x = 0, const std::uint16_t& y = 0, const std::uint16_t& z = 0) noexcept;
		// copy
		inline Vector3ui16(const Vector3ui16& other) noexcept;
		inline Vector3ui16& operator=(const Vector3ui16& other) noexcept;
		// move
		inline Vector3ui16(Vector3ui16&& other) noexcept;
		inline Vector3ui16& operator=(Vector3ui16&& other) noexcept;
		// assignment
		inline Vector3ui16& operator=(const std::uint16_t& number) noexcept;

		// math operator
		inline Vector3ui16 operator +(const Vector3ui16& v) const noexcept;
		inline Vector3ui16 operator -(const Vector3ui16& v) const noexcept;
		inline Vector3ui16 operator *(const Vector3ui16& v) const noexcept;
		inline Vector3ui16 operator /(const Vector3ui16& v) const noexcept;

		inline Vector3ui16 operator +(const std::uint16_t& number) const noexcept;
		inline Vector3ui16 operator -(const std::uint16_t& number) const noexcept;
		inline Vector3ui16 operator *(const std::uint16_t& number) const noexcept;
		inline Vector3ui16 operator /(const std::uint16_t& number) const noexcept;

		// increment / decrement
		inline Vector3ui16& operator++ () noexcept;		// prefix increment
		inline Vector3ui16& operator-- () noexcept;		// prefix decrement
		inline Vector3ui16  operator++ (int) noexcept;		// postfix increment
		inline Vector3ui16  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3ui16& operator+= (const Vector3ui16& right) noexcept;
		inline Vector3ui16& operator-= (const Vector3ui16& right) noexcept;
		inline Vector3ui16& operator*= (const Vector3ui16& right) noexcept;
		inline Vector3ui16& operator/= (const Vector3ui16& right) noexcept;

		inline Vector3ui16& operator+= (const std::uint16_t& number) noexcept;
		inline Vector3ui16& operator-= (const std::uint16_t& number) noexcept;
		inline Vector3ui16& operator*= (const std::uint16_t& number) noexcept;
		inline Vector3ui16& operator/= (const std::uint16_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3ui16& other) const noexcept;
		inline bool operator<=  (const Vector3ui16& other) const noexcept;
		inline bool operator>	(const Vector3ui16& other) const noexcept;
		inline bool operator>=  (const Vector3ui16& other) const noexcept;
		 
		inline bool operator<	(const std::uint16_t& number) const noexcept;
		inline bool operator<=  (const std::uint16_t& number) const noexcept;
		inline bool operator>	(const std::uint16_t& number) const noexcept;
		inline bool operator>=  (const std::uint16_t& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3ui16& other) const noexcept;
		inline bool operator!=(const Vector3ui16& other) const noexcept;
		inline bool operator==(const std::uint16_t& number)  const noexcept;
		inline bool operator!=(const std::uint16_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint16_t& stnd_value = 0) noexcept;
		inline std::uint16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector4ui16
	{
	public:
		std::uint16_t a, b, c, d;
	public:
		inline Vector4ui16(const std::uint16_t& a = 0, const std::uint16_t& b = 0, const std::uint16_t& c = 0, const std::uint16_t& d = 0) noexcept;
		// copy
		inline Vector4ui16(const Vector4ui16& other) noexcept;
		inline Vector4ui16& operator=(const Vector4ui16& other) noexcept;
		// move
		inline Vector4ui16(Vector4ui16&& other) noexcept;
		inline Vector4ui16& operator=(Vector4ui16&& other) noexcept;
		// assignment
		inline Vector4ui16& operator=(const std::uint16_t& number) noexcept;
		
		// math operator
		inline Vector4ui16 operator +(const Vector4ui16& v) const noexcept;
		inline Vector4ui16 operator -(const Vector4ui16& v) const noexcept;
		inline Vector4ui16 operator *(const Vector4ui16& v) const noexcept;
		inline Vector4ui16 operator /(const Vector4ui16& v) const noexcept;
		
		inline Vector4ui16 operator +(const std::uint16_t& number) const noexcept;
		inline Vector4ui16 operator -(const std::uint16_t& number) const noexcept;
		inline Vector4ui16 operator *(const std::uint16_t& number) const noexcept;
		inline Vector4ui16 operator /(const std::uint16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector4ui16& operator++ () noexcept;		// prefix increment
		inline Vector4ui16& operator-- () noexcept;		// prefix decrement
		inline Vector4ui16  operator++ (int) noexcept;		// postfix increment
		inline Vector4ui16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4ui16& operator+= (const Vector4ui16& right) noexcept;
		inline Vector4ui16& operator-= (const Vector4ui16& right) noexcept;
		inline Vector4ui16& operator*= (const Vector4ui16& right) noexcept;
		inline Vector4ui16& operator/= (const Vector4ui16& right) noexcept;
		
		inline Vector4ui16& operator+= (const std::uint16_t& number) noexcept;
		inline Vector4ui16& operator-= (const std::uint16_t& number) noexcept;
		inline Vector4ui16& operator*= (const std::uint16_t& number) noexcept;
		inline Vector4ui16& operator/= (const std::uint16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4ui16& other) const noexcept;
		inline bool operator<=  (const Vector4ui16& other) const noexcept;
		inline bool operator>	(const Vector4ui16& other) const noexcept;
		inline bool operator>=  (const Vector4ui16& other) const noexcept;
		
		inline bool operator<	(const std::uint16_t& number) const noexcept;
		inline bool operator<=  (const std::uint16_t& number) const noexcept;
		inline bool operator>	(const std::uint16_t& number) const noexcept;
		inline bool operator>=  (const std::uint16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4ui16& other) const noexcept;
		inline bool operator!=(const Vector4ui16& other) const noexcept;
		inline bool operator==(const std::uint16_t& number)  const noexcept;
		inline bool operator!=(const std::uint16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint16_t& stnd_value = 0) noexcept;
		inline std::uint16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector5ui16
	{
	public:
		std::uint16_t a, b, c, d, e;
	public:
		inline Vector5ui16(const std::uint16_t& a = 0, const std::uint16_t& b = 0, const std::uint16_t& c = 0, const std::uint16_t& d = 0,
			const std::uint16_t& e = 0) noexcept;
		// copy
		inline Vector5ui16(const Vector5ui16& other) noexcept;
		inline Vector5ui16& operator=(const Vector5ui16& other) noexcept;
		// move
		inline Vector5ui16(Vector5ui16&& other) noexcept;
		inline Vector5ui16& operator=(Vector5ui16&& other) noexcept;
		// assignment
		inline Vector5ui16& operator=(const std::uint16_t& number) noexcept;
		 
		// math operator
		inline Vector5ui16 operator +(const Vector5ui16& v) const noexcept;
		inline Vector5ui16 operator -(const Vector5ui16& v) const noexcept;
		inline Vector5ui16 operator *(const Vector5ui16& v) const noexcept;
		inline Vector5ui16 operator /(const Vector5ui16& v) const noexcept;
		
		inline Vector5ui16 operator +(const std::uint16_t& number) const noexcept;
		inline Vector5ui16 operator -(const std::uint16_t& number) const noexcept;
		inline Vector5ui16 operator *(const std::uint16_t& number) const noexcept;
		inline Vector5ui16 operator /(const std::uint16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector5ui16& operator++ () noexcept;		// prefix increment
		inline Vector5ui16& operator-- () noexcept;		// prefix decrement
		inline Vector5ui16  operator++ (int) noexcept;		// postfix increment
		inline Vector5ui16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5ui16& operator+= (const Vector5ui16& right) noexcept;
		inline Vector5ui16& operator-= (const Vector5ui16& right) noexcept;
		inline Vector5ui16& operator*= (const Vector5ui16& right) noexcept;
		inline Vector5ui16& operator/= (const Vector5ui16& right) noexcept;
		
		inline Vector5ui16& operator+= (const std::uint16_t& number) noexcept;
		inline Vector5ui16& operator-= (const std::uint16_t& number) noexcept;
		inline Vector5ui16& operator*= (const std::uint16_t& number) noexcept;
		inline Vector5ui16& operator/= (const std::uint16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5ui16& other) const noexcept;
		inline bool operator<=  (const Vector5ui16& other) const noexcept;
		inline bool operator>	(const Vector5ui16& other) const noexcept;
		inline bool operator>=  (const Vector5ui16& other) const noexcept;
		
		inline bool operator<	(const std::uint16_t& number) const noexcept;
		inline bool operator<=  (const std::uint16_t& number) const noexcept;
		inline bool operator>	(const std::uint16_t& number) const noexcept;
		inline bool operator>=  (const std::uint16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5ui16& other) const noexcept;
		inline bool operator!=(const Vector5ui16& other) const noexcept;
		inline bool operator==(const std::uint16_t& number)  const noexcept;
		inline bool operator!=(const std::uint16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint16_t& stnd_value = 0) noexcept;
		inline std::uint16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector6ui16
	{
	public:
		std::uint16_t a, b, c, d, e, f;
	public:
		inline Vector6ui16(const std::uint16_t& a = 0, const std::uint16_t& b = 0, const std::uint16_t& c = 0, const std::uint16_t& d = 0,
			const std::uint16_t& e = 0, const std::uint16_t& f = 0) noexcept;
		// copy
		inline Vector6ui16(const Vector6ui16& other) noexcept;
		inline Vector6ui16& operator=(const Vector6ui16& other) noexcept;
		// move
		inline Vector6ui16(Vector6ui16&& other) noexcept;
		inline Vector6ui16& operator=(Vector6ui16&& other) noexcept;
		// assignment
		inline Vector6ui16& operator=(const std::uint16_t& number) noexcept;
		
		// math operator
		inline Vector6ui16 operator +(const Vector6ui16& v) const noexcept;
		inline Vector6ui16 operator -(const Vector6ui16& v) const noexcept;
		inline Vector6ui16 operator *(const Vector6ui16& v) const noexcept;
		inline Vector6ui16 operator /(const Vector6ui16& v) const noexcept;
		
		inline Vector6ui16 operator +(const std::uint16_t& number) const noexcept;
		inline Vector6ui16 operator -(const std::uint16_t& number) const noexcept;
		inline Vector6ui16 operator *(const std::uint16_t& number) const noexcept;
		inline Vector6ui16 operator /(const std::uint16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector6ui16& operator++ () noexcept;		// prefix increment
		inline Vector6ui16& operator-- () noexcept;		// prefix decrement
		inline Vector6ui16  operator++ (int) noexcept;		// postfix increment
		inline Vector6ui16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6ui16& operator+= (const Vector6ui16& right) noexcept;
		inline Vector6ui16& operator-= (const Vector6ui16& right) noexcept;
		inline Vector6ui16& operator*= (const Vector6ui16& right) noexcept;
		inline Vector6ui16& operator/= (const Vector6ui16& right) noexcept;
		
		inline Vector6ui16& operator+= (const std::uint16_t& number) noexcept;
		inline Vector6ui16& operator-= (const std::uint16_t& number) noexcept;
		inline Vector6ui16& operator*= (const std::uint16_t& number) noexcept;
		inline Vector6ui16& operator/= (const std::uint16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6ui16& other) const noexcept;
		inline bool operator<  (const Vector6ui16& other) const noexcept;
		inline bool operator>  (const Vector6ui16& other) const noexcept;
		inline bool operator>= (const Vector6ui16& other) const noexcept;
		
		inline bool operator<  (const std::uint16_t& number) const noexcept;
		inline bool operator<= (const std::uint16_t& number) const noexcept;
		inline bool operator>  (const std::uint16_t& number) const noexcept;
		inline bool operator>= (const std::uint16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6ui16& other) const noexcept;
		inline bool operator!=(const Vector6ui16& other) const noexcept;
		inline bool operator==(const std::uint16_t& number)  const noexcept;
		inline bool operator!=(const std::uint16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint16_t& stnd_value = 0) noexcept;
		inline std::uint16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector7ui16
	{
	public:
		std::uint16_t a, b, c, d, e, f, g;
	public:
		inline Vector7ui16(const std::uint16_t& a = 0, const std::uint16_t& b = 0, const std::uint16_t& c = 0, const std::uint16_t& d = 0,
			const std::uint16_t& e = 0, const std::uint16_t& f = 0, const std::uint16_t& g = 0) noexcept;
		// copy
		inline Vector7ui16(const Vector7ui16& other) noexcept;
		inline Vector7ui16& operator=(const Vector7ui16& other) noexcept;
		// move
		inline Vector7ui16(Vector7ui16&& other) noexcept;
		inline Vector7ui16& operator=(Vector7ui16&& other) noexcept;
		// assignment
		inline Vector7ui16& operator=(const std::uint16_t& number) noexcept;
		
		// math operator
		inline Vector7ui16 operator +(const Vector7ui16& v) const noexcept;
		inline Vector7ui16 operator -(const Vector7ui16& v) const noexcept;
		inline Vector7ui16 operator *(const Vector7ui16& v) const noexcept;
		inline Vector7ui16 operator /(const Vector7ui16& v) const noexcept;
		
		inline Vector7ui16 operator +(const std::uint16_t& number) const noexcept;
		inline Vector7ui16 operator -(const std::uint16_t& number) const noexcept;
		inline Vector7ui16 operator *(const std::uint16_t& number) const noexcept;
		inline Vector7ui16 operator /(const std::uint16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector7ui16& operator++ () noexcept;		// prefix increment
		inline Vector7ui16& operator-- () noexcept;		// prefix decrement
		inline Vector7ui16  operator++ (int) noexcept;		// postfix increment
		inline Vector7ui16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7ui16& operator+= (const Vector7ui16& right) noexcept;
		inline Vector7ui16& operator-= (const Vector7ui16& right) noexcept;
		inline Vector7ui16& operator*= (const Vector7ui16& right) noexcept;
		inline Vector7ui16& operator/= (const Vector7ui16& right) noexcept;
		
		inline Vector7ui16& operator+= (const std::uint16_t& number) noexcept;
		inline Vector7ui16& operator-= (const std::uint16_t& number) noexcept;
		inline Vector7ui16& operator*= (const std::uint16_t& number) noexcept;
		inline Vector7ui16& operator/= (const std::uint16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7ui16& other) const noexcept;
		inline bool operator<  (const Vector7ui16& other) const noexcept;
		inline bool operator>  (const Vector7ui16& other) const noexcept;
		inline bool operator>= (const Vector7ui16& other) const noexcept;
		
		inline bool operator<  (const std::uint16_t& number) const noexcept;
		inline bool operator<= (const std::uint16_t& number) const noexcept;
		inline bool operator>  (const std::uint16_t& number) const noexcept;
		inline bool operator>= (const std::uint16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7ui16& other) const noexcept;
		inline bool operator!=(const Vector7ui16& other) const noexcept;
		inline bool operator==(const std::uint16_t& number)  const noexcept;
		inline bool operator!=(const std::uint16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint16_t& stnd_value = 0) noexcept;
		inline std::uint16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector8ui16
	{
	public:
		std::uint16_t a, b, c, d, e, f, g, h;
	public:
		inline Vector8ui16(const std::uint16_t& a = 0, const std::uint16_t& b = 0, const std::uint16_t& c = 0, const std::uint16_t& d = 0,
			const std::uint16_t& e = 0, const std::uint16_t& f = 0, const std::uint16_t& g = 0, const std::uint16_t& h = 0) noexcept;
		// copy
		inline Vector8ui16(const Vector8ui16& other) noexcept;
		inline Vector8ui16& operator=(const Vector8ui16& other) noexcept;
		// move
		inline Vector8ui16(Vector8ui16&& other) noexcept;
		inline Vector8ui16& operator=(Vector8ui16&& other) noexcept;
		// assignment
		inline Vector8ui16& operator=(const std::uint16_t& number) noexcept;
		
		// math operator
		inline Vector8ui16 operator +(const Vector8ui16& v) const noexcept;
		inline Vector8ui16 operator -(const Vector8ui16& v) const noexcept;
		inline Vector8ui16 operator *(const Vector8ui16& v) const noexcept;
		inline Vector8ui16 operator /(const Vector8ui16& v) const noexcept;
		
		inline Vector8ui16 operator +(const std::uint16_t& number) const noexcept;
		inline Vector8ui16 operator -(const std::uint16_t& number) const noexcept;
		inline Vector8ui16 operator *(const std::uint16_t& number) const noexcept;
		inline Vector8ui16 operator /(const std::uint16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector8ui16& operator++ () noexcept;		// prefix increment
		inline Vector8ui16& operator-- () noexcept;		// prefix decrement
		inline Vector8ui16  operator++ (int) noexcept;		// postfix increment
		inline Vector8ui16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8ui16& operator+= (const Vector8ui16& right) noexcept;
		inline Vector8ui16& operator-= (const Vector8ui16& right) noexcept;
		inline Vector8ui16& operator*= (const Vector8ui16& right) noexcept;
		inline Vector8ui16& operator/= (const Vector8ui16& right) noexcept;
		
		inline Vector8ui16& operator+= (const std::uint16_t& number) noexcept;
		inline Vector8ui16& operator-= (const std::uint16_t& number) noexcept;
		inline Vector8ui16& operator*= (const std::uint16_t& number) noexcept;
		inline Vector8ui16& operator/= (const std::uint16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8ui16& other) const noexcept;
		inline bool operator<  (const Vector8ui16& other) const noexcept;
		inline bool operator>  (const Vector8ui16& other) const noexcept;
		inline bool operator>= (const Vector8ui16& other) const noexcept;
		
		inline bool operator<  (const std::uint16_t& number) const noexcept;
		inline bool operator<= (const std::uint16_t& number) const noexcept;
		inline bool operator>  (const std::uint16_t& number) const noexcept;
		inline bool operator>= (const std::uint16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8ui16& other) const noexcept;
		inline bool operator!=(const Vector8ui16& other) const noexcept;
		inline bool operator==(const std::uint16_t& number)  const noexcept;
		inline bool operator!=(const std::uint16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint16_t& stnd_value = 0) noexcept;
		inline std::uint16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector9ui16
	{
	public:
		std::uint16_t a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9ui16(const std::uint16_t& a = 0, const std::uint16_t& b = 0, const std::uint16_t& c = 0, const std::uint16_t& d = 0,
			const std::uint16_t& e = 0, const std::uint16_t& f = 0, const std::uint16_t& g = 0, const std::uint16_t& h = 0,
			const std::uint16_t& i = 0) noexcept;
		// copy
		inline Vector9ui16(const Vector9ui16& other) noexcept;
		inline Vector9ui16& operator=(const Vector9ui16& other) noexcept;
		// move
		inline Vector9ui16(Vector9ui16&& other) noexcept;
		inline Vector9ui16& operator=(Vector9ui16&& other) noexcept;
		// assignment
		inline Vector9ui16& operator=(const std::uint16_t& number) noexcept;
		
		// math operator
		inline Vector9ui16 operator +(const Vector9ui16& v) const noexcept;
		inline Vector9ui16 operator -(const Vector9ui16& v) const noexcept;
		inline Vector9ui16 operator *(const Vector9ui16& v) const noexcept;
		inline Vector9ui16 operator /(const Vector9ui16& v) const noexcept;
		
		inline Vector9ui16 operator +(const std::uint16_t& number) const noexcept;
		inline Vector9ui16 operator -(const std::uint16_t& number) const noexcept;
		inline Vector9ui16 operator *(const std::uint16_t& number) const noexcept;
		inline Vector9ui16 operator /(const std::uint16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector9ui16& operator++ () noexcept;		// prefix increment
		inline Vector9ui16& operator-- () noexcept;		// prefix decrement
		inline Vector9ui16  operator++ (int) noexcept;		// postfix increment
		inline Vector9ui16  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9ui16& operator+= (const Vector9ui16& right) noexcept;
		inline Vector9ui16& operator-= (const Vector9ui16& right) noexcept;
		inline Vector9ui16& operator*= (const Vector9ui16& right) noexcept;
		inline Vector9ui16& operator/= (const Vector9ui16& right) noexcept;
		
		inline Vector9ui16& operator+= (const std::uint16_t& number) noexcept;
		inline Vector9ui16& operator-= (const std::uint16_t& number) noexcept;
		inline Vector9ui16& operator*= (const std::uint16_t& number) noexcept;
		inline Vector9ui16& operator/= (const std::uint16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9ui16& other) const noexcept;
		inline bool operator<  (const Vector9ui16& other) const noexcept;
		inline bool operator>  (const Vector9ui16& other) const noexcept;
		inline bool operator>= (const Vector9ui16& other) const noexcept;
		
		inline bool operator<  (const std::uint16_t& number) const noexcept;
		inline bool operator<= (const std::uint16_t& number) const noexcept;
		inline bool operator>  (const std::uint16_t& number) const noexcept;
		inline bool operator>= (const std::uint16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9ui16& other) const noexcept;
		inline bool operator!=(const Vector9ui16& other) const noexcept;
		inline bool operator==(const std::uint16_t& number)  const noexcept;
		inline bool operator!=(const std::uint16_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint16_t& stnd_value = 0) noexcept;
		inline std::uint16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint16_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector10ui16
	{
	public:
		std::uint16_t a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10ui16(const std::uint16_t& a = 0, const std::uint16_t& b = 0, const std::uint16_t& c = 0, const std::uint16_t& d = 0,
			const std::uint16_t& e = 0, const std::uint16_t& f = 0, const std::uint16_t& g = 0, const std::uint16_t& h = 0,
			const std::uint16_t& i = 0, const std::uint16_t& j = 0) noexcept;
		// copy
		inline Vector10ui16(const Vector10ui16& other) noexcept;
		inline Vector10ui16& operator=(const Vector10ui16& other) noexcept;
		// move
		inline Vector10ui16(Vector10ui16&& other) noexcept;
		inline Vector10ui16& operator=(Vector10ui16&& other) noexcept;
		// assignment
		inline Vector10ui16& operator=(const std::uint16_t& number) noexcept;
		
		// math operator
		inline Vector10ui16 operator +(const Vector10ui16& v) const noexcept;
		inline Vector10ui16 operator -(const Vector10ui16& v) const noexcept;
		inline Vector10ui16 operator *(const Vector10ui16& v) const noexcept;
		inline Vector10ui16 operator /(const Vector10ui16& v) const noexcept;
		
		inline Vector10ui16 operator +(const std::uint16_t& number) const noexcept;
		inline Vector10ui16 operator -(const std::uint16_t& number) const noexcept;
		inline Vector10ui16 operator *(const std::uint16_t& number) const noexcept;
		inline Vector10ui16 operator /(const std::uint16_t& number) const noexcept;
		
		// increment / decrement
		inline Vector10ui16& operator++ () noexcept;		// prefix increment
		inline Vector10ui16& operator-- () noexcept;		// prefix decrement
		inline Vector10ui16  operator++ (int) noexcept;	// postfix increment
		inline Vector10ui16  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10ui16& operator+= (const Vector10ui16& right) noexcept;
		inline Vector10ui16& operator-= (const Vector10ui16& right) noexcept;
		inline Vector10ui16& operator*= (const Vector10ui16& right) noexcept;
		inline Vector10ui16& operator/= (const Vector10ui16& right) noexcept;
		
		inline Vector10ui16& operator+= (const std::uint16_t& number) noexcept;
		inline Vector10ui16& operator-= (const std::uint16_t& number) noexcept;
		inline Vector10ui16& operator*= (const std::uint16_t& number) noexcept;
		inline Vector10ui16& operator/= (const std::uint16_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10ui16& other) const noexcept;
		inline bool operator<  (const Vector10ui16& other) const noexcept;
		inline bool operator>  (const Vector10ui16& other) const noexcept;
		inline bool operator>= (const Vector10ui16& other) const noexcept;

		inline bool operator<  (const std::uint16_t& number) const noexcept;
		inline bool operator<= (const std::uint16_t& number) const noexcept;
		inline bool operator>  (const std::uint16_t& number) const noexcept;
		inline bool operator>= (const std::uint16_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10ui16& other) const noexcept;
		inline bool operator!=(const Vector10ui16& other) const noexcept;
		inline bool operator==(const std::uint16_t& number)   const noexcept;
		inline bool operator!=(const std::uint16_t& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint16_t& stnd_value = 0) noexcept;
		inline std::uint16_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint16_t& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2ui16& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3ui16& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4ui16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5ui16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6ui16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7ui16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8ui16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9ui16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10ui16& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}