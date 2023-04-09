{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = nixpkgs.legacyPackages.${system};
      in {
        packages = rec {
          MeerkatEngine = pkgs.callPackage ./default.nix { };
          default = MeerkatEngine;
        };

        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            premake5
            raylib
            imagemagick
            gdb
            valgrind
            nixfmt
          ];
        };
      });
}