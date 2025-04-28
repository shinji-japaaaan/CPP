/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:38:43 by sishizaw          #+#    #+#             */
/*   Updated: 2025/04/26 21:44:35 by sishizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void printMessage(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return;
    }
    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            std::cout << (char)std::toupper(argv[i][j]);
            j++;
        }
        if (i < argc - 1)
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    printMessage(argc, argv);
    return 0;
}

