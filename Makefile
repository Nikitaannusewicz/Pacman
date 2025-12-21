CC = clang
CFLAGS = -I include -Wexcess-initializers
LDFLAGS = -L lib/
FRAMEWORKS = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
LIBS = lib/libraylib.a
SRC = src/*.c
TARGET = compiled-raylib-game

$(TARGET): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) $(FRAMEWORKS) $(LIBS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(TARGET)

.PHONY: clean run