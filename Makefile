# Tên file đầu ra
TARGET = program.exe

# Trình biên dịch
CXX = g++

# Cờ biên dịch (tùy chọn)
CXXFLAGS = -Wall -Wextra -std=c++17

# Danh sách file nguồn
SRC = main.cpp

# Mục tiêu mặc định
all: $(TARGET)

# Quy tắc biên dịch
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Xóa file biên dịch
clean:
	del $(TARGET)
