INCDIRS = ../../include

LIBDIRS = ../../lib
LIBS = libbetterstring.a

SRCDIR = src
SRC = main.c
SRC := $(patsubst %, $(SRCDIR)/%, $(SRC))

TARGETDIR = bin
TARGET = $(TARGETDIR)/test1.exe

CFLAGS += -c
CFLAGS += -Wall -Wextra

OPTIONS = $(CFLAGS)
OPTIONS += $(patsubst %, -I%, $(INCDIRS))
OPTIONS += $(patsubst %, -L%, $(LIBDIRS))
OPTIONS += $(patsubst %, -l%, $(LIBS))

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p $(TARGETDIR)
	$(CC) $(OPTIONS) -o $@ $(SRC)

clean:
	rm -rf bin