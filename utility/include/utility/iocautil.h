#pragma once
#include <string>
#include <vector>
#include <ostream>
#include <cstdint>
#include <functional>
#include <algorithm>
#include <iterator>

// version 2.0

#define IH_NODISCARD [[nodiscard]]
#define IH_LIKELY	 [[likely]]		// requires C++20
#define IH_UNLIKELY  [[unlikely]]	// requires C++20


#define IHI_CXP_AND_INL inline	// iterator
#define IH_CXP_AND_INL	inline	// some functions can always be constexpr no matter of the C++ version

#define IH_CXP_OR_INL   IH_CXP_AND_INL	// some functions can only be constexpr when using C++20 other wise they are inline
#define IHI_CXP_INL		IH_CXP_OR_INL	// constexpr if available (C++ 20) or inline [iterator]
#define IH_CXP_INL		IH_CXP_OR_INL	// constexpr if constexpr is available inline else (C++ 20)

namespace util::io {
	class InputHandler_const_iterator
	{
	private:
		static const std::vector<std::string> m_EmptyVectorBuffer;
		const std::vector<std::string>& m_Vec;
		int m_Idx;

		using MySelf     = InputHandler_const_iterator;
		using MySelfRef  = InputHandler_const_iterator&;
		using MySelfCRef = const InputHandler_const_iterator&;
	public:
		using iterator_category = std::random_access_iterator_tag;

		using value_type      = std::string;
		using difference_type = ptrdiff_t;
		using reference       = const std::string&;
		using pointer         = const std::string*;
	public:
		IHI_CXP_AND_INL InputHandler_const_iterator() : m_Vec(m_EmptyVectorBuffer), m_Idx(0) {};
		IHI_CXP_AND_INL explicit InputHandler_const_iterator(const std::vector<std::string>& vec, int size) noexcept : m_Vec(vec), m_Idx(size) {}

		IH_NODISCARD IHI_CXP_INL reference operator*() const noexcept { return *operator->(); }
		IH_NODISCARD IHI_CXP_INL pointer  operator->() const noexcept { return &m_Vec[m_Idx]; }

		IHI_CXP_AND_INL MySelfRef operator++()    noexcept { ++m_Idx; return *this; }
		IHI_CXP_AND_INL MySelfRef operator--()    noexcept { --m_Idx; return *this; }
		IHI_CXP_AND_INL MySelf    operator++(int) noexcept { MySelf _Tmp = *this; ++m_Idx; return _Tmp; }
		IHI_CXP_AND_INL MySelf    operator--(int) noexcept { MySelf _Tmp = *this; --m_Idx; return _Tmp; }

		IHI_CXP_AND_INL MySelfRef operator+=(const int _Off) noexcept { m_Idx += _Off; return *this; }
		IHI_CXP_AND_INL MySelfRef operator-=(const int _Off) noexcept { m_Idx -= _Off; return *this; }
		IH_NODISCARD IHI_CXP_AND_INL MySelf operator+(const int _Off)    const noexcept { MySelf _Tmp = *this; _Tmp += _Off; return _Tmp; }
		IH_NODISCARD IHI_CXP_AND_INL MySelf operator-(const int _Off)    const noexcept { MySelf _Tmp = *this; _Tmp -= _Off; return _Tmp; }
		IH_NODISCARD IHI_CXP_AND_INL int    operator+(MySelfCRef _Right) const noexcept { return m_Idx + _Right.m_Idx; }
		IH_NODISCARD IHI_CXP_AND_INL int    operator-(MySelfCRef _Right) const noexcept { return m_Idx - _Right.m_Idx; }
		IH_NODISCARD IHI_CXP_INL reference  operator[](const int _Off)   const noexcept { return m_Vec[_Off]; }

