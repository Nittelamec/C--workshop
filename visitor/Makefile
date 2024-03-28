CXXFLAGS=-std=c++20 -Wall -Wextra -Werror -pedantic -Wold-style-cast

CXX=g++

OBJS=visitor_test.o builder.o tree.o \
    node.o leaf.o \
    compute_visitor.o \
    add.o sub.o mul.o div.o print_visitor.o

TARGET=visitor

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

clean:
	$(RM) $(TARGET) $(OBJS)
