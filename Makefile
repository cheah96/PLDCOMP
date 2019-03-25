ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP

default:
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp  Main.g4
	clang++ -DTRACE -g -std=c++11  -I $(ANTLRRUNTIME)/antlr4-runtime/ *.cpp  -o Main.exe $(ANTLRRUNTIME)/lib/libantlr4-runtime.a
clean:
	rm -rf MainBaseVisitor.* MainLexer.* MainParser.* MainVisitor.* *.dot *.pdf *.interp *.tokens *.exe *.s *.o *.out
