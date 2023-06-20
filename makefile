AS = lcc -c
CC = lcc -Wa-l -Wl-m

BIN = CityWorm.gb
SRC = $(shell find . -name "*.c")
OBJ = $(SRC:.c=.o)

GEN_FOLDER = generated
ROM_FOLDER = builds
GEN_LIST = $(shell find . -name "*.lst") $(shell find . -name "*.asm") $(shell find . -name "*.o") $(shell find . -name "*.sym") $(shell find . -name "*.ihx") $(shell find . -name "*.map")

all: clean $(BIN) move

$(BIN): $(OBJ)
	@echo 'Generating ROM'
	$(CC) -o $(BIN) $^

move:
	@echo 'Moving generated files'
	@mkdir -p $(GEN_FOLDER)
	@mv -u $(GEN_LIST) $(GEN_FOLDER)
	@mkdir -p $(ROM_FOLDER)
	@mv -u $(BIN) $(ROM_FOLDER)

clean:
	@echo 'Cleaning useless files !'
	@rm -rf $(GEN_LIST)