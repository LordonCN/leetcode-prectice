cmake_minimum_required(VERSION 3.17)
project(Game_12_24_12)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Game_12_24_12
        Agent.cpp
        Agent.h
        Agents.cpp
        Agents.h
        DPAgent.cpp
        DPAgent.h
        DQNAgent.cpp
        DQNAgent.h
        Game.cpp
        Game.h
        main.cpp
        Params.cpp
        Params.h
        State.cpp
        State.h
        Utils.cpp
        Utils.h)
