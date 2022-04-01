#pragma once
#include <ostream>

namespace util::io {

    template <typename T>
    // Only for use with writing containers that support iterators
    static inline bool WriteContainerStream(std::ostream& stream, const T& container, const char separator = '\n', const bool flush = false) {
        if(!stream)
            return false;

        for(auto it = container.begin(); it != container.end(); ++it) {
            stream << *it;
            if(it != container.end() - 1) {
                stream << separator;
            }
        }
        if(flush)
            stream.flush();
        return true;
    }
    
}