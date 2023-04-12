{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
          overlays = [ (import ./overlay.nix) ];
        };
      in rec {
        packages = {
          raygui = pkgs.callPackage ./external/raygui.nix { };
          MeerkatEngine =
            pkgs.callPackage ./default.nix { inherit (packages) raygui; };
          default = packages.MeerkatEngine;
        };

        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [ premake5 raylib packages.raygui ripgrep nixfmt ];
        };
      });
}
