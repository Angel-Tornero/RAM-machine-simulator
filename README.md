# Simulador RAM

Los programas a cargar en la máquina RAM y los contenidos de las cintas de entrada
y de salida deben estar en tres ficheros diferentes, y sus nombres deben poder ser
introducidos mediante teclado.

## Ejecución

• El simulador debe ejecutarse del siguiente modo:
```./ram_sim ram_program.ram input_tape.in output_tape.out debug```

- ram_program.ram: fichero con el programa RAM.
- input_tape.in: fichero con el contenido de la cinta de entrada.
- output_tape.out: fichero con el contenido de la cinta de salida.
- debug: Si el valor de este parámetro es 1, se presentará un menú de
características similares al siguiente figura y, permitirá ejecutar cada una
de sus opciones, mostrando en cada paso de ejecución la instrucción
ejecutada y el estado de la máquina.

```>h
r: ver los registros
t: traza
e: ejecutar
s: desensamblador
i: ver cinta entrada
o: ver cinta salida
h: ayuda
x: salir
>```

El valor 0 lleva a cabo la simulación completa. Al finalizar la misma, sólo
deberá mostrarse por consola el número total de instrucciones ejecutadas.