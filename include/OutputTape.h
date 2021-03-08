/**
 * @file OutputTape.h
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
 * @class OutputTape
 * 
 */
class OutputTape: public Tape {
  public:
    /**
     * @brief Construct a new Output Tape object
     * 
     * @param fileName 
     */
    OutputTape(std::string fileName);

    /**
     * @brief Destroy the Output Tape object
     * 
     */
    ~OutputTape()=default;

    /**
     * @brief Writes on the output tape the given value
     * 
     * @param value 
     */
    void write(int value);

    /**
     * @brief Prints on terminal the content of the tape (including 
     * which position of the tape is pointing the machine)
     * 
     */
    void show();

    /**
     * @brief Outputs the content of the tape to the file specified 
     * in the constructor
     * 
     */
    void outputTapeToFile();

};