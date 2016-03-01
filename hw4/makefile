CXX = g++
CPPFLAGS = -g -Wall
BIN_DIR = bin

all: $(BIN_DIR)/.dirstamp Facile

Facile: $(BIN_DIR)/LetStatement.o $(BIN_DIR)/ProgramState.o Facile.cpp
	$(CXX) $(CPPFLAGS) Facile.cpp $(BIN_DIR)/LetStatement.o $(BIN_DIR)/ProgramState.o -o Facile

$(BIN_DIR)/LetStatement.o: Statement.h LetStatement.cpp LetStatement.h
	$(CXX) $(CPPFLAGS) -c LetStatement.cpp -o $(BIN_DIR)/LetStatement.o

$(BIN_DIR)/ProgramState.o: ProgramState.cpp ProgramState.h
	$(CXX) $(CPPFLAGS) -c ProgramState.cpp -o $(BIN_DIR)/ProgramState.o

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp