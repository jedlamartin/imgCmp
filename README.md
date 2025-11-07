# imgCmp

A simple C++ utility for comparing images bit by bit.

---

## Build

This project uses C++ and CMake. To build it, ensure you have a C++ compiler and CMake installed.

*Dependencies:* [DevIL](https://openil.sourceforge.net/)

### Build Steps

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/jedlamartin/imgCmp
    cd imgCmp
    ```

2.  **Run CMake and build:**
    ```bash
    cmake . && cmake --build .
    ```
---

## Usage
```bash
./imgCmp <image1> <image2>
