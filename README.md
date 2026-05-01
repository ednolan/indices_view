# beman.indices_view: A range adaptor that generates a sequence of integers from $0$ to $n - 1$

<!--
SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
-->

<!-- markdownlint-disable-next-line line-length -->
![Library Status](https://raw.githubusercontent.com/bemanproject/beman/refs/heads/main/images/badges/beman_badge-beman_library_production_ready_stable_api.svg) ![Continuous Integration Tests](https://github.com/bemanproject/indices_view/actions/workflows/ci_tests.yml/badge.svg) ![Lint Check (pre-commit)](https://github.com/bemanproject/indices_view/actions/workflows/pre-commit-check.yml/badge.svg) [![Coverage](https://coveralls.io/repos/github/bemanproject/indices_view/badge.svg?branch=main)](https://coveralls.io/github/bemanproject/indices_view?branch=main) ![Standard Target](https://github.com/bemanproject/beman/blob/main/images/badges/cpp26.svg)

**Implements**: `std::views::indices` proposed in [Add std::views::indices(n) (P3060R2)](https://wg21.link/P3060R2).

**Status**: [Production ready. Stable API.](https://github.com/bemanproject/beman/blob/main/docs/beman_library_maturity_model.md#production-ready-stable-api)

## License

`beman.indices_view` is licensed under the Apache License v2.0 with LLVM Exceptions.

## Usage

```cpp
#include <iostream>
#include <vector>

#include <beman/indices_view/indices.hpp>

namespace biv = beman::indices_view;

// Example given in the paper for `std::views::indices`, adapted to work with C++20.
int main() {
    std::vector rng(5, 0);

    std::cout << "[";
    bool first = true;
    for (auto i : biv::indices(std::ranges::size(rng))) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << i;
        first = false;
    }
    std::cout << "]\n";

    return 0;
}

```

Full runnable examples can be found in [`examples/`](examples/).

## Dependencies

### Build Environment

This project requires at least the following to build:

* A C++ compiler that conforms to the C++20 standard or greater
* CMake 3.30 or later
* (Test Only) GoogleTest

You can disable building tests by setting CMake option `BEMAN_INDICES_VIEW_BUILD_TESTS` to
`OFF` when configuring the project.

### Supported Platforms

| Compiler   | Version | C++ Standards | Standard Library  |
|------------|---------|---------------|-------------------|
| GCC        | 15-13   | C++26-C++20   | libstdc++         |
| GCC        | 12-11   | C++23, C++20  | libstdc++         |
| Clang      | 22-19   | C++26-C++20   | libstdc++, libc++ |
| Clang      | 18      | C++26-C++20   | libc++            |
| Clang      | 18      | C++23, C++20  | libstdc++         |
| Clang      | 17      | C++26-C++20   | libc++            |
| Clang      | 17      | C++20         | libstdc++         |
| AppleClang | latest  | C++26-C++20   | libc++            |
| MSVC       | latest  | C++23         | MSVC STL          |

## Development

See the [Contributing Guidelines](CONTRIBUTING.md).

## Integrate beman.indices_view into your project

### Build

You can build indices_view using a CMake workflow preset:

```bash
cmake --workflow --preset gcc-release
```

To list available workflow presets, you can invoke:

```bash
cmake --list-presets=workflow
```

For details on building beman.indices_view without using a CMake preset, refer to the
[Contributing Guidelines](CONTRIBUTING.md).

### Installation

#### Vcpkg

The preferred way to install indices_view is via vcpkg. To do so, after installing vcpkg
itself, you need to add support for the Beman project's [vcpkg
registry](https://github.com/bemanproject/vcpkg-registry) by configuring a
`vcpkg-configuration.json` file (which indices_view [provides](vcpkg-configuration.json)).

Then, simply run `vcpkg install beman-indices-view`.

#### Manual

To install beman.indices_view globally after building with the `gcc-release` preset, you can
run:

```bash
sudo cmake --install build/gcc-release
```

Alternatively, to install to a prefix, for example `/opt/beman`, you can run:

```bash
sudo cmake --install build/gcc-release --prefix /opt/beman
```

This will generate the following directory structure:

```txt
/opt/beman
├── include
│   └── beman
│       └── indices_view
│           ├── indices.hpp
│           └── ...
└── lib
    └── cmake
        └── beman.indices_view
            ├── beman.indices_view-config-version.cmake
            ├── beman.indices_view-config.cmake
            └── beman.indices_view-targets.cmake
```

### CMake Configuration

If you installed beman.indices_view to a prefix, you can specify that prefix to your CMake
project using `CMAKE_PREFIX_PATH`; for example, `-DCMAKE_PREFIX_PATH=/opt/beman`.

You need to bring in the `beman.indices_view` package to define the `beman::indices_view` CMake
target:

```cmake
find_package(beman.indices_view REQUIRED)
```

You will then need to add `beman::indices_view` to the link libraries of any libraries or
executables that include `beman.indices_view` headers.

```cmake
target_link_libraries(yourlib PUBLIC beman::indices_view)
```

### Using beman.indices_view

To use `beman.indices_view` in your C++ project,
include an appropriate `beman.indices_view` header from your source code.

```c++
#include <beman/indices_view/indices.hpp>
```

> [!NOTE]
>
> `beman.indices_view` headers are to be included with the `beman/indices_view/` prefix.
> Altering include search paths to spell the include target another way (e.g.
> `#include <indices.hpp>`) is unsupported.
