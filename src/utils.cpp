/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:46:27 by potero-d          #+#    #+#             */
/*   Updated: 2024/11/25 10:49:55 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Scop.h"

std::vector<std::string> splitString(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void frameSize(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    Object* obj = static_cast<Object*>(glfwGetWindowUserPointer(window));
    obj->scale = std::min(width / 1080.0f, height / 720.0f); // Scale proportionally
}
