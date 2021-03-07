ram: src/main.cc src/RAMachine.cc src/Program.cc src/Tag.cc src/Memory.cc src/OutputTape.cc src/InputTape.cc src/Instruction.cc src/Instrucciones/InstructionADD.cc src/Instrucciones/InstructionDIV.cc src/Instrucciones/InstructionHALT.cc src/Instrucciones/InstructionJGTZ.cc src/Instrucciones/InstructionJUMP.cc src/Instrucciones/InstructionJZERO.cc src/Instrucciones/InstructionLOAD.cc src/Instrucciones/InstructionMULT.cc src/Instrucciones/InstructionREAD.cc src/Instrucciones/InstructionSTORE.cc src/Instrucciones/InstructionSUB.cc src/Instrucciones/InstructionWRITE.cc
	g++ -g src/main.cc src/RAMachine.cc src/Program.cc src/Tag.cc src/Memory.cc src/OutputTape.cc src/InputTape.cc src/Instruction.cc src/Instrucciones/InstructionADD.cc src/Instrucciones/InstructionDIV.cc src/Instrucciones/InstructionHALT.cc src/Instrucciones/InstructionJGTZ.cc src/Instrucciones/InstructionJUMP.cc src/Instrucciones/InstructionJZERO.cc src/Instrucciones/InstructionLOAD.cc src/Instrucciones/InstructionMULT.cc src/Instrucciones/InstructionREAD.cc src/Instrucciones/InstructionSTORE.cc src/Instrucciones/InstructionSUB.cc src/Instrucciones/InstructionWRITE.cc -o ram

clean:
	rm -f $(ram)
