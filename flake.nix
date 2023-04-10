{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
    let pkgs = import nixpkgs { inherit system; overlays = [
      (import ./overlay.nix)
    ];};
      in rec {
        packages = {
          rguilayout = pkgs.callPackage ./external/rguilayout.nix { };
          MeerkatEngine = pkgs.callPackage ./default.nix { };
          default = packages.MeerkatEngine;
        };

        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            packages.rguilayout
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
