# Versión mínima requerida de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(BancoUCC)

# Establecer el estándar de C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Añadir los archivos fuente del proyecto
add_executable(BancoUCC
        cliente.cpp
        cliente.h
        cuenta.cpp
        cuenta.h
        transaccion.cpp
        transaccion.h
        banco.cpp
        banco.h
        main.cpp
        TarjetaCredito.h
        TarjetaCredito.cpp
)

# Incluir directorios de encabezados
target_include_directories(BancoUCC PUBLIC
        "${PROJECT_SOURCE_DIR}"
)
