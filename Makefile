all:
	make serve
watch:
	mdbook watch --open
build:
	mdbook build
clean:
	mdbook clean
serve:
	mdbook serve
deploy:
	make clean && make build && ntl deploy --prod
