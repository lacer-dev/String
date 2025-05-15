	g# Include directories
INCDIRS = include

# Source files
SRCDIR = src
SRC = betterstring.c
SRC := $(patsubst %, $(SRCDIR)/%, $(SRC))

# Intermediate binaries
OBJDIR = bin/obj
OBJ = betterstring.o
OBJ := $(patsubst %, $(OBJDIR)/%, $(OBJ))

# Output library
TARGETDIR = bin
TARGET = $(TARGETDIR)/libbetterstring.a

# CFLAGS
CFLAGS += -c
CFLAGS += -Wall -Wextra
CFLAGS += -g
CFLAGS += -std=c23
CFLAGS += $(patsubst %, -I%, $(INCDIRS))

all: $(TARGET) tests

$(TARGET): $(OBJ)
	ar -rcs $@ $(OBJ)

OPTIONS = $(CFLAGS)
OPTIONS += $(patsubst %, -I%, $(INCDIRS))
OPTIONS += -c

$(OBJ): $(SRC)
	mkdir -p $(OBJDIR) $(TARGETDIR)
	$(CC) $(OPTIONS) -o $@ $<

tests: $(TARGET)
	pushd tests && make && popd

clean:
	rm -rf bin lib
	pushd tests && make clean && popd
	