		IH_NODISCARD IHI_CXP_AND_INL bool operator==(MySelfCRef _Right) const noexcept { return m_Idx == _Right.m_Idx; }
		IH_NODISCARD IHI_CXP_AND_INL bool operator!=(MySelfCRef _Right) const noexcept { return !(*this == _Right);    }
		IH_NODISCARD IHI_CXP_AND_INL bool operator< (MySelfCRef _Right) const noexcept { return m_Idx < _Right.m_Idx;  }
		IH_NODISCARD IHI_CXP_AND_INL bool operator> (MySelfCRef _Right) const noexcept { return _Right < *this;        }
		IH_NODISCARD IHI_CXP_AND_INL bool operator<=(MySelfCRef _Right) const noexcept { return !(_Right < *this);     }
		IH_NODISCARD IHI_CXP_AND_INL bool operator>=(MySelfCRef _Right) const noexcept { return !(*this < _Right);     }
	};


	class InputHandler_iterator : public InputHandler_const_iterator
	{
	private:
		using MyBase = InputHandler_const_iterator;

		using MySelf    = InputHandler_iterator;
		using MySelfRef = InputHandler_iterator&;
	public:
		using value_type      = std::string;
		using difference_type = ptrdiff_t;
		using reference       = std::string&;
		using pointer         = std::string*;
	public:
		IHI_CXP_AND_INL InputHandler_iterator() noexcept : MyBase() {};
		IHI_CXP_AND_INL explicit InputHandler_iterator(std::vector<std::string>& vec, int size) noexcept : MyBase(vec, size) {}

		IH_NODISCARD IHI_CXP_INL reference operator*() const noexcept { return const_cast<reference>(MyBase::operator*()); }
		IH_NODISCARD IHI_CXP_INL pointer  operator->() const noexcept { return const_cast<pointer>(MyBase::operator->());  }

		IHI_CXP_AND_INL MySelfRef operator++()    noexcept { MyBase::operator++(); return *this; }
		IHI_CXP_AND_INL MySelfRef operator--()    noexcept { MyBase::operator--(); return *this; }
		IHI_CXP_AND_INL MySelf    operator++(int) noexcept { MySelf _Tmp = *this; MyBase::operator++(); return _Tmp; }
		IHI_CXP_AND_INL MySelf    operator--(int) noexcept { MySelf _Tmp = *this; MyBase::operator--(); return _Tmp; }
		
		IHI_CXP_AND_INL MySelfRef operator+=(const int _Off) noexcept { MyBase::operator+=(_Off); return *this; }
		IHI_CXP_AND_INL MySelfRef operator-=(const int _Off) noexcept { MyBase::operator-=(_Off); return *this; }
		IH_NODISCARD IHI_CXP_AND_INL MySelf operator+(const int _Off) const noexcept { MySelf _Tmp = *this; _Tmp += _Off; return _Tmp; }
		IH_NODISCARD IHI_CXP_AND_INL MySelf operator-(const int _Off) const noexcept { MySelf _Tmp = *this; _Tmp -= _Off; return _Tmp; }
		using MyBase::operator+;
		using MyBase::operator-;
		IH_NODISCARD IHI_CXP_INL reference operator[](const int _Off) const noexcept { return const_cast<reference>(MyBase::operator[](_Off)); }
	};



	enum class IHM : std::uint8_t	// InputHandlerMode
	{
		Normal = 0,
		Lower  = 1,
		Upper  = 2
	};

	class InputHandler
	{
	public:
		static constexpr std::uint8_t Empty = 1;
		using iterator = InputHandler_iterator;
		using const_iterator = InputHandler_const_iterator;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;
	private:
		const int m_Size;
		mutable IHM m_SearchMode; // just inorder to use SetSearchMode() for const instances
		std::vector<std::string> m_Inputs;
		std::vector<std::string> m_InputsLower;
		std::vector<std::string> m_InputsUpper;
	private:
		IH_CXP_AND_INL const void SetMode(IHM* mode) const noexcept { *mode = m_SearchMode == IHM::Lower || m_SearchMode == IHM::Upper ? m_SearchMode : *mode; }

