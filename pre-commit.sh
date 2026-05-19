#!/bin/bash

echo "Running pre-commit hook..."

echo "Checking code style with clang-format..."
echo "clang-format -i *.cpp *.hpp"

echo "Checking code style with clang-tidy..."
echo "clang-tidy --fix *.cpp *.hpp -- -std=c++17"

echo "Checking code style with cppcheck...";
echo "cppcheck --enable=all"