# Implementation of an HDF5 IO layer for PODIO
## Google Summer of Code 2019 Evaluation Test

If you are interested in our GSoC project to [implement an HDF5 layer
in the High-Energy Physics event model software PODIO](https://hepsoftwarefoundation.org/gsoc/2019/proposal_PODIOHDF5.html),
then please complete the following evaluation test.

This exercise can be completed on most modern Linux distributions, such as
Ubuntu18.04, CentOS7, Fedora29. OS X is possible, but more tricky to setup, so we
do not recommend it. It is not possible to use Windows.

## Docker Container

If you do not have direct access to a suitable platform we provide a
[Docker container](https://hub.docker.com/r/graemeastewart/u18-podio)
that you can use to complete the exercise, `graemeastewart/u18-podio`.

(It is not necessary to have root access in the container, but if you need it
you can use `sudo` and the password is `hsf`.)

## Startup Instructions

1. Clone a local copy of the PODIO repository from [GitHub](https://github.com/AIDASoft/podio).

1. Install a local copy of the HEP [ROOT software](https://root.cern.ch)
    - We recommend using the latest stable version of ROOT (6.16.00).
    - Downloading a [pre-built](https://root.cern.ch/content/release-61600)
      version of ROOT is perfectly acceptable.
    - N.B. In the `graemeastewart/u18-podio` container this is provided for
      you, installed into `/opt`.

1. Compile PODIO and run its unit tests, to check that your development
   setup is working.
    - Follow the instructions on the [PODIO github](https://github.com/AIDASoft/podio/blob/master/README.md).
    - Finally, `make test` should run and successfully complete the five
      PODIO unit tests.

N.B. If you are having trouble with any dependencies in your environment
you can consult the Dockerfiles of the container we provided and that
might help you solve the issue: [1](https://github.com/graeme-a-stewart/hithe/blob/master/u18-dev/Dockerfile)
and [2](https://github.com/graeme-a-stewart/hithe/blob/master/u18-podio/Dockerfile).

## Evaluation Test

1. Write a shell script that will checkout the PODIO code, compile it
   and run the unit tests.

1. Study the PODIO sample data model in `tests/datalayout.yaml`.

1. Look at the data object `SimpleStruct`, and make sure you understand
   how the data is represented as a C++ object.
    - The code in `tests/src` and `tests/datamodel` will help.

1. Write a code example in C++ that will use the HDF5 libraries to
    - Create a `SimpleStruct` array, of size 100, in memory and write some
      predictable data into it.
    - Create a compound HDF5 datatype that corresponds to the
      `SimpleStruct`.
    - Write the `SimpleStruct` data into an HDF5 file.
    - N.B. it's not necessary to use the PODIO C++ code for this, but
      you can if you want.

1. Write a second piece of code in C++ that will reread the HDF5 file and
   check that the `SimpleStruct` array is successfully deserialised into memory.

1. Your code should at least compile using `make`; using `cmake` is also
   fine.

## Submitting Your Answer

You can submit your answer by sending the mentors a link to a github
repository with the solution.

- Make sure you include:
    - The shell script that will checkout PODIO, comple and test it.
    - The C++ to write and read back `SimpleStuct`s in HDF5 format.
    - A `README.md` that describes how to compile and run your solution.

It is advisable that you test that your solution works properly
in the `graemeastewart/u18-podio` container - this is what we will
use for testing the solutions.

If you need clarification on any aspect of the test then you are very welcome
to contact the mentors:

- Graeme Stewart <graeme.andrew.stewart@cern.ch>
- Benedikt Hegner <bhegner@bnl.gov>
- Frank Gaede <frank.gaede@desy.de>
