# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 05:25:06 by sishizaw          #+#    #+#              #
#    Updated: 2025/04/29 05:53:58 by sishizaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# コンパイラとフラグ
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# オブジェクトファイルの置き場
OBJ_DIR = obj

# ソースファイルとオブジェクトファイル
SRC_FILES = $(wildcard *.cpp)
OBJ_FILES = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# 実行ファイル名
TARGET = zombieHorde

# デフォルトターゲット
all: $(TARGET)

# 実行ファイルのビルド
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(TARGET)

# オブジェクトファイルのビルド
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# クリーンターゲット (.o ファイルだけ削除)
clean:
	rm -rf $(OBJ_DIR)

# 実行ファイルも含めて完全削除
fclean: clean
	rm -f $(TARGET)

# 再ビルド
re: fclean all


