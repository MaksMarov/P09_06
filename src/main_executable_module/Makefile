CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11 \
         -I../data_libs \
         -I../data_module \
         -I../yet_another_decision_module

LDFLAGS = -lm

BUILD_DIR = ../../build
TARGET = $(BUILD_DIR)/Quest_5

# sources
MAIN = main_executable_module.c
DATA_IO = ../data_libs/data_io.c
DATA_STAT = ../data_libs/data_stat.c
DECISION = ../yet_another_decision_module/decision.c

# dynamic module
DATA_PROCESS = ../data_module/data_process.c
DATA_PROCESS_SO = $(BUILD_DIR)/data_process.so

all: build_with_dynamic

build_with_dynamic: data_process.so
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) \
	-DUSE_DYNAMIC \
	$(MAIN) \
	$(DATA_IO) \
	$(DATA_STAT) \
	$(DECISION) \
	-L$(BUILD_DIR) -ldata_process \
	-o $(TARGET) $(LDFLAGS)

data_process.so:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -fPIC -c $(DATA_PROCESS) -o $(BUILD_DIR)/data_process.o
	$(CC) -shared $(BUILD_DIR)/data_process.o -o $(DATA_PROCESS_SO)

clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.so $(TARGET)

rebuild: clean all