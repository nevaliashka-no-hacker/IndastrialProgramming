#!/bin/bash

# cобрать файлы, которые попали в коммит
FILES=$(git diff --cached --name-only --diff-filter=ACM | grep -E "\.(cpp|hpp)$")

# если C++ файлов нет - выходим
if [ -z "$FILES" ]; then
    exit 0
fi

echo "Running pre-commit hook..."

if command -v clang-format > /dev/null 2>&1; then
    echo "[clang-format] Correcting indents and spaces..."
    clang-format -i $FILES
    git add $FILES  
else
    echo "[clang-format] clang-format not been installed. Cancellation."
fi

if command -v clang-tidy > /dev/null 2>&1; then
    echo "[clang-tidy] Checking the code..."
    clang-tidy --quiet --warnings-as-errors=* $FILES -- -std=c++17
    if [ $? -ne 0 ]; then
        echo "[clang-tidy] There are errors here. Please correct them."
        exit 1
    fi
else
    echo "[clang-tidy] clang-tidy not been installed. Cancellation."
fi

if command -v cppcheck > /dev/null 2>&1; then
    echo "[cppcheck] Checking for leaks and logical errors..."
    cppcheck --error-exitcode=1 --enable=all $FILES
    if [ $? -ne 0 ]; then
        echo "[cppcheck] There are errors here. Please correct them."
        exit 1
    fi
else
    echo "[cppcheck] not been installed. Cancellation."
fi

echo "Pre-commit hook completed. Commit allowed."
exit 0