		IH_NODISCARD IH_CXP_INL const unsigned int GetIndex(const std::string& str, IHM mode) const noexcept
		{
			SetMode(&mode);
			switch (mode)
			{
			case IHM::Normal:
			{
				for (int i = 0; i < m_Size; ++i)
					if (m_Inputs[i] == str)
						return i;
				return 0;
			}

			IH_LIKELY case IHM::Lower:
			{
				std::string loweredStr = LowerCopy(str);
				for (int i = 0; i < m_Size; ++i)
					if (m_InputsLower[i] == loweredStr)
						return i;
				return 0;
			}

			case IHM::Upper:
			{
				std::string upperedStr = UpperCopy(str);
				for (int i = 0; i < m_Size; ++i)
					if (m_InputsUpper[i] == upperedStr)
						return i;
				return 0;
			}
			default:
				return 0;
			}
		}

		IH_NODISCARD IH_CXP_INL const std::vector<unsigned int> GetIndecies(const std::string& str, IHM mode) const noexcept
		{
			SetMode(&mode);
			std::vector<unsigned int> result;
			switch (mode)
			{
			case IHM::Normal:
			{
				for (int i = 0; i < m_Size; ++i)
					if (m_Inputs[i] == str)
						result.push_back(i);
				break;
			}

			IH_LIKELY case IHM::Lower:
			{
				std::string loweredStr = LowerCopy(str);
				for (int i = 0; i < m_Size; ++i)
					if (m_InputsLower[i] == loweredStr)
						result.push_back(i);
				break;
			}

			case IHM::Upper:
			{
				std::string upperedStr = UpperCopy(str);
				for (int i = 0; i < m_Size; ++i)
					if (m_InputsUpper[i] == upperedStr)
						result.push_back(i);
				break;
			}
			}
			return result;
		}

		IH_NODISCARD inline const std::string& GetString(const unsigned int index, IHM mode) const noexcept
		{
			SetMode(&mode);
			static std::string emptyStr = "";
			if (index >= m_Inputs.size())
				return emptyStr;

			switch (mode)
			{
			case IHM::Normal:
				return m_Inputs[index];

			IH_LIKELY case IHM::Lower:
				return m_InputsLower[index];

			case IHM::Upper:
				return m_InputsUpper[index];
			default:
				return emptyStr;
			}
		}

		template <typename T>
		IH_NODISCARD IH_CXP_AND_INL const bool IsInContainerIndex(const T& cont, const unsigned int index, IHM mode) const noexcept
		{
			const std::string toCheck = GetString(index, mode);
			if (toCheck == "")
				return false;

			for (const std::string& i : cont) {
				if (i == toCheck)
					return true;
			}
			return false;
		}

		template <typename T>
		IH_NODISCARD IH_CXP_AND_INL const bool IsInContainerString(const T& cont, std::string str, IHM mode) const noexcept
		{
			SetMode(&mode);
			IH_UNLIKELY if (str == "")
				return false;

			IH_LIKELY if (mode == IHM::Lower)
				Lower(str);
			else if (mode == IHM::Upper)
				Upper(str);

			for (const std::string& i : cont) {
				IH_UNLIKELY if (i == str)
					return true;
			}
			return false;
		}

		IH_NODISCARD IH_CXP_INL const bool IsInIndex(const std::function<const bool(const std::string&)>& func, const unsigned int index, IHM mode) const noexcept
		{
			IH_UNLIKELY if (index >= static_cast<unsigned int>(Size()))
				return false;

			const std::string str = GetString(index, mode);
			IH_UNLIKELY if (str == "")
				return false;

			return func(str);
		}

		IH_NODISCARD IH_CXP_INL const bool IsInString(const std::function<const bool(const std::string&)>& func, const std::string& str, IHM mode) const noexcept
		{
			SetMode(&mode);
			IH_UNLIKELY if (str == "")
				return false;

			IH_LIKELY if (mode == IHM::Lower)
				return func(LowerCopy(str));
			if (mode == IHM::Upper)
				return func(UpperCopy(str));

			return func(str);
		}

		IH_NODISCARD IH_CXP_INL std::vector<std::string> StringStartsWith(const std::string& str, IHM mode) const noexcept
		{
			SetMode(&mode);
			std::vector<std::string> result;
			switch (mode)
			{
			case IHM::Normal:
			{
				for (int i = 0; i < m_Size; ++i) {
					if (m_Inputs[i].rfind(str, 0) == 0) // pos=0 limits the search to the prefix
						result.push_back(m_Inputs[i]);
				}
				break;
			}

			case IHM::Lower:
			{
				for (int i = 0; i < m_Size; ++i) {
					if (m_InputsLower[i].rfind(str, 0) == 0) // pos=0 limits the search to the prefix
						result.push_back(m_Inputs[i]);
				}
				break;
			}

			case IHM::Upper:
			{
				for (int i = 0; i < m_Size; ++i) {
					if (m_InputsUpper[i].rfind(str, 0) == 0) // pos=0 limits the search to the prefix
						result.push_back(m_Inputs[i]);
				}
				break;
			}
			}
			return result;
		}
	public:
		IH_CXP_INL explicit InputHandler(const int argc, const char** argv) : InputHandler(argc, const_cast<char**>(argv)) {}
		IH_CXP_INL explicit InputHandler(const int argc, char** argv) : m_Size(argc)
		{
			m_Inputs.reserve(argc);
			m_InputsLower.reserve(argc);
			m_InputsUpper.reserve(argc);
			for (int i = 0; i < m_Size; ++i)
			{
				std::string currentArg = argv[i];
				m_Inputs.push_back(currentArg);
				Lower(currentArg); m_InputsLower.push_back(currentArg);
				Upper(currentArg); m_InputsUpper.push_back(currentArg);
			}
		}
		IH_CXP_INL ~InputHandler() = default;
		
