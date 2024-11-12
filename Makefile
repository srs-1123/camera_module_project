CXX = g++
CXXFLAGS = `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`
TARGET = camera_app
SRCS = main.cpp camera_module.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f $(OBJS) $(TARGET)