{ pkgs ? import <nixpkgs> {} }:
pkgs.stdenv.mkDerivation {
  pname = "MeerkatEngine";
  version = "0.0.1";
  src = ./.;
  buildInputs = with pkgs; [
    premake5
    SDL2
    SDL2_image
    imagemagick
  ];
  buildPhase = ''
    premake5 gmake
    make -C build config=release
  '';
  installPhase = ''
    mkdir -p $out/bin
    mkdir -p $out/share
    cp -r build/bin/Release $out/share/MeerkatEngine
    cp App/script/MeerkatEngine $out/bin/MeerkatEngine
  '';
}
