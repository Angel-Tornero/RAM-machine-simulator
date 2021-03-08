/**
 * @file Tape.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include <string>
#include <vector>

#ifndef _TAPE_
#define _TAPE_

/**
 * @class Tape
 * 
 */
class Tape {

  protected:
    std::vector<int> values_;
    std::string fileName_;
    int index_;
  
  public:
    /**
     * @brief Construct a new Tape object
     * 
     */
    Tape()=default;

    /**
     * @brief Destroy the Tape object
     * 
     */
    ~Tape()=default;

};

#endif