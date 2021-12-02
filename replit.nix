{ stdenv, libX11, pkgs }: {
	deps = [
		pkgs.gcc
    pkgs.gnumake
    pkgs.xorg.xorgserver
    pkgs.xorg.xrandr
    pkgs.xorg.libXrandr
    pkgs.xorg.libXinerama
    pkgs.xorg.libXcursor
    pkgs.xorg.libXext
    pkgs.xorg.libXi
    pkgs.xorg.libX11
    pkgs.nix-index
	];

  config = {
    hardware.opengl.enable = true;
    services.xserver.enable = true;
  };

  XLIB_OUT = "${pkgs.xorg.libX11.outDir}";
  LD_PATH_EXTRA = with deps; "${stdenv.lib.makeLibraryPath deps}";
}