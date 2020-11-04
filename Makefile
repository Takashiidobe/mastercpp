all:
	make serve
build:
	mdbook build
clean:
	mdbook clean
serve:
	mdbook serve --open
deploy:
	make release && make clean && make build && ntl deploy --prod
release:
	git tag $(cat VERSION) && git-chglog -o CHANGELOG.md
increment:
	make increment_patch
increment_patch:
	python3 increment_version.py
increment_minor:
	python3 increment_version.py minor
increment_major:
	python3 increment_version.py major
