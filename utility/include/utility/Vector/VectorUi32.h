#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::uint32_t
		Bytes: 4
		Range: 0 to 4.294.967.295
	*/

	class Vector2ui32
	{
	public:
		std::uint32_t x, y;
	public:
		inline Vector2ui32(const std::uint32_t& x = 0U, const std::uint32_t& y = 0U) noexcept;
		// copy
		inline Vector2ui32(const Vector2ui32& other) noexcept;
		inline Vector2ui32& operator=(const Vector2ui32& other) noexcept;
		// move
		inline Vector2ui32(Vector2ui32&& other) noexcept;
		inline Vector2ui32& operator=(Vector2ui32&& other) noexcept;
		// assignment
		inline Vector2ui32& operator=(const std::uint32_t& number) noexcept;

		// math operator
		inline Vector2ui32 operator +(const Vector2ui32& v) const noexcept;
		inline Vector2ui32 operator -(const Vector2ui32& v) const noexcept;
		inline Vector2ui32 operator *(const Vector2ui32& v) const noexcept;
		inline Vector2ui32 operator /(const Vector2ui32& v) const noexcept;

		inline Vector2ui32 operator +(const std::uint32_t& number) const noexcept;
		inline Vector2ui32 operator -(const std::uint32_t& number) const noexcept;
		inline Vector2ui32 operator *(const std::uint32_t& number) const noexcept;
		inline Vector2ui32 operator /(const std::uint32_t& number) const noexcept;

		// increment / decrement
		inline Vector2ui32& operator++ () noexcept;		// prefix increment
		inline Vector2ui32& operator-- () noexcept;		// prefix decrement
		inline Vector2ui32  operator++ (int) noexcept;		// postfix increment
		inline Vector2ui32  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2ui32& operator+= (const Vector2ui32& right) noexcept;
		inline Vector2ui32& operator-= (const Vector2ui32& right) noexcept;
		inline Vector2ui32& operator*= (const Vector2ui32& right) noexcept;
		inline Vector2ui32& operator/= (const Vector2ui32& right) noexcept;

		inline Vector2ui32& operator+= (const std::uint32_t& number) noexcept;
		inline Vector2ui32& operator-= (const std::uint32_t& number) noexcept;
		inline Vector2ui32& operator*= (const std::uint32_t& number) noexcept;
		inline Vector2ui32& operator/= (const std::uint32_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2ui32& other) const noexcept;
		inline bool operator<=  (const Vector2ui32& other) const noexcept;
		inline bool operator>	(const Vector2ui32& other) const noexcept;
		inline bool operator>=  (const Vector2ui32& other) const noexcept;

		inline bool operator<	(const std::uint32_t& number) const noexcept;
		inline bool operator<=  (const std::uint32_t& number) const noexcept;
		inline bool operator>	(const std::uint32_t& number) const noexcept;
		inline bool operator>=  (const std::uint32_t& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2ui32& other) const noexcept;
		inline bool operator!=(const Vector2ui32& other) const noexcept;
		inline bool operator==(const std::uint32_t& number)  const noexcept;
		inline bool operator!=(const std::uint32_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint32_t& stnd_value = 0U) noexcept;
		inline std::uint32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector3ui32
	{
	public:
		std::uint32_t x, y, z;
	public:
		inline Vector3ui32(const std::uint32_t& x = 0U, const std::uint32_t& y = 0U, const std::uint32_t& z = 0U) noexcept;
		// copy
		inline Vector3ui32(const Vector3ui32& other) noexcept;
		inline Vector3ui32& operator=(const Vector3ui32& other) noexcept;
		// move
		inline Vector3ui32(Vector3ui32&& other) noexcept;
		inline Vector3ui32& operator=(Vector3ui32&& other) noexcept;
		// assignment
		inline Vector3ui32& operator=(const std::uint32_t& number) noexcept;

		// math operator
		inline Vector3ui32 operator +(const Vector3ui32& v) const noexcept;
		inline Vector3ui32 operator -(const Vector3ui32& v) const noexcept;
		inline Vector3ui32 operator *(const Vector3ui32& v) const noexcept;
		inline Vector3ui32 operator /(const Vector3ui32& v) const noexcept;

		inline Vector3ui32 operator +(const std::uint32_t& number) const noexcept;
		inline Vector3ui32 operator -(const std::uint32_t& number) const noexcept;
		inline Vector3ui32 operator *(const std::uint32_t& number) const noexcept;
		inline Vector3ui32 operator /(const std::uint32_t& number) const noexcept;

		// increment / decrement
		inline Vector3ui32& operator++ () noexcept;		// prefix increment
		inline Vector3ui32& operator-- () noexcept;		// prefix decrement
		inline Vector3ui32  operator++ (int) noexcept;		// postfix increment
		inline Vector3ui32  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3ui32& operator+= (const Vector3ui32& right) noexcept;
		inline Vector3ui32& operator-= (const Vector3ui32& right) noexcept;
		inline Vector3ui32& operator*= (const Vector3ui32& right) noexcept;
		inline Vector3ui32& operator/= (const Vector3ui32& right) noexcept;

		inline Vector3ui32& operator+= (const std::uint32_t& number) noexcept;
		inline Vector3ui32& operator-= (const std::uint32_t& number) noexcept;
		inline Vector3ui32& operator*= (const std::uint32_t& number) noexcept;
		inline Vector3ui32& operator/= (const std::uint32_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3ui32& other) const noexcept;
		inline bool operator<=  (const Vector3ui32& other) const noexcept;
		inline bool operator>	(const Vector3ui32& other) const noexcept;
		inline bool operator>=  (const Vector3ui32& other) const noexcept;
		 
		inline bool operator<	(const std::uint32_t& number) const noexcept;
		inline bool operator<=  (const std::uint32_t& number) const noexcept;
		inline bool operator>	(const std::uint32_t& number) const noexcept;
		inline bool operator>=  (const std::uint32_t& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3ui32& other) const noexcept;
		inline bool operator!=(const Vector3ui32& other) const noexcept;
		inline bool operator==(const std::uint32_t& number)  const noexcept;
		inline bool operator!=(const std::uint32_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint32_t& stnd_value = 0U) noexcept;
		inline std::uint32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector4ui32
	{
	public:
		std::uint32_t a, b, c, d;
	public:
		inline Vector4ui32(const std::uint32_t& a = 0U, const std::uint32_t& b = 0U, const std::uint32_t& c = 0U, const std::uint32_t& d = 0U) noexcept;
		// copy
		inline Vector4ui32(const Vector4ui32& other) noexcept;
		inline Vector4ui32& operator=(const Vector4ui32& other) noexcept;
		// move
		inline Vector4ui32(Vector4ui32&& other) noexcept;
		inline Vector4ui32& operator=(Vector4ui32&& other) noexcept;
		// assignment
		inline Vector4ui32& operator=(const std::uint32_t& number) noexcept;
		
		// math operator
		inline Vector4ui32 operator +(const Vector4ui32& v) const noexcept;
		inline Vector4ui32 operator -(const Vector4ui32& v) const noexcept;
		inline Vector4ui32 operator *(const Vector4ui32& v) const noexcept;
		inline Vector4ui32 operator /(const Vector4ui32& v) const noexcept;
		
		inline Vector4ui32 operator +(const std::uint32_t& number) const noexcept;
		inline Vector4ui32 operator -(const std::uint32_t& number) const noexcept;
		inline Vector4ui32 operator *(const std::uint32_t& number) const noexcept;
		inline Vector4ui32 operator /(const std::uint32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector4ui32& operator++ () noexcept;		// prefix increment
		inline Vector4ui32& operator-- () noexcept;		// prefix decrement
		inline Vector4ui32  operator++ (int) noexcept;		// postfix increment
		inline Vector4ui32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4ui32& operator+= (const Vector4ui32& right) noexcept;
		inline Vector4ui32& operator-= (const Vector4ui32& right) noexcept;
		inline Vector4ui32& operator*= (const Vector4ui32& right) noexcept;
		inline Vector4ui32& operator/= (const Vector4ui32& right) noexcept;
		
		inline Vector4ui32& operator+= (const std::uint32_t& number) noexcept;
		inline Vector4ui32& operator-= (const std::uint32_t& number) noexcept;
		inline Vector4ui32& operator*= (const std::uint32_t& number) noexcept;
		inline Vector4ui32& operator/= (const std::uint32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4ui32& other) const noexcept;
		inline bool operator<=  (const Vector4ui32& other) const noexcept;
		inline bool operator>	(const Vector4ui32& other) const noexcept;
		inline bool operator>=  (const Vector4ui32& other) const noexcept;
		
		inline bool operator<	(const std::uint32_t& number) const noexcept;
		inline bool operator<=  (const std::uint32_t& number) const noexcept;
		inline bool operator>	(const std::uint32_t& number) const noexcept;
		inline bool operator>=  (const std::uint32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4ui32& other) const noexcept;
		inline bool operator!=(const Vector4ui32& other) const noexcept;
		inline bool operator==(const std::uint32_t& number)  const noexcept;
		inline bool operator!=(const std::uint32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint32_t& stnd_value = 0U) noexcept;
		inline std::uint32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector5ui32
	{
	public:
		std::uint32_t a, b, c, d, e;
	public:
		inline Vector5ui32(const std::uint32_t& a = 0U, const std::uint32_t& b = 0U, const std::uint32_t& c = 0U, const std::uint32_t& d = 0U,
			const std::uint32_t& e = 0U) noexcept;
		// copy
		inline Vector5ui32(const Vector5ui32& other) noexcept;
		inline Vector5ui32& operator=(const Vector5ui32& other) noexcept;
		// move
		inline Vector5ui32(Vector5ui32&& other) noexcept;
		inline Vector5ui32& operator=(Vector5ui32&& other) noexcept;
		// assignment
		inline Vector5ui32& operator=(const std::uint32_t& number) noexcept;
		 
		// math operator
		inline Vector5ui32 operator +(const Vector5ui32& v) const noexcept;
		inline Vector5ui32 operator -(const Vector5ui32& v) const noexcept;
		inline Vector5ui32 operator *(const Vector5ui32& v) const noexcept;
		inline Vector5ui32 operator /(const Vector5ui32& v) const noexcept;
		
		inline Vector5ui32 operator +(const std::uint32_t& number) const noexcept;
		inline Vector5ui32 operator -(const std::uint32_t& number) const noexcept;
		inline Vector5ui32 operator *(const std::uint32_t& number) const noexcept;
		inline Vector5ui32 operator /(const std::uint32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector5ui32& operator++ () noexcept;		// prefix increment
		inline Vector5ui32& operator-- () noexcept;		// prefix decrement
		inline Vector5ui32  operator++ (int) noexcept;		// postfix increment
		inline Vector5ui32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5ui32& operator+= (const Vector5ui32& right) noexcept;
		inline Vector5ui32& operator-= (const Vector5ui32& right) noexcept;
		inline Vector5ui32& operator*= (const Vector5ui32& right) noexcept;
		inline Vector5ui32& operator/= (const Vector5ui32& right) noexcept;
		
		inline Vector5ui32& operator+= (const std::uint32_t& number) noexcept;
		inline Vector5ui32& operator-= (const std::uint32_t& number) noexcept;
		inline Vector5ui32& operator*= (const std::uint32_t& number) noexcept;
		inline Vector5ui32& operator/= (const std::uint32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5ui32& other) const noexcept;
		inline bool operator<=  (const Vector5ui32& other) const noexcept;
		inline bool operator>	(const Vector5ui32& other) const noexcept;
		inline bool operator>=  (const Vector5ui32& other) const noexcept;
		
		inline bool operator<	(const std::uint32_t& number) const noexcept;
		inline bool operator<=  (const std::uint32_t& number) const noexcept;
		inline bool operator>	(const std::uint32_t& number) const noexcept;
		inline bool operator>=  (const std::uint32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5ui32& other) const noexcept;
		inline bool operator!=(const Vector5ui32& other) const noexcept;
		inline bool operator==(const std::uint32_t& number)  const noexcept;
		inline bool operator!=(const std::uint32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint32_t& stnd_value = 0U) noexcept;
		inline std::uint32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector6ui32
	{
	public:
		std::uint32_t a, b, c, d, e, f;
	public:
		inline Vector6ui32(const std::uint32_t& a = 0U, const std::uint32_t& b = 0U, const std::uint32_t& c = 0U, const std::uint32_t& d = 0U,
			const std::uint32_t& e = 0U, const std::uint32_t& f = 0U) noexcept;
		// copy
		inline Vector6ui32(const Vector6ui32& other) noexcept;
		inline Vector6ui32& operator=(const Vector6ui32& other) noexcept;
		// move
		inline Vector6ui32(Vector6ui32&& other) noexcept;
		inline Vector6ui32& operator=(Vector6ui32&& other) noexcept;
		// assignment
		inline Vector6ui32& operator=(const std::uint32_t& number) noexcept;
		
		// math operator
		inline Vector6ui32 operator +(const Vector6ui32& v) const noexcept;
		inline Vector6ui32 operator -(const Vector6ui32& v) const noexcept;
		inline Vector6ui32 operator *(const Vector6ui32& v) const noexcept;
		inline Vector6ui32 operator /(const Vector6ui32& v) const noexcept;
		
		inline Vector6ui32 operator +(const std::uint32_t& number) const noexcept;
		inline Vector6ui32 operator -(const std::uint32_t& number) const noexcept;
		inline Vector6ui32 operator *(const std::uint32_t& number) const noexcept;
		inline Vector6ui32 operator /(const std::uint32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector6ui32& operator++ () noexcept;		// prefix increment
		inline Vector6ui32& operator-- () noexcept;		// prefix decrement
		inline Vector6ui32  operator++ (int) noexcept;		// postfix increment
		inline Vector6ui32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6ui32& operator+= (const Vector6ui32& right) noexcept;
		inline Vector6ui32& operator-= (const Vector6ui32& right) noexcept;
		inline Vector6ui32& operator*= (const Vector6ui32& right) noexcept;
		inline Vector6ui32& operator/= (const Vector6ui32& right) noexcept;
		
		inline Vector6ui32& operator+= (const std::uint32_t& number) noexcept;
		inline Vector6ui32& operator-= (const std::uint32_t& number) noexcept;
		inline Vector6ui32& operator*= (const std::uint32_t& number) noexcept;
		inline Vector6ui32& operator/= (const std::uint32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6ui32& other) const noexcept;
		inline bool operator<  (const Vector6ui32& other) const noexcept;
		inline bool operator>  (const Vector6ui32& other) const noexcept;
		inline bool operator>= (const Vector6ui32& other) const noexcept;
		
		inline bool operator<  (const std::uint32_t& number) const noexcept;
		inline bool operator<= (const std::uint32_t& number) const noexcept;
		inline bool operator>  (const std::uint32_t& number) const noexcept;
		inline bool operator>= (const std::uint32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6ui32& other) const noexcept;
		inline bool operator!=(const Vector6ui32& other) const noexcept;
		inline bool operator==(const std::uint32_t& number)  const noexcept;
		inline bool operator!=(const std::uint32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint32_t& stnd_value = 0U) noexcept;
		inline std::uint32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector7ui32
	{
	public:
		std::uint32_t a, b, c, d, e, f, g;
	public:
		inline Vector7ui32(const std::uint32_t& a = 0U, const std::uint32_t& b = 0U, const std::uint32_t& c = 0U, const std::uint32_t& d = 0U,
			const std::uint32_t& e = 0U, const std::uint32_t& f = 0U, const std::uint32_t& g = 0U) noexcept;
		// copy
		inline Vector7ui32(const Vector7ui32& other) noexcept;
		inline Vector7ui32& operator=(const Vector7ui32& other) noexcept;
		// move
		inline Vector7ui32(Vector7ui32&& other) noexcept;
		inline Vector7ui32& operator=(Vector7ui32&& other) noexcept;
		// assignment
		inline Vector7ui32& operator=(const std::uint32_t& number) noexcept;
		
		// math operator
		inline Vector7ui32 operator +(const Vector7ui32& v) const noexcept;
		inline Vector7ui32 operator -(const Vector7ui32& v) const noexcept;
		inline Vector7ui32 operator *(const Vector7ui32& v) const noexcept;
		inline Vector7ui32 operator /(const Vector7ui32& v) const noexcept;
		
		inline Vector7ui32 operator +(const std::uint32_t& number) const noexcept;
		inline Vector7ui32 operator -(const std::uint32_t& number) const noexcept;
		inline Vector7ui32 operator *(const std::uint32_t& number) const noexcept;
		inline Vector7ui32 operator /(const std::uint32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector7ui32& operator++ () noexcept;		// prefix increment
		inline Vector7ui32& operator-- () noexcept;		// prefix decrement
		inline Vector7ui32  operator++ (int) noexcept;		// postfix increment
		inline Vector7ui32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7ui32& operator+= (const Vector7ui32& right) noexcept;
		inline Vector7ui32& operator-= (const Vector7ui32& right) noexcept;
		inline Vector7ui32& operator*= (const Vector7ui32& right) noexcept;
		inline Vector7ui32& operator/= (const Vector7ui32& right) noexcept;
		
		inline Vector7ui32& operator+= (const std::uint32_t& number) noexcept;
		inline Vector7ui32& operator-= (const std::uint32_t& number) noexcept;
		inline Vector7ui32& operator*= (const std::uint32_t& number) noexcept;
		inline Vector7ui32& operator/= (const std::uint32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7ui32& other) const noexcept;
		inline bool operator<  (const Vector7ui32& other) const noexcept;
		inline bool operator>  (const Vector7ui32& other) const noexcept;
		inline bool operator>= (const Vector7ui32& other) const noexcept;
		
		inline bool operator<  (const std::uint32_t& number) const noexcept;
		inline bool operator<= (const std::uint32_t& number) const noexcept;
		inline bool operator>  (const std::uint32_t& number) const noexcept;
		inline bool operator>= (const std::uint32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7ui32& other) const noexcept;
		inline bool operator!=(const Vector7ui32& other) const noexcept;
		inline bool operator==(const std::uint32_t& number)  const noexcept;
		inline bool operator!=(const std::uint32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint32_t& stnd_value = 0U) noexcept;
		inline std::uint32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector8ui32
	{
	public:
		std::uint32_t a, b, c, d, e, f, g, h;
	public:
		inline Vector8ui32(const std::uint32_t& a = 0U, const std::uint32_t& b = 0U, const std::uint32_t& c = 0U, const std::uint32_t& d = 0U,
			const std::uint32_t& e = 0U, const std::uint32_t& f = 0U, const std::uint32_t& g = 0U, const std::uint32_t& h = 0U) noexcept;
		// copy
		inline Vector8ui32(const Vector8ui32& other) noexcept;
		inline Vector8ui32& operator=(const Vector8ui32& other) noexcept;
		// move
		inline Vector8ui32(Vector8ui32&& other) noexcept;
		inline Vector8ui32& operator=(Vector8ui32&& other) noexcept;
		// assignment
		inline Vector8ui32& operator=(const std::uint32_t& number) noexcept;
		
		// math operator
		inline Vector8ui32 operator +(const Vector8ui32& v) const noexcept;
		inline Vector8ui32 operator -(const Vector8ui32& v) const noexcept;
		inline Vector8ui32 operator *(const Vector8ui32& v) const noexcept;
		inline Vector8ui32 operator /(const Vector8ui32& v) const noexcept;
		
		inline Vector8ui32 operator +(const std::uint32_t& number) const noexcept;
		inline Vector8ui32 operator -(const std::uint32_t& number) const noexcept;
		inline Vector8ui32 operator *(const std::uint32_t& number) const noexcept;
		inline Vector8ui32 operator /(const std::uint32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector8ui32& operator++ () noexcept;		// prefix increment
		inline Vector8ui32& operator-- () noexcept;		// prefix decrement
		inline Vector8ui32  operator++ (int) noexcept;		// postfix increment
		inline Vector8ui32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8ui32& operator+= (const Vector8ui32& right) noexcept;
		inline Vector8ui32& operator-= (const Vector8ui32& right) noexcept;
		inline Vector8ui32& operator*= (const Vector8ui32& right) noexcept;
		inline Vector8ui32& operator/= (const Vector8ui32& right) noexcept;
		
		inline Vector8ui32& operator+= (const std::uint32_t& number) noexcept;
		inline Vector8ui32& operator-= (const std::uint32_t& number) noexcept;
		inline Vector8ui32& operator*= (const std::uint32_t& number) noexcept;
		inline Vector8ui32& operator/= (const std::uint32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8ui32& other) const noexcept;
		inline bool operator<  (const Vector8ui32& other) const noexcept;
		inline bool operator>  (const Vector8ui32& other) const noexcept;
		inline bool operator>= (const Vector8ui32& other) const noexcept;
		
		inline bool operator<  (const std::uint32_t& number) const noexcept;
		inline bool operator<= (const std::uint32_t& number) const noexcept;
		inline bool operator>  (const std::uint32_t& number) const noexcept;
		inline bool operator>= (const std::uint32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8ui32& other) const noexcept;
		inline bool operator!=(const Vector8ui32& other) const noexcept;
		inline bool operator==(const std::uint32_t& number)  const noexcept;
		inline bool operator!=(const std::uint32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint32_t& stnd_value = 0U) noexcept;
		inline std::uint32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector9ui32
	{
	public:
		std::uint32_t a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9ui32(const std::uint32_t& a = 0U, const std::uint32_t& b = 0U, const std::uint32_t& c = 0U, const std::uint32_t& d = 0U,
			const std::uint32_t& e = 0U, const std::uint32_t& f = 0U, const std::uint32_t& g = 0U, const std::uint32_t& h = 0U,
			const std::uint32_t& i = 0U) noexcept;
		// copy
		inline Vector9ui32(const Vector9ui32& other) noexcept;
		inline Vector9ui32& operator=(const Vector9ui32& other) noexcept;
		// move
		inline Vector9ui32(Vector9ui32&& other) noexcept;
		inline Vector9ui32& operator=(Vector9ui32&& other) noexcept;
		// assignment
		inline Vector9ui32& operator=(const std::uint32_t& number) noexcept;
		
		// math operator
		inline Vector9ui32 operator +(const Vector9ui32& v) const noexcept;
		inline Vector9ui32 operator -(const Vector9ui32& v) const noexcept;
		inline Vector9ui32 operator *(const Vector9ui32& v) const noexcept;
		inline Vector9ui32 operator /(const Vector9ui32& v) const noexcept;
		
		inline Vector9ui32 operator +(const std::uint32_t& number) const noexcept;
		inline Vector9ui32 operator -(const std::uint32_t& number) const noexcept;
		inline Vector9ui32 operator *(const std::uint32_t& number) const noexcept;
		inline Vector9ui32 operator /(const std::uint32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector9ui32& operator++ () noexcept;		// prefix increment
		inline Vector9ui32& operator-- () noexcept;		// prefix decrement
		inline Vector9ui32  operator++ (int) noexcept;		// postfix increment
		inline Vector9ui32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9ui32& operator+= (const Vector9ui32& right) noexcept;
		inline Vector9ui32& operator-= (const Vector9ui32& right) noexcept;
		inline Vector9ui32& operator*= (const Vector9ui32& right) noexcept;
		inline Vector9ui32& operator/= (const Vector9ui32& right) noexcept;
		
		inline Vector9ui32& operator+= (const std::uint32_t& number) noexcept;
		inline Vector9ui32& operator-= (const std::uint32_t& number) noexcept;
		inline Vector9ui32& operator*= (const std::uint32_t& number) noexcept;
		inline Vector9ui32& operator/= (const std::uint32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9ui32& other) const noexcept;
		inline bool operator<  (const Vector9ui32& other) const noexcept;
		inline bool operator>  (const Vector9ui32& other) const noexcept;
		inline bool operator>= (const Vector9ui32& other) const noexcept;
		
		inline bool operator<  (const std::uint32_t& number) const noexcept;
		inline bool operator<= (const std::uint32_t& number) const noexcept;
		inline bool operator>  (const std::uint32_t& number) const noexcept;
		inline bool operator>= (const std::uint32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9ui32& other) const noexcept;
		inline bool operator!=(const Vector9ui32& other) const noexcept;
		inline bool operator==(const std::uint32_t& number)  const noexcept;
		inline bool operator!=(const std::uint32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint32_t& stnd_value = 0U) noexcept;
		inline std::uint32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector10ui32
	{
	public:
		std::uint32_t a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10ui32(const std::uint32_t& a = 0U, const std::uint32_t& b = 0U, const std::uint32_t& c = 0U, const std::uint32_t& d = 0U,
			const std::uint32_t& e = 0U, const std::uint32_t& f = 0U, const std::uint32_t& g = 0U, const std::uint32_t& h = 0U,
			const std::uint32_t& i = 0U, const std::uint32_t& j = 0U) noexcept;
		// copy
		inline Vector10ui32(const Vector10ui32& other) noexcept;
		inline Vector10ui32& operator=(const Vector10ui32& other) noexcept;
		// move
		inline Vector10ui32(Vector10ui32&& other) noexcept;
		inline Vector10ui32& operator=(Vector10ui32&& other) noexcept;
		// assignment
		inline Vector10ui32& operator=(const std::uint32_t& number) noexcept;
		
		// math operator
		inline Vector10ui32 operator +(const Vector10ui32& v) const noexcept;
		inline Vector10ui32 operator -(const Vector10ui32& v) const noexcept;
		inline Vector10ui32 operator *(const Vector10ui32& v) const noexcept;
		inline Vector10ui32 operator /(const Vector10ui32& v) const noexcept;
		
		inline Vector10ui32 operator +(const std::uint32_t& number) const noexcept;
		inline Vector10ui32 operator -(const std::uint32_t& number) const noexcept;
		inline Vector10ui32 operator *(const std::uint32_t& number) const noexcept;
		inline Vector10ui32 operator /(const std::uint32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector10ui32& operator++ () noexcept;		// prefix increment
		inline Vector10ui32& operator-- () noexcept;		// prefix decrement
		inline Vector10ui32  operator++ (int) noexcept;	// postfix increment
		inline Vector10ui32  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10ui32& operator+= (const Vector10ui32& right) noexcept;
		inline Vector10ui32& operator-= (const Vector10ui32& right) noexcept;
		inline Vector10ui32& operator*= (const Vector10ui32& right) noexcept;
		inline Vector10ui32& operator/= (const Vector10ui32& right) noexcept;
		
		inline Vector10ui32& operator+= (const std::uint32_t& number) noexcept;
		inline Vector10ui32& operator-= (const std::uint32_t& number) noexcept;
		inline Vector10ui32& operator*= (const std::uint32_t& number) noexcept;
		inline Vector10ui32& operator/= (const std::uint32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10ui32& other) const noexcept;
		inline bool operator<  (const Vector10ui32& other) const noexcept;
		inline bool operator>  (const Vector10ui32& other) const noexcept;
		inline bool operator>= (const Vector10ui32& other) const noexcept;

		inline bool operator<  (const std::uint32_t& number) const noexcept;
		inline bool operator<= (const std::uint32_t& number) const noexcept;
		inline bool operator>  (const std::uint32_t& number) const noexcept;
		inline bool operator>= (const std::uint32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10ui32& other) const noexcept;
		inline bool operator!=(const Vector10ui32& other) const noexcept;
		inline bool operator==(const std::uint32_t& number)   const noexcept;
		inline bool operator!=(const std::uint32_t& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint32_t& stnd_value = 0U) noexcept;
		inline std::uint32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint32_t& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2ui32& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3ui32& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4ui32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5ui32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6ui32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7ui32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8ui32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9ui32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10ui32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}