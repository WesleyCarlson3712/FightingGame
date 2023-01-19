{ pkgs }: {
	deps = [
		pkgs.asdf-vm
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}