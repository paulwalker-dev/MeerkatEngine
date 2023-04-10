self: super: {
  raylib = super.raylib.overrideAttrs (old: rec {
    name = "${old.pname}-${version}";
    version = "4.5.0";
    src = super.fetchFromGitHub {
      owner = "raysan5";
      repo = "raylib";
      rev = version;
      sha256 = "Uqqzq5shDp0AgSBT5waHBNUkEu0LRj70SNOlR5R2yAM=";
    };
  });
}
