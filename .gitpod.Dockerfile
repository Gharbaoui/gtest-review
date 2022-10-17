FROM ubuntu
RUN apt update
RUN apt install bazel
RUN apt install clang++