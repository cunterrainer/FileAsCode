#pragma once
#include <iostream>
#include <cstdint>
#include <cmath>

namespace util::math {

	/*
		According to the MSVC C++ specification for Windows 10.
		Bytes and the associated Range may differ with other specifications
		but are also dependent on the compiler and platform.

		Type : bool
		Bytes: 1
		Range: true or false
	*/

	class Vector2b
	{
	public:
		bool x, y;
	public:
		inline Vector2b(const bool& x = false, const bool& y = false) noexcept;
		// copy
		inline Vector2b(const Vector2b& other) noexcept;
		inline Vector2b& operator=(const Vector2b& other) noexcept;
		// move
		inline Vector2b(Vector2b&& other) noexcept;
		inline Vector2b& operator=(Vector2b&& other) noexcept;
		// assignment
		inline Vector2b& operator=(const bool& number) noexcept;

		// math operator
		inline Vector2b operator +(const Vector2b& v) const noexcept;
		inline Vector2b operator -(const Vector2b& v) const noexcept;
		inline Vector2b operator *(const Vector2b& v) const noexcept;
		inline Vector2b operator /(const Vector2b& v) const noexcept;

		inline Vector2b operator +(const bool& number) const noexcept;
		inline Vector2b operator -(const bool& number) const noexcept;
		inline Vector2b operator *(const bool& number) const noexcept;
		inline Vector2b operator /(const bool& number) const noexcept;

		// increment / decrement
		inline Vector2b& operator++ () noexcept;		// prefix increment
		inline Vector2b& operator-- () noexcept;		// prefix decrement
		inline Vector2b  operator++ (int) noexcept;		// postfix increment
		inline Vector2b  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector2b& operator+= (const Vector2b& right) noexcept;
		inline Vector2b& operator-= (const Vector2b& right) noexcept;
		inline Vector2b& operator*= (const Vector2b& right) noexcept;
		inline Vector2b& operator/= (const Vector2b& right) noexcept;

		inline Vector2b& operator+= (const bool& number) noexcept;
		inline Vector2b& operator-= (const bool& number) noexcept;
		inline Vector2b& operator*= (const bool& number) noexcept;
		inline Vector2b& operator/= (const bool& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector2b& other) const noexcept;
		inline bool operator<=  (const Vector2b& other) const noexcept;
		inline bool operator>	(const Vector2b& other) const noexcept;
		inline bool operator>=  (const Vector2b& other) const noexcept;

		inline bool operator<	(const bool& number) const noexcept;
		inline bool operator<=  (const bool& number) const noexcept;
		inline bool operator>	(const bool& number) const noexcept;
		inline bool operator>=  (const bool& number) const noexcept;

		// equal / not equal
		inline bool operator==(const Vector2b& other) const noexcept;
		inline bool operator!=(const Vector2b& other) const noexcept;
		inline bool operator==(const bool& number)  const noexcept;
		inline bool operator!=(const bool& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const bool& stnd_value = false) noexcept;
		inline bool& operator[](const std::uint8_t& index) noexcept;
		inline bool& at(const std::uint8_t& index) noexcept;
	};


	class Vector3b
	{
	public:
		bool x, y, z;
	public:
		inline Vector3b(const bool& x = false, const bool& y = false, const bool& z = false) noexcept;
		// copy
		inline Vector3b(const Vector3b& other) noexcept;
		inline Vector3b& operator=(const Vector3b& other) noexcept;
		// move
		inline Vector3b(Vector3b&& other) noexcept;
		inline Vector3b& operator=(Vector3b&& other) noexcept;
		// assignment
		inline Vector3b& operator=(const bool& number) noexcept;

		// math operator
		inline Vector3b operator +(const Vector3b& v) const noexcept;
		inline Vector3b operator -(const Vector3b& v) const noexcept;
		inline Vector3b operator *(const Vector3b& v) const noexcept;
		inline Vector3b operator /(const Vector3b& v) const noexcept;

		inline Vector3b operator +(const bool& number) const noexcept;
		inline Vector3b operator -(const bool& number) const noexcept;
		inline Vector3b operator *(const bool& number) const noexcept;
		inline Vector3b operator /(const bool& number) const noexcept;

		// increment / decrement
		inline Vector3b& operator++ () noexcept;		// prefix increment
		inline Vector3b& operator-- () noexcept;		// prefix decrement
		inline Vector3b  operator++ (int) noexcept;		// postfix increment
		inline Vector3b  operator-- (int) noexcept;		// postfix decrement

		// assignments
		inline Vector3b& operator+= (const Vector3b& right) noexcept;
		inline Vector3b& operator-= (const Vector3b& right) noexcept;
		inline Vector3b& operator*= (const Vector3b& right) noexcept;
		inline Vector3b& operator/= (const Vector3b& right) noexcept;

		inline Vector3b& operator+= (const bool& number) noexcept;
		inline Vector3b& operator-= (const bool& number) noexcept;
		inline Vector3b& operator*= (const bool& number) noexcept;
		inline Vector3b& operator/= (const bool& number) noexcept;

		// less than / greater than
		inline bool operator<	(const Vector3b& other) const noexcept;
		inline bool operator<=  (const Vector3b& other) const noexcept;
		inline bool operator>	(const Vector3b& other) const noexcept;
		inline bool operator>=  (const Vector3b& other) const noexcept;
		 
		inline bool operator<	(const bool& number) const noexcept;
		inline bool operator<=  (const bool& number) const noexcept;
		inline bool operator>	(const bool& number) const noexcept;
		inline bool operator>=  (const bool& number) const noexcept;
		 
		// equal / not equal
		inline bool operator==(const Vector3b& other) const noexcept;
		inline bool operator!=(const Vector3b& other) const noexcept;
		inline bool operator==(const bool& number)  const noexcept;
		inline bool operator!=(const bool& number)  const noexcept;

		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const bool& stnd_value = false) noexcept;
		inline bool& operator[](const std::uint8_t& index) noexcept;
		inline bool& at(const std::uint8_t& index) noexcept;
	};


	class Vector4b
	{
	public:
		bool a, b, c, d;
	public:
		inline Vector4b(const bool& a = false, const bool& b = false, const bool& c = false, const bool& d = false) noexcept;
		// copy
		inline Vector4b(const Vector4b& other) noexcept;
		inline Vector4b& operator=(const Vector4b& other) noexcept;
		// move
		inline Vector4b(Vector4b&& other) noexcept;
		inline Vector4b& operator=(Vector4b&& other) noexcept;
		// assignment
		inline Vector4b& operator=(const bool& number) noexcept;
		
		// math operator
		inline Vector4b operator +(const Vector4b& v) const noexcept;
		inline Vector4b operator -(const Vector4b& v) const noexcept;
		inline Vector4b operator *(const Vector4b& v) const noexcept;
		inline Vector4b operator /(const Vector4b& v) const noexcept;
		
		inline Vector4b operator +(const bool& number) const noexcept;
		inline Vector4b operator -(const bool& number) const noexcept;
		inline Vector4b operator *(const bool& number) const noexcept;
		inline Vector4b operator /(const bool& number) const noexcept;
		
		// increment / decrement
		inline Vector4b& operator++ () noexcept;		// prefix increment
		inline Vector4b& operator-- () noexcept;		// prefix decrement
		inline Vector4b  operator++ (int) noexcept;		// postfix increment
		inline Vector4b  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector4b& operator+= (const Vector4b& right) noexcept;
		inline Vector4b& operator-= (const Vector4b& right) noexcept;
		inline Vector4b& operator*= (const Vector4b& right) noexcept;
		inline Vector4b& operator/= (const Vector4b& right) noexcept;
		
		inline Vector4b& operator+= (const bool& number) noexcept;
		inline Vector4b& operator-= (const bool& number) noexcept;
		inline Vector4b& operator*= (const bool& number) noexcept;
		inline Vector4b& operator/= (const bool& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector4b& other) const noexcept;
		inline bool operator<=  (const Vector4b& other) const noexcept;
		inline bool operator>	(const Vector4b& other) const noexcept;
		inline bool operator>=  (const Vector4b& other) const noexcept;
		
		inline bool operator<	(const bool& number) const noexcept;
		inline bool operator<=  (const bool& number) const noexcept;
		inline bool operator>	(const bool& number) const noexcept;
		inline bool operator>=  (const bool& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector4b& other) const noexcept;
		inline bool operator!=(const Vector4b& other) const noexcept;
		inline bool operator==(const bool& number)  const noexcept;
		inline bool operator!=(const bool& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const bool& stnd_value = false) noexcept;
		inline bool& operator[](const std::uint8_t& index) noexcept;
		inline bool& at(const std::uint8_t& index) noexcept;
	};


	class Vector5b
	{
	public:
		bool a, b, c, d, e;
	public:
		inline Vector5b(const bool& a = false, const bool& b = false, const bool& c = false, const bool& d = false,
			const bool& e = false) noexcept;
		// copy
		inline Vector5b(const Vector5b& other) noexcept;
		inline Vector5b& operator=(const Vector5b& other) noexcept;
		// move
		inline Vector5b(Vector5b&& other) noexcept;
		inline Vector5b& operator=(Vector5b&& other) noexcept;
		// assignment
		inline Vector5b& operator=(const bool& number) noexcept;
		 
		// math operator
		inline Vector5b operator +(const Vector5b& v) const noexcept;
		inline Vector5b operator -(const Vector5b& v) const noexcept;
		inline Vector5b operator *(const Vector5b& v) const noexcept;
		inline Vector5b operator /(const Vector5b& v) const noexcept;
		
		inline Vector5b operator +(const bool& number) const noexcept;
		inline Vector5b operator -(const bool& number) const noexcept;
		inline Vector5b operator *(const bool& number) const noexcept;
		inline Vector5b operator /(const bool& number) const noexcept;
		
		// increment / decrement
		inline Vector5b& operator++ () noexcept;		// prefix increment
		inline Vector5b& operator-- () noexcept;		// prefix decrement
		inline Vector5b  operator++ (int) noexcept;		// postfix increment
		inline Vector5b  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector5b& operator+= (const Vector5b& right) noexcept;
		inline Vector5b& operator-= (const Vector5b& right) noexcept;
		inline Vector5b& operator*= (const Vector5b& right) noexcept;
		inline Vector5b& operator/= (const Vector5b& right) noexcept;
		
		inline Vector5b& operator+= (const bool& number) noexcept;
		inline Vector5b& operator-= (const bool& number) noexcept;
		inline Vector5b& operator*= (const bool& number) noexcept;
		inline Vector5b& operator/= (const bool& number) noexcept;
		
		// less than / greater than
		inline bool operator<	(const Vector5b& other) const noexcept;
		inline bool operator<=  (const Vector5b& other) const noexcept;
		inline bool operator>	(const Vector5b& other) const noexcept;
		inline bool operator>=  (const Vector5b& other) const noexcept;
		
		inline bool operator<	(const bool& number) const noexcept;
		inline bool operator<=  (const bool& number) const noexcept;
		inline bool operator>	(const bool& number) const noexcept;
		inline bool operator>=  (const bool& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector5b& other) const noexcept;
		inline bool operator!=(const Vector5b& other) const noexcept;
		inline bool operator==(const bool& number)  const noexcept;
		inline bool operator!=(const bool& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const bool& stnd_value = false) noexcept;
		inline bool& operator[](const std::uint8_t& index) noexcept;
		inline bool& at(const std::uint8_t& index) noexcept;
	};


	class Vector6b
	{
	public:
		bool a, b, c, d, e, f;
	public:
		inline Vector6b(const bool& a = false, const bool& b = false, const bool& c = false, const bool& d = false,
			const bool& e = false, const bool& f = false) noexcept;
		// copy
		inline Vector6b(const Vector6b& other) noexcept;
		inline Vector6b& operator=(const Vector6b& other) noexcept;
		// move
		inline Vector6b(Vector6b&& other) noexcept;
		inline Vector6b& operator=(Vector6b&& other) noexcept;
		// assignment
		inline Vector6b& operator=(const bool& number) noexcept;
		
		// math operator
		inline Vector6b operator +(const Vector6b& v) const noexcept;
		inline Vector6b operator -(const Vector6b& v) const noexcept;
		inline Vector6b operator *(const Vector6b& v) const noexcept;
		inline Vector6b operator /(const Vector6b& v) const noexcept;
		
		inline Vector6b operator +(const bool& number) const noexcept;
		inline Vector6b operator -(const bool& number) const noexcept;
		inline Vector6b operator *(const bool& number) const noexcept;
		inline Vector6b operator /(const bool& number) const noexcept;
		
		// increment / decrement
		inline Vector6b& operator++ () noexcept;		// prefix increment
		inline Vector6b& operator-- () noexcept;		// prefix decrement
		inline Vector6b  operator++ (int) noexcept;		// postfix increment
		inline Vector6b  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector6b& operator+= (const Vector6b& right) noexcept;
		inline Vector6b& operator-= (const Vector6b& right) noexcept;
		inline Vector6b& operator*= (const Vector6b& right) noexcept;
		inline Vector6b& operator/= (const Vector6b& right) noexcept;
		
		inline Vector6b& operator+= (const bool& number) noexcept;
		inline Vector6b& operator-= (const bool& number) noexcept;
		inline Vector6b& operator*= (const bool& number) noexcept;
		inline Vector6b& operator/= (const bool& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector6b& other) const noexcept;
		inline bool operator<  (const Vector6b& other) const noexcept;
		inline bool operator>  (const Vector6b& other) const noexcept;
		inline bool operator>= (const Vector6b& other) const noexcept;
		
		inline bool operator<  (const bool& number) const noexcept;
		inline bool operator<= (const bool& number) const noexcept;
		inline bool operator>  (const bool& number) const noexcept;
		inline bool operator>= (const bool& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector6b& other) const noexcept;
		inline bool operator!=(const Vector6b& other) const noexcept;
		inline bool operator==(const bool& number)  const noexcept;
		inline bool operator!=(const bool& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const bool& stnd_value = false) noexcept;
		inline bool& operator[](const std::uint8_t& index) noexcept;
		inline bool& at(const std::uint8_t& index) noexcept;
	};


	class Vector7b
	{
	public:
		bool a, b, c, d, e, f, g;
	public:
		inline Vector7b(const bool& a = false, const bool& b = false, const bool& c = false, const bool& d = false,
			const bool& e = false, const bool& f = false, const bool& g = false) noexcept;
		// copy
		inline Vector7b(const Vector7b& other) noexcept;
		inline Vector7b& operator=(const Vector7b& other) noexcept;
		// move
		inline Vector7b(Vector7b&& other) noexcept;
		inline Vector7b& operator=(Vector7b&& other) noexcept;
		// assignment
		inline Vector7b& operator=(const bool& number) noexcept;
		
		// math operator
		inline Vector7b operator +(const Vector7b& v) const noexcept;
		inline Vector7b operator -(const Vector7b& v) const noexcept;
		inline Vector7b operator *(const Vector7b& v) const noexcept;
		inline Vector7b operator /(const Vector7b& v) const noexcept;
		
		inline Vector7b operator +(const bool& number) const noexcept;
		inline Vector7b operator -(const bool& number) const noexcept;
		inline Vector7b operator *(const bool& number) const noexcept;
		inline Vector7b operator /(const bool& number) const noexcept;
		
		// increment / decrement
		inline Vector7b& operator++ () noexcept;		// prefix increment
		inline Vector7b& operator-- () noexcept;		// prefix decrement
		inline Vector7b  operator++ (int) noexcept;		// postfix increment
		inline Vector7b  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector7b& operator+= (const Vector7b& right) noexcept;
		inline Vector7b& operator-= (const Vector7b& right) noexcept;
		inline Vector7b& operator*= (const Vector7b& right) noexcept;
		inline Vector7b& operator/= (const Vector7b& right) noexcept;
		
		inline Vector7b& operator+= (const bool& number) noexcept;
		inline Vector7b& operator-= (const bool& number) noexcept;
		inline Vector7b& operator*= (const bool& number) noexcept;
		inline Vector7b& operator/= (const bool& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector7b& other) const noexcept;
		inline bool operator<  (const Vector7b& other) const noexcept;
		inline bool operator>  (const Vector7b& other) const noexcept;
		inline bool operator>= (const Vector7b& other) const noexcept;
		
		inline bool operator<  (const bool& number) const noexcept;
		inline bool operator<= (const bool& number) const noexcept;
		inline bool operator>  (const bool& number) const noexcept;
		inline bool operator>= (const bool& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector7b& other) const noexcept;
		inline bool operator!=(const Vector7b& other) const noexcept;
		inline bool operator==(const bool& number)  const noexcept;
		inline bool operator!=(const bool& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const bool& stnd_value = false) noexcept;
		inline bool& operator[](const std::uint8_t& index) noexcept;
		inline bool& at(const std::uint8_t& index) noexcept;
	};


	class Vector8b
	{
	public:
		bool a, b, c, d, e, f, g, h;
	public:
		inline Vector8b(const bool& a = false, const bool& b = false, const bool& c = false, const bool& d = false,
			const bool& e = false, const bool& f = false, const bool& g = false, const bool& h = false) noexcept;
		// copy
		inline Vector8b(const Vector8b& other) noexcept;
		inline Vector8b& operator=(const Vector8b& other) noexcept;
		// move
		inline Vector8b(Vector8b&& other) noexcept;
		inline Vector8b& operator=(Vector8b&& other) noexcept;
		// assignment
		inline Vector8b& operator=(const bool& number) noexcept;
		
		// math operator
		inline Vector8b operator +(const Vector8b& v) const noexcept;
		inline Vector8b operator -(const Vector8b& v) const noexcept;
		inline Vector8b operator *(const Vector8b& v) const noexcept;
		inline Vector8b operator /(const Vector8b& v) const noexcept;
		
		inline Vector8b operator +(const bool& number) const noexcept;
		inline Vector8b operator -(const bool& number) const noexcept;
		inline Vector8b operator *(const bool& number) const noexcept;
		inline Vector8b operator /(const bool& number) const noexcept;
		
		// increment / decrement
		inline Vector8b& operator++ () noexcept;		// prefix increment
		inline Vector8b& operator-- () noexcept;		// prefix decrement
		inline Vector8b  operator++ (int) noexcept;		// postfix increment
		inline Vector8b  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector8b& operator+= (const Vector8b& right) noexcept;
		inline Vector8b& operator-= (const Vector8b& right) noexcept;
		inline Vector8b& operator*= (const Vector8b& right) noexcept;
		inline Vector8b& operator/= (const Vector8b& right) noexcept;
		
		inline Vector8b& operator+= (const bool& number) noexcept;
		inline Vector8b& operator-= (const bool& number) noexcept;
		inline Vector8b& operator*= (const bool& number) noexcept;
		inline Vector8b& operator/= (const bool& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector8b& other) const noexcept;
		inline bool operator<  (const Vector8b& other) const noexcept;
		inline bool operator>  (const Vector8b& other) const noexcept;
		inline bool operator>= (const Vector8b& other) const noexcept;
		
		inline bool operator<  (const bool& number) const noexcept;
		inline bool operator<= (const bool& number) const noexcept;
		inline bool operator>  (const bool& number) const noexcept;
		inline bool operator>= (const bool& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector8b& other) const noexcept;
		inline bool operator!=(const Vector8b& other) const noexcept;
		inline bool operator==(const bool& number)  const noexcept;
		inline bool operator!=(const bool& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const bool& stnd_value = false) noexcept;
		inline bool& operator[](const std::uint8_t& index) noexcept;
		inline bool& at(const std::uint8_t& index) noexcept;
	};


	class Vector9b
	{
	public:
		bool a, b, c, d, e, f, g, h, i;
	public:
		inline Vector9b(const bool& a = false, const bool& b = false, const bool& c = false, const bool& d = false,
			const bool& e = false, const bool& f = false, const bool& g = false, const bool& h = false,
			const bool& i = false) noexcept;
		// copy
		inline Vector9b(const Vector9b& other) noexcept;
		inline Vector9b& operator=(const Vector9b& other) noexcept;
		// move
		inline Vector9b(Vector9b&& other) noexcept;
		inline Vector9b& operator=(Vector9b&& other) noexcept;
		// assignment
		inline Vector9b& operator=(const bool& number) noexcept;
		
		// math operator
		inline Vector9b operator +(const Vector9b& v) const noexcept;
		inline Vector9b operator -(const Vector9b& v) const noexcept;
		inline Vector9b operator *(const Vector9b& v) const noexcept;
		inline Vector9b operator /(const Vector9b& v) const noexcept;
		
		inline Vector9b operator +(const bool& number) const noexcept;
		inline Vector9b operator -(const bool& number) const noexcept;
		inline Vector9b operator *(const bool& number) const noexcept;
		inline Vector9b operator /(const bool& number) const noexcept;
		
		// increment / decrement
		inline Vector9b& operator++ () noexcept;		// prefix increment
		inline Vector9b& operator-- () noexcept;		// prefix decrement
		inline Vector9b  operator++ (int) noexcept;		// postfix increment
		inline Vector9b  operator-- (int) noexcept;		// postfix decrement
		
		// assignments
		inline Vector9b& operator+= (const Vector9b& right) noexcept;
		inline Vector9b& operator-= (const Vector9b& right) noexcept;
		inline Vector9b& operator*= (const Vector9b& right) noexcept;
		inline Vector9b& operator/= (const Vector9b& right) noexcept;
		
		inline Vector9b& operator+= (const bool& number) noexcept;
		inline Vector9b& operator-= (const bool& number) noexcept;
		inline Vector9b& operator*= (const bool& number) noexcept;
		inline Vector9b& operator/= (const bool& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector9b& other) const noexcept;
		inline bool operator<  (const Vector9b& other) const noexcept;
		inline bool operator>  (const Vector9b& other) const noexcept;
		inline bool operator>= (const Vector9b& other) const noexcept;
		
		inline bool operator<  (const bool& number) const noexcept;
		inline bool operator<= (const bool& number) const noexcept;
		inline bool operator>  (const bool& number) const noexcept;
		inline bool operator>= (const bool& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector9b& other) const noexcept;
		inline bool operator!=(const Vector9b& other) const noexcept;
		inline bool operator==(const bool& number)  const noexcept;
		inline bool operator!=(const bool& number)  const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const bool& stnd_value = false) noexcept;
		inline bool& operator[](const std::uint8_t& index) noexcept;
		inline bool& at(const std::uint8_t& index) noexcept;
	};


	class Vector10b
	{
	public:
		bool a, b, c, d, e, f, g, h, i, j;
	public:
		inline Vector10b(const bool& a = false, const bool& b = false, const bool& c = false, const bool& d = false,
			const bool& e = false, const bool& f = false, const bool& g = false, const bool& h = false,
			const bool& i = false, const bool& j = false) noexcept;
		// copy
		inline Vector10b(const Vector10b& other) noexcept;
		inline Vector10b& operator=(const Vector10b& other) noexcept;
		// move
		inline Vector10b(Vector10b&& other) noexcept;
		inline Vector10b& operator=(Vector10b&& other) noexcept;
		// assignment
		inline Vector10b& operator=(const bool& number) noexcept;
		
		// math operator
		inline Vector10b operator +(const Vector10b& v) const noexcept;
		inline Vector10b operator -(const Vector10b& v) const noexcept;
		inline Vector10b operator *(const Vector10b& v) const noexcept;
		inline Vector10b operator /(const Vector10b& v) const noexcept;
		
		inline Vector10b operator +(const bool& number) const noexcept;
		inline Vector10b operator -(const bool& number) const noexcept;
		inline Vector10b operator *(const bool& number) const noexcept;
		inline Vector10b operator /(const bool& number) const noexcept;
		
		// increment / decrement
		inline Vector10b& operator++ () noexcept;		// prefix increment
		inline Vector10b& operator-- () noexcept;		// prefix decrement
		inline Vector10b  operator++ (int) noexcept;	// postfix increment
		inline Vector10b  operator-- (int) noexcept;	// postfix decrement
		
		// assignments
		inline Vector10b& operator+= (const Vector10b& right) noexcept;
		inline Vector10b& operator-= (const Vector10b& right) noexcept;
		inline Vector10b& operator*= (const Vector10b& right) noexcept;
		inline Vector10b& operator/= (const Vector10b& right) noexcept;
		
		inline Vector10b& operator+= (const bool& number) noexcept;
		inline Vector10b& operator-= (const bool& number) noexcept;
		inline Vector10b& operator*= (const bool& number) noexcept;
		inline Vector10b& operator/= (const bool& number) noexcept;
		
		// less than / greater than
		inline bool operator<= (const Vector10b& other) const noexcept;
		inline bool operator<  (const Vector10b& other) const noexcept;
		inline bool operator>  (const Vector10b& other) const noexcept;
		inline bool operator>= (const Vector10b& other) const noexcept;

		inline bool operator<  (const bool& number) const noexcept;
		inline bool operator<= (const bool& number) const noexcept;
		inline bool operator>  (const bool& number) const noexcept;
		inline bool operator>= (const bool& number) const noexcept;
		
		// equal / not equal
		inline bool operator==(const Vector10b& other) const noexcept;
		inline bool operator!=(const Vector10b& other) const noexcept;
		inline bool operator==(const bool& number)   const noexcept;
		inline bool operator!=(const bool& number)   const noexcept;
		
		inline constexpr std::uint8_t size() const noexcept;
		inline void reset(const bool& stnd_value = false) noexcept;
		inline bool& operator[](const std::uint8_t& index) noexcept;
		inline bool& at(const std::uint8_t& index) noexcept;
	};


	// overloads for the << operator
	inline static std::ostream& operator<<(std::ostream& os, const Vector2b& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector3b& v) noexcept
	{
		os << "x: " << v.x << " | y: " << v.y << " | z: " << v.z;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector4b& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector5b& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector6b& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector7b& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector8b& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector9b& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i;
		return os;
	}

	inline static std::ostream& operator<<(std::ostream& os, const Vector10b& v) noexcept
	{
		os << "a: " << v.a << " | b: " << v.b << " | c: " << v.c << " | d: " << v.d << " | e: " << v.e << " | f: " << v.f << " | g: " << v.g << " | h: " << v.h << " | i: " << v.i << " | j: " << v.j;
		return os;
	}
	// End
}