add_library(yaka SHARED src/yaka.cc)

target_link_libraries(hello_yaka yaka)

target_include_directories(yaka PUBLIC "${PROJECT_SOURCE_DIR}/libyaka/include")
