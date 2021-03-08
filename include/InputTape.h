/**
 * @file InputTape.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include "Tape.h"

/**
 * @class InputTape
 * 
 */
class InputTape: public Tape {

  public:
    /**
     * @brief Construct a new Input Tape object from a file
     * 
     * @param fileName 
     */
    InputTape(std::string fileName);

    /**
     * @brief Destroy the Input Tape object
     * 
     */
    ~InputTape()=default;

    /**
     * @brief Loads the values of input tape on a vector (attribute)
     * 
     * @param fileName 
     */
    void load(std::string fileName);

    /**
     * @brief Prints on terminal the content of the tape (including 
     * which position of the tape is pointing the machine)
     * 
     */
    void show();

    /**
     * @brief Returns the next value that has to be readed on the tape
     * 
     * @return int 
     */
    int readValue();

};