#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::uint64_t
		Bytes: 8
		Range: 0 to 18.446.744.073.709.551.615
	*/

	class Vector2ui64
	{
	public:
		std::uint64_t x, y;
	public:
		inline Vector2ui64(const std::uint64_t& x = 0Ull, const std::uint64_t& y = 0Ull) noexcept;
		// copy
		inline Vector2ui64(const Vector2ui64& other) noexcept;
		inline Vector2ui64& operator=(const Vector2ui64& other) noexcept;
		// move
		inline Vector2ui64(Vector2ui64&& other) noexcept;
		inline Vector2ui64& operator=(Vector2ui64&& other) noexcept;
		// assignment
		inline Vector2ui64& operator=(const std::uint64_t& number) noexcept;

		// math operator
		inline Vector2ui64 operator +(const Vector2ui64& v) const noexcept;
		inline Vector2ui64 operator -(const Vector2ui64& v) const noexcept;
		inline Vector2ui64 operator *(const Vector2ui64& v) const noexcept;
		inline Vector2ui64 operator /(const Vector2ui64& v) const noexcept;

		inline Vector2ui64 operator +(const std::uint64_t& number) const noexcept;
		inline Vector2ui64 operator -(const std::uint64_t& number) const noexcept;
		inline Vector2ui64 operator *(const std::uint64_t& number) const noexcept;
		inline Vector2ui64 operator /(const std::uint64_t& number) const noexcept;

		// increment / decrement
		inline Vector2ui64& operator++ () noexcept;		// prefix increment
		inline Vector2ui64& operator-- () noexcept;		// prefix decrement
		inline Vector2ui64  operator++ (int) noexcept;		// postfix increment
		inline Vector2ui64  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2ui64& operator+= (const Vector2ui64& right) noexcept;
		inline Vector2ui64& operator-= (const Vector2ui64& right) noexcept;
		inline Vector2ui64& operator*= (const Vector2ui64& right) noexcept;
		inline Vector2ui64& operator/= (const Vector2ui64& right) noexcept;

		inline Vector2ui64& operator+= (const std::uint64_t& number) noexcept;
		inline Vector2ui64& operator-= (const std::uint64_t& number) noexcept;
		inline Vector2ui64& operator*= (const std::uint64_t& number) noexcept;
		inline Vector2ui64& operator/= (const std::uint64_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2ui64& other) const noexcept;
		inline bool operator<=  (const Vector2ui64& other) const noexcept;
		inline bool operator>	(const Vector2ui64& other) const noexcept;
		inline bool operator>=  (const Vector2ui64& other) const noexcept;

		inline bool operator<	(const std::uint64_t& number) const noexcept;
		inline bool operator<=  (const std::uint64_t& number) const noexcept;
		inline bool operator>	(const std::uint64_t& number) const noexcept;
		inline bool operator>=  (const std::uint64_t& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2ui64& other) const noexcept;
		inline bool operator!=(const Vector2ui64& other) const noexcept;
		inline bool operator==(const std::uint64_t& number)  const noexcept;
		inline bool operator!=(const std::uint64_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint64_t& stnd_value = 0Ull) noexcept;
		inline std::uint64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector3ui64
	{
	public:
		std::uint64_t x, y, z;
	public:
		inline Vector3ui64(const std::uint64_t& x = 0Ull, const std::uint64_t& y = 0Ull, const std::uint64_t& z = 0Ull) noexcept;
		// copy
		inline Vector3ui64(const Vector3ui64& other) noexcept;
		inline Vector3ui64& operator=(const Vector3ui64& other) noexcept;
		// move
		inline Vector3ui64(Vector3ui64&& other) noexcept;
		inline Vector3ui64& operator=(Vector3ui64&& other) noexcept;
		// assignment
		inline Vector3ui64& operator=(const std::uint64_t& number) noexcept;

		// math operator
		inline Vector3ui64 operator +(const Vector3ui64& v) const noexcept;
		inline Vector3ui64 operator -(const Vector3ui64& v) const noexcept;
		inline Vector3ui64 operator *(const Vector3ui64& v) const noexcept;
		inline Vector3ui64 operator /(const Vector3ui64& v) const noexcept;

		inline Vector3ui64 operator +(const std::uint64_t& number) const noexcept;
		inline Vector3ui64 operator -(const std::uint64_t& number) const noexcept;
		inline Vector3ui64 operator *(const std::uint64_t& number) const noexcept;
		inline Vector3ui64 operator /(const std::uint64_t& number) const noexcept;

		// increment / decrement
		inline Vector3ui64& operator++ () noexcept;		// prefix increment
		inline Vector3ui64& operator-- () noexcept;		// prefix decrement
		inline Vector3ui64  operator++ (int) noexcept;		// postfix increment
		inline Vector3ui64  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3ui64& operator+= (const Vector3ui64& right) noexcept;
		inline Vector3ui64& operator-= (const Vector3ui64& right) noexcept;
		inline Vector3ui64& operator*= (const Vector3ui64& right) noexcept;
		inline Vector3ui64& operator/= (const Vector3ui64& right) noexcept;

		inline Vector3ui64& operator+= (const std::uint64_t& number) noexcept;
		inline Vector3ui64& operator-= (const std::uint64_t& number) noexcept;
		inline Vector3ui64& operator*= (const std::uint64_t& number) noexcept;
		inline Vector3ui64& operator/= (const std::uint64_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3ui64& other) const noexcept;
		inline bool operator<=  (const Vector3ui64& other) const noexcept;
		inline bool operator>	(const Vector3ui64& other) const noexcept;
		inline bool operator>=  (const Vector3ui64& other) const noexcept;
		 
		inline bool operator<	(const std::uint64_t& number) const noexcept;
		inline bool operator<=  (const std::uint64_t& number) const noexcept;
		inline bool operator>	(const std::uint64_t& number) const noexcept;
		inline bool operator>=  (const std::uint64_t& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3ui64& other) const noexcept;
		inline bool operator!=(const Vector3ui64& other) const noexcept;
		inline bool operator==(const std::uint64_t& number)  const noexcept;
		inline bool operator!=(const std::uint64_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint64_t& stnd_value = 0Ull) noexcept;
		inline std::uint64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector4ui64
	{
	public:
		std::uint64_t a, b, c, d;
	public:
		inline Vector4ui64(const std::uint64_t& a = 0Ull, const std::uint64_t& b = 0Ull, const std::uint64_t& c = 0Ull, const std::uint64_t& d = 0Ull) noexcept;
		// copy
		inline Vector4ui64(const Vector4ui64& other) noexcept;
		inline Vector4ui64& operator=(const Vector4ui64& other) noexcept;
		// move
		inline Vector4ui64(Vector4ui64&& other) noexcept;
		inline Vector4ui64& operator=(Vector4ui64&& other) noexcept;
		// assignment
		inline Vector4ui64& operator=(const std::uint64_t& number) noexcept;
		
		// math operator
		inline Vector4ui64 operator +(const Vector4ui64& v) const noexcept;
		inline Vector4ui64 operator -(const Vector4ui64& v) const noexcept;
		inline Vector4ui64 operator *(const Vector4ui64& v) const noexcept;
		inline Vector4ui64 operator /(const Vector4ui64& v) const noexcept;
		
		inline Vector4ui64 operator +(const std::uint64_t& number) const noexcept;
		inline Vector4ui64 operator -(const std::uint64_t& number) const noexcept;
		inline Vector4ui64 operator *(const std::uint64_t& number) const noexcept;
		inline Vector4ui64 operator /(const std::uint64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector4ui64& operator++ () noexcept;		// prefix increment
		inline Vector4ui64& operator-- () noexcept;		// prefix decrement
		inline Vector4ui64  operator++ (int) noexcept;		// postfix increment
		inline Vector4ui64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4ui64& operator+= (const Vector4ui64& right) noexcept;
		inline Vector4ui64& operator-= (const Vector4ui64& right) noexcept;
		inline Vector4ui64& operator*= (const Vector4ui64& right) noexcept;
		inline Vector4ui64& operator/= (const Vector4ui64& right) noexcept;
		
		inline Vector4ui64& operator+= (const std::uint64_t& number) noexcept;
		inline Vector4ui64& operator-= (const std::uint64_t& number) noexcept;
		inline Vector4ui64& operator*= (const std::uint64_t& number) noexcept;
		inline Vector4ui64& operator/= (const std::uint64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4ui64& other) const noexcept;
		inline bool operator<=  (const Vector4ui64& other) const noexcept;
		inline bool operator>	(const Vector4ui64& other) const noexcept;
		inline bool operator>=  (const Vector4ui64& other) const noexcept;
		
		inline bool operator<	(const std::uint64_t& number) const noexcept;
		inline bool operator<=  (const std::uint64_t& number) const noexcept;
		inline bool operator>	(const std::uint64_t& number) const noexcept;
		inline bool operator>=  (const std::uint64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4ui64& other) const noexcept;
		inline bool operator!=(const Vector4ui64& other) const noexcept;
		inline bool operator==(const std::uint64_t& number)  const noexcept;
		inline bool operator!=(const std::uint64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint64_t& stnd_value = 0Ull) noexcept;
		inline std::uint64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector5ui64
	{
	public:
		std::uint64_t a, b, c, d, e;
	public:
		inline Vector5ui64(const std::uint64_t& a = 0Ull, const std::uint64_t& b = 0Ull, const std::uint64_t& c = 0Ull, const std::uint64_t& d = 0Ull,
			const std::uint64_t& e = 0Ull) noexcept;
		// copy
		inline Vector5ui64(const Vector5ui64& other) noexcept;
		inline Vector5ui64& operator=(const Vector5ui64& other) noexcept;
		// move
		inline Vector5ui64(Vector5ui64&& other) noexcept;
		inline Vector5ui64& operator=(Vector5ui64&& other) noexcept;
		// assignment
		inline Vector5ui64& operator=(const std::uint64_t& number) noexcept;
		 
		// math operator
		inline Vector5ui64 operator +(const Vector5ui64& v) const noexcept;
		inline Vector5ui64 operator -(const Vector5ui64& v) const noexcept;
		inline Vector5ui64 operator *(const Vector5ui64& v) const noexcept;
		inline Vector5ui64 operator /(const Vector5ui64& v) const noexcept;
		
		inline Vector5ui64 operator +(const std::uint64_t& number) const noexcept;
		inline Vector5ui64 operator -(const std::uint64_t& number) const noexcept;
		inline Vector5ui64 operator *(const std::uint64_t& number) const noexcept;
		inline Vector5ui64 operator /(const std::uint64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector5ui64& operator++ () noexcept;		// prefix increment
		inline Vector5ui64& operator-- () noexcept;		// prefix decrement
		inline Vector5ui64  operator++ (int) noexcept;		// postfix increment
		inline Vector5ui64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5ui64& operator+= (const Vector5ui64& right) noexcept;
		inline Vector5ui64& operator-= (const Vector5ui64& right) noexcept;
		inline Vector5ui64& operator*= (const Vector5ui64& right) noexcept;
		inline Vector5ui64& operator/= (const Vector5ui64& right) noexcept;
		
		inline Vector5ui64& operator+= (const std::uint64_t& number) noexcept;
		inline Vector5ui64& operator-= (const std::uint64_t& number) noexcept;
		inline Vector5ui64& operator*= (const std::uint64_t& number) noexcept;
		inline Vector5ui64& operator/= (const std::uint64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5ui64& other) const noexcept;
		inline bool operator<=  (const Vector5ui64& other) const noexcept;
		inline bool operator>	(const Vector5ui64& other) const noexcept;
		inline bool operator>=  (const Vector5ui64& other) const noexcept;
		
		inline bool operator<	(const std::uint64_t& number) const noexcept;
		inline bool operator<=  (const std::uint64_t& number) const noexcept;
		inline bool operator>	(const std::uint64_t& number) const noexcept;
		inline bool operator>=  (const std::uint64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5ui64& other) const noexcept;
		inline bool operator!=(const Vector5ui64& other) const noexcept;
		inline bool operator==(const std::uint64_t& number)  const noexcept;
		inline bool operator!=(const std::uint64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint64_t& stnd_value = 0Ull) noexcept;
		inline std::uint64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector6ui64
	{
	public:
		std::uint64_t a, b, c, d, e, f;
	public:
		inline Vector6ui64(const std::uint64_t& a = 0Ull, const std::uint64_t& b = 0Ull, const std::uint64_t& c = 0Ull, const std::uint64_t& d = 0Ull,
			const std::uint64_t& e = 0Ull, const std::uint64_t& f = 0Ull) noexcept;
		// copy
		inline Vector6ui64(const Vector6ui64& other) noexcept;
		inline Vector6ui64& operator=(const Vector6ui64& other) noexcept;
		// move
		inline Vector6ui64(Vector6ui64&& other) noexcept;
		inline Vector6ui64& operator=(Vector6ui64&& other) noexcept;
		// assignment
		inline Vector6ui64& operator=(const std::uint64_t& number) noexcept;
		
		// math operator
		inline Vector6ui64 operator +(const Vector6ui64& v) const noexcept;
		inline Vector6ui64 operator -(const Vector6ui64& v) const noexcept;
		inline Vector6ui64 operator *(const Vector6ui64& v) const noexcept;
		inline Vector6ui64 operator /(const Vector6ui64& v) const noexcept;
		
		inline Vector6ui64 operator +(const std::uint64_t& number) const noexcept;
		inline Vector6ui64 operator -(const std::uint64_t& number) const noexcept;
		inline Vector6ui64 operator *(const std::uint64_t& number) const noexcept;
		inline Vector6ui64 operator /(const std::uint64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector6ui64& operator++ () noexcept;		// prefix increment
		inline Vector6ui64& operator-- () noexcept;		// prefix decrement
		inline Vector6ui64  operator++ (int) noexcept;		// postfix increment
		inline Vector6ui64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6ui64& operator+= (const Vector6ui64& right) noexcept;
		inline Vector6ui64& operator-= (const Vector6ui64& right) noexcept;
		inline Vector6ui64& operator*= (const Vector6ui64& right) noexcept;
		inline Vector6ui64& operator/= (const Vector6ui64& right) noexcept;
		
		inline Vector6ui64& operator+= (const std::uint64_t& number) noexcept;
		inline Vector6ui64& operator-= (const std::uint64_t& number) noexcept;
		inline Vector6ui64& operator*= (const std::uint64_t& number) noexcept;
		inline Vector6ui64& operator/= (const std::uint64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6ui64& other) const noexcept;
		inline bool operator<  (const Vector6ui64& other) const noexcept;
		inline bool operator>  (const Vector6ui64& other) const noexcept;
		inline bool operator>= (const Vector6ui64& other) const noexcept;
		
		inline bool operator<  (const std::uint64_t& number) const noexcept;
		inline bool operator<= (const std::uint64_t& number) const noexcept;
		inline bool operator>  (const std::uint64_t& number) const noexcept;
		inline bool operator>= (const std::uint64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6ui64& other) const noexcept;
		inline bool operator!=(const Vector6ui64& other) const noexcept;
		inline bool operator==(const std::uint64_t& number)  const noexcept;
		inline bool operator!=(const std::uint64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint64_t& stnd_value = 0Ull) noexcept;
		inline std::uint64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector7ui64
	{
	public:
		std::uint64_t a, b, c, d, e, f, g;
	public:
		inline Vector7ui64(const std::uint64_t& a = 0Ull, const std::uint64_t& b = 0Ull, const std::uint64_t& c = 0Ull, const std::uint64_t& d = 0Ull,
			const std::uint64_t& e = 0Ull, const std::uint64_t& f = 0Ull, const std::uint64_t& g = 0Ull) noexcept;
		// copy
		inline Vector7ui64(const Vector7ui64& other) noexcept;
		inline Vector7ui64& operator=(const Vector7ui64& other) noexcept;
		// move
		inline Vector7ui64(Vector7ui64&& other) noexcept;
		inline Vector7ui64& operator=(Vector7ui64&& other) noexcept;
		// assignment
		inline Vector7ui64& operator=(const std::uint64_t& number) noexcept;
		
		// math operator
		inline Vector7ui64 operator +(const Vector7ui64& v) const noexcept;
		inline Vector7ui64 operator -(const Vector7ui64& v) const noexcept;
		inline Vector7ui64 operator *(const Vector7ui64& v) const noexcept;
		inline Vector7ui64 operator /(const Vector7ui64& v) const noexcept;
		
		inline Vector7ui64 operator +(const std::uint64_t& number) const noexcept;
		inline Vector7ui64 operator -(const std::uint64_t& number) const noexcept;
		inline Vector7ui64 operator *(const std::uint64_t& number) const noexcept;
		inline Vector7ui64 operator /(const std::uint64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector7ui64& operator++ () noexcept;		// prefix increment
		inline Vector7ui64& operator-- () noexcept;		// prefix decrement
		inline Vector7ui64  operator++ (int) noexcept;		// postfix increment
		inline Vector7ui64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7ui64& operator+= (const Vector7ui64& right) noexcept;
		inline Vector7ui64& operator-= (const Vector7ui64& right) noexcept;
		inline Vector7ui64& operator*= (const Vector7ui64& right) noexcept;
		inline Vector7ui64& operator/= (const Vector7ui64& right) noexcept;
		
		inline Vector7ui64& operator+= (const std::uint64_t& number) noexcept;
		inline Vector7ui64& operator-= (const std::uint64_t& number) noexcept;
		inline Vector7ui64& operator*= (const std::uint64_t& number) noexcept;
		inline Vector7ui64& operator/= (const std::uint64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7ui64& other) const noexcept;
		inline bool operator<  (const Vector7ui64& other) const noexcept;
		inline bool operator>  (const Vector7ui64& other) const noexcept;
		inline bool operator>= (const Vector7ui64& other) const noexcept;
		
		inline bool operator<  (const std::uint64_t& number) const noexcept;
		inline bool operator<= (const std::uint64_t& number) const noexcept;
		inline bool operator>  (const std::uint64_t& number) const noexcept;
		inline bool operator>= (const std::uint64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7ui64& other) const noexcept;
		inline bool operator!=(const Vector7ui64& other) const noexcept;
		inline bool operator==(const std::uint64_t& number)  const noexcept;
		inline bool operator!=(const std::uint64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint64_t& stnd_value = 0Ull) noexcept;
		inline std::uint64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector8ui64
	{
	public:
		std::uint64_t a, b, c, d, e, f, g, h;
	public:
		inline Vector8ui64(const std::uint64_t& a = 0Ull, const std::uint64_t& b = 0Ull, const std::uint64_t& c = 0Ull, const std::uint64_t& d = 0Ull,
			const std::uint64_t& e = 0Ull, const std::uint64_t& f = 0Ull, const std::uint64_t& g = 0Ull, const std::uint64_t& h = 0Ull) noexcept;
		// copy
		inline Vector8ui64(const Vector8ui64& other) noexcept;
		inline Vector8ui64& operator=(const Vector8ui64& other) noexcept;
		// move
		inline Vector8ui64(Vector8ui64&& other) noexcept;
		inline Vector8ui64& operator=(Vector8ui64&& other) noexcept;
		// assignment
		inline Vector8ui64& operator=(const std::uint64_t& number) noexcept;
		
		// math operator
		inline Vector8ui64 operator +(const Vector8ui64& v) const noexcept;
		inline Vector8ui64 operator -(const Vector8ui64& v) const noexcept;
		inline Vector8ui64 operator *(const Vector8ui64& v) const noexcept;
		inline Vector8ui64 operator /(const Vector8ui64& v) const noexcept;
		
		inline Vector8ui64 operator +(const std::uint64_t& number) const noexcept;
		inline Vector8ui64 operator -(const std::uint64_t& number) const noexcept;
		inline Vector8ui64 operator *(const std::uint64_t& number) const noexcept;
		inline Vector8ui64 operator /(const std::uint64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector8ui64& operator++ () noexcept;		// prefix increment
		inline Vector8ui64& operator-- () noexcept;		// prefix decrement
		inline Vector8ui64  operator++ (int) noexcept;		// postfix increment
		inline Vector8ui64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8ui64& operator+= (const Vector8ui64& right) noexcept;
		inline Vector8ui64& operator-= (const Vector8ui64& right) noexcept;
		inline Vector8ui64& operator*= (const Vector8ui64& right) noexcept;
		inline Vector8ui64& operator/= (const Vector8ui64& right) noexcept;
		
		inline Vector8ui64& operator+= (const std::uint64_t& number) noexcept;
		inline Vector8ui64& operator-= (const std::uint64_t& number) noexcept;
		inline Vector8ui64& operator*= (const std::uint64_t& number) noexcept;
		inline Vector8ui64& operator/= (const std::uint64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8ui64& other) const noexcept;
		inline bool operator<  (const Vector8ui64& other) const noexcept;
		inline bool operator>  (const Vector8ui64& other) const noexcept;
		inline bool operator>= (const Vector8ui64& other) const noexcept;
		
		inline bool operator<  (const std::uint64_t& number) const noexcept;
		inline bool operator<= (const std::uint64_t& number) const noexcept;
		inline bool operator>  (const std::uint64_t& number) const noexcept;
		inline bool operator>= (const std::uint64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8ui64& other) const noexcept;
		inline bool operator!=(const Vector8ui64& other) const noexcept;
		inline bool operator==(const std::uint64_t& number)  const noexcept;
		inline bool operator!=(const std::uint64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint64_t& stnd_value = 0Ull) noexcept;
		inline std::uint64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector9ui64
	{
	public:
		std::uint64_t a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9ui64(const std::uint64_t& a = 0Ull, const std::uint64_t& b = 0Ull, const std::uint64_t& c = 0Ull, const std::uint64_t& d = 0Ull,
			const std::uint64_t& e = 0Ull, const std::uint64_t& f = 0Ull, const std::uint64_t& g = 0Ull, const std::uint64_t& h = 0Ull,
			const std::uint64_t& i = 0Ull) noexcept;
		// copy
		inline Vector9ui64(const Vector9ui64& other) noexcept;
		inline Vector9ui64& operator=(const Vector9ui64& other) noexcept;
		// move
		inline Vector9ui64(Vector9ui64&& other) noexcept;
		inline Vector9ui64& operator=(Vector9ui64&& other) noexcept;
		// assignment
		inline Vector9ui64& operator=(const std::uint64_t& number) noexcept;
		
		// math operator
		inline Vector9ui64 operator +(const Vector9ui64& v) const noexcept;
		inline Vector9ui64 operator -(const Vector9ui64& v) const noexcept;
		inline Vector9ui64 operator *(const Vector9ui64& v) const noexcept;
		inline Vector9ui64 operator /(const Vector9ui64& v) const noexcept;
		
		inline Vector9ui64 operator +(const std::uint64_t& number) const noexcept;
		inline Vector9ui64 operator -(const std::uint64_t& number) const noexcept;
		inline Vector9ui64 operator *(const std::uint64_t& number) const noexcept;
		inline Vector9ui64 operator /(const std::uint64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector9ui64& operator++ () noexcept;		// prefix increment
		inline Vector9ui64& operator-- () noexcept;		// prefix decrement
		inline Vector9ui64  operator++ (int) noexcept;		// postfix increment
		inline Vector9ui64  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9ui64& operator+= (const Vector9ui64& right) noexcept;
		inline Vector9ui64& operator-= (const Vector9ui64& right) noexcept;
		inline Vector9ui64& operator*= (const Vector9ui64& right) noexcept;
		inline Vector9ui64& operator/= (const Vector9ui64& right) noexcept;
		
		inline Vector9ui64& operator+= (const std::uint64_t& number) noexcept;
		inline Vector9ui64& operator-= (const std::uint64_t& number) noexcept;
		inline Vector9ui64& operator*= (const std::uint64_t& number) noexcept;
		inline Vector9ui64& operator/= (const std::uint64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9ui64& other) const noexcept;
		inline bool operator<  (const Vector9ui64& other) const noexcept;
		inline bool operator>  (const Vector9ui64& other) const noexcept;
		inline bool operator>= (const Vector9ui64& other) const noexcept;
		
		inline bool operator<  (const std::uint64_t& number) const noexcept;
		inline bool operator<= (const std::uint64_t& number) const noexcept;
		inline bool operator>  (const std::uint64_t& number) const noexcept;
		inline bool operator>= (const std::uint64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9ui64& other) const noexcept;
		inline bool operator!=(const Vector9ui64& other) const noexcept;
		inline bool operator==(const std::uint64_t& number)  const noexcept;
		inline bool operator!=(const std::uint64_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint64_t& stnd_value = 0Ull) noexcept;
		inline std::uint64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint64_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector10ui64
	{
	public:
		std::uint64_t a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10ui64(const std::uint64_t& a = 0Ull, const std::uint64_t& b = 0Ull, const std::uint64_t& c = 0Ull, const std::uint64_t& d = 0Ull,
			const std::uint64_t& e = 0Ull, const std::uint64_t& f = 0Ull, const std::uint64_t& g = 0Ull, const std::uint64_t& h = 0Ull,
			const std::uint64_t& i = 0Ull, const std::uint64_t& j = 0Ull) noexcept;
		// copy
		inline Vector10ui64(const Vector10ui64& other) noexcept;
		inline Vector10ui64& operator=(const Vector10ui64& other) noexcept;
		// move
		inline Vector10ui64(Vector10ui64&& other) noexcept;
		inline Vector10ui64& operator=(Vector10ui64&& other) noexcept;
		// assignment
		inline Vector10ui64& operator=(const std::uint64_t& number) noexcept;
		
		// math operator
		inline Vector10ui64 operator +(const Vector10ui64& v) const noexcept;
		inline Vector10ui64 operator -(const Vector10ui64& v) const noexcept;
		inline Vector10ui64 operator *(const Vector10ui64& v) const noexcept;
		inline Vector10ui64 operator /(const Vector10ui64& v) const noexcept;
		
		inline Vector10ui64 operator +(const std::uint64_t& number) const noexcept;
		inline Vector10ui64 operator -(const std::uint64_t& number) const noexcept;
		inline Vector10ui64 operator *(const std::uint64_t& number) const noexcept;
		inline Vector10ui64 operator /(const std::uint64_t& number) const noexcept;
		
		// increment / decrement
		inline Vector10ui64& operator++ () noexcept;		// prefix increment
		inline Vector10ui64& operator-- () noexcept;		// prefix decrement
		inline Vector10ui64  operator++ (int) noexcept;	// postfix increment
		inline Vector10ui64  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10ui64& operator+= (const Vector10ui64& right) noexcept;
		inline Vector10ui64& operator-= (const Vector10ui64& right) noexcept;
		inline Vector10ui64& operator*= (const Vector10ui64& right) noexcept;
		inline Vector10ui64& operator/= (const Vector10ui64& right) noexcept;
		
		inline Vector10ui64& operator+= (const std::uint64_t& number) noexcept;
		inline Vector10ui64& operator-= (const std::uint64_t& number) noexcept;
		inline Vector10ui64& operator*= (const std::uint64_t& number) noexcept;
		inline Vector10ui64& operator/= (const std::uint64_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10ui64& other) const noexcept;
		inline bool operator<  (const Vector10ui64& other) const noexcept;
		inline bool operator>  (const Vector10ui64& other) const noexcept;
		inline bool operator>= (const Vector10ui64& other) const noexcept;

		inline bool operator<  (const std::uint64_t& number) const noexcept;
		inline bool operator<= (const std::uint64_t& number) const noexcept;
		inline bool operator>  (const std::uint64_t& number) const noexcept;
		inline bool operator>= (const std::uint64_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10ui64& other) const noexcept;
		inline bool operator!=(const Vector10ui64& other) const noexcept;
		inline bool operator==(const std::uint64_t& number)   const noexcept;
		inline bool operator!=(const std::uint64_t& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::uint64_t& stnd_value = 0Ull) noexcept;
		inline std::uint64_t& operator[](const std::uint8_t& index) noexcept;
		inline std::uint64_t& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2ui64& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3ui64& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4ui64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5ui64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6ui64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7ui64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8ui64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9ui64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10ui64& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}