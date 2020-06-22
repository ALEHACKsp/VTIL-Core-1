project(VTIL-Tests)

add_executable(${PROJECT_NAME}
    doctest.h
    main.cpp
    regs.cpp
)

target_link_libraries(${PROJECT_NAME} VTIL)
