#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::int32_t
		Bytes: 4
		Range: -2.147.483.648 to 2.147.483.647
	*/

	class Vector2i32
	{
	public:
		std::int32_t x, y;
	public:
		inline Vector2i32(const std::int32_t& x = 0, const std::int32_t& y = 0) noexcept;
		// copy
		inline Vector2i32(const Vector2i32& other) noexcept;
		inline Vector2i32& operator=(const Vector2i32& other) noexcept;
		// move
		inline Vector2i32(Vector2i32&& other) noexcept;
		inline Vector2i32& operator=(Vector2i32&& other) noexcept;
		// assignment
		inline Vector2i32& operator=(const std::int32_t& number) noexcept;

		// math operator
		inline Vector2i32 operator +(const Vector2i32& v) const noexcept;
		inline Vector2i32 operator -(const Vector2i32& v) const noexcept;
		inline Vector2i32 operator *(const Vector2i32& v) const noexcept;
		inline Vector2i32 operator /(const Vector2i32& v) const noexcept;

		inline Vector2i32 operator +(const std::int32_t& number) const noexcept;
		inline Vector2i32 operator -(const std::int32_t& number) const noexcept;
		inline Vector2i32 operator *(const std::int32_t& number) const noexcept;
		inline Vector2i32 operator /(const std::int32_t& number) const noexcept;

		// increment / decrement
		inline Vector2i32& operator++ () noexcept;		// prefix increment
		inline Vector2i32& operator-- () noexcept;		// prefix decrement
		inline Vector2i32  operator++ (int) noexcept;		// postfix increment
		inline Vector2i32  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2i32& operator+= (const Vector2i32& right) noexcept;
		inline Vector2i32& operator-= (const Vector2i32& right) noexcept;
		inline Vector2i32& operator*= (const Vector2i32& right) noexcept;
		inline Vector2i32& operator/= (const Vector2i32& right) noexcept;

		inline Vector2i32& operator+= (const std::int32_t& number) noexcept;
		inline Vector2i32& operator-= (const std::int32_t& number) noexcept;
		inline Vector2i32& operator*= (const std::int32_t& number) noexcept;
		inline Vector2i32& operator/= (const std::int32_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2i32& other) const noexcept;
		inline bool operator<=  (const Vector2i32& other) const noexcept;
		inline bool operator>	(const Vector2i32& other) const noexcept;
		inline bool operator>=  (const Vector2i32& other) const noexcept;

		inline bool operator<	(const std::int32_t& number) const noexcept;
		inline bool operator<=  (const std::int32_t& number) const noexcept;
		inline bool operator>	(const std::int32_t& number) const noexcept;
		inline bool operator>=  (const std::int32_t& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2i32& other) const noexcept;
		inline bool operator!=(const Vector2i32& other) const noexcept;
		inline bool operator==(const std::int32_t& number)  const noexcept;
		inline bool operator!=(const std::int32_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int32_t& stnd_value = 0) noexcept;
		inline std::int32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector3i32
	{
	public:
		std::int32_t x, y, z;
	public:
		inline Vector3i32(const std::int32_t& x = 0, const std::int32_t& y = 0, const std::int32_t& z = 0) noexcept;
		// copy
		inline Vector3i32(const Vector3i32& other) noexcept;
		inline Vector3i32& operator=(const Vector3i32& other) noexcept;
		// move
		inline Vector3i32(Vector3i32&& other) noexcept;
		inline Vector3i32& operator=(Vector3i32&& other) noexcept;
		// assignment
		inline Vector3i32& operator=(const std::int32_t& number) noexcept;

		// math operator
		inline Vector3i32 operator +(const Vector3i32& v) const noexcept;
		inline Vector3i32 operator -(const Vector3i32& v) const noexcept;
		inline Vector3i32 operator *(const Vector3i32& v) const noexcept;
		inline Vector3i32 operator /(const Vector3i32& v) const noexcept;

		inline Vector3i32 operator +(const std::int32_t& number) const noexcept;
		inline Vector3i32 operator -(const std::int32_t& number) const noexcept;
		inline Vector3i32 operator *(const std::int32_t& number) const noexcept;
		inline Vector3i32 operator /(const std::int32_t& number) const noexcept;

		// increment / decrement
		inline Vector3i32& operator++ () noexcept;		// prefix increment
		inline Vector3i32& operator-- () noexcept;		// prefix decrement
		inline Vector3i32  operator++ (int) noexcept;		// postfix increment
		inline Vector3i32  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3i32& operator+= (const Vector3i32& right) noexcept;
		inline Vector3i32& operator-= (const Vector3i32& right) noexcept;
		inline Vector3i32& operator*= (const Vector3i32& right) noexcept;
		inline Vector3i32& operator/= (const Vector3i32& right) noexcept;

		inline Vector3i32& operator+= (const std::int32_t& number) noexcept;
		inline Vector3i32& operator-= (const std::int32_t& number) noexcept;
		inline Vector3i32& operator*= (const std::int32_t& number) noexcept;
		inline Vector3i32& operator/= (const std::int32_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3i32& other) const noexcept;
		inline bool operator<=  (const Vector3i32& other) const noexcept;
		inline bool operator>	(const Vector3i32& other) const noexcept;
		inline bool operator>=  (const Vector3i32& other) const noexcept;
		 
		inline bool operator<	(const std::int32_t& number) const noexcept;
		inline bool operator<=  (const std::int32_t& number) const noexcept;
		inline bool operator>	(const std::int32_t& number) const noexcept;
		inline bool operator>=  (const std::int32_t& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3i32& other) const noexcept;
		inline bool operator!=(const Vector3i32& other) const noexcept;
		inline bool operator==(const std::int32_t& number)  const noexcept;
		inline bool operator!=(const std::int32_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int32_t& stnd_value = 0) noexcept;
		inline std::int32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector4i32
	{
	public:
		std::int32_t a, b, c, d;
	public:
		inline Vector4i32(const std::int32_t& a = 0, const std::int32_t& b = 0, const std::int32_t& c = 0, const std::int32_t& d = 0) noexcept;
		// copy
		inline Vector4i32(const Vector4i32& other) noexcept;
		inline Vector4i32& operator=(const Vector4i32& other) noexcept;
		// move
		inline Vector4i32(Vector4i32&& other) noexcept;
		inline Vector4i32& operator=(Vector4i32&& other) noexcept;
		// assignment
		inline Vector4i32& operator=(const std::int32_t& number) noexcept;
		
		// math operator
		inline Vector4i32 operator +(const Vector4i32& v) const noexcept;
		inline Vector4i32 operator -(const Vector4i32& v) const noexcept;
		inline Vector4i32 operator *(const Vector4i32& v) const noexcept;
		inline Vector4i32 operator /(const Vector4i32& v) const noexcept;
		
		inline Vector4i32 operator +(const std::int32_t& number) const noexcept;
		inline Vector4i32 operator -(const std::int32_t& number) const noexcept;
		inline Vector4i32 operator *(const std::int32_t& number) const noexcept;
		inline Vector4i32 operator /(const std::int32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector4i32& operator++ () noexcept;		// prefix increment
		inline Vector4i32& operator-- () noexcept;		// prefix decrement
		inline Vector4i32  operator++ (int) noexcept;		// postfix increment
		inline Vector4i32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4i32& operator+= (const Vector4i32& right) noexcept;
		inline Vector4i32& operator-= (const Vector4i32& right) noexcept;
		inline Vector4i32& operator*= (const Vector4i32& right) noexcept;
		inline Vector4i32& operator/= (const Vector4i32& right) noexcept;
		
		inline Vector4i32& operator+= (const std::int32_t& number) noexcept;
		inline Vector4i32& operator-= (const std::int32_t& number) noexcept;
		inline Vector4i32& operator*= (const std::int32_t& number) noexcept;
		inline Vector4i32& operator/= (const std::int32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4i32& other) const noexcept;
		inline bool operator<=  (const Vector4i32& other) const noexcept;
		inline bool operator>	(const Vector4i32& other) const noexcept;
		inline bool operator>=  (const Vector4i32& other) const noexcept;
		
		inline bool operator<	(const std::int32_t& number) const noexcept;
		inline bool operator<=  (const std::int32_t& number) const noexcept;
		inline bool operator>	(const std::int32_t& number) const noexcept;
		inline bool operator>=  (const std::int32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4i32& other) const noexcept;
		inline bool operator!=(const Vector4i32& other) const noexcept;
		inline bool operator==(const std::int32_t& number)  const noexcept;
		inline bool operator!=(const std::int32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int32_t& stnd_value = 0) noexcept;
		inline std::int32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector5i32
	{
	public:
		std::int32_t a, b, c, d, e;
	public:
		inline Vector5i32(const std::int32_t& a = 0, const std::int32_t& b = 0, const std::int32_t& c = 0, const std::int32_t& d = 0,
			const std::int32_t& e = 0) noexcept;
		// copy
		inline Vector5i32(const Vector5i32& other) noexcept;
		inline Vector5i32& operator=(const Vector5i32& other) noexcept;
		// move
		inline Vector5i32(Vector5i32&& other) noexcept;
		inline Vector5i32& operator=(Vector5i32&& other) noexcept;
		// assignment
		inline Vector5i32& operator=(const std::int32_t& number) noexcept;
		 
		// math operator
		inline Vector5i32 operator +(const Vector5i32& v) const noexcept;
		inline Vector5i32 operator -(const Vector5i32& v) const noexcept;
		inline Vector5i32 operator *(const Vector5i32& v) const noexcept;
		inline Vector5i32 operator /(const Vector5i32& v) const noexcept;
		
		inline Vector5i32 operator +(const std::int32_t& number) const noexcept;
		inline Vector5i32 operator -(const std::int32_t& number) const noexcept;
		inline Vector5i32 operator *(const std::int32_t& number) const noexcept;
		inline Vector5i32 operator /(const std::int32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector5i32& operator++ () noexcept;		// prefix increment
		inline Vector5i32& operator-- () noexcept;		// prefix decrement
		inline Vector5i32  operator++ (int) noexcept;		// postfix increment
		inline Vector5i32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5i32& operator+= (const Vector5i32& right) noexcept;
		inline Vector5i32& operator-= (const Vector5i32& right) noexcept;
		inline Vector5i32& operator*= (const Vector5i32& right) noexcept;
		inline Vector5i32& operator/= (const Vector5i32& right) noexcept;
		
		inline Vector5i32& operator+= (const std::int32_t& number) noexcept;
		inline Vector5i32& operator-= (const std::int32_t& number) noexcept;
		inline Vector5i32& operator*= (const std::int32_t& number) noexcept;
		inline Vector5i32& operator/= (const std::int32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5i32& other) const noexcept;
		inline bool operator<=  (const Vector5i32& other) const noexcept;
		inline bool operator>	(const Vector5i32& other) const noexcept;
		inline bool operator>=  (const Vector5i32& other) const noexcept;
		
		inline bool operator<	(const std::int32_t& number) const noexcept;
		inline bool operator<=  (const std::int32_t& number) const noexcept;
		inline bool operator>	(const std::int32_t& number) const noexcept;
		inline bool operator>=  (const std::int32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5i32& other) const noexcept;
		inline bool operator!=(const Vector5i32& other) const noexcept;
		inline bool operator==(const std::int32_t& number)  const noexcept;
		inline bool operator!=(const std::int32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int32_t& stnd_value = 0) noexcept;
		inline std::int32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector6i32
	{
	public:
		std::int32_t a, b, c, d, e, f;
	public:
		inline Vector6i32(const std::int32_t& a = 0, const std::int32_t& b = 0, const std::int32_t& c = 0, const std::int32_t& d = 0,
			const std::int32_t& e = 0, const std::int32_t& f = 0) noexcept;
		// copy
		inline Vector6i32(const Vector6i32& other) noexcept;
		inline Vector6i32& operator=(const Vector6i32& other) noexcept;
		// move
		inline Vector6i32(Vector6i32&& other) noexcept;
		inline Vector6i32& operator=(Vector6i32&& other) noexcept;
		// assignment
		inline Vector6i32& operator=(const std::int32_t& number) noexcept;
		
		// math operator
		inline Vector6i32 operator +(const Vector6i32& v) const noexcept;
		inline Vector6i32 operator -(const Vector6i32& v) const noexcept;
		inline Vector6i32 operator *(const Vector6i32& v) const noexcept;
		inline Vector6i32 operator /(const Vector6i32& v) const noexcept;
		
		inline Vector6i32 operator +(const std::int32_t& number) const noexcept;
		inline Vector6i32 operator -(const std::int32_t& number) const noexcept;
		inline Vector6i32 operator *(const std::int32_t& number) const noexcept;
		inline Vector6i32 operator /(const std::int32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector6i32& operator++ () noexcept;		// prefix increment
		inline Vector6i32& operator-- () noexcept;		// prefix decrement
		inline Vector6i32  operator++ (int) noexcept;		// postfix increment
		inline Vector6i32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6i32& operator+= (const Vector6i32& right) noexcept;
		inline Vector6i32& operator-= (const Vector6i32& right) noexcept;
		inline Vector6i32& operator*= (const Vector6i32& right) noexcept;
		inline Vector6i32& operator/= (const Vector6i32& right) noexcept;
		
		inline Vector6i32& operator+= (const std::int32_t& number) noexcept;
		inline Vector6i32& operator-= (const std::int32_t& number) noexcept;
		inline Vector6i32& operator*= (const std::int32_t& number) noexcept;
		inline Vector6i32& operator/= (const std::int32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6i32& other) const noexcept;
		inline bool operator<  (const Vector6i32& other) const noexcept;
		inline bool operator>  (const Vector6i32& other) const noexcept;
		inline bool operator>= (const Vector6i32& other) const noexcept;
		
		inline bool operator<  (const std::int32_t& number) const noexcept;
		inline bool operator<= (const std::int32_t& number) const noexcept;
		inline bool operator>  (const std::int32_t& number) const noexcept;
		inline bool operator>= (const std::int32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6i32& other) const noexcept;
		inline bool operator!=(const Vector6i32& other) const noexcept;
		inline bool operator==(const std::int32_t& number)  const noexcept;
		inline bool operator!=(const std::int32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int32_t& stnd_value = 0) noexcept;
		inline std::int32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector7i32
	{
	public:
		std::int32_t a, b, c, d, e, f, g;
	public:
		inline Vector7i32(const std::int32_t& a = 0, const std::int32_t& b = 0, const std::int32_t& c = 0, const std::int32_t& d = 0,
			const std::int32_t& e = 0, const std::int32_t& f = 0, const std::int32_t& g = 0) noexcept;
		// copy
		inline Vector7i32(const Vector7i32& other) noexcept;
		inline Vector7i32& operator=(const Vector7i32& other) noexcept;
		// move
		inline Vector7i32(Vector7i32&& other) noexcept;
		inline Vector7i32& operator=(Vector7i32&& other) noexcept;
		// assignment
		inline Vector7i32& operator=(const std::int32_t& number) noexcept;
		
		// math operator
		inline Vector7i32 operator +(const Vector7i32& v) const noexcept;
		inline Vector7i32 operator -(const Vector7i32& v) const noexcept;
		inline Vector7i32 operator *(const Vector7i32& v) const noexcept;
		inline Vector7i32 operator /(const Vector7i32& v) const noexcept;
		
		inline Vector7i32 operator +(const std::int32_t& number) const noexcept;
		inline Vector7i32 operator -(const std::int32_t& number) const noexcept;
		inline Vector7i32 operator *(const std::int32_t& number) const noexcept;
		inline Vector7i32 operator /(const std::int32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector7i32& operator++ () noexcept;		// prefix increment
		inline Vector7i32& operator-- () noexcept;		// prefix decrement
		inline Vector7i32  operator++ (int) noexcept;		// postfix increment
		inline Vector7i32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7i32& operator+= (const Vector7i32& right) noexcept;
		inline Vector7i32& operator-= (const Vector7i32& right) noexcept;
		inline Vector7i32& operator*= (const Vector7i32& right) noexcept;
		inline Vector7i32& operator/= (const Vector7i32& right) noexcept;
		
		inline Vector7i32& operator+= (const std::int32_t& number) noexcept;
		inline Vector7i32& operator-= (const std::int32_t& number) noexcept;
		inline Vector7i32& operator*= (const std::int32_t& number) noexcept;
		inline Vector7i32& operator/= (const std::int32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7i32& other) const noexcept;
		inline bool operator<  (const Vector7i32& other) const noexcept;
		inline bool operator>  (const Vector7i32& other) const noexcept;
		inline bool operator>= (const Vector7i32& other) const noexcept;
		
		inline bool operator<  (const std::int32_t& number) const noexcept;
		inline bool operator<= (const std::int32_t& number) const noexcept;
		inline bool operator>  (const std::int32_t& number) const noexcept;
		inline bool operator>= (const std::int32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7i32& other) const noexcept;
		inline bool operator!=(const Vector7i32& other) const noexcept;
		inline bool operator==(const std::int32_t& number)  const noexcept;
		inline bool operator!=(const std::int32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int32_t& stnd_value = 0) noexcept;
		inline std::int32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector8i32
	{
	public:
		std::int32_t a, b, c, d, e, f, g, h;
	public:
		inline Vector8i32(const std::int32_t& a = 0, const std::int32_t& b = 0, const std::int32_t& c = 0, const std::int32_t& d = 0,
			const std::int32_t& e = 0, const std::int32_t& f = 0, const std::int32_t& g = 0, const std::int32_t& h = 0) noexcept;
		// copy
		inline Vector8i32(const Vector8i32& other) noexcept;
		inline Vector8i32& operator=(const Vector8i32& other) noexcept;
		// move
		inline Vector8i32(Vector8i32&& other) noexcept;
		inline Vector8i32& operator=(Vector8i32&& other) noexcept;
		// assignment
		inline Vector8i32& operator=(const std::int32_t& number) noexcept;
		
		// math operator
		inline Vector8i32 operator +(const Vector8i32& v) const noexcept;
		inline Vector8i32 operator -(const Vector8i32& v) const noexcept;
		inline Vector8i32 operator *(const Vector8i32& v) const noexcept;
		inline Vector8i32 operator /(const Vector8i32& v) const noexcept;
		
		inline Vector8i32 operator +(const std::int32_t& number) const noexcept;
		inline Vector8i32 operator -(const std::int32_t& number) const noexcept;
		inline Vector8i32 operator *(const std::int32_t& number) const noexcept;
		inline Vector8i32 operator /(const std::int32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector8i32& operator++ () noexcept;		// prefix increment
		inline Vector8i32& operator-- () noexcept;		// prefix decrement
		inline Vector8i32  operator++ (int) noexcept;		// postfix increment
		inline Vector8i32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8i32& operator+= (const Vector8i32& right) noexcept;
		inline Vector8i32& operator-= (const Vector8i32& right) noexcept;
		inline Vector8i32& operator*= (const Vector8i32& right) noexcept;
		inline Vector8i32& operator/= (const Vector8i32& right) noexcept;
		
		inline Vector8i32& operator+= (const std::int32_t& number) noexcept;
		inline Vector8i32& operator-= (const std::int32_t& number) noexcept;
		inline Vector8i32& operator*= (const std::int32_t& number) noexcept;
		inline Vector8i32& operator/= (const std::int32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8i32& other) const noexcept;
		inline bool operator<  (const Vector8i32& other) const noexcept;
		inline bool operator>  (const Vector8i32& other) const noexcept;
		inline bool operator>= (const Vector8i32& other) const noexcept;
		
		inline bool operator<  (const std::int32_t& number) const noexcept;
		inline bool operator<= (const std::int32_t& number) const noexcept;
		inline bool operator>  (const std::int32_t& number) const noexcept;
		inline bool operator>= (const std::int32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8i32& other) const noexcept;
		inline bool operator!=(const Vector8i32& other) const noexcept;
		inline bool operator==(const std::int32_t& number)  const noexcept;
		inline bool operator!=(const std::int32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int32_t& stnd_value = 0) noexcept;
		inline std::int32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector9i32
	{
	public:
		std::int32_t a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9i32(const std::int32_t& a = 0, const std::int32_t& b = 0, const std::int32_t& c = 0, const std::int32_t& d = 0,
			const std::int32_t& e = 0, const std::int32_t& f = 0, const std::int32_t& g = 0, const std::int32_t& h = 0,
			const std::int32_t& i = 0) noexcept;
		// copy
		inline Vector9i32(const Vector9i32& other) noexcept;
		inline Vector9i32& operator=(const Vector9i32& other) noexcept;
		// move
		inline Vector9i32(Vector9i32&& other) noexcept;
		inline Vector9i32& operator=(Vector9i32&& other) noexcept;
		// assignment
		inline Vector9i32& operator=(const std::int32_t& number) noexcept;
		
		// math operator
		inline Vector9i32 operator +(const Vector9i32& v) const noexcept;
		inline Vector9i32 operator -(const Vector9i32& v) const noexcept;
		inline Vector9i32 operator *(const Vector9i32& v) const noexcept;
		inline Vector9i32 operator /(const Vector9i32& v) const noexcept;
		
		inline Vector9i32 operator +(const std::int32_t& number) const noexcept;
		inline Vector9i32 operator -(const std::int32_t& number) const noexcept;
		inline Vector9i32 operator *(const std::int32_t& number) const noexcept;
		inline Vector9i32 operator /(const std::int32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector9i32& operator++ () noexcept;		// prefix increment
		inline Vector9i32& operator-- () noexcept;		// prefix decrement
		inline Vector9i32  operator++ (int) noexcept;		// postfix increment
		inline Vector9i32  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9i32& operator+= (const Vector9i32& right) noexcept;
		inline Vector9i32& operator-= (const Vector9i32& right) noexcept;
		inline Vector9i32& operator*= (const Vector9i32& right) noexcept;
		inline Vector9i32& operator/= (const Vector9i32& right) noexcept;
		
		inline Vector9i32& operator+= (const std::int32_t& number) noexcept;
		inline Vector9i32& operator-= (const std::int32_t& number) noexcept;
		inline Vector9i32& operator*= (const std::int32_t& number) noexcept;
		inline Vector9i32& operator/= (const std::int32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9i32& other) const noexcept;
		inline bool operator<  (const Vector9i32& other) const noexcept;
		inline bool operator>  (const Vector9i32& other) const noexcept;
		inline bool operator>= (const Vector9i32& other) const noexcept;
		
		inline bool operator<  (const std::int32_t& number) const noexcept;
		inline bool operator<= (const std::int32_t& number) const noexcept;
		inline bool operator>  (const std::int32_t& number) const noexcept;
		inline bool operator>= (const std::int32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9i32& other) const noexcept;
		inline bool operator!=(const Vector9i32& other) const noexcept;
		inline bool operator==(const std::int32_t& number)  const noexcept;
		inline bool operator!=(const std::int32_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int32_t& stnd_value = 0) noexcept;
		inline std::int32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int32_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector10i32
	{
	public:
		std::int32_t a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10i32(const std::int32_t& a = 0, const std::int32_t& b = 0, const std::int32_t& c = 0, const std::int32_t& d = 0,
			const std::int32_t& e = 0, const std::int32_t& f = 0, const std::int32_t& g = 0, const std::int32_t& h = 0,
			const std::int32_t& i = 0, const std::int32_t& j = 0) noexcept;
		// copy
		inline Vector10i32(const Vector10i32& other) noexcept;
		inline Vector10i32& operator=(const Vector10i32& other) noexcept;
		// move
		inline Vector10i32(Vector10i32&& other) noexcept;
		inline Vector10i32& operator=(Vector10i32&& other) noexcept;
		// assignment
		inline Vector10i32& operator=(const std::int32_t& number) noexcept;
		
		// math operator
		inline Vector10i32 operator +(const Vector10i32& v) const noexcept;
		inline Vector10i32 operator -(const Vector10i32& v) const noexcept;
		inline Vector10i32 operator *(const Vector10i32& v) const noexcept;
		inline Vector10i32 operator /(const Vector10i32& v) const noexcept;
		
		inline Vector10i32 operator +(const std::int32_t& number) const noexcept;
		inline Vector10i32 operator -(const std::int32_t& number) const noexcept;
		inline Vector10i32 operator *(const std::int32_t& number) const noexcept;
		inline Vector10i32 operator /(const std::int32_t& number) const noexcept;
		
		// increment / decrement
		inline Vector10i32& operator++ () noexcept;		// prefix increment
		inline Vector10i32& operator-- () noexcept;		// prefix decrement
		inline Vector10i32  operator++ (int) noexcept;	// postfix increment
		inline Vector10i32  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10i32& operator+= (const Vector10i32& right) noexcept;
		inline Vector10i32& operator-= (const Vector10i32& right) noexcept;
		inline Vector10i32& operator*= (const Vector10i32& right) noexcept;
		inline Vector10i32& operator/= (const Vector10i32& right) noexcept;
		
		inline Vector10i32& operator+= (const std::int32_t& number) noexcept;
		inline Vector10i32& operator-= (const std::int32_t& number) noexcept;
		inline Vector10i32& operator*= (const std::int32_t& number) noexcept;
		inline Vector10i32& operator/= (const std::int32_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10i32& other) const noexcept;
		inline bool operator<  (const Vector10i32& other) const noexcept;
		inline bool operator>  (const Vector10i32& other) const noexcept;
		inline bool operator>= (const Vector10i32& other) const noexcept;

		inline bool operator<  (const std::int32_t& number) const noexcept;
		inline bool operator<= (const std::int32_t& number) const noexcept;
		inline bool operator>  (const std::int32_t& number) const noexcept;
		inline bool operator>= (const std::int32_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10i32& other) const noexcept;
		inline bool operator!=(const Vector10i32& other) const noexcept;
		inline bool operator==(const std::int32_t& number)   const noexcept;
		inline bool operator!=(const std::int32_t& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int32_t& stnd_value = 0) noexcept;
		inline std::int32_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int32_t& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2i32& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3i32& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4i32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5i32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6i32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7i32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8i32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9i32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10i32& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}