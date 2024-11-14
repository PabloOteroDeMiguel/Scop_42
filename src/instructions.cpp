/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <potero-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:52:40 by potero-d          #+#    #+#             */
/*   Updated: 2024/11/14 13:06:01 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Scop.h"

void instructions() {
    std::cout << "Welcome to SCOP" << std::endl;
    std::cout << "Instructions:" << std::endl;
    std::cout << "\tMove:" << std::endl;
    std::cout << "\t\tA: Turn left" << std::endl;
    std::cout << "\t\tD: Turn right" << std::endl;
    std::cout << "\t\tW: Turn up" << std::endl;
    std::cout << "\t\tS: Turn down" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "\tScale:" << std::endl;
    std::cout << "\t\tQ: Smaller" << std::endl;
    std::cout << "\t\tE: Bigger" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "\tMode:" << std::endl;
    std::cout << "\t\tT: Mode up" << std::endl;
    std::cout << "\t\t1: Basic color" << std::endl;
    std::cout << "\t\t2: Disco" << std::endl;
    std::cout << "\t\t3: Texture 1" << std::endl;
    std::cout << "\t\t4: texture 2" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "\tEsc for EXIT" << std::endl;
}