/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:52:40 by potero-d          #+#    #+#             */
/*   Updated: 2024/11/25 10:56:16 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Scop.h"

void instructions() {
    std::cout << "Welcome to SCOP" << std::endl;
    std::cout << "Instructions:" << std::endl;
    std::cout << "\tMove:" << std::endl;
    std::cout << "\t\tA: Left" << std::endl;
    std::cout << "\t\tD: Right" << std::endl;
    std::cout << "\t\tW: Up" << std::endl;
    std::cout << "\t\tS: Down" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "\tTurn:" << std::endl;
    std::cout << "\t\tLeft arrow: Turn left" << std::endl;
    std::cout << "\t\tRight arrow: Turn right" << std::endl;
    std::cout << "\t\tUp arrow: Turn up" << std::endl;
    std::cout << "\t\tDown arrow: Turn down" << std::endl;
    std::cout << "\t\tM: Automatic" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "\tScale:" << std::endl;
    std::cout << "\t\tQ: Smaller" << std::endl;
    std::cout << "\t\tE: Bigger" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "\tMode:" << std::endl;
    std::cout << "\t\tT: Next mode" << std::endl;
    std::cout << "\t\t1: Basic color" << std::endl;
    std::cout << "\t\t2: Disco" << std::endl;
    std::cout << "\t\t3: Texture 1" << std::endl;
    std::cout << "\t\t4: texture 2" << std::endl;
    std::cout << "\t\t5: Gray" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "\tEsc for EXIT" << std::endl;
}