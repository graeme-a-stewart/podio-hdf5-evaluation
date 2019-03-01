# Implementation of an HDF5 IO layer for PODIO
## Google Summer of Code 2019 Evaluation Test

If you are interested in our GSoC project to implement an HDF5 layer
in the High-Energy Physics event model software PODIO, then please
complete the following evaluation test.

This exercise can be completed on most modern Linux distributions, such as
Ubuntu18.04, CentOS7, Fedora29. OS X is possible, but hard to setup, so we
do not recommend it. It's not possible to use Windows. If you don't have
direct access to a suitable platform we provide a Docker container that
you can use to complete the exercise, `graemeastewart/u18-podio`.

## Questions for us...

- What compiler limitations do we have? e.g. would gcc4.8 work on CentOS7?


## Startup Instructions

1. Clone a local copy of the PODIO repository from [GitHub](https://github.com/AIDASoft/podio).

1. Install a local copy of the HEP [ROOT software](https://root.cern.ch)
    - We recommend using the latest stable version of ROOT (6.16.00)
    - Downloading a [pre-built](https://root.cern.ch/content/release-61600) version of ROOT is perfectly acceptable

1. Compile PODIO and run its unit tests, to check that your development
   setup is working.
    - Follow the instructions on the [PODIO github](https://github.com/AIDASoft/podio/blob/master/README.md)
    - Finally, `make test` should run and successfully complete the five
      PODIO unittests

N.B. If you are having trouble with any dependencies in your environment
you can consult the Dockerfiles of the container we provided and that
might help you solve the issue, [1](https://github.com/graeme-a-stewart/hithe/blob/master/u18-dev/Dockerfile)
[2](https://github.com/graeme-a-stewart/hithe/blob/master/u18-podio/Dockerfile).

## Evaluation Test

1. Study the PODIO sample data model in `tests/datalayout.yaml`

1. Pick the data objects `foo` and `bar`, and make sure you understand
   how the data is represented as a C++ object.
    - The code in `tests/src` and `tests/datamodel` will help.

1. Write a code example in C++ that will use the HDF5 libraries to
   write the representation of `foo` and `bar` into a file.
    - You don't need to use any of the PODIO code to do this, but you
      can if you like.

1. Write a second piece of code in C++ that will reread the HDF5 file and
   check that the objects are successfully deserialised into memory.

1. Your code should at least compile using a `make`; using `cmake` is also
   fine.

## Submitting Your Answer

1. You can submit your answer by sending the mentors a link to a github
   repository with the solution, which should also contain a `README.md`
   file with instructions as to how to compile and run the code.
    - It's advisable that you test that your solution works properly
      in the `graemeastewart/u18-podio` container.

If you need clarification on any aspect of the test then you are very welcome
to contact the mentors:

- Graeme Stewart <graeme.andrew.stewart@cern.ch>
- Benedikt Hegner <bhegner@bnl.gov>
- Frank Gaede <frank.gaede@desy.de>
