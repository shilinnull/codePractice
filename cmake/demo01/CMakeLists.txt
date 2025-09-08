cmake_minimum_required(VERSION 3.18)

project(helloworld)

add_executable(main main.cc)

add_executable(mytest test.cc)

include(CTest)
add_test(
    NAME my_Case_test
    COMMAND mytest
)

include(GNUInstallDirs)
install(TARGETS main)

include(CPack)