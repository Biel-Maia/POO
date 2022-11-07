{ pkgs }: {
	deps = [
		pkgs.makemake clean
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}