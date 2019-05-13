add_executable(${PROJECT_NAME} 
                main.cpp
                oncollide.cpp
                bullet.cpp
                alien.cpp
                ship.cpp
                )
                
target_link_libraries(space-invaders
    ${SFML_LIBRARIES}
    )
    
install(TARGETS space-invaders DESTINATION ${CMAKE_SOURCE_DIR}/build)
