# ==============================================================================
# uikit-cpp-win32 Makefile
# Copyright (c) 2012 Jay Phelps
# MIT licensed
# https://github.com/jayphelps/uikit-cpp-win32
# ==============================================================================

# Directories ==================================================================

SRC_DIR        = src
BIN_DIR        = bin
OBJECT_DIR     = obj
TMP_DIR        = \tmp
DB_DIR         = db
FOUNDATION_DIR = $(SRC_DIR)\Foundation
UIKIT_DIR      = $(SRC_DIR)\UIKit

# Executables ==================================================================

CXX = cl
EXEC = uikit-cpp-win32

# Flags ========================================================================

CC = $(CXX)

DEBUG_LEVEL = 
CXXFLAGS    = $(DEBUG_LEVEL) /I./$(SRC_DIR)/ /EHsc /Fd$(DB_DIR)\

# Files ========================================================================

SRC_FILES   = $(UIKIT_DIR)\UIApplication.cpp         \
              $(UIKIT_DIR)\UIApplicationDelegate.cpp \
              $(UIKIT_DIR)\UIViewController.cpp      \
              $(UIKIT_DIR)\UIView.cpp                \
              $(UIKIT_DIR)\UIWindow.cpp              \
              $(SRC_DIR)\main.cpp

O_FILES     = $(SRC_FILES:%.cpp=%.o)

OUTPUT_FILE = app

# Config =======================================================================

VPATH = %$(SRC_EXT) $(SRC_DIR)

# Targets ======================================================================

all: $(EXEC)

$(EXEC):
    @if not exist $(OBJECT_DIR)\ mkdir $(OBJECT_DIR)
    @if not exist $(BIN_DIR)\ mkdir $(BIN_DIR)
    @$(CXX) $(CXXFLAGS) $(SRC_FILES) /Fo$(OBJECT_DIR)\ /Fe$(BIN_DIR)\$(OUTPUT_FILE)\

clean:
    @if exist $(OBJECT_DIR) rmdir /s /q $(OBJECT_DIR)
    @if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)
    @echo cleaned.