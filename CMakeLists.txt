cmake_minimum_required(VERSION 3.15)
project(Rtree)

set(CMAKE_CXX_STANDARD 14)

add_executable(Rtree main.cpp photo.cpp photo.h gallery.cpp gallery.h Rtree.h historicalRtree.cpp historicalRtree.h)