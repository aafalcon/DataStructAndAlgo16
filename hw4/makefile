CXX = g++
CPPFLAGS = -g -Wall
BIN_DIR = bin

all: $(BIN_DIR)/.dirstamp Facile

Facile: $(BIN_DIR)/ProgramState.o $(BIN_DIR)/LetStatement.o $(BIN_DIR)/PrintStatement.o $(BIN_DIR)/PrintallStatement.o $(BIN_DIR)/EndStatement.o Facile.cpp
	$(CXX) $(CPPFLAGS) Facile.cpp $(BIN_DIR)/ProgramState.o $(BIN_DIR)/LetStatement.o $(BIN_DIR)/PrintStatement.o $(BIN_DIR)/PrintallStatement.o $(BIN_DIR)/EndStatement.o -o Facile

$(BIN_DIR)/ProgramState.o: ProgramState.cpp ProgramState.h
	$(CXX) $(CPPFLAGS) -c ProgramState.cpp -o $(BIN_DIR)/ProgramState.o

$(BIN_DIR)/LetStatement.o: Statement.h LetStatement.cpp LetStatement.h
	$(CXX) $(CPPFLAGS) -c LetStatement.cpp -o $(BIN_DIR)/LetStatement.o

$(BIN_DIR)/PrintStatement.o: Statement.h PrintStatement.cpp PrintStatement.h
	$(CXX) $(CPPFLAGS) -c PrintStatement.cpp -o $(BIN_DIR)/PrintStatement.o

$(BIN_DIR)/PrintallStatement.o: Statement.h PrintallStatement.cpp PrintallStatement.h
	$(CXX) $(CPPFLAGS) -c PrintallStatement.cpp -o $(BIN_DIR)/PrintallStatement.o

$(BIN_DIR)/EndStatement.o: Statement.h EndStatement.cpp EndStatement.h
	$(CXX) $(CPPFLAGS) -c EndStatement.cpp -o $(BIN_DIR)/EndStatement.o

.PHONY: clean

clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp