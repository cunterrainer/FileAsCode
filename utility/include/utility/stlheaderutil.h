#pragma once

// C
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// C later version
//#include <ccomplex>
//#include <cfenv>
//#include <cinttypes>
//#include <cstdalign>
//#include <cstdbool>
//#include <cstdint>
//#include <ctgmath>
//#include <cwchar>
//#include <cwctype>

// C++
#ifdef __cplusplus
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

#include <optional>
#include <variant>
#include <any>
#include <coroutine>
#include <concepts>
#include <execution>
#include <filesystem>
#include <memory_resource>
#include <span>
#include <string_view>
#endif

// windows
#ifdef _WIN32
	#include <windows.h>
#endif

//#include <bits/stdc++.h>
//// stl container
//#include <tuple>
//#include <utility>
//#include <span>
//#include <bitset>
//#include <initializer_list>
//
//// stl algorithm
//#include <algorithm>
//#include <functional>
//#include <numeric>
//#include <iterator>
//#include <memory>
//#include <type_traits>
//#include <typeinfo>
//#include <typeindex>
//
//// data structure
//#include <array>
//#include <vector>
//#include <list>
//#include <deque>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <stack>
//#include <queue>
//
//// algorithm
//#include <algorithm>
//#include <iterator>
//#include <functional>
//#include <numeric>
//#include <utility>
//#include <memory>
//
//// io
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <iomanip>
//#include <streambuf>
//
//// multi threading
//#include <thread>
//#include <mutex>
//#include <atomic>
//#include <future>
//#include <condition_variable>
//
//// c++ standard library
//#include <string_view>
//#include <optional>
//#include <variant>
//#include <any>
//#include <filesystem>
//#include <string>
//#include <random>
//#include <chrono>
//#include <valarray>
//#include <regex>
//#include <cstdint>
//#include <cfloat>
//
//// c standard library
//#include <cassert>
//#include <ctime>
//#include <cctype>
//#include <cstdarg>
//#include <cstddef>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <climits>