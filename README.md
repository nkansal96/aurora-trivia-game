# Aurora C++ Trivia Game

This is a simple proof of concept for Aurora C++ API. It it a trivia game in which five questions are asked to the player and the player is scored based on whether their responses are correct. It shows examples of text to speech, speech to text, and playing audio files.

## Building & Running

1. Recursively clone this repository with `git clone --recurse-submodules https://github.com/nkansal96/aurora-trivia-game.git`
2. Run CMake to configure the project and install dependencies: `cmake .`
3. Build the game binary: `make` 
4. Set environmental variables `APP_TOKEN` and `APP_ID` with respective Aurora developer credentials
5. Run the trivia game: `./bin/trivia_game`
