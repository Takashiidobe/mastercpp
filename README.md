# Master C++

This website teaches you how to learn C++ from the ground up.

## Contributing

### Adding Comments

- This repository uses [utteranc.es](https://utteranc.es/) for its commenting engine. Any comments that you leave on a specific page on the website are fetched from this github repository and are displayed on the page when first loaded. This creates a new issue thread in the repository if one does not already exist, or adds on to the existing repository.

### Development

#### Dependencies

You'll need the following dependencies to contribute to development.

- [mdBook](https://github.com/rust-lang/mdBook#installation)
- [make](https://linux.die.net/man/1/make)
- [python3](https://www.python.org/downloads/)
- [git-chglog](https://github.com/git-chglog/git-chglog)

#### Commit Messages

- This project follows [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/).

- Until a v1.0.0 release (one that is suitable for a reader to read), any commit can be considered breaking. The site will be available for reading, but its contents may change at any time.

- Any commit that is backwards compatible and does not introduce new content should contain a commit prefixed with "fix:". This corresponds to a PATCH update in semver.
- Any commit that adds new content should contain a commit prefixed with "feat:". This corresponds to a MINOR update in semver.
- Any commit that breaks existing content should have a ! before the colon for its scope. (eg. refactor!: ...). This corresponds to a MAJOR update in semver.

#### Useful Make Commands

`make` or `make serve` will open a development version of the project on port 3000 for you to develop on. Whenever you make a change, the project will update.

`make build` creates a production ready version of the project in the `book/` directory.

`make clean` deletes the `book` directory for a clean build.

`make release` will run `git-chglog` which will generate a `CHANGELOG.md` file based on the changes since the last release.

`make increment` or `make increment_patch` will increment the patch semver version. Run this command for any backwards compatible bug fixes.

`make increment_minor` will increment the minor semver version. Run this command when you add any content or fix content that does not break existing links.

- Some examples of minor increment worthy changes:
  - Adding a chapter or section
  - Updating a chapter or section
  - Adding new content to an existing chapter or section

`make increment_major` will increment the major semver version. Run this command for any backwards incompatible fixes.

- Some examples of major increment worthy changes:
  - Removing a chapter
  - Updating the focus or overhauling a section
