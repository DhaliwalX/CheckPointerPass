add_library(CheckPointerPass MODULE
    CheckPointer.cpp
)

target_compile_features(CheckPointerPass PRIVATE cxx_range_for cxx_auto_type)
set_target_properties(CheckPointerPass PROPERTIES
    COMPILE_FLAGS "-fno-rtti"
)

install(TARGETS CheckPointerPass
		LIBRARY DESTINATION /usr/local/lib)
