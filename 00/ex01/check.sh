#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

EXECUTABLE="phonebook"

# コンパイル
echo "Compiling..."
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o $EXECUTABLE
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
else
    echo -e "${GREEN}Compilation succeeded.${NC}"
fi

# 正常系テスト
echo "Running basic execution test..."
echo -e "EXIT\n" | ./$EXECUTABLE
if [ $? -ne 0 ]; then
    echo -e "${RED}Basic execution failed.${NC}"
    exit 1
else
    echo -e "${GREEN}Basic execution succeeded.${NC}"
fi

# 異常系入力テスト
echo "Running invalid input tests..."

# コマンドに存在しない文字列を入力
echo -e "abcd\nEXIT\n" | ./$EXECUTABLE > output_invalid1.txt 2>&1
# SEARCH後に変なindexを入力
echo -e "SEARCH\nabc\nEXIT\n" | ./$EXECUTABLE > output_invalid2.txt 2>&1
echo -e "SEARCH\n-1\nEXIT\n" | ./$EXECUTABLE > output_invalid3.txt 2>&1
echo -e "SEARCH\n100\nEXIT\n" | ./$EXECUTABLE > output_invalid4.txt 2>&1
echo -e "SEARCH\n\nEXIT\n" | ./$EXECUTABLE > output_invalid5.txt 2>&1
# ADD時にPhone Numberに変なものを入れる（可能なら）
echo -e "ADD\nJohn\nDoe\nJD\nabcd\nSecret\nEXIT\n" | ./$EXECUTABLE > output_invalid6.txt 2>&1

for i in {1..6}
do
    if grep -q "Segmentation fault" output_invalid${i}.txt; then
        echo -e "${RED}Crash detected in invalid test $i.${NC}"
        exit 1
    fi
done

echo -e "${GREEN}Invalid input tests passed (no crash detected).${NC}"

# 後始末
rm -f output_invalid*.txt

# メモリリークチェック
if ! command -v valgrind &> /dev/null; then
    echo -e "${YELLOW}Valgrind not installed. Skipping memory leak check.${NC}"
else
    echo "Running memory leak check with Valgrind..."
    echo -e "EXIT\n" | valgrind --leak-check=full --error-exitcode=1 ./$EXECUTABLE
    if [ $? -ne 0 ]; then
        echo -e "${RED}Memory leaks detected.${NC}"
        exit 1
    else
        echo -e "${GREEN}No memory leaks detected.${NC}"
    fi
fi

echo ""
echo -e "${GREEN}==== Final Result ====${NC}"
echo -e "${GREEN}All basic and extended invalid input checks completed.${NC}"
