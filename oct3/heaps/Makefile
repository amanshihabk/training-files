CC = gcc
RELEASE_FLAGS = -O3 -Wall
DEBUG_FLAGS = -g -Wall

SRC_DIR = src
INCLUDE_DIR = include
DEBUG_DIR = debug
RELEASE_DIR = release

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
DEBUG_OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(DEBUG_DIR)/obj/%.o, $(SRC_FILES))
RELEASE_OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(RELEASE_DIR)/obj/%.o, $(SRC_FILES))

DEBUG_BIN = $(DEBUG_DIR)/bin/debug_executable
RELEASE_BIN = $(RELEASE_DIR)/bin/release_executable

debug : $(DEBUG_BIN)

release : $(RELEASE_BIN)

$(DEBUG_BIN) : $(DEBUG_OBJ_FILES)
	$(CC) $(DEBUG_FLAGS) -o $@ $^

$(DEBUG_DIR)/obj/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $(DEBUG_FLAGS) -I$(INCLUDE_DIR) $< -o $@

$(RELEASE_BIN) : $(RELEASE_OBJ_FILES)
	$(CC) -I$(INCLUDE_DIR) $^ -o $@ $(RELEASE_FLAGS)

$(RELEASE_DIR)/obj/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -I$(INCLUDE_DIR) -c $< -o $@ $(RELEASE_FLAGS)

clean :
	rm -rf $(DEBUG_DIR)/obj/*.o $(DEBUG_BIN) $(RELEASE_DIR)/obj/*.o $(RELEASE_BIN)

# `@` hides the command from being echoed
# `$<` uses the first argument from the list of dependencies
# `$^` uses all the arguments from the list of dependencies
# `$@` uses the first arg from the list of targets (think @ is used to address a target in social media)
# `wildcard` is used to retrieve a list of args that match a particular patter
# `patsubst` is used to match a pattern and substitute with a defined replacement, it takes list of args and each of these are checked for the pattern and then they are replaced