		IH_CXP_INL void Lower(std::string& data) const noexcept { std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c) -> int { return std::tolower(c); }); }
		IH_CXP_INL void Upper(std::string& data) const noexcept { std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c) -> int { return std::toupper(c); }); }
		IH_NODISCARD IH_CXP_INL std::string LowerCopy(std::string str) const noexcept { Lower(str); return str; }
		IH_NODISCARD IH_CXP_INL std::string UpperCopy(std::string str) const noexcept { Upper(str); return str; }

		IH_CXP_INL void Lower(std::vector<std::string>& vec) const noexcept { for (std::string& i : vec) Lower(i); }
		IH_CXP_INL void Upper(std::vector<std::string>& vec) const noexcept { for (std::string& i : vec) Upper(i); }
		IH_NODISCARD IH_CXP_INL const std::vector<std::string> LowerCopy(std::vector<std::string> vec) const noexcept { Lower(vec); return vec; }
		IH_NODISCARD IH_CXP_INL const std::vector<std::string> UpperCopy(std::vector<std::string> vec) const noexcept { Upper(vec); return vec; }

		IH_NODISCARD IH_CXP_AND_INL const std::vector<std::string>& GetArguments(IHM mode) const noexcept {
			SetMode(&mode);
			switch (mode) {
			case IHM::Lower:
				return m_InputsLower;
			case IHM::Upper:
				return m_InputsUpper;
			default:
				return m_Inputs;
			}
		}

		IH_NODISCARD inline const long long IsNumber(const char* data) const {
			try {
				long long number = std::stoll(data);
				return number;
			}
			catch (...) {
				return false;
			}
		}

		IH_NODISCARD inline const long double IsFloat(const char* data) const {
			try {
				long double number = std::stold(data);
				return number;
			}
			catch (...) {
				return false;
			}
		}

		IH_NODISCARD IH_CXP_AND_INL int Size() const noexcept { return m_Size; }
		IH_NODISCARD IH_CXP_AND_INL bool IsEmpty() const noexcept { return (m_Size == InputHandler::Empty); }
		IH_CXP_AND_INL void SetSearchMode(const IHM mode) const noexcept { m_SearchMode = mode == IHM::Normal || mode == IHM::Lower || mode == IHM::Upper ? mode : IHM::Normal; }
		IH_NODISCARD IH_CXP_AND_INL IHM GetSearchMode() const noexcept { return m_SearchMode; }

		IH_NODISCARD IH_CXP_INL const std::vector<std::string> StartsWith(const std::string& str) const noexcept { return StringStartsWith(str, IHM::Normal); }
		IH_NODISCARD IH_CXP_INL const std::vector<std::string> StartsWithL(const std::string& str) const noexcept { return StringStartsWith(str, IHM::Lower); }
		IH_NODISCARD IH_CXP_INL const std::vector<std::string> StartsWithU(const std::string& str) const noexcept { return StringStartsWith(str, IHM::Upper); }

		IH_NODISCARD inline const long long IsNumber (const std::string& str) const noexcept { return IsNumber(str.c_str()); }
		IH_NODISCARD inline const long long GetNumber(const std::string& str) const noexcept { return IsNumber(str.c_str()); }
		IH_NODISCARD inline const long long GetNumber(const char* str)        const noexcept { return IsNumber(str);         }

		IH_NODISCARD inline const long double IsFloat (const std::string& str) const noexcept { return IsFloat(str.c_str()); }
		IH_NODISCARD inline const long double GetFloat(const std::string& str) const noexcept { return IsFloat(str.c_str()); }
		IH_NODISCARD inline const long double GetFloat(const char* str)        const noexcept { return IsFloat(str);         }

		// Returns the index of the first occurence of the string
		IH_NODISCARD IH_CXP_INL const unsigned int Get (const std::string& str) const noexcept { return GetIndex(str, IHM::Normal); }
		IH_NODISCARD IH_CXP_INL const unsigned int GetL(const std::string& str) const noexcept { return GetIndex(str, IHM::Lower);  }
		IH_NODISCARD IH_CXP_INL const unsigned int GetU(const std::string& str) const noexcept { return GetIndex(str, IHM::Upper);  }

		IH_NODISCARD IH_CXP_INL const std::vector<unsigned int> GetAll (const std::string& str) const noexcept { return GetIndecies(str, IHM::Normal); }
		IH_NODISCARD IH_CXP_INL const std::vector<unsigned int> GetAllL(const std::string& str) const noexcept { return GetIndecies(str, IHM::Lower);  }
		IH_NODISCARD IH_CXP_INL const std::vector<unsigned int> GetAllU(const std::string& str) const noexcept { return GetIndecies(str, IHM::Upper);  }

		IH_NODISCARD inline const std::string& Get (const unsigned int index) const noexcept { return GetString(index, IHM::Normal); }
		IH_NODISCARD inline const std::string& GetL(const unsigned int index) const noexcept { return GetString(index, IHM::Lower);  }
		IH_NODISCARD inline const std::string& GetU(const unsigned int index) const noexcept { return GetString(index, IHM::Upper);  }

		IH_NODISCARD inline const std::string& operator[](const unsigned int index) const noexcept { return GetString(index, IHM::Normal); }
		IH_NODISCARD IH_CXP_INL const unsigned int operator[](const std::string& str) const noexcept { return GetIndex(str, IHM::Normal); }

		IH_NODISCARD IH_CXP_INL const bool Find (const std::string& str) const noexcept { return GetIndex(str, IHM::Normal); }
		IH_NODISCARD IH_CXP_INL const bool FindL(const std::string& str) const noexcept { return GetIndex(str, IHM::Lower);  }
		IH_NODISCARD IH_CXP_INL const bool FindU(const std::string& str) const noexcept { return GetIndex(str, IHM::Upper);  }

		IH_NODISCARD IH_CXP_INL const bool Find (const unsigned int index) const noexcept { return GetString(index, IHM::Normal) == "" ? false : true; }
		IH_NODISCARD IH_CXP_INL const bool FindL(const unsigned int index) const noexcept { return GetString(index, IHM::Lower) == "" ? false : true;  }
		IH_NODISCARD IH_CXP_INL const bool FindU(const unsigned int index) const noexcept { return GetString(index, IHM::Upper) == "" ? false : true;  }

		template <typename T> IH_NODISCARD IH_CXP_AND_INL const bool IsInContainer (const T& cont, const unsigned int index) const noexcept { return IsInContainerIndex(cont, index, IHM::Normal); }
		template <typename T> IH_NODISCARD IH_CXP_AND_INL const bool IsInContainerL(const T& cont, const unsigned int index) const noexcept { return IsInContainerIndex(cont, index, IHM::Lower);  }
		template <typename T> IH_NODISCARD IH_CXP_AND_INL const bool IsInContainerU(const T& cont, const unsigned int index) const noexcept { return IsInContainerIndex(cont, index, IHM::Upper);  }

		template <typename T> IH_NODISCARD IH_CXP_AND_INL const bool IsInContainer (const T& cont, const std::string& str) const noexcept { return IsInContainerString(cont, str, IHM::Normal); }
		template <typename T> IH_NODISCARD IH_CXP_AND_INL const bool IsInContainerL(const T& cont, const std::string& str) const noexcept { return IsInContainerString(cont, str, IHM::Lower);  }
		template <typename T> IH_NODISCARD IH_CXP_AND_INL const bool IsInContainerU(const T& cont, const std::string& str) const noexcept { return IsInContainerString(cont, str, IHM::Upper);  }

		IH_NODISCARD IH_CXP_INL const bool IsIn (const std::function<const bool(const std::string&)>& func, const std::string& str) const noexcept { return IsInString(func, str, IHM::Normal); }
		IH_NODISCARD IH_CXP_INL const bool IsInL(const std::function<const bool(const std::string&)>& func, const std::string& str) const noexcept { return IsInString(func, str, IHM::Lower);  }
		IH_NODISCARD IH_CXP_INL const bool IsInU(const std::function<const bool(const std::string&)>& func, const std::string& str) const noexcept { return IsInString(func, str, IHM::Upper);  }
		
		IH_NODISCARD IH_CXP_INL const bool IsIn (const std::function<const bool(const std::string&)>& func, const unsigned int index) const noexcept { return IsInIndex(func, index, IHM::Normal); }
		IH_NODISCARD IH_CXP_INL const bool IsInL(const std::function<const bool(const std::string&)>& func, const unsigned int index) const noexcept { return IsInIndex(func, index, IHM::Lower);  }
		IH_NODISCARD IH_CXP_INL const bool IsInU(const std::function<const bool(const std::string&)>& func, const unsigned int index) const noexcept { return IsInIndex(func, index, IHM::Upper);  }

		IH_NODISCARD IHI_CXP_INL iterator begin() noexcept { return iterator(m_Inputs, 0); }
		IH_NODISCARD IHI_CXP_INL iterator end()   noexcept { return iterator(m_Inputs, m_Size); }

		IH_NODISCARD IHI_CXP_INL const_iterator begin() const noexcept { return const_iterator(m_Inputs, 0); }
		IH_NODISCARD IHI_CXP_INL const_iterator end()   const noexcept { return const_iterator(m_Inputs, m_Size); }
		
		IH_NODISCARD IHI_CXP_INL const_iterator cbegin() const noexcept { return const_iterator(m_Inputs, 0); }
		IH_NODISCARD IHI_CXP_INL const_iterator cend()   const noexcept { return const_iterator(m_Inputs, m_Size); }

		IH_NODISCARD IHI_CXP_INL reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
		IH_NODISCARD IHI_CXP_INL reverse_iterator rend()   noexcept { return reverse_iterator(begin()); }
		
		IH_NODISCARD IHI_CXP_INL const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }
		IH_NODISCARD IHI_CXP_INL const_reverse_iterator rend()   const noexcept { return const_reverse_iterator(begin()); }
		
		IH_NODISCARD IHI_CXP_INL const_reverse_iterator crbegin() const noexcept { return rbegin(); }
		IH_NODISCARD IHI_CXP_INL const_reverse_iterator crend()   const noexcept { return rend(); }
	};


	IH_NODISCARD static inline std::ostream& operator<<(std::ostream& os, const util::io::InputHandler& ih) {
		os << "InputHandler:<" << ih.Size() << "> [";
		for (int i = 0; i < ih.Size(); ++i)
		{
			os << ih[i];
			IH_LIKELY if (i != ih.Size() - 1)
				os << ", ";
		}
		os << "]";
		return os;
	}
}