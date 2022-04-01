#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : std::double_t
		Bytes: 8
		Range: 1.7E +/- 308  precision: (15 digits)
	*/

	class Vector2d
	{
	public:
		std::double_t x, y;
	public:
		inline Vector2d(const std::double_t& x = 0.0, const std::double_t& y = 0.0) noexcept;
		// copy
		inline Vector2d(const Vector2d& other) noexcept;
		inline Vector2d& operator=(const Vector2d& other) noexcept;
		// move
		inline Vector2d(Vector2d&& other) noexcept;
		inline Vector2d& operator=(Vector2d&& other) noexcept;
		// assignment
		inline Vector2d& operator=(const std::double_t& number) noexcept;

		// math operator
		inline Vector2d operator +(const Vector2d& v) const noexcept;
		inline Vector2d operator -(const Vector2d& v) const noexcept;
		inline Vector2d operator *(const Vector2d& v) const noexcept;
		inline Vector2d operator /(const Vector2d& v) const noexcept;

		inline Vector2d operator +(const std::double_t& number) const noexcept;
		inline Vector2d operator -(const std::double_t& number) const noexcept;
		inline Vector2d operator *(const std::double_t& number) const noexcept;
		inline Vector2d operator /(const std::double_t& number) const noexcept;

		// increment / decrement
		inline Vector2d& operator++ () noexcept;		// prefix increment
		inline Vector2d& operator-- () noexcept;		// prefix decrement
		inline Vector2d  operator++ (int) noexcept;		// postfix increment
		inline Vector2d  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2d& operator+= (const Vector2d& right) noexcept;
		inline Vector2d& operator-= (const Vector2d& right) noexcept;
		inline Vector2d& operator*= (const Vector2d& right) noexcept;
		inline Vector2d& operator/= (const Vector2d& right) noexcept;

		inline Vector2d& operator+= (const std::double_t& number) noexcept;
		inline Vector2d& operator-= (const std::double_t& number) noexcept;
		inline Vector2d& operator*= (const std::double_t& number) noexcept;
		inline Vector2d& operator/= (const std::double_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2d& other) const noexcept;
		inline bool operator<=  (const Vector2d& other) const noexcept;
		inline bool operator>	(const Vector2d& other) const noexcept;
		inline bool operator>=  (const Vector2d& other) const noexcept;

		inline bool operator<	(const std::double_t& number) const noexcept;
		inline bool operator<=  (const std::double_t& number) const noexcept;
		inline bool operator>	(const std::double_t& number) const noexcept;
		inline bool operator>=  (const std::double_t& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2d& other) const noexcept;
		inline bool operator!=(const Vector2d& other) const noexcept;
		inline bool operator==(const std::double_t& number)  const noexcept;
		inline bool operator!=(const std::double_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::double_t& stnd_value = 0.0) noexcept;
		inline std::double_t& operator[](const std::uint8_t& index) noexcept;
		inline std::double_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector3d
	{
	public:
		std::double_t x, y, z;
	public:
		inline Vector3d(const std::double_t& x = 0.0, const std::double_t& y = 0.0, const std::double_t& z = 0.0) noexcept;
		// copy
		inline Vector3d(const Vector3d& other) noexcept;
		inline Vector3d& operator=(const Vector3d& other) noexcept;
		// move
		inline Vector3d(Vector3d&& other) noexcept;
		inline Vector3d& operator=(Vector3d&& other) noexcept;
		// assignment
		inline Vector3d& operator=(const std::double_t& number) noexcept;

		// math operator
		inline Vector3d operator +(const Vector3d& v) const noexcept;
		inline Vector3d operator -(const Vector3d& v) const noexcept;
		inline Vector3d operator *(const Vector3d& v) const noexcept;
		inline Vector3d operator /(const Vector3d& v) const noexcept;

		inline Vector3d operator +(const std::double_t& number) const noexcept;
		inline Vector3d operator -(const std::double_t& number) const noexcept;
		inline Vector3d operator *(const std::double_t& number) const noexcept;
		inline Vector3d operator /(const std::double_t& number) const noexcept;

		// increment / decrement
		inline Vector3d& operator++ () noexcept;		// prefix increment
		inline Vector3d& operator-- () noexcept;		// prefix decrement
		inline Vector3d  operator++ (int) noexcept;		// postfix increment
		inline Vector3d  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3d& operator+= (const Vector3d& right) noexcept;
		inline Vector3d& operator-= (const Vector3d& right) noexcept;
		inline Vector3d& operator*= (const Vector3d& right) noexcept;
		inline Vector3d& operator/= (const Vector3d& right) noexcept;

		inline Vector3d& operator+= (const std::double_t& number) noexcept;
		inline Vector3d& operator-= (const std::double_t& number) noexcept;
		inline Vector3d& operator*= (const std::double_t& number) noexcept;
		inline Vector3d& operator/= (const std::double_t& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3d& other) const noexcept;
		inline bool operator<=  (const Vector3d& other) const noexcept;
		inline bool operator>	(const Vector3d& other) const noexcept;
		inline bool operator>=  (const Vector3d& other) const noexcept;
		 
		inline bool operator<	(const std::double_t& number) const noexcept;
		inline bool operator<=  (const std::double_t& number) const noexcept;
		inline bool operator>	(const std::double_t& number) const noexcept;
		inline bool operator>=  (const std::double_t& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3d& other) const noexcept;
		inline bool operator!=(const Vector3d& other) const noexcept;
		inline bool operator==(const std::double_t& number)  const noexcept;
		inline bool operator!=(const std::double_t& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::double_t& stnd_value = 0.0) noexcept;
		inline std::double_t& operator[](const std::uint8_t& index) noexcept;
		inline std::double_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector4d
	{
	public:
		std::double_t a, b, c, d;
	public:
		inline Vector4d(const std::double_t& a = 0.0, const std::double_t& b = 0.0, const std::double_t& c = 0.0, const std::double_t& d = 0.0) noexcept;
		// copy
		inline Vector4d(const Vector4d& other) noexcept;
		inline Vector4d& operator=(const Vector4d& other) noexcept;
		// move
		inline Vector4d(Vector4d&& other) noexcept;
		inline Vector4d& operator=(Vector4d&& other) noexcept;
		// assignment
		inline Vector4d& operator=(const std::double_t& number) noexcept;
		
		// math operator
		inline Vector4d operator +(const Vector4d& v) const noexcept;
		inline Vector4d operator -(const Vector4d& v) const noexcept;
		inline Vector4d operator *(const Vector4d& v) const noexcept;
		inline Vector4d operator /(const Vector4d& v) const noexcept;
		
		inline Vector4d operator +(const std::double_t& number) const noexcept;
		inline Vector4d operator -(const std::double_t& number) const noexcept;
		inline Vector4d operator *(const std::double_t& number) const noexcept;
		inline Vector4d operator /(const std::double_t& number) const noexcept;
		
		// increment / decrement
		inline Vector4d& operator++ () noexcept;		// prefix increment
		inline Vector4d& operator-- () noexcept;		// prefix decrement
		inline Vector4d  operator++ (int) noexcept;		// postfix increment
		inline Vector4d  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4d& operator+= (const Vector4d& right) noexcept;
		inline Vector4d& operator-= (const Vector4d& right) noexcept;
		inline Vector4d& operator*= (const Vector4d& right) noexcept;
		inline Vector4d& operator/= (const Vector4d& right) noexcept;
		
		inline Vector4d& operator+= (const std::double_t& number) noexcept;
		inline Vector4d& operator-= (const std::double_t& number) noexcept;
		inline Vector4d& operator*= (const std::double_t& number) noexcept;
		inline Vector4d& operator/= (const std::double_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4d& other) const noexcept;
		inline bool operator<=  (const Vector4d& other) const noexcept;
		inline bool operator>	(const Vector4d& other) const noexcept;
		inline bool operator>=  (const Vector4d& other) const noexcept;
		
		inline bool operator<	(const std::double_t& number) const noexcept;
		inline bool operator<=  (const std::double_t& number) const noexcept;
		inline bool operator>	(const std::double_t& number) const noexcept;
		inline bool operator>=  (const std::double_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4d& other) const noexcept;
		inline bool operator!=(const Vector4d& other) const noexcept;
		inline bool operator==(const std::double_t& number)  const noexcept;
		inline bool operator!=(const std::double_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::double_t& stnd_value = 0.0) noexcept;
		inline std::double_t& operator[](const std::uint8_t& index) noexcept;
		inline std::double_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector5d
	{
	public:
		std::double_t a, b, c, d, e;
	public:
		inline Vector5d(const std::double_t& a = 0.0, const std::double_t& b = 0.0, const std::double_t& c = 0.0, const std::double_t& d = 0.0,
			const std::double_t& e = 0.0) noexcept;
		// copy
		inline Vector5d(const Vector5d& other) noexcept;
		inline Vector5d& operator=(const Vector5d& other) noexcept;
		// move
		inline Vector5d(Vector5d&& other) noexcept;
		inline Vector5d& operator=(Vector5d&& other) noexcept;
		// assignment
		inline Vector5d& operator=(const std::double_t& number) noexcept;
		 
		// math operator
		inline Vector5d operator +(const Vector5d& v) const noexcept;
		inline Vector5d operator -(const Vector5d& v) const noexcept;
		inline Vector5d operator *(const Vector5d& v) const noexcept;
		inline Vector5d operator /(const Vector5d& v) const noexcept;
		
		inline Vector5d operator +(const std::double_t& number) const noexcept;
		inline Vector5d operator -(const std::double_t& number) const noexcept;
		inline Vector5d operator *(const std::double_t& number) const noexcept;
		inline Vector5d operator /(const std::double_t& number) const noexcept;
		
		// increment / decrement
		inline Vector5d& operator++ () noexcept;		// prefix increment
		inline Vector5d& operator-- () noexcept;		// prefix decrement
		inline Vector5d  operator++ (int) noexcept;		// postfix increment
		inline Vector5d  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5d& operator+= (const Vector5d& right) noexcept;
		inline Vector5d& operator-= (const Vector5d& right) noexcept;
		inline Vector5d& operator*= (const Vector5d& right) noexcept;
		inline Vector5d& operator/= (const Vector5d& right) noexcept;
		
		inline Vector5d& operator+= (const std::double_t& number) noexcept;
		inline Vector5d& operator-= (const std::double_t& number) noexcept;
		inline Vector5d& operator*= (const std::double_t& number) noexcept;
		inline Vector5d& operator/= (const std::double_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5d& other) const noexcept;
		inline bool operator<=  (const Vector5d& other) const noexcept;
		inline bool operator>	(const Vector5d& other) const noexcept;
		inline bool operator>=  (const Vector5d& other) const noexcept;
		
		inline bool operator<	(const std::double_t& number) const noexcept;
		inline bool operator<=  (const std::double_t& number) const noexcept;
		inline bool operator>	(const std::double_t& number) const noexcept;
		inline bool operator>=  (const std::double_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5d& other) const noexcept;
		inline bool operator!=(const Vector5d& other) const noexcept;
		inline bool operator==(const std::double_t& number)  const noexcept;
		inline bool operator!=(const std::double_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::double_t& stnd_value = 0.0) noexcept;
		inline std::double_t& operator[](const std::uint8_t& index) noexcept;
		inline std::double_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector6d
	{
	public:
		std::double_t a, b, c, d, e, f;
	public:
		inline Vector6d(const std::double_t& a = 0.0, const std::double_t& b = 0.0, const std::double_t& c = 0.0, const std::double_t& d = 0.0,
			const std::double_t& e = 0.0, const std::double_t& f = 0.0) noexcept;
		// copy
		inline Vector6d(const Vector6d& other) noexcept;
		inline Vector6d& operator=(const Vector6d& other) noexcept;
		// move
		inline Vector6d(Vector6d&& other) noexcept;
		inline Vector6d& operator=(Vector6d&& other) noexcept;
		// assignment
		inline Vector6d& operator=(const std::double_t& number) noexcept;
		
		// math operator
		inline Vector6d operator +(const Vector6d& v) const noexcept;
		inline Vector6d operator -(const Vector6d& v) const noexcept;
		inline Vector6d operator *(const Vector6d& v) const noexcept;
		inline Vector6d operator /(const Vector6d& v) const noexcept;
		
		inline Vector6d operator +(const std::double_t& number) const noexcept;
		inline Vector6d operator -(const std::double_t& number) const noexcept;
		inline Vector6d operator *(const std::double_t& number) const noexcept;
		inline Vector6d operator /(const std::double_t& number) const noexcept;
		
		// increment / decrement
		inline Vector6d& operator++ () noexcept;		// prefix increment
		inline Vector6d& operator-- () noexcept;		// prefix decrement
		inline Vector6d  operator++ (int) noexcept;		// postfix increment
		inline Vector6d  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6d& operator+= (const Vector6d& right) noexcept;
		inline Vector6d& operator-= (const Vector6d& right) noexcept;
		inline Vector6d& operator*= (const Vector6d& right) noexcept;
		inline Vector6d& operator/= (const Vector6d& right) noexcept;
		
		inline Vector6d& operator+= (const std::double_t& number) noexcept;
		inline Vector6d& operator-= (const std::double_t& number) noexcept;
		inline Vector6d& operator*= (const std::double_t& number) noexcept;
		inline Vector6d& operator/= (const std::double_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6d& other) const noexcept;
		inline bool operator<  (const Vector6d& other) const noexcept;
		inline bool operator>  (const Vector6d& other) const noexcept;
		inline bool operator>= (const Vector6d& other) const noexcept;
		
		inline bool operator<  (const std::double_t& number) const noexcept;
		inline bool operator<= (const std::double_t& number) const noexcept;
		inline bool operator>  (const std::double_t& number) const noexcept;
		inline bool operator>= (const std::double_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6d& other) const noexcept;
		inline bool operator!=(const Vector6d& other) const noexcept;
		inline bool operator==(const std::double_t& number)  const noexcept;
		inline bool operator!=(const std::double_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::double_t& stnd_value = 0.0) noexcept;
		inline std::double_t& operator[](const std::uint8_t& index) noexcept;
		inline std::double_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector7d
	{
	public:
		std::double_t a, b, c, d, e, f, g;
	public:
		inline Vector7d(const std::double_t& a = 0.0, const std::double_t& b = 0.0, const std::double_t& c = 0.0, const std::double_t& d = 0.0,
			const std::double_t& e = 0.0, const std::double_t& f = 0.0, const std::double_t& g = 0.0) noexcept;
		// copy
		inline Vector7d(const Vector7d& other) noexcept;
		inline Vector7d& operator=(const Vector7d& other) noexcept;
		// move
		inline Vector7d(Vector7d&& other) noexcept;
		inline Vector7d& operator=(Vector7d&& other) noexcept;
		// assignment
		inline Vector7d& operator=(const std::double_t& number) noexcept;
		
		// math operator
		inline Vector7d operator +(const Vector7d& v) const noexcept;
		inline Vector7d operator -(const Vector7d& v) const noexcept;
		inline Vector7d operator *(const Vector7d& v) const noexcept;
		inline Vector7d operator /(const Vector7d& v) const noexcept;
		
		inline Vector7d operator +(const std::double_t& number) const noexcept;
		inline Vector7d operator -(const std::double_t& number) const noexcept;
		inline Vector7d operator *(const std::double_t& number) const noexcept;
		inline Vector7d operator /(const std::double_t& number) const noexcept;
		
		// increment / decrement
		inline Vector7d& operator++ () noexcept;		// prefix increment
		inline Vector7d& operator-- () noexcept;		// prefix decrement
		inline Vector7d  operator++ (int) noexcept;		// postfix increment
		inline Vector7d  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7d& operator+= (const Vector7d& right) noexcept;
		inline Vector7d& operator-= (const Vector7d& right) noexcept;
		inline Vector7d& operator*= (const Vector7d& right) noexcept;
		inline Vector7d& operator/= (const Vector7d& right) noexcept;
		
		inline Vector7d& operator+= (const std::double_t& number) noexcept;
		inline Vector7d& operator-= (const std::double_t& number) noexcept;
		inline Vector7d& operator*= (const std::double_t& number) noexcept;
		inline Vector7d& operator/= (const std::double_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7d& other) const noexcept;
		inline bool operator<  (const Vector7d& other) const noexcept;
		inline bool operator>  (const Vector7d& other) const noexcept;
		inline bool operator>= (const Vector7d& other) const noexcept;
		
		inline bool operator<  (const std::double_t& number) const noexcept;
		inline bool operator<= (const std::double_t& number) const noexcept;
		inline bool operator>  (const std::double_t& number) const noexcept;
		inline bool operator>= (const std::double_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7d& other) const noexcept;
		inline bool operator!=(const Vector7d& other) const noexcept;
		inline bool operator==(const std::double_t& number)  const noexcept;
		inline bool operator!=(const std::double_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::double_t& stnd_value = 0.0) noexcept;
		inline std::double_t& operator[](const std::uint8_t& index) noexcept;
		inline std::double_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector8d
	{
	public:
		std::double_t a, b, c, d, e, f, g, h;
	public:
		inline Vector8d(const std::double_t& a = 0.0, const std::double_t& b = 0.0, const std::double_t& c = 0.0, const std::double_t& d = 0.0,
			const std::double_t& e = 0.0, const std::double_t& f = 0.0, const std::double_t& g = 0.0, const std::double_t& h = 0.0) noexcept;
		// copy
		inline Vector8d(const Vector8d& other) noexcept;
		inline Vector8d& operator=(const Vector8d& other) noexcept;
		// move
		inline Vector8d(Vector8d&& other) noexcept;
		inline Vector8d& operator=(Vector8d&& other) noexcept;
		// assignment
		inline Vector8d& operator=(const std::double_t& number) noexcept;
		
		// math operator
		inline Vector8d operator +(const Vector8d& v) const noexcept;
		inline Vector8d operator -(const Vector8d& v) const noexcept;
		inline Vector8d operator *(const Vector8d& v) const noexcept;
		inline Vector8d operator /(const Vector8d& v) const noexcept;
		
		inline Vector8d operator +(const std::double_t& number) const noexcept;
		inline Vector8d operator -(const std::double_t& number) const noexcept;
		inline Vector8d operator *(const std::double_t& number) const noexcept;
		inline Vector8d operator /(const std::double_t& number) const noexcept;
		
		// increment / decrement
		inline Vector8d& operator++ () noexcept;		// prefix increment
		inline Vector8d& operator-- () noexcept;		// prefix decrement
		inline Vector8d  operator++ (int) noexcept;		// postfix increment
		inline Vector8d  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8d& operator+= (const Vector8d& right) noexcept;
		inline Vector8d& operator-= (const Vector8d& right) noexcept;
		inline Vector8d& operator*= (const Vector8d& right) noexcept;
		inline Vector8d& operator/= (const Vector8d& right) noexcept;
		
		inline Vector8d& operator+= (const std::double_t& number) noexcept;
		inline Vector8d& operator-= (const std::double_t& number) noexcept;
		inline Vector8d& operator*= (const std::double_t& number) noexcept;
		inline Vector8d& operator/= (const std::double_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8d& other) const noexcept;
		inline bool operator<  (const Vector8d& other) const noexcept;
		inline bool operator>  (const Vector8d& other) const noexcept;
		inline bool operator>= (const Vector8d& other) const noexcept;
		
		inline bool operator<  (const std::double_t& number) const noexcept;
		inline bool operator<= (const std::double_t& number) const noexcept;
		inline bool operator>  (const std::double_t& number) const noexcept;
		inline bool operator>= (const std::double_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8d& other) const noexcept;
		inline bool operator!=(const Vector8d& other) const noexcept;
		inline bool operator==(const std::double_t& number)  const noexcept;
		inline bool operator!=(const std::double_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::double_t& stnd_value = 0.0) noexcept;
		inline std::double_t& operator[](const std::uint8_t& index) noexcept;
		inline std::double_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector9d
	{
	public:
		std::double_t a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9d(const std::double_t& a = 0.0, const std::double_t& b = 0.0, const std::double_t& c = 0.0, const std::double_t& d = 0.0,
			const std::double_t& e = 0.0, const std::double_t& f = 0.0, const std::double_t& g = 0.0, const std::double_t& h = 0.0,
			const std::double_t& i = 0.0) noexcept;
		// copy
		inline Vector9d(const Vector9d& other) noexcept;
		inline Vector9d& operator=(const Vector9d& other) noexcept;
		// move
		inline Vector9d(Vector9d&& other) noexcept;
		inline Vector9d& operator=(Vector9d&& other) noexcept;
		// assignment
		inline Vector9d& operator=(const std::double_t& number) noexcept;
		
		// math operator
		inline Vector9d operator +(const Vector9d& v) const noexcept;
		inline Vector9d operator -(const Vector9d& v) const noexcept;
		inline Vector9d operator *(const Vector9d& v) const noexcept;
		inline Vector9d operator /(const Vector9d& v) const noexcept;
		
		inline Vector9d operator +(const std::double_t& number) const noexcept;
		inline Vector9d operator -(const std::double_t& number) const noexcept;
		inline Vector9d operator *(const std::double_t& number) const noexcept;
		inline Vector9d operator /(const std::double_t& number) const noexcept;
		
		// increment / decrement
		inline Vector9d& operator++ () noexcept;		// prefix increment
		inline Vector9d& operator-- () noexcept;		// prefix decrement
		inline Vector9d  operator++ (int) noexcept;		// postfix increment
		inline Vector9d  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9d& operator+= (const Vector9d& right) noexcept;
		inline Vector9d& operator-= (const Vector9d& right) noexcept;
		inline Vector9d& operator*= (const Vector9d& right) noexcept;
		inline Vector9d& operator/= (const Vector9d& right) noexcept;
		
		inline Vector9d& operator+= (const std::double_t& number) noexcept;
		inline Vector9d& operator-= (const std::double_t& number) noexcept;
		inline Vector9d& operator*= (const std::double_t& number) noexcept;
		inline Vector9d& operator/= (const std::double_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9d& other) const noexcept;
		inline bool operator<  (const Vector9d& other) const noexcept;
		inline bool operator>  (const Vector9d& other) const noexcept;
		inline bool operator>= (const Vector9d& other) const noexcept;
		
		inline bool operator<  (const std::double_t& number) const noexcept;
		inline bool operator<= (const std::double_t& number) const noexcept;
		inline bool operator>  (const std::double_t& number) const noexcept;
		inline bool operator>= (const std::double_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9d& other) const noexcept;
		inline bool operator!=(const Vector9d& other) const noexcept;
		inline bool operator==(const std::double_t& number)  const noexcept;
		inline bool operator!=(const std::double_t& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::double_t& stnd_value = 0.0) noexcept;
		inline std::double_t& operator[](const std::uint8_t& index) noexcept;
		inline std::double_t& at(const std::uint8_t& index) noexcept;
	};


	class Vector10d
	{
	public:
		std::double_t a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10d(const std::double_t& a = 0.0, const std::double_t& b = 0.0, const std::double_t& c = 0.0, const std::double_t& d = 0.0,
			const std::double_t& e = 0.0, const std::double_t& f = 0.0, const std::double_t& g = 0.0, const std::double_t& h = 0.0,
			const std::double_t& i = 0.0, const std::double_t& j = 0.0) noexcept;
		// copy
		inline Vector10d(const Vector10d& other) noexcept;
		inline Vector10d& operator=(const Vector10d& other) noexcept;
		// move
		inline Vector10d(Vector10d&& other) noexcept;
		inline Vector10d& operator=(Vector10d&& other) noexcept;
		// assignment
		inline Vector10d& operator=(const std::double_t& number) noexcept;
		
		// math operator
		inline Vector10d operator +(const Vector10d& v) const noexcept;
		inline Vector10d operator -(const Vector10d& v) const noexcept;
		inline Vector10d operator *(const Vector10d& v) const noexcept;
		inline Vector10d operator /(const Vector10d& v) const noexcept;
		
		inline Vector10d operator +(const std::double_t& number) const noexcept;
		inline Vector10d operator -(const std::double_t& number) const noexcept;
		inline Vector10d operator *(const std::double_t& number) const noexcept;
		inline Vector10d operator /(const std::double_t& number) const noexcept;
		
		// increment / decrement
		inline Vector10d& operator++ () noexcept;		// prefix increment
		inline Vector10d& operator-- () noexcept;		// prefix decrement
		inline Vector10d  operator++ (int) noexcept;	// postfix increment
		inline Vector10d  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10d& operator+= (const Vector10d& right) noexcept;
		inline Vector10d& operator-= (const Vector10d& right) noexcept;
		inline Vector10d& operator*= (const Vector10d& right) noexcept;
		inline Vector10d& operator/= (const Vector10d& right) noexcept;
		
		inline Vector10d& operator+= (const std::double_t& number) noexcept;
		inline Vector10d& operator-= (const std::double_t& number) noexcept;
		inline Vector10d& operator*= (const std::double_t& number) noexcept;
		inline Vector10d& operator/= (const std::double_t& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10d& other) const noexcept;
		inline bool operator<  (const Vector10d& other) const noexcept;
		inline bool operator>  (const Vector10d& other) const noexcept;
		inline bool operator>= (const Vector10d& other) const noexcept;

		inline bool operator<  (const std::double_t& number) const noexcept;
		inline bool operator<= (const std::double_t& number) const noexcept;
		inline bool operator>  (const std::double_t& number) const noexcept;
		inline bool operator>= (const std::double_t& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10d& other) const noexcept;
		inline bool operator!=(const Vector10d& other) const noexcept;
		inline bool operator==(const std::double_t& number)   const noexcept;
		inline bool operator!=(const std::double_t& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const std::double_t& stnd_value = 0.0) noexcept;
		inline std::double_t& operator[](const std::uint8_t& index) noexcept;
		inline std::double_t& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2d& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3d& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4d& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5d& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6d& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7d& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8d& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9d& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10d& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}