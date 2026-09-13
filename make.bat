@echo off
echo Compiling Monopoly...

:: Compile all source files across your directory structure
g++ *.cpp Tiles/*.cpp Tiles/Ownable/*.cpp Tiles/Ownable/Property/*.cpp Tiles/Drawable/*.cpp Decks/*.cpp -o Monopoly.exe

:: Check if the compilation threw any errors
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo Build failed. Please fix the errors above.
    exit /b %ERRORLEVEL%
)

echo.
echo Build successful! Starting game...
echo -----------------------------------
.\Monopoly.exe