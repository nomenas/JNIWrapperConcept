# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

add_definitions(-std=c++11)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/native-lib.cpp
             src/main/cpp/jni_core/JNIInit.cpp
             src/main/cpp/jni/CallbackTester.jni.cpp
             src/main/cpp/jni/SingleInheritance.jni.cpp
             src/main/cpp/jni/SingleInheritanceExt.jni.cpp
             src/main/cpp/jni/SimpleClass.jni.cpp
             src/main/cpp/jni/BaseClass.jni.cpp
             src/main/cpp/jni/Integer.jni.cpp
             src/main/cpp/jni/MultipleInheritance.jni.cpp
             src/main/cpp/jni/ExtendAndImplement.jni.cpp
             src/main/cpp/jni/SmartPointers.jni.cpp
             src/main/cpp/project/CallbackTester.cpp
             src/main/cpp/project/SimpleClass.cpp
             src/main/cpp/project/SmartPointers.cpp
             src/main/cpp/project/SingleInheritance.cpp
             src/main/cpp/project/MultipleInheritance.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because system libraries are included in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in the
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )

target_include_directories(native-lib PUBLIC src/main/cpp/jni_core)