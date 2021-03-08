/**
 * @file Memory.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Diseño y Análisis de algoritmos
 * @version 0.1
 * @date 2021-03-08
 * 
 */

#include <vector>

/**
 * @class Memory
 * 
 */
class Memory {
  private:
    std::vector<int> register_;
  
  public:
    /**
     * @brief Construct a new Memory object
     * 
     */
    Memory()=default;

    /**
     * @brief Destroy the Memory object
     * 
     */
    ~Memory()=default;

    /**
     * @brief Writes on a memory register the given value
     * 
     * @param pos register position
     * @param value 
     */
    void write(int pos, int value);

    /**
     * @brief Reads a value from the memory
     * 
     * @param pos register position
     * @return int 
     */
    int read(int pos);

    /**
     * @brief Prints on terminal the content of all the memory registers
     * 
     */
    void show();

};