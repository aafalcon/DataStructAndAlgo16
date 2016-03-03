CXX = g++
CPPFLAGS = -g -Wall
BIN_DIR = bin

all: $(BIN_DIR)/.dirstamp Facile

Facile: $(BIN_DIR)/ProgramState.o $(BIN_DIR)/LetStatement.o $(BIN_DIR)/PrintStatement.o \
$(BIN_DIR)/PrintallStatement.o $(BIN_DIR)/EndStatement.o $(BIN_DIR)/AddStatement.o \
$(BIN_DIR)/SubStatement.o $(BIN_DIR)/MultStatement.o $(BIN_DIR)/DivStatement.o \
$(BIN_DIR)/GotoStatement.o $(BIN_DIR)/IfStatement.o Facile.cpp
	$(CXX) $(CPPFLAGS) $^ -o $@

$(BIN_DIR)/ProgramState.o: ProgramState.cpp ProgramState.h
	$(CXX) $(CPPFLAGS) -c ProgramState.cpp -o $@

$(BIN_DIR)/LetStatement.o: Statement.h LetStatement.cpp LetStatement.h
	$(CXX) $(CPPFLAGS) -c LetStatement.cpp -o $@

$(BIN_DIR)/PrintStatement.o: Statement.h PrintStatement.cpp PrintStatement.h
	$(CXX) $(CPPFLAGS) -c PrintStatement.cpp -o $@

$(BIN_DIR)/PrintallStatement.o: Statement.h PrintallStatement.cpp PrintallStatement.h
	$(CXX) $(CPPFLAGS) -c PrintallStatement.cpp -o $@

$(BIN_DIR)/EndStatement.o: Statement.h EndStatement.cpp EndStatement.h
	$(CXX) $(CPPFLAGS) -c EndStatement.cpp -o $@

$(BIN_DIR)/AddStatement.o: Statement.h AddStatement.cpp AddStatement.h
	$(CXX) $(CPPFLAGS) -c AddStatement.cpp -o $@

$(BIN_DIR)/SubStatement.o: Statement.h SubStatement.cpp SubStatement.h
	$(CXX) $(CPPFLAGS) -c SubStatement.cpp -o $@

$(BIN_DIR)/MultStatement.o: Statement.h MultStatement.cpp MultStatement.h
	$(CXX) $(CPPFLAGS) -c MultStatement.cpp -o $@

$(BIN_DIR)/DivStatement.o: Statement.h DivStatement.cpp DivStatement.h
	$(CXX) $(CPPFLAGS) -c DivStatement.cpp -o $@

$(BIN_DIR)/GotoStatement.o: Statement.h GotoStatement.cpp GotoStatement.h
	$(CXX) $(CPPFLAGS) -c GotoStatement.cpp -o $@

$(BIN_DIR)/IfStatement.o: Statement.h IfStatement.cpp IfStatement.h
	$(CXX) $(CPPFLAGS) -c IfStatement.cpp -o $@

.PHONY: all clean

clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp