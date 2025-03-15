## Overview

This project provides utilities, such as scripts and code libraries, commonly used in Emute Lab Instrument projects.

This project uses Meson as its build system.

The main build directory is `build`.


## Directory structure

All source code lives under the `src` directory. It should be able to be included by any dependent projects like so: 

```cpp
#include "utils/string.h"
```

## Libraries

### eli-string

This static library provides an `ELI::String` type as a unified interface to various string implementation backends, some of which may be more suitable for some platforms (e.g. embedded) than others. 

An `ELI::String` is either an `std::string`, an `ELI::Extended_std_string` class that extends `std::string`, an `Arduino::String` (as provided directly by the Arduino core), or some other custom implementation. This depends on which value the preprocessor macro `ELI_STRING_BACKEND` is set to.

Possible values for `ELI_STRING_BACKEND` are:

- `ELI_STRING_STD`
- `ELI_STRING_EXTENDED_STD`
- `ELI_STRING_ARDUINO`
- `ELI_STRING_OTHER`

This option is set through the Meson build system, and is exposed to dependent libraries such that they can pick which version of the `ELI::String` they will build with.
