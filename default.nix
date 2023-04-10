{ stdenv, lib, premake5, raylib, raygui, imagemagick, makeWrapper, toybox, ...
}:
stdenv.mkDerivation {
  pname = "MeerkatEngine";
  version = "0.0.1";
  src = ./.;
  buildInputs = [ premake5 raylib raygui imagemagick ];
  nativeBuildInputs = [ makeWrapper ];
  buildPhase = ''
    premake5 gmake
    make -C build config=release
  '';
  installPhase = ''
    mkdir -p $out/bin
    mkdir -p $out/share
    cp -r build/bin/Release $out/share/MeerkatEngine
    cp App/script/MeerkatEngine $out/bin/MeerkatEngine
    wrapProgram $out/bin/MeerkatEngine \
      --prefix PATH : ${lib.makeBinPath [ toybox ]}
  '';
}
