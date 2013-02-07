bootstrap.c
===========

`bootstrap.c` is a template for simple projects written in C with
autotools. It is however mostly an experiment. Can it be as useful as
projects like [HTML5 Boilerplate][]?

[HTML5 Boilerplate]: http://html5boilerplate.com/

Usage
-----

Clone this repository to the directory of your choice. Then, use the
following command to extract the next steps:

    ::sh
    git ls-tree -r --name-only HEAD | \
          xargs grep -nH "T[O]DO:" | \
          sed 's/\([^:]*:[^:]*\):\(.*\)TODO\(.*\)/\3 (\1)/' | \
          sort -n

Once you are done, your project is ready and you can compile it with
and get a release tarball with:

    ::sh
    ./autogen.sh
    mkdir build
    cd build
    ../configure
    make
    make dist

Also, don't forget to replace this `README.md` file!

Once you want to make a release, tag the tree with `git tag 1.3`, then
run the previous commands from the top. You'll get a properly
versioned tarball with a `ChangeLog` file if this is not your first
version.
