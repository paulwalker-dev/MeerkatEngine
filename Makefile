all:
	premake5 gmake
	$(MAKE) -C build

.PHONY: all
