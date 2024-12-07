#!/usr/bin/env bash

# Configuration variables
BUILD_TOOL="ninja" # Change to "make" if desired
BUILD_DIR="./build"
EXECUTABLE="./OpenGL-Project"

# Function to display usage
function show_help() {
    echo "Usage: ./run.sh [--build] [--run] [--clean] [--debug]"
    echo ""
    echo "Flags:"
    echo "  --build     Only build the project."
    echo "  --run       Only run the project executable."
    echo "  --clean     Clean the build directory before building."
    echo "  --debug     Build with debug information."
    echo "Default: Build and run the project."
}

# Parse command-line arguments
DO_BUILD=false
DO_RUN=false
DO_CLEAN=false
DO_DEBUG=false

for arg in "$@"; do
    case $arg in
    --build)
        DO_BUILD=true
        ;;
    --run)
        DO_RUN=true
        ;;
    --clean)
        DO_CLEAN=true
        ;;
    --debug)
        DO_DEBUG=true
        ;;
    --help)
        show_help
        exit 0
        ;;
    *)
        echo "[run.sh]=> Unknown option: $arg"
        show_help
        exit 1
        ;;
    esac
done

# Default behavior if no flags are provided
if [ "$DO_BUILD" = false ] && [ "$DO_RUN" = false ]; then
    DO_BUILD=true
    DO_RUN=true
fi

# Clean the build directory if requested
if [ "$DO_CLEAN" = true ]; then
    echo "[run.sh]=> Cleaning build directory..."
    rm -rf "$BUILD_DIR"
fi

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# Change to the build directory
cd "$BUILD_DIR" || exit

# Build the project
if [ "$DO_BUILD" = true ]; then
    echo "[run.sh]=> Building project using $BUILD_TOOL..."
    if [ "$DO_DEBUG" = true ]; then
        cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
    else
        cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
    fi

    if [ "$BUILD_TOOL" = "ninja" ]; then
        ninja
    elif [ "$BUILD_TOOL" = "make" ]; then
        make
    else
        echo "[run.sh]=> Error: Unsupported build tool '$BUILD_TOOL'."
        exit 1
    fi
fi

# Run the project
if [ "$DO_RUN" = true ]; then
    echo "[run.sh]=> Running the executable..."
    if [ -f "$EXECUTABLE" ]; then
        "$EXECUTABLE"
    else
        echo "Error: Executable not found: $EXECUTABLE"
        exit 1
    fi
fi
