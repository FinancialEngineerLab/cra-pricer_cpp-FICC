include(CheckCXXCompilerFlag)

# Cheking C C++ compilers
if(CHECK_CXX_COMPILER_USED1)
    # using Visual Studio C++
    elseif("${CMAKE_CXX_COMPILER_ID}x" STREQUAL "MSVCx")

    # using Intel C++
    elseif("${CMAKE_CXX_COMPILER_ID}x" STREQUAL "Intelx")

    #using Clang++
    elseif("${CMAKE_CXX_COMPILER_ID}x" STREQUAL "Clangx")    
    # C++11
    CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)

    if(COMPILER_SUPPORTS_CXX11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
        set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
        message("Compiler supports c++11")
    else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
    endif(COMPILER_SUPPORTS_CXX11)

    if(CHECK_CXX_COMPILER_USED2)
        elseif("${CMAKE_CXX_COMPILER_ID}x" MATCHES "Clangx")
        # using Clang
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-global-constructors")
            message("Warnings")
        elseif("${CMAKE_CXX_COMPILER_ID}x" STREQUAL "GNUx")
        # using GCC
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
    endif(CHECK_CXX_COMPILER_USED2)

endif(CHECK_CXX_COMPILER_USED1)
