{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.05";
  };

  outputs = {
    self,
    nixpkgs,
  }: let
    inherit (nixpkgs) lib;

    genSystems = lib.genAttrs ["x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin"];

    eachSystem = f:
      genSystems
      (system: f nixpkgs.legacyPackages.${system});
  in {
    formatter = eachSystem (pkgs: pkgs.alejandra);

    devShells = eachSystem (pkgs: {
      default = pkgs.mkShell {
        name = "rythmopen-dev";
        packages = with pkgs; [
          # C++
          gcc
          cmake
          
          # Qt6
          qt6.full
          qt6.qtbase
          qt6.qtmultimedia
          
          # Build tools
          ninja
          pkg-config
          
          # Debugging
          gdb
          clang-tools
        ];

        shellHook = ''
          export QT_QPA_PLATFORM_PLUGIN_PATH="${pkgs.qt6.qtbase}/lib/qt-6/plugins"
          export QT_PLUGIN_PATH="${pkgs.qt6.qtbase}/lib/qt-6/plugins"
          echo "- GCC: $(gcc --version | head -n1)"
          echo "- CMake: $(cmake --version | head -n1)"
          echo "- Qt6: ${pkgs.qt6.qtbase.version}"
        '';
      };
    });

    packages = eachSystem (pkgs: {
      default = pkgs.stdenv.mkDerivation {
        pname = "rythmopen_poc";
        version = "0.1.0";
        src = ./.;
    
        nativeBuildInputs = with pkgs; [
          cmake
          ninja
          qt6.wrapQtAppsHook
        ];
    
        buildInputs = with pkgs; [
          qt6.qtbase
          qt6.qtmultimedia
        ];
      };
    });
  };
}
