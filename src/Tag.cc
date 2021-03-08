/**
 * @file Tag.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include "../include/Tag.h"

Tag::Tag(int sl, std::string id) {
  id_ = id;
  startLine_ = sl;
}

int Tag::getStartLine() {
  return startLine_;
}

std::string Tag::getId() {
  return id_;
}