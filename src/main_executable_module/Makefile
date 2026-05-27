CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c11 \
		  -I../data_libs \
		  -I../data_module \
		  -I../yet_another_decision_module

LDFLAGS = -lm

BUILD_DIR = ../../build

MAIN = main_executable_module.c

DATA_IO = ../data_libs/data_io.c
DATA_STAT = ../data_libs/data_stat.c
DATA_PROCESS = ../data_module/data_process.c
DECISION = ../yet_another_decision_module/decision.c

DATA_STAT_OBJ = $(BUILD_DIR)/data_stat.o
DATA_STAT_A = $(BUILD_DIR)/data_stat.a

DATA_PROCESS_OBJ = $(BUILD_DIR)/data_process.o
DATA_PROCESS_SO = $(BUILD_DIR)/libdata_process.so

TARGET_3 = $(BUILD_DIR)/Quest_3
TARGET_4 = $(BUILD_DIR)/Quest_4
TARGET_5 = $(BUILD_DIR)/Quest_5

.PHONY: all clean rebuild Quest_3 Quest_4 Quest_5 \
		data_stat.a build_with_static \
		data_process.so build_with_dynamic \
		format check-format

all: Quest_3

Quest_3:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) \
	$(MAIN) \
	$(DATA_PROCESS) \
	$(DATA_IO) \
	$(DATA_STAT) \
	$(DECISION) \
	-o $(TARGET_3) \
	$(LDFLAGS)

data_stat.a:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c -o $(DATA_STAT_OBJ)
	ar rcs $(DATA_STAT_A) $(DATA_STAT_OBJ)

build_with_static: data_stat.a
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) \
	$(MAIN) \
	$(DATA_PROCESS) \
	$(DATA_IO) \
	$(DECISION) \
	$(DATA_STAT_A) \
	-o $(TARGET_4) \
	$(LDFLAGS)

Quest_4: build_with_static

data_process.so:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -fPIC -c $(DATA_PROCESS) -o $(DATA_PROCESS_OBJ)
	$(CC) -shared $(DATA_PROCESS_OBJ) -o $(DATA_PROCESS_SO)

build_with_dynamic: data_process.so
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) \
	-DUSE_DYNAMIC \
	$(MAIN) \
	$(DATA_IO) \
	$(DATA_STAT) \
	$(DECISION) \
	-L$(BUILD_DIR) \
	-ldata_process \
	-o $(TARGET_5) \
	$(LDFLAGS)

Quest_5: build_with_dynamic

format:
	find .. -type f \( -name "*.c" -o -name "*.h" \) \
	-exec clang-format -i {} +

check-format:
	find .. -type f \( -name "*.c" -o -name "*.h" \) \
	-exec clang-format --dry-run --Werror {} +

clean:
	rm -rf $(BUILD_DIR)/*.o
	rm -rf $(BUILD_DIR)/*.a
	rm -rf $(BUILD_DIR)/*.so
	rm -rf $(TARGET_3)
	rm -rf $(TARGET_4)
	rm -rf $(TARGET_5)

rebuild: clean all