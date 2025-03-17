#compiler
CXX = g++

I_DIRS = $(shell find src -type d)
BUILD_DIR=build/linux/x86_64
BUILD_ASSETS_DIR=$(BUILD_DIR)/assets
ASSETS_DIR=src/assets

ASSETS = $(shell find $(ASSETS_DIR) -type f)

CXXFLAGS = -std=c++17 `pkg-config --cflags gtkmm-4.0`  $(foreach d, $(I_DIRS), -I $d)
LDFLAGS = `pkg-config --libs gtkmm-4.0`

SRC_DIR = src
OBJ_DIR = obj
BIN = $(BUILD_DIR)/dmoffice

#files source and objects
SRC = $(shell find $(SRC_DIR) -type f -name "*.cpp")

OBJ = $(patsubst $(SRC)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

#target default
all: $(BIN)

#build app file
$(BIN) : $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJ) -o $(BIN) $(LDFLAGS) $(CXXFLAGS)

#compile .cpp files to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp @mkdir -p $(dir $@)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN)


#copy-assets:
#	@mkdir -p $(BUILD_ASSETS_DIR) 
#	cp -r $(ASSETS) $(BUILD_ASSETS_DIR)