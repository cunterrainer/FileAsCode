#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::int64_t
		Bytes: 8
		Range: -9.223.372.036.854.775.808 to 9.223.372.036.854.775.807
	*/

	class Vector2i64
	{
	public:
		std::int64_t x, y;
	public:
		inline Vector2i64(const std::int64_t& x = 0ll, const std::int64_t& y = 0ll) noexcept;
		// copy
		inline Vector2i64(const Vector2i64& other) noexcept;
		inline Vector2i64& operator=(const Vector2i64& other) noexcept;
		// move
		inline Vector2i64(Vector2i64&& other) noexcept;
		inline Vector2i64& operator=(Vector2i64&& other) noexcept;
		// assignment
		inline Vector2i64& operator=(const std::int64_t& number) noexcept;

		// math operator
		inline Vector2i64 operator +(const Vector2i64& v) const noexcept;
		inline Vector2i64 operator -(const Vector2i64& v) const noexcept;
		inline Vector2i64 operator *(const Vector2i64& v) const noexcept;
		inline Vector2i64 operator /(const Vector2i64& v) const noexcept;

		inline Vector2i64 operator +(const std::int64_t& number) const noexcept;
		inline Vector2i64 operator -(const std::int64_t& number) const noexcept;
		inline Vector2i64 operator *(const std::int64_t& number) const noexcept;
		inline Vector2i64 operator /(const std::int64_t& number) const noexcept;

		// increment / decrement
		inline Vector2i64& operator++ () noexcept;		// prefix increment
		inline Vector2i64& operator-- () noexcept;		// prefix decrement
		inline Vector2i64  operator++ (int) noexcept;		// postfix increment
		inline Vector2i64  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2i64& operator+= (const Vector2i64& right) noexcept;
		inline Vector2i64& operator-= (const Vector2i64& right) noexcept;
		inline Vector2i64& operator*= (const Vector2i64& right) noexcept;
		inline Vector2i64& operator/= (const Vector2i64& right) noexcept;

		inline Vector2i64& operator+= (const std::int64_t& number) noexcept;
		inline Vector2i64& operator-= (const std::int64_t& number) noexcept;
		inline Vector2i64& operator*= (const std::int64_t& number) noexcept;
		inline Vector2i64& operator/= (const std::int64_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2i64& other) const noexcept;
		inline bool operator<=  (const Vector2i64& other) const noexcept;
		inline bool operator>	(const Vector2i64& other) const noexcept;
		inline bool operator>=  (const Vector2i64& other) const noexcept;

		inline bool operator<	(const std::int64_t& number) const noexcept;
		inline bool operator<=  (const std::int64_t& number) const noexcept;
		inline bool operator>	(const std::int64_t& number) const noexcept;
		inline bool operator>=  (const std::int64_t& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2i64& other) const noexcept;
		inline bool operator!=(const Vector2i64& other) const noexcept;
		inline bool operator==(const std::int64_t& number)  const noexcept;
		inline bool operator!=(const std::int64_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int64_t& stnd_value = 0ll) noexcept;
		inline std::int64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector3i64
	{
	public:
		std::int64_t x, y, z;
	public:
		inline Vector3i64(const std::int64_t& x = 0ll, const std::int64_t& y = 0ll, const std::int64_t& z = 0ll) noexcept;
		// copy
		inline Vector3i64(const Vector3i64& other) noexcept;
		inline Vector3i64& operator=(const Vector3i64& other) noexcept;
		// move
		inline Vector3i64(Vector3i64&& other) noexcept;
		inline Vector3i64& operator=(Vector3i64&& other) noexcept;
		// assignment
		inline Vector3i64& operator=(const std::int64_t& number) noexcept;

		// math operator
		inline Vector3i64 operator +(const Vector3i64& v) const noexcept;
		inline Vector3i64 operator -(const Vector3i64& v) const noexcept;
		inline Vector3i64 operator *(const Vector3i64& v) const noexcept;
		inline Vector3i64 operator /(const Vector3i64& v) const noexcept;

		inline Vector3i64 operator +(const std::int64_t& number) const noexcept;
		inline Vector3i64 operator -(const std::int64_t& number) const noexcept;
		inline Vector3i64 operator *(const std::int64_t& number) const noexcept;
		inline Vector3i64 operator /(const std::int64_t& number) const noexcept;

		// increment / decrement
		inline Vector3i64& operator++ () noexcept;		// prefix increment
		inline Vector3i64& operator-- () noexcept;		// prefix decrement
		inline Vector3i64  operator++ (int) noexcept;		// postfix increment
		inline Vector3i64  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3i64& operator+= (const Vector3i64& right) noexcept;
		inline Vector3i64& operator-= (const Vector3i64& right) noexcept;
		inline Vector3i64& operator*= (const Vector3i64& right) noexcept;
		inline Vector3i64& operator/= (const Vector3i64& right) noexcept;

		inline Vector3i64& operator+= (const std::int64_t& number) noexcept;
		inline Vector3i64& operator-= (const std::int64_t& number) noexcept;
		inline Vector3i64& operator*= (const std::int64_t& number) noexcept;
		inline Vector3i64& operator/= (const std::int64_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3i64& other) const noexcept;
		inline bool operator<=  (const Vector3i64& other) const noexcept;
		inline bool operator>	(const Vector3i64& other) const noexcept;
		inline bool operator>=  (const Vector3i64& other) const noexcept;
		 
		inline bool operator<	(const std::int64_t& number) const noexcept;
		inline bool operator<=  (const std::int64_t& number) const noexcept;
		inline bool operator>	(const std::int64_t& number) const noexcept;
		inline bool operator>=  (const std::int64_t& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3i64& other) const noexcept;
		inline bool operator!=(const Vector3i64& other) const noexcept;
		inline bool operator==(const std::int64_t& number)  const noexcept;
		inline bool operator!=(const std::int64_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int64_t& stnd_value = 0ll) noexcept;
		inline std::int64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector4i64
	{
	public:
		std::int64_t a, b, c, d;
	public:
		inline Vector4i64(const std::int64_t& a = 0ll, const std::int64_t& b = 0ll, const std::int64_t& c = 0ll, const std::int64_t& d = 0ll) noexcept;
		// copy
		inline Vector4i64(const Vector4i64& other) noexcept;
		inline Vector4i64& operator=(const Vector4i64& other) noexcept;
		// move
		inline Vector4i64(Vector4i64&& other) noexcept;
		inline Vector4i64& operator=(Vector4i64&& other) noexcept;
		// assignment
		inline Vector4i64& operator=(const std::int64_t& number) noexcept;
		
		// math operator
		inline Vector4i64 operator +(const Vector4i64& v) const noexcept;
		inline Vector4i64 operator -(const Vector4i64& v) const noexcept;
		inline Vector4i64 operator *(const Vector4i64& v) const noexcept;
		inline Vector4i64 operator /(const Vector4i64& v) const noexcept;
		
		inline Vector4i64 operator +(const std::int64_t& number) const noexcept;
		inline Vector4i64 operator -(const std::int64_t& number) const noexcept;
		inline Vector4i64 operator *(const std::int64_t& number) const noexcept;
		inline Vector4i64 operator /(const std::int64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector4i64& operator++ () noexcept;		// prefix increment
		inline Vector4i64& operator-- () noexcept;		// prefix decrement
		inline Vector4i64  operator++ (int) noexcept;		// postfix increment
		inline Vector4i64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4i64& operator+= (const Vector4i64& right) noexcept;
		inline Vector4i64& operator-= (const Vector4i64& right) noexcept;
		inline Vector4i64& operator*= (const Vector4i64& right) noexcept;
		inline Vector4i64& operator/= (const Vector4i64& right) noexcept;
		
		inline Vector4i64& operator+= (const std::int64_t& number) noexcept;
		inline Vector4i64& operator-= (const std::int64_t& number) noexcept;
		inline Vector4i64& operator*= (const std::int64_t& number) noexcept;
		inline Vector4i64& operator/= (const std::int64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4i64& other) const noexcept;
		inline bool operator<=  (const Vector4i64& other) const noexcept;
		inline bool operator>	(const Vector4i64& other) const noexcept;
		inline bool operator>=  (const Vector4i64& other) const noexcept;
		
		inline bool operator<	(const std::int64_t& number) const noexcept;
		inline bool operator<=  (const std::int64_t& number) const noexcept;
		inline bool operator>	(const std::int64_t& number) const noexcept;
		inline bool operator>=  (const std::int64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4i64& other) const noexcept;
		inline bool operator!=(const Vector4i64& other) const noexcept;
		inline bool operator==(const std::int64_t& number)  const noexcept;
		inline bool operator!=(const std::int64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int64_t& stnd_value = 0ll) noexcept;
		inline std::int64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector5i64
	{
	public:
		std::int64_t a, b, c, d, e;
	public:
		inline Vector5i64(const std::int64_t& a = 0ll, const std::int64_t& b = 0ll, const std::int64_t& c = 0ll, const std::int64_t& d = 0ll,
			const std::int64_t& e = 0ll) noexcept;
		// copy
		inline Vector5i64(const Vector5i64& other) noexcept;
		inline Vector5i64& operator=(const Vector5i64& other) noexcept;
		// move
		inline Vector5i64(Vector5i64&& other) noexcept;
		inline Vector5i64& operator=(Vector5i64&& other) noexcept;
		// assignment
		inline Vector5i64& operator=(const std::int64_t& number) noexcept;
		 
		// math operator
		inline Vector5i64 operator +(const Vector5i64& v) const noexcept;
		inline Vector5i64 operator -(const Vector5i64& v) const noexcept;
		inline Vector5i64 operator *(const Vector5i64& v) const noexcept;
		inline Vector5i64 operator /(const Vector5i64& v) const noexcept;
		
		inline Vector5i64 operator +(const std::int64_t& number) const noexcept;
		inline Vector5i64 operator -(const std::int64_t& number) const noexcept;
		inline Vector5i64 operator *(const std::int64_t& number) const noexcept;
		inline Vector5i64 operator /(const std::int64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector5i64& operator++ () noexcept;		// prefix increment
		inline Vector5i64& operator-- () noexcept;		// prefix decrement
		inline Vector5i64  operator++ (int) noexcept;		// postfix increment
		inline Vector5i64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5i64& operator+= (const Vector5i64& right) noexcept;
		inline Vector5i64& operator-= (const Vector5i64& right) noexcept;
		inline Vector5i64& operator*= (const Vector5i64& right) noexcept;
		inline Vector5i64& operator/= (const Vector5i64& right) noexcept;
		
		inline Vector5i64& operator+= (const std::int64_t& number) noexcept;
		inline Vector5i64& operator-= (const std::int64_t& number) noexcept;
		inline Vector5i64& operator*= (const std::int64_t& number) noexcept;
		inline Vector5i64& operator/= (const std::int64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5i64& other) const noexcept;
		inline bool operator<=  (const Vector5i64& other) const noexcept;
		inline bool operator>	(const Vector5i64& other) const noexcept;
		inline bool operator>=  (const Vector5i64& other) const noexcept;
		
		inline bool operator<	(const std::int64_t& number) const noexcept;
		inline bool operator<=  (const std::int64_t& number) const noexcept;
		inline bool operator>	(const std::int64_t& number) const noexcept;
		inline bool operator>=  (const std::int64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5i64& other) const noexcept;
		inline bool operator!=(const Vector5i64& other) const noexcept;
		inline bool operator==(const std::int64_t& number)  const noexcept;
		inline bool operator!=(const std::int64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int64_t& stnd_value = 0ll) noexcept;
		inline std::int64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector6i64
	{
	public:
		std::int64_t a, b, c, d, e, f;
	public:
		inline Vector6i64(const std::int64_t& a = 0ll, const std::int64_t& b = 0ll, const std::int64_t& c = 0ll, const std::int64_t& d = 0ll,
			const std::int64_t& e = 0ll, const std::int64_t& f = 0ll) noexcept;
		// copy
		inline Vector6i64(const Vector6i64& other) noexcept;
		inline Vector6i64& operator=(const Vector6i64& other) noexcept;
		// move
		inline Vector6i64(Vector6i64&& other) noexcept;
		inline Vector6i64& operator=(Vector6i64&& other) noexcept;
		// assignment
		inline Vector6i64& operator=(const std::int64_t& number) noexcept;
		
		// math operator
		inline Vector6i64 operator +(const Vector6i64& v) const noexcept;
		inline Vector6i64 operator -(const Vector6i64& v) const noexcept;
		inline Vector6i64 operator *(const Vector6i64& v) const noexcept;
		inline Vector6i64 operator /(const Vector6i64& v) const noexcept;
		
		inline Vector6i64 operator +(const std::int64_t& number) const noexcept;
		inline Vector6i64 operator -(const std::int64_t& number) const noexcept;
		inline Vector6i64 operator *(const std::int64_t& number) const noexcept;
		inline Vector6i64 operator /(const std::int64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector6i64& operator++ () noexcept;		// prefix increment
		inline Vector6i64& operator-- () noexcept;		// prefix decrement
		inline Vector6i64  operator++ (int) noexcept;		// postfix increment
		inline Vector6i64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6i64& operator+= (const Vector6i64& right) noexcept;
		inline Vector6i64& operator-= (const Vector6i64& right) noexcept;
		inline Vector6i64& operator*= (const Vector6i64& right) noexcept;
		inline Vector6i64& operator/= (const Vector6i64& right) noexcept;
		
		inline Vector6i64& operator+= (const std::int64_t& number) noexcept;
		inline Vector6i64& operator-= (const std::int64_t& number) noexcept;
		inline Vector6i64& operator*= (const std::int64_t& number) noexcept;
		inline Vector6i64& operator/= (const std::int64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6i64& other) const noexcept;
		inline bool operator<  (const Vector6i64& other) const noexcept;
		inline bool operator>  (const Vector6i64& other) const noexcept;
		inline bool operator>= (const Vector6i64& other) const noexcept;
		
		inline bool operator<  (const std::int64_t& number) const noexcept;
		inline bool operator<= (const std::int64_t& number) const noexcept;
		inline bool operator>  (const std::int64_t& number) const noexcept;
		inline bool operator>= (const std::int64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6i64& other) const noexcept;
		inline bool operator!=(const Vector6i64& other) const noexcept;
		inline bool operator==(const std::int64_t& number)  const noexcept;
		inline bool operator!=(const std::int64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int64_t& stnd_value = 0ll) noexcept;
		inline std::int64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector7i64
	{
	public:
		std::int64_t a, b, c, d, e, f, g;
	public:
		inline Vector7i64(const std::int64_t& a = 0ll, const std::int64_t& b = 0ll, const std::int64_t& c = 0ll, const std::int64_t& d = 0ll,
			const std::int64_t& e = 0ll, const std::int64_t& f = 0ll, const std::int64_t& g = 0ll) noexcept;
		// copy
		inline Vector7i64(const Vector7i64& other) noexcept;
		inline Vector7i64& operator=(const Vector7i64& other) noexcept;
		// move
		inline Vector7i64(Vector7i64&& other) noexcept;
		inline Vector7i64& operator=(Vector7i64&& other) noexcept;
		// assignment
		inline Vector7i64& operator=(const std::int64_t& number) noexcept;
		
		// math operator
		inline Vector7i64 operator +(const Vector7i64& v) const noexcept;
		inline Vector7i64 operator -(const Vector7i64& v) const noexcept;
		inline Vector7i64 operator *(const Vector7i64& v) const noexcept;
		inline Vector7i64 operator /(const Vector7i64& v) const noexcept;
		
		inline Vector7i64 operator +(const std::int64_t& number) const noexcept;
		inline Vector7i64 operator -(const std::int64_t& number) const noexcept;
		inline Vector7i64 operator *(const std::int64_t& number) const noexcept;
		inline Vector7i64 operator /(const std::int64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector7i64& operator++ () noexcept;		// prefix increment
		inline Vector7i64& operator-- () noexcept;		// prefix decrement
		inline Vector7i64  operator++ (int) noexcept;		// postfix increment
		inline Vector7i64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7i64& operator+= (const Vector7i64& right) noexcept;
		inline Vector7i64& operator-= (const Vector7i64& right) noexcept;
		inline Vector7i64& operator*= (const Vector7i64& right) noexcept;
		inline Vector7i64& operator/= (const Vector7i64& right) noexcept;
		
		inline Vector7i64& operator+= (const std::int64_t& number) noexcept;
		inline Vector7i64& operator-= (const std::int64_t& number) noexcept;
		inline Vector7i64& operator*= (const std::int64_t& number) noexcept;
		inline Vector7i64& operator/= (const std::int64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7i64& other) const noexcept;
		inline bool operator<  (const Vector7i64& other) const noexcept;
		inline bool operator>  (const Vector7i64& other) const noexcept;
		inline bool operator>= (const Vector7i64& other) const noexcept;
		
		inline bool operator<  (const std::int64_t& number) const noexcept;
		inline bool operator<= (const std::int64_t& number) const noexcept;
		inline bool operator>  (const std::int64_t& number) const noexcept;
		inline bool operator>= (const std::int64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7i64& other) const noexcept;
		inline bool operator!=(const Vector7i64& other) const noexcept;
		inline bool operator==(const std::int64_t& number)  const noexcept;
		inline bool operator!=(const std::int64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int64_t& stnd_value = 0ll) noexcept;
		inline std::int64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector8i64
	{
	public:
		std::int64_t a, b, c, d, e, f, g, h;
	public:
		inline Vector8i64(const std::int64_t& a = 0ll, const std::int64_t& b = 0ll, const std::int64_t& c = 0ll, const std::int64_t& d = 0ll,
			const std::int64_t& e = 0ll, const std::int64_t& f = 0ll, const std::int64_t& g = 0ll, const std::int64_t& h = 0ll) noexcept;
		// copy
		inline Vector8i64(const Vector8i64& other) noexcept;
		inline Vector8i64& operator=(const Vector8i64& other) noexcept;
		// move
		inline Vector8i64(Vector8i64&& other) noexcept;
		inline Vector8i64& operator=(Vector8i64&& other) noexcept;
		// assignment
		inline Vector8i64& operator=(const std::int64_t& number) noexcept;
		
		// math operator
		inline Vector8i64 operator +(const Vector8i64& v) const noexcept;
		inline Vector8i64 operator -(const Vector8i64& v) const noexcept;
		inline Vector8i64 operator *(const Vector8i64& v) const noexcept;
		inline Vector8i64 operator /(const Vector8i64& v) const noexcept;
		
		inline Vector8i64 operator +(const std::int64_t& number) const noexcept;
		inline Vector8i64 operator -(const std::int64_t& number) const noexcept;
		inline Vector8i64 operator *(const std::int64_t& number) const noexcept;
		inline Vector8i64 operator /(const std::int64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector8i64& operator++ () noexcept;		// prefix increment
		inline Vector8i64& operator-- () noexcept;		// prefix decrement
		inline Vector8i64  operator++ (int) noexcept;		// postfix increment
		inline Vector8i64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8i64& operator+= (const Vector8i64& right) noexcept;
		inline Vector8i64& operator-= (const Vector8i64& right) noexcept;
		inline Vector8i64& operator*= (const Vector8i64& right) noexcept;
		inline Vector8i64& operator/= (const Vector8i64& right) noexcept;
		
		inline Vector8i64& operator+= (const std::int64_t& number) noexcept;
		inline Vector8i64& operator-= (const std::int64_t& number) noexcept;
		inline Vector8i64& operator*= (const std::int64_t& number) noexcept;
		inline Vector8i64& operator/= (const std::int64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8i64& other) const noexcept;
		inline bool operator<  (const Vector8i64& other) const noexcept;
		inline bool operator>  (const Vector8i64& other) const noexcept;
		inline bool operator>= (const Vector8i64& other) const noexcept;
		
		inline bool operator<  (const std::int64_t& number) const noexcept;
		inline bool operator<= (const std::int64_t& number) const noexcept;
		inline bool operator>  (const std::int64_t& number) const noexcept;
		inline bool operator>= (const std::int64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8i64& other) const noexcept;
		inline bool operator!=(const Vector8i64& other) const noexcept;
		inline bool operator==(const std::int64_t& number)  const noexcept;
		inline bool operator!=(const std::int64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int64_t& stnd_value = 0ll) noexcept;
		inline std::int64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector9i64
	{
	public:
		std::int64_t a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9i64(const std::int64_t& a = 0ll, const std::int64_t& b = 0ll, const std::int64_t& c = 0ll, const std::int64_t& d = 0ll,
			const std::int64_t& e = 0ll, const std::int64_t& f = 0ll, const std::int64_t& g = 0ll, const std::int64_t& h = 0ll,
			const std::int64_t& i = 0ll) noexcept;
		// copy
		inline Vector9i64(const Vector9i64& other) noexcept;
		inline Vector9i64& operator=(const Vector9i64& other) noexcept;
		// move
		inline Vector9i64(Vector9i64&& other) noexcept;
		inline Vector9i64& operator=(Vector9i64&& other) noexcept;
		// assignment
		inline Vector9i64& operator=(const std::int64_t& number) noexcept;
		
		// math operator
		inline Vector9i64 operator +(const Vector9i64& v) const noexcept;
		inline Vector9i64 operator -(const Vector9i64& v) const noexcept;
		inline Vector9i64 operator *(const Vector9i64& v) const noexcept;
		inline Vector9i64 operator /(const Vector9i64& v) const noexcept;
		
		inline Vector9i64 operator +(const std::int64_t& number) const noexcept;
		inline Vector9i64 operator -(const std::int64_t& number) const noexcept;
		inline Vector9i64 operator *(const std::int64_t& number) const noexcept;
		inline Vector9i64 operator /(const std::int64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector9i64& operator++ () noexcept;		// prefix increment
		inline Vector9i64& operator-- () noexcept;		// prefix decrement
		inline Vector9i64  operator++ (int) noexcept;		// postfix increment
		inline Vector9i64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9i64& operator+= (const Vector9i64& right) noexcept;
		inline Vector9i64& operator-= (const Vector9i64& right) noexcept;
		inline Vector9i64& operator*= (const Vector9i64& right) noexcept;
		inline Vector9i64& operator/= (const Vector9i64& right) noexcept;
		
		inline Vector9i64& operator+= (const std::int64_t& number) noexcept;
		inline Vector9i64& operator-= (const std::int64_t& number) noexcept;
		inline Vector9i64& operator*= (const std::int64_t& number) noexcept;
		inline Vector9i64& operator/= (const std::int64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9i64& other) const noexcept;
		inline bool operator<  (const Vector9i64& other) const noexcept;
		inline bool operator>  (const Vector9i64& other) const noexcept;
		inline bool operator>= (const Vector9i64& other) const noexcept;
		
		inline bool operator<  (const std::int64_t& number) const noexcept;
		inline bool operator<= (const std::int64_t& number) const noexcept;
		inline bool operator>  (const std::int64_t& number) const noexcept;
		inline bool operator>= (const std::int64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9i64& other) const noexcept;
		inline bool operator!=(const Vector9i64& other) const noexcept;
		inline bool operator==(const std::int64_t& number)  const noexcept;
		inline bool operator!=(const std::int64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int64_t& stnd_value = 0ll) noexcept;
		inline std::int64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector10i64
	{
	public:
		std::int64_t a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10i64(const std::int64_t& a = 0ll, const std::int64_t& b = 0ll, const std::int64_t& c = 0ll, const std::int64_t& d = 0ll,
			const std::int64_t& e = 0ll, const std::int64_t& f = 0ll, const std::int64_t& g = 0ll, const std::int64_t& h = 0ll,
			const std::int64_t& i = 0ll, const std::int64_t& j = 0ll) noexcept;
		// copy
		inline Vector10i64(const Vector10i64& other) noexcept;
		inline Vector10i64& operator=(const Vector10i64& other) noexcept;
		// move
		inline Vector10i64(Vector10i64&& other) noexcept;
		inline Vector10i64& operator=(Vector10i64&& other) noexcept;
		// assignment
		inline Vector10i64& operator=(const std::int64_t& number) noexcept;
		
		// math operator
		inline Vector10i64 operator +(const Vector10i64& v) const noexcept;
		inline Vector10i64 operator -(const Vector10i64& v) const noexcept;
		inline Vector10i64 operator *(const Vector10i64& v) const noexcept;
		inline Vector10i64 operator /(const Vector10i64& v) const noexcept;
		
		inline Vector10i64 operator +(const std::int64_t& number) const noexcept;
		inline Vector10i64 operator -(const std::int64_t& number) const noexcept;
		inline Vector10i64 operator *(const std::int64_t& number) const noexcept;
		inline Vector10i64 operator /(const std::int64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector10i64& operator++ () noexcept;		// prefix increment
		inline Vector10i64& operator-- () noexcept;		// prefix decrement
		inline Vector10i64  operator++ (int) noexcept;	// postfix increment
		inline Vector10i64  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10i64& operator+= (const Vector10i64& right) noexcept;
		inline Vector10i64& operator-= (const Vector10i64& right) noexcept;
		inline Vector10i64& operator*= (const Vector10i64& right) noexcept;
		inline Vector10i64& operator/= (const Vector10i64& right) noexcept;
		
		inline Vector10i64& operator+= (const std::int64_t& number) noexcept;
		inline Vector10i64& operator-= (const std::int64_t& number) noexcept;
		inline Vector10i64& operator*= (const std::int64_t& number) noexcept;
		inline Vector10i64& operator/= (const std::int64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10i64& other) const noexcept;
		inline bool operator<  (const Vector10i64& other) const noexcept;
		inline bool operator>  (const Vector10i64& other) const noexcept;
		inline bool operator>= (const Vector10i64& other) const noexcept;

		inline bool operator<  (const std::int64_t& number) const noexcept;
		inline bool operator<= (const std::int64_t& number) const noexcept;
		inline bool operator>  (const std::int64_t& number) const noexcept;
		inline bool operator>= (const std::int64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10i64& other) const noexcept;
		inline bool operator!=(const Vector10i64& other) const noexcept;
		inline bool operator==(const std::int64_t& number)   const noexcept;
		inline bool operator!=(const std::int64_t& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::int64_t& stnd_value = 0ll) noexcept;
		inline std::int64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::int64_t& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2i64& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3i64& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4i64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5i64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6i64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7i64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8i64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9i64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10i64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}