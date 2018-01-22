SOURCES=$(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
OBJECTS=$(addprefix obj/,$(subst src/,,$(SOURCES:.cpp=.o)))
PROGRAM=firefight
INCLUDES=-Isrc/include/sfml/include -Isrc/include/rapidjson/include

LIBRARIES=-lcurl -pthread -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -lsfml-network
CC=g++
CC_FLAGS=-std=c++14


all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)

	$(CC) -o $@ $^ $(LIBRARIES)

obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) $(INCLUDES) -g -c -o $@ $<

clean:

	rm -f $(PROGRAM) $(OBJECTS)

run: ./$(PROGRAM)

	./$(PROGRAM) 
