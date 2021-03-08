/**
 * @file Tag.h
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

#ifndef _TAG_
#define _TAG_

/**
 * @class Tag
 * 
 */
class Tag {
  private:
    int startLine_;
    std::string id_;
  
  public:
    /**
     * @brief Construct a new Tag object
     * 
     * @param sl start line
     * @param id identifier
     */
    Tag(int sl, std::string id);

    /**
     * @brief Destroy the Tag object
     * 
     */
    ~Tag()=default;

    /**
     * @brief Get the Start Line attribute
     * 
     * @return int 
     */
    int getStartLine();

    /**
     * @brief Get the Identifier attribute
     * 
     * @return std::string 
     */
    std::string getId();
};

#endif