{ stdenv, raylib, fetchFromGitHub, buildFHSUserEnvBubblewrap, ... }:
let
  rguilayout = stdenv.mkDerivation rec {
    name = "rguilayout";
    src = fetchFromGitHub {
      owner = "raysan5";
      repo = "rguilayout";
      rev = "41f0bd3c9ec1ed54383be0d2cb2ff7f1b2325d10";
      sha256 = "pAAgEh2ZaImYv3p2p42K14F+NeommDyeThmt7AIxLbo=";
    };
    buildInputs = [ raylib ];
    buildPhase = ''
      gcc -o ${name} src/${name}.c src/external/*.c -Isrc/external -w -lraylib -lm -DPLATFORM_DESKTOP
    '';
    installPhase = ''
      mkdir -p $out/bin
      cp ${name} $out/bin
    '';
  };
in buildFHSUserEnvBubblewrap {
  name = "rguilayout";
  targetPkgs = pkgs: (with pkgs; [ kdialog rguilayout ]);
  runScript = "rguilayout";
}
