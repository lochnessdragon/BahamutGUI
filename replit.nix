{ pkgs }: {
	deps = [
		pkgs.gcc
    pkgs.gnumake
    pkgs.xorg.xorgserver
    pkgs.xorg.xrandr
    pkgs.xorg.libXrandr
    pkgs.xorg.libXinerama
    pkgs.xorg.libXcursor
    pkgs.xorg.libXi
	];
  config = {
    hardware.opengl.enable = true;
  };
}