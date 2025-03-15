#compiler
CXX = g++
CXXFLAGS = -std=c++17 `pkg-config --cflags gtkmm-4.0`
LDFLAGS = `pkg-config --libs gtkmm-4.0`

SRC_DIR = src
OBJ_DIR = obj
BIN = dmoffice

#files source and objects
SRC = $(shell find $(SRC_DIR) -type f -name "*.cpp")

OBJ = $(patsubst $(SRC)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

#target default
all: $(BIN)

#build app file
$(BIN) : $(OBJ)
	$(CXX) $(OBJ) -o $(BIN) $(LDFLAGS) $(CXXFLAGS)

#compile .cpp files to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp @mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN)