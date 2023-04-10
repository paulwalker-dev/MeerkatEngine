{ stdenv, raylib, fetchFromGitHub, ... }:
stdenv.mkDerivation rec {
  name = "raygui";
  src = fetchFromGitHub {
    owner = "raysan5";
    repo = "raygui";
    rev = "3.2";
    sha256 = "iwbmNFci7VJIrBNJCjrIVxC+vvq9ZHOozuzOuN/uAsU=";
  };
  buildInputs = [ raylib ];
  buildPhase = ''
    cp src/raygui.h src/raygui.c
    gcc -o libraygui.so src/raygui.c -shared -DRAYGUI_IMPLEMENTATION -lraylib -lm -w
  '';
  installPhase = ''
    mkdir -p $out/include
    mkdir -p $out/lib
    cp src/raygui.h $out/include
    cp libraygui.so $out/lib

    mkdir -p $out/include/styles
    cp styles/*/*.h $out/include/styles
  '';
}
