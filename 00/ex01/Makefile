# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 21:48:28 by sishizaw          #+#    #+#              #
#    Updated: 2025/04/28 21:51:27 by sishizaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# コンパイラの設定
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# ソースファイルとオブジェクトファイルの設定
SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

NAME = phonebook

# ルール
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

# オブジェクトファイルをコンパイル
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# クリーン
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


