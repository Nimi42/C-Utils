BUILD = build
BUILD_TREE := $(dir $(addprefix $(BUILD)/, $(wildcard */*/*.c)))
BINARY = libmultiline.a
EXAMPLE = example.out

ALL_SOURCES := $(wildcard */*/*.c)
ALL_OBJ := $(addprefix $(BUILD)/,$(ALL_SOURCES:%.c=%.o))

LIB_SOURCES := $(filter-out %example.c, $(ALL_SOURCES))
LIB_BUILD := $(addprefix $(BUILD)/,$(LIB_SOURCES:%.c=%.o))

INCLUDE_DIRS = $(wildcard */*/include)
I_FLAG := $(INCLUDE_DIRS:%=-I%)

all: $(BUILD)/$(BINARY) $(BUILD)/$(EXAMPLE)

$(BUILD)/$(BINARY): $(LIB_BUILD)
	ar rcs $@ $<

$(BUILD)/$(EXAMPLE): $(ALL_OBJ)
	gcc -o $@ $^

$(ALL_OBJ): $(BUILD)/%.o: %.c | $(BUILD_TREE)
	gcc $(I_FLAG) -c $< -o $@

$(BUILD_TREE):
	@ mkdir -p $@

clean:
	rm -Rf $(BUILD)

.PHONY: all