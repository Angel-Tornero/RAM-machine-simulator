ram: src/main.cc src/ram_t.cc src/program_t.cc src/output_tape_t.cc src/input_tape_t.cc src/instruction_t.cc
	g++ -g src/main.cc src/ram_t.cc src/program_t.cc src/output_tape_t.cc src/input_tape_t.cc src/instruction_t.cc -o ram

clean:
	rm -f $(ram)