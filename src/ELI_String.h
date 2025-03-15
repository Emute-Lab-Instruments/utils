#ifndef ELI_STRING_H_
#define ELI_STRING_H_

namespace ELI {

#if ELI_STRING_BACKEND == ELI_STRING_STD
    #include <string>
    using String = std::string;

#elif ELI_STRING_BACKEND == ELI_STRING_EXTENDED_STD
    #include <string>
    class String : public std::string {
    public:
        using std::string::string;  // Inherit constructors
        
        // Add Arduino-like substring method
        std::string substring(size_t pos, size_t len) const { return substr(pos, len); }
        std::string substring(size_t len) const { return substr(len); }
    };

#elif ELI_STRING_BACKEND == ELI_STRING_ARDUINO
    #include <Arduino.h>
    using String = ::String;

#elif ELI_STRING_BACKEND == ELI_STRING_OTHER
    // Custom string implementation
    class String {
        // ...existing Arduino String implementation...
    };

#else
    #error "Invalid ELI_STRING_BACKEND value"
#endif

} // namespace ELI

#endif // ELI_STRING_H_
