CC := g++
SRCDIR := src
TSTDIR := tests
BUILDDIR := build
TARGET := main
TESTES := program/testes.cpp

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall -O3 -std=c++14
INC := -I include/ -I third_party/

$(TARGET): $(OBJECTS)
	$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	
tests: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $(TESTES) $(TSTSOURCES) $^ -o $(BINDIR)/testes
	$(BINDIR)/testes

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)

.PHONY: clean
