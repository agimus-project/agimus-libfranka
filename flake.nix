{
  description = "ROS integration for Franka research robots";

  inputs.gepetto.url = "github:gepetto/nix";

  outputs =
    inputs:
    inputs.gepetto.lib.mkFlakoboros inputs (
      { lib, ... }:
      {
        rosOverrideAttrs.agimus-libfranka = {
          src = lib.fileset.toSource {
            root = ./.;
            fileset = lib.fileset.unions [
              ./cmake
              ./doc
              ./examples
              ./include
              ./scripts
              ./src
              ./test
              ./CHANGELOG.md
              ./CMakeLists.txt
              ./LICENSE
              ./NOTICE
              ./README.md
            ];
          };
        };
      }
    );
}
