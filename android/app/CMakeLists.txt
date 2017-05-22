# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

add_definitions(-std=c++11)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

set(JNI_CORE_PATH ../../core/jni)
set(PROJECT_PATH ../../project)

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             ${JNI_CORE_PATH}/JNIInit.cpp
             ${JNI_CORE_PATH}/Converter.cpp
             ${PROJECT_PATH}/CallbackTester.cpp
             ${PROJECT_PATH}/SimpleClass.cpp
             ${PROJECT_PATH}/SmartPointers.cpp
             ${PROJECT_PATH}/SingleInheritance.cpp
             ${PROJECT_PATH}/MultipleInheritance.cpp
             src/main/cpp/CallbackTester.jni.cpp
             src/main/cpp/SingleInheritance.jni.cpp
             src/main/cpp/SingleInheritanceExt.jni.cpp
             src/main/cpp/SimpleClass.jni.cpp
             src/main/cpp/BaseClass.jni.cpp
             src/main/cpp/Integer.jni.cpp
             src/main/cpp/MultipleInheritance.jni.cpp
             src/main/cpp/SmartPointers.jni.cpp)

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

target_include_directories(native-lib PUBLIC ${JNI_CORE_PATH} ${PROJECT_PATH})