echo >&2 "Checking is Brew is installed";
command -v brew >/dev/null 2>&1 || { echo >&2 "Installing Homebrew Now"; \
source brewinstall.sh; \
source ~/.zshrc;
}
echo >&2 "Brew is installed";
echo >&2 "Checking is CMAKE is installed";
command -v cmake --version >/dev/null 2>&1 || { echo >&2 "Installing CMAKE Now"; \
command brew install cmake 2>&1;
}

echo >&2 "CMAKE is installed";

command cd sdl && cmake . && make && cd ../sfml && cmake . && make && cd ../opengl && cmake . && make && cd .. && cmake . && make;