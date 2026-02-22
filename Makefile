# Powered by BangGaming8826
CXX = g++-15
CXXFLAGS = -std=c++26 
TARGET = dev_calc 
SRC = dev_calc.cpp 
all: $(TARGET)
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) 
install: 
	install -m 755 $(TARGET) /usr/bin/
clean:
	rm -f $(TARGET